#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int age;
    cin >> age;

    if (age >=18)
        {
        cout << "Voce e maior de idade!" << endl;
        }
    else if (age>=16)
        cout << "Voce e menor de idade mas pode votar" << endl;
    else 
        cout << "Voce e menor de idade!" << endl;

    cout << "Fim do Programa!" << endl;

    int time;
    cin >> time;
    string message = (time < 12) ? "Bom dia": "Boa tarde";
    // if (time < 10)
    //     message = "Bom dia";
    // else
    //     message = "Boa tarde";

    cout << message << endl;

    cout << "Fim do programa" << endl;


    return 0;
}
