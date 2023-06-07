#include <iostream>
#include <vector>

using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    cout << "Enter an integer ";
    int n;
    cin >> n;
    cout << "\nThe factorial of " << n << " is " << factorial(n) << endl;
}
