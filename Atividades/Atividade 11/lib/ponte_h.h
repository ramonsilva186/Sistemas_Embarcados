#ifndef _PONTE_H_H
#define _PONTE_H_H

gpio_num_t PIN1;
gpio_num_t PIN2;
gpio_num_t PIN3;
gpio_num_t PIN4;

#define SENTIDO_HORARIO 1
#define SENTIDO_ANTIHORARIO 0
#define STOP 2
#define PONTO_MORTO 2
#define FREIO 3
#define delay(value) vTaskDelay(value/ portTICK_PERIOD_MS)

typedef enum {
    PONTE_H_LN29N = 1,
    PONTE_H_TRANSISTOR = 2,
} ponte_h_t;

typedef enum {
    MOTOR_1 = 1,
    MOTOR_2 = 2,
} motor_t;

void inicializar(ponte_h_t tipo, gpio_num_t in1, gpio_num_t in2, gpio_num_t in3, gpio_num_t in4);

void rotacionar_horario(void);

void rotacionar_antihorario(void);

void parar_rotacao(void);

void selecionar_motor_ln29n(motor_t motor);

#endif