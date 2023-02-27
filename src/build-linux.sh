#!/usr/bin/env bash

set -Eeu
set -o pipefail

###

gcc main.c -o scriptrunner -lraylib -lm -ldl -lpthread
