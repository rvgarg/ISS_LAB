#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    map<char, int> freq;
    cout << "enter cypher text: ";
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        freq[str.at(i)]++;
    }

    

    for (map<char, int>::iterator i = freq.begin(); i != freq.end(); i++)
    {
        cout << i->first << " : " << i->second << endl;
    }
    
}