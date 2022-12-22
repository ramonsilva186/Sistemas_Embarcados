#include <stdio.h>
#include "driver/gpio.h"
#include "soc/gpio_periph.h"
#include <strings.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "ponte_h.h"

gpio_num_t PIN1;
gpio_num_t PIN2;
gpio_num_t PIN3;
gpio_num_t PIN4;

ponte_h_t TIPO;
motor_t  MOTOR_SELECIONADO;

void inicializar(ponte_h_t tipo, gpio_num_t in1, gpio_num_t in2, gpio_num_t in3, gpio_num_t in4)
{
    PIN1 = in1;
    PIN2 = in2;
    PIN3 = in3;
    PIN4 = in4;
    TIPO = tipo;
    gpio_reset_pin(PIN1);
    gpio_reset_pin(PIN2);
    gpio_reset_pin(PIN3);
    gpio_reset_pin(PIN4);
    gpio_set_direction(PIN1, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN2, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN3, GPIO_MODE_OUTPUT);
    gpio_set_direction(PIN4, GPIO_MODE_OUTPUT);

}

void ponteH_transistor(int sentido){
    switch (sentido)
    {
    case SENTIDO_HORARIO:
        gpio_set_level(PIN1, 0);
        gpio_set_level(PIN4, 0);
        delay(2);
        gpio_set_level(PIN2, 1);
        gpio_set_level(PIN3, 1);
        break; 
    case SENTIDO_ANTIHORARIO:
        gpio_set_level(PIN2, 0);
        gpio_set_level(PIN3, 0);
        delay(2);
        gpio_set_level(PIN1, 1);
        gpio_set_level(PIN4, 1);
        break; 
    case STOP:
        gpio_set_level(PIN2, 0);
        gpio_set_level(PIN3, 0);
        gpio_set_level(PIN1, 0);
        gpio_set_level(PIN4, 0);
        break;
    }
}

void ponteH_LN29N(motor_t motor, int sentido){
    switch (motor){
        case 1:
            switch (sentido){
                case SENTIDO_HORARIO:
                    gpio_set_level(PIN1, 1);
                    gpio_set_level(PIN2, 0);
                    break;
                case SENTIDO_ANTIHORARIO:
                    gpio_set_level(PIN1, 0);
                    gpio_set_level(PIN2, 1);
                    break;
                case PONTO_MORTO:
                    gpio_set_level(PIN1, 0);
                    gpio_set_level(PIN2, 0);
                    break;
                case FREIO:
                    gpio_set_level(PIN1, 1);
                    gpio_set_level(PIN2, 1);
                    break;
        break;
            }
            break;
        
        case 2:
            switch (sentido){
                case SENTIDO_HORARIO:
                    gpio_set_level(PIN3, 1);
                    gpio_set_level(PIN4, 0);
                    break;
                case SENTIDO_ANTIHORARIO:
                    gpio_set_level(PIN3, 0);
                    gpio_set_level(PIN4, 1);
                    break;
                case PONTO_MORTO:
                    gpio_set_level(PIN3, 0);
                    gpio_set_level(PIN4, 0);
                    break;
                case FREIO:
                    gpio_set_level(PIN3, 1);
                    gpio_set_level(PIN4, 1);
                    break;
            }
            break;
    }
}

void rotacionar_horario(void){
    if(TIPO == PONTE_H_TRANSISTOR){
        ponteH_transistor(SENTIDO_HORARIO);
    }else {
        ponteH_LN29N(MOTOR_SELECIONADO, SENTIDO_HORARIO);
    }
}

void rotacionar_antihorario(void){
    if(TIPO == PONTE_H_TRANSISTOR){
        ponteH_transistor(SENTIDO_ANTIHORARIO);
    }else {
        ponteH_LN29N(MOTOR_SELECIONADO, SENTIDO_ANTIHORARIO);
    }
}

void parar_rotacao(void){
    if(TIPO == PONTE_H_TRANSISTOR){
        ponteH_transistor(STOP);
    }else {
        ponteH_LN29N(MOTOR_SELECIONADO, STOP);
    }
}

void selecionar_motor_ln29n(motor_t motor){
    MOTOR_SELECIONADO = motor;
}

