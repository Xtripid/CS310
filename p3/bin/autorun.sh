#!/bin/bash 
cd ..
cd serverlogs/
rm server.output 1.config 2.config 3.config 1.log 2.log 3.log
cp 1_INIT.config 1.config
cp 2_INIT.config 2.config
cp 3_INIT.config 3.config
cp 1_INIT.log 1.log
cp 2_INIT.log 2.log
cp 3_INIT.log 3.log
cd ..
make
bin/runtest.sh 10 tests/sampletest.txt
