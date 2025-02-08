#include <iostream>

using namespace std;

int main (int argc, char const *argv[])
{
    //string names[4];

    // names[0] = "Cleyson";
    // names[1] = "Elton";
    // names[2] = "Amauri";
    // names[3] = "Wesley";

    string names[] = {"Cleyson", "Elton","Amauri", "Wesley"};

   // for(int i=0;i<4;i++) cout << names[i] << endl;

   for (string name: names)
        {
            cout << name << endl;
        }

    // cout << names[0] << endl;
    // cout << names[1] << endl;
    // cout << names[2] << endl;
    // cout << names[3] << endl;

    return 0;
}
