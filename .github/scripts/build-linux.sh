#!/bin/bash
set -e

if [ "${MATRIX_PLATFORM}" = "clang" ]
then
    export CC=clang
    export CXX=clang++
else
    export CC=gcc
    export CXX=g++
fi

if [[ "${GITHUB_REF_TYPE}" == "tag" ]]; then
    BUILD_TAG=${GITHUB_REF_NAME}
else 
    BUILD_TAG=$(git rev-parse --short HEAD)
fi

# install deps
sudo apt-get update -qq > /dev/null
sudo apt-get install -qq -y libsdl2-dev libsdl2-image-dev libsdl2-ttf-dev > /dev/null

# grab bitmap resources
curl -Lo /tmp/ski32_resources.zip https://archive.org/download/ski32_resources/ski32_resources.zip
unzip -d resources /tmp/ski32_resources.zip

# build
cmake -DCMAKE_BUILD_TYPE=RelWithDebInfo -DBUILD_TESTS=ON -B build
cmake --build build --

# package artifact
releasename="skifree_sdl-${BUILD_TAG}-linux-${PLATFORM_ARCH}"
rm -rf "$releasename"
mkdir "$releasename"
cp build/skifree_sdl "$releasename/skifree_sdl"
tar -czvf "$releasename.tar.gz" "$releasename"
echo "filename=$releasename.tar.gz" >>$GITHUB_OUTPUT

