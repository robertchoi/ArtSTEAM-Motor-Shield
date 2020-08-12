#include <SoftwareSerial.h>  

// SoftwareSerial(RX, TX) 형식으로 블루투스 모듈과 교차하여 연결

SoftwareSerial BlueToothSerial(A1, A0);

 
void setup(){
    Serial.begin(9600);           // Serial 통신 초기화
    BlueToothSerial.begin(9600);  // 블루투스 통신 초기화(SoftwareSerial 통신 초기화)
}

 

void loop(){

// 블루투스 모듈 ➜ 아두이노 ➜ 시리얼 모니터
    if(BlueToothSerial.available()){                    // 데이터 수신 대기
       char receivechar = BlueToothSerial.read();       // 수신 데이터 읽기
       Serial.write(receivechar);                       // 수신 데이터 시리얼모니터로 출력
    }

// 시리얼 모니터 ➜ 아두이노 ➜ 블루투스 모듈
    if(Serial.available()){                             // 시리얼 모니터 확인
       char transmitchar = Serial.read();               // 시리얼 모니터 데이터 읽기
       BlueToothSerial.write(transmitchar);             // 블루투스로 데이터 전송
    }
}
