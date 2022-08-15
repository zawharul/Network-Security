#include<iostream>
#include<math.h>
using namespace std;

int gcd(int a, int b) {
   int t;
   while(1) {
      t= a%b;
      if(t==0)
      return b;
      a = b;
      b= t;
   }
}
int main() {
    double message;
    cout<<"Enter message:";
    cin>>message;

   double p = 23;
   double q = 13;
   double n=p*q;
   double track;
   double phi= (p-1)*(q-1);
   //public key
   //e stands for encrypt
   double e=2;
   //for checking that 1 < e < phi(n) and gcd(e, phi(n)) = 1; i.e., e and phi(n) are coprime.
   while(e<phi) {
      track = gcd(e,phi);
      if(track==1)
         break;
      else
         e++;
   }
   //private key
   //d stands for decrypt
   double d1=1/e;
   double d=fmod(d1,phi);

   double c = pow(message,e); //encrypt the message
   double m = pow(c,d);
   c=fmod(c,n);
   m=fmod(m,n);
   cout<<"Original Message = "<<message;
   cout<<"\n"<<"p = "<<p;
   cout<<"\n"<<"q = "<<q;
   cout<<"\n"<<"n = pq = "<<n;
   cout<<"\n"<<"phi = "<<phi;
   cout<<"\n"<<"e = "<<e;
   cout<<"\n"<<"d = "<<d;
   cout<<"\n\n"<<"Encrypted message = "<<c;
   cout<<"\n\n"<<"Decrypted message = "<<m<<"\n";
   return 0;
}

