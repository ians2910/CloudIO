/*Course Conclusion Project - CloudIO

Responsible technicians: 
  Gustavo Higuti de Souza        - number 11
  Ian Aguila Sanchez             - number 12
  Igor de Lucca Carneiro Antonio - number 13

Description of the code:
  This code is made to read a DHT22 humidity and temperature sensor measurements
  using an Arduino board, to pass this data serially to a computer, for it to
  send the data to the cloud

First version: 1.0 - made at 03:46 AM of 06/06/2020 
Previous version : 2.0 - made at 11:49PM of 16/08/2020 
Actual version : 3.0 - FINAL - made at 12:21PM of 08/09/2020
*/

//--------------------------------------------------------------- Libraries Inclusion ---------------------------------------------------------------
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

//--------------------------------- Definition of the pin where the device is connected and the type of used sensor ---------------------------------
#define DHTPIN 2     // Digital pin connected to the DHT sensor 
// Feather HUZZAH ESP8266 note: use pins 3, 4, 5, 12, 13 or 14 --
// Pin 15 can work but DHT must be disconnected during program upload.
#define DHTTYPE    DHT22     

DHT_Unified dht(DHTPIN, DHTTYPE);

//----------------------------------------------------------- Global Variables Declaration ----------------------------------------------------------
int humidity, temperature; // Variables to maintain the temperature and humidity values multiplicated by 10 (to transform in integer values)
char temperatureSignal; // Variable that maintains the temperature signal (if it is negative or positive)
int hDecimal, hUnit, hTen, hHundred, tDecimal, tUnit, tTen; // Variables that split the data into each decimal place
String dataToSend = ""; // String that will maintain the whole data concatenated to send
//---------------------------------------------------------------------------------------------------------------------------------------------------


void setup() {
  Serial.begin(9600); //Serial communication begin with a baud rate of 9600
  dht.begin(); //Sensor begin
  delay(2000); //Mandatory delay of 2 seconds to start the circuit
}

 
void loop() {

if(Serial.available()) // If there is anything at the serial buffer it will read
 {
if(Serial.read() == 'L') // If the caracter at the buffer is an L, then the sensor will measure the temperature and humidity and the data will be sent through USB
 {
// Section where the humidity and temperature values are measured, transformed into an integer value and attributed to its respective variables
  sensors_event_t event;
  temperature = 10 * (event.temperature); 
  dht.humidity().getEvent(&event);
  humidity   = 10 * (event.relative_humidity); 
//---------------------------------------------------------------------------------------------------------------------------------------------------

// Section where the signal of the temperature is recorded and its module is obtained and attributed to the same variable that it was 
  if(temperature < 0) 
  {
    temperatureSignal = "-";  
    temperature *= -1;
  }
  else
  {
    temperatureSignal = "+";
  }
//---------------------------------------------------------------------------------------------------------------------------------------------------

//--------------- Section where the temperature and humidity data are splitted into decimal places and attributed to integer variables -------------- 
  tTen     = temperature / 100; 
  tUnit    = temperature / 10 - (10 * tTen);
  tDecimal = temperature - (10 * tUnit) - (100 * tTen);

  hHundred = humidity / 1000; 
  hTen     = humidity / 100 - (10   * hHundred);
  hUnit    = humidity / 10  - (100  * hHundred) - (10  * hTen);
  hDecimal = humidity       - (1000 * hHundred) - (100 * hTen) - (10 * hUnit);
//---------------------------------------------------------------------------------------------------------------------------------------------------

//------------------------------------------------ Section where the data will be concatenated to be sent -------------------------------------------
  dataToSend.concat(temperatureSignal);
  dataToSend.concat(tTen);
  dataToSend.concat(tUnit);
  dataToSend.concat(tDecimal);
  dataToSend.concat(';');
  dataToSend.concat(hHundred);
  dataToSend.concat(hTen);
  dataToSend.concat(hUnit);
  dataToSend.concat(hDecimal);
//-------------------------------------------------------------------------------------------------------------------------------------------------
  Serial.println(dataToSend); // Serial transmission of the data
  
  }
    Serial.flush(); // If there was anything at the serial buffer, wether it was an L or not, the buffer will be flushed
  }
}
