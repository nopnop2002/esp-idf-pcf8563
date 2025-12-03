# esp-idf-pcf8563
PCF8563 RTC Driver for esp-idf

# Software requirements
ESP-IDF V5.0 or later.   
ESP-IDF V4.4 release branch reached EOL in July 2024.   
ESP-IDF V5.1 is required when using ESP32-C6.   

__Note for ESP-IDF V5.2.__   
A new i2c driver is now available in ESP-IDF V5.2.   
Under ESP-IDF V5.2 or later, this project uses a new i2c driver.   

# Installation
```Shell
git clone https://github.com/nopnop2002/esp-idf-pcf8563
cd esp-idf-pcf8563
idf.py menuconfig
idf.py flash
```

# Wireing  

|PCF8563||ESP32|ESP32S2/S3/H2|ESP32Cn|
|:-:|:-:|:-:|:-:|:-:|
|SCL|--|GPIO22|GPIO02|GPIO06|
|SDA|--|GPIO21|GPIO01|GPIO05|
|GND|--|GND|GND|GND|
|VCC|--|3.3V|3.3V|3.3V|

You can change GPIO using menuconfig.   

# Set Clock Mode   

This mode set RTC initial value using NTP time Server.   
you have to set these config value using menuconfig.   

![Image](https://github.com/user-attachments/assets/3b1fb2a0-9466-4298-b549-ad1770f721f7)
![Image](https://github.com/user-attachments/assets/14dab99c-c05f-4ad9-9ac3-c2f7643d0e7e)

you have to set gpio & NTP Server using menuconfig.   

![Image](https://github.com/user-attachments/assets/96765746-f007-4c8a-b11e-1c0afa236e83)
![Image](https://github.com/user-attachments/assets/c1299e26-0530-4746-aae6-84bbeadf5563)


# Get Clock Mode   

This mode take out the time from a RTC clock.   
you have to change mode using menuconfig.   

![Image](https://github.com/user-attachments/assets/96765746-f007-4c8a-b11e-1c0afa236e83)
![Image](https://github.com/user-attachments/assets/7c46b0b9-af1c-42b4-9991-de1de55cdd57)
![pcf8563-13](https://user-images.githubusercontent.com/6020549/61298923-10717d80-a81a-11e9-91c4-2136030eb2eb.jpg)


# Get the time difference of NTP and RTC   

This mode get time over NTP, and take out the time from a RTC clock.   
Calculate time difference of NTP and RTC.   
you have to change mode using menuconfig.   

![Image](https://github.com/user-attachments/assets/96765746-f007-4c8a-b11e-1c0afa236e83)
![Image](https://github.com/user-attachments/assets/1e977db2-c495-4f1f-92a2-90f6616f3b09)
![pcf8563-14](https://user-images.githubusercontent.com/6020549/61298986-38f97780-a81a-11e9-99ab-6c4954373735.jpg)


# Time difference of 1 week later.   

![pcf8563-1week](https://user-images.githubusercontent.com/6020549/61800860-c5361b00-ae68-11e9-8b7d-ed64529f25fe.jpg)


# Time difference of 1 month later.   

![pcf8563-1month](https://user-images.githubusercontent.com/6020549/63231385-021de380-c256-11e9-9872-17ccc8a698b9.jpg)

# Comparison with other RTCs
This module has a large time lag.   
I recommend the DS3231 RTC.   
https://github.com/nopnop2002/esp-idf-ds3231

