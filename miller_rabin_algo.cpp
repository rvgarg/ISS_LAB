#include <bits/stdc++.h>
using namespace std;

int po(int x, unsigned int y, int mod)
{
    int result = 1;
    x %= mod;
    while (y > 0)
    {
        if (y & 1)
        {
            result = (result * x) % mod;
        }
        y = y >> 1;
        x = (x * x) % mod;
    }
    return result;
}

bool miillerTest(int d, int n)
{
    int a = 2 + rand() % (n - 4);

    int x = po(a, d, n);

    if (x == 1 || x == n - 1)
        return true;

    while (d != n - 1)
    {
        x = (x * x) % n;
        d *= 2;

        if (x == 1)
            return false;
        if (x == n - 1)
            return true;
    }

    return false;
}

bool isPrime(int n, int k)
{
    if (n <= 1 || n == 4)
        return false;
    if (n <= 3)
        return true;

    int d = n - 1;
    while (d % 2 == 0)
        d /= 2;

    for (int i = 0; i < k; i++)
        if (!miillerTest(d, n))
            return false;

    return true;
}

int main()
{
    int numofiteraons, num;
    cout << "enter number of iterations ";
    cin >> numofiteraons;
    cout << "enter a number ";
    cin >> num;
    for (int i = 0; i < num; i++)
    {
        if (isPrime(i, numofiteraons))
            cout << i << " ";
    }
    return 0;
}