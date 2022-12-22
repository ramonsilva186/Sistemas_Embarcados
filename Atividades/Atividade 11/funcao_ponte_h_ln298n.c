#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "soc/gpio_periph.h"
#include "esp_log.h"

#define delay(value) vTaskDelay(value/ portTICK_PERIOD_MS)

//ponte H LN298N
#define IN1 GPIO_NUM_25
#define IN2 GPIO_NUM_26
#define IN3 GPIO_NUM_27
#define IN4 GPIO_NUM_14

#define SENTIDO_HORARIO 1
#define SENTIDO_ANTIHORARIO 0
#define STOP 2
#define PONTO_MORTO 2
#define FREIO 3


static const char *TAG = "example";

void setup(void){
    gpio_reset_pin(IN1);
    gpio_reset_pin(IN2);
    gpio_reset_pin(IN3);
    gpio_reset_pin(IN4);
    gpio_set_direction(IN1, GPIO_MODE_OUTPUT);
    gpio_set_direction(IN2, GPIO_MODE_OUTPUT);
    gpio_set_direction(IN3, GPIO_MODE_OUTPUT);
    gpio_set_direction(IN4, GPIO_MODE_OUTPUT);
}

void ponteH_LN29N(int motor,int sentido){
    switch (motor){
        case 1:
            switch (sentido){
                case SENTIDO_HORARIO:
                    gpio_set_level(IN1, 1);
                    gpio_set_level(IN2, 0);
                    break;
                case SENTIDO_ANTIHORARIO:
                    gpio_set_level(IN1, 0);
                    gpio_set_level(IN2, 1);
                    break;
                case PONTO_MORTO:
                    gpio_set_level(IN1, 0);
                    gpio_set_level(IN2, 0);
                    break;
                case FREIO:
                    gpio_set_level(IN1, 1);
                    gpio_set_level(IN2, 1);
                    break;
            }
            break;
        
        case 2:
            switch (sentido){
                case SENTIDO_HORARIO:
                    gpio_set_level(IN3, 1);
                    gpio_set_level(IN4, 0);
                    break;
                case SENTIDO_ANTIHORARIO:
                    gpio_set_level(IN3, 0);
                    gpio_set_level(IN4, 1);
                    break;
                case PONTO_MORTO:
                    gpio_set_level(IN3, 0);
                    gpio_set_level(IN4, 0);
                    break;
                case FREIO:
                    gpio_set_level(IN3, 1);
                    gpio_set_level(IN4, 1);
                    break;
            }
            break;
    }
}

void app_main(void){
    setup();
    while (1){  

        ponteH_LN29N(1, SENTIDO_HORARIO);
        ESP_LOGI(TAG, "Rodando motor 1 em Sentido Horario");
        delay(5000);
        ponteH_LN29N(1, PONTO_MORTO);
        delay(5000);
        ponteH_LN29N(1, SENTIDO_ANTIHORARIO);
        ESP_LOGI(TAG, "Rodando motor 1 em Sentido Anti Horario");
        delay(5000);
        ponteH_LN29N(1, PONTO_MORTO);
        delay(5000);

        ponteH_LN29N(2, SENTIDO_HORARIO);
        ESP_LOGI(TAG, "Rodando motor 2 em Sentido Horario");
        delay(5000);
        ponteH_LN29N(2, PONTO_MORTO);
        delay(5000);
        ponteH_LN29N(2, SENTIDO_ANTIHORARIO);
        ESP_LOGI(TAG, "Rodando motor 2 em Sentido Anti Horario");
        delay(5000);
        ponteH_LN29N(2, PONTO_MORTO);
        delay(5000);

    }
}


