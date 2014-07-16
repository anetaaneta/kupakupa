#!/bin/bash 
#3
export KUPA_HOME=`pwd` 
cd /home/aneta/aneta-kupa/source/ns-3-dce/ 
./waf --run "kupakupa  --TypeOfConnection=w --ModeOperation=true --tcp_mem_user=4096 8192 8388608 --tcp_mem_server=4096 8192 8388608 --tcp_cc=reno --htmlSize=2 --user_bw=150Mbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.010"
cd $KUPA_HOME