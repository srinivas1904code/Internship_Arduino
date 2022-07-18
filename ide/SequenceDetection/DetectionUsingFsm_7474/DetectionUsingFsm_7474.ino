//detection of 1111 sequence using fsm
int q1,q2,q3,d1,d2,d3;
int x,y;
void setup() {
  // put your setup code here, to run once:
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,INPUT); //input as x
  pinMode(7,OUTPUT); //y as output
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT); // clock
  pinMode(13,OUTPUT); // input led reference
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(13,HIGH);
  digitalWrite(11,HIGH);  
  delay(1000);
  x = digitalRead(5); 
  digitalWrite(13,LOW);
  q1 = digitalRead(4);
  q2 = digitalRead(3);
  q3 = digitalRead(2);
  d1 = (!q1)&&(!q3)&&x;
 d2 = (!q3 && q2 &&(!q1)&&x) ||(!q3 && (!q2)&&(q1)&&x);
 d3 = (q3 && !q2 && !q1 && x)||(!q3 && q1&&q2&&x);

  y=d3;
  digitalWrite(7,y);
  digitalWrite(10,d1);
  digitalWrite(9,d2);
  digitalWrite(8,d3);
  digitalWrite(11,LOW);   
  Serial.println(String(d3)+String(d2)+String(d1)+" y="+String(y));
  delay(1000);
}
