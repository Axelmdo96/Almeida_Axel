/*
   Universidad Tecnica del Norte
   Nombre: Axel Almeida
   Fecha: 10/12/2019

   Realizar un ejercicio en el cual tenga las etapas de: (i)Ingreso de datos y (ii) ordenamiento
   (i)Al ingresar la palabra solo pueden ser números por comunicación serial.
   (ii) Una vez ingresados lo números, ordenarlos de menor a mayor e imprimirlo por comunicación serial.
*/

int cont = 0;
String str;
int num;
boolean a = false;
int i = 0;
int j = 0;
char vector[100];
char vector2[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
char vector3[100];
void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(0, interrupcion, RISING);
}

void loop() {
  if (cont == 1 && a == true) {
    if (Serial.available() >= 0) {
      str = Serial.readString();
    }
    for (i = 0; i < str.length(); i++) {
      if (str.charAt(i) == ',') {

      } else vector[i] = str.charAt(i);

    }
    a = false;
  }

  if (cont == 2 && a == false) {

    for (i = 0; i < 10; i++) {
      for (j = 0; j < str.length(); j++) {

        if (vector2[i] == vector[j]) {
          vector3[j] = vector2[i];
          Serial.print(vector3[j]);
        }
      }
    }
    a = true;
  }


}


void interrupcion() {
  switch (cont) {
    case 0:
      a = true;
      Serial.print("Ingrese los numeros separados por comas del 0 al 9: ");
      cont++;
      break;
    case 1:
      Serial.println(" ");
      Serial.print("1. Ordenamiento: ");
      cont++;
      break;
    case 2:
      Serial.println(" ");
      Serial.println("2. Reiniciar");
      
      cont = 0;
      i = 0;
      j = 0;
      a = false;
      break;
  }
}
