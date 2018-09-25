#!/bin/bash

rm average.csv
for i in {0..999}
do
	echo $i
	cat SwarmInput_$i.csv |awk 'BEGIN{FS = ","}{print sprintf("%.8f,%.8f,%.8f,%.8f", $1,$2,$3,$4);}' > out
	Rscript.exe average.R out
#	Rscript.exe average.R SwarmInput_$i.csv
	rm out
done