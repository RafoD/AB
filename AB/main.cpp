#include <iostream>
#include <NTL/ZZ.h>
using namespace std;
using namespace NTL;
#include "vigenere.h"
#include "escitala.h"
#include "afin.h"
#include "RSA.h"
int main()
{//vigenere
/*
    vigenere cifrado1;
    cifrado1.cifrado();
    cifrado1.descifrado();

    //escitala
    Escitala cifrado2;
    cifrado2.cifrado();
    cifrado2.descifrado();
    */

    //afin
    int a=24;
    afin b;
    string tc = b.cifrado("123abc123abc");
    cout<<tc<<endl;
    afin c(a,b);
    cout<<c.descifrado(tc);
   /*
   //RSA
   /*
   string mensaje = "holacomoestas";
   string mc,md;
   rsa receptor;
   rsa emisor(125201,394913);
   mc = emisor.cifrado(mensaje);
   cout<<mc<<endl;
   md = receptor.cifrado(mc);
   cout<<endl;*/

    return 0;
}


