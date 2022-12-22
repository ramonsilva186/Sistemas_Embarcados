#include <stdio.h>
#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

static const char *TAG = "example";

#define delay(value) vTaskDelay(value/ portTICK_PERIOD_MS)

#define datapin  GPIO_NUM_2 // DS
#define clockpin GPIO_NUM_1 // SHCP
#define latchpin GPIO_NUM_3 // STCP

#define ALTO  1
#define BAIXO 0


void setup(void) {
    gpio_set_direction(datapin,  GPIO_MODE_OUTPUT);
    gpio_set_direction(clockpin, GPIO_MODE_OUTPUT);
    gpio_set_direction(latchpin, GPIO_MODE_OUTPUT);
}

void clock(void) {
    gpio_set_level(clockpin, ALTO);
    delay(100);
    gpio_set_level(clockpin, BAIXO);
}


void shiftout(uint8_t data) {
    gpio_set_level(latchpin, ALTO);
    for (int i = 0; i < 8; ++i) {
    if (data & (1 << i)) { 
        ESP_LOGI(TAG, "Jogando 1 na posição %d", i);
        gpio_set_level(datapin, ALTO);
    }
    else {
        gpio_set_level(datapin, BAIXO);
        ESP_LOGI(TAG, "Jogando 0 na posição %d", i);

    }
    clock();
    }
    gpio_set_level(latchpin, BAIXO);

}

void app_main(void){
    setup();
    uint8_t data= 0;
    while(1){
        shiftout(data);
        delay(1000);
        data++;
    }
}