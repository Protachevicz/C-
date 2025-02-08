#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string name = "Cleyson";

    cout << name << endl;
    cout << &name << endl;
    
    string *ptr = &name;  //// *ptr = valor do ponteiro
    cout << ptr << endl;   //// ptr = o endereço guardado pelo ponteiro que armazena o valor *ptr
    cout << *ptr << endl;

    *ptr = "Cleyson Lima";

    name = "Cleyson Lima 2";

    cout << *ptr << endl;
    cout << name << endl;




    return 0;
}


