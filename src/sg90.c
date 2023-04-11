#include "sg90.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdlib.h>

sg90_t* sg90_init(uint8_t pin) 
{  
    if(pin > 16)
    {
        return NULL;
    }

    sg90_t *s = (sg90_t*)malloc(sizeof(sg90_t));
    
    s->gpio_pin = pin;
    s->pwm_channel = pwm_gpio_to_channel(s->gpio_pin);
    s->pwm_slice = pwm_gpio_to_slice_num(s->gpio_pin);

    s->attached = 0;

    return s;
}

void sg90_attach(sg90_t *s) 
{
    if(s)
    {
        gpio_set_function(s->gpio_pin, GPIO_FUNC_PWM);
        
        pwm_set_clkdiv(s->pwm_slice, sg90_CLK_DIV);
        pwm_set_wrap(s->pwm_slice, 65465);
        pwm_set_chan_level(s->pwm_slice, s->pwm_channel, 3276.75f);

        pwm_set_enabled(s->pwm_slice, 1);
        s->attached = 1;
    }
    return;
}

void sg90_dettach(sg90_t *s)
{
    if(s)
    {
        pwm_set_enabled(s->pwm_slice, 0);
        s->attached = 0;
    }
    return;
}

uint8_t sg90_isAttached(sg90_t *s)
{

    return s->attached;
}

void sg90_write(sg90_t *s, uint8_t angle)
{
    if(s)
    {
        if(angle > 180)
            angle = 180;
        else if(angle < 0)
            angle = 0;

        pwm_set_chan_level(s->pwm_slice, s->pwm_channel, 3276.75f*angle/180 + 3276.75f);
    }

    return;
}