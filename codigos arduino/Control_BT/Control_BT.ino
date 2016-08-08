/*
* Primer demo de comunicación de arduino con android por medio del modulo bluetooth HC-05
* Desarrollado y probado por SETISAEDU para las placas Arduino Mega y Arduino Due.
*/


//Declaracion de pines para los LEDs
int LED1=2;
int LED2=3;
int LED3=4;
int LED4=5;
int potenciometro; //Variable para guardar el valor analogico
unsigned char BluetoothData;

void setup() {
 //Inciacion de salidas digitales
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);

//Rutina de arranque
//Nota:esta parte solo para tener una indicacion visual de que el arduino ya esta arrancado
  digitalWrite(LED1,HIGH);
  digitalWrite(LED2,HIGH);
  digitalWrite(LED3,HIGH);
  digitalWrite(LED4,HIGH);
  delay(500);
  digitalWrite(LED1,LOW);
  digitalWrite(LED2,LOW);
  digitalWrite(LED3,LOW);
  digitalWrite(LED4,LOW);
 
 //Iniciacion del puerto serial para el Bluetooth
  Serial1.begin(115200); 
}

void loop() {
    //Espera de dato entrante del Bluetooth
    if (Serial1.available()){
    BluetoothData=Serial1.read(); 
    //Decision de accion a realizar
    if(BluetoothData=='D')
    {
      digitalWrite(LED1,HIGH);
    }else if(BluetoothData=='d')
    {
      digitalWrite(LED1,LOW);
    }else if(BluetoothData=='E')
    {
      digitalWrite(LED2,HIGH);
    }else if(BluetoothData=='e')
    {
      digitalWrite(LED2,LOW);
    }else if(BluetoothData=='F')
    {
      digitalWrite(LED3,HIGH);
    }else if(BluetoothData=='f')
    {
      digitalWrite(LED3,LOW);
    }else if(BluetoothData=='G')
    {
      digitalWrite(LED4,HIGH);
    }else if(BluetoothData=='g')
    {
      digitalWrite(LED4,LOW);
    }
  
  } 
   //Lectura de pines analogico y envio de datos
    Serial1.print("*P"); //Se usa la letra P para el poteciometro, como se declaro en la app
    potenciometro=analogRead(0);// Se lee el valor del potenciometro con el ADC del arduino
    Serial1.print(String(potenciometro)); // Se envia el valor leido
    Serial1.print("*"); // Se cierra la comunicacion usando un * extra al final

  //Retardo para evitar conflictos
   delay(200); 
}

