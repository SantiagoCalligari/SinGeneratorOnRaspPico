#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "tabla.h"       //Nuestras Dos Tablas de consulta.
#define SONIDO_OUT 0     //Pin de salida.
#define ON 1
#define OFF 0
#define RESOLUCION 256   //Cantidad De Valores de Nuestra 
//Tabla de Consulta de Senos
#define A PWM_CHAN_A     //Abreviaturas
#define PWM GPIO_FUNC_PWM//Abreviaturas
		
void setDuty(int valor, int canal)
{
    pwm_set_chan_level(canal, A, valor);}//Mandamos nuestra señal
		//por el canal hasta el 
		//valor dado.
				
int main() 
{                                      
	int iterar = 0;//Creamos un canal PWM en el pin de Sonido
	int canal = pwm_gpio_to_slice_num(SONIDO_OUT);
	//Convertimos el pin de sonido de GPIO a PWM.
    gpio_set_function(SONIDO_OUT, PWM);
    pwm_set_enabled(canal, true);//Iniciamos PWM en el canal      
	pwm_set_wrap(canal, RESOLUCION*2);
	while(1) //Loop Infinito
	{
		//Ponemos la ventana igual a nuestra Resolucion.
		setDuty(valores[iterar], canal);
        //sleep_us(1543525);
		//dormimos el tiempo suficiente para nuestra F.             
        if(iterar == 256) iterar = 0;
        else
            iterar++;
	}
}
