#!/bin/bash 
#2
export KUPA_HOME=`pwd` 
cd /home/nama/dce/source/ns-3-dce 
/home/nama/dce/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --TypeOfConnection=u --ModeOperation=false --udp_bw=1 --SimuTime=10.00 --user_bw_down=2Mbps --user_bw_up=10Mbps --ErrorModel=1 --errRate=0.000 --ErrorModel2=1 --errRate2=0.000 --chan_k_dw=0.300 --avg_delay_dw=1.000 --delay_pdv_dw=0.200 --chan_k_up=5.000 --avg_delay_up=4.000 --delay_pdv_up=1.600
