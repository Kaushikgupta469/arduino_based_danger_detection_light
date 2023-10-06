int trigger_pin= 8;
int echo_pin= 9;

int green_led= 12;
int red_led= 13;

int distance;
long duration;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trigger_pin,OUTPUT);
  pinMode(echo_pin,INPUT);

  pinMode(green_led,OUTPUT);
  pinMode(red_led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
 digitalWrite(trigger_pin,LOW);
 delayMicroseconds(2);  //pause program for 2 microseconds->1 seconds=1000000 micro seconds
 digitalWrite(trigger_pin,HIGH);  //apply 5v to the trigger pin
 delayMicroseconds(10);      //pause program for 10 micro seconds ->1seconds=1000000 micro seconds
 digitalWrite(trigger_pin,LOW);    //apply 0v to trigger pin


 duration=pulseIn(echo_pin,HIGH);
 distance=(duration/2)/29.1;  //formula to calculate distance in cm

 Serial.print("Distance  :");
 Serial.print(distance);
 Serial.println(" CM ");

 if(distance <15){
  digitalWrite(red_led,HIGH);
  digitalWrite(green_led,LOW);
  Serial.print("Danger");}
  else{
    digitalWrite(green_led,HIGH);
    digitalWrite(red_led,LOW);
  Serial.print("Success");}
 }
