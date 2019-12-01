#include<stdlib.h>

/* Universidad Técnica del Norte
 *  
 *  Nombre: Axel Almeida
 *  Fecha: 30/11/2019
 *  
 * Realizar un programa que el número ingresado por comunicación serial se refleje en código binario hasta 8 bits con leds. 
 * Ejemplo: número ingresado 5 -> sistema con leds 00000101
 */


int numero;
int digito;
int cont;
double binario;//variables para numero decimal
int leds[8];//matriz de 8 led

int led1 = 6, led2 = 7, led3 = 8, led4 = 9, led5 = 10, led6 = 11, led7 = 12, led8 = 13; //pines de los leds

void setup() {
  Serial.begin(9600);

  pinMode(led1, OUTPUT);// asignamos los pines como salidas
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  Serial.println("INGRESE UN NUMERO");

}

void loop() {
  if (Serial.available() > 0 ) {
    numero = Serial.parseInt();//leemos el numero como entero
    while (numero < 0); //mientras el numero no sea menor que cero se sige repitiendo
    cont = 0;
    binario = 0;
    for (int i = 0; i < 8; i++) {// enceramos los led para nuevo valor
      leds[i] = 0;
    }
    while (numero != 0 ) {// mientra el numero sea diferente de cero seguira sacando el modulo  
      digito = numero % 2; // sacamos el modulo de el numero
      binario =  binario + digito ;
      leds[cont] = digito;
      cont++;
      numero = numero / 2;
      digito = 0;
    }
    digitalWrite(led8, leds[7]);// se pone el HIGH -->1 || LOW --> 0
    digitalWrite(led7, leds[6]);
    digitalWrite(led6, leds[5]);
    digitalWrite(led5, leds[4]);
    digitalWrite(led4, leds[3]);
    digitalWrite(led3, leds[2]);
    digitalWrite(led2, leds[1]);
    digitalWrite(led1, leds[0]);
  }
}

    
