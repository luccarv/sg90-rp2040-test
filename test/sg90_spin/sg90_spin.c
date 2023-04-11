#include "sg90.h"
#include "pico/stdlib.h"

int main()
{
    sg90_t* s = sg90_init(1);
    sg90_attach(s);
    sg90_write(s, 180);

    for(;;)
    {
        sg90_write(s, 180);
        sleep_ms(1500);
        sg90_write(s, 90);
        sleep_ms(1500);
        sg90_write(s, 0);
        sleep_ms(1500);
    }

    return 0;
}