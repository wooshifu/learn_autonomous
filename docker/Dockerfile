FROM ubuntu:22.04


ENV DEBIAN_FRONTEND noninteractive

RUN apt-get update && \
    apt-get install -y ca-certificates gpg wget && \
    wget -O - https://apt.kitware.com/keys/kitware-archive-latest.asc 2>/dev/null | gpg --dearmor - | tee /usr/share/keyrings/kitware-archive-keyring.gpg >/dev/null && \
    echo 'deb [signed-by=/usr/share/keyrings/kitware-archive-keyring.gpg] https://apt.kitware.com/ubuntu/ jammy main' | tee /etc/apt/sources.list.d/kitware.list >/dev/null && \
    apt-get update && \
    rm /usr/share/keyrings/kitware-archive-keyring.gpg && \
    apt-get install -y kitware-archive-keyring cmake

RUN apt-get install -y \
    gcc \
    g++ \
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
    clang-format \
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
    libxtst-dev \
    libtool \
    '^libxcb.*-dev' \
    libx11-xcb-dev \
    libxrender-dev \
    libxkbcommon-dev \
    libxkbcommon-x11-dev \
    libopengl-dev \
    libegl-dev \
    libx11-dev \
    libxft-dev \
    libxext-dev \
    libwayland-dev \
    libegl1-mesa-dev \
    libibus-1.0-dev
