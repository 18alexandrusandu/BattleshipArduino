#ifndef INPUTDEVICES_H_INCLUDED
#define INPUTDEVICES_H_INCLUDED

#include<Keypad.h>
#include"outputDevices.h"
char keys[4][4]={
{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}};


 byte rowPins[4]={7,6,5,4};
 byte colPins[4]={3,14,15,16};
Keypad kpd=Keypad(makeKeymap(keys),rowPins,colPins,4,4);

int location[2][3]={{0,0,0},{0,0,0}};

void ask_for_location2(int Player,int size_of_board)
{
 if(Player==1)
 {
print_ask_start(1,size_of_board);

char key =kpd.getKey();
 int x_location,y_location;

while(!key)
 key =kpd.getKey();

  if(key)
  {
      y_location=key-'0';
      print_auxiliary_x_location(1,x_location);

  }

print_ask_column(1);
key=0;
 key =kpd.getKey();

while(!key)
 key =kpd.getKey();


  if(key)
  { x_location=key-'0';
    print_auxiliary_y_location(1,x_location);

  }


print_ask_choose(1,x_location,y_location);



location[0][0]=x_location;
location[0][1]=y_location;


}
else
{
print_ask_start(2,size_of_board);

char key=0;
if(Serial1.available())
  key =Serial1.read();
 int x_location,y_location;

while(!key)
{
   if(Serial1.available())
     key =Serial1.read();
}
Serial1.flush();

  if(key)
  {
   y_location=key-'0';

    print_auxiliary_y_location(2,y_location);

  }
Serial1.flush();
print_ask_column(2);
key=0;
 if(Serial1.available())
     key =Serial1.read();

while(!key)
  if(Serial1.available())
     key =Serial1.read();



  if(key)
  { x_location=key-'0';
      print_auxiliary_x_location(2,x_location);

  }
  Serial1.flush();
  print_ask_choose(2,x_location,y_location);
}

}
void ask_for_location(int Player,int size_of_board)
{
 if(Player==1)
 {
print_ask_start(1,size_of_board);

char key =kpd.getKey();
 int x_location,y_location;

while(!key)
 key =kpd.getKey();

  if(key)
  {
    y_location=key-'0';
    print_auxiliary_y_location(1,y_location);

  }
Serial.flush();
 print_ask_column(1);
key=0;
 key =kpd.getKey();

while(!key)
 key =kpd.getKey();


  if(key)
  { x_location=key-'0';
     print_auxiliary_x_location(1,x_location);


  }
Serial.flush();

 print_ask_choose(1,x_location,y_location);



int valid=0;

key=0;
 do{
    print_ask_orientation1(1);
    valid=1;
while(!key)
 key =kpd.getKey();

  print_ask_orientation2(1,key);

 if(key=='0')
 {
    location[0][2]=0;

 }
  else
 if(key=='1')
 {
       location[0][2]=1;
 }
 else
 valid=0;

 }while(valid==0);
location[0][0]=x_location;
location[0][1]=y_location;

Serial.flush();
}
else
{
print_ask_start(2,size_of_board);

char key=0;

 int x_location,y_location;
   Serial1.flush();
while(!key)
{

   if(Serial1.available())
      key =Serial1.read();
}
  if(key)
  {
   y_location=key-'0';
   print_auxiliary_y_location(2,y_location);

  }
 print_ask_column(2);
key=0;
  Serial1.flush();
while(key<=0)
  if(Serial1.available())
     key =Serial1.read();

Serial1.flush();

  if(key)
  { x_location=key-'0';
     print_auxiliary_x_location(2,x_location);

  }
print_ask_choose(2,x_location,y_location);


int valid=0;
    print_ask_orientation1(2);
    Serial1.flush();

    valid=1;
    key=0;

while(key==0)
    if(Serial1.available()>0)
     {
        key =Serial.read();
        Serial.print(key);
     }

 print_ask_orientation2(2,key);

 if(key=='0')
 {
       location[1][2]=0;

 }else
  if(key=='1')
 {
      location[1][2]=1;
 }
 else
 valid=0;

location[1][0]=x_location;
location[1][1]=y_location;
}

}

#endif // INPUTDEVICES_H_INCLUDED
