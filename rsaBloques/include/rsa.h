#ifndef RSA_H
#define RSA_H
#include "mathfunc.h"
#include <NTL/ZZ.h>
#include <sstream>
#include <string>

using namespace std;

using namespace NTL;

class RSABloques {
private:
    const string alfabeto = "abcdefghijklmnopqrstuvwxyz0123456789 ";
    ZZ Phi,d, dp, dq, ap, aq,p, q;
    string toBloques(string msn, int sizAlf, int sizN);
    string fromBloques(string msn, int sizAlf);
    string formatInt(int num, int dig);
    string formatZZ(ZZ num, int dig);

public:
    ZZ e, N;
    string cifrar(string mensaje);
    string descifrar(string cipher);
    RSABloques(int);
    RSABloques(ZZ, ZZ);
};

#endif // RSABLOQUES_H
