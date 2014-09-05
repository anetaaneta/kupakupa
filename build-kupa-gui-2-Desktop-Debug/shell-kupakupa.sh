#!/bin/bash 
#1
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=p --delay=0ms --ModeOperation=true --tcp_mem_user=4096,87380,8388608 --tcp_mem_user_wmem=4096,87380,8388608 --tcp_mem_user_rmem=4096,87380,8388608 --tcp_mem_server=4096,87380,8388608 --tcp_mem_server_wmem=4096,87380,8388608 --tcp_mem_server_rmem=4096,87380,8388608 --tcp_cc=reno --SimuTime=10.00 --user_bw=1Gbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.000 --chan_alpha=0.00 --chan_mean=1.000 --chan_variance=0.000 --chan_jitter=1
