/*---------------------------------------------------------------------------
 * Project: CloudIO
 * Code: Test Code (Simulating a DHT22 with a potentiometer)
 * Responsible Technicians: Gustavo Higuti de Souza
 *                          Ian Aguila Sanchez
 *                          Igor de Lucca Carneiro Antonio
 *                          
 * This is a test code made with the purpose of testing the CloudIO system. 
 * Current Version: Final
 * Made at 03:50AM of August 28 of 2020 
 *---------------------------------------------------------------------------*/
 
  int tTen, tUnit, tDecimal, hHundred, hTen, hUnit, hDecimal;
  float temperature, humidity;
  char sinalTemp;
  String leitura = "";
void setup() {
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  
if(Serial.available()> 0) // Waits until the computer to require the data 
  {
  
  if(Serial.read() == 'L')  // If the computer have required the data
  {
  temperature = map(analogRead(A1), 0 , 1023, -400, 800) / 10;  // The system generates temperature and humidity values into the 
  humidity =  map(analogRead(A1), 0 , 1023, 0, 1000) / 10;      // measurement range of the sensor
  temperature *= 10;                             // The numbers are transformed at integer numbers mutiplicating them by ten
  humidity *= 10;
  
  if(temperature < 0)
  {
    sinalTemp = '-';                 // The temperature signal is registered and is normalized to positive 
    temperature = temperature * -1;
  }
  else sinalTemp = '+';
  
  tTen     = temperature / 100;                         // The data is parsed and separated by algarisms and atributed
  tUnit    = temperature / 10 - (10 * tTen);            // to their respective variables
  tDecimal = temperature - (10 * tUnit) - (100 * tTen);

  hHundred = humidity / 1000; 
  hTen     = humidity / 100 - (10   * hHundred);
  hUnit    = humidity / 10  - (100  * hHundred) - (10  * hTen);
  hDecimal = humidity       - (1000 * hHundred) - (100 * hTen) - (10 * hUnit);
  leitura = "";
  leitura.concat(sinalTemp); // All the values are concatenated at a string separated by a semicolon
  leitura.concat(tTen);
  leitura.concat(tUnit);
  leitura.concat(tDecimal);
  leitura.concat(";");
  leitura.concat(hHundred);
  leitura.concat(hTen);
  leitura.concat(hUnit);
  leitura.concat(hDecimal);
  Serial.println(leitura); 
  }
  else {Serial.flush();}
  }

}
