#!/bin/bash 
#3
export KUPA_HOME=`pwd` 
cd /home/aneta/aneta-kupa/source/ns-3-dce/ 
./waf --run "kupakupa  --TypeOfConnection=w --ModeOperation=true --tcp_mem_user=4096 8192 8388608 --tcp_mem_server=4096 8192 8388608 --tcp_cc=reno --htmlSize=2 --user_bw=150Mbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.010 --chan_alpha=0.300 --chan_k=10.00 --chan_tetha=1.000 --chan_jitter=0"
cd $KUPA_HOME