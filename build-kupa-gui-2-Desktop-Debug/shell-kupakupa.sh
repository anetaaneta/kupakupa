#!/bin/bash 
#1
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=p --delay=0.500ms --ModeOperation=true --tcp_mem_user=4096,8192,8388608 --tcp_mem_server=4096,8192,8388608 --tcp_cc=reno --SimuTime=20 --user_bw=150Mbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.001 --chan_alpha=0.300 --chan_k=1.00 --chan_theta=1.0 --chan_jitter=1
