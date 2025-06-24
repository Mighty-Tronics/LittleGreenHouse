EESchema Schematic File Version 4
EELAYER 30 0
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
L power:+5V #PWR0101
U 1 1 66493BF4
P 4350 2850
F 0 "#PWR0101" H 4350 2700 50  0001 C CNN
F 1 "+5V" H 4365 3023 50  0000 C CNN
F 2 "" H 4350 2850 50  0001 C CNN
F 3 "" H 4350 2850 50  0001 C CNN
	1    4350 2850
	1    0    0    -1  
$EndComp
$Comp
L Switch:SW_Push BP1
U 1 1 6649400F
P 4600 3050
F 0 "BP1" V 4646 3002 50  0000 R CNN
F 1 "Green" V 4555 3002 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 4600 3250 50  0001 C CNN
F 3 "~" H 4600 3250 50  0001 C CNN
	1    4600 3050
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push BP2
U 1 1 6649580C
P 5150 3050
F 0 "BP2" V 5196 3002 50  0000 R CNN
F 1 "RED" V 5105 3002 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 5150 3250 50  0001 C CNN
F 3 "~" H 5150 3250 50  0001 C CNN
	1    5150 3050
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push BP3
U 1 1 6649619E
P 5700 3050
F 0 "BP3" V 5746 3002 50  0000 R CNN
F 1 "YELLOW" V 5655 3002 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 5700 3250 50  0001 C CNN
F 3 "~" H 5700 3250 50  0001 C CNN
	1    5700 3050
	0    -1   -1   0   
$EndComp
$Comp
L Switch:SW_Push BP4
U 1 1 66496776
P 6300 3050
F 0 "BP4" V 6346 3002 50  0000 R CNN
F 1 "BLUE" V 6255 3002 50  0000 R CNN
F 2 "Button_Switch_THT:SW_PUSH-12mm" H 6300 3250 50  0001 C CNN
F 3 "~" H 6300 3250 50  0001 C CNN
	1    6300 3050
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4350 2850 4600 2850
Wire Wire Line
	4600 2850 5150 2850
Connection ~ 4600 2850
Wire Wire Line
	5150 2850 5700 2850
Connection ~ 5150 2850
Wire Wire Line
	5700 2850 6300 2850
Connection ~ 5700 2850
$Comp
L Device:R R11
U 1 1 664976EB
P 4600 4050
F 0 "R11" H 4670 4096 50  0000 L CNN
F 1 "10K" H 4670 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 4530 4050 50  0001 C CNN
F 3 "~" H 4600 4050 50  0001 C CNN
	1    4600 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R12
U 1 1 66497D72
P 5150 4050
F 0 "R12" H 5220 4096 50  0000 L CNN
F 1 "10K" H 5220 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5080 4050 50  0001 C CNN
F 3 "~" H 5150 4050 50  0001 C CNN
	1    5150 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R13
U 1 1 664983D7
P 5700 4050
F 0 "R13" H 5770 4096 50  0000 L CNN
F 1 "10K" H 5770 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 5630 4050 50  0001 C CNN
F 3 "~" H 5700 4050 50  0001 C CNN
	1    5700 4050
	1    0    0    -1  
$EndComp
$Comp
L Device:R R14
U 1 1 66498950
P 6300 4050
F 0 "R14" H 6370 4096 50  0000 L CNN
F 1 "10K" H 6370 4005 50  0000 L CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P7.62mm_Horizontal" V 6230 4050 50  0001 C CNN
F 3 "~" H 6300 4050 50  0001 C CNN
	1    6300 4050
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 6649954E
P 4600 4550
F 0 "#PWR0102" H 4600 4300 50  0001 C CNN
F 1 "GND" H 4605 4377 50  0000 C CNN
F 2 "" H 4600 4550 50  0001 C CNN
F 3 "" H 4600 4550 50  0001 C CNN
	1    4600 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4200 4600 4250
Wire Wire Line
	4600 4250 5150 4250
Wire Wire Line
	5150 4250 5150 4200
Connection ~ 4600 4250
Wire Wire Line
	5150 4250 5700 4250
