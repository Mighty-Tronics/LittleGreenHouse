//Little Greenhouse 0.1
//Code to manage a small green house for plants
//Watering based on the level of humidity of soil
//Ventilation based on the humidity and temperature of air
//Displaying on OLED environmental measures
//Capable to set triggers for watering and ventilation

//Libraries
#include "DHT.h"
#include "Wire.h"
#include <U8x8lib.h>
#include <DS3231.h>

//Setup devices

  // Setup Oled with U8x8 lib
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif

  //Setup DHT11
#define DHTTYPE DHT11
#define DHTPIN 2

  //Set Soil sensor
#define SOILPIN A0
  
//Create devices instances
DHT dht(DHTPIN, DHTTYPE); // Humidity sensor DHT11
DS3231  rtc(SDA, SCL); // create instance for Real Time clock DS3231

//Define pins for buttons
#define GREEN 3
#define RED 4
#define YELLOW 5
#define BLUE 6
#define PUMP_WATER 9
#define LEDS 10

//Define OLED display size
//U8X8_SSD1306_128X64_NONAME_SW_I2C u8x8(/* clock=*/ SCL, /* data=*/ SDA, /* reset=*/ U8X8_PIN_NONE);   // OLEDs without Reset of the Display
U8X8_SSD1306_128X64_NONAME_HW_I2C u8x8(/* reset=*/ U8X8_PIN_NONE);   

//Intitialize triggers
int HUMSOIL = 10;
int L_DURATION = 0;
int tempH = 0 ;
int tempM = 0 ;
int startTime = 0 ;
int LstartH = 0 ;
int LstartMN = 0 ;
int LstopH = 0;
int LstopMN = 0 ;
//int minutesNow = 0 ;
//Functions

  //Display Splash Screen
 void Disp_Splash(){ 
  //Clear screen
  u8x8.clearDisplay();  
  //Display text  
  u8x8.drawString(5,1,"LITTLE");  
  u8x8.drawString(3,3,"GREENHOUSE"); 
  u8x8.drawString(5,5,"V 1.0");  
  delay(1000);
  u8x8.clearDisplay(); 
 }
 
  //Get temperature from DHT11
float Get_Temp_Air(){
  float temp_air;
  temp_air = dht.readTemperature();  
  return temp_air;
}

  //Get temperature from DHT11
float Get_Hum_Air(){
  float hum_air;
  hum_air = dht.readHumidity();
  return hum_air;
}

    //Get soil humidity from soil sensor
float Get_Hum_Soil(){
  int hum_digit;
  float hum_soil;
  float hum_step = 0.0049; 
  hum_digit = analogRead(SOILPIN);
  hum_soil = 100-(((hum_digit * hum_step)/5) * 100) ;
  return hum_soil;  
}

    //Display measures on display
void Disp_Mes(float tempA, float humA, float humS){
  u8x8.drawString(0,0,rtc.getDateStr());
  u8x8.drawString(0,1,rtc.getTimeStr());
  //Get_CurrentTime(rtc.getTimeStr());
  
  if (humS<HUMSOIL){    
    u8x8.drawString(9,1,"Dry!");
    Start_Watering(PUMP_WATER, 255, 5000);
  } 
  else  {    
    u8x8.drawString(9,1,"      ");   
  }
  u8x8.setCursor(0,3);
  u8x8.print("AIR TEMP: " + String(int(tempA)) + "C");  
  u8x8.setCursor(0,5);
  u8x8.print("AIR HUM:  " + String(int(humA)) + "%"); 
  u8x8.setCursor(0,7);
  u8x8.print("SOIL HUM: " + String(int(humS)) + "%");    
}

  //Check if setup mode is enabled to change triggers
void Check_TrigSetup(){
  if (digitalRead(GREEN)==HIGH){
    delay(3000);
    if (digitalRead(GREEN)==HIGH){
      u8x8.clearDisplay();
      u8x8.setCursor(0,0);
      u8x8.print("Enter Setup Mode");
      delay(700);
      Set_RtcTimeDate();
      Set_Hum_Trigger();
      Set_Light_Trigger();      
      //debugln("Enter Setup");
      u8x8.clearDisplay();
      u8x8.setCursor(0,0);      
      u8x8.print("Exit Setup");      
      delay(400);        
    }
  }
}

  //Set triggers to watering plants based on soil humidity level
