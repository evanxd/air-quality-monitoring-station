# MQTT Air Quality Monitoring Station
A MQTT-based air quality monitoring station firmware. We use [NodeMcu][node-mcu] (Arduino-like board with ESP8266 Wi-Fi chip) and [PMS3003 air quality sensor][pms3003] here.

![Device](./images/device.jpg)

## Setup
* Flash the firmware with Arduino IDE. (Please ensure unplug the air quality sensor from the board when you do flashing. Because TX and RX will be used when do flashing)



[node-mcu]: http://www.nodemcu.com/index_en.html
[pms3003]: http://aqicn.org/sensor/pms3003
