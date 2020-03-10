#!/bin/sh
#
# shell-script for building cl.
#
cc -c -o cl.o cl.c
cc -c -o cl_cal.o cl_cal.c
cc    -o cl cl.o cl_cal.o
