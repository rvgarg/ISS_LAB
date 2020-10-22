#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
    string str;
    cout << "enter upto 20 character string : ";
    cin >> str;
    if (str.length() > 20)
    {
        cout << "length greater than mentioned";
    }
    unsigned int key, tkey;
    cout << "enter 5 digit key for cipher";
    cin >> key;
    vector<pair<int, int>> qwerty;
    tkey = key;
    int limit = 4;
    while (tkey > 0)
    {
        int digit = tkey % 10;
        qwerty.push_back(make_pair(digit, limit));
        limit--;
        tkey /= 10;
    }
    sort(qwerty.begin(), qwerty.end());
    for (int i = 0; i < 5; i++)
    {
        cout << qwerty[i].first << " " << qwerty[i].second << endl;
    }
    char data[4][5], cyphered[5][4];
    int r = 0, c = 0;
    cout << " original data: " << endl;
    for (int i = 0; i < 20; i++)
    {
        data[r][c] = str.at(i);
        c++;
        cout << str.at(i) << " ";
        if (c == 5)
        {
            r++;
            c = 0;
            cout << endl;
        }
    }
    cout << "Cyphered text: " << endl;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << data[j][qwerty[i].second] << " ";
            cyphered[i][j] = data[j][qwerty[i].second];
        }
        cout << endl;
    }
    return 0;
}
