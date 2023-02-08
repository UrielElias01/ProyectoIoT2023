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
## Tabla con el hardware utilizado
| Id | Componente | Descripción | Imagen | Cantidad | Costo total |
|----|------------|-------------|--------|----------|-------------|
|01|ESP32|Es una solución de Wi-Fi/Bluetooth todo en uno, integrada y certificada que proporciona no solo la radio inalámbrica, sino también un procesador integrado con interfaces para conectarse con varios periféricos. |![image](https://user-images.githubusercontent.com/99992207/217118104-4f9fd4e0-7e79-4c2f-8dbb-960b21e69e99.png)|1 |$150 |
|02 |Raspberry Pi 4|Es una computadora de bajo costo y con un tamaño compacto, del porte de una tarjeta de crédito, puede ser conectada a un monitor de computador o un TV, y usarse con un mouse y teclado estándar. |![image](https://user-images.githubusercontent.com/99992207/217118234-a10f00f6-86c7-47f9-8340-2f267241881d.png)|1 |$3,200 |
|03 |Sensor DHT11 |Es un sensor digital de temperatura y humedad relativa de bajo costo y fácil uso. |![image](https://user-images.githubusercontent.com/99992207/217118292-7ca06b6c-9faa-48c5-94f6-4315757314da.png)|1 |$150 |
|04 |Modulo de reles |Es un dispositivo electromagnético que funciona como un interruptor controlado por un circuito eléctrico en el que, por medio de una bobina y un electroimán, se acciona un juego de uno o varios contactos que permiten abrir o cerrar otros circuitos eléctricos independientes. |![image](https://user-images.githubusercontent.com/99992207/217118354-3ae7ba1c-b630-4fed-a769-f9bd4ce01a6c.png)|1 |$30 |
|05 |Valvula selenoide |Es un dispositivo operado eléctricamente, y es utilizado para controlar el flujo de líquidos o gases en posición completamente abierta o completamente cerrada |![image](https://user-images.githubusercontent.com/99992207/217118402-d3605aa6-5941-4eb9-b7ed-9a51386066a4.png)|1 |$150 |
|06 |Memoria SD 32GB |Es una tarjeta de memoria flash extraíble utilizada para almacenar información digital, como programas y archivos. |![image](https://user-images.githubusercontent.com/99992207/217118451-4bbf6593-4918-4f3a-94ff-8c8dd54a541e.png) |1 |$120 |
|07 |Cables |Para incorporar la conexión desde las placas a los sensores. |![image](https://user-images.githubusercontent.com/99992207/217118498-fc44878e-69ca-4183-a520-b438c73fea94.png) |No definido |No definido |

## Epicas del proyecto (Minimo debe de haber una épica por integrante de equipo)
- Como usuario, poder ahorrar tiempo y dinero
- Como usuario, quiero poder guardar los datos de la humedad, dentro de una base datos
- Como usuario, quiero poder activar el sistema de riego desde una cierta distancia.
- Seria mas facil el poder controlar mi sistema de riego y humedad desde mi casa.

##Tabla de historias de usuario
## Tabla de historias de usuario
| Id | Historia de usuario | Prioridad | Estimación | Como probarlo | Responsable |
|----|---------------------|-----------|------------|---------------|-------------|
|01 | Funcionamiento correcto del sensor DHT11.| Alta|1 semana | Con el codigo en funcionamiento|Integrantes del equipo |
|02 | Funcionamiento de la valvula selenoide dependiendo de la humedad del suelo.|Alta | 4 semanas| Con la compilación del código|Integrantes del quipo |
|03 | La ESP32 debe de recopilar los datos tomados del sensor DHT11| Alta| 4-5 semanas| El alojamiento en la nube| Integrantes del equipo|
|04 | Encender y apagar el sistema de riego de forma automática| Alta| 4-6 semanas|Con la compilación del código | Integrantes del equipo|


## Prototipo en dibujo
- Coloca la fotografia de tu prototipo dibujado a lapiz
