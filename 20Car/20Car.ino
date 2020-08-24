#include <SoftwareSerial.h>
SoftwareSerial BTSerial(A1,A0); //Tx, Rx  --> Tx는 D2, Rx는 D3에 연결

#define in5 5
#define in6 6
#define in10 10
#define in11 11
#define LED 13

int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;

int command;
int Speed = 200;
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; 
int brakeTime = 45;
int brkonoff = 1; 

void setup() {
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in10, OUTPUT);
  pinMode(in11, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(LED, OUTPUT); //Set the LED pin.
  Serial.begin(9600);  
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available() > 0) {
    command = BTSerial.read();
    Stop(); //Initialize with motors stoped.
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        forwardleft();
        break;
      case 'I':
        forwardright();
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 140;
        break;
      case '2':
        Speed = 153;
        break;
      case '3':
        Speed = 165;
        break;
      case '4':
        Speed = 178;
        break;
      case '5':
        Speed = 191;
        break;
      case '6':
        Speed = 204;
        break;
      case '7':
        Speed = 216;
        break;
      case '8':
        Speed = 229;
        break;
      case '9':
        Speed = 242;
        break;
      case 'q':
        Speed = 255;
        break;
    }
    Speedsec = Turnradius;
    if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }
  }
}

void forward() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,HIGH);
   analogWrite(E1, Speed);
   analogWrite(E2, Speed);
//  analogWrite(in5, Speed);
//  analogWrite(in10, Speed);
}

void back() {
    digitalWrite(M1,LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, Speed);
    analogWrite(E2, Speed);
//  analogWrite(in6, Speed);
//  analogWrite(in11, Speed);
}

void left() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,LOW);
   analogWrite(E1, Speed);
   analogWrite(E2, Speed);
//  analogWrite(in5, Speed);
//  analogWrite(in11, Speed);
}

void right() {
   digitalWrite(M1,LOW);
   digitalWrite(M2,HIGH);
   analogWrite(E1, Speed);
   analogWrite(E2, Speed);
//  analogWrite(in6, Speed);
//  analogWrite(in10, Speed);
}
void forwardleft() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,HIGH);
   analogWrite(E1, Speed);
   analogWrite(E2, Speedsec);
//  analogWrite(in10, Speedsec);
//  analogWrite(in5, Speed);
}
void forwardright() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,HIGH);
   analogWrite(E1, Speedsec);
   analogWrite(E2, Speed);
//  analogWrite(in10, Speed);
//  analogWrite(in5, Speedsec);
}
void backright() {
   digitalWrite(M1,LOW);
   digitalWrite(M2,LOW);
   analogWrite(E1, Speed);
   analogWrite(E2, Speedsec);
//  analogWrite(in11, Speed);
//  analogWrite(in6, Speedsec);
}
void backleft() {
   digitalWrite(M1,LOW);
   digitalWrite(M2,LOW);
   analogWrite(E1, Speedsec);
   analogWrite(E2, Speed);
//  analogWrite(in11, Speedsec);
//  analogWrite(in6, Speed);
}

void Stop() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,HIGH);
   analogWrite(E1, 0);
   analogWrite(E2, 0);

//  analogWrite(in5, 0);
//  analogWrite(in6, 0);
//  analogWrite(in10, 0);
//  analogWrite(in11, 0);
}

void brakeOn() {
  //Here's the future use: an electronic braking system!
  // read the pushbutton input pin:
  buttonState = command;
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(in5, HIGH);
        digitalWrite(in6, HIGH);
        digitalWrite(in10, HIGH);
        digitalWrite(in11, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState = buttonState;
  }
}
void brakeOff() {

}
#include <SoftwareSerial.h>
SoftwareSerial BTSerial(A1,A0); //Tx, Rx  --> Tx는 D2, Rx는 D3에 연결

#define in5 5
#define in6 6
#define in10 10
#define in11 11
#define LED 13

int E1 = 10;
int M1 = 12;
int E2 =11;
int M2 = 13;

int command;
int Speed = 200;
int Speedsec;
int buttonState = 0;
int lastButtonState = 0;
int Turnradius = 0; 
int brakeTime = 45;
int brkonoff = 1; 

