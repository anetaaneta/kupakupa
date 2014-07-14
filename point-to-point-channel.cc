/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
* Copyright (c) 2007, 2008 University of Washington
*
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License version 2 as
* published by the Free Software Foundation;
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

#include "point-to-point-channel.h"
#include "point-to-point-net-device.h"
#include "ns3/trace-source-accessor.h"
#include "ns3/packet.h"
#include "ns3/simulator.h"
#include "ns3/log.h"
#include "ns3/core-module.h"

NS_LOG_COMPONENT_DEFINE ("PointToPointChannel");

namespace ns3 {

NS_OBJECT_ENSURE_REGISTERED (PointToPointChannel);

TypeId
PointToPointChannel::GetTypeId (void)
{
  static TypeId tid = TypeId ("ns3::PointToPointChannel")
    .SetParent<Channel> ()
    .AddConstructor<PointToPointChannel> ()
    .AddAttribute ("Delay", "Transmission delay through the channel",
                   TimeValue (Seconds (0)),
                   MakeTimeAccessor (&PointToPointChannel::m_delay),
                   MakeTimeChecker ())
.AddAttribute ("Jitter", "Implement Jitter",
                   UintegerValue (0),
                   MakeUintegerAccessor (&PointToPointChannel::m_jitter),
                   MakeUintegerChecker<uint16_t> ())
.AddAttribute ("alpha", "Set jitter moving average value",
                   DoubleValue (0.4),
                   MakeDoubleAccessor (&PointToPointChannel::m_alpha),
                   MakeDoubleChecker<int64_t>())
.AddAttribute ("k", "Set gamma distribution k value",
                   DoubleValue (5.0),
                   MakeDoubleAccessor (&PointToPointChannel::m_k),
                   MakeDoubleChecker<int64_t>())
.AddAttribute ("tetha", "Set gamma distribution tetha value",
                   DoubleValue (2.0),
                   MakeDoubleAccessor (&PointToPointChannel::m_tetha),
                   MakeDoubleChecker<int64_t>())	
    .AddTraceSource ("TxRxPointToPoint",
                     "Trace source indicating transmission of packet from the PointToPointChannel, used by the Animation interface.",
                     MakeTraceSourceAccessor (&PointToPointChannel::m_txrxPointToPoint))
  ;
  return tid;
}

//
// By default, you get a channel that
// has an "infitely" fast transmission speed and zero delay.
PointToPointChannel::PointToPointChannel()
  :
    Channel (),
    m_delay (Seconds (0.)),
    m_nDevices (0),
    m_jitter (0),
    m_alpha (0.4),
    m_k (5.0),
    m_tetha (2.0),
    m_previousDelay (0)
{
  NS_LOG_FUNCTION_NOARGS ();
}

void
PointToPointChannel::Attach (Ptr<PointToPointNetDevice> device)
{
  NS_LOG_FUNCTION (this << device);
  NS_ASSERT_MSG (m_nDevices < N_DEVICES, "Only two devices permitted");
  NS_ASSERT (device != 0);

  m_link[m_nDevices++].m_src = device;
//
// If we have both devices connected to the channel, then finish introducing
// the two halves and set the links to IDLE.
//
  if (m_nDevices == N_DEVICES)
    {
      m_link[0].m_dst = m_link[1].m_src;
      m_link[1].m_dst = m_link[0].m_src;
      m_link[0].m_state = IDLE;
      m_link[1].m_state = IDLE;
    }
}

bool
PointToPointChannel::TransmitStart (
  Ptr<Packet> p,
  Ptr<PointToPointNetDevice> src,
  Time txTime)
{
  NS_LOG_FUNCTION (this << p << src);
  NS_LOG_LOGIC ("UID is " << p->GetUid () << ")");

  NS_ASSERT (m_link[0].m_state != INITIALIZING);
  NS_ASSERT (m_link[1].m_state != INITIALIZING);

  uint32_t wire = src == m_link[0].m_src ? 0 : 1;
  if (m_jitter==0)
  {

  Simulator::ScheduleWithContext (m_link[wire].m_dst->GetNode ()->GetId (),
                                  txTime+m_delay, &PointToPointNetDevice::Receive,
                                  m_link[wire].m_dst, p);
  
  // Call the tx anim callback on the net device
  m_txrxPointToPoint (p, src, m_link[wire].m_dst, txTime, txTime+m_delay);
  }
  else
  {
  
  double prevDelay=(m_previousDelay==0)? GammaRandomValue():m_previousDelay;
  double cur_delay= (1-m_alpha)*prevDelay+m_alpha*GammaRandomValue();

  Time rcvTime = Simulator::Now()+ Time(cur_delay);

  if (rcvTime < m_prevRcvTime)
  {
          rcvTime= m_prevRcvTime;
cur_delay=0;
  }
  m_previousDelay=cur_delay;
  m_prevRcvTime = rcvTime;

  Simulator::ScheduleWithContext (m_link[wire].m_dst->GetNode ()->GetId (),
                                  Time(cur_delay), &PointToPointNetDevice::Receive,
                                  m_link[wire].m_dst, p);
  // Call the tx anim callback on the net device
  m_txrxPointToPoint (p, src, m_link[wire].m_dst, Seconds(0),Time(cur_delay));

  }
  return true;
}

uint32_t
PointToPointChannel::GetNDevices (void) const
{
  NS_LOG_FUNCTION_NOARGS ();
  return m_nDevices;
}




Ptr<PointToPointNetDevice>
PointToPointChannel::GetPointToPointDevice (uint32_t i) const
{
  NS_LOG_FUNCTION_NOARGS ();
  NS_ASSERT (i < 2);
  return m_link[i].m_src;
}

Ptr<NetDevice>
PointToPointChannel::GetDevice (uint32_t i) const
{
  NS_LOG_FUNCTION_NOARGS ();
  return GetPointToPointDevice (i);
}

Time
PointToPointChannel::GetDelay (void) const
{
  return m_delay;
}

Ptr<PointToPointNetDevice>
PointToPointChannel::GetSource (uint32_t i) const
{
  return m_link[i].m_src;
}

Ptr<PointToPointNetDevice>
PointToPointChannel::GetDestination (uint32_t i) const
{
  return m_link[i].m_dst;
}

bool
PointToPointChannel::IsInitialized (void) const
{
  NS_ASSERT (m_link[0].m_state != INITIALIZING);
  NS_ASSERT (m_link[1].m_state != INITIALIZING);
  return true;
}
double
PointToPointChannel::GammaRandomValue()
{


  Ptr<GammaRandomVariable> x = CreateObject<GammaRandomVariable> ();
  x->SetAttribute ("Alpha", DoubleValue (m_k));
  x->SetAttribute ("Beta", DoubleValue (m_tetha));
  // The expected value for the mean of the values returned by a
  // gammaly distributed random variable is equal to
  //
  // E[value] = alpha * beta .
  //
  double value = x->GetValue ()* double(1000000);
  return value;
}

} // namespace ns3
