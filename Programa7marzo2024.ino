#include <SPI.h> // Uso de la libreria SPI para comunicar con el sensor BMP280
#include <SIM800L.h> //INSTALAR LIBRERIA PERSONALIZADA, SIRVE PARA COMUNICAR EFECTIVAMENTE CON EL SIM800L
#include <Adafruit_Sensor.h> //Dependencia de libreria
#include <Adafruit_BMP280.h> //INSTALAR LIBRERIA, ACEPTAR INSTALAR DEPENDENCIAS
#include <HardwareSerial.h>

const int BMP_SCK = 18; // Pin de reloj de la comunicacion SPI
const int BMP_MISO = 19; // Pin de MISO la comunicacion SPI
const int BMP_MOSI = 23; // Pin de MOSI la comunicacion SPI
const int BMP_CS = 5; // Pin de CS la comunicacion SPI

HardwareSerial simserial(2); //Se abre un puerto serial para luego usarlo en el SIM800L
SIM800L sim800l(simserial); // Se conecta con el SIM800L
Adafruit_BMP280 bmp(BMP_CS); // Se conecta con el BMP280

// Aqui se escribe el numero de telefono para poder recibir los mesajes 
// Usar con la lada nacional +52
const String numero_cel = "+528342732818"; 
const int tiempo_entre_mensajes = 60000; // Expresado en milisegundos, esta ajustado ahora con 1 min


void setup() {

  simserial.begin(9600); // Se abre el puerto serie para luego iniciar la comunicacion
  sim800l.begin(9600); // Se inicia la comunicacion con el sensor


  //Se hace un chequeo del sensor BMP280 para revisar que este funcionando debidamente

  if (!bmp.begin()) { 
    Serial.println("No se pudo encontrar el sensor BMP280");
    while (1);
  }

  //Se ajusta el sensor BMP280 a modo normal
  bmp.setSampling(Adafruit_BMP280::MODE_NORMAL);

  
}

void loop() {
  
  float temperatura = bmp.readTemperature(); // Se lee la temperatura del sensor BMP280
  float presion = bmp.readPressure() / 100.0; // Se lee la presion del sensor BMP 280 convertido a hPa
  float altitud = bmp.readAltitude(); // Se lee la altitud del sensor BMP280

  // Se crea un mensaje con los datos obtenidos

  String mensaje = "Temperatura: " + String(temperatura) + " °C\n" +
                   "Presión: " + String(presion) + " hPa\n" +
                   "Altitud: " + String(altitud) + " metros";

  // Se envia el mensaje al numero de telefono con la informacion y se espera el tiempo establecido
  sim800l.sendSMS(numero_cel, mensaje);
  delay(tiempo_entre_mensajes);

}


