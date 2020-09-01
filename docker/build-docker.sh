#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-auscashpay/auscashd-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/auscashd docker/bin/
cp $BUILD_DIR/src/auscash-cli docker/bin/
cp $BUILD_DIR/src/auscash-tx docker/bin/
strip docker/bin/auscashd
strip docker/bin/auscash-cli
strip docker/bin/auscash-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker
