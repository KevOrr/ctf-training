FROM ubuntu:18.10
ENV DEBIAN_FRONTEDN=noninteractive

RUN apt update
RUN apt install -y gcc-multilib

RUN adduser --home /home/epa --disabled-password --gecos "" epa
COPY epa /home/epa
RUN chmod 6555 /home/epa/epa

COPY flag /home/epa
RUN chmod 400 /home/epa/flag

USER epa
WORKDIR /home/epa

CMD ["/bin/bash"]
