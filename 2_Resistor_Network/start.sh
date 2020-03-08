#!/bin/sh

gcc main.c -lport3 -lm -o matrix.out -L/usr/local/lib/gcc/9 -lgfortran
