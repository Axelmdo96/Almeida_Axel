/*
 * Universidad Técnica del Norte
 * FICA-CIERCOM
 * Sistemas Microprocesados
 * Nombre: Axel Almeida         Fecha: 14/01/20202
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9 ,8); 

void setup(){
  lcd.begin(16,2); // Inicializada el interface para la LCD                
  lcd.clear();                  
  lcd.setCursor(1,0); 
  lcd.print("Sistemas Microprocesados. Al fin Salio¡¡");   
  lcd.setCursor(1,1); 
  lcd.print("Axel Almeida");  
}

void loop()
{
  lcd.setCursor(16,1);
  lcd.autoscroll();     // el autoscroll hace que de desplacen los caracteres
  lcd.print(" ");      
  delay(200);
}
