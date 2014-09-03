#!/bin/bash 
#3
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=w --delay=0.500ms --ModeOperation=true --tcp_mem_user=4096,8192,8388608 --tcp_mem_server=4096,8192,8388608 --tcp_cc=reno --htmlSize=8 --user_bw=10Gbps --server_bw=1Gbps --ErrorModel=1 --errRate=0.000 --chan_alpha=0.000 --chan_k=0.00 --chan_theta=0.0 --chan_jitter=1
