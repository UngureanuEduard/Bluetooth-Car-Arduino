#define NOTE_G5 784 //notele folosite pentru buzzer
#define NOTE_GS5 831
#define NOTE_E6 1319
#define NOTE_G6 1568
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_D7 2349
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_G7 3136
#define NOTE_A7 3520

int melody[] = {
NOTE_E7, NOTE_E7, 0, NOTE_E7,
0, NOTE_C7, NOTE_E7, 0,
NOTE_G7, 0, 0, 0, 
NOTE_G6, 0, 0, 0,

NOTE_C7, 0, 0, NOTE_G6, 
0, 0, NOTE_E6, 0,
0, NOTE_A6, 0, NOTE_B6,
0, NOTE_AS6, NOTE_A6, 0,

NOTE_G6, NOTE_E7, NOTE_G7,
NOTE_A7, 0, NOTE_F7, NOTE_G7,
0, NOTE_E7, 0, NOTE_C7,
 NOTE_D7, NOTE_B6, 0, 0,

NOTE_C7, 0, 0, NOTE_G6,
0, 0, NOTE_E6, 0,
0, NOTE_A6, 0, NOTE_B6, 
0, NOTE_AS6, NOTE_A6, 0,

NOTE_G6, NOTE_E7, NOTE_G7,
NOTE_A7, 0, NOTE_F7, NOTE_G7,
0, NOTE_E7, 0, NOTE_C7, 
NOTE_D7, NOTE_B6, 0, 0 }; //Tema melodică Super Mario

int tempo[] = {
12,12,12,12,
12,12,12,12,
12,12,12,12,
12,12,12,12,

12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,

9, 9, 9,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,

12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,

9, 9, 9,
12, 12, 12, 12,
12, 12, 12, 12,
12, 12, 12, 12,
};// Tempo Melodie
int melody2[] = {NOTE_GS5, NOTE_G5, NOTE_GS5, NOTE_G5}; // Tema melodică alarmă

#include <NewPing.h> //librarie senzor ultrasonic 
#include <Servo.h> //librarie servomotor
int mla = 2;
int mlb = 3;
int m2a = 4;
int m2b = 5;
int mspeed= 11;
//Pinii folositi pentru controlarea motoraşelor

char val;
//Variabila care primeste valoarea din modulul Bluetooth

#define melodyPin 12 //Pin Buzzer

NewPing sonar (7,6,500); //Pin Senzor Ultrasonic cu range maxim de 500cm

Servo S; //Declarare Servomotor

int viteza=255; //Viteza initiala
int vitezaob=80; //Viteza folosita la ocolire

void setup()
{
S.attach (10);
pinMode (mla, OUTPUT); 
pinMode (mlb, OUTPUT);
pinMode (m2a, OUTPUT);
pinMode (m2b, OUTPUT); 
pinMode (11, OUTPUT); 
pinMode (12, OUTPUT); 
Serial.begin(9600);
S.write (90);
delay (50);
}

