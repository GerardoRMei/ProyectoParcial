#include<iostream>
#include "ZonaEspecial.h"
#include "entidad.h"
#include "users.h"
#include<thread>
#include<chrono>
#include<vector>
#include<time.h>
#include<pthread.h>
#include<windows.h>
#include<stdio.h>

using namespace std;

int board_X=25;
int board_Y=25;
bool GameOver=false, didWon=false;
int movement_counter =50;
int total_Score=0;
ZonaEspecial okane[3], SafeSpace;
entidad enemigo[2], player;

void GenerateObjects( ZonaEspecial monedas[3], ZonaEspecial &SafeSpace, entidad enemigo[2],entidad &player){
    int randX, randY, randZ, randW;
    for(int i=0;i<3;i++){
        randX = (rand() % board_X);
        randY = (1+rand() % board_Y);
        monedas[i]= ZonaEspecial(randX,randY,"$");
        randZ = (rand() % board_X);
        randW = (1+rand() % board_Y);
        enemigo[i] = entidad(randZ, randW, "X");
    }
    randX = (rand() % board_X);
    randY = (1+rand() % (board_Y-20));
    SafeSpace=ZonaEspecial(randX, randY,"0");
    player = entidad(board_X-1,board_Y-2,"P"); // para colocar al borde de la zona
}

void FillGameBoard(vector<vector<string>> board,ZonaEspecial monedas[3], ZonaEspecial SafeSpace,entidad enemigo[2],entidad &player){
    board.resize(board_Y, vector<string>(board_X));

    for(int i=0;i<board_Y;i++){
        for(int j=0;j<board_X;j++){
            if(i==0 || i == board_Y-1){
                board[i][j]= "-";
            }else if(i==monedas[0].getposicionY() && j==monedas[0].getposicionX() && monedas[0].isPisoteado()==false){
                board[i][j]= monedas[0].getSimbolo();
            }     
            else if(i==monedas[1].getposicionY() && j==monedas[1].getposicionX() && monedas[1].isPisoteado()==false){
                board[i][j]= monedas[1].getSimbolo();
            }
            else if(i==monedas[2].getposicionY() && j==monedas[2].getposicionX() && monedas[2].isPisoteado()==false){
                board[i][j]= monedas[2].getSimbolo();
            }
            else if(i==SafeSpace.getposicionY() && j==SafeSpace.getposicionX()){
                board[i][j]= SafeSpace.getSimbolo();
            }
            else if(i==enemigo[0].getposicionY() && j==enemigo[0].getposicionX()){
                board[i][j]= enemigo[0].getSimbolo();
            }
            else if(i==enemigo[1].getposicionY() && j==enemigo[1].getposicionX()){
                board[i][j]= enemigo[1].getSimbolo();
            }
            else if(i==player.getposicionY() && j==player.getposicionX()){
                board[i][j]= player.getSimbolo();
            }   
            else{
                board[i][j]=" ";
            }
        }
    }
    for(int i=0;i<board_X;i++){
        cout<<"\t\t|";
        for(int j=0;j<board_Y;j++){
            cout<<board[i][j];
        }
        cout<<"|\n";
    }
}

void checkGameOver(){
    if(movement_counter<=0){
        didWon=false;
        GameOver = true;
    }
    if(SafeSpace.isPisoteado()){
        didWon = true;
        GameOver = true;
    }
    if(player.checkCrash()){
        didWon = false;
        GameOver = true;
    }
}

