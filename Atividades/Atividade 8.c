// atividade 8 Sistemas Embarcados, Allan dos Santos Batista Bastos

#include <stdio.h>

void q4(){
  int A = 8;
  int X = ~A;
  printf("A: %d\n", A);
  printf("B: %d\n", X);
  
}

void q5(){
  int res = 0x77 & 0x88;
  printf("operador &: %d\n", res);

  res = 0x77 && 0x88;
  printf("operador &&: %d\n", res);
  
  res = 0xAA | 0x55;
  printf("operador |: %d\n", res);

  res = 0xAA || 0x55;
  printf("operador ||: %d\n", res);
}


int main(void) {
  
  printf("\n\n---------------------------------\n\n");
  q4();
  printf("\n\n---------------------------------\n\n");
  q5();
  printf("\n\n---------------------------------\n\n");

  return 0;
}
/*
Saida Questão 4 e 5 atividade 8
---------------------------------

A: 8
B: -9


---------------------------------

operador &: 0
operador &&: 1
operador |: 255
operador ||: 1


---------------------------------
*/