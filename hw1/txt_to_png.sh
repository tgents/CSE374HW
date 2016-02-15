#!/bin/bash

#Thomas Tseng 
#tgents 1339907

if [ $# -eq 0 ]
then
   echo "No arguments found." >&2
fi 

for file in $@
do
   if [ ! -e $file ]
   then
      echo "$file not found." >&2
   else
   
      filename=$(basename $file .txt)
      width=$(head -n 1 $file)
      height=$(head -n 2 $file | tail -n +2)
      tempW=0
      tempH=0
      first=0;

      echo "# ImageMagick pixel enumeration: $width,$height,255,srgb" > "$filename.temp"      

      values=$(while read line
      do
         if (( $first==0 ))
         then
            read line
            read line
            ((first++))
         fi

         echo "$tempW,$tempH: ("$(echo $line | tr " " ",")")"
      
         ((tempW++))
         if ((tempW==width))
         then
	    ((tempW=0))
            ((tempH++))
         fi
      done < $file)
      echo "$values" >> "$filename.temp"
      convert "txt:$filename.temp" "$filename.png"
      rm "$filename.temp"
   fi
done