void Set_Hum_Trigger(){        
  int tempH;
  tempH = HUMSOIL;
  
  u8x8.clearDisplay();
  do{         
    u8x8.setCursor(0,0);
    u8x8.print("SET WATER");
    u8x8.setCursor(0,2);
    u8x8.print("CURRENT: " + String(tempH) + "%");
    u8x8.setCursor(0,4);
    if (HUMSOIL<10){
      u8x8.print("NEW: 0" + String(HUMSOIL) + "%");
    }
    else{
      u8x8.print("NEW: " + String(HUMSOIL) + "%");
    }
    
    
    //Substract 5% to HUMSOIL trigger
    if (digitalRead(YELLOW)== HIGH){
      delay(500);
      if ((digitalRead(YELLOW)== LOW) && HUMSOIL>0){
        HUMSOIL = HUMSOIL -5;
        //debugln("Watering trigger: " + String(HUMSOIL));                                
      }
    }    
    //Add 5% to HUMSOIL trigger
    if (digitalRead(BLUE)== HIGH){
      delay(500);
      if ((digitalRead(BLUE)== LOW) && HUMSOIL<100){
        HUMSOIL = HUMSOIL + 5;  
        //debugln("Watering trigger: " + String(HUMSOIL));                               
      }
    }   
  }while(digitalRead(GREEN)== LOW);
  delay(1000);  
}

  //Set Lights triggers duration in hours
void Set_Light_Trigger(){        
  int tempL;
  tempL = L_DURATION;
  u8x8.clearDisplay();
   
  do{      
    u8x8.setCursor(0,0);
    u8x8.print("SET LIGHT");
    u8x8.setCursor(0,2);
    u8x8.print("CURRENT: " + String(L_DURATION) + "H");
    u8x8.setCursor(0,4);
    if (tempL<10){
      u8x8.print("NEW: 0" + String(tempL) + "H");
    }
    else{
      u8x8.print("NEW: " + String(tempL) + "H");  
    }     
    
    //Substract 1H to Light duration trigger
    if (digitalRead(YELLOW)== HIGH){
      delay(500);
      if ((digitalRead(YELLOW)== LOW) && tempL>0){
        tempL = tempL -1;
        //debugln("Light duration trigger: " + String(tempL));                                
      }
    }    
    //Add 1H to Light duration trigger
    if (digitalRead(BLUE)== HIGH){
      delay(500);
      if ((digitalRead(BLUE)== LOW) && tempL<24){
        tempL = tempL + 1;  
        //debugln("Light duration trigger: " + String(tempL));                               
      }
    }   
  }while(digitalRead(GREEN)== LOW); 
  
  if (tempL != L_DURATION){
    // set start time for the light...
    LstartH = Get_CurrentHours(rtc.getTimeStr()) ;
    LstartMN = Get_CurrentMinutes(rtc.getTimeStr()) ;
    L_DURATION = tempL;
    if (L_DURATION > 0){
      digitalWrite(LEDS,HIGH);
    }
    else if(L_DURATION == 0){
      digitalWrite(LEDS,LOW);
    }
    //Calculate stop time....
     LstopMN = LstartMN ;   
    if (LstartH + L_DURATION < 24){
      LstopH = LstartH + L_DURATION ;
    }
    else if (LstartH + L_DURATION > 24){
      LstopH = (LstartH + L_DURATION)-24 ;      
    } 
      }  
  delay(1000);
}

 //Set Hours for Real Time Clock DS3231 module
