#include <bits/stdc++.h>
using namespace std;
string generateKey(string key, int size)
{
    string gen_key;
    int len = key.length();
    for (int i = 0; i < size; i++)
    {
        gen_key.push_back(key.at(i % len));
    }
    return gen_key;
}

string cypher(string text, string key)
{
    string cypher_text;
    for (int i = 0; i < text.length(); i++)
    {
        char ch = (text.at(i) + key.at(i)) % 26;

        ch += 'A';
        cypher_text.push_back(ch);
    }
    return cypher_text;
}

string decypher(string cytext, string key)
{
    string decyphered_text;
    for (int i = 0; i < cytext.length(); i++)
    {
        char ch = (cytext.at(i) - key.at(i) +26) % 26;

        ch += 'A';
        decyphered_text.push_back(ch);
    }
    return decyphered_text;
}

int main()
{
    string message, key;
    cout << "enter message";
    cin >> message;
    cout << "enter key";
    cin >> key;
    string genkey = generateKey(key, message.length());

    string cypher_text = cypher(message, genkey);

    cout << "Cypher text: " << cypher_text << endl;

    cout << "Decyphered text: " << decypher(cypher_text, genkey);
}