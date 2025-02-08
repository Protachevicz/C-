#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 20;

    //Soma
    int sum = a + b;
    cout << sum << endl;

    //Subtracao
    int sub = a - b;
    cout << sub << endl;

    //Multiplicacao
    int mul = a * b;
    cout << mul << endl;

    //Divisao
    double div = a / double(b) ; 
    cout << div << endl;

    //Modulo
    int mod = a / b;
    cout << mod << endl;

    //Incremento
    a++;
    cout << a << endl;

    // Decremento
    a--;
    cout << a << endl;

    cout << a++ << endl;
    cout << ++a << endl;

    cout << a-- << endl;
    cout << --a << endl;

    return 0;
}