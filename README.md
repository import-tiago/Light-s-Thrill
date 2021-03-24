# Light's Thrill

[![Status](https://img.shields.io/badge/Status-Finished-green.svg)](https://github.com/TiagoPaulaSilva/Light-s-Thrill) [![Donate](https://img.shields.io/badge/Donate-Buy%20Me%20a%20Coffee-yellow.svg)](https://www.buymeacoffee.com/TiagoPaulaSilva)

Light's Thrill is an USB controller for RGB LED strips compatible with Corsair iCUE.

#### Compatible with: 
* [iCUE](https://www.corsair.com/br/pt/icue)
* [OpenRGB](https://gitlab.com/CalcProgrammer1/OpenRGB)
* [JackNet RGB Sync](https://rgbsync.com/)
* [RGB Infrared Controller](https://github.com/TiagoPaulaSilva/Light-s-Thrill/blob/master/Assets/RGB%20Infrared%20Controller%20Example.jpg)

## Enclosure Preview
![](https://github.com/TiagoPaulaSilva/Light-s-Thrill/blob/master/Assets/Enclosure%20Preview1.jpg) | ![](https://github.com/TiagoPaulaSilva/Light-s-Thrill/blob/master/Assets/Enclosure%20Preview2.jpg) | ![](https://github.com/TiagoPaulaSilva/Light-s-Thrill/blob/master/Assets/Enclosure%20Preview3.jpg)
--- | --- | ---

## Schematic
<img src="https://github.com/TiagoPaulaSilva/Light-s-Thrill/blob/master/Assets/Schematic%20Preview.png" width="100%" height="100%">

## SETUP Parts
<img src="https://github.com/TiagoPaulaSilva/Light-s-Thrill/blob/master/Assets/SETUP%20Parts.png" width="100%" height="100%">

## MCU SETUP
- Burn the Arduino Leornado bootloader at ATmega32U4 with an Arduino UNO as ISP programmer using SPI circuit connection.
- Install the Corsair Lighting Protocol Boards to the Arduino IDE from: ```https://raw.githubusercontent.com/Legion2/CorsairLightingProtocolBoards/master/package_Legion2_CorsairLightingProtocolBoards_index.json```.
- Upload the ```Firmware\Addressable LED Strip\iCUE\Firmware.ino``` to the ATmega32u4 as following:
<img src="https://github.com/TiagoPaulaSilva/Light-s-Thrill/blob/master/Assets/Arduino%20IDE%20SETUP.png" width="75%" height="75%">
- Done. The device is now ready to be recognized by Corsair iCUE application.

## Corsair iCUE SETUP
- To have the maximum (2x 89) of LEDs controlled by the iCUE, configure it as follows:
<img src="https://github.com/TiagoPaulaSilva/Light-s-Thrill/blob/master/Assets/iCUE%20SETUP.png" width="100%" height="100%">

## Video - Demo
<p align="center"><a href="https://vimeo.com/446214253"><img src="https://github.com/TiagoPaulaSilva/Light-s-Thrill/blob/master/Assets/Video%20Preview.png" width="80%" height="80%" title="Watch the video" alt="Watch the video"></a></p>

### Contributing
0. Give this project a :star:
1. Create an issue and describe your idea.
2. [Fork it](https://github.com/TiagoPaulaSilva/Light-s-Thrill/fork).
3. Create your feature branch (`git checkout -b my-new-feature`).
4. Commit your changes (`git commit -a -m "Added feature title"`).
5. Publish the branch (`git push origin my-new-feature`).
6. Create a new pull request.
7. Done! :heavy_check_mark:

### License Information
<a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="https://i.creativecommons.org/l/by-sa/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">Light's Thrill</span> by <a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/TiagoPaulaSilva" property="cc:attributionName" rel="cc:attributionURL">Tiago Silva</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-sa/4.0/">Creative Commons Attribution-ShareAlike 4.0 International License</a>.<br />
Based on a work at <a xmlns:dct="http://purl.org/dc/terms/" href="[Corsair Lighting Protocol](https://github.com/Legion2/CorsairLightingProtocol)" rel="dct:source">[Corsair Lighting Protocol](https://github.com/Legion2/CorsairLightingProtocol)</a> and <a xmlns:dct="http://purl.org/dc/terms/" href="[Open Corsair Link](https://github.com/audiohacked/OpenCorsairLink)" rel="dct:source">[Open Corsair Link](https://github.com/audiohacked/OpenCorsairLink)</a>.<br />
Permissions beyond the scope of this license may be available at <a xmlns:cc="http://creativecommons.org/ns#" href="https://twitter.com/tiagopsilvaa" rel="cc:morePermissions">tiagodepaulasilva@gmail.com</a>.
