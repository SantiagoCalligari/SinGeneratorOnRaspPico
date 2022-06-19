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
		
float Hz(int frecuencia)
{return hertz[frecuencia];}
		
void setDuty(int valor, int canal)
{pwm_set_chan_level(canal, A, valor);}//Mandamos nuestra señal
		//por el canal hasta el 
		//valor dado.
				
int main() 
{                                      
	int iterar = 0;//Creamos un canal PWM en el pin de Sonido
	int canal = pwm_gpio_to_slice_num(SONIDO_OUT);
	//Convertimos el pin de sonido de GPIO a PWM.
    gpio_set_function(SONIDO_OUT, PWM);
    pwm_set_enabled(canal, true);//Iniciamos PWM en el canal      
	while(1) //Loop Infinito
	{
		//Ponemos la ventana igual a nuestra Resolucion.
		pwm_set_wrap(canal, RESOLUCION*2);
		setDuty(valores[iterar], canal);
		//dormimos el tiempo suficiente para nuestra F.
		sleep_us(Hz(1));                
	
        (iterar == RESOLUCION-1) ? iterar = 0 : iterar++;
	}
}
