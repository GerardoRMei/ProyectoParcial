#include<iostream>
#include<vector>
#include<stdlib.h>
#include<string.h>
#include<fstream>
#include <time.h>
#include<pthread.h>


using namespace std;

int board_X=40;
int board_Y=40;
bool GameOver=false;
int movement_counter =100;
int total_Score=0;

class ZonaEspecial{
    private:
    int posX;
    int posY;
    string simbolo;
    bool pisoteado;//verifica si la zona tiene que estar activa o no.
    
    public:
    ZonaEspecial(){

    }
    ZonaEspecial(int X, int Y, string simb){
        posX = X;
        posY = Y;
        simbolo = simb;
        pisoteado = false;
    }

    bool isPisoteado();
    int getposicionX(){
        return posX;
    }
    int getposicionY(){
        return posY;
    }
    string getSimbolo(){
        return simbolo;
    }
    
};

class entidad{
    private:
    int posX;
    int posY;
    string simbolo;
    int movimiento;
    
    public:
    entidad(){

    }
    entidad(int X, int Y, string simb){
        posX = X;
        posY = Y;
        simbolo = simb;
    }
    int getposicionX(){
        return posX;
    }
    int getposicionY(){
        return posY;
    }
    string getSimbolo(){
        return simbolo;
    }

};

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
    player = entidad(38,38,"P"); // para colocar al borde de la zona
}

void StoreData(string user){
    ifstream archivo;
    ofstream apuntar;

}

void FillGameBoard(vector<vector<string>> board,ZonaEspecial monedas[3], ZonaEspecial SafeSpace,entidad enemigo[2],entidad &player){
    
    board.resize(board_Y, vector<string>(board_X));

    for(int i=0;i<board_Y;i++){
        for(int j=0;j<board_X;j++){
            if(i==0 || i == board_Y-1){
                board[i][j]= "-";
            }else if(i==monedas[0].getposicionY() && j==monedas[0].getposicionX()){
                board[i][j]= monedas[0].getSimbolo();
            }
            
            else if(i==monedas[1].getposicionY() && j==monedas[1].getposicionX()){
                board[i][j]= monedas[1].getSimbolo();
            }
            else if(i==monedas[2].getposicionY() && j==monedas[2].getposicionX()){
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


int main(){
    srand(time(NULL));

    vector<vector<string>> board;
    
    string newUser;
    ZonaEspecial okane[3], SafeSpace;
    entidad enemigo[2], player;
    
    GenerateObjects(okane, SafeSpace, enemigo, player);
    while(!GameOver){
    FillGameBoard(board,okane,SafeSpace, enemigo, player);
    cout<<"\n \n"<<"Le quedan "<<movement_counter<<" Turnos"<<endl;
    movement_counter--;
    system("pause");
    system("cls");
    }
    /*
    cout<<"GAME OVER!!!!!!!!!!!"<<"\n"<<"\n"<<"\n";
    cout<<"Please Type your name"<<endl;
    getline(cin,newUser);
    
    */

}