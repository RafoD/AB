#ifndef RSAB_H
#define RSAB_H
#include <NTL/ZZ.h>
#include <vector>
#include <string>
#include <fstream>
#include <time.h>
#include <stdlib.h>
using namespace std;
using namespace NTL;
//string leer(string name);
/*string leer(string name)
{
    string tex;
    ifstream file;
    file.open(name, ios::in);
    if(file.fail())
    {
        cout<<"Error"<<endl;
        exit(1);
    }

    while(!file.eof())
    {
        getline(file, tex);
        return tex;
    }
    file.close();
}*/
class RSAB
{
    public:
        RSAB(int);
        RSAB(ZZ,ZZ);
        string cifrado(string);
        vector<string> gen_blocks(string);
        string add_zero(string,int);
        string descifrado(string);
        ZZ getN(){return N;}
        ZZ get_e(){return e;}
    private:
        ZZ N,p,q,e,phi, d;
        string a="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz 0123456789,.:;=!";
        //string a=leer("ASCII");
};

#endif // RSAB_H
