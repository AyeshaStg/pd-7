#include <iostream>
using namespace std;
bool isPrime(int number)
{
 if (number <= 1)
   return 0;
 if (number == 2)
   return 1;
 if (number % 2 == 0) 
   return 0;
for (int i = 3; i * i <= number; i += 2)
    {
      if (number % i == 0)
     {
            return 0; 
      }
    }

    return 1;
}

int main()
{
int num;
cout << "Enter a number: ";
cin >> num;
if (isPrime(num))
 {
   cout <<"1"<< endl;
 }
 else
  {
   cout <<"0" << endl;
  }

return 0;
}
