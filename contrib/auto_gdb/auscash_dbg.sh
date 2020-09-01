#!/bin/bash
# use testnet settings,  if you need mainnet,  use ~/.auscashcore/auscashd.pid file instead
auscash_pid=$(<~/.auscashcore/testnet3/auscashd.pid)
sudo gdb -batch -ex "source debug.gdb" auscashd ${auscash_pid}
