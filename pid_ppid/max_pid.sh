#!/bin/bash

MAX_PID=$(($(cat /proc/sys/kernel/pid_max)-1))

echo "The maximum PID value is: $MAX_PID"