void instructions(){ //funcion estilo menu para que explicar al usuario.
    cout<<"\n\n";
    cout<<"Intructions:  \n";
    cout<<"Goal: reach the safe zone before running out of time, also avoid the enemies\n";
    cout<<"1. To move one right type 'r', for 2 spaces right type '2r'"<<"\n";
    cout<<"2. To move one left type 'l', for 2 spaces left type '2l'"<<"\n";
    cout<<"3. To move one up type 'u', for 2 spaces up type '2u'"<<"\n";
    cout<<"4. To move one down type 'd', for 2 spaces down type '2d'"<<"\n";
    cout<<"5. For diagonal movement type 'dru', 'dlu', 'drd', 'dlu'"<<"\n";
}
void *PlayerMove(void *arg){
    string action;
    cout<<"Type your move"<<endl;
    getline(cin,action);

    if(action=="r"){
        if(player.getposicionX()+1>=board_X){}
        else{
            player.setposiciones(player.getposicionX()+1,player.getposicionY());
        }
    }
    else if(action=="2r"){
            if(player.getposicionX()+2>=board_X){
            }else{
                player.setposiciones(player.getposicionX()+2,player.getposicionY());
            }
    }
    else if(action=="l"){
            if(player.getposicionX()-1<0){}
            else{
                player.setposiciones(player.getposicionX()-1,player.getposicionY());
            }
    }
    else if(action=="2l"){
            if(player.getposicionX()-2<0){}
            else{
                player.setposiciones(player.getposicionX()-2,player.getposicionY());
            }
    }
    else if(action=="u"){
        if(player.getposicionY()-1<=0){}
        else{
            player.setposiciones(player.getposicionX(),player.getposicionY()-1);
        }
    }
    else if(action=="2u"){
            if(player.getposicionY()-2<=0){}
            else{
            player.setposiciones(player.getposicionX(),player.getposicionY()-2);
            }
    }
    else if(action=="d"){
        if(player.getposicionY()+1>=board_Y-1){}
        else{
        player.setposiciones(player.getposicionX(),player.getposicionY()+1);
        }
    }
    else if(action=="2d"){
        if(player.getposicionY()+2>=board_Y-1){}
        else{
        player.setposiciones(player.getposicionX(),player.getposicionY()+2);
        }    
    }
    else if(action=="dru"){
        if(player.getposicionX()+1>=board_X || player.getposicionY()-1<=0){}
        else{
        player.setposiciones(player.getposicionX()+1,player.getposicionY()-1);
        }
    }else if(action=="dlu"){
        if(player.getposicionX()-1<0 || player.getposicionY()-1<=0){}
        else{
        player.setposiciones(player.getposicionX()-1,player.getposicionY()-1);
        }
    }else if(action=="drd"){
        if(player.getposicionX()+1>=board_X || player.getposicionY()+1>=board_Y-1){}
        else{
        player.setposiciones(player.getposicionX()+1,player.getposicionY()+1);
        }
    }else if(action=="dld"){
        if(player.getposicionX()-1<0 || player.getposicionY()+1>=board_Y-1){}
        else{
        player.setposiciones(player.getposicionX()-1,player.getposicionY()+1);
        }
    }
    else{
        cout<<"Please type a valid movement, you lost a turn"<<endl;
    }
    //checar si golpeo la moneda
    for(int i=0;i<3;i++){
        if(player.getposicionX()==okane[i].getposicionX() && player.getposicionY()==okane[i].getposicionY()){
                okane[i].setPisoteado();
        }
    }
    if(player.getposicionX()==SafeSpace.getposicionX() && player.getposicionY()==SafeSpace.getposicionY()){
            SafeSpace.setPisoteado();
    }
    for(int i=0;i<2;i++){
        if(enemigo[i].getposicionX()==player.getposicionX() && enemigo[i].getposicionY()==player.getposicionY()){
                enemigo[i].setCrash();
                player.setCrash();
        }
    }
    checkGameOver();
    pthread_exit(NULL);
}

void *enemyMove(void *arg){
    srand(time(NULL));
    for(int i=0;i<2;i++){
        int coin_flip = (1 + rand() % 4);

        if(coin_flip==1){//uno arriba
            if(enemigo[i].getposicionY()-1<=0){}
            else{
                enemigo[i].setposiciones(enemigo[i].getposicionX(),enemigo[i].getposicionY()-1);
            }
        }else if(coin_flip==2){//uno abajo
            if(enemigo[i].getposicionY()+1>=board_Y-1){}
            else{
                enemigo[i].setposiciones(enemigo[i].getposicionX(),enemigo[i].getposicionY()+1);
            }
        }else if(coin_flip==3){//uno a la derecha
            if(enemigo[i].getposicionX()+1>=board_X){}
            else{
                enemigo[i].setposiciones(enemigo[i].getposicionX()+1,enemigo[i].getposicionY());
            }
        }else if(coin_flip==4){//uno a la izquierda
            if(enemigo[i].getposicionX()-1<=0){}
            else{
                enemigo[i].setposiciones(enemigo[i].getposicionX()-1,enemigo[i].getposicionY());
            }
        }
    }
    for(int i=0;i<2;i++){
        if(enemigo[i].getposicionX()==player.getposicionX() && enemigo[i].getposicionY()==player.getposicionY()){
                enemigo[i].setCrash();
                player.setCrash();
        }
    }
    checkGameOver();
    pthread_exit(NULL);
    
}
void *ClockDown(void *arg){
    for(;;){
        //this_thread::sleep_for(chrono::seconds(30));
    }

}
int getScore(){
    int puntaje=0;
    if(didWon==true){
        puntaje += 10*movement_counter;
        for(int i=0;i<3;i++){
            if(okane[i].isPisoteado()){
                puntaje +=1000;
            }
        }
    }else{
        puntaje += 5*(movement_counter);
    }
    return puntaje;
}

int main(){
    srand(time(NULL));
    vector<vector<string>> board;
    pthread_t jugador;
    pthread_t enemies[2];
    pthread_t jikan;
    int action, action2, action3, tiempo;
    string newUser;
    void *ret_join;
    
    GenerateObjects(okane, SafeSpace, enemigo, player);

    while(!GameOver){
        checkGameOver();
        instructions();
        FillGameBoard(board,okane,SafeSpace, enemigo, player);
        cout<<"\n \n"<<movement_counter<<" Turns left"<<endl;
        //tiempo = pthread_create(&jikan,NULL,&ClockDown,NULL);
        action = pthread_create(&jugador,NULL,&PlayerMove,NULL);
        action2 = pthread_create(&enemies[0],NULL,&enemyMove,NULL);
        action2 = pthread_join(enemies[0],&ret_join);
        action3 = pthread_create(&enemies[1],NULL,&enemyMove,NULL);
        action3 = pthread_join(enemies[1],&ret_join);
        movement_counter--;
        checkGameOver();
        system("pause");
        system("cls");
    }

    total_Score = getScore();
    cout<<"\t\t GAMEOVER!!!!!!!!!!!!!!!"<<endl;
    cout<<"Your score was "<<total_Score<<"\n";
    cout<<"Please type your username"<<endl;
    getline(cin,newUser);
    
   StoreData(newUser, total_Score);
    
    cout<<"THANKS FOR PLAYING MY GAME"<<endl;

    Sleep(1000);
}