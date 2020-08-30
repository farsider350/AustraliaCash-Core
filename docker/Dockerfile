FROM debian:stretch
LABEL maintainer="AusCash Developers <dev@auscash.org>"
LABEL description="Dockerised AusCashCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/
