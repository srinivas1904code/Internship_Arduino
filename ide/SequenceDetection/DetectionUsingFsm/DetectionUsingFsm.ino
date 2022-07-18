//  detecting 111 sequence using finite stae machine that uses d-latch or d-flipflop
void zero(){
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);  
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);    
  digitalWrite(8,HIGH);
}
void one(){
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);    
  digitalWrite(8,HIGH);  
}
void null(){
  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);  
  digitalWrite(6,HIGH);
  digitalWrite(7,HIGH);    
  digitalWrite(8,HIGH);  
}
int q1=0,q2=0,a=0;
int d1=0,d2=0;
int y=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,INPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(11,HIGH);
delay(2000);  
a = digitalRead(9);
if(a){
    one();
  }
else{
    zero();
  }
digitalWrite(11,LOW);
delay(2000);
null();
delay(1000);
d1 = (!q1)&&(!q2)&&(a);  // the boolean equations here satisfiy only non repeating sequence
d2 = (q1)&&(a)&&(!q2);
y= (q2)&&a&&(!q1);
Serial.print(String(q1)+String(q2)+String(y));
if(y==1){
digitalWrite(10,HIGH);
delay(4000);
}
q1=d1;
q2 = d2;
digitalWrite(10,LOW);
}
