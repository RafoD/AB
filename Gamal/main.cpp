#include <iostream>
#include "gamal.h"

using namespace std;

int main()
{/*
    ZZ p;
    GenPrime(p,32);
    gamal receptor(p);
    vector<ZZ> entrega=receptor.fdeliver();
    gamal emisor(entrega);
    string msn="HOLA COMO ESTAS";
    string cifrado=emisor.cifrado(msn);
    string descifrado=receptor.descifrado(cifrado);

    cout<<"e1  : "<<receptor.e1<<endl;
    cout<<endl;
    cout<<"e2  : "<<receptor.e2<<endl;
    cout<<endl;

    cout<<"c1  : "<<emisor.C1<<endl;
        cout<<endl;

    cout<<"c2  : "<<emisor.C2<<endl;
        cout<<endl;

    cout<<"p  : "<<emisor.p<<endl;
        cout<<endl;

    //cout<<cifrado<<endl;
    cout<<endl;
    cout<<endl;
    cout<<descifrado<<endl;
    */
    vector<ZZ> entrega = {(ZZ)2,(ZZ)346453336,(ZZ)4234179589};
    cout<<"aqui"<<endl;
    gamal prueba(entrega);
    cout<<"aqui"<<endl;
    string descifrado = prueba.descifrado("000000000100714110020222222222");
    cout<<"MENSAJE -> "<<descifrado;
    return 0;
}
