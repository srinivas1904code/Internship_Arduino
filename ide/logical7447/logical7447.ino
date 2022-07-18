int w,x,y,z;
void sevenseg(int a1,int b1,int c1,int d1,int e1,int f1,int g1){
  digitalWrite(2,!(a1));
  digitalWrite(3,!(b1));
  digitalWrite(4,!(c1));
  digitalWrite(5,!(d1));
  digitalWrite(6,!(e1));
  digitalWrite(7,!(f1));
  digitalWrite(8,!(g1));
}
void bcdToSevenseg(int A,int B,int C,int D){  
int a,b,c,d,e,f,g;  
a = (C || (A&&(!C)) ||((!B)&&(!D)) ||(B&&D));
b = (((!A)&&(!B)) || (C&&D) || (A&&(!B)) || ((!C)&&(!D)));
c = (A || B || (!C) || D);
d = (((!B)&&(!D)) || (C&&(!D)) || ((!B)&&C&&D) || (B&&(!C)&&D));
e = ((C&&(!D)) || ((!B)&&(!D)));
f = ((A&&(!B)) || ((!C)&&(!D)) || (B&&(!D)) || ((!C)&&B));
g = ((A&&(!B)) || (C&&(!D)) || (B&&(!C)) || ((!B)&&C));
sevenseg(a,b,c,d,e,f,g);
}
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
w =  digitalRead(9);
x = digitalRead(10);
y = digitalRead(11);
z = digitalRead(12);
bcdToSevenseg(w,x,y,z);
}