void setup() {
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in10, OUTPUT);
  pinMode(in11, OUTPUT);
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
  pinMode(LED, OUTPUT); //Set the LED pin.
  Serial.begin(9600);  
  Serial.println("Enter AT commands:");
  BTSerial.begin(9600);
}

void loop() {
  if (BTSerial.available() > 0) {
    command = BTSerial.read();
    Stop(); //Initialize with motors stoped.
    switch (command) {
      case 'F':
        forward();
        break;
      case 'B':
        back();
        break;
      case 'L':
        left();
        break;
      case 'R':
        right();
        break;
      case 'G':
        forwardleft();
        break;
      case 'I':
        forwardright();
        break;
      case 'H':
        backleft();
        break;
      case 'J':
        backright();
        break;
      case '0':
        Speed = 100;
        break;
      case '1':
        Speed = 140;
        break;
      case '2':
        Speed = 153;
        break;
      case '3':
        Speed = 165;
        break;
      case '4':
        Speed = 178;
        break;
      case '5':
        Speed = 191;
        break;
      case '6':
        Speed = 204;
        break;
      case '7':
        Speed = 216;
        break;
      case '8':
        Speed = 229;
        break;
      case '9':
        Speed = 242;
        break;
      case 'q':
        Speed = 255;
        break;
    }
    Speedsec = Turnradius;
    if (brkonoff == 1) {
      brakeOn();
    } else {
      brakeOff();
    }
  }
}

void forward() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,HIGH);
   analogWrite(E1, Speed);
   analogWrite(E2, Speed);
//  analogWrite(in5, Speed);
//  analogWrite(in10, Speed);
}

void back() {
    digitalWrite(M1,LOW);
    digitalWrite(M2, LOW);
    analogWrite(E1, Speed);
    analogWrite(E2, Speed);
//  analogWrite(in6, Speed);
//  analogWrite(in11, Speed);
}

void left() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,LOW);
   analogWrite(E1, Speed);
   analogWrite(E2, Speed);
//  analogWrite(in5, Speed);
//  analogWrite(in11, Speed);
}

void right() {
   digitalWrite(M1,LOW);
   digitalWrite(M2,HIGH);
   analogWrite(E1, Speed);
   analogWrite(E2, Speed);
//  analogWrite(in6, Speed);
//  analogWrite(in10, Speed);
}
void forwardleft() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,HIGH);
   analogWrite(E1, Speed);
   analogWrite(E2, Speedsec);
//  analogWrite(in10, Speedsec);
//  analogWrite(in5, Speed);
}
void forwardright() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,HIGH);
   analogWrite(E1, Speedsec);
   analogWrite(E2, Speed);
//  analogWrite(in10, Speed);
//  analogWrite(in5, Speedsec);
}
void backright() {
   digitalWrite(M1,LOW);
   digitalWrite(M2,LOW);
   analogWrite(E1, Speed);
   analogWrite(E2, Speedsec);
//  analogWrite(in11, Speed);
//  analogWrite(in6, Speedsec);
}
void backleft() {
   digitalWrite(M1,LOW);
   digitalWrite(M2,LOW);
   analogWrite(E1, Speedsec);
   analogWrite(E2, Speed);
//  analogWrite(in11, Speedsec);
//  analogWrite(in6, Speed);
}

void Stop() {
   digitalWrite(M1,HIGH);
   digitalWrite(M2,HIGH);
   analogWrite(E1, 0);
   analogWrite(E2, 0);

//  analogWrite(in5, 0);
//  analogWrite(in6, 0);
//  analogWrite(in10, 0);
//  analogWrite(in11, 0);
}

void brakeOn() {
  //Here's the future use: an electronic braking system!
  // read the pushbutton input pin:
  buttonState = command;
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == 'S') {
      if (lastButtonState != buttonState) {
        digitalWrite(in5, HIGH);
        digitalWrite(in6, HIGH);
        digitalWrite(in10, HIGH);
        digitalWrite(in11, HIGH);
        delay(brakeTime);
        Stop();
      }
    }
    // save the current state as the last state,
    //for next time through the loop
    lastButtonState = buttonState;
  }
}
void brakeOff() {

}
