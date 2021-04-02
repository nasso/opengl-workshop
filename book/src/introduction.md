<!-- markdownlint-disable MD033 -->
<!-- markdownlint-disable MD041 -->

<img class="light-only" src="res/OpenGL_170px_June16.png">
<img class="dark-only" src="res/OpenGL_White_170px_June16.png">

# Introduction

Welcome to my OpenGL workshop! This workshop will walk you through the
realisation of a minimal C program capable of displaying a (transparent) sprite
using modern OpenGL (>= 3.3).

## What's OpenGL?

OpenGL is a graphics API that gives you the power to use your video card for
graphical rendering. Without it, you would have to manually compute the colour
for every single pixel you would like to draw using the CPU. That's horrendously
slow, because you have to iterate through every single pixel one by one in
sequence!

Instead, many computers have a Graphical Processing Unit (GPU for short). It is
much more efficient because it's able to render different parts of your scene in
parallel! To be able to communicate with it in your programs, many different
APIs exist, each with a different set of capabilities and platform support:

| Platform | OpenGL | Direct3D | Vulkan | Metal |
| -------: | :----: | :------: | :----: | :---: |
|  Windows |   ++   |   +++    |   ++   |   -   |
|    Linux |   ++   |    -     |  +++   |   -   |
|  Android |   ++   |    -     |  +++   |   -   |
|      Mac |   +    |    -     |  +\*   |  +++  |
|      iOS |   +    |    -     |  +\*   |  +++  |

\*: non-official support through third-party software

These aren't the only low-level graphics APIs to exist, but they are the main
supported ones.

## What are we making?

To give you a rough understanding of how the OpenGL API is structured, we're
going to render a basic 2D sprite on the screen. It may sound easy at first if
you're used to higher level APIs such as the SFML (right?), but being a low
level API, OpenGL requires us to follow quite a bunch of steps in order to reach
our goal:

1. Create a shader program
2. Load the sprite's texture
3. Create a buffer containing vertex coordinates
4. Create another buffer for texture coordinates
5. Define an array of vertices using the two buffers
6. Bind vertex data to variables in our shader
7. Clear the output framebuffer
8. Draw all 4 vertices in our vertex array using our shader and texture!

Don't worry, we'll go through each of those steps one by one!
