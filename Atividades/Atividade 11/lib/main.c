#include <stdio.h>
#include <strings.h>
#include <stdlib.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "soc/gpio_periph.h"
#include "esp_log.h"
#include "ponte_h.h"

#define delay(value) vTaskDelay(value/ portTICK_PERIOD_MS)

#define IN1 GPIO_NUM_25
#define IN2 GPIO_NUM_26
#define IN3 GPIO_NUM_27
#define IN4 GPIO_NUM_14


static const char *TAG = "example";

void app_main(void){
    // Comente um, antes de testar o outro;

    /* testando a ponte H LN29N */
    // inicializar(PONTE_H_LN29N, IN1, IN2, IN3, IN4);
    // motor_t motor = MOTOR_1;
    // while (1){ 
    //     motor = (motor == MOTOR_1) ? MOTOR_2 : MOTOR_1;
    //     selecionar_motor_ln29n(motor);
    //     rotacionar_horario();
    //     ESP_LOGI(TAG, "Rodando motor %d sentido horario", motor);
    //     delay(5000);
    //     rotacionar_antihorario();
    //     ESP_LOGI(TAG, "Rodando motor %d sentido antihorario", motor);
    //     delay(5000);
    //     parar_rotacao();
    //     ESP_LOGI(TAG, "Parando rotação do motor %d sentido antihorario", motor);
    //     delay(1000);
    // }

    /* testando a ponte H com 4 transistores */
    inicializar(PONTE_H_TRANSISTOR, IN1, IN2, IN3, IN4);
    while (1){ 
        rotacionar_horario();
        ESP_LOGI(TAG, "Rodando sentido horario");
        delay(5000);
        rotacionar_antihorario();
        ESP_LOGI(TAG, "Rodando sentido antihorario");
        delay(5000);
        parar_rotacao();
        ESP_LOGI(TAG, "Parando rotação do motor sentido antihorario");
        delay(1000);
    }
}


