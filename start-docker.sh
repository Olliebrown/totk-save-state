#!/bin/bash
export MSYS_NO_PATHCONV=1

if [ -f ./totksavs-buildtools.cid ]; then
  echo "Reusing Existing Docker container ..."
  docker start -i -a $(cat ./totksavs-buildtools.cid)
else
  echo "Building New Docker container ..."
  docker build -t totksavs-buildtools .
  docker run --cidfile ./totksavs-buildtools.cid -v $(pwd):/totksavs -w /totksavs -i -t totksavs-buildtools bash
fi
