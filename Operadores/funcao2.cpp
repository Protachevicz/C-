#include <iostream>

using namespace std;

void greeting(string name);
void sum(int a, int b);
void sum(double a, double b);

int main(int argc, char const *argv[])
{
    greeting("Paulo");
    greeting("Ricardo");
    greeting("Protachevicz");
    sum (10,20);

    sum (10.666, 17.1111);

    return 0;
}

void sum(int a, int b)
{
int result = a + b;
cout << result << endl;
}

void sum(double a, double b)
{
double result = a + b;
cout << result << endl;
}


void greeting(string name)
{
    cout << "Ola, " << name << " Mundo" << endl;
}