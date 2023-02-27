#!/usr/bin/env bash

set -Eeu
set -o pipefail

###

gcc -o scriptrunner main.c -L/opt/vc/lib -lraylib -lm -lbrcmEGL -lbrcmGLESv2 -lbcm_host -lpthread
