#include<bits/stdc++.h>
using namespace std;

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
    map<char,char> mappedCharEncrypt{
        {'a','Z'},
        {'b','Y'},
        {'c','X'},
        {'d','W'},
        {'e','V'},
        {'f','U'},
        {'g','T'},
        {'h','S'},
        {'i','R'},
        {'j','Q'},
        {'k','P'},
        {'l','O'},
        {'m','N'},
        {'n','M'},
        {'o','L'},
        {'p','K'},
        {'q','J'},
        {'r','I'},
        {'s','H'},
        {'t','G'},
        {'u','F'},
        {'v','E'},
        {'w','D'},
        {'x','C'},
        {'y','B'},
        {'z','A'},
    };

    map<char,char> mappedCharDecrypt;
    for(auto itr= mappedCharEncrypt.begin(); itr!=mappedCharEncrypt.end();itr++){
        mappedCharDecrypt[itr->second] = itr->first;
    }

    string message;
    cout<<endl<<"Enter the text: ";
    getline(cin,message);

    message = validation(message);
    cout<<endl<<"Validation After Text: "<<message;

    string encryption="";
    for(int i=0;i<message.length();i++){
        encryption+= mappedCharEncrypt[message[i]];
    }
    cout<<endl<<"Encryption : "<<encryption;

    string decrypt="";
    for(int i=0;i<encryption.length();i++){
        decrypt+=mappedCharDecrypt[encryption[i]];
    }
    cout<<endl<<"Decryption: "<<decrypt;

}
