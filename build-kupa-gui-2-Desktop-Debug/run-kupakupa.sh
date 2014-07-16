#!/bin/bash 
/home/aneta/aneta-kupa/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=p --ModeOperation=true --tcp_mem_user=4096 8192 8388608 --tcp_mem_server=4096 8192 8388608 --tcp_cc=reno --SimuTime=20 --user_bw=150Mbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.010
