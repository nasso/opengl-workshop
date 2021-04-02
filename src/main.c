#include "framework.h"
#include <glad/gl.h>

/* Create everything! */
static int init()
{
    // Return 0 for successful initialisation!
    return 0;
}

/* Render everything! */
static void render()
{
}

/* Destroy everything! */
static void cleanup()
{
}

/* Start everything! */
int main()
{
    workshop_on_init(init);
    workshop_on_render(render);
    workshop_on_cleanup(cleanup);

    return workshop_start("less gooo", 640, 480);
}
