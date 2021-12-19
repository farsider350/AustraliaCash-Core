#!/bin/bash
for i in {1..999}
do
	echo " $i "
	./coin-cli generate $i
done
