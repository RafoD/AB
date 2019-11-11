#include "rsa.h"
#include <NTL/ZZ.h>
#include <iostream>
#include <string>
#include <vector>
#include "mathfunc.h"


using namespace std;
using namespace NTL;

int main(){
    //claves random
    RSABloques receptor(1024);

    // Claves de receptor
    RSABloques emisor(receptor.e, receptor.N);

    //Claves para claveCustom
    //    RSABloques emisor(ZZ(7313), ZZ(35621));
    //    RSABloques emisor(ZZ(193), ZZ(35909));
    //    RSA prob(ZZ(34855), ZZ(813473));

    string cifrado, descifrado;
    string h = "Hola como estas";
    //    std::string h = "HOLACOMOESTAS";

    cifrado = emisor.cifrar(h);
    cout << cifrado <<endl;/*

    descifrado = receptor.descifrar(cifrado);
    cout << descifrado <<endl;

    //SOLO DECIFRAR
    //    RSABloques claveCUSTOM;
    //    claveCUSTOM.e = to_ZZ("7313");
    //    claveCUSTOM.d = to_ZZ("15581");
    //    claveCUSTOM.N = to_ZZ("35621");

    //    cout << claveCUSTOM.descifrar(cifrado) <<endl;*/
    return 0;
}