Wire Wire Line
	5700 4250 5700 4200
Connection ~ 5150 4250
Wire Wire Line
	5700 4250 6300 4250
Wire Wire Line
	6300 4250 6300 4200
Connection ~ 5700 4250
$Comp
L Connector:Conn_01x06_Male J1
U 1 1 664B26FE
P 7750 3050
F 0 "J1" H 7950 3400 50  0000 R CNN
F 1 "Conn_01x06_Male" H 7858 3340 50  0001 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-6_P5.08mm" H 7750 3050 50  0001 C CNN
F 3 "~" H 7750 3050 50  0001 C CNN
	1    7750 3050
	-1   0    0    -1  
$EndComp
Wire Wire Line
	6300 2850 7550 2850
Connection ~ 6300 2850
Connection ~ 6300 4250
Wire Wire Line
	6300 3750 7500 3750
Wire Wire Line
	7500 3250 7550 3250
Connection ~ 6300 3750
Wire Wire Line
	6300 3750 6300 3900
Wire Wire Line
	4600 4250 4600 4550
Wire Wire Line
	6300 3250 6300 3750
Wire Wire Line
	7500 3250 7500 3750
Wire Wire Line
	6300 4250 7550 4250
Wire Wire Line
	7550 3350 7550 4250
Wire Wire Line
	7450 3150 7450 3700
Wire Wire Line
	7450 3700 5700 3700
Wire Wire Line
	5700 3250 5700 3700
Connection ~ 5700 3700
Wire Wire Line
	5700 3700 5700 3900
Wire Wire Line
	7550 3050 7400 3050
Wire Wire Line
	7400 3050 7400 3650
Wire Wire Line
	7400 3650 5150 3650
Wire Wire Line
	5150 3250 5150 3650
Connection ~ 5150 3650
Wire Wire Line
	5150 3650 5150 3900
Wire Wire Line
	7550 2950 7350 2950
Wire Wire Line
	7350 2950 7350 3600
Wire Wire Line
	7350 3600 4600 3600
Wire Wire Line
	4600 3250 4600 3600
Connection ~ 4600 3600
Wire Wire Line
	4600 3600 4600 3900
Text GLabel 9000 2600 2    50   Input ~ 0
+5V
Text GLabel 9000 2750 2    50   Input ~ 0
GREEN
Text GLabel 9000 2900 2    50   Input ~ 0
RED
Text GLabel 9000 3200 2    50   Input ~ 0
BLUE
Text GLabel 9000 3050 2    50   Input ~ 0
YELLOW
Text GLabel 9000 3350 2    50   Input ~ 0
GND
Wire Wire Line
	8950 2600 7850 2600
Wire Wire Line
	7850 2600 7850 2850
Wire Wire Line
	7850 2850 7550 2850
Connection ~ 7550 2850
Wire Wire Line
	9000 2750 7900 2750
Wire Wire Line
	7900 2750 7900 2950
Wire Wire Line
	7900 2950 7550 2950
Connection ~ 7550 2950
Wire Wire Line
	9000 2900 7950 2900
Wire Wire Line
	7950 2900 7950 3050
Wire Wire Line
	7950 3050 7550 3050
Connection ~ 7550 3050
Wire Wire Line
	9000 3050 8000 3050
Wire Wire Line
	8000 3050 8000 3150
Wire Wire Line
	7450 3150 7550 3150
Connection ~ 7550 3150
Wire Wire Line
	7550 3150 8000 3150
Wire Wire Line
	9000 3200 8050 3200
Connection ~ 7550 3250
Wire Wire Line
	7550 3250 8050 3250
Wire Wire Line
	7550 3350 9000 3350
Connection ~ 7550 3350
Wire Wire Line
	8050 3250 8050 3200
Text Notes 7050 7050 0    138  ~ 28
Mighty Tronics\nConnect, Create & Innovate!
Text Notes 7350 7500 0    59   ~ 0
Front pannel  of the greenhouse
Text Notes 8150 7650 0    59   ~ 0
24-06-2025
$EndSCHEMATC
