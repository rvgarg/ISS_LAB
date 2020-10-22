#include <bits/stdc++.h>
using namespace std;

class position
{
public:
    int row;
    int column;
};

char matrix[5][5]; // Global variable for matrix of cipher

void generateMatrix(string key)
{
    // flag keeps track of letters that are filled in matrix
    // flag = 0 -> letter not already present in matrix
    // flag = 1 -> letter already present in matrix
    int flag[26] = {0};
    int x = 0, y = 0;

    // Add all characters present in the key
    for (int i = 0; i < key.length(); i++)
    {
        if (key[i] == 'j') // replace j with i
            key[i] = 'i';

        if (flag[key[i] - 'a'] == 0)
        {
            matrix[x][y++] = key[i];
            flag[key[i] - 'a'] = 1;
        }
        if (y == 5)
            x++, y = 0;
    }

    // Add remaining characters
    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        if (ch == 'j')
            continue; // don't fill j since j was replaced by i

        if (flag[ch - 'a'] == 0)
        {
            matrix[x][y++] = ch;
            flag[ch - 'a'] = 1;
        }
        if (y == 5)
            x++, y = 0;
    }
}

// function to add filler letter('x')
string formatMessage(string msg)
{
    for (int i = 0; i < msg.length(); i++)
    {
        if (msg[i] == 'j') // replacing j with i in the message
            msg[i] = 'i';
    }

    for (int i = 1; i < msg.length(); i += 2) //pairing two characters
    {
        if (msg[i - 1] == msg[i])
            msg.insert(i, "x");
    }

    if (msg.length() % 2 != 0) // insert 'x' at the last of message if the length of the message is odd
        msg += "x";
    return msg;
}

// Returns the position of the character
position getPosition(char c)
{
    for (int i = 0; i < 5; i++)
        for (int j = 0; j < 5; j++)
            if (c == matrix[i][j])
            {
                position p = {i, j}; // object of position class with the row and column value of the character in the matrix
                return p;
            }
}

// Encrypts the message passed an argument to the function
string Encrypt(string message)
{
    string cipheredText = "";
    for (int i = 0; i < message.length(); i += 2) // i is incremented by 2 inorder to check for pair values
    {
        position p1 = getPosition(message[i]);     // getting the position of the character at ith position in the message
        position p2 = getPosition(message[i + 1]); // getting the position of the character at i + 1 th position in the message
        int x1 = p1.row;
        int y1 = p1.column;
        int x2 = p2.row;
        int y2 = p2.column;

        if (x1 == x2) // case of same row
        {
            cipheredText += matrix[x1][(y1 + 1) % 5];
            cipheredText += matrix[x2][(y2 + 1) % 5];
        }
        else if (y1 == y2) // case of same column
        {
            cipheredText += matrix[(x1 + 1) % 5][y1];
            cipheredText += matrix[(x2 + 1) % 5][y2];
        }
        else // all the reamining cases
        {
            cipheredText += matrix[x1][y2];
            cipheredText += matrix[x2][y1];
        }
    }
    return cipheredText;
}

// Decrypts the encrypted message passed as an argument to the function
string Decrypt(string message)
{
    string decipheredText = "";
    for (int i = 0; i < message.length(); i += 2) // i is incremented by 2 inorder to check for pair values
    {
        position p1 = getPosition(message[i]);     // getting the position of the character at ith position in the message
        position p2 = getPosition(message[i + 1]); // getting the position of the character at i + 1 th position in the message
        int x1 = p1.row;
        int y1 = p1.column;
        int x2 = p2.row;
        int y2 = p2.column;

        if (x1 == x2) // case of same row
        {
            decipheredText += matrix[x1][--y1 < 0 ? 4 : y1];
            decipheredText += matrix[x2][--y2 < 0 ? 4 : y2];
        }
        else if (y1 == y2) // case of same column
        {
            decipheredText += matrix[--x1 < 0 ? 4 : x1][y1];
            decipheredText += matrix[--x2 < 0 ? 4 : x2][y2];
        }
        else // all the remaining cases
        {
            decipheredText += matrix[x1][y2];
            decipheredText += matrix[x2][y1];
        }
    }
    return decipheredText;
}

int main()
{
    string plainText;
    cout << "Enter message : ";
    cin >> plainText;

    string key;

    cout << "\nEnter key  : " << key;
    cin >> key;

    generateMatrix(key); // generating matrix

    cout << "Key "
         << " Matrix:" << endl;
    for (int k = 0; k < 5; k++) // printing matrix
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[k][j] << "  ";
        }
        cout << endl;
    }

    string formattedMessage = formatMessage(plainText);
    cout << "Formatted Message \t: " << formattedMessage << endl;

    string cipherText = Encrypt(formattedMessage);
    cout << "Encrypted Message \t: " << cipherText << endl;

    string decryptMsg = Decrypt(cipherText);
    cout << "Decrypted Message \t: " << decryptMsg << endl;
}
