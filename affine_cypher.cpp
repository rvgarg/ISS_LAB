#include <bits/stdc++.h>
using namespace std;

// Multiplicative Inverse for Calculating Inverse of A with respect to M
int multiplicative_Inverse(int a, int m)
{

    // calculating multiplicative inverse
    int flag = 0;

    for (int i = 0; i < m; i++)
    {
        flag = (a * i) % m;
        if (flag == 1)
        {
            return i;
        }
    }
}

string encrypt(int a, int b, int m, string msg)
{

    // taking an string to be ciphered
    string ciphered = "";

    // using c = ap + b (mod m) for every character in the string except space.
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] != ' ')
            // appending with the ciphered text character by character using encryption technique
            ciphered = ciphered + (char)((((a * (msg[i] - 'A')) + b) % m) + 'A');
        else
            ciphered += msg[i];
    }
    return ciphered;
}

string decrypt(int a, int b, int m, string ciphered)
{
    string text = "";

    // calculating inverse of a for decryption
    int inverse_a = multiplicative_Inverse(a, m);

    // using p = inverse(a)(c-b) (mod m) for every character except space
    for (int i = 0; i < ciphered.length(); i++)
    {
        if (ciphered[i] != ' ')
            // appending with the deciphered text character by character using decryption technique
            text = text + (char)(((inverse_a * ((ciphered[i] + 'A' - b)) % m)) + 'A');
        else
            text += ciphered[i];
    }

    return text;
}

int main()
{
    // a and b are keys for the Affine Cipher
    // text is our original text which is to be ciphered

    string text;
    int a, b, m;
    cout << "Enter the 2 keys : " << endl;
    cin >> a >> b;
    cout << "Enter the message : ";
    cin >> text;

    // using english alphabets so m = 26
    m = 26;
    string encryptedText, dencryptedText;

    // function calls to encrpyt and decrypt
    encryptedText = encrypt(a, b, m, text);
    cout << "Encrypted: " << encryptedText << "\n";
    dencryptedText = decrypt(a, b, m, encryptedText);
    cout << "Decrypted: " << dencryptedText << "\n";

    return 0;
}
