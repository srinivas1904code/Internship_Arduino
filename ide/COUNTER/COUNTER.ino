int a=0,b=0,c=0,d=0;
int w,x,y,z;
void setup() {
 // OTAsetup();
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT);
  pinMode(13,OUTPUT);
  pinMode(9,OUTPUT);//msb
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(8,OUTPUT);//lsb
  Serial.begin(9600);
}

void loop() {

  // put your main code here, to run repeatedly:
  //OTAloop();
  // delay(1000);
   digitalWrite(13,HIGH);
  a= digitalRead(2);
  b= digitalRead(3);
  c= digitalRead(4);
  d= digitalRead(5);
 // delay(1000);
  
  // w = (a&&(!d)) ||(b&&c&&d);
  // y = ((!a)&&(!c)&&(d))|| ((c)&&(!d));
  // x =((b)&&(!d))||(b&&(!c)&&d)||((!b)&&c&&d);
  // z = !d;   // equations for incremental decoder
w  = (!a)&&(!b)&&(!c)&&(!d) || (a&&d);
x =  (a)&&(!d)||(b&&d)||(b&&c);
y = (c&&d)||(a&&(!d))||(b&&(!c)&&(!d));
z = (!d);   // equations for decade counter
  digitalWrite(8,w);
  digitalWrite(9,x);
  digitalWrite(10,y);
  digitalWrite(11,z);
  delay(1000);
  Serial.println(String(w)+String(x)+String(y)+String(z));
  digitalWrite(13,LOW);  
  delay(1000);
  // a=w;//msb
  // b=x;
  // c=y;
  // d=z;//lsb
}
