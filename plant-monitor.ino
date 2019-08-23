#include "Adafruit_DHT_Particle.h"

#define DHTPIN D2
#define DHTTYPE DHT11

// DHT setup
DHT dht(DHTPIN, DHTTYPE);
int loopCount;

// Moisture setup
int sensor_pin = A4;
int moisture_sensor_value;

void setup() {
	Particle.publish("state", "Startup");

	dht.begin();
// 	loopCount = 0; // Used for deep sleep stuff
	delay(2000);
}

void loop() {
/*  ==========================
    Get moisture sensor values
    ==========================
*/
    moisture_sensor_value = analogRead(sensor_pin);
    // output_value = map(output_value,550,0,0,100); // Not sure what this does
    
/*
    ==========================
    Get DHT11 values
    ==========================
*/
	float humidity = dht.getHumidity();
	float temp_c = dht.getTempCelcius();
	float temp_f = dht.getTempFarenheit();

/*
    ==========================
    Publish values
    ==========================
*/
    Particle.publish("moisture", String(moisture_sensor_value));
    Particle.publish("humidity", String(humidity));
    Particle.publish("temp_f", String(temp_f));
    // Particle.publish("temp_c", String(temp_c)); // Don't care about Celsius at the moment
	delay(10000);

/*
    ==========================
    Deep sleep stuff
    ==========================
*/
// 	loopCount++;
// 	if(loopCount >= 6){
// 	  Particle.publish("state", "Going to sleep for 5 minutes");
// 	  delay(1000);
// 	  System.sleep(SLEEP_MODE_DEEP, 300);  
// 	}
}


