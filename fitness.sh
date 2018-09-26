#!/bin/bash

rm fitness.csv
for i in {0..999}
do
	echo $i
	cat result_$i.csv |awk 'BEGIN{FS = ","}{print sprintf("%.8f", $15+$16);}' > out
	Rscript.exe fitness.R out
	rm out
done