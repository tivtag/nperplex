#!/bin/bash

# requires permission: chmod 775 make-proj-lin.sh
conf=debuglib64

# gen make files
premake4 gmake

rm bin/* -r
make -C project config=$conf

