#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

class Escitala{
    public:
     string mensaje;
     string clave[3][5];
     string mCifrado;
     string mDescifrado;
     Escitala();
     void cifrado();
     void descifrado();
     int stoint(string);
     void generarClave();
};
void escribir(string mensaje,string narchivo){
    ofstream archivo;
    archivo.open("C://Users//DELL//Documents//Programacion 2019//AB//txt//" + narchivo + ".txt",ios::out);//lo abre;
    if(archivo.fail()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    archivo<<mensaje;
    //archivo<<"Hola que tal? mi nombre es RAFO"<<endl;
    archivo.close();
}
string lectura(string narchivo){
    ifstream archivo;
    string texto;
    archivo.open("C://Users//DELL//Documents//Programacion 2019//AB//txt//" + narchivo + ".txt",ios::in);
    if(archivo.fail()){
        cout<<"No se pudo leer el archivo"<<endl;
        exit(1);
    }
    while(!archivo.eof()){
        getline(archivo,texto);
        return texto;

    }
    archivo.close();

}

void Escitala::generarClave(){
    int x = 0;
    for(int i= 0; i<3;i++){
        for(int j = 0;j<5;j++){
            clave[i][j] += mensaje[x];
            x++;
        }
    }
    for(int i= 0; i<3;i++){
        for(int j = 0;j<5;j++){
            cout<<clave[i][j]<<" ";
        }
        cout<<endl;
    }
}
Escitala::Escitala(){
}
void Escitala::cifrado(){
    //cout<<"Ingrese el mensaje que desea cifrar = ";
    //getline(cin,mensaje);
    mensaje = lectura("mensaje");
    cout<<"Mensaje : "<<mensaje<<endl;
    generarClave();
    for(int i = 0,j=0; j<5;){
        mCifrado+=clave[i][j];
        //cout<<"clave["<<i<<"]["<<j<<"] -> "<<clave[i][j]<<endl;
        i++;
        if(i==3){
            j++;
            i=0;
        }
        //cout<<mCifrado<<endl;
    }
    cout<<endl;
    escribir(mCifrado,"mensaje_cifrado");
    cout<<"Texto cifrado : "<<lectura("mensaje_cifrado")<<endl;

}
void Escitala::descifrado(){
    for(int i = 0,j = 0; i<mensaje.length();i++){
        if(j>=mensaje.length()){
            j -= mensaje.length()-1;
        }
        //cout<<"j : "<<j<<endl;
        mDescifrado += mCifrado[j];
        j += 3;
    }
    escribir(mCifrado,"mensaje_descifrado");
    cout<< "Texto descifrado : "<<mDescifrado;
}
