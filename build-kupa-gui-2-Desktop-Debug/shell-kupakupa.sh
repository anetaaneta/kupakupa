#!/bin/bash 
#2
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=u --delay=0.500ms --ModeOperation=true --udp_bw=20 --SimuTime=10.00 --user_bw=150Mbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.000 --chan_alpha=0 --chan_k=0 --chan_theta=0 --chan_jitter=1
