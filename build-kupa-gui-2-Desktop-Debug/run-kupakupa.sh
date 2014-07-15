#!/bin/bash 
export KUPA_HOME=`pwd` 
cd /home/aneta/aneta-kupa/source/ns-3-dce/ 
./waf shell 
./home/aneta/aneta-kupa/source/ns-3-dce/build/myscripts/kupakupa/bin/kupakupa  --user_bw=150Mbps --server_bw=10Gbps --ErrorModel=1 --errRate=0.010
cd $KUPA_HOME