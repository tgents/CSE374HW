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

grep -o -e 'http[^<>]*\.[^"]*' $input > $output
sed -i '/.*\(babelfish\|100best\|\/wiki\/\).*/d' $output
