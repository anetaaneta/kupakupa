#!/bin/bash 
#1
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=p --ModeOperation=true --tcp_mem_user=4096,87380,8388608 --tcp_mem_user_wmem=4096,87380,8388608 --tcp_mem_user_rmem=4096,87380,8388608 --tcp_mem_server=4096,87380,8388608 --tcp_mem_server_wmem=4096,87380,8388608 --tcp_mem_server_rmem=4096,87380,8388608 --tcp_cc=reno --SimuTime=10.00 --user_bw_down=1Mbps --user_bw_up=1Mbps --ErrorModel=1 --errRate=0.000 --ErrorModel2=1 --errRate2=0.000 --chan_k_dw=0.100 --avg_delay_dw=2.000 --delay_pdv_dw=0.100 --chan_k_up=0.100 --avg_delay_up=3.000 --delay_pdv_up=0.200
