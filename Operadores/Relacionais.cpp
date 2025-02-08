#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    int a = 5, b = 10;

    // Igual
    cout << (a == b) << endl;  // Saida é um valor booleano 0 = Falso e 1 = Verdadeiro

    // Diferente
    cout << (a != b) << endl;

    // Maior que 
    cout << (a > b) << endl;

    // Menor que 
    cout << (a < b) << endl;

    //Maior ou igual
    cout << (a >= b) << endl;

    //Menor ou igual
    cout << (a <= b) << endl;

    return 0;
}
