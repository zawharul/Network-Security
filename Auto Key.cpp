#include<stdio.h>
#include <iostream>
#include<algorithm>
#include <string>
using namespace std;
int main()
{
    string message, message1,message2,message3;
    char ch;
    int i,key;
    cout<<"Enter a message(small letter) to encrypt: ";
    getline(cin,message2);
    message=message2;
    message.erase(std::remove(message.begin(), message.end(), ' '), message.end());
    cout<< "Enter Key Stream: ";
    cin>> key;
    
    int n=message.length();
    for(i=0; i<=n; i++)
    {
        message1[0]=key+97;
        message1[i+1]=message[i];
    }

    for(i=0; i<=n; i++)
    {
        ch=(((message1[i]-'a')+(message[i]-'a'))%26)+'A';
        message3[i]=ch;
    }
    for(i=0;i<n;i++){
        cout<<message3[i];
    }

    cout<<endl<<"Decrypted Message: ";
    ch=' ';
    for(i=1; i<=n; i++)
    {
        ch=((((message3[i]-'A')-(message[i]-'a'))+26)%26)+'a';
        cout<<ch;
    }

    return 0;
}
