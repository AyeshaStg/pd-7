#include <iostream>
using namespace std;
int triangularNumber(int n) 
{
    return (n * (n + 1)) / 2;
}
int main()
{
int n;
cout << "Enter the  number of triangle: ";
cin >> n;
cout << "dots in the triangle: "<<triangularNumber(n) << endl;
return 0;
}
