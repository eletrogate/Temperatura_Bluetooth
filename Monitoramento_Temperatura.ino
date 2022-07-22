/*
 * Eletrogate - Monitoramento da Temperatura via Bluetooth 
 * Autor: Miguel Sena
 * Blog da Eletrogate: blog.eletrogate.com
 */

#include <Adafruit_Sensor.h>                              //Inclusão das bibliotecas utilizadas
#include <DHT.h>
#include <DHT_U.h>

#define pin 2                                             //Define do pino em que o sensor está conectado
#define type DHT11                                        //Define o tipo do sensor (se for utilizado o DHT22, devemos trocar o tipo do sensor)

DHT_Unified dht(pin, type);                               //Cria o objeto do sensor

void setup() {
  Serial.begin(9600);                                     //Inicia o Monitor Serial
  dht.begin();                                            //Inicia o sensor
}

void loop() {
 if (Serial.available()) {                                //Checa se tem alguma entrada Serial disponível
    char cmd = Serial.read();                             //Cria uma variável cmd, do tipo char, que receberá os dados enviados no Monitor Serial

    if (cmd == 't') {                                     //Verifica se o comando inserido é igual a 't'
      sensors_event_t event;                              //Cria um objeto event
      dht.temperature().getEvent(&event);                 //Mede os dados do sensor e os atribui ao objeto event
      Serial.println("------------------------------"); 
      Serial.print("Temperatura: ");
      Serial.print(event.temperature);                    //Acessa a temperatura e imprime no Monitor Serial
      Serial.println("*");
      Serial.println("------------------------------");
      Serial.println();
    }
  }
}