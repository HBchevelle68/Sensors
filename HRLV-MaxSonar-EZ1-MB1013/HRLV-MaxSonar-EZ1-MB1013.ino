//Written to read sensor data through PWM
//Arduino Uno


const int SensorRecvPin = 3; //PWM pin
long sensor;       //Raw sensor data
long mm;           //conversion to mm
long inches;       //conversion to inches 

void ReadSensor(){
  //Get the reading from the sesnsor in raw form(uS)
  //1uS = 1mm
  
  sensor = pulseIn(SensorRecvPin, HIGH); 
  mm = sensor;
  
  inches = mm/25.4; // convert to inches according to datasheet
}

void PrintRange(){
  Serial.print("Distance =");
  Serial.print(mm);
  Serial.print(" mm /  ");
  Serial.print(inches);
  Serial.print(" inches");
  Serial.println();
}


void setup() {
  Serial.begin(9600);
  
}

void loop() {
  ReadSensor();
  PrintRange();
  
  //VERY IMPORTANT!!!
  //HRLV-MaxSonar-EZ1 has a sensor read rate of 10Hz
  //Delay required to match!
  delay(100);

}


