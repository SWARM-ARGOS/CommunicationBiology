#!/bin/bash

rm exit.txt
rm offspring_log.csv
rm result_*
rm SwarmInput_*

python Initialization.py

for i in {0..500}
do
	echo $i
	./Harsh_Mistress20.exe $i
	tail -n +2 result_$i.csv |awk 'BEGIN{FS = ","}{print $(NF-4)+$(NF-3)}' > tmp
	python Evolution.py SwarmInput_$i.csv
	if [ -e exit.txt ]; then
		break
	fi
	mv output.csv SwarmInput_$((i + 1)).csv
done