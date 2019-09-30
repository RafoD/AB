int moduloE(int,int);

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
		s1=moduloE(s1,b);
	return s1;
}

int moduloE(int a, int b)
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

int euclides(int a, int b)
{
  int x=a,y=b;
  int r;
  while(y>0)
  {
    r=moduloE(x,y);
    x=y;
    y=r;
  }
  return x;
}
