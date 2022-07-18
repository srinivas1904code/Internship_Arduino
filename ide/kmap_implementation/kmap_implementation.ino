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
int a,b,c,d;
int f = 0;

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
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  a=0;
  b=0;
  c=0;
  d=0;
  f = (a&&b) || (a&&c&&d) || ((!a)&&(!b)&&(d)) || (b)&&(!c)&&(!d);
  if(f){
    one();
  }
  else{
    zero();
  }
  

}
