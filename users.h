#include<iostream>
#include<fstream>
#include<vector>
#include <bits/stdc++.h>
#include<map>
#include<stdlib.h>
#include<string.h>

using namespace std;

bool comparar(pair<string, int>& m, pair<string, int>& n)
{
    return m.second < n.second;
}

void StoreData(string user, int puntaje){
    ifstream archivo,archivo2;
    ofstream anotar, anotar2, createBoard;
    string usuario;
    int cant, contero=0,aux=0;
    map<string,int> players_scores;
    
    archivo.open("Scores.txt",ios::in);
    archivo2.open("Names.txt",ios::in);
    
    if(archivo.fail()){
    }

    while(!archivo.eof()){//llenamos nuestro mapa
        getline(archivo2,usuario);
        archivo>>cant;
        players_scores.insert(make_pair(usuario,cant));
        contero++;
    }
    if(players_scores.find(user)!=players_scores.end()){
        if(players_scores[user]<puntaje){
            players_scores[user] = puntaje;
            contero--;
        }else{contero--;}
    }else{
        players_scores.insert(make_pair(user,puntaje));
    }
    
    archivo.close();
    archivo2.close();
    
    vector<pair<string,int>> helper;
    for(map<string,int>::iterator it = players_scores.begin(); it!=players_scores.end() ;it++){
        helper.push_back(*it);
    }
    sort(helper.begin(),helper.end(),comparar);//ordenamos

    anotar.open("Scores.txt");
    anotar2.open("Names.txt");

    for(vector<pair<string,int>>::iterator it = helper.end(); it>=helper.begin() ;it--){//Imprimimos al reves
        if(it==helper.end()){

        }else{
            pair<string,int> u = *it;
            if(aux == contero){
                anotar2<<u.first;
                anotar<<u.second;
            }else{
                anotar2<<u.first<<endl;
                anotar<<u.second<<endl;
            }
            aux++;
        }
    }
    anotar.close();
    anotar2.close();
    createBoard.open("board.txt"); //creamos el "board"
    aux=0;

    createBoard<<"SCORES \n";
    createBoard<<"Username: \t Score: \n";
    for(vector<pair<string,int>>::iterator it = helper.end(); it>=helper.begin() ;it--){
        if(it==helper.end()){

        }else{
            pair<string,int> u = *it;
            if(aux == contero){
                createBoard<<aux+1<<". "<<u.first<<"\t "<<u.second;
            }else{
                createBoard<<aux+1<<". "<<u.first<<"\t "<<u.second<<"\n";
            }
            aux++;
        }
    }
    createBoard.close();
}