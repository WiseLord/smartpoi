EESchema Schematic File Version 4
EELAYER 26 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L MCU_Microchip_ATmega:ATmega328P-AU U1
U 1 1 5C8CCE9E
P 5650 3400
F 0 "U1" H 5150 4850 50  0000 L CNN
F 1 "ATmega328P-AU" H 5600 3400 50  0000 C CNN
F 2 "Package_QFP:TQFP-32_7x7mm_P0.8mm" H 5650 3400 50  0001 C CIN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/ATmega328_P%20AVR%20MCU%20with%20picoPower%20Technology%20Data%20Sheet%2040001984A.pdf" H 5650 3400 50  0001 C CNN
	1    5650 3400
	1    0    0    -1  
$EndComp
$Comp
L Connector:AVR-ISP-6 J1
U 1 1 5C8CCF53
P 8300 2200
F 0 "J1" H 8300 2600 50  0000 L CNN
F 1 "AVR-ISP-6" H 8700 1900 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_2x03_P2.54mm_Horizontal" V 8050 2250 50  0001 C CNN
F 3 " ~" H 7025 1650 50  0001 C CNN
	1    8300 2200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6250 2500 6600 2500
Text Label 6600 2500 2    50   ~ 0
MOSI
Wire Wire Line
	6250 2600 6600 2600
Text Label 6600 2600 2    50   ~ 0
MISO
Wire Wire Line
	6250 2700 6600 2700
Text Label 6600 2700 2    50   ~ 0
SCK
Wire Wire Line
	8700 2100 8950 2100
Text Label 8950 2100 2    50   ~ 0
MOSI
Wire Wire Line
	8700 2000 8950 2000
Text Label 8950 2000 2    50   ~ 0
MISO
Wire Wire Line
	8700 2200 8950 2200
Text Label 8950 2200 2    50   ~ 0
SCK
Wire Wire Line
	8700 2300 8950 2300
Text Label 8950 2300 2    50   ~ 0
~RST
Text Label 6600 3700 2    50   ~ 0
~RST
$Comp
L power:+3V8 #PWR010
U 1 1 5C8CD489
P 8200 1650
F 0 "#PWR010" H 8200 1500 50  0001 C CNN
F 1 "+3V8" H 8215 1823 50  0000 C CNN
F 2 "" H 8200 1650 50  0001 C CNN
F 3 "" H 8200 1650 50  0001 C CNN
	1    8200 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1650 8200 1700
$Comp
L power:+3V8 #PWR03
U 1 1 5C8CD532
P 5700 1700
F 0 "#PWR03" H 5700 1550 50  0001 C CNN
F 1 "+3V8" H 5715 1873 50  0000 C CNN
F 2 "" H 5700 1700 50  0001 C CNN
F 3 "" H 5700 1700 50  0001 C CNN
	1    5700 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1900 5650 1800
Wire Wire Line
	5650 1800 5700 1800
Wire Wire Line
	5700 1800 5700 1700
Wire Wire Line
	5750 1900 5750 1800
Wire Wire Line
	5750 1800 5700 1800
Connection ~ 5700 1800
$Comp
L power:GNDD #PWR011
U 1 1 5C8CD82A
P 8200 2650
F 0 "#PWR011" H 8200 2400 50  0001 C CNN
F 1 "GNDD" H 8204 2495 50  0000 C CNN
F 2 "" H 8200 2650 50  0001 C CNN
F 3 "" H 8200 2650 50  0001 C CNN
	1    8200 2650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 2650 8200 2600
$Comp
L power:GNDD #PWR02
U 1 1 5C8CD938
P 5650 4950
F 0 "#PWR02" H 5650 4700 50  0001 C CNN
F 1 "GNDD" H 5654 4795 50  0000 C CNN
F 2 "" H 5650 4950 50  0001 C CNN
F 3 "" H 5650 4950 50  0001 C CNN
	1    5650 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 4950 5650 4900
