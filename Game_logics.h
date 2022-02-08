#ifndef GAME_LOGICS_H_INCLUDED
#define GAME_LOGICS_H_INCLUDED

#include"inputDevices.h"
#include"outputDevices.h"
int Destroyer[]={1,1};
int Submarine[]={2,2,2};
int Cruiser[]={3,3,3};
int Battleship[]={4,4,4,4};
int Carrier[]={5,5,5,5,5};
int timeSinceSinked1[5]={0,0,0,0,0};
int timeSinceSinked2[5]={0,0,0,0,0};

int ScorePlayer1 , ScorePlayer2;

int Sinked(int matrice_dorita[],int size_board,int tip_ship)
{
int sinked=1;
for(int i=0;i<size_board;i++)
for(int j=0;j<size_board;j++)
if(matrice_dorita[(i-1)*size_board+j]==tip_ship)
sinked=0;
return sinked;
}

int win( int matrice_dorita[],int size_board)
{
int winvalue=1;
for(int i=0;i<size_board;i++)
for(int j=0;j<size_board;j++)
if(matrice_dorita[(i-1)*size_board+j]!=6 && matrice_dorita[(i-1)*size_board+j]!=-1 && matrice_dorita[(i-1)*size_board+j]!=0)
winvalue=0;
return winvalue;
}
int lose(int matrice_dorita[],int size_board)
{

int loseval=1;
for(int i=0;i<size_board;i++)
for(int j=0;j<size_board;j++)
if(matrice_dorita[(i-1)*size_board+j]==0)
loseval=0;
return loseval;

}
int battleships_player1[]={1,1,1,1,1};
int battleships_player2[]={1,1,1,1,1};

int PlacedBatleships1()
{
for(int i=0;i<5;i++)
if(battleships_player1[i]!=0)
  return 0;
  return 1;
}
int PlacedBatleships2()
{
for(int i=0;i<5;i++)
if(battleships_player2[i]!=0)
  return 0;
  return 1;
}
//return 1 if succes -1 if the placement can't be done -2 if the game already started
int Place_battle_ship_on_grid(int matrice_dorita[],int size_board,int tip_ship,int x_location,int y_location,int vert_orizont)
{
  int size_ships[6]={0,1,2,2,3,4};

  for(int i=0;i<size_ships[tip_ship];i++)
  {
    if(vert_orizont==0)
    {
        int index=(y_location-1)*size_board+x_location+i;

        if(matrice_dorita[index]!=0)
          return -1;
          matrice_dorita[index]=tip_ship;

    }else
    {
      int index=(y_location-1+i)*size_board+x_location;
      if(matrice_dorita[index]!=0)
          return -1;
        matrice_dorita[index]=tip_ship;
    }

  }


}
void TryToHit(int size_board,int x_location,int y_location,int* enemy_mat,int* visible_mat,int Player)
{    //try to hit and hit

    if(enemy_mat[y_location*size_board+x_location]>0 && enemy_mat[y_location*size_board+x_location]!=6)
    {

        printHit(Player,x_location,y_location);
        enemy_mat[y_location*size_board+x_location]=6;
        visible_mat[y_location*size_board+x_location]=6;
        if(Player==1)
             ScorePlayer1+= enemy_mat[y_location*size_board+x_location];
            else
             ScorePlayer2+= enemy_mat[y_location*size_board+x_location];



    }
    else
    {

        //you missed

        printMiss(Player,x_location,y_location);
        enemy_mat[y_location*size_board+x_location]=-1;
        visible_mat[y_location*size_board+x_location]=-1;
         if(Player==1)
             ScorePlayer1+= -1;
            else
             ScorePlayer2+= -1;

    }


}

void Check_sincked(int Player,int size_board )
{
    for(int i=0;i<5;i++)
 {
     if(Player==1)
     if(Sinked(matriceHidden1,size_board,i))
     {  if(timeSinceSinked1[i]==0)
         print_Sinked(1,i);
         timeSinceSinked1[i]++;
     }
     else
    if(Sinked(matriceHidden2,size_board,i))
       {if(timeSinceSinked2[i]==0)
         print_Sinked(2,i);
         timeSinceSinked2[i]++;
     }
 }

}





void Game_run(int size_board)
{

while(!PlacedBatleships1() && !PlacedBatleships2() )
{


for(int i=0;i<5;i++)
{
if(battleships_player1[i])
{
print_wait_message(2);
printOnMonitor(matriceHidden1,matricePlayer1,size_board);

placeShip(1,i);
ask_for_location(1,size_board);
if(Place_battle_ship_on_grid(matriceHidden1,size_board,i+1,location[0][0],location[0][1] ,location[0][2])==-1)
    print_eroare1(1);
printOnMonitor(matriceHidden1,matricePlayer1,size_board);
}

if(battleships_player2[i])
{
print_wait_message(1);
printOnBluetooth(matriceHidden2,matricePlayer2,size_board);
placeShip(2,i);
ask_for_location(2,size_board);
if(Place_battle_ship_on_grid(matriceHidden2,size_board,i+1,location[1][0],location[1][1] ,location[1][2])==-1)
    print_eroare1(2);
printOnBluetooth(matriceHidden2,matricePlayer2,size_board);

}




}
}

while(!win(matriceHidden1,size_board)  && !win(matriceHidden2,size_board)
&& !lose(matriceHidden1,size_board) && !lose(matriceHidden2,size_board))
{



print_wait_message(2);
printOnMonitor( matriceHidden1,matricePlayer1, size_board);
ask_for_location2(1,size_board);
TryToHit(size_board, location[0][0],location[0][1] ,matriceHidden2,matricePlayer1,1);
Check_sincked(2,size_board);
printOnMonitor( matriceHidden1,matricePlayer1, size_board);


print_wait_message(1);
printOnBluetooth(matriceHidden2,matricePlayer2,size_board);
ask_for_location2(2,size_board);
TryToHit(size_board, location[1][0],location[1][1] ,matriceHidden1,matricePlayer2,2);
Check_sincked(1,size_board);
printOnBluetooth(matriceHidden2,matricePlayer2,size_board);


}
print_final_score( ScorePlayer1, ScorePlayer2);




}










#endif // GAME_LOGICS_H_INCLUDED
