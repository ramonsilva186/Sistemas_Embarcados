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

//ponte H com  4 transistores
#define A GPIO_NUM_25
#define B GPIO_NUM_26
#define C GPIO_NUM_27
#define D GPIO_NUM_14

#define SENTIDO_HORARIO 1
#define SENTIDO_ANTIHORARIO 0
#define STOP 2

static const char *TAG = "example";

void setup(void){
    gpio_reset_pin(A);
    gpio_reset_pin(B);
    gpio_reset_pin(C);
    gpio_reset_pin(D);
    gpio_set_direction(A, GPIO_MODE_OUTPUT);
    gpio_set_direction(B, GPIO_MODE_OUTPUT);
    gpio_set_direction(C, GPIO_MODE_OUTPUT);
    gpio_set_direction(D, GPIO_MODE_OUTPUT);
}

void ponteH_transistor(int sentido){
    switch (sentido)
    {
    case SENTIDO_HORARIO:
        gpio_set_level(A, 0);
        gpio_set_level(D, 0);
        delay(2);
        gpio_set_level(B, 1);
        gpio_set_level(C, 1);
        break; 
    case SENTIDO_ANTIHORARIO:
        gpio_set_level(B, 0);
        gpio_set_level(C, 0);
        delay(2);
        gpio_set_level(A, 1);
        gpio_set_level(D, 1);
        break; 
    case STOP:
        gpio_set_level(B, 0);
        gpio_set_level(C, 0);
        gpio_set_level(A, 0);
        gpio_set_level(D, 0);
        break;
    }
}


void app_main(void){
    setup();
    while (1){  

        ponteH_transistor(SENTIDO_HORARIO);
        ESP_LOGI(TAG, "Rodando em Sentido Horario");
        delay(5000);
        ponteH_transistor(STOP);
        delay(5000);
        ponteH_transistor(SENTIDO_ANTIHORARIO);
        ESP_LOGI(TAG, "Rodando em Sentido Anti Horario");
        delay(5000);
        ponteH_transistor(STOP);
        delay(5000);

    }
}


