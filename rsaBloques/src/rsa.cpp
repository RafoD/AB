#include "rsa.h"

RSABloques::RSABloques(ZZ eex, ZZ Nex)
{
    e = eex;
    N = Nex;
}

//Constructor receptor (Genera claves)
RSABloques::RSABloques(int bits)
{
    //Genera primos p y q de 512 bits
    GenPrime(p, bits);
    GenPrime(q, bits);

    //Valor de N de 1024 bits
    N = p * q;

    //Se halla el Totiente
    Phi = (p - 1) * (q - 1);

    //Genera 1 < e < Phi
    RandomBnd(e, Phi);

    while (GCD(e, Phi) != 1 || e == 1)
        RandomBnd(e, Phi);

    //Inversa de e
    d = euclext(e, Phi);
    d = Modulo(d, Phi);

    dp=Modulo(d,p-1);
    dq=Modulo(d,q-1);

}

string zzToString(const ZZ& x)
{
    stringstream buffer;
    buffer << x;
    return buffer.str();
}

string RSABloques::toBloques(string msn, int sizAlf, int sizN)
{
    string res, digAct;
    string fill = to_string(sizAlf);
    int digsizAlf =to_string(sizAlf).length();
    int k = sizN - 1;

    //string de numeros posicion
    for (int i = 0; i < msn.length(); i++) {
        digAct = msn[i];
        //Format posicion, then add to res
        res += formatInt(alfabeto.find(digAct), digsizAlf);
    }

    int ite = Modulo(res.length(), k);
    //No hace falta relleno
    if (ite == 0)
        return res;

    //Relleno con sizAlf
    ite = k - ite;
    int i = 0;
    while (i < ite) {
        res += fill[Modulo(i, fill.length())];
        i++;
    }
    return res;
}

string RSABloques::fromBloques(string msn, int sizAlf)
{
    string res, digAct;
    int digsizAlf = to_string(sizAlf).length();
    int pos;

    int ite = msn.length() / digsizAlf;
    for (int i = 0; i < ite; i++) {
        pos = stoi(msn.substr(i * digsizAlf, digsizAlf));
        res += alfabeto[pos];
    }
    return res;
}

string RSABloques::formatInt(int num, int dig)
{
    string res;
    res = to_string(num);

    //5 dig - 1size = 4 ceros a la izq
    int difeSize = dig - res.length();

    while (difeSize > 0) {
        res = '0' + res;
        difeSize--;
    }
    return res;
}

string RSABloques::formatZZ(ZZ num, int dig)
{
    string res;
    res += zzToString(num);
    //5 dig - 1size = 4 ceros a la izq
    int difeSize = dig - res.length();

    while (difeSize > 0) {
        res = '0' + res;
        difeSize--;
    }
    return res;
}

string RSABloques::cifrar(string msnsaje)
{
    string res;
    string resTemp;

    int Ndig = zzToString(N).length();
    int k = Ndig - 1;

    //Convert msnsaje a numeros para bloque
    resTemp = toBloques(msnsaje, alfabeto.length(), Ndig);

    ZZ opera;
    int nBloques = resTemp.length() / k;

    for (int i = 0; i < nBloques; i++) {
        opera = stoi(resTemp.substr(i * k, k));
        opera = expoM(opera, e, N);
        res += formatZZ(opera, Ndig);
    }
    return res;
}

string RSABloques::descifrar(string msncifrado)
{
    string res;
    string resTemp;

    int Ndig = zzToString(N).length();
    int k = Ndig - 1;

    ZZ opera;
    int nBloques = msncifrado.length() / Ndig;

    for (int i = 0; i < nBloques; i++) {
        opera = stoi(msncifrado.substr(i * Ndig, Ndig));
        ap=expoM(opera,dp,p);
        aq=expoM(opera,dq,q);
        vector<ZZ>a={ap,aq};
        vector<ZZ>P={p,q};
        opera= resch(a,P,ZZ(0));
        resTemp += formatZZ(opera, k);
    }

    //Convert a mensaje
    res += fromBloques(resTemp, alfabeto.length());

    return res;
}
