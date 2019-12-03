/*
 * Universidad Tecnica del Norte
 * FICA-CIERCOM
 * Sistemas Microprosesados
 * 
 * Nombre: Axel Almeida
 * Fecha: 02/12/2019
 * 
 * Realizar un programa que active 4 juegos de luces con 5 leds al ingresar datos por comunicación serial de la siguiente forma:
 * ACBF-> Activa juego 1 ACGF -> Activa juego 2 ADBF -> Activa juego 3 ADBH -> Activa juego 4
 */
String Palabra;
int i = 0; //creamos e inicializamos el contador i
int j = 0; //creamos e inicializamos el contador j
int leds[14] = {5, 6, 7, 8, 9, 10, 11, 12, 13};
void setup() {
  pinMode (5, OUTPUT);//declaramos al pin como salida
  pinMode (6, OUTPUT);//declaramos al pin como salida
  pinMode (7, OUTPUT);//declaramos al pin como salida
  pinMode (8, OUTPUT);//declaramos al pin como salida
  pinMode (9, OUTPUT);//declaramos al pin como salida
  pinMode (10, OUTPUT);//declaramos al pin como salida
  pinMode (11, OUTPUT);//declaramos al pin como salida
  pinMode (12, OUTPUT);//declaramos al pin como salida
  pinMode (13, OUTPUT);//declaramos al pin como salida
  Serial.begin(9600);
//  Serial.println("JUEGO 1 --> ACBF ");
//  Serial.println("JUEGO 2 --> ACGF");
//  Serial.println("JUEGO 3 --> ADBF");
//  Serial.println("JUEGO 4 --> ADBH");
  Serial.println("INGRESE CODIGO DE JUEGO");

}

void loop() {
  if (Serial.available() > 0) {
    Palabra = Serial.readString();
    if (Palabra.equals("ACBD")) {
      Serial.println("juego1");
      juego_1();
    }
    if (Palabra.equals("ACGF")) {
      Serial.println("juego2");
      juego_2();
    }
    if (Palabra.equals("ADBF")) {
      Serial.println("juego3");
      juego_3();
    }
    if (Palabra.equals("ADBH")) {
      Serial.println("juego4");
      juego_4();
    }
  }
  Palabra=" ";
}

//////

void juego_1() { //creamos el metodo del juego 1
  for (i = 0; i < 14; i++) { //este ciclo permite determinar la secuencia en que los pines se pondran en alto
    digitalWrite(leds[i], HIGH);
    delay(200);
  }
  for (i = 14; i >= 0; i--) { //este ciclo hace que los leds se apaguen en secuencia contraria al encendido.
    digitalWrite(leds[i], LOW);
    delay(200);
  }
}
void juego_2() { //creamos el metodo del juego 2
  for (i = 0, j = 13; i < 13; i++, j--) { //para este ciclo utilizamos dos contadores ya que los leds se encenderan al mismo tiempo, empezando desde los extremos
    digitalWrite(leds[i], HIGH), digitalWrite(leds[j], HIGH);
    delay(100);
  }
  for (i = 7, j = 7; i >= 0; i--, j++) { //este ciclo cumple la funcion de apagar los leds en secuencia contraria al encendido, igualmente usamos dos contadores
    digitalWrite(leds[i], LOW), digitalWrite(leds[j], LOW);
    delay(100);
  }
}
void juego_3() { //creamos el metodo del juego 3
  for (i = 0, j = 6; i < 12; i++, j++) { //este ciclo utiliza dos contadores y permite que los leds se enciendan y apaguen en pares con un led apagado en medio de ellos.
    digitalWrite(leds[i], HIGH), digitalWrite(leds[j], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW), digitalWrite(leds[j], LOW);
    delay(100);
  }
}
void juego_4() { //creamos el metodo del juego 3
  for (i = 0, j = 0; i < 10; i++, j--) { //este ciclo utiliza dos contadores y permite que los leds se enciendan y apaguen en pares con un led apagado en medio de ellos.
    digitalWrite(leds[i], HIGH), digitalWrite(leds[j], HIGH);
    delay(100);
    digitalWrite(leds[i], LOW), digitalWrite(leds[j], LOW);
    delay(100);
  }
}
