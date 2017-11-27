#!/bin/bash

export CROSS_COMPILE=$(pwd)/arm-linux-androideabi-4.9/bin/arm-linux-androideabi-

#mkdir output

make -C $(pwd) O=output unofficial_kmini3g_defconfig
export KBUILD_BUILD_USER=Gapirov
export KBUILD_BUILD_HOST=Build
make -j2 -C $(pwd) O=output

cp output/arch/arm/boot/Image $(pwd)/arch/arm/boot/zImage
