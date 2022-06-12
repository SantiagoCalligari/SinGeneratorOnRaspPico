// Output PWM signals on pins 0 and 1
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "tabla.h"
#define LEDPIN 25
#define ON 1
#define OFF 0
 
setDuty(int valor, uint slice_num)
{
    pwm_set_enabled(slice_num, true);
    pwm_set_chan_level(slice_num, PWM_CHAN_B, valor);    
}

int main() 
{
    int x=0;
    gpio_init(LEDPIN);
    gpio_set_dir(LEDPIN, GPIO_OUT);
    gpio_put(LEDPIN, 1);
    sleep_ms(1000);
    gpio_put(LEDPIN, 0);
    // Tell GPIO 0 and 1 they are allocated to the PWM
    gpio_set_function(LEDPIN, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(LEDPIN);
    while(1)
    {
        pwm_set_wrap(slice_num, 20000); 
        //(x<180) ? setDuty(valores[x], slice_num): setDuty(valores[x]-10000, slice_num);
        setDuty(valores[x], slice_num);
        sleep_us(500);
        x++;
        (x==1440) ? x = 0: x;
    }
    // Note we could also use pwm_set_gpio_level(gpio, x) which looks up the
    // correct slice and channel for a given GPIO.
}
