#!/bin/bash 
#2
export KUPA_HOME=`pwd` 
cd /home/aneta/aneta-kupa/source/ns-3-dce 
/home/aneta/aneta-kupa/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=u --ModeOperation=true --udp_bw=20 --SimuTime=10.00 --user_bw=50Mbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.000 --chan_jitter=1 --chan_k=0.100 --avg_delay=1.000 --delay_pdv=1.000
