#include <iostream>


using namespace std;

int main(int argc, char const *argv[])
{
    //Conjuncao - E logico - && 
    cout << "Conjuncao" << endl;
    cout << (true && true) << endl;
    cout << (true && false) << endl;
    cout << (false && true) << endl;
    cout << (false && false) << endl;

    //Conjuncao - Ou Logico -  ||
    cout << "Disjuncao" << endl;
    cout << (true || true) << endl;
    cout << (true || false) << endl;
    cout << (false || true) << endl;
    cout << (false || false) << endl;

    // Conjucao - Nao logico
    cout << "Negacao" << endl;
    cout << (!true) << endl;
    cout << (!false) << endl;

    return 0;
}
