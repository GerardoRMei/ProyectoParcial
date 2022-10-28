#include<iostream>

using namespace std;

class entidad{
    private:
        int posX;
        int posY;
        string simbolo;
        bool crash;
    
    public:
        entidad(){

        }
        entidad(int X, int Y, string simb){
            posX = X;
            posY = Y;
            simbolo = simb;
            crash = false;
        }
        int getposicionX(){
            return posX;
        }
        
        int getposicionY(){
            return posY;
        }
        bool checkCrash(){
            return crash;
        }
        void setposiciones(int X, int Y){
         posX =X;
         posY= Y;
        }
        void setCrash(){
            crash=true;
        }
        
        string getSimbolo(){
            return simbolo;
        }
};