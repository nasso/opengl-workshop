# Creating a vertex array

You should now have a pair of shaders that are compiled and linked together to
form a shader program!

The next step will be to actually feed data to our program! The graphics
pipeline starts with the _Vertex Shader_, so we have to provide it _per-vertex
data_. We do so by creating what is called a _Vertex Array_ (makes sense,
right?).

Our triangle is made up of three vertices, so we will need three entries in our
vertex array. In the following table, each line represents a vertex in our
vertex array:

| X position | Y position |
| :--------: | :--------: |
|   `0.0`    |   `0.5`    |
|   `-0.5`   |   `0.5`    |
|   `0.5`    |   `-0.5`   |

A vertex can have any sort of data associated with it, not just its position!
For instance, we can associate a colour to each vertex:

| X position | Y position |  Red  | Green | Blue  |
| :--------: | :--------: | :---: | :---: | :---: |
|   `0.0`    |   `0.5`    | `1.0` | `0.0` | `0.0` |
|   `-0.5`   |   `0.5`    | `0.0` | `1.0` | `0.0` |
|   `0.5`    |   `-0.5`   | `0.0` | `0.0` | `1.0` |

## Buffers

In OpenGL, as with many other graphics API, a vertex array doesn't directly hold
the data associated with each vertex. Instead, a one-dimensional generic data
structure called a "buffer" is used to store arbitrary data that can then be
used to construct a vertex array.

Keeping the example above, we could have a buffer storing 2D vertex positions:

|  X1   |  Y1   |   X2   |  Y2   |  X3   |   Y3   |
| :---: | :---: | :----: | :---: | :---: | :----: |
| `0.0` | `0.5` | `-0.5` | `0.5` | `0.5` | `-0.5` |

Because buffers are one-dimensional data structures, vertex coordinates have to
be stored in an interleaved layout (`X1, Y1, X2, Y2, ...XN, YN`).

OpenGL provides a couple functions to manipulate buffers:

- `glGenBuffers`: to create buffers
- `glDeleteBuffers`: to destroy buffers
- `glBufferData`: to set the buffer contents
- `glBindBuffer`: to "bind" buffers (more on that in the next section)

### The OpenGL state machine

When programming with the OpenGL API, you will encounter many `glBind*`
functions. This is because OpenGL was designed around the concept of a "state
machine" where objects must be bound before being manipulated. In other words,
**you cannot use `glBufferData` before having bound your buffer with
`glBindBuffer`**:

```c
// first, bind the buffer...
glBindBuffer(GL_ARRAY_BUFFER, my_buffer);
// now that it is the current GL_ARRAY_BUFFER, you can set its data!
glBufferData(GL_ARRAY_BUFFER, /* ... */);
```

> **Pay attention to the arguments of `glBufferData`!** Look it up... None of
> them corresponds _directly_ to the buffer ID you want to manipulate.

### Buffers: checkpoint

Back to code! Create the following buffers for the vertex array we will be
creating in the next section:

|  X1   |  Y1   |   X2   |  Y2   |  X3   |   Y3   |
| :---: | :---: | :----: | :---: | :---: | :----: |
| `0.0` | `0.5` | `-0.5` | `0.5` | `0.5` | `-0.5` |

|  R1   |  G1   |  B1   |  R2   |  G2   |  B2   |  R3   |  G3   |  B3   |
| :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: | :---: |
| `1.0` | `0.0` | `0.0` | `0.0` | `1.0` | `0.0` | `0.0` | `0.0` | `1.0` |

The first one will contain vertex coordinates, and the second will contain
vertex colours. The data they contain should be an array of `float`s.

> Don't forget to delete the buffers at the end of your program!
