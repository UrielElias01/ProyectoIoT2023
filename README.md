# Sistema de riego automatizado.
## Integrantes
- Ángel de Jesús Ortega Amaro
- Diego Emmanuel Cárdenas Baeza
- Fernando Mendoza García
- Ángel Uriel Elías Velázquez
## Objetivo general
- Nuestro proyecto como objetivo general tiene el optimizar el uso de agua a través de un mecanismo de riego automatizado, dependiendo de la humedad del suelo, ahorrando tiempo y dinero al consumidor.
### Objetivos específicos
- El programa detectará la humedad del suelo.
- Se abrirá automaticamente la llave de paso para cumplir su función.
- Ahorrar la suficiente cantidad de agua de acuerdo a la humedad del suelo.
- Ahorrar tiempo al consumidor.
## Tabla de Software utilizado
| Id | Software | Version | Tipo |
|----|----------|---------|------|
| 01 | Arduino IDE |1.8.57.0 |Entorno de programación |
| 02 | Firebase |10.4.0 |Alojador de nube |
|03 |App Inventor |2.0 | Enrtoreno de programación|
|04|Mosquitto| 5.0.3.1.1|Freeware|
|05|Node-Red|3.0|Freeware|

## Tabla con el hardware utilizado
| Id | Componente | Descripción | Imagen | Cantidad | Costo total |
|----|------------|-------------|--------|----------|-------------|
|01|ESP32|Es una solución de Wi-Fi/Bluetooth todo en uno, integrada y certificada que proporciona no solo la radio inalámbrica, sino también un procesador integrado con interfaces para conectarse con varios periféricos. |![image](https://user-images.githubusercontent.com/99992207/217118104-4f9fd4e0-7e79-4c2f-8dbb-960b21e69e99.png)|1 |$150 |
|02 |Raspberry Pi 4|Es una computadora de bajo costo y con un tamaño compacto, del porte de una tarjeta de crédito, puede ser conectada a un monitor de computador o un TV, y usarse con un mouse y teclado estándar. |![image](https://user-images.githubusercontent.com/99992207/217118234-a10f00f6-86c7-47f9-8340-2f267241881d.png)|1 |$3,200 |
|03 |Sensor DHT11 |Es un sensor digital de temperatura y humedad relativa de bajo costo y fácil uso. |![image](https://user-images.githubusercontent.com/99992207/217118292-7ca06b6c-9faa-48c5-94f6-4315757314da.png)|1 |$150 |
|04 |Modulo de reles |Es un dispositivo electromagnético que funciona como un interruptor controlado por un circuito eléctrico en el que, por medio de una bobina y un electroimán, se acciona un juego de uno o varios contactos que permiten abrir o cerrar otros circuitos eléctricos independientes. |![image](https://user-images.githubusercontent.com/99992207/217118354-3ae7ba1c-b630-4fed-a769-f9bd4ce01a6c.png)|1 |$30 |
|05 |Bomba de agua |Es un dispositivo operado eléctricamente, y es utilizado para controlar el flujo de líquidos o gases en posición completamente abierta o completamente cerrada |![bomba](https://user-images.githubusercontent.com/107594036/233724412-2b67da14-ad33-40f7-82d4-2fe0ffd956e1.jpg)|1 |$150 |
|06 |Memoria SD 32GB |Es una tarjeta de memoria flash extraíble utilizada para almacenar información digital, como programas y archivos. |![image](https://user-images.githubusercontent.com/99992207/217118451-4bbf6593-4918-4f3a-94ff-8c8dd54a541e.png) |1 |$120 |
|07 |Cables |Para incorporar la conexión desde las placas a los sensores. |![image](https://user-images.githubusercontent.com/99992207/217118498-fc44878e-69ca-4183-a520-b438c73fea94.png) |No definido |No definido |
|08|Sensor de Obstáculos|Dispositivo que permite detectar la presencia de objetos u obstaculos| ![sensor-de-obstaculos-reflectivo-infrarrojo](https://user-images.githubusercontent.com/107594036/233718176-97d0d843-146a-4e29-bfeb-cefb15bc95c2.jpg)|1 |$67|
|09|Sensor de Húmedad FC-28| Dispositivo que permite medir el nivel de la humadad en la tierra|![AR0371-H3](https://user-images.githubusercontent.com/107594036/233718034-af1c21d5-5f00-492d-8225-7b76bf80ca1f.jpg)|1 |$60 |
|10| Sensor de luz Fotorresistor| Sensor que nos permite medir el nivel o presencia de luz |![D_NQ_NP_689314-MLM45684799988_042021-O](https://user-images.githubusercontent.com/107594036/233718324-c1dd2d0f-0cf1-41cf-be42-17fb5be354af.jpg)|1 |$50|

## Epicas del proyecto (Minimo debe de haber una épica por integrante de equipo)
- Como usuario, poder ahorrar tiempo y dinero
- Como usuario, quiero poder guardar los datos de la humedad, dentro de una base datos
- Como usuario, quiero poder activar el sistema de riego desde una cierta distancia.
- Yo como usuario quiero poder controlar el flujo y tiempos de mi sistema de riego y humedad desde mi casa.

##Tabla de historias de usuario
## Tabla de historias de usuario
| Id | Historia de usuario | Prioridad | Estimación | Como probarlo | Responsable |
|----|---------------------|-----------|------------|---------------|-------------|
|01 | Control a distancia del encendido y apagado del sistema de riego.| Alta|1 semana | configuración del código y dispositivo remoto|Integrantes del equipo |
|02 | Funcionamiento de la valvula selenoide dependiendo de la humedad del suelo.|Alta | 4 semanas| Con la compilación del código|Integrantes del quipo |
|03 | La ESP32 debe de recopilar los datos tomados del sensor DHT11| Alta| 4-5 semanas| El alojamiento en la nube| Integrantes del equipo|
|04 | Encender y apagar el sistema de riego de forma automática y manual| Alta| 4-6 semanas|Con la compilación del código | Integrantes del equipo|


## Prototipo en dibujo
- ![IMG_20230208_130250](https://user-images.githubusercontent.com/107594036/217627468-9a8f2edd-f9d5-49c7-8476-7f0a284df8d3.jpg)
## Diagrama en fritzing 
![SistemaDeRiego](https://user-images.githubusercontent.com/107594036/234069243-360f91bc-a723-4363-9afa-f3d97dbae9ba.png)
## Código utilizado
  // Librerías necesarias
#include <DHT.h>
#include <WiFi.h>
#include <PubSubClient.h>
  // Variables y objetos
int sensorHumedad = 15 ;      // Sensor de humedad
int bomba = 4;                // Bomba de agua
int led_Bomba = 18;           // LED que se activa cuando la bomba de agua esta activa
int led_Obs = 21;             // LED que se activa cuando el sensor de obstaculos detecta una planta con cierta altura
#define obs_pin 25            // Sensor de obstaculos
#define fotorresistor_pin 14  // Fotorresistor
#define DHTTYPE DHT11         // Tipo de sensor DHT
#define DHTPIN 5              // Pin del DHT11
#define buzzer 19             // Pin del Buzzer
DHT dht(DHTPIN, DHTTYPE);     // Objeto DHT

  // Configuración de RED y Broker
const char* ssid = "UE";                    // SSID de la red
const char* password = "12345678";          // CONTRASEÑA de la red
const char* mqtt_server = "broker.emqx.io";   // IP del broker

  // Configuracion del wifi y broker
WiFiClient wifi_client;
PubSubClient mqtt_client(wifi_client);

  // Método setup
void setup() {
  Serial.begin(115200);
  dht.begin();
  pinMode(obs_pin , INPUT);
  pinMode(sensorHumedad, INPUT);
  pinMode(bomba, OUTPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(led_Bomba, OUTPUT);
  pinMode(led_Obs, OUTPUT);
  Serial.print("Conectando a red WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println("Conexión WiFi establecida.");
  mqtt_client.setServer(mqtt_server, 1883);
}

  // Método loop
void loop() {
    // Lectura de los sensores
  float h = dht.readHumidity();             // Lectura de humedad ambiental
  float t = dht.readTemperature();          // Lecuta de temperatura ambiental
  int fotorresistor_value = digitalRead(fotorresistor_pin); // Lectura del sensor de luz
  int obs = digitalRead(obs_pin);           // Lectura del sensor de obstaculos
  int hum = digitalRead(sensorHumedad);     // Lectura de la humedad de la tierra
  int act1 = digitalRead(bomba);
  int act2 = digitalRead(led_Bomba);
  int act3 = digitalRead(led_Obs);
  int act = act1 * act2 * act3;

    // Monitoreo de valores mediante el monitor serial
  Serial.println(" ");
  Serial.print("Humedad ambiental: ");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperatura ambiental: ");
  Serial.print(t);
  Serial.println("°C");
  Serial.print("Estado de los actuadores: ");
  Serial.println(act);
  Serial.println(" ");
  if (fotorresistor_value == HIGH) {
    Serial.println("Luz baja o no detectada, posible riego en proceso");
    if (hum == LOW) {
      Serial.print("Lectura de humedad en la tierra baja, accionando bomba");
      digitalWrite(bomba, HIGH);
      digitalWrite(led_Bomba, HIGH);
    } else {
      Serial.println("Tierra aún humeda, esperando lectura mas baja para accionar bomba");
    }
  } else {
    Serial.print("Luz detectada, esperando la noche para comenzar el riego");
    digitalWrite(bomba, LOW);
    digitalWrite(led_Bomba, LOW);
  }
  if (obs == HIGH) {
    Serial.print("Planta alta detectada, revisar la plantación para trasplantar");
    digitalWrite(led_Obs, HIGH);
    digitalWrite(buzzer, HIGH);
  } else {
    digitalWrite(led_Obs, LOW);
    digitalWrite(buzzer, LOW);
  }

    // Envío de datos via broker MQTT
  if (mqtt_client.connect("ESP32Cliente")) {
    String jsonTemp = "{\"id\":\"TempAmbiental\", \"sensor\":\"1\", \"value\":\""+String(t)+"\"}";
    String jsonHumd = "{\"id\":\"HumdAmbiental\", \"sensor\":\"1\", \"value\":\""+String(h)+"\"}";
    String jsonHumt = "{\"id\":\"HumedadTierra\", \"sensor\":\"2\", \"value\":\""+String(hum)+"\"}";
    String jsonFtrs = "{\"id\":\"Photoresistor\", \"sensor\":\"3\", \"value\":\""+String(fotorresistor_value)+"\"}";
    String jsonObst = "{\"id\":\"SensorObstacs\", \"sensor\":\"4\", \"value\":\""+String(obs)+"\"}";
    String jsonActs = "{\"id\":\"ActuadoresSis\", \"sensor\":\"5\", \"value\":\""+String(act)+"\"}";
    mqtt_client.publish("esp32chus/temp", jsonTemp.c_str());
    mqtt_client.publish("esp32chus/huma", jsonHumd.c_str());
    mqtt_client.publish("esp32chus/humt", jsonHumt.c_str());
    mqtt_client.publish("esp32chus/lgth", jsonFtrs.c_str());
    mqtt_client.publish("esp32chus/obst", jsonObst.c_str());
    mqtt_client.publish("esp32chus/acts", jsonActs.c_str());

      // A dashboard
//    mqtt_client.publish("esp32chus/t", String(t).c_str());
//    mqtt_client.publish("esp32chus/ha", String(h).c_str());
//   mqtt_client.publish("esp32chus/ht", String(hum).c_str());
//    mqtt_client.publish("esp32chus/l", String(fotorresistor_value).c_str());
//    mqtt_client.publish("esp32chus/o", String(obs).c_str());
  }  
  delay(10000);
}
## Fotos demostración del proyecto
![Imagen de WhatsApp 2023-04-24 a las 11 17 541](https://user-images.githubusercontent.com/107594036/234070491-6ee7472c-8012-4496-874f-6be6d8a3303f.jpg)
![Imagen de WhatsApp 2023-04-24 a las 11 17 54](https://user-images.githubusercontent.com/107594036/234070516-b6d0c5e8-aff9-4db2-b496-1f2722825ea4.jpg)
![Imagen de WhatsApp 2023-04-24 a las 11 17 53](https://user-images.githubusercontent.com/107594036/234070543-84de93f9-e024-422c-997a-bb2a4c385498.jpg)
![Imagen de WhatsApp 2023-04-24 a las 11 20 15](https://user-images.githubusercontent.com/107594036/234070575-0d22e2cc-5626-46fe-be9f-a113f1f605ff.jpg)
![Imagen de WhatsApp 2023-04-24 a las 11 20 162](https://user-images.githubusercontent.com/107594036/234070593-ad699d47-291d-498b-9aa8-4e74f4d2660f.jpg)
![Imagen de WhatsApp 2023-04-24 a las 11 20 161](https://user-images.githubusercontent.com/107594036/234070627-b4044090-fa46-4042-b0b7-d7984cb4f5ad.jpg)
![Imagen de WhatsApp 2023-04-24 a las 11 20 16](https://user-images.githubusercontent.com/107594036/234070670-b223cabb-1578-43bf-a15d-a33e1597c1c0.jpg)

## Video desmostrativo

