#ifndef GAMAL_H
#define GAMAL_H
#include "mathfunc.h"

class gamal
{
    public:
        gamal(ZZ);
        gamal(vector<ZZ>);
        ZZ e1,e2,C1,C2,p;
        string alfabeto="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";
        string cifrado(string);
        string descifrado(string);
        vector<ZZ> fdeliver();
    private:
        ZZ d,r,Km;
        string fromBloques(string,int);
};

#endif // GAMAL_H
