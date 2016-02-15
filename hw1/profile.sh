#!/bin/bash

#Thomas Tseng
#tgents 1339907

echo '#N time' > moonlight.dat
echo '#N time' > rosebud.dat

for (( i=250; i<5000; i+=250))
do
  moon=$(("/usr/bin/time" -f "%e" ./moonlight $i > /dev/null) 2>&1)
  rose=$(("/usr/bin/time" -f "%e" ./rosebud $i > /dev/null) 2>&1)
  echo "$i $moon" >> moonlight.dat
  echo "$i $rose" >> rosebud.dat
done
