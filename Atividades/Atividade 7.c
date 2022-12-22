// codigo em C

#include <stdio.h>

void q3(void);
void q4(void);
void q5(void);
void q6(void);
void q7(void);

int main(void) {

  printf("\n\n----- Resposta Atividade 7 -----\n\n");
  
  printf("Questão 3:\n\n");
  q3();
  
  printf("\n\n---------------------------------\n\n");
  
  printf("Questão 4\n\n");
  q4();

  printf("\n\n---------------------------------\n\n");
  
  printf("Questão 5\n\n");
  q5();

  printf("\n\n---------------------------------\n\n");

  printf("Questão 6\n\n");
  q6();

  printf("\n\n---------------------------------\n\n");

  printf("Questão 7\n\n");
  q7();

  printf("\n\n---------------------------------\n\n");
  
  return 0;
}

void q3 (void){
 char matricula[15] = "201821250026";
 char nome[50] = "Allan dos Santos Batista Bastos";
 char sexo = 'M'; 
 float salario = 1200.00;

  printf("Nome: %s \nMatricula: %s \nSexo: %c\nSalario: %2.f", nome, matricula, sexo, salario);
}

void q4 (void){
  int X  = 2;
  float Y = 3.0;
  double Z = 8.00;
  char W = 'a';

  printf("X = %dB, Y = %dB, Z = %dB, W = %dB", sizeof(X), sizeof(Y), sizeof(Z), sizeof(W));
  
}

void q5 (void){
  int X  = 4;
  float Y = 3.5;
  float Z = 8.44;
  
  float calculo  =  X*6/Y+Z/X; 
  printf("%f\n", calculo);
  
  calculo = (1+X)/Y - Z/Y;
  printf("%f\n", calculo);
  
  calculo = 2*Y+(X/Z) - 1;
  printf("%f", calculo);
}

void q6 (void){
 double numero = 158.96;

  printf("Parte Inteira : %d\n",(int) numero);
  printf("Parte Decimal : %f", numero - ((int)numero));

}

int port;

void func_A(){
  port = 255;
}

void func_B(){
  printf("%d", port); 
}

void q7 (void){
  func_A();
  func_B();
}

// Saida 
/*
----- Resposta Atividade 7 -----

Questão 3:

Nome: Allan dos Santos Batista Bastos 
Matricula: 201821250026 
Sexo: M
Salario: 1200

---------------------------------

Questão 4

X = 4B, Y = 4B, Z = 8B, W = 1B

---------------------------------

Questão 5

8.967143
-0.982857
6.473934

---------------------------------

Questão 6

Parte Inteira : 158
Parte Decimal : 0.960000

---------------------------------

Questão 7

255

---------------------------------

*/