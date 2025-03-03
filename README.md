# Affine Cipher Implementation in C++

**Name**  Mohamed Tarek

## Description

This program implements the **Affine Cipher**, an encryption technique based on modular arithmetic. It takes user input for a plaintext message and encrypts it using the Affine Cipher formula. The program then decrypts the ciphertext back to the original plaintext.

## How to Run

### Compilation

Use a C++ compiler (e.g., `g++`) to compile the program:

```sh
 g++ affine_cipher.cpp -o affine_cipher

```

### Execution

Run the compiled program:

```sh
./affine_cipher

```

### Usage

1.  Enter the plaintext message.
2.  Enter key `a` (must be coprime with 26; otherwise, the program will prompt for a valid input).
3.  Enter key `b` (any integer).
4.  The program will display the encrypted ciphertext and the decrypted plaintext.

## Input Format

-   Enter a **plaintext message** (only alphabetic characters are encrypted; others are preserved).
-   Enter **key 'a'** (must be coprime with 26).
-   Enter **key 'b'** (any integer).

## Example Usage

```
Enter the plaintext: HELLO
Enter key 'a': 5
Enter key 'b': 8
Ciphertext: ZEBBW
Decrypted text: HELLO

```

## Additional Features

-   ✅ Preserves non-alphabetic characters.
-   ✅ Validates that `a` is coprime with 26 before proceeding.
-   ✅ Supports both uppercase and lowercase letters.

## Notes

-   If `a` is **not coprime** with 26, the program will prompt the user to enter another value.
-   If **no modular inverse** exists for `a`, decryption is not possible.

