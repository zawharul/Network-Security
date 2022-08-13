#include<bits/stdc++.h>
#include<algorithm>
#include<string>

using namespace std;


int inverse(int key){
    for(int i=0;i<26;i++){
        if((i*key)%26==1)return i;
        if(i>26) return 27;
    }
}

string validation(string &str){
    string valid="";
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z') valid+=str[i];
        if(str[i]>='A' && str[i]<='Z') valid+=(str[i]+32);
        else continue;
    }
    return valid;
}

int main(){
    string message,message1;
    int key,keyInverse,secondKey;
    char ch;

    cout<<"Enter the text: ";
    getline(cin,message);

    message = validation(message);
    cout<<endl<<"After validation: "<<message;

    a:

    cout<<endl<<"Enter First Key: ";
    cin>>key;
    cout<<endl<<"Enter Second Key: ";
    cin>>secondKey;

    keyInverse= inverse(key);
    if(keyInverse!=27){
        for(int i=0;message[i]!='\0';i++){
            ch = message[i];
            if(ch>=97 && ch<=122){
                ch = ((((ch-97)*key)+secondKey)%26)+97;
                message[i]=ch;
            }
        }
        message1 = message;

        transform(message1.begin(),message1.end(),message1.begin(),::toupper);
        message1.erase(std::remove(message1.begin(),message1.end(), ' '),message1.end());
        cout<<endl<<"Encryption: "<<message1;

        for(int i=0;message[i]!='\0';i++){
            ch = message[i];
            if(ch>=97 && ch<=122){
                ch = ((((ch-97)-secondKey)*keyInverse+26)%26)+97;
                message[i]=ch;

            }
        }
        cout<<endl<<"Decryption: "<<message;
    }else{
        cout<<endl<<"Inverse is not possible";
        goto a;
    }
}
