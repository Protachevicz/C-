#include <iostream>

using namespace std;

int main (int argc, char const *arg[])
{
double d1 = 10.5;
int i1 = (int)d1;

int i2=5;
double d2 = (double)i2;

cout << i1 << endl;
cout << d2 << endl;

int i3 = int (d1);
double d3 = double(i2);

cout << i3 << endl;
cout << d3 << endl;

string s1 = "123";
string s2 = "123.456";

int i4 = stoi(s1);
double d4 = stod(s2);

cout << i4 << endl;
cout << d4 << endl;
}
