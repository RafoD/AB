#include <iostream>
using namespace std;
#include "vigenere.h"
#include "escitala.h"
#include "afin.h"
int main()
{
    vigenere cifrado1;
    cifrado1.cifrado();
    cifrado1.descifrado();
    /*Escitala cifrado2;
    cifrado2.cifrado();
    cifrado2.descifrado();
    */
    /*
    int a=24;
    afin b;
    string tc = b.cifrado("123abc123abc");
    cout<<tc<<endl;
    afin c(a,b);
    cout<<c.descifrado(tc);
    */
}


