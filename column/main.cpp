#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void enc(string);
void decr(string);
int key[5]={3,1,4,5,2};
int revkey[5]={2,5,1,3,4};
//Default blocksize is 5
int main()
{
    string s;
    int num;
    int cas;
    cout<<"Enter 1 for encryption and 2 for decryption and 3 to exit"<<endl;
    cin>>cas;
    while(cas!=3){
        switch(cas){
            case 1: cout<<"Enter string to encrypt:"<<endl;
                    cin>>s;
                    cout<<endl;
                    enc(s);
                    break;
            case 2: cout<<"Enter string to decrypt:"<<endl;
                    cin>>s;
                    cout<<endl;
                    decr(s);
                    break;

            case 3: break;
            }
            cin>>cas;
    }
    return 0;
}
//enemyattackstonight
//ntsgycnzeakietthmaot
void enc(string s){
    int l=s.length();
    int r,row;
    if(l%5!=0){
        r=5-l%5;
        cout<<"Appending "<<r<<" z's in the end"<<cout;
        for(int j=0;j<r;j++){
            s.append("z");
        }
    }
    l=s.length();
    row=l/5;
     int len=0,z=0;
     char alpha[row][5];
     char beta[row][5];
    for(z=0;z<row;z++){
        for(int i = 0 ; i<5 ; i++){
            alpha[z][i]=s[len];
            len++;
        }
    }
    cout<<"Table written in row form"<<endl;
    for(z=0;z<row;z++){
        for(int i = 0 ; i<5 ; i++){
            cout<<alpha[z][i];
        }
        cout<<endl;
    }
    cout<<endl;

    for(int i = 0 ;i<5; i++){
        int x=key[i];
        x--;
        for(int j =0;j<row;j++){
            beta[j][x]=alpha[j][i];
        }
    }
    cout<<"Table after applying key"<<endl;
    for(z=0;z<row;z++){
        for(int i = 0 ; i<5 ; i++){
            cout<<beta[z][i];
        }
        cout<<endl;
    }
    cout<<endl;

    cout<<"Encrypted string is:"<<endl;
    for(z=0;z<5;z++){
        for(int i = 0 ; i<row ; i++){
            cout<<beta[i][z];
        }
    }
    cout<<endl;
}

void decr(string s){
    int l=s.length();
    int row=l/5;
    int len=0,z=0;
    char alpha[row][5];
    char beta[row][5];
    for(z=0;z<5;z++){
        for(int i = 0 ; i<row ; i++){
            beta[i][z]=s[len];
            len++;
        }
    }
    cout<<endl<<"Column form is:"<<endl;
    for(z=0;z<row;z++){
        for(int i = 0 ; i<5 ; i++){
            cout<<beta[z][i];
        }
        cout<<endl;
    }
    cout<<endl;


    for(int i = 0 ;i<5; i++){
        int x=revkey[i];
        x--;
        for(int j =0;j<row;j++){
            alpha[j][x]=beta[j][i];
        }
    }

    cout<<"Table after applying key is:"<<endl;
    for(z=0;z<row;z++){
        for(int i = 0 ; i<5 ; i++){
            cout<<alpha[z][i];
        }
        cout<<endl;
    }
    cout<<endl;
    cout<<"Decrypted string is:"<<endl;
       for(z=0;z<row;z++){
        for(int i = 0 ; i<5 ; i++){
            cout<<alpha[z][i];
        }
    }
}

