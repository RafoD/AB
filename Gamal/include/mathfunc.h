#pragma once
#ifndef FMATH_H
#define FMATH_H
#include <NTL/ZZ.h>
#include <vector>
#include <sstream>
#include <string>
#include <time.h>

using namespace NTL;
using namespace std;

inline ZZ Modulo(ZZ a,ZZ n){
    ZZ res=a-n*(a/n);
    if(res<0)
        res+=n;
    return res;
}

inline int Modulo(int a,int n){
    int res=a-n*(a/n);
    if(res<0)
        res+=n;
    return res;
}

inline ZZ mcd(ZZ a, ZZ n){
    ZZ b=a;
    ZZ c=n;
    ZZ res= Modulo(b,c);
    while(res!=0){
        b=c;
        c=res;
        res=Modulo(b,c);
    }
    return c;
}

inline ZZ euclext(ZZ a, ZZ b){
    ZZ d,x,y,q,r;
    ZZ x2=ZZ(1);
    ZZ x1=ZZ(0);
    ZZ y2=ZZ(0);
    ZZ y1=ZZ(1);
    if(b==0){
        d=a;
        x=ZZ(1);
        y=ZZ(1);
    }
    while(b>0){
        q=a/b;
        r=a-q*b;
        x=x2-q*x1;
        y=y2-q*y1;
        a=b;
        b=r;
        x2=x1;
        x1=x;
        y2=y1;
        y1=y;
    }
    d=a;
    x=x2;
    y=y2;
    return x;
}

inline ZZ inversoM(ZZ a,ZZ b){
    ZZ c=euclext(a,b);
    while(c<ZZ(0)){
        c+=b;
    }
    return c;
}

inline ZZ expoM(ZZ a,ZZ e,ZZ N){
    ZZ exp=ZZ(1);
    ZZ x=Modulo(a,N);
    while(e>ZZ(0)){
        if(Modulo(e,ZZ(2))==ZZ(1))
            exp=Modulo(exp*x,N);
        x=Modulo(x*x,N);
        e=e/ZZ(2);
    }
    return exp;
}

inline ZZ expoMB(ZZ a,ZZ e,ZZ N){
    int k=NumBits(e);
    ZZ c;
    if(bit(e,k-1)==1)
        c=a;
    else
        c=ZZ(1);
    for(int i=k-2;i>=0;i--){
        c=Modulo(c*c,N);
        if(bit(e,i)==1)
            c=Modulo(c*a,N);
    }
    return c;
}

inline ZZ expoMBS(ZZ a,vector<int> e,ZZ N, int k){
    ZZ c;
    if(e[k-1]==1)
        c=a;
    else
        c=ZZ(1);
    for(int i=k-2;i>=0;i--){
        c=Modulo(c*c,N);
        if(e[i]==1)
            c=Modulo(c*a,N);
    }
    return c;
}

inline ZZ resch(vector<ZZ> a, vector<ZZ> p){
    ZZ qInv=euclext(p[1],p[0]);
    ZZ tam=to_ZZ(a.size());
    for(int i=0;i<tam;i++){
        a[i]=Modulo(a[i],p[i]);
    }
    ZZ h=Modulo(qInv*Modulo(a[0]-a[1],p[0]),p[0]);
    ZZ m=a[1]+h*p[1];
    return m;
}

inline string zzToString(const ZZ x)
{
    stringstream buffer;
    buffer << x;
    return buffer.str();
}

inline ZZ Stringtozz(string x)
{
    stringstream buffer(x);
    ZZ y;
    buffer >> y;
    return y;
}

inline ZZ phi (ZZ n)
{
   ZZ result = n;
   ZZ i;
   for (i=2; i*i<=n; ++i)
      if (Modulo(n,i) == 0){
        while (Modulo(n,i) == 0)
           n /= i;
       result -= result / i;
    }
    if (n > 1)
        result -= result / n;
    return result;
}

//template <typename T>
inline vector<ZZ> factors(ZZ num) {    // works great for small prime factors
    vector<ZZ> v;
    if (num < 4) { v.push_back(num); return v; }
    while ((num & 1) == 0) { v.push_back(ZZ(2)); num >>= 1; }   // remove all factors of 2
    ZZ d {3};
    while (num >= d * d) {
        while (num % d == 0) {  // remove all repeats of this divisor
            v.push_back(d);
            num /= d;
        }
        d += 2;
        if (d * d > num && num > 1) { v.push_back(num); return v; }
    }
    return v;
}

//p=2q+1
/*inline ZZ gen(ZZ p){
    ZZ q=(p-ZZ(1))/ZZ(2);
    bool found=0;
    vector<ZZ> Zp;
    for(int i=2;i<p-1;i++){
        if(mcd(ZZ(i),p)==1)
            Zp.push_back(ZZ(i));
    }
    int i=0;
    ZZ g;
    while(found!=1){
        g=Zp[i];
        if(expoMB(g,ZZ(2),p)!=ZZ(1) && expoMB(g,q,p)!=ZZ(1))
            found=1;
        i++;
    }
    return g;
}*/

//Z siempre es primo
/*inline ZZ gen(ZZ Z){
    ZZ M=phi(Z);
    vector<ZZ> p=factors(M);
    vector<ZZ> m;
    vector<ZZ> ge;
    for(int i=0;i<p.size();i++){
        ZZ res=M/p[i];
        m.push_back(res);
    }

    for(ZZ i=ZZ(1);i<Z;i++){
        bool valid=true;
        for(int j=0;j<m.size();j++){
            if(expoMB(i,m[j],Z)==ZZ(1)){
                valid=false;
                break;
            }
        }
        if(valid==true)
            ge.push_back(i);
    }
    return ge[ge.size()-1];
}*/

/*inline ZZ gen(ZZ Z){
    ZZ M=phi(Z);
    vector<ZZ> p=factors(M);
    vector<ZZ> m;
    vector<ZZ> ge;
    for(int i=0;i<p.size();i++){
        ZZ res=M/p[i];
        m.push_back(res);
    }

    for(ZZ i=ZZ(1);i<Z;i++){
        bool valid=true;
        for(int j=0;j<m.size();j++){
            if(expoMB(i,m[j],Z)==ZZ(1)){
                valid=false;
                break;
            }
        }
        if(valid==true)
            ge.push_back(i);
    }
    return ge[ge.size()-1];
}*/

/*inline ZZ gen(ZZ p){
    ZZ q, g;
    q = (p - 1)/2;
    for(int i = 0; i < p-1; i++){
        g = (p-1) - i;
        if((expoMB(g, to_ZZ(2), p) != 1) && (expoMB(g, q, p) != 1))
            return q;
    }
    return g;
}*/

inline ZZ gen(ZZ p){
    ZZ q=(p-1)/2;
    ZZ e(ZZ(2));
    for(ZZ i=ZZ(2);i<p;i++){
        if(expoMB(i,e,p)!=ZZ(1)&&expoMB(i,q,p)!=ZZ(1))
        return i;
    }
}


inline string formatZZ(ZZ num, int dig){
    string res;
    res += zzToString(num);
    int difeSize = dig - res.length();

    while (difeSize > 0) {
        res = '0' + res;
        difeSize--;
    }
    return res;
}



#endif
