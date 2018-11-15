FROM ubuntu:18.10
ENV DEBIAN_FRONTEND=noninteractive

RUN \
  dpkg --add-architecture i386 && \
  apt update && \
  apt install -y --no-install-recommends libc6:i386 && \
  rm -rf /var/lib/apt/lists/*

COPY rage /root
RUN chmod 555 /root/rage

USER root
WORKDIR /root

CMD ["./rage"]
