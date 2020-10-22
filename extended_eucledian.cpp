#include <bits/stdc++.h>
using namespace std;

int extended(int a, int b, int *x, int *y)
{
    if (a == 0)
    {
        *x = 0;
        *y = 1;

        return b;
    }

    int x1, y1;
    int gc = extended(b % a, b, &x1, &y1);
    cout << gc;
    *x = y1 - (b / a) * x1;
    *y = x1;
    return gc;
}

int main()
{
    int x, y, a, b, gc;
    cout << "enter values for which you want to find gcd ";
    cin >> a >> b;
    if (a > b)
        gc = extended(a, b, &x, &y);
    else
        gc = extended(b, a, &x, & y);
    cout << "GCD(" << a << "," << b << ") = " << gc << endl;
    cout << "x = " << x << endl;
    cout << "y = " << y;
}