# CloudIO
Temperature and humidity measurement system with on-cloud data storage

This project was made by the following electronics technicians:
  - <i>Gustavo Higuti de Souza</i>
  - <i>Ian Aguila Sanchez</i>
  - <i>Igor de Lucca Carneiro Antonio</i>

The system is composed by 4 parts:
  - An Arduino with a DHT22 temperature and humidity sensor
  - A computer connected with the internet and executing the software made
  - A cloud service (OneDrive is the most recommended one) with a .txt file in it (to record the data)
  - A dynamic template from PowerBI

The CloudIO operation consists of the following actions:
  - The software asks Arduino, via serial port, for the measured data.
  - Arduino measures the temperature and the humidity and sends it through the USB.
  - The software gets the data, that comes in the following pattern:
    <b>temperature signal + temperatureTen + temperatureUnit + temperatureDecimalPart + ';' + humidityHundred + humidityTen + humidityUnit + humidityDecimalPart</b>
    So, if the temperature measured was <b>82.2°C</b> and the humidity was of <b>22.0%</b> the string sent will be: <b>+822;220</b>.
  - Then, this data gets recovered and divided by 10 (to recover the numbers correctly, because the data had to be multiplicated by 10 to simplify the string construction.
  - Later, a string is made on the pattern <b>Recording Date (DD/MM/YYYY) + (Tab) + Recording Hour (HH:MM:SS) + (Tab) + Temperature in Celsius + (Tab) + Humidity + '%' + (Enter)</b>
  
  
