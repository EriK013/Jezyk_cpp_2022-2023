#include "sha256.h"
#include <iostream>
#include <string>
#include <chrono>
using namespace std;
// Utworzenie SHA265
SHA256 sha256;

const long long MAX_NONCE = 1000000;

string kop(int numer_bloku, string tranzakcje, string previous_hash, int prefix_zeros){
    string btc_prefix = string(prefix_zeros, '0');
    string new_hash;
    for (long long nonce = 0; nonce < MAX_NONCE; nonce++){
        string text = (to_string(numer_bloku) + tranzakcje + previous_hash + to_string(nonce));
        new_hash = sha256(text);
        if (new_hash.starts_with(btc_prefix)){
            cout << "Wykopano bitcoin! Nonce " << nonce << endl;
            return new_hash;
        }
    }
    cout << "Nie udało się wykopać bitcoina:(" << 
    endl;
    return new_hash;   
}

int main(){
    string tranzakcje =
    "ABC->DEF \nGHI->JKL";
    int difficulty = 19;
    auto t1 = chrono::high_resolution_clock::now();
    string new_hash = kop(785660, tranzakcje, "00000000000000000001a2c29b0c4193ecb20d0a5b7a4a863067cca5ca0cb2d4", difficulty);
    auto t2 = chrono::high_resolution_clock::now();
    auto int_ms = chrono::duration_cast<chrono::milliseconds>(t2 - t1);
    cout << "Czas w ms: " << int_ms.count() << endl;
    cout << new_hash << endl;
}