#!/bin/bash 
#2
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=u --delay=0.500ms --ModeOperation=true --udp_bw=1 --user_bw=10Gbps --server_bw=1Gbps --ErrorModel=1 --errRate=0.010 --chan_alpha=0.000 --chan_k=3.00 --chan_theta=1.0 --chan_jitter=1
