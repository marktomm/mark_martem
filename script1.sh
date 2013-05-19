#!/bin/bash
if [ "$1" = "" ]
then
TOTALRAM=$((`grep -i 'MemTotal' /proc/meminfo | awk '{print $2}' | sed s/...$//`))
FREEMEM=$((`grep -i 'MemFree' /proc/meminfo | awk '{print $2}' | sed s/...$//`))
USED=$((TOTALRAM - FREEMEM))
printf "RAM: %d MB used / %d MB total ( %d MB free )\n" $USED $TOTALRAM $FREEMEM
else
TOTALRAM=$((`grep -i 'MemTotal' $1 | awk '{print $2}' | sed s/...$//`))
FREEMEM=$((`grep -i 'MemFree' $1 | awk '{print $2}' | sed s/...$//`))
USED=$((TOTALRAM - FREEMEM))
printf "RAM: %d MB used / %d MB total ( %d MB free )\n" $USED $TOTALRAM $FREEMEM
fi
