int ModuloE(int a, int b)
{
  int q=a/b;
  int r=a-q*b;
  if(r<0)
  {
    int q=(a/b)-1;
    r=a-q*b;
  }
  return r;
}

int euclidianE(int a, int b)
{
	int r1=a, r2=b, s1=1, s2=0, t1=0, t2=1;
	int q,r,s,t;
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
		s1=ModuloE(s1,b);
	return s1;
}

int euclides(int a, int b)
{
  int x=a,y=b;
  int r;
  while(y>0)
  {
    r=ModuloE(x,y);
    x=y;
    y=r;
  }
  return x;
}


ZZ mod(ZZ a,ZZ b){
    if((a==0)){
        return ZZ(0);
    }
    ZZ tmp=a/b;
    ZZ r=a-(tmp*b);
    while(r<0){
        r+=b;
    }
    return r;
}

int mod(int a,int b){
    if((a==0)){
        return 07;
    }
    int tmp=a/b;
    int r=a-(tmp*b);
    while(r<0){
        r+=b;
    }
    return r;
}

ZZ mcd(ZZ a, ZZ b){
    ZZ r=mod(a,b);
    ZZ d=b;
    while(r>ZZ(0)){
        ZZ c=d;
        d=r;
        r=mod(c,d);
    }
    return d;
}
ZZ euclideanE(ZZ a, ZZ b){
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

int inversoM(int a,int b){
    int c=euclidianE(a,b);
    while(c<int(0)){
        c+=b;
    }
    return c;
}
 int expoM(int a,int e,int N){
    int exp=int(1);
    int x=mod(a,N);
    while(e>int(0)){
        if(mod(e,int(2))==int(1))
            exp=mod(exp*x,N);
        x=mod(x*x,N);
        e=e/int(2);
    }
    return exp;
}
/*
numberToString(ZZ num)
{
    int len = ceil(log(num)/log(128));
    char str[len];
    for(int i = len-1; i >= 0; i--)
    {
        str[i] = conv<int>(num % 128);
        num /= 128;
    }

    return (string)str;
}

stringToNumber(string str){
    ZZ number = conv<ZZ>(str[0]);
    int len = str.length();
    for(int i = 1; i < len; i++)
    {
        number *= 128;
        number += conv<ZZ>(str[i]);
    }

    return number;
}
*/int stoint(string str){
    string::size_type sz; //alias de size_T
    int tmp = stoi(str,&sz);
    return tmp;
}
