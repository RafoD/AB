#include "RSAB.h"
#include<iostream>
#include<windows.h>
#include <conio.h>

using namespace std;
#define ESCAPE 27


void menu(){
    int bits;
    char opcion;
        cout<<"Cifrado RCA con Bloques"<<endl;
        cout<<"Ingrese el numero bits"<<endl;
        cin>>bits;
        RSAB receptor(bits);
        system("cls");
    while(opcion!=char(27)){
        cout<<"Cifrado RCA con Bloques"<<endl;
        cout<<"N = "<<receptor.getN()<<" "<<"E = "<<receptor.get_e()<<endl;
        cout<<"¿Que desea hacer?"<<endl;
        cout<<"1. Cifrar"<<endl;
        cout<<"2. Descifrar"<<endl;
        if(!kbhit()){
            opcion = getch();
            system("cls");
            if(opcion=='1'){
                string m;
                ZZ n,e;
                cout<<"Ingresar las claves publicas"<<endl;
                cout<<"N : "<<endl;
                cout<<"E : "<<endl;
                cin>>n;
                system("cls");
                cout<<"Ingresar las claves publicas"<<endl;
                cout<<"N : "<<n<<endl;
                cout<<"E : "<<endl;
                cin>>e;
                system("cls");
                cout<<"Ingresar las claves publicas"<<endl;
                cout<<"N : "<<n<<endl;
                cout<<"E : "<<e<<endl;
                system("cls");
                RSAB emisor(n,e);
                cout<<"Ingresar el texto plano"<<endl;
                cin>>m;
                emisor.cifrado(m);
                if(!kbhit()){
                    opcion= getch();
                    if(opcion==char(23)){
                        continue;
                    }
                }

                system("cls");
            }
            if(opcion=='2'){
                string r;
                cout<<"Ingresar el texto cifrado"<<endl;
                cin>>r;
                receptor.descifrado(r);
                if(!kbhit()){
                    opcion= getch();
                    if(opcion==char(23)){
                        continue;
                    }
                }
                system("cls");
            }
        }
    }

}

int main(){
    menu();

    return 0;
}
