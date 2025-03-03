#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int mod_inverse(int a, int m) {
    for (int i = 1; i < m; i++) {
        if ((a * i) % m == 1)
            return i;
    }
    return -1; // No modular inverse exists
}

string affine_encrypt(string plaintext, int a, int b) {
    string ciphertext = "";
    for (char c : plaintext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int P = c - base;
            int C = (a * P + b) % 26;
            ciphertext += (C + base);
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

string affine_decrypt(string ciphertext, int a, int b) {
    int a_inv = mod_inverse(a, 26);
    if (a_inv == -1) {
        throw runtime_error("No modular inverse found. Decryption is not possible.");
    }
    
    string plaintext = "";
    for (char c : ciphertext) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            int C = c - base;
            int P = (a_inv * (C - b + 26)) % 26; // Ensure positive modulo
            plaintext += (P + base);
        } else {
            plaintext += c;
        }
    }
    return plaintext;
}

int main() {
    string plaintext;
    cout << "Enter the plaintext: ";
    getline(cin, plaintext);
    
    int a, b;
    while (true) {
        cout << "Enter key 'a': ";
        cin >> a;
        if (gcd(a, 26) == 1) {
            break;
        } else {
            cout << "Error: 'a' must be coprime with 26. Try again." << endl;
        }
    }
    
    cout << "Enter key 'b': ";
    cin >> b;
    cin.ignore(); // Ignore newline character after entering b
    
    string ciphertext = affine_encrypt(plaintext, a, b);
    cout << "Ciphertext: " << ciphertext << endl;
    
    string decrypted_text = affine_decrypt(ciphertext, a, b);
    cout << "Decrypted text: " << decrypted_text << endl;
}
