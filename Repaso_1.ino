/*
   Universidad Técnica del Norte
   FICA-CIERCOM
   Sistemas Microprocesados

   Nombre: Axel Almeida
   Fecha: 29/11/2019

   Realizar un programa que por comunicación serial se ingrese el límite de lectura del conversor análogo digital (0-1024) si el valor
   del conversor supera dicho valor, se enciende un led.
*/

float conversor = 0;    // Obtencion del valor del puerto analogo-digital
float dato = 0;
int menor = 0;
int mayor = 0;
int num = 0;

void setup () {
  Serial.begin(9600);
   pinMode(2, OUTPUT);

  if (Serial.available() >= 0) {     //Lectura del serial

    Serial.println("ingrese valor menor");
    delay (1000);
    num = Serial.parseInt();
    Serial.println("ingrese valor mayor"); 
    delay (1000);                // Ingreso del mayor valor
    mayor = Serial.parseInt();
    Serial.print("valor menor es: ");    // Ingreso del menor valor
    Serial.println(num);
    Serial.print("valor mayor es : ");       // Mensaje de confirmacion
    Serial.print(mayor);
    delay (250);


  }
}
void loop() {
  conversor = analogRead(0);      //Lee los datos del puerto analogo-digital 0
  dato = conversor;
  if (num<dato && mayor>dato) {             // si el valor que ingreso al serial es menor al dato este imprimira el valor supera el limite
    digitalWrite(2, LOW);
  } else {
    Serial.println("el valor supera el limite");
    digitalWrite(2, HIGH);
  }

}
