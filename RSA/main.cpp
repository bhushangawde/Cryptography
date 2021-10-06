#include <iostream>
#include <math.h>
using namespace std;

int gcd (int a , int b){
    if(a==0){
        return b;
    }
    else {
        return gcd(b%a,a);
    }
}

bool coprime (int a , int b){
    return (gcd(a,b)==1);
}

bool prime(int a){

    for(int i = 2;i<=a/2 ;i++){
        if(a%i==0)
            return false;
    }
    return true;

}

int inverse(int key,int fin ){
     for(int i =1;i<fin;i++){
        if((key*i)%fin == 1){
            return i;
        }
     }
}

int power(int x, unsigned int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res*x) % p;
        y = y>>1;
        x = (x*x) % p;
    }
    return res;
}

void encrypt(int P , int e, int fin,int n){
    int Cy = (int)pow(P,e);
    int C = Cy%n;
    int d = inverse(e,fin);
    cout<<d;
    cout<<"The encrypted text is : "<<endl<<C<<endl;
    int x = power(C,d,n);
    cout<<"The decrypted text is : "<<endl<<x;
}

int main()
{
    int num,P,C;
    cout<<"Enter num: ";
    cin>>num;
    int p,q;

    for(int i = 2;i<=num/2 ;i++){
        if(num%i==0 && prime(i) && prime(num/i)){
            p=i;
            q=num/i;
            break;
        }
    }
    cout<<p<<endl<<q<<endl;
    int fin = (p-1)*(q-1);
    int e;
    for(int i = 2;i<=fin ;i++){
        if(coprime(fin,i)){
            e=i;
            cout<<e;
            break;
        }
    }
    cout<<endl<<"Enter the Plain Text: ";
    cin>>P;
    encrypt(P,e,fin,num);
    return 0;
}


