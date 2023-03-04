#include <SPI.h>
#include <LoRa.h>
#include <Adafruit_MPL3115A2.h>

Adafruit_MPL3115A2 basinc;

int counter = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  Serial.println("LoRa Sender");

  if (!LoRa.begin(868E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }

   if (!basinc.begin()) {
    Serial.println("Could not find sensor. Check wiring.");
    while(1);
  }

  basinc.setSeaPressure(1013.26);  
}

void loop() {

  float pressure = basinc.getPressure();
  float altitude = basinc.getAltitude();
  float temperature = basinc.getTemperature();

  Serial.println("-----------------");
  Serial.print("pressure = "); Serial.print(pressure); Serial.println(" hPa");
  Serial.print("altitude = "); Serial.print(altitude); Serial.println(" m");
  Serial.print("temperature = "); Serial.print(temperature); Serial.println(" C");
  
  Serial.print("Sending packet: ");
  Serial.println(counter);

  // send packet
  LoRa.beginPacket();
  LoRa.print("hello ");
  LoRa.print(counter);
  LoRa.print(" ");
  LoRa.print(altitude);
  LoRa.endPacket();

  counter++;

  delay(5000);
}