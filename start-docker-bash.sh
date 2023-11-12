#!/bin/bash
export MSYS_NO_PATHCONV=1
docker build -t totksavs-buildtools .
docker run -v $(pwd):/totksavs -w /totksavs -i -t totksavs-buildtools bash