$Comp
L Device:R R1
U 1 1 5C8CDBA6
P 6750 1900
F 0 "R1" H 6820 1946 50  0000 L CNN
F 1 "47k" H 6820 1855 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 6680 1900 50  0001 C CNN
F 3 "~" H 6750 1900 50  0001 C CNN
	1    6750 1900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2050 6750 2250
$Comp
L power:+3V8 #PWR04
U 1 1 5C8CE199
P 6750 1700
F 0 "#PWR04" H 6750 1550 50  0001 C CNN
F 1 "+3V8" H 6765 1873 50  0000 C CNN
F 2 "" H 6750 1700 50  0001 C CNN
F 3 "" H 6750 1700 50  0001 C CNN
	1    6750 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 1700 6750 1750
$Comp
L Transistor_FET:BSS138 Q1
U 1 1 5C8CE6B3
P 7350 3650
F 0 "Q1" H 7556 3696 50  0000 L CNN
F 1 "IRLML6244TRPBF" H 7556 3605 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7550 3575 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 7350 3650 50  0001 L CNN
	1    7350 3650
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR07
U 1 1 5C8CE75F
P 7450 3900
F 0 "#PWR07" H 7450 3650 50  0001 C CNN
F 1 "GNDD" H 7454 3745 50  0000 C CNN
F 2 "" H 7450 3900 50  0001 C CNN
F 3 "" H 7450 3900 50  0001 C CNN
	1    7450 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	7450 3900 7450 3850
$Comp
L Transistor_FET:BSS138 Q2
U 1 1 5C8CEB0A
P 7650 4150
F 0 "Q2" H 7856 4196 50  0000 L CNN
F 1 "IRLML6244TRPBF" H 7856 4105 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 7850 4075 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 7650 4150 50  0001 L CNN
	1    7650 4150
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR08
U 1 1 5C8CEB11
P 7750 4400
F 0 "#PWR08" H 7750 4150 50  0001 C CNN
F 1 "GNDD" H 7754 4245 50  0000 C CNN
F 2 "" H 7750 4400 50  0001 C CNN
F 3 "" H 7750 4400 50  0001 C CNN
	1    7750 4400
	1    0    0    -1  
$EndComp
Wire Wire Line
	7750 4400 7750 4350
$Comp
L Transistor_FET:BSS138 Q3
U 1 1 5C8CECE5
P 7950 4650
F 0 "Q3" H 8156 4696 50  0000 L CNN
F 1 "IRLML6244TRPBF" H 8156 4605 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 8150 4575 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/BS/BSS138.pdf" H 7950 4650 50  0001 L CNN
	1    7950 4650
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR09
U 1 1 5C8CECEC
P 8050 4900
F 0 "#PWR09" H 8050 4650 50  0001 C CNN
F 1 "GNDD" H 8054 4745 50  0000 C CNN
F 2 "" H 8050 4900 50  0001 C CNN
F 3 "" H 8050 4900 50  0001 C CNN
	1    8050 4900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 4900 8050 4850
Wire Wire Line
	8050 4450 8050 4350
Wire Wire Line
	8050 4350 8850 4350
Wire Wire Line
	7750 3950 7750 3850
Wire Wire Line
	7750 3850 8850 3850
Wire Wire Line
	7450 3450 7450 3350
Wire Wire Line
	7450 3350 8850 3350
$Comp
L Connector_Generic:Conn_01x01 J2
U 1 1 5C8CFA30
P 9050 3350
F 0 "J2" H 9130 3392 50  0000 L CNN
F 1 "K_RED" H 9130 3301 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 9050 3350 50  0001 C CNN
F 3 "~" H 9050 3350 50  0001 C CNN
	1    9050 3350
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J3
U 1 1 5C8CFB0A
P 9050 3850
F 0 "J3" H 9130 3892 50  0000 L CNN
F 1 "K_GREEN" H 9130 3801 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 9050 3850 50  0001 C CNN
F 3 "~" H 9050 3850 50  0001 C CNN
	1    9050 3850
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x01 J4
U 1 1 5C8CFB4C
P 9050 4350
F 0 "J4" H 9129 4392 50  0000 L CNN
F 1 "K_BLUE" H 9129 4301 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 9050 4350 50  0001 C CNN
F 3 "~" H 9050 4350 50  0001 C CNN
	1    9050 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	7150 3650 6900 3650
