# Air Quality Monitoring Station
A web-based air quality monitoring station firmware. You can see the visualized real-time air quality data with the [Air Quality Widget][air-quality-widget], like
<p align="center">
  <img src="https://raw.githubusercontent.com/evanxd/air-quality-widget/master/images/demo.gif" />
</p>

We use [NodeMcu][node-mcu] (Arduino-like board with ESP8266 Wi-Fi chip) and [PMS3003 air quality sensor][pms3003] here. Please check the [How-to][how-to] section to learn how to setup the air quality monitoring station and check the real-time data.

![Device](./images/device.jpg)

## How-to
1. Update the [SSID][ssid], [Wi-Fi password][password], and [MQTT topic][topic] (you can name it with any name you want) in the firmware, and flash the firmware with Arduino IDE.
  - Please ensure unplug the air quality sensor from the board when you do flashing. Because TX and RX will be used when do flashing.
2. Check the real-time air quality data with a MQTT client.
  - Go to the [HiveMQ MQTT client web page][mqtt-client] and subscribe the [topic][topic] you assigned in the firmware.

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
