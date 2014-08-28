#!/bin/bash 
#3
export KUPA_HOME=`pwd` 
cd /home/aneta/aneta-kupa/source/ns-3-dce 
/home/aneta/aneta-kupa/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=w --delay=1.000ms --ModeOperation=true --tcp_mem_user=4000,8388608,8388608 --tcp_mem_server=4000,8388608,8388608 --tcp_cc=reno --htmlSize=3 --user_bw=10Gbps --server_bw=1Gbps --ErrorModel=1 --errRate=0.010 --chan_alpha=0.100 --chan_k=3.00 --chan_theta=1.0 --chan_jitter=1
