#include "framework.h"

#include <glad/gl.h>

static int init()
{
    // 1. Load our shader program

    // 2. Load the sprite

    // 3. Load vertex positions in a buffer

    // 4. Load texture coordinates in another buffer

    // 5. Create a vertex array from the buffer

    // 6.a Bind vertex position to attribute location 0

    // 6.b Bind texture coordinates to attribute location 1

    // Return 0 for successful initialisation!
    return 0;
}

static void render()
{
    // 7. Clear the output

    // 8. Draw 4 vertices using our program and vertex array!
}

static void cleanup()
{
    // Destroy everything!
}

int main()
{
    workshop_on_init(init);
    workshop_on_render(render);
    workshop_on_cleanup(cleanup);

    return workshop_start("less gooo", 640, 480);
}
