#include <iostream>
using namespace std;

//ALGORITMO 1
unsigned long long alg_1(unsigned long long a,unsigned long long b){
    //PASO 1: LEER A Y B
    cin>>a;cout<<" ";cin>>b;
    //PASO 2: R = RESTO DE DIVIDIR A ENTRE B
    unsigned long long r = a % b;
    //PASO 3: SI R= 0 ENTONCES LA FUNCION(A,B) = B -> FIN
    if(r == 0){
        return b;
    }
    //PASO 4: SI NO A = B, B = R;
    else{
        a = b;
        b = r;
    }
    //PASO 5. IR AL PASO 2
}
int main(){
return 0;
}
