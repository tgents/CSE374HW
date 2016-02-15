# !/bin/bash
# Thomas Tseng
# tgents 1339907

if [ $# -lt 2 ]
then
	>&2 echo "Error: invalid arguments"
	exit 1
fi

input=$1
output=$2

if [ ! -e $input ]
then
	>&2 echo "Error: invalid arguments"
	exit 1
fi

echo "rank URL page-size" > $output

index=1

while read line
	do
	echo "Performing measurment on $line"
	size=$(./perform-measurement.sh $line)
	if (( $size==0 ))
		then
		echo "...failed"
	else
		echo "...success"
		echo "$index $line $size" >> $output
	fi
	((index++))
	done < $input
