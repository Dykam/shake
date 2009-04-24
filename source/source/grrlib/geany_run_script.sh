#!/bin/sh

export DEVKITPRO=/home/giuseppe/devkitpro;export DEVKITPPC=$DEVKITPRO/devkitPPC;PATH=$PATH:$DEVKITPPC/bin;PATH=$PATH:$DEVKITPRO/wiiload/lin32;export WIILOAD=tcp:192.168.1.4;cd ..;make run

echo "

------------------
(program exited with code: $?)" 		


echo "Press return to continue"
#to be more compatible with shells like dash
dummy_var=""
read dummy_var
rm $0