void Set_RtcTimeDate(){
  //Set Clock hours
  int tempH = Get_CurrentHours(rtc.getTimeStr()) ;
  int tempM = Get_CurrentMinutes(rtc.getTimeStr()) ;
  int tempD = Get_CurrentDay(rtc.getDateStr()) ;
  int tempMo = Get_CurrentMonth(rtc.getDateStr()) ;
  int tempY = Get_CurrentYear(rtc.getDateStr()) ;
  u8x8.clearDisplay();
  do{     
    u8x8.setCursor(0,0);
    u8x8.println("SET HOURS");    
    u8x8.setCursor(0,4);
    if (tempH<10){
      u8x8.print("Hours: 0" + String(tempH));  
    }
    else{
      u8x8.print("Hours: " + String(tempH)); 
    }    
    
    //Substract 1H to Clock
    if (digitalRead(YELLOW)== HIGH){
      delay(500);
      if ((digitalRead(YELLOW)== LOW) && tempH>0){
        tempH = tempH -1;                                    
      }
    }    
    //Add 1H toClock
    if (digitalRead(BLUE)== HIGH){
      delay(500);
      if ((digitalRead(BLUE)== LOW) && tempH<23){
        tempH = tempH + 1;                                        
      }      
    }   
  }while(digitalRead(GREEN)== LOW);  
  delay(1000);

  // Set Clock minutes
  u8x8.clearDisplay();
  do{      
    u8x8.setCursor(0,0);
    u8x8.println("SET MINUTES");    
    u8x8.setCursor(0,4);
    if (tempM<10){
      u8x8.print("Minutes: 0" + String(tempM));
    }
    else{
      u8x8.print("Minutes: " + String(tempM));
    }
    
   
    //Substract 1mn to Clock
    if (digitalRead(YELLOW)== HIGH){
      delay(500);
      if ((digitalRead(YELLOW)== LOW) && tempM>0){
        tempM = tempM -1;                                      
      }
    }    
    //Add 1mn to Clock
    if (digitalRead(BLUE)== HIGH){
      delay(500);
      if ((digitalRead(BLUE)== LOW) && tempM<59){
        tempM = tempM + 1;                           
      }
    }   
  }while(digitalRead(GREEN)== LOW);
  
  rtc.setTime(tempH, tempM, 0);
  //startTime = Get_CurrentTime(rtc.getTimeStr());
    
  delay(500);
  
  // Set Day
  u8x8.clearDisplay();
  do{      
    u8x8.setCursor(0,0);
    u8x8.println("SET DAY");    
    u8x8.setCursor(0,4);
    if (tempD<10){
      u8x8.print("Day: 0" + String(tempD));
    }
    else{
      u8x8.print("Day: " + String(tempD));
    }
    
   
    //Substract 1 to current Day
    if (digitalRead(YELLOW)== HIGH){
      delay(500);
      if ((digitalRead(YELLOW)== LOW) && tempD>1){
        tempD = tempD -1;                                      
      }
    }    
    //Add 1 to Day
    if (digitalRead(BLUE)== HIGH){
      delay(500);
      if ((digitalRead(BLUE)== LOW) && tempD<31){
        tempD = tempD + 1;                           
      }
    }   
  }while(digitalRead(GREEN)== LOW);
  
  delay(500);
  
  // Set Month
  u8x8.clearDisplay();
  do{      
    u8x8.setCursor(0,0);
    u8x8.println("SET MONTH");    
    u8x8.setCursor(0,4);
    if (tempMo<10){
      u8x8.print("Month: 0" + String(tempMo));
    }
    else{
      u8x8.print("Month: " + String(tempMo));
    }
       
    //Substract 1 to current Month
    if (digitalRead(YELLOW)== HIGH){
      delay(500);
      if ((digitalRead(YELLOW)== LOW) && tempMo>1){
        tempMo = tempMo -1;                                      
      }
    }    
    //Add 1 to current Month
    if (digitalRead(BLUE)== HIGH){
      delay(500);
      if ((digitalRead(BLUE)== LOW) && tempMo<12){
        tempMo = tempMo + 1;                           
      }
    }   
  }while(digitalRead(GREEN)== LOW);
  
  delay(500);

  // Set Year
  u8x8.clearDisplay();
  do{      
    u8x8.setCursor(0,0);
    u8x8.println("SET YEAR");    
    u8x8.setCursor(0,4);
    u8x8.print("Year: " + String(tempY));
           
    //Substract 1 to current Month
    if (digitalRead(YELLOW)== HIGH){
      delay(500);
      if ((digitalRead(YELLOW)== LOW) && tempY>2023){
        tempY = tempY -1;                                      
      }
    }    
    //Add 1 to current Month
    if (digitalRead(BLUE)== HIGH){
      delay(500);
      if ((digitalRead(BLUE)== LOW)){
        tempY = tempY + 1;                           
      }
    }   
  }while(digitalRead(GREEN)== LOW);

  rtc.setDate(tempD, tempMo, tempY);
  delay(1000);
}

  //Activate pump
