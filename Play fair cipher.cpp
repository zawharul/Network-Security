#include<bits/stdc++.h>
using namespace std;
vector<int> BogusPositionStore;
char BogusChar = 'x';
map<char, pair<int,int> > matrix;
void initMatrix(){
    matrix.insert({'a', {0, 4}});
    matrix.insert({'b', {0, 3}});
    matrix.insert({'c', {1, 4}});
    matrix.insert({'d', {0, 2}});
    matrix.insert({'e', {1, 3}});
    matrix.insert({'f', {2, 4}});
    matrix.insert({'g', {0, 1}});
    matrix.insert({'h', {1, 2}});
    matrix.insert({'i', {2, 3}});
    matrix.insert({'j', {2, 3}});
    matrix.insert({'k', {3, 4}});
    matrix.insert({'l', {0, 0}});
    matrix.insert({'m', {1, 1}});
    matrix.insert({'n', {2, 2}});
    matrix.insert({'o', {3, 3}});
    matrix.insert({'p', {4, 4}});
    matrix.insert({'q', {1, 0}});
    matrix.insert({'r', {2, 1}});
    matrix.insert({'s', {3, 2}});
    matrix.insert({'t', {4, 3}});
    matrix.insert({'u', {2, 0}});
    matrix.insert({'v', {3, 1}});
    matrix.insert({'w', {4, 2}});
    matrix.insert({'x', {3, 0}});
    matrix.insert({'y', {4, 1}});
    matrix.insert({'z', {4, 0}});

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            for(auto it = matrix.begin(); it != matrix.end(); it++){
                pair<int, int> pp = {i,j};
                if((it->second) == pp) cout<<(it->first)<<" ";
            }
        }
        cout<<endl;
    }
}

string encrypt(string &Plaintext){
    string cipherText = "";
    char ch1, ch2;
    pair<int, int> p1, p2, r1, r2;
    for(int i = 0; i < Plaintext.size(); i += 2){
        
        p1 = matrix[Plaintext[i]];
        p2 = matrix[Plaintext[i+1]];
        if(p1.first == p2.first){
            r1 = {p1.first, (p1.second + 1) % 5};
            r2 = {p2.first, (p2.second + 1) % 5};
        }
        else if(p1.second == p2.second){
            r1 = {(p1.first+1) % 5, p1.second};
            r2 = {(p2.first+1) % 5, p2.second};
        }
        else{
            r1 = {p1.first, p2.second};
            r2 = {p2.first, p1.second};
        }
        
        char res_ch1, res_ch2;
        for(auto it = matrix.begin(); it != matrix.end(); it++){
            if((it->second) == r1) res_ch1 = (it->first);
            if((it->second) == r2) res_ch2 = (it->first);
        }
        cipherText = cipherText + res_ch1 + res_ch2;
    }
    return cipherText;
}
string decrypt(string &cipherText){
    string Plaintext = "";
    char ch1, ch2;
    pair<int, int> p1, p2, r1, r2;
    for(int i = 0; i < cipherText.size(); i += 2){
      
        p1 = matrix[cipherText[i]];
        p2 = matrix[cipherText[i+1]];
        if(p1.first == p2.first){
            r1 = {p1.first, (p1.second - 1 + 5) % 5};
            r2 = {p2.first, (p2.second - 1 + 5) % 5};
        }
        else if(p1.second == p2.second){
            r1 = {(p1.first - 1 + 5) % 5, p1.second};
            r2 = {(p2.first - 1 + 5) % 5, p2.second};
        }
        else{
            r1 = {p1.first, p2.second};
            r2 = {p2.first, p1.second};
        }
        
        char res_ch1, res_ch2;
        for(auto it = matrix.begin(); it != matrix.end(); it++){
            if((it->second) == r1) res_ch1 = (it->first);
            if((it->second) == r2) res_ch2 = (it->first);
        }
        Plaintext = Plaintext + res_ch1 + res_ch2;
    }
    return Plaintext;
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
vector<pair<char, char> > ValidPairMaker(string str){
    vector<pair<char, char> > pi_vec;
    char ch1, ch2;
    for(int i = 0; i < str.size(); i += 2){
        ch1 = str[i];
        if(i+1 >= str.size()) {
            ch2 = BogusChar;
            BogusPositionStore.push_back(2*pi_vec.size() + 1);
        }
        else if((str[i] == str[i+1]) || ((str[i] == 'i' || str[i] == 'j') && (str[i+1] == 'i' || str[i+1] == 'j'))){
            ch2 = BogusChar;
            BogusPositionStore.push_back(2*pi_vec.size() + 1);
            i--;
        }
        else ch2 = str[i+1];
        pi_vec.push_back({ch1, ch2});
    }
    return pi_vec;
}
string print(vector<pair<char, char> >pi_vec){
    string bogusPlain = "";
    for(int i = 0; i < pi_vec.size(); i++){
        cout<<"{"<<pi_vec[i].first<<", "<<pi_vec[i].second<<"}";
        bogusPlain = bogusPlain + pi_vec[i].first + pi_vec[i].second ;
    }
    return bogusPlain;
}
string RemoveBogus(string ResultPlaintext){
    string plain = "";
    int j = 0;
    for(int i = 0; i < ResultPlaintext.size(); i++){
        if(j<BogusPositionStore.size() && (BogusPositionStore[j] == i)){
            j++;
            continue;
        }
        plain += ResultPlaintext[i];
    }
    return plain;
}
int main(){
    initMatrix();
    string Plaintext, cipherText, ResultPlaintext;
    cout<<endl<<"Input Your PlainText String: ";
    getline(cin, Plaintext);

    Plaintext = validation(Plaintext);
    cout<<endl<<"After Removing ODD char, Your PlainText is: "<<Plaintext<<endl<<endl;

    vector<pair<char, char> > PairsForPlaintext = ValidPairMaker(Plaintext);
    Plaintext = print(PairsForPlaintext);
    cout<<endl<<"After Adding Bogus on PlainText with pair making : "<<Plaintext<<endl;

    cout<<endl<<"Encryption: ";
    cipherText = encrypt(Plaintext);
    cout<<"(Done)"<<endl;

    cout<<"CipherText (Encrypted Result) = "<<Capital(cipherText)<<endl<<endl;

    cout<<"Decryption: ";
    ResultPlaintext = decrypt(cipherText);
    cout<<"(Done)"<<endl;

    cout<<"After Decryption = "<<ResultPlaintext<<endl;
    cout<<"Result Plaintext = "<<RemoveBogus(ResultPlaintext)<<endl;
    return 0;
}
