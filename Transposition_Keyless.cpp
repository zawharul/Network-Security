#include<bits/stdc++.h>
using namespace std;
int numberOrCol = 4;

string encrypt(string &Plaintext){
    string cipherText = "";
    for(int col = 0; col<numberOrCol; col++){ ///matrix na baniye direct calculation kore ciphertext generate. matrix er motoi kaj kore (internally matrix).
        int charPosition = col;
        while(charPosition < Plaintext.size()){
            cipherText += Plaintext[charPosition];
            charPosition +=  numberOrCol;
        }
    }
    return cipherText;
}
string decrypt(string &cipherText){
    return encrypt(cipherText); /// same kaj (ulta hoileo kaj kore)
}
string Capital(string str){
    for(int i=0; i<str.size(); i++){
        str[i] = (char)(str[i] - 32);
    }
    return str;
}
string validation(string &str){
    string valid = "";
    for(int i = 0; i<str.size(); i++){
        if(str[i] >= 'a' && str[i] <= 'z') valid += str[i];
        else if(str[i] >= 'A' && str[i] <= 'Z') valid += (str[i] + 32);
        else continue;
    }
    return valid;
}
int main(){
    string Plaintext, cipherText, ResultPlaintext;
    cout<<"Input Your PlainText String: ";
    getline(cin, Plaintext);

    Plaintext = validation(Plaintext);
    cout<<endl<<"Your PlainText is: "<<Plaintext<<endl;

    cout<<endl<<"Encryption: ";
    cipherText = encrypt(Plaintext);
    cout<<"(Done)"<<endl;

    cout<<"CipherText (Encrypted Result) = "<<Capital(cipherText)<<endl<<endl;

    cout<<"Decryption: ";
    ResultPlaintext = decrypt(cipherText);
    cout<<"(Done)"<<endl;

    cout<<"Decryption Result Plaintext = "<<ResultPlaintext<<endl;
    return 0;
}

