@echo off
break ON
rem fichiers BAT et fork créés par Sébastien CANET
SET currentpath=%~dp1
cd %currentpath%python
cls
python.exe ..\rDuinoUploader\rDuino_uploader_server.py -D COM14 -U arduino_debug.exe -C arduino.exe -T F:\Logiciels\Arduino_graphique\Blockly-at-rduino_AIO\ArduinoTechnoEduc\