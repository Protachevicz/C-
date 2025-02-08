#include <iostream>

using namespace std;

int main (int argc, char const *arg[])
{
int age = 25;
cout << age << endl;
age = 30;
cout << age << endl;

const int age2=30;
cout << age2 << endl;

age2=32;
cout << age2 << endl;

return 0;
}
