#!/bin/bash

# Build the example project as explained in the readme.

: ${BN:?"ERROR: run.sh requires env. var. BN to be set and not empty. It should be the example branch name checked out to run the example."}
DKRIMG=$BN:latest

# build docker image if it does not exist
[ "$(docker images | grep -c $BN)" -eq "0" ] && docker build --rm -f Dockerfile -t $DKRIMG .

# build command using docker image
docker run -v `pwd`:/data $DKRIMG make clean all
