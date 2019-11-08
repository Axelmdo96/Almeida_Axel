/*
   Contador binario
*/




int leds[] = {8, 9, 10, 11, 12, 13}; //Vector de leds
int conta = 64;                      //Numero maximo del contador(6 bits)
int j = 0;
int i = 0;
#define btn 2                        //Defino al boton en la posicion 6

void setup() {
  
  pinMode(btn, INPUT);              //Declaro como entrada al boton
  for (j = 0; j < 6; j++) {
    pinMode(leds[j], OUTPUT);       //Declaro como salida al vector de leds
  }
  j = 0;                            //Reinicio la variable j 
}


void loop() {

  if (digitalRead(btn) == HIGH) {  //Funcionamiento del boton
    delay(300);  
    i++;                           // Contador

  }
  if (i >= 0 && i <= 64) {         //Condcion del valor maximo del contador
    contador(i);                   //Declaro el metodo creado

  } else {
    i = 0;                         //Reinicio la variable i
  }


}
void contador(byte binario) {      //Metodo para la lectura del numero binario, La variable byte ( pueden almacenar un número entre 0 y 255. )

  for (j = 0; j < 6; j++)         //Ciclo de encendido de leds en la posicion correspondiente
  {
    if (bitRead (binario, j) == 1) //bitRead (Lee un bit de un número.)
    {
      digitalWrite(leds[j], HIGH); //5v en el pin correspondiente al vector de leds en la posicion de j
    }
    else {
      digitalWrite(leds[j], LOW); //0v en el pin correpondiente al vector de leds en la posicion de j
    }
  }
}
