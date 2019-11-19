/*UNIVERSIDAD TÉCNICA DEL NORTE
   FICA-CIERCOM
   MICROPROCESADOS

   Nombre: Axel Almeida
   Fecha: 19-11-2019

   Deber Cedula:
   Recibir por comunicación serial la cédula ecuatoriana con la estructura 100337804-7 y validarla.
   Al final del proceso debe indicar si el dato es correcto o falso. Además confirmar que el total de caracteres ingresados son 11.
*/
#include<stdlib.h>

void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {   //si resive un dato funciona caso contrario no funciona
    String cedula = Serial.readString();
    validarCedula(cedula);
  }
}

void validarCedula(String cedula1) {
if (cedula1.length() == 11) {


  char digito1 = cedula1.charAt(0);   //Datos tipo char almacenan el valor de un caracter, trasformar a tipo char
  char digito2 = cedula1.charAt(1);  
  char digito3 = cedula1.charAt(2);
  char digito10 = cedula1.charAt(10);
  int validador[] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
  int valor;
  int total = 0;

  int n1 = digito1 - 48;        // El -48 es el 0 en ascii, almacena una variable int y la inicializa en 0
  int n2 = digito2 - 48;
  int n3 = digito3 - 48;
  int n10 = digito10 - 48;
  int total2 = 0;



  
    if (n1 >= 1 || n1 <= 2 && n2 >= 0 || n2 <= 4) {
      if (n3 < 6 && n3 >= 0) {                    //hace que cumpla con la condicion que solo el 3er digito debe ser menos a 6
        for (int i = 0; i < 9; i++) {
          valor = validador[i] * (((cedula1.charAt(i) - 48)));
          if (valor >= 10) {
            valor = valor - 9;
          }
          total = total + valor;
          total2 = 10 - (total % 10);     //Cumple la condicion, el total se divide para 10, toma el residuo y resta al 10
          if (total2 == 10) {
            total2 = 0;
          }

        }

        if (total2 == n10) {
          Serial.print(": ");
          Serial.println("Cedula correcta");
          delay(200);

        } else {
          Serial.print(": ");
          Serial.println("Cedula Incorrecta las condiciones no son validas");
          delay(200);

        }

      } else {
        Serial.print(": ");
        Serial.println("Cedula Incorrecta tercer digito incorrecto");
        delay(200);
      }

    } else {
      Serial.print(": ");
      Serial.println("Cedula Incorrecta primeros digitos incorrectos");
      delay(200);
    }
  } else if (cedula1.length() < 10) {
    Serial.print(": ");
    Serial.println("Cedula Incorrecta la cedula tiene menos de 10 digitos");
    delay(200);

  } else if (cedula1.length() > 10) {
    Serial.print(": ");
    Serial.println("Cedula Incorrecta la cedula tiene mas de 10 digitos");
    delay(200);

  }

}
