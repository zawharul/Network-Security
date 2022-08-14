#include<bits/stdc++.h>
#define ll long long
using namespace std;

int Multiplicative_Inverse(int key, int z){
    for(int i = 1; i <= z; i++)
        if((i * key%z) % z == 1) return i;
}
ll BigMod(int base, int power, int MOD){
    if(power == 0) return 1;
    else if(power%2 == 1) return (BigMod(base, power - 1, MOD) * base) % MOD;
    else {
        ll val = BigMod(base, (int)power/2, MOD);
        return (val * val) % MOD;
    }
}
int encrypt(string &Plaintext, int Public_key , int MOD){
    int CipherInt = 0;
    for(int i=0; i<Plaintext.size(); i++){
        CipherInt = CipherInt * 100 + (int)(Plaintext[i] - 'a' + 1);
    }
    return BigMod(CipherInt, Public_key, MOD);
}
string decrypt(int cipherText, int Private_Key, int MOD){
    int plain = BigMod(cipherText, Private_Key, MOD);
    string Plaintext = "";
    while(plain){
        Plaintext = (char)('a' - 1 + plain%100) + Plaintext;
        plain /= 100;
    }
    return Plaintext;
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
    string Plaintext, ResultPlaintext;
    ll cipherText;
    int p, q, public_key;
    cout<<"Give Two Prime Number: ";
    cin>>p>>q;
    int Phi = (p-1) * (q-1);
    int n = p * q;
    cout<<"n = "<<n<<", Phi = "<<Phi<<endl;

    cout<<"Input Your Public Key: ";
    cin>>public_key;
    while(__gcd(public_key, Phi) != 1){
        cout<<"Invalid Key, Input the key again: ";
        cin>>public_key;
    }
    int Private_key = Multiplicative_Inverse(public_key, Phi);
    cout<<"Your Private Key is: "<<Private_key<<endl;

    cout<<"Input Your PlainText String: ";
    cin.ignore();
    getline(cin, Plaintext);


    Plaintext = validation(Plaintext);
    cout<<endl<<"Your PlainText is: "<<Plaintext<<endl;

    cout<<endl<<"Encryption: ";
    cipherText = encrypt(Plaintext, public_key, n);
    cout<<"(Done)"<<endl;

    cout<<"CipherText (Encrypted Result) = "<<cipherText<<endl<<endl;

    cout<<"Decryption: ";
    ResultPlaintext = decrypt(cipherText, Private_key, n);
    cout<<"(Done)"<<endl;

    cout<<"Decryption Result Plaintext = "<<ResultPlaintext<<endl;
    return 0;
}
