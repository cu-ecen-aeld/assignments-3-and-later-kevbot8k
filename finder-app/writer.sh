#!/bin/bash

set -e
if [ -z "$1" ]
then
	echo "first arg not supplied";
	exit 1;
fi

if [ -z "$2" ]
then
	echo "no content for file provided in second arg"
	exit 1;
fi

rm -f $1
mkdir -p $(dirname $1)
echo "$2" > $1
