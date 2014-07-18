#!/bin/bash 
#2
export KUPA_HOME=`pwd` 
cd /home/aneta/aneta-kupa/source/ns-3-dce/ 
./waf --run "kupakupa  --TypeOfConnection=u --ModeOperation=true --udp_bw=9 --user_bw=150Mbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.010 --chan_alpha=0.300 --k=10.00 --chan_tetha=1.000 --chan_jitter=0"
cd $KUPA_HOME