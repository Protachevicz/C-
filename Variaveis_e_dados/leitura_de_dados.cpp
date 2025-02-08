#include <iostream>

using namespace std;

int main (int argc, char const *arg[])
{
int x, y;
cout << "Primeiro valor:";
cin >> x;
cout << "Segundo valor:";
cin >> y;

int sum = x + y;
cout << "Soma: " << sum << endl;

string name;
cin >> name;

cout << name << endl;

cin.ignore();

getline(cin,name);
cout << name << endl;

return 0;
}
