#include <iostream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <time.h>
using namespace std;

class vigenere
{
    public:
    vigenere();
    void cifrado();//pide el mensaje
    void descifrado();
    private:
        string abc = "abcdefghijklmnopqrstuvwxyz0123456789 ";
        string mensaje;
        string pos;
        string clave;
        string mCifrado;
        string mDescifrado;

        int mCifradoInt[100000];

        void generaClave();//genera la clave
        void aleatorios();//genera los aleatorios
        int stoint(string);//convierte string en int,
                           //sirve para generar la clave
        int mayorabc(int);
        friend int menorabc(int,int,int);
};
int vigenere::mayorabc(int num){
    if(num>abc.length()-1){
        return num-abc.length();
    }
    else{
        return num;
    }
}
int menorabc(int cifrado, int clave, int abc){
    if(cifrado<clave){
        return abc + (clave - cifrado)*(-1);
    }
    if(cifrado == clave){
        return 0;
    }
    return cifrado - clave;
}

int vigenere::stoint(string str){
    string::size_type sz; //alias de size_T
    int tmp = stoi(str,&sz);
    return tmp;
}

void vigenere::aleatorios(){
    srand(time(NULL));
    for (int c = 0; c < mensaje.length(); c++)
    {
        int num = rand() % (abc.length()-1);
        pos += to_string(num)+ " ";
        //cout<<num<<endl;
    }
}

void vigenere::cifrado(){
    cout << "Ingrese el mensaje que desea cifrar: ";
    getline(cin,mensaje);
    generaClave();
    for(int i = 0; i<mensaje.length();i++){
        mCifrado+=abc[mayorabc(abc.find(clave[i])+abc.find(mensaje[i]))];
        mCifradoInt[i] = abc.find(mCifrado[i]);
    }
    //cout<<"pos = "<<pos<<endl;
    cout<<"Mensaje Cifrado = "<<mCifrado<<endl;
    for(int i = 0; i<mensaje.length();i++){
        //cout<<mCifradoInt[i]<<" = "<<abc.find(clave[i])<<" + "<<abc.find(mensaje[i])<<endl;
    }
    cout<<endl;
}

void vigenere::descifrado(){
    for(int i= 0;i<mensaje.length();i++){
        mDescifrado+=abc[menorabc(abc.find(mCifrado[i]),abc.find(clave[i]),abc.length())];
        //cout<<mDescifrado<<" ";
        //cout<<abc.find(mCifrado[i])<<endl;
        //cout<<mCifradoInt[i]-abc.find(clave[i])<<" ";
    }
    cout<<"Mensaje Descifrado = "<<mDescifrado<<endl;
    for(int i = 0; i<mensaje.length();i++){

        //cout<<abc.find(mCifrado[i])-abc.find(clave[i])<<" = "<<abc.find(mCifrado[i])<<" - "<<abc.find(clave[i])<<endl;
        //cout<<menorabc(abc.find(mCifrado[i]),abc.find(clave[i]),abc.length())<<" = "<<abc.find(mCifrado[i])<<" - "<<abc.find(clave[i])<<endl;

    }
}
void vigenere::generaClave(){
    aleatorios();
    //cout<<pos<<endl;
    for(int i = 0,j = 0; i < pos.length()+1; i++){
        if(pos[i] == ' '){
            string temp = pos.substr(j,i-j);
            i++;
            j=i;
            //cout<<stoint(temp)+1<<" "<<endl;
            clave+=abc[stoint(temp)];
            //cout<<"clave -> "<< clave<<" "<<endl;
        }
    }
}
vigenere::vigenere(){
}
