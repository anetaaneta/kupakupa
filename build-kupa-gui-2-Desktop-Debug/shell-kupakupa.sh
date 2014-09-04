#!/bin/bash 
#1
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=p --delay=0ms --ModeOperation=true --tcp_mem_user=40000,40000,40000 --tcp_mem_user_wmem=40000,40000,40000 --tcp_mem_user_rmem=40000,40000,40000 --tcp_mem_server=40000,40000,40000 --tcp_mem_server_wmem=40000,40000,40000 --tcp_mem_server_rmem=40000,40000,40000 --tcp_cc=cubic --SimuTime=10.00 --user_bw=1Gbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.000 --chan_alpha=0.000 --chan_mean=0.385 --chan_variance=0.000 --chan_jitter=1
