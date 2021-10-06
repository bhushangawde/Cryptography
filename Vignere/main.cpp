#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void enc(string,string);
void decr(string,string);
int main()
{
    string s,k;
    int cas;
    cout<<"Enter 1 for encryption and 2 for decryption and 3 to exit"<<endl;
    cin>>cas;
    while(cas!=3){
        switch(cas){
            case 1: cout<<"Enter string to encrypt:"<<endl;
                    cin>>s;
                    cout<<"Enter key to encrypt:"<<endl;
                    cin>>k;
                    enc(s,k);
                    break;
            case 2: cout<<"Enter string to decrypt:"<<endl;
                    cin>>s;
                    cout<<"Enter key to encrypt:"<<endl;
                    cin>>k;
                    decr(s,k);
                    break;

            case 3: break;
            }
            cin>>cas;
    }
    return 0;
}

void enc(string s,string k){
    int plen = s.length();
    int klen = k.length();
    int i =0,j=0,tmp=0;
    string c ="";
    while(i<plen){
        tmp=(s[i]-97) +(k[j]-97);
        tmp = tmp%26;
        c=c+(char)(tmp+97);
        j++;
        if(j==klen){
            j=0;
        }
        i++;
    }
    cout<<"Encrypted text is : "<<c<<endl;
}

void decr(string s,string k){
    int plen = s.length();
    int klen = k.length();
    int i =0,j=0,tmp=0;
    string p ="";
    while(i<plen){
        tmp=(s[i]-97)-(k[j]-97);
        if(tmp<0){
            tmp = tmp +26;
        }
        else {
        tmp = tmp%26;
        }
        p=p+(char)(tmp+97);
        j++;
        if(j==klen){
            j=0;
        }
        i++;
    }
    cout<<"Decrypted text is : "<<p<<endl;
}
