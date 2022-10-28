#include<iostream>

using namespace std;

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
        bool isPisoteado(){
            return pisoteado;
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
        void setPisoteado(){
            pisoteado = true;
        }
        
};