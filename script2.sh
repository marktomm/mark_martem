#!/bin/bash
printf "Compilation started\n"
g++ filesystem.cpp -o filesystem -lboost_system -lboost_filesystem -lboost_date_time
printf "Compilation finished\n"
