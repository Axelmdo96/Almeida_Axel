 /*                                 UNIVERSIDAD TECNICA DEL NORTE
 *                                        FICA-CIERCOM
 *                        Nombre: Axel Almeida           Fecha: 04/02/2020
 * Realizar un ejercicio que cada 2 segundos el sistema se encuentre activado y cada 10 segundos
 * el sistema baje su consumo de corriente. Envíe mensajes de comunicación serial para mostrar el resultado.
*/

#include<TimerOne.h>
#include<EEPROM.h>
#include<avr/sleep.h>
#include<avr/power.h>
#include <avr/wdt.h>

int sistema;
int cont = 0;


void setup() {
  Serial.begin(9600);
  sistema = EEPROM.read(0);
  EEPROM.write(0, 1);
  attachInterrupt(0, wakeup, LOW);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  set_sleep_mode(SLEEP_MODE_PWR_SAVE);
  Serial.begin(9600);
  Serial.println(sistema);


}

void loop() {
  if (cont == 2 ) {
    Serial.println("ACTIVO");
    EEPROM.write(0, 1);
    Serial.println(sistema);
  }
  if (cont == 12) {
    Serial.println("DORMIDO");
    EEPROM.update(0, 0);
    sleep_mode();
    sleep_enable();
    sleep_disable();
  }
}

void conteo() {
  cont++;

}

void wakeup() {
  sleep_disable();
  Serial.println("REINICIO DEL SISTEMA");
  cont = 0;
}
