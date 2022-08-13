#include<bits/stdc++.h>
#include<algorithm>
#include<string>

using namespace std;

string validation(string &str){
    string valid="";
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z') valid+=str[i];
        else if(str[i]>='A' && str[i]<='Z') valid+= (str[i]+32);
        else continue;
    }
    return valid;
}

int main(){
    string message,message1;
    char ch;
    int key;

    cout<<"Enter the text:";
    getline(cin,message);

    message = validation(message);
    cout<<endl<<"Validation after text: "<<message;

    cout<<endl<<"Key : ";
    cin>>key;

    for(int i=0;message[i]!='\0';i++){
        ch = message[i];
        if(ch>=97 && ch<=122){
            ch = ((ch-97+key)%26)+97;
            message[i] = ch;
        }
    }

    message1 = message;

    transform(message1.begin(), message1.end(),message1.begin(),::toupper);
    message1.erase(std::remove(message1.begin(),message1.end(),' ' ),message1.end());

    cout<<endl<<"The cipher text is :"<<message1;

    for(int i=0;message[i]!='\0';i++){
        ch = message[i];
        if(ch>=97 && ch<=122){
            ch = ((ch-97-key+26)%26)+97;
            message[i]=ch;
        }
    }
    cout<<endl<<"Decryption (Plain text) :"<<message;

}
