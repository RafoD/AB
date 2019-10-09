#include<iostream>
#include<string>
using namespace std;

class enigma{
    private:
        string r1,r2,r3;
        int c1=0,c2=0,c3=0;
        abc = "abcdefghijklmnopqrstuvwxyz";
        r1 = "cdefghijklmnopqrstuvwxyzab";
        r2 = "defghijklmnopqrstuvwxyzabc";
        r3 = "efghijklmnopqrstuvwxyzabcd";
    public:
        enigma();
        string cifrado();
        string descifrado();
        string m;
};
void enigma::permutar(string abc){
    for(int i =0 ;i<abc.length();i++){
        string tmp = abc[i];
        abc[i]=abc[i+1];
        abc[i+1]=tmp;
        i++;

    }

}
enigma::enigma(){
    cin>>m;
}
string enigma::cifrado(){
    string tc;
    for(int i=0;i<m.length();i++){
        string letra = a.substr(i,1);
        c1++;

        if(c1>=r1.length()){
            c1=0;
            c2++;
        }
        if(c2>=r2.length()){
           c2=0;
           c3++;
        }
        if(c3>=r3.length()){
            c3=0;
        }
        int r1 = abc.find(r1.find(letra));
        int r2 = abc.find(r2.find(letra));
        int r3 = abc.find(r3.find(letra));
        tc+=letra+r1+r2+r3;
    }

}
