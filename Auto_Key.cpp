#include<bits/stdc++.h>
using namespace std;

string validation(string &str){
    string valid ="";
    for(int i=0;i<str.size();i++){
        if(str[i]>='a' && str[i]<='z') valid+=str[i];
        if(str[i]>='A' && str[i]<='Z') valid+=(str[i]+32);
        else continue;
    }
    return valid;
}
string encrypt(string &plaintext,int key){
    string cipherText="";
    for(int i=0;i<plaintext.size();i++){
        cipherText+= (plaintext[i]-'a'+key)%26+'a';
        key = plaintext[i]-'a';
    }
    return cipherText;
}
string decrypt(string &ciphertext,int key){
    string plaintext="";
    for(int i=0;i<ciphertext.size();i++){
        plaintext += (ciphertext[i]-'a'-key+26)%26+'a';
        key=(ciphertext[i]-'a'-key+26)%26;
    }
    return plaintext;
}


int main(){
    string text,plainText,cipherText,message,resultPlaintext;
    int key;
    cout<<"Enter the Text : ";
    getline(cin,text);
    plainText = validation(text);
    cout<<endl<<"After validation: "<<plainText;

    cout<<endl<<"Enter the key: ";
    cin>>key;
    cipherText = encrypt(plainText,key);
    message = cipherText;

    transform(message.begin(),message.end(),message.begin(),::toupper);
    cout<<endl<<"Cipher text is: "<< message;

    resultPlaintext = decrypt(cipherText,key);
    cout<<endl<<"Plain text is :"<<resultPlaintext;


}
