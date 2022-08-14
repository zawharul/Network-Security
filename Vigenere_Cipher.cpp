#include<bits/stdc++.h>
using namespace std;

string validation(string &str){
    string valid = "";
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z') valid+=str[i];
        if(str[i]>='A' && str[i]<='Z') valid+=(str[i]+32);
        else continue;
    }
    return valid;
}


int main(){
    string message,key;
    char ch;
    int j=0,m,n;
    cout<<"Enter the message: ";
    getline(cin,message);
    cout<<endl<<"Validation after text: ";
    message = validation(message);
    cout<<message;
    cout<<endl<<"Enter the key: ";
    cin>>key;

    m = message.length();
    n = key.length();
    int arr[m];
    for(int i=0;i<m&&j<n;i++){
        arr[i]=key[j]-'a';
        j++;
        if(j>=n){
            j=0;
        }
    }
    cout<<endl<<"Encryption: ";
    message.erase(std::remove(message.begin(),message.end(),' '),message.end());
    for(int i=0;i<m;i++){
        ch = (((message[i]-'a')+arr[i])%26)+65;
        message[i]=ch;
    }
    cout<<message;
    cout<<endl<<"Decryption : ";
    for(int i=0;i<m;i++){
        ch = (((message[i]-'A')-arr[i]+26)%26)+97;
        message[i]=ch;
    }
    cout<<message;
}
