/* Universidad Técnica del Norte
 *  FICA-CIERCOM
 *  Sistemas Microprosesados
 *  Nombre: Axel Almeida        Fecha: 14/01/2020

  Realizar un programa que mediante teclado matricial (consultar) ingrese el tiempo en segundos de una cuenta regresiva.
  Esta cuenta, decrece cada 1 segundo mediante timer.
*/



#include <Keypad.h>     
#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const byte FILAS = 4;     
const byte COLUMNAS = 4;    
char keys[FILAS][COLUMNAS] = {   
  {'7', '8', '9', 'A'},
  {'4', '5', '6', 'B'},
  {'1', '2', '3', 'C'},
  {'*', '0', '#', 'D'}
};

byte pinesFilas[FILAS] = {A0, A1, A2, A3}; 
byte pinesColumnas[COLUMNAS] = {7, 6, 5, 4}; 

Keypad teclado = Keypad(makeKeymap(keys), pinesFilas, pinesColumnas, FILAS, COLUMNAS);  

char tecla;       
char dato[2];        
byte nume = 0;      
int segundos;
int i = 0;
int valorSeg;
long value;

void setup()
{
  lcd.begin(16, 2);
  MsTimer2::set(1000, cuenta);
  MsTimer2::start();
  Serial.begin(9600);      
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Sistema On");
}

void loop() {
  tecla = teclado.getKey();  
  if (tecla)        
  {
    dato[nume] = tecla;    
    nume++;       
    value = atol(dato);
    lcd.setCursor(0, 1);
    lcd.print(value);
  }
}

void cuenta() {
  i--;
  valorSeg = value + 1;
  Serial.println(valorSeg);
  if (valorSeg == 0) {
    MsTimer2::stop();
  }
}