Text Label 6900 3650 0    50   ~ 0
RED
Wire Wire Line
	7450 4150 6900 4150
Text Label 6900 4150 0    50   ~ 0
GREEN
Wire Wire Line
	7750 4650 6900 4650
Text Label 6900 4650 0    50   ~ 0
BLUE
Wire Wire Line
	5050 2200 4900 2200
Wire Wire Line
	6250 3700 6600 3700
Text Label 6750 2250 1    50   ~ 0
~RST
Text Label 8800 3350 2    50   ~ 0
K_RED
Text Label 8800 3850 2    50   ~ 0
K_GREEN
Text Label 8800 4350 2    50   ~ 0
K_BLUE
$Comp
L power:+3V8 #PWR01
U 1 1 5C8D4CF1
P 4900 1700
F 0 "#PWR01" H 4900 1550 50  0001 C CNN
F 1 "+3V8" H 4915 1873 50  0000 C CNN
F 2 "" H 4900 1700 50  0001 C CNN
F 3 "" H 4900 1700 50  0001 C CNN
	1    4900 1700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1700 4900 2200
Wire Wire Line
	6250 3400 6600 3400
Text Label 6600 3400 2    50   ~ 0
RED
Wire Wire Line
	6250 3500 6600 3500
Text Label 6600 3500 2    50   ~ 0
GREEN
Wire Wire Line
	6250 3600 6600 3600
Text Label 6600 3600 2    50   ~ 0
BLUE
$Comp
L Connector_Generic:Conn_01x01 J5
U 1 1 5C8D97A4
P 9050 4850
F 0 "J5" H 9129 4892 50  0000 L CNN
F 1 "GND" H 9129 4801 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 9050 4850 50  0001 C CNN
F 3 "~" H 9050 4850 50  0001 C CNN
	1    9050 4850
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR012
U 1 1 5C8D9856
P 8750 4950
F 0 "#PWR012" H 8750 4700 50  0001 C CNN
F 1 "GNDD" H 8754 4795 50  0000 C CNN
F 2 "" H 8750 4950 50  0001 C CNN
F 3 "" H 8750 4950 50  0001 C CNN
	1    8750 4950
	1    0    0    -1  
$EndComp
Wire Wire Line
	8850 4850 8750 4850
Wire Wire Line
	8750 4850 8750 4950
$Comp
L Device:C C1
U 1 1 5C8DA8E2
P 7350 2350
F 0 "C1" H 7465 2396 50  0000 L CNN
F 1 "0.1" H 7465 2305 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 7388 2200 50  0001 C CNN
F 3 "~" H 7350 2350 50  0001 C CNN
	1    7350 2350
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR06
U 1 1 5C8DA9AE
P 7350 2600
F 0 "#PWR06" H 7350 2350 50  0001 C CNN
F 1 "GNDD" H 7354 2445 50  0000 C CNN
F 2 "" H 7350 2600 50  0001 C CNN
F 3 "" H 7350 2600 50  0001 C CNN
	1    7350 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2600 7350 2500
$Comp
L power:+3V8 #PWR05
U 1 1 5C8DAFDA
P 7350 2100
F 0 "#PWR05" H 7350 1950 50  0001 C CNN
F 1 "+3V8" H 7365 2273 50  0000 C CNN
F 2 "" H 7350 2100 50  0001 C CNN
F 3 "" H 7350 2100 50  0001 C CNN
	1    7350 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7350 2100 7350 2200
$EndSCHEMATC
