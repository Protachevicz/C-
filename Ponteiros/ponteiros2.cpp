#include <iostream>

using namespace std;

// void change_value(int a)
// {
// a=10;
// }

void change_value(int &a)
{
a=10;
}



int main(int argc, char const *argv[])
{
    int a = 1;

    cout << a << endl;

    change_value(a);

    cout << a << endl;

    return 0;
}


