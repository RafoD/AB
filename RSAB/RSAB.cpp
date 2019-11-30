#include "RSAB.h"
#include <NTL/ZZ.h>
#include <sstream>
#include <vector>
using namespace NTL;
using namespace std;
string zToString(const ZZ&);
ZZ convert(string);
ZZ eucliEX(ZZ,ZZ);
string add_zero(string msj, int n_zeros);
ZZ exp(ZZ m, ZZ e, const ZZ n);
string zeros(string,int);
int to_int(string);
ZZ moduloE(ZZ a, ZZ b);
string zb(string msj, int n);
ZZ CRT (vector<ZZ>,vector<ZZ>);
RSAB::RSAB(int num)
{
    p=GenPrime_ZZ(num);
    q=GenPrime_ZZ(num);
    N=p*q;
    phi=(p-1)*(q-1);
    e=GenPrime_ZZ(num);
    while(GCD(e,phi)!=1)
    {
        e=GenPrime_ZZ(num);
    }
    d=eucliEX(e,phi);
    cout<<"E: "<<e<<endl;
    cout<<"N: "<<N<<endl;
    cout<<"D: "<<d<<endl;
}
RSAB::RSAB(ZZ n, ZZ c)
{
    N=n;
    e=c;
}
string RSAB::cifrado(string msj)
{
    ZZ n1;
    n1=3;
    int n2=zToString(n1).size();
    msj=add_zero(msj,n2);
    //cout<<"Mensaje: "<<msj<<endl;
    //cout<<"N: "<<N<<endl;
    //cout<<"e: "<<e<<endl;
    vector<string> blocks=gen_blocks(msj);
    int len=blocks.size();
    vector<string> BC;
    string ans;
    int dig=zToString(N).size();
    for(int i=0; i<len; i++)
    {
        ZZ bc;
        ZZ tmp=convert(blocks[i]);
        //cout<<"Bloque: "<<tmp<<endl;
        bc=exp(tmp,e,N);
        //cout<<"Exponeciacion: "<<bc<<endl;
        string aux;
        aux=zToString(bc);
        //cout<<"Bloque cifrado: "<<bc<<endl;
        ans=ans+zeros(aux,dig);
    }
    cout<<"cifrado: "<<ans<<endl;
    //cout<<"Cifrado terminado"<<endl;
    return ans;
}

string RSAB::descifrado(string bc)
{
    cout<<"Descifrado iniciado: "<<endl;
    int len=bc.size();
    string ans;
    int tam=zToString(N).size();
    ZZ dp=moduloE(d,p-1); //Rest chino
    ZZ dq=moduloE(d,q-1); //Resto Chino
    vector<ZZ> m={p,q};
    for(int i=0; i<len; i=i+tam)
    {
        ZZ bd;
        bd=convert(bc.substr(i,tam));
        //cout<<"Bloque: "<<bd<<endl;
        ZZ aux1(0), aux2(0);
        aux1=exp(bd,dp,p); aux2=exp(bd,dq,q);
        vector<ZZ> a={aux1, aux2};
        ZZ aux;
        aux=CRT(a,m);
        //cout<<"Resto chino: "<<aux<<endl;
        //aux=exp(bd,d,N);
        ans=ans+zb(zToString(aux), 3);
        //ans=ans+a[conv<int>(aux)];
    }
    int l=ans.size();
    string answer;
    string aux;
    for(int i=0; i< l; i=i+3)
    {
        //answer=answer+a[stoi(ans.substr(i,3))];
        aux=char(stoi(ans.substr(i,3)));
        //cout<<"Letra descifarda: "<<aux<<endl;
        answer=answer+aux;
        aux.clear();
    }
    cout<<ans<<endl;
    int t=ans.size();
    //cout<<"Bloque descifrado: "<<ans<<endl;
    string md;
    cout<<"Mensaje armado: "<<answer<<endl;
    return answer;
}

string zToString(const ZZ &z){
    stringstream buffer;
    buffer << z;
    return buffer.str();
}

