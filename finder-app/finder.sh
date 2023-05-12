#!/bin/bash

if [ -z "$1" ]
then
	echo "first arg not supplied";
	exit 1;
fi

if [ ! -d "$1" ]; then
    echo "$1 is not a directory";
    exit 1;
fi

if [ -z "$2" ] 
then
	echo "second arg not supplied";
	exit 1;
fi

FILE_COUNT=$(ls $1 | wc -l);
LINE_MATCH=0;

for file in $(ls $1)
do
    MATCH_FOR_FILE=$(grep $2 "$1/$file" | wc -l)
    LINE_MATCH=$(( $LINE_MATCH + $MATCH_FOR_FILE ))
done

echo "The number of files are $FILE_COUNT and the number of matching lines are $LINE_MATCH"
