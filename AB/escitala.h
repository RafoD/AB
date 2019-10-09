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
     int filas = 3;
     int columnas;
     string mCifrado;
     string mDescifrado;
     Escitala();
     string clave[][5];
     void cifrado();
     void descifrado();
     int stoint(string);
     void generarClave();
};
void escribir(string mensaje,string narchivo){
    ofstream archivo;
    archivo.open("txt//" + narchivo + ".txt",ios::out);//lo abre;
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
    archivo.open("txt//" + narchivo + ".txt",ios::in);
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
    for(int i= 0; i<filas and x<mensaje.length()-1;i++){
        for(int j = 0;j<columnas;j++){
            clave[i][j] = " ";
        }
    }
    for(int i= 0; i<filas and x<mensaje.length()-1;i++){
        for(int j = 0;j<columnas;j++){
            //cout<<x<<" "<<mensaje[x]<<endl;
            clave[i][j] = mensaje[x];
            x++;
        }
    }
    for(int i= 0; i<filas;i++){
        for(int j = 0;j<columnas;j++){
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
    columnas = mensaje.length()/filas;
    //string clave[3][];
    generarClave();
    for(int i = 0,j=0; j<columnas;){
        mCifrado+=clave[i][j];
        //cout<<"clave["<<i<<"]["<<j<<"] -> "<<clave[i][j]<<endl;
        i++;
        if(i==filas){
            j++;
            i=0;
        }
        //cout<<mCifrado<<endl;
    }
    cout<<endl;
    escribir(mCifrado,"mensaje_cifrado");
    //cout<<"Texto cifrado : "<<lectura("mensaje_cifrado")<<endl;

}
void Escitala::descifrado(){
    for(int i = 0,j = 0; i<mensaje.length();i++){
        if(j>=columnas*filas){
            j -= columnas*filas-1;
        }
        //cout<<"j : "<<mCifrado[j]<<" "<<j<<endl;
        mDescifrado += mCifrado[j];
        j += filas;
    }
    escribir(mDescifrado,"mensaje_descifrado");
    cout<< "Texto descifrado : "<<mDescifrado;
}
