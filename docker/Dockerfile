FROM ubuntu:22.04


ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && \
    apt-get install -y ca-certificates gpg wget && \
    wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null && \
    echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ jammy main' | tee /etc/apt/sources.list.d/kitware.list >/dev/null && \
    apt-get update && \
    rm /usr/share/keyrings/kitware-archive-keyring.gpg && \
    apt-get install -y kitware-archive-keyring

RUN apt-get install -y \
    cmake \
    gcc \
    build-essential \
    ninja-build \
    curl \
    zip \
    unzip \
    nasm \
    bison \
    flex \
    git \
    lsb-release \
    openssl \
    clang-tidy \
    autoconf \
    autoconf-archive \
    pkg-config \
    gfortran \
    python3-distutils \
    python3-setuptools \
    python3-pip \
    linux-libc-dev \
    libxinerama-dev \
    libxcursor-dev \
    xorg-dev \
    libglu1-mesa-dev \
    libdbus-1-dev \
    libxi-dev \
    libxtst-dev