void Start_Watering(int pin, int speed, int duration){
  delay(2000);
  u8x8.clearDisplay();
  u8x8.setCursor(0,4);
  u8x8.print("WATERING...");
  analogWrite(pin, speed);
  delay (duration);
  analogWrite(pin,0);  
}

  //Check if red button was pushed to amorce pump
void Check_WaterBtn(int pin, int speed){
  if (digitalRead(RED)==HIGH){
    //debugln("Manual watering started...");
    u8x8.clearDisplay();    
    do{           
        analogWrite(pin, speed);
        //debugln("Watering in progress...");
        u8x8.setCursor(3,4);
        u8x8.print("PUMP ON!");        
        delay(500);
      }while(digitalRead(RED) == HIGH);
      
    analogWrite(pin,0);
    u8x8.clearDisplay();
    u8x8.setCursor(3,4);
    u8x8.print("PUMP OFF!");     
    delay(700);
    u8x8.clearDisplay();    
    } 
  }

  /*Get current time and return in minutes
 int Get_CurrentTime(String tempTime){
  String hr,mn ;
  int hNow, mnNow, currentTime;
  hr = tempTime.substring(0,2);
  mn = tempTime.substring(3,5);
  hNow = hr.toInt();
  mnNow = mn.toInt();
  currentTime = (hNow*60) + mnNow ;
  return currentTime;  
 }*/

  //Check light duration
 void Check_LightDuration(){
   
  if (L_DURATION == 0){
    digitalWrite(LEDS, LOW);
  }
  if (L_DURATION == 24){
    digitalWrite(LEDS, HIGH);
  }

  if ((L_DURATION != 0) && (L_DURATION !=24)){
    int tempH = Get_CurrentHours(rtc.getTimeStr()) ;
    int tempM = Get_CurrentMinutes(rtc.getTimeStr()) ;
    if ((tempH == LstopH) && (tempM == LstopMN)){
      digitalWrite(LEDS, LOW);
    }   
    if ((tempH == LstartH) && (tempM == LstartMN)){
      digitalWrite(LEDS, HIGH);
    }
  }  
}

  //Get current hours
int Get_CurrentHours(String timeStr){
  String hStr;
  int hInt;
  hStr = timeStr.substring(0,2);
  hInt = hStr.toInt();
  return hInt;
}

 //Get current minutes
int Get_CurrentMinutes(String timeStr){
  String mStr;
  int mInt;
  mStr = timeStr.substring(3,5);
  mInt = mStr.toInt();
  return mInt;
}

//Get current day
int Get_CurrentDay(String dateStr){
  String dStr;
  int dInt;
  dStr = dateStr.substring(0,2);
  dInt = dStr.toInt();
  return dInt;
}

//Get current month
int Get_CurrentMonth(String dateStr){
  String mStr;
  int mInt;
  mStr = dateStr.substring(3,5);
  mInt = mStr.toInt();
  return mInt;
}

//Get current year
int Get_CurrentYear(String dateStr){
  String yStr;
  int yInt;
  yStr = dateStr.substring(6,10);
  yInt = yStr.toInt();
  return yInt;
}

//Genreral setup
void setup(){
  Serial.begin(115200);
  // Initialize DHT11 sensor
  dht.begin(); 
  
  // Initialize the rtc object 
  rtc.begin();
  //startTime = Get_CurrentTime(rtc.getTimeStr());  
  //Set input mode for buttons
  pinMode(GREEN, INPUT);
  pinMode(RED, INPUT);
  pinMode(YELLOW, INPUT);
  pinMode(BLUE, INPUT);
  //Set output mode for pump
  pinMode(PUMP_WATER, OUTPUT);
  digitalWrite(PUMP_WATER, LOW);
  //Set output mode for ramp leds
  pinMode(LEDS, OUTPUT);
  digitalWrite(LEDS, LOW);
  
  //Initialize Oled display
  u8x8.begin();
  u8x8.setPowerSave(0); 
  u8x8.setFont(u8x8_font_chroma48medium8_r); 
    
  //Call splash screen;
  Disp_Splash(); 
}

//main code
void loop() {
  float T_air, H_air, H_soil;
  T_air = Get_Temp_Air();
  H_air = Get_Hum_Air();
  H_soil = Get_Hum_Soil(); 
  Disp_Mes(T_air,H_air,H_soil); 
  Check_TrigSetup(); 
  Check_WaterBtn(PUMP_WATER,255);  
  Check_LightDuration();
}
 
