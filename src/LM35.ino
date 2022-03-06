
const int sensor = 0;                                           //Sensor conectado al pin analogico "0"

float milivolts;
float temperature;
float startTime, stopTime;
float myDesiredTime;                                            //Definimos variables

void setup(){                                                   //void setup se ejecuta una vez que hace clic en el botón de carga
  Serial.begin(9600);
  startTime = 0;
  stopTime = 0;
  myDesiredTime = 600000;                                       //El sketch se ejecuta durante 600000 milisegundos
}



void loop(){                                                   //void loop es una rutina iterativa
  if(stopTime-startTime<=myDesiredTime){
      milivolts = (analogRead(sensor)*5000L)/1023;            //Conversor analógico a digital
      temperature = (milivolts / 10);                         //factor de escala lineal
      Serial.println(temperature);
      delay(1000);                                            //el sketch lee la temperatura cada segundo
      stopTime=millis();
    }
}
