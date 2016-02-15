# !/bin/bash
# Thomas Tseng
# tgents 1339907

if [ $# -eq 0 ]
then
	>&2 echo "Error: no arguments found"
	exit 1
else
	url=$1
	filename=$(mktemp)

	rm $filename 2> /dev/null
	wget --tries=10 -q -O $filename $url
	wc -c < $filename
	rm -f $filename
fi
