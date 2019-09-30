#include<iostream>
#include<string>
#include "funciones.h"
using namespace std;

class afin{
        //string m;
        string abc = "abcdefghijklmnopqrstuvwxyz0123456789 ";
        int a,b;
    public:
        afin();
        afin(int a,afin af);
        afin(int a,int b);
        string cifrado(string);
        string descifrado(string);
        int get_b(){return b;};
};

afin::afin(){
    cin>>a;
    cout<<endl;
    int tam=abc.size();
    while(euclides(a,tam)!=1){
        cout<<"Ingrese otra clave: "<<endl;
        cin>>a;}
    b=rand()%(tam+1);
    cout<<"Constante: "<<b<<endl;
}
afin::afin(int a, afin af){
    int t=abc.size();
    this->a=euclidianE(a,t);
    this->b=af.get_b();
}
string afin::cifrado(string m){
    string tc;
    int t=m.size();
    int t1=abc.size();
    int x=a;
    if(a>t1)
    {
        x=moduloE(a,t1);
    }
    for(int i=0; i<t; i++)
    {
        int n=abc.find(m[i]);
        int p=moduloE(x*n+b, t1);
        tc=tc+abc[p];
    }
    return tc;
}
string afin::descifrado(string tc){
    int t2=abc.size();
    int y=a;
    if(a>t2)
    {
        y=moduloE(a,t2);
    }
    int tam=tc.size();
    string td;
    for(int i=0; i<tam; i++)
    {
        int n=abc.find(tc[i]);
        //cout<<n<<endl<<endl;
        int pos=moduloE(y*(n-b), t2);
        td+=abc[pos];
    }
    return td;
}
afin::afin(int a, int b){
    int t=abc.size();
    this->a=euclidianE(a,t);
    this->b=b;
}


/*
afin b;
b cifrado(mensaje)
afin c(a,b)
c.descifrado(tc);
*/
