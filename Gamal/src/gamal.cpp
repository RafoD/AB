#include "gamal.h"
gamal::gamal(ZZ p)
{
    this->p=p;
    e1=gen(p);
    RandomBnd(d,p-ZZ(1));
    while(d<2)
        RandomBnd(d,p-ZZ(1));
    e2=expoMB(e1,d,p);
}

vector<ZZ> gamal::fdeliver(){
    vector<ZZ> res;
    res.push_back(e1);
    res.push_back(e2);
    res.push_back(p);
    return res;
}

gamal::gamal(vector<ZZ> Kpub)
{
    p=Kpub[2];
    r =1;
    RandomBnd(r,p-(ZZ)1);
    cout<<r<<endl;

    while(r<2)
        RandomBnd(r,p-ZZ(1));

    C1=expoM(Kpub[0],r,p);
    Km=expoM(Kpub[1],r,p);
}

string gamal::fromBloques(string msn, int sizAlf)
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

string gamal::cifrado(string msn){
    string cypher;
    string tamp=zzToString(p);
    int Ndig=tamp.size();
    cypher+=formatZZ(C1,Ndig);
    for(int i=0;i<msn.size();i++){
        ZZ pos=ZZ(alfabeto.find(msn[i]));
        C2=Modulo(pos*Km,p);
        cypher+=formatZZ(C2,Ndig);
    }
    return cypher;
}

string gamal::descifrado(string msn){
    string res;
    string decypher;
    string tamp=zzToString(p);
    int Ndig=tamp.size();
    int NdigA=to_string(alfabeto.size()).size();
    C1=Stringtozz(msn.substr(0,Ndig));
    Km=expoMB(C1,d,p);
    ZZ Kmi=inversoM(Km,p);
    ZZ opera;
    int tam=msn.size()/Ndig;
    for(int i=1;i<tam;i++){
        opera=Stringtozz(msn.substr(i*Ndig,Ndig));
        opera=Modulo(opera*Kmi,p);
        res+=formatZZ(opera,NdigA);
    }
    decypher=fromBloques(res,alfabeto.size());
    return decypher;
}
