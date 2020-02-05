/*                                    UNIVERSIDDAD TECNICA DEL NORTE
 *                                            FICA CIERCOM
 *                          Nombre: Axel Almeida       Fecha: 04/02/2020
 * DEBER WDT
 * Realizar un programa que mediante comunicación serial ingrese el tiempo de reset del arduino de la siguiente forma: A-> 1 s B-> 2s C-> 4s D-> 8s
 * Hay que tener en cuenta que el sistema puede ser re configurado la veces necesarias(interrupciones).
 * 
*/
#include <avr/wdt.h>
#include <EEPROM.h>
#include <TimerOne.h>

int encendido = 0;
int cont = 0;
int in = 0;
String tiempo;

void setup() {
  Serial.begin(9600);
  attachInterrupt(0, menu, LOW);
  attachInterrupt(1, inicio, LOW);
  Serial.println("Sistema Wdt");
  Timer1.stop();
  cont = 0;
  in=0;
  tiempo=" ";

}

void loop() {
  if (encendido == 1) {
    if (Serial.available() > 0 ) {
      tiempo = Serial.readString();
      Timer1.initialize(1000000);
      Timer1.attachInterrupt(conteo);
    }
   
  }
}

void menu() {
  switch (encendido) {
    case 0:
      Serial.println("Ingrese el tiempo");
      encendido++;
      break;
    case 1:
      Serial.println(" ");
      encendido = 0;
      break;

  }
}
void conteo() {
  cont++;
 if(in==1){
 if(tiempo=="1"){
     Serial.println(String(2-cont));
    }
    if(tiempo=="2"){
     Serial.println(String(3-cont));
    }
    if(tiempo=="3"){
     Serial.println(String(5-cont));
    }
    if(tiempo=="4"){
     Serial.println(String(9-cont));
    }
 }
}
void inicio() {
  in++;
  if (tiempo == "1" && in == 1) {
    Serial.println("Reinicio 1S");
    wdt_enable(WDTO_1S);
  }
  if (tiempo == "2" && in == 1) {
    Serial.println("Reinicio 2S");
    wdt_enable(WDTO_2S);
  }
  if (tiempo == "3" && in == 1) {
    Serial.println("Reinicio 4S");
    wdt_enable(WDTO_4S);
  }
  if (tiempo == "4" && in == 1) {
    Serial.println("Reinicio 8S");
    wdt_enable(WDTO_8S);
  }
}
