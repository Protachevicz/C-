#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string first_name,midle_name,last_name;

    cout << "Primeiro nome: ";
    cin >> first_name;
    cout << "Nome do meio: ";
    cin >> midle_name;
    cout << "Sobrenome: ";
    cin >> last_name;

    string full_name = first_name + " " + midle_name + " " + last_name;
    cout << "Nome Completo: " << full_name << endl;
    
    string full_name2 = first_name.append(" ").append(midle_name).append(" ").append(last_name);
    cout << "Nome Completo 2: " <<  full_name2 << endl;

    return 0;
}