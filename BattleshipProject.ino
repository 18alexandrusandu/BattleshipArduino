#include"inputDevices.h"
#include"outputDevices.h"
#include"Game_logics.h"
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  Game_run(8);
 // Serial1.print("hello\n");
 //  printOnBluetooth(matriceHidden2,matricePlayer2,8);
}