void loop()
{
  while (Serial.available() > 0)
    val = Serial.read();

  if (val == '1') //Schimbare viteaza 1,2,3,4,5...
    viteza=70;
  else if (val== '2')
      viteza=90;
  else if (val== '3')
      viteza=110;
  else if (val == '4')
      viteza=140;
  else if (val == '5')
      viteza=170;
  else if (val =='6')
      viteza=180;
  else if (val='7')
      viteza=199;
  else if (val='8')
      viteza=227;
  else if (val == '9')
      viteza=255;
  else if ( val == 'F') // Inainte
      inainte (viteza);
  else if (val== 'B') // Inapoi
      inapoi (viteza);
  else if (val== 'R') //dreapta
      dreapta (viteza);
  else if (val == 'L') //stanga
      stanga (viteza);
  else if (val == 'S') //Stationar
      {
        stationar (viteza);
        if (sonar.ping_cm() <=4&&sonar.ping_cm() !=0)
          {
            for(int i=0;i<=4;i++)
              {
                int noteDuration=1000/ tempo[i];
                buzz (melodyPin, melody2 [i], noteDuration);
                int pauseBetweenNotes=noteDuration*1.30;
                delay (pauseBetweenNotes);
                buzz (melodyPin, 0, noteDuration);
              }
          }
      }
  else if (val=='q') //Tema melodică Super Mario
{
int size = sizeof(melody) / sizeof(int);
for (int thisNote = 0; thisNote < size; thisNote++) {
  int noteDuration=1000/ tempo [thisNote];
  buzz (melodyPin, melody [thisNote], noteDuration);
  int pauseBetweenNotes=noteDuration*1.30;
  delay (pauseBetweenNotes);
  buzz (melodyPin, 0, noteDuration);
  }
}
else if (val=='V') // Servomotor rotire la 0 grade
{
  S.write(0);
  delay (400);
}
else if (val=='U') // Servomotor rotire la 90 grade
{
  S.write(90);
  delay (400);
}
else if (val=='W') // Servomotor rotire la 180 grade
{
  S.write(180);
  delay(400);
}
else if (val=='X') // Ocolire obiect
ocolire();
}
void inainte (int viteza)
{
digitalWrite(mla, HIGH);
digitalWrite(mlb, LOW);
analogWrite (mspeed, viteza);
digitalWrite(m2a, HIGH);
digitalWrite(m2b, LOW);
analogWrite (mspeed, viteza);
}

void stanga (int viteza)
{
digitalWrite(mla, HIGH); 
digitalWrite(mlb, LOW);
analogWrite (mspeed, viteza);
digitalWrite(m2a, LOW);
digitalWrite(m2b, LOW);
analogWrite (mspeed, viteza);
}

void dreapta (int viteza)
{
digitalWrite(mla, LOW);
digitalWrite(mlb, LOW);
analogWrite (mspeed, viteza);
digitalWrite(m2a, HIGH); digitalWrite (m2b, LOW);
analogWrite (mspeed, viteza);
}

void inapoi (int viteza)
{
digitalWrite(mla, LOW);
digitalWrite(mlb, HIGH);
analogWrite (mspeed, viteza);
digitalWrite(m2a, LOW);
digitalWrite(m2b, HIGH);
analogWrite (mspeed, viteza);
}

void stationar (int viteza)
{
digitalWrite(mla, LOW);
digitalWrite(mlb, LOW);
analogWrite (mspeed, viteza);
digitalWrite (m2a, LOW);
digitalWrite(m2b, LOW);
analogWrite (mspeed, viteza);
}

void ocolire()
{
while (sonar.ping_cm()>19) //apropiere obiect
  inainte (vitezaob);
stationar (vitezaob); //stop'

S.write(180); //sonar stanga delay(2000);

while (sonar.ping_cm()>30)//dreapta
  dreapta (vitezaob);
delay(60);
stationar (vitezaob);

delay(2000);

while (sonar.ping_cm() <40)
  inainte (vitezaob);
stationar (vitezaob);

inainte (vitezaob);
delay (370);

stationar (vitezaob);

S.write(160);//sonar stanga
delay(2000);

while (sonar.ping_cm()>10)
  stanga (vitezaob);
stationar (vitezaob);
S.write(180);
delay(1500);

inainte (vitezaob);
delay(250);

stationar (vitezaob);

while (sonar.ping_cm()<20)
  inainte (vitezaob);
delay (350);
stationar (vitezaob);
}

void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2; 
  long numCycles = frequency * length / 1000; 
  for (long i = 0; i < numCycles; i++) { 
    digitalWrite(targetPin, HIGH); 
    delayMicroseconds(delayValue); 
    digitalWrite(targetPin, LOW); 
    delayMicroseconds(delayValue);
  }
  digitalWrite(13, LOW);
}