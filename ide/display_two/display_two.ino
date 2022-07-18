void sevenseg(int a1,int b1,int c1,int d1,int e1,int f1,int g1){
  digitalWrite(2,(a1));
  digitalWrite(3,(b1));
  digitalWrite(4,(c1));
  digitalWrite(5,(d1));
  digitalWrite(6,(e1));
  digitalWrite(7,(f1));
  digitalWrite(8,(g1));
}
void disp(int a){
  switch(a){
    case 0:sevenseg(0,0,0,0,0,0,1);
    break;
    case 1: sevenseg(1,0,0,1,1,1,1);
    break;
    case 2: sevenseg(0,0,1,0,0,1,0);
    break;
    case 3: sevenseg(0,0,0,0,1,1,0);
    break;
    case 4: sevenseg(1,0,0,1,1,0,0);
    break;
    case 5: sevenseg(0,1,0,0,1,0,0);
    break;
    case 6: sevenseg(1,1,0,0,0,0,1);
    break;
    case 7: sevenseg(0,0,0,1,1,1,1);
    break;
    case 8: sevenseg(0,0,0,0,0,0,0);
    break;
    case 9: sevenseg(0,0,0,1,1,0,0);
    break;
  }

}
void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);

  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(9,HIGH); //lsb
  digitalWrite(10,LOW);
  disp(0);
  delay(10);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  disp(1);
  delay(10);
}
