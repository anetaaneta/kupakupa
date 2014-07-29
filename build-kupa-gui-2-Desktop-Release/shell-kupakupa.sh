#!/bin/bash 
#1
export KUPA_HOME=`pwd` 
cd /home/aneta/aneta-kupa/source/ns-3-dce 
./build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=p --ModeOperation=true --tcp_mem_user=4096,8192,8388608 --tcp_mem_server=10000000,10000000,10000000 --tcp_cc=reno --SimuTime=20 --user_bw=150Mbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.001 --chan_alpha=0.300 --chan_k=10.00 --chan_tetha=1.0 --chan_jitter=0
cd $KUPA_HOME