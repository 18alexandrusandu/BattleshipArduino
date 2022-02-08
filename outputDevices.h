#ifndef OUTPUTDEVICES_H_INCLUDED
#define OUTPUTDEVICES_H_INCLUDED



int matriceHidden1[]={
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,

};

int matricePlayer1[]={
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
};
int matricePlayer2[]={
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
};

int matriceHidden2[]={
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0
};
char ShipsNames[][30]={"Destroyer","Submarine","Cruiser","Battleship","Carrier"};

#include<string.h>
void printOnMonitor(int* mat1,int* mat2,int size_mat)
{

 char header[100]="harta ta";
 int s1= strlen(header);
   if(size_mat==8)
   {
    for(int i=0;i<22;i++)
       header[s1+i]=' ';
       header[s1+23]=0;
   }
  if(size_mat==5)
   {
    for(int i=0;i<10;i++)
       header[s1+i]=' ';
       header[s1+11]=0;
   }




 strcat(header,"|harta adversarului");


  Serial.println(header);
  Serial.println(" ");
  Serial.print("  ");

for(int i=0;i<size_mat;i++)
{
  Serial.print(i);
  Serial.print("  ");

}

  Serial.print("|");

for(int i=0;i<size_mat;i++)
{
  Serial.print(i);
  Serial.print("  ");
}
  Serial.println("\n");

for(int i=0;i<size_mat;i++)
{
  Serial.print(i);
for(int j=0;j<size_mat;j++)
{
  Serial.print("|");
  if(mat1[i*size_mat+j]==0)
Serial.print("  ");
  else
  if(mat1[i*size_mat+j]==-1)
 Serial.print(" X");
   else
 if(mat1[i*size_mat+j]==6)
 Serial.print(" H");
    else
 Serial.print(" *");


}

Serial.print("|");

for(int j=0;j<size_mat;j++)
{
  Serial.print("|");
  if(mat2[i*size_mat+j]==0)
Serial.print("  ");
  else
  if(mat2[i*size_mat+j]==-1)
 Serial.print(" X");
   else
 if(mat2[i*size_mat+j]==6)
 Serial.print(" H");
    else
 Serial.print(" *");

}
 Serial.print("|");
 Serial.print("\n");

}

}

#include<string.h>
void printOnBluetooth(int* mat1,int* mat2,int size_mat)
{

 char header[100]="harta ta";
 int s1= strlen(header);
   if(size_mat==8)
   {
    for(int i=0;i<22;i++)
       header[s1+i]=' ';
       header[s1+23]=0;
   }
  if(size_mat==5)
   {
    for(int i=0;i<10;i++)
       header[s1+i]=' ';
       header[s1+11]=0;
   }




 strcat(header,"|harta adversarului");


  Serial1.println(header);
  Serial1.println(" ");
  Serial1.print("  ");

for(int i=0;i<size_mat;i++)
{
  Serial1.print(i);
  Serial1.print("  ");

}

  Serial1.print("|");

for(int i=0;i<size_mat;i++)
{
  Serial1.print(i);
  Serial1.print("  ");
}
  Serial1.println("\n");

for(int i=0;i<size_mat;i++)
{
  Serial1.print(i);
for(int j=0;j<size_mat;j++)
{
  Serial1.print("|");
  if(mat1[i*size_mat+j]==0)
Serial1.print("   ");
  else
  if(mat1[i*size_mat+j]==-1)
 Serial1.print(" X ");
   else
 if(mat1[i*size_mat+j]==6)
 Serial1.print(" H ");
    else
 Serial1.print(" * ");


}

Serial1.print("|");

for(int j=0;j<size_mat;j++)
{
  Serial1.print("|");
  if(mat2[i*size_mat+j]==0)
Serial1.print("   ");
  else
  if(mat2[i*size_mat+j]==-1)
 Serial1.print(" X ");
   else
 if(mat2[i*size_mat+j]==6)
 Serial1.print(" H ");
    else
 Serial1.print(" * ");

}
 Serial1.print("|");
 Serial1.print("\n");

}

}


void printHit(int Player,int x_location,int y_location)
{
    if(Player==1)
     {
     Serial.print("you hit a location at:");
     Serial.print("row:");
     Serial.print(y_location);
     Serial.print(",column:");
     Serial.print(x_location);
     Serial.print("\n");
    }
     else
    {Serial1.print("you hit a location at:");
     Serial1.print("row:");
     Serial1.print(y_location);
     Serial1.print(",column:");
     Serial1.print(x_location);
     Serial1.print("\n");
     }




}

void printMiss(int Player,int x_location,int y_location)
{
         if(Player==1)
     {
     Serial.print("you missed a location at:");
     Serial.print("row:");
     Serial.print(y_location);
     Serial.print(",column:");
     Serial.print(x_location);
     Serial.print("\n");
    }
     else
    {Serial1.print("you missed a location at:");
     Serial1.print("row:");
     Serial1.print(y_location);
     Serial1.print(",column:");
     Serial1.print(x_location);
     Serial1.print("\n");
     }

}
int placeShip(int Player,int typeship)
{
if(Player==1)
{

Serial.print("you try to place a ship of type ");
Serial.print(ShipsNames[typeship]);
Serial.print("\n");
}
else
{

Serial1.print("you try to place a ship of type ");
Serial1.print(ShipsNames[typeship]);
Serial1.print("\n");
}

}

void print_ask_start(int Player,int size_of_board)
{
    if(Player==1)
    {
        Serial.print("you try to find out a batlleship");
        Serial.print("\n Please choose an x and y location from the range 0 to %d");
        Serial.print(size_of_board);
        Serial.print("\n Please choose a row number\n");
    }
    else
    {   Serial1.print("you try to find out a batlleship");
        Serial1.print("\n Please choose an x and y location from the range 0 to %d");
        Serial1.print(size_of_board);
        Serial1.print("\n Please choose a row number\n");

    }


}

void print_ask_choose(int Player,int x_location,int y_location)
{

    if(Player==1)
    {

        Serial.print("\n Position you choosed is:(");
        Serial.print(y_location);
        Serial.print(",");
        Serial.print(x_location);
        Serial.print(")\n");

    }
    else
    {


        Serial1.print("\n Position you choosed is:(");
        Serial1.print(y_location);
        Serial1.print(",");
        Serial1.print(x_location);
        Serial1.print(")\n");

    }


}
void print_ask_column(int Player)
{

    if(Player==1)
    Serial.print("\n Please choose a column number\n");
    else
    Serial1.print("\n Please choose a column number\n");

}

void print_ask_orientation1(int Player)
{

     if(Player==1)
     Serial.print("\n Please choose orientation: do you want your ship orizontal:0 or vertical:1 \n");
      else
     Serial1.print("\n Please choose orientation: do you want your ship orizontal:0 or vertical:1 \n");

}

void print_ask_orientation2(int Player,char key)
{
     if(Player==1)
     {

         if(key=='0')
     {
    Serial.print("you choose horizontal\n");

     }
     else
     if(key=='1')
     {
       Serial.print("you choose vertical\n");

     }

     }
     else
     {
      if(key=='o')
     {
    Serial1.print("you choose horizontal\n");
     }
     else
     if(key=='v')
     {
       Serial1.print("you choose vertical\n");

     }

     }
}

void print_auxiliary_x_location(int Player,int x_location)
{
    if(Player==1)
Serial.print(x_location);
   else
Serial1.print(x_location);

}

void print_auxiliary_y_location(int Player,int y_location)
{
   if(Player==1)
   Serial.print(y_location);
     else
   Serial1.print(y_location);

}

void print_final_score(int ScorePlayer1,int ScorePlayer2)
{
    Serial.print("The game has ended. Your final Score is:");
    Serial.print(ScorePlayer1);
    Serial.print("\n");
    Serial.print("The other player final score is:");
    Serial.print(ScorePlayer2);
    Serial.print("\n");
    Serial.print("the winner is:");
    if(ScorePlayer1>ScorePlayer2)
    Serial.print("You");
    else
    Serial.print("The other player");


    Serial1.print("The game has ended. Your final Score is:");
    Serial1.print(ScorePlayer2);
    Serial1.print("\n");
    Serial1.print("The other player final score is:");
    Serial1.print(ScorePlayer1);
    Serial1.print("\n");
    Serial1.print("the winner is:");
    if(ScorePlayer2>ScorePlayer1)
    Serial1.print("You");

}

void print_eroare1(int Player)
{
    if(Player==1)
    Serial.print("coudn't place ship on position because the desired position is not empty\n");
    else
    Serial1.print("coudn't place ship on position because the desired position is not empty\n");
}
void print_Sinked(int Player,int tip_ship )
{

    if(Player==1)
    { Serial.print(ShipsNames[tip_ship]);
      Serial.print("was sinked");
    }
    else
   {
    Serial1.print(ShipsNames[tip_ship]);
    Serial1.print("was sinked");

   }



}
void print_wait_message(int Player)
{
    if(Player==1)
        Serial.print("Please wait after Player 2 ends his input\n");
    else
        Serial1.print("please wait after Player 1 ends his input\n");

}






#endif // OUTPUTDEVICES_H_INCLUDED
