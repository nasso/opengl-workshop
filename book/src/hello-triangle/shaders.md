# Your own shader program

It's time! Time for what you ask? Well, time to write your very own pair of GLSL
shaders of course!

You might be wondering what I'm talking about, so let's reiterate, shall we?

## What is a shader?

Shaders are pieces of software that run on your GPU. They are used to perform
specialised calculations based on a set of inputs in parallel. They are written
in a language specific to the graphics API you're using. The _OpenGL Shading
Language_, abbreviated as _GLSL_, is the one we're going to use today. Examples
of other shading languages include _HLSL_ (_High-Level Shading Language_),
mainly used by Microsoft's Direct3D APIs, _MSL_ (_Metal Shading Language_) for
Metal, by Apple, and _SPIR-V_, a portable binary format popularised by Vulkan.

> Don't worry! GLSL is actually very close to C! It just comes with fancy
> features that make it easier to write shaders: types such as `vec2`, `vec3`,
> `vec4` to represent vectors and built-in mathematical functions like
> `distance`, `normalize` and `cross`.

Depending on their role in the graphics pipeline, shaders can take several
names:

### Vertex shaders

Vertex shaders are executed once per vertex. The main job of a vertex shader is
to calculate the coordinates of each vertex that make up your scene. Typically,
this is where you would apply transformations and 3D projections.

```glsl
#version 330 core

layout(location = 0) in vec2 a_Position;

void main() {
    gl_Position = vec4(a_Position, 0.0, 1.0);
}
```

Here are a couple things to note about this example shader:

- It has a single input: `a_Position`, a 2D vector. The `layout(location = 0)`
  part just means "this is input #0".
- It constructs a 4D vector from `a_Position` and stores it into `gl_Position`.
  The `z` component is set to `0.0` and `w` (the fourth component) is set to
  `1.0`.

The main output of our vertex shader is the `gl_Position` variable, holding the
coordinates of a single point of the geometry we're drawing on screen!

> You might wonder why `gl_Position` is a `vec4` instead of a `vec2` or a
> `vec3`. This has to do with something called [homogeneous coordinates]. Don't
> worry too much about it for now, just keep in mind that `w` should be set to
> `1.0`!

[homogeneous coordinates]: https://en.wikipedia.org/wiki/Homogeneous_coordinates

The inputs of a vertex shader can be anything you want! For example, you could
keep it simple and just feed it plain 2D coordinates like in the example above.
But you could also feed it 3D coordinates and matrices, and let it do the math
to figure out the final 2D position! Don't worry, your GPU _loves_ doing math:
this is its duty.

_TODO: loading the vertex shader with opengl_

### Fragment (or pixel) shaders

_TODO_

### Compute shaders

_TODO_
