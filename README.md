# Envío de datos de sensor BMP280 por SMS

Este repositorio contiene un código en Arduino diseñado para comunicarse con un sensor BMP280 para medir temperatura, presión y altitud. Posteriormente, los datos obtenidos se envían a un número de teléfono específico a través de mensajes de texto utilizando un módulo SIM800L.

## Requisitos
- Placa Arduino compatible
- Sensor BMP280
- Módulo SIM800L
- Librerías necesarias: SPI, Adafruit_Sensor, Adafruit_BMP280, SIM800L
  
## Instalación
1. Conectar el sensor BMP280 y el módulo SIM800L a la placa Arduino.
2. Instalar las librerías necesarias. Las librerías Adafruit_BMP280 y Adafruit_Sensor se pueden instalar a través del Administrador de bibliotecas de Arduino. La librería SIM800L es personalizada y debe ser instalada manualmente.
3. Subir el código a la placa Arduino.
   
## Uso
- Asegúrese de configurar correctamente los pines de conexión del sensor BMP280 y del módulo SIM800L en el código según su configuración.
- Especifique el número de teléfono al que desea enviar los mensajes de texto en el código.
- El código enviará los datos de temperatura, presión y altitud al número de teléfono especificado cada minuto.
  
## Notas
- Este código ha sido diseñado para funcionar con un sensor BMP280 y un módulo SIM800L. Asegúrese de tener los componentes adecuados para su funcionamiento.
- Ajuste la velocidad de transmisión (baud rate) del puerto serie según la configuración de su módulo SIM800L.
- Asegúrese de tener suficiente crédito o plan de mensajes de texto en la tarjeta SIM utilizada en el módulo SIM800L para enviar los mensajes.

## Créditos

Este código utiliza las librerías Adafruit_BMP280 y Adafruit_Sensor para la comunicación con el sensor BMP280, así como la librería personalizada SIM800L para la comunicación con el módulo SIM800L.
