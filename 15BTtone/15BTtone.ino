#include "pitches.h"
#include <SoftwareSerial.h>  

// SoftwareSerial(RX, TX) 형식으로 블루투스 모듈과 교차하여 연결

SoftwareSerial BlueToothSerial(A1, A0);

// notes in the melody:
int melody[] = {
  NOTE_G7, NOTE_G7
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 4
};

int connectFlag = 1;


void setup() {
    Serial.begin(9600);           // Serial 통신 초기화
    BlueToothSerial.begin(9600);  // 블루투스 통신 초기화(SoftwareSerial 통신 초기화)
}

void loop() {
// 블루투스 모듈 ➜ 아두이노 ➜ 시리얼 모니터
    if(BlueToothSerial.available()){                    // 데이터 수신 대기
       char receivechar = BlueToothSerial.read();       // 수신 데이터 읽기
       //Serial.write(receivechar);                     // 수신 데이터 시리얼모니터로 출력
       
       if(receivechar == 0xFFFFFFF3){
          if(connectFlag){
            connectFlag = 0;
            playBeep();
          }
       }
       else if(receivechar == 0xFFFFFFF5){
          connectFlag = 1;
       }
       Serial.print(receivechar,HEX);
       Serial.print("\n");
    }

// 시리얼 모니터 ➜ 아두이노 ➜ 블루투스 모듈
    if(Serial.available()){                             // 시리얼 모니터 확인
       char transmitchar = Serial.read();               // 시리얼 모니터 데이터 읽기
       BlueToothSerial.write(transmitchar);             // 블루투스로 데이터 전송
    }
}


void playBeep(){
  // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 2; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(4, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(4);
  }  
}
