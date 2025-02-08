#include <iostream>

using namespace std;

int main (int argc, char const *arg[])
{
// int
int i=50;
cout << i << endl;
cout << sizeof(i) << endl;

//long int
long int j=50;
cout << j << endl;
cout << sizeof(j) << endl;

//short int
short int k=50;
cout << k << endl;
cout << sizeof(k) << endl;

//float
float f = 10.5;
cout << f << endl;
cout << sizeof(f) << endl;

//double
double d = 345.2387234;
cout << d << endl;
cout << sizeof(d) << endl;

//char
char c = 'c';
cout << c << endl;
cout << sizeof(c) << endl;

//string
string s = "Paulo Ricardo Protachevicz";
cout << s << endl;
cout << sizeof(s) << endl;

//boolean
bool b = false;
cout << b << endl;
cout << sizeof(b) << endl;

//unsigned 0 - 4,294,967,295
unsigned int u = 20;
cout << u << endl;
cout << sizeof(u) << endl;

return 0;
}
