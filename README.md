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
    "temperature signal + temperatureTen + temperatureUnit + temperatureDecimalPart + ';' + humidityHundred + humidityTen + humidityUnit + humidityDecimalPart"
    So, if the temperature measured was </b>82.2°C</b> and the humidity was of <b>22.0%</b> the string sent will be: <b>+822;220</b>
  