string RSAB::add_zero(string msj, int n)
{
    //cout<<"Mensaje entrante: "<<msj<<endl;
    int len=msj.size();
    //cout<<"Tamanio: "<<len<<endl;
    string answer;
    string aux;
    string l;
    int cont=0;
    for(int i=0; i< len; i++)
    {
        int tmp=int(char(msj[i]));
        //cout<<"Numero: "<<tmp<<endl;
        if(to_string(tmp).size()==1)
        {
            aux="00";
            aux=aux+to_string(tmp);
        }
        else if(to_string(tmp).size()==2)
        {
            aux="0";
            aux=aux+to_string(tmp);
        }
        else{
            aux=aux+to_string(tmp);
        }
        answer=answer+aux;
        aux.clear();
    }
    /*for(int i=0; i<len; i++)
    {
        int tmp=a.find(msj[i]);
        if(to_string(tmp).size()<n)
        {
            tmp=tmp+10;
            answer=answer+to_string(tmp);
        }
        else
        {
            tmp=tmp+10;
            answer=answer+to_string(tmp);
        }
    }*/
    //cout<<"Ceros: "<<answer<<endl;
    return answer;
}

string zeros(string m, int n)
{
    string aux;
    aux="0";
    string ans;
    int len=m.size();
    while(len<n)
    {
        aux=aux+m;
        m=aux;
        aux="0";
        len=m.size();
    }
    return m;
}
string zb(string msj, int n)
{
    string z;
    z="0";
    while(msj.size()%n!=0)
    {
        z=z+msj;
        msj=z;
        z="0";
    }
    return msj;
}

vector<string> RSAB::gen_blocks(string msje)
{
    vector<string> blocks;
    string block;
    int len1=zToString(N).size();
    int len2=msje.size();
    int cont=0;
    while(cont<len2)
    {
        if((block+msje.substr(cont,3)).size()<=len1 and convert(block+msje[cont])<N)
        {
            block=block+msje.substr(cont,3);
            cont=cont+3;
        }
        else{
            blocks.push_back(block);
            block.clear();
        }
    }
    if(block.size())
    {
        blocks.push_back(block);
    }
    int a=blocks.size();
    /*for(int i=0; i<a; i++)
    {
        cout<<"Arreglo de bloques: "<<blocks[i]<<endl;
    }*/
    return blocks;
}

ZZ convert(string s)
{
    int tam=s.size();
    ZZ res;
    res=0;
    for(int i=0; i<tam; i++)
    {
        res=res*10+(s[i]-'0');
    }
    return res;
}int to_int(string a)
{
    int tam=a.size();
    int res;
    res=0;
    for(int i=0; i<tam; i++)
    {
        res=res*10+(a[i]-'0');
    }
    return res;
}
ZZ exp(ZZ m, ZZ e, const ZZ n)
{
    ZZ c=e;
    ZZ m2;
    ZZ result(1);
    ZZ bag=m;
    ZZ bag2(1);
    while(c>0)
    {
        m2=e%2;
        bag=(bag*bag2)%n;
        if(m2==1)
        {
            result=(bag*result)%n;
        }
        c=c/2;
        e=c;
        bag2=bag;
    }
    return result;
}
/*ZZ exp(ZZ m, ZZ e, const ZZ n)
{
    int k =NumBits(e);
    ZZ c;
    if(bit(e,k-1)==1)
        c=m;
    else
        c=ZZ(1);
    for(int i=k-2; i>=0; i--){
        c=moduloE(c*c,n);
        if(bit(e,i)==1)
            c=moduloE(c*m,n);
    }
    return c;
}*/
ZZ eucliEX(ZZ a,ZZ b)
{
    ZZ r1=a;
    ZZ r2=b;
    ZZ s1(1),s2(0),t1(0),t2(1),q,r,s,t;
    while(r2>0)
    {
        q=r1/r2;
        r=r1-q*r2;
        r1=r2;
        r2=r;
        s=s1-q*s2;
        s1=s2;
        s2=s;
        t=t1-q*t2;
        t1=t2;
        t2=t;
    }
    if(s1<0)
        s1=moduloE(s1,b);
    return s1;
}
ZZ moduloE(ZZ a, ZZ b)
{
  ZZ q(a/b);
  ZZ r(a-q*b);
  if(r<0)
  {
    ZZ q((a/b)-1);
    r=a-q*b;
  }
  return r;
}
ZZ CRT(vector<ZZ> a, vector<ZZ> p)
{
    ZZ q_inv=exp(p[1],p[0]-2, p[0]);
    int tam=a.size();
    for(int i=0; i<tam; i++)
    {
        a[i]=moduloE(a[i], p[i]);
    }
    ZZ h=moduloE(q_inv*moduloE(a[0]-a[1], p[0]),p[0]);
    ZZ m=a[1]+h*p[1];
    return m;
}
