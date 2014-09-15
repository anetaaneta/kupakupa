#!/bin/bash 
#2
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=u --delay=0ms --ModeOperation=true --udp_bw=20 --SimuTime=10.00 --user_bw=1Gbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.000 --chan_alpha=1.00 --chan_mean=1.000 --chan_variance=2.000 --chan_jitter=1
