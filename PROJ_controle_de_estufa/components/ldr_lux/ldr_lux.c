/* ADC2 Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/adc.h"
#include "driver/dac.h"
#include "esp_system.h"
#include "math.h"
#include "esp_log.h"

static const char *TAG = "main";

#define delay(value) vTaskDelay(value * portTICK_PERIOD_MS)
#define ADC_CHANNEL ADC2_CHANNEL_7
#define ADC_ATTEN ADC_ATTEN_11db

static const int MAX_ADC_READING = 4095;
static const int ADC_REF_VOLTAGE = 5;
static const int REF_RESISTANCE = 7645;
static const int LUX_CALC_SCALAR = 12518931 ;
static const int LUX_CALC_EXPONENT = -1.405;

static const adc_bits_width_t width = ADC_WIDTH_BIT_12;

void calcularLux(int raw, int *lux){
    float resistorVoltage = (float)raw / MAX_ADC_READING * ADC_REF_VOLTAGE;
    float ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
    float ldrResistance = ldrVoltage/resistorVoltage * REF_RESISTANCE; 
    float ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT); 
    *lux = ldrLux;
}


void getLux(int* variavel_lux){

    printf("Calculando Get Lux");
    int read_raw;
    adc2_config_channel_atten( ADC_CHANNEL, ADC_ATTEN );
    delay(2);
    printf("start conversion.\n");

    adc2_get_raw( ADC_CHANNEL, width, &read_raw);
    calcularLux(read_raw, &variavel_lux);
    ESP_LOGI(TAG, "Valor lido: %d |\t V: %f |\t lux: %d", read_raw, (read_raw/4095.0) * 5.0,