# Air Quality Monitoring Station
A web-based air quality monitoring station firmware. You can see the visualized real-time air quality data with the [Air Quality Widget][air-quality-widget], like the below image, or you can check the [raw data with a MQTT client][check-data-with-mqtt-client].
<p align="center">
  <img src="https://raw.githubusercontent.com/evanxd/air-quality-widget/master/images/demo.gif" />
</p>

## How-to

### Setup Air Quality Monitoring Station & Check Data
We use [NodeMcu][node-mcu] (Arduino-like board with ESP8266 Wi-Fi chip) and [PMS3003 air quality sensor][pms3003] here. Please have them before you setup.

![Device](./images/device.jpg)

1. Update the [SSID][ssid], [Wi-Fi password][password], and [MQTT topic][topic] (you can name it with any name you want) in the firmware, and flash the firmware with Arduino IDE.
  - Please ensure unplug the air quality sensor from the board when you do flashing. Because TX and RX will be used when do flashing.
2. Go to the [Air Quality Widget demonstration page][air-quality-widget-demonstration-page] to see the visualized data.

### Check Data With MQTT Client
Go to the [HiveMQ MQTT client web page][mqtt-client] and subscribe the [topic][topic] you assigned in the firmware.

![MQTT Client](./images/mqtt-client.png)

[mqtt]: https://en.wikipedia.org/wiki/MQTT
[node-mcu]: http://www.nodemcu.com/index_en.html
[pms3003]: http://aqicn.org/sensor/pms3003
[how-to]: #how-to
[mqtt-client]: http://www.hivemq.com/demos/websocket-client/
[ssid]: https://github.com/evanxd/mqtt-air-quality-monitoring-station/blob/master/mqtt-air-quality-monitoring-station.ino#L4
[password]: https://github.com/evanxd/mqtt-air-quality-monitoring-station/blob/master/mqtt-air-quality-monitoring-station.ino#L5
[topic]: https://github.com/evanxd/mqtt-air-quality-monitoring-station/blob/master/mqtt-air-quality-monitoring-station.ino#L9
[air-quality-widget]: https://github.com/evanxd/air-quality-widget
[air-quality-widget-demonstration-page]: http://evanxd.io/air-quality-widget
[check-data-with-mqtt-client]: #check-data-with-mqtt-client
