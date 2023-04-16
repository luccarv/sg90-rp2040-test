#include "sg90.h"
#include "pico/stdlib.h"
#include <math.h>
#include <stdlib.h>

typedef struct
{
    float a;
    float b;
    float c;
}float3_t;

float3_t *invKin(float x, float y, float z, float l2, float l3)
{
    float3_t *angles = (float3_t*)malloc(sizeof(float3_t));

    angles->a = atan2(x, y) + M_PI;
    angles->c = acos((z*z + y*y + x*x - l2*l2 - l3*l3)/(2*l2*l3));
    angles->b = atan2(z, -sqrt(x*x + y*y)) - atan2(l3*sin(angles->c), l2 + l3*cos(angles->c));

    return angles;

}

void angleNormalize(float3_t *ang)
{
    ang->a -= M_PI;
    ang->b -= M_PI/2;
}

int main()
{
    sg90_t* s1 = sg90_init(1);
    sg90_t* s2 = sg90_init(2);
    sg90_t* s3 = sg90_init(3);


    for(;;)
    {

    }

    return 0;
}