// Output PWM signals on pins 0 and 1
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "tabla.h"
#define SONIDO_OUT 0
#define ON 1
#define OFF 0
#define RESOLUCION 512

void setDuty(int valor, uint canal)
{
    pwm_set_enabled(canal, true);
    pwm_set_chan_level(canal, PWM_CHAN_A, valor);    
}

int main() 
{
    int x=0;
    gpio_set_function(SONIDO_OUT, GPIO_FUNC_PWM);
    uint canal = pwm_gpio_to_slice_num(SONIDO_OUT);
    while(1)
    {
        pwm_set_wrap(canal,512);
        setDuty(valores[x],canal);
        sleep_us(hertz[20]);
        (x==RESOLUCION-1) ? x = 0: x++;
    }
}
