#!/bin/bash 
#1
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=p --ModeOperation=true --tcp_mem_user=4096,87380,8388608 --tcp_mem_user_wmem=4096,87380,8388608 --tcp_mem_user_rmem=4096,87380,8388608 --tcp_mem_server=4096,87380,8388608 --tcp_mem_server_wmem=4096,87380,8388608 --tcp_mem_server_rmem=4096,87380,8388608 --tcp_cc=reno --SimuTime=10.00 --user_bw=1Gbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.000 --chan_jitter=1 --chan_k=0.100 --avg_delay=1.000 --delay_pdv=0.100
