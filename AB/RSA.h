#include<iostream>
#include <NTL/ZZ.h>
#include <string>
using namespace std;
using namespace NTL;

class rsa{
    public:
        rsa(int);
        string abc="abcdefghijklmnopqrstuvwxyz123456789 ";
        string cifrado(string);
        string descifrado(string);
        int e,N;
        rsa(int,int);
        rsa();
    private:
        int p,q,phi,d;
};
rsa::rsa(){
    p=557;
    q=709;
    N=p*q;//394913
    phi=(p-1)*(q-1);
    e=125201;
    d=InvMod(e,phi);
}
rsa::rsa(int e,int  N){
    this->e = e;
    this->N = N;
    this->d = inversoM(e,N);
}

string rsa::cifrado(string m){
    string mc;
    for(int i = 0;i<m.length();i++){
        int tmp = abc.find(m[i]);
        int c = expoM(tmp,e,N);
        mc+=abc.find(m[c]);
    }
    return mc;
}
string rsa::descifrado(string mc){
    string md;
    for(int i = 0;i<mc.length();i++){
        int tmp = abc.find(mc[i]);
        int c = expoM(tmp,d,N);
        md+=abc.find(mc[i]);
    }
    return md;

}
