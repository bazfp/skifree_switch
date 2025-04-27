Skifree SDL for Nintendo Switch!
=================================

I always thought Nintendo Switch was missing this Windows 3.0 classic.

Has simple joystick controls and jump (A!).

You will get eaten.

A source port of the classic [Microsoft Entertainment Pack](https://en.wikipedia.org/wiki/Microsoft_Entertainment_Pack) game "skifree" to cross platform SDL2 and now running on the switch!

Introduced a Makefile for compiling with `DevKitPro` docker image for Nintendo Switch.

Forked again from the Skifree SDL by jeff-1amstudios 

Forked from the decompiled skifree [skifree_decomp](https://github.com/yuv422/skifree_decomp) by Eric Fry

![Untitled](https://github.com/jeff-1amstudios/skifree_sdl/assets/1063652/95b53385-4d16-4de5-8f9d-10a877fee6a9)

## Compiling for Nintendo Switch

Use the `DevKitPro` docker image https://hub.docker.com/r/devkitpro/devkita64

```sh
docker pull devkitpro/devkita64
# Set your local cd somewhere sensible as we're gonna bindmount it

docker run --mount type=bind,src=.,dst=/home/switchdev-it -it devkitpro/devkita64 bash
cd /home/switchdev-it
git clone https://github.com/bazfp/skifree_switch
cd skifree_switch

# grab resources
curl -Lo /tmp/ski32_resources.zip https://archive.org/download/ski32_resources/ski32_resources.zip
unzip -d resources /tmp/ski32_resources.zip

# Generate resources header
cmake -DSOURCE_DIR=/home/switchdev-it/skifree_sdl -DRESOURCES_GLOB=resources/* -P /home/switchdev-it/skifree_switch/cmake/EmbedResources.cmake
mv embedded_resources.h src/

# Just build it!
make
```

## Dependencies
### Resources
You will need to place the original gfx and icon resources into `resources/`.
You can download the original version
from the [official Skifree website](https://ski.ihoc.net/) and extract the resources with a a PE resources extractor (e.g. [ResourcesExtract](https://www.nirsoft.net/utils/resources_extract.html))

Alternatively, you can fetch pre-extracted resources: 
```sh
curl -Lo /tmp/ski32_resources.zip https://archive.org/download/ski32_resources/ski32_resources.zip
unzip -d resources /tmp/ski32_resources.zip
```

### Libraries
- SDL2
- SDL2_image
- SDL2_ttf

## Todo
- Sound maybe(?) - https://foone.wordpress.com/2017/06/20/uncovering-the-sounds-of-skifree/
