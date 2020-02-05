/*
 *                                              UNIVERSIDAD TECNICA DEL NORTE
 *                                                       FICA CIERCOM
 *                                      Nombre: Axel Almeida         Fecha: 04/02/2020
 * Realizar un programa que cada 5 segundos el sistema desactiva el conversor análogo digital,
 * cada 8 segundos la comunicación serial y cada 12 segundos un desactivación total. Esta
 * información debe verse en una LCD.
*/

#include <LowPower.h>
#include <avr/wdt.h>
#include<avr/sleep.h>
#include <avr/power.h>
#include <EEPROM.h>
#include <MsTimer2.h>
#include <TimerOne.h>

#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int number = EEPROM.read(0);
int LcdA = 7;
int cont = 0;
int dato;


void setup() {
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(conteo);
  power_all_enable();
  lcd.begin(16, 2);
  number = 0;
}

void loop() {
  Serial.println(number);
  desactivado();
  lcd.setCursor(6, 1);
  lcd.print("Tiempo:" + String(cont));
  dato = analogRead(0);
  lcd.setCursor(0, 1);
  lcd.print(dato);
}
void conteo() {
  cont++;
}

void desactivado() {
  if (cont == 5) {                    // Conversor analogo digital desactivo durante 5s
    number = number + 1;
    lcd.setCursor(0, 0);
    lcd.print("CAanlogoDigital OFF");
    power_adc_disable();

  }
  if (cont == 8) {                    // Comunicacion Serial desactivada
    lcd.setCursor(0, 0);
    lcd.print("                     ");
    lcd.setCursor(0, 0);
    lcd.print("CX OFF");
    power_spi_disable();
  }
  if (cont == 12) {                     //Sistemas desactivado en 12s
    lcd.setCursor(0, 0);
    lcd.print("                    ");
    lcd.setCursor(0, 0);
    lcd.print("Sistema OFF");
    power_all_disable();
  }
  if (EEPROM.read(0) > 12) {        // Se guarda la informacion en la memoria eeprom para que recuerde que cada 12s debe apagar todo el sistema
    number = 0;
    power_all_enable();
    EEPROM.write(0, number);
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("REINICIO");
    lcd.setCursor(0, 1);
    lcd.print("DEL SISTEMA");
    digitalWrite(LcdA, HIGH);
    delay(10);
    wdt_enable(WDTO_1S);

  }
}
