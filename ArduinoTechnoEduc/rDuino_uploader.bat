@echo off
break ON
rem fichiers BAT et fork cr��s par S�bastien CANET
SET currentpath=%~dp1
cd %currentpath%scripts
cls
python.exe .\rDuino\rDuino_uploader_server.py -D COM4 -U arduino_debug.exe -C arduino.exe -T F:\Logiciels\Arduino_graphique\Blockly-at-rduino_AIO\ArduinoTechnoEduc\