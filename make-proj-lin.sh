#!/bin/bash

# requires permission: chmod 775 make-proj-lin.sh
conf=debuglib64

# gen make files
premake4 gmake

rm -r -f bin/*
make -C project config=$conf

