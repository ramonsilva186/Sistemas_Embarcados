#include <stdio.h>
#include <esp_log.h>
#include <esp_system.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_spi_flash.h"
#include "dht.h"
#include "driver/gpio.h"
#include "ldr_lux.h"
#include "driver/adc.h"
#include "server-http.h"

#define sensorDH11 GPIO_NUM_33
#define lampada GPIO_NUM_25
#define delay(value) vTaskDelay(value * portTICK_PERIOD_MS)

const adc1_channel_t LDR = ADC1_CHANNEL_0;

static const char *TAG = "main";

float humidade = 0;
float temperatura = 0;
int luminosidade = 0;
int estado_lampada = 0;


void getInfoDht(void){
    dht_read_float_data(DHT_TYPE_DHT11, sensorDH11, &humidade, &temperatura);
    ESP_LOGI(TAG, "Humidade %.2f%% Temperatura: %.2f°C", humidade, temperatura);
}

void app_main(void)
{   

    ldr_lux_setup();

    server_init();

    while (1)
    {   

        getInfoDht();

        get_lux(&luminosidade);

    }
    
}
