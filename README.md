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
  - A dynamic dashboard made with PowerBI

The CloudIO operation consists of the following actions:
  - The software requires from Arduino, via serial port, the measured data.
  - Arduino measures the temperature and the humidity and sends it through the USB.
  - The software gets the data, that comes in the following pattern:
    <b>temperature signal + temperatureTen + temperatureUnit + temperatureDecimalPart + ';' + humidityHundred + humidityTen + humidityUnit + humidityDecimalPart</b>
    
    Example: if the temperature measured was <b>82.2°C</b> and the humidity was of <b>22.0%</b> the string sent will be: <b>+822;220</b>.
  - Then, this data gets recovered and divided by 10 (to recover the numbers correctly, because the data had to be multiplicated by 10 to simplify the string construction.
  - Later, a string is made on the pattern <b>Recording Date (DD/MM/YYYY) + (Tab) + Recording Hour (HH:MM:SS) + (Tab) + Temperature in Celsius + (Tab) + Humidity + '%' + (Enter)</b> and it is recorded at the .txt file located in the cloud service.
    
    Example: if the date was <b>21/11/2020</b>, the hour was <b>03:24:25</b>, the temperature was <b>-25.2°C</b> and the humidity was <b>95.7%</b>, then the string recorded will   be:
    <b>21/11/2020 03:24:25  -25,2 95,7%</b> (The decimal separator used was the comma because it is a brazillian system, and in Brazil the comma is used as decimal separator while the dot is used as the thousands separator, then 25 million in Brazil could be represented as 25.000.000 while three quarters could be represented as 0,75)
  - This process gets repeated several times until the user stops the software.
  
  The string saved at the file is made in the mentioned way just because it makes the .txt file readable by services such as Excel and PowerBI, being the tab a separator of columns and the enter a separator of lines.
  When the user opens the PowerBI dashboard, the system applies the made filters and is able to convert the temperature to Celsius, Kelvin and Fahrenheit beyond allowing the user to select a certain range of time to analyze at the graphics.
  
  
