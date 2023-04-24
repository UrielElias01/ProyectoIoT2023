//Creación de variables
#include <DHT.h> 
#define DHTTYPE DHT11
int sensorHumedad = 15 ; //sensor de humedad
int bomba= 4;//bomba de agua
int led_Bomba = 18;
int led_Obs = 21;
#define obs_pin 25 //obstaculos
#define fotorresistor_pin 14 //fotorresistor
#define DHTPIN 5 //DHT11
#define buzzer 19 

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  dht.begin();
  pinMode(obs_pin , INPUT);
  pinMode(bomba, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_Bomba, OUTPUT);
  pinMode(led_Obs, OUTPUT);
  Serial.begin(115200);
}

void loop() {

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  

  if(isnan(h) || isnan(t)){
    Serial.println("Error");
    return;
  }

  int fotorresistor_value = analogRead(fotorresistor_pin);
  int pl = fotorresistor_value * 0.01;
  int value = 0;
  value = digitalRead(obs_pin);

  //Monitoreo de valores
  Serial.println(" ");
  Serial.print("Humedad: ");
  Serial.print(h);
  Serial.println("%\t");
  Serial.print("Temperatura: ");
  Serial.print(t);
  Serial.println("°C ");


  //**************************************
  Serial.print("Humedad:");
  Serial.println(analogRead(sensorHumedad)); //Leer la humedad del sensor
  delay(500);

  Serial.print("Luz: ");
Serial.print(pl);
Serial.println("%");

// Sensor de obstaculos
if (value == HIGH) {
     Serial.println("Obstaculo: Detectado");
     digitalWrite(buzzer, HIGH);
     digitalWrite(led_Obs, HIGH);
  }else{
    Serial.println("Obstaculo: No detectado");
    digitalWrite(buzzer, LOW);
    digitalWrite(led_Obs, LOW);
  }
  
if(analogRead(sensorHumedad) >=3500){
  digitalWrite(bomba,HIGH);
  digitalWrite(led_Bomba, HIGH);
}else if(analogRead(sensorHumedad) <= 500){
  digitalWrite(bomba,LOW);
  digitalWrite(led_Bomba, LOW);
}
}