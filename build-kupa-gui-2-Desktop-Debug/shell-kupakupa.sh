#!/bin/bash 
#1
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=p --delay=0.500ms --ModeOperation=false --tcp_mem_user=4000,8388608,8388608 --tcp_mem_server=4000,8388608,8388608 --tcp_cc=reno --SimuTime=20 --user_bw=10Gbps --server_bw=1Gbps --ErrorModel=1 --errRate=0.010 --chan_alpha=0.000 --chan_k=0.00 --chan_theta=0.0 --chan_jitter=1
