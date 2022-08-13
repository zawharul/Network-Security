#include<bits/stdc++.h>
#include<string>
#include<algorithm>

using namespace std;

string validation(string &str){
    string valid = "";
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z') valid+=str[i];
        if(str[i]>='A' && str[i]<='Z')valid+=(str[i]+32);
        else continue;
    }
    return valid;
}

int inverse(int key){
    for(int i=0;i<26;i++){
        if((i*key)%26==1)return i;
        if(i>26) return 27;
    }
}

int main(){
    string message,message1;
    int key,keyInverse;
    char ch;
    cout<<"Enter the text: ";
    getline(cin,message);
    message = validation(message);
    cout<<endl<<"Validation after text: "<<message;
    a:
    cout<<endl<<"Key : ";
    cin>>key;

    keyInverse=inverse(key);

    if(keyInverse!=27){

        for(int i=0;message[i]!='\0';i++){
            ch = message[i];
            if(ch>=97 && ch<=122){
                ch=(((ch-97)*key)%26)+97;
                message[i]=ch;
            }
        }
        message1 = message;

        transform(message1.begin(),message1.end(),message1.begin(),::toupper);
        message1.erase(std::remove(message1.begin(),message1.end(),' '),message1.end());
        cout<<endl<<"Encryption: "<<message1;

        for(int i=0;message[i]!='\0';i++){
            ch = message[i];
            if(ch>=97 && ch<=122){
                ch = (((ch-97)*keyInverse+26)%26)+97;
                message[i]=ch;
            }
        }
        cout<<endl<<"Decryption: "<<message;

    }else{
        cout<<"NO inverse";
        goto a;
    }


}
