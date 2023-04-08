#!/bin/bash
for i in {1..999}
do
	echo " $i "
	./australiacash-cli -testnet -generate
done
