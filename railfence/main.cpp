#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void enc(string);
void decr(string);
int main()
{
    string s;
    int cas;
    cout<<"Enter 1 for encryption and 2 for decryption and 3 to exit"<<endl;
    cin>>cas;
    while(cas!=3){
        switch(cas){
            case 1: cout<<"Enter string to encrypt:"<<endl;
                    cin>>s;
                    enc(s);
                    break;
            case 2: cout<<"Enter string to decrypt:"<<endl;
                    cin>>s;
                    decr(s);
                    break;

            case 3: break;
            }
            cin>>cas;
    }
    return 0;
}

void enc(string s){
    char u[20],d[20];
    int j=0,k=0;
    int l = s.length();
    for(int i=0;i<l;i++){
        if(i%2==0){
            u[j++]=s[i];
        }
        else if(i%2!=0){
            d[k++]=s[i];
        }
    }
    u[j]='\0';
    d[k]='\0';
    cout<<u<<d<<endl;
}
//enemyattackstonight
//eeytaktngtnmatcsoih

void decr(string s){
    int l = s.length();
    int k,j;
    if(l%2==0){
        k=l/2;
    }
    else {
        k=l/2+1;
    }
    j=k;
    for(int i = 0; i<k,j<=l;i++,j++){
        cout<<s[i]<<s[j];
    }
    cout<<endl;
}
