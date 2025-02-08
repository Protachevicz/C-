#include <iostream>
#include <map>

using namespace std;

int main (int argc, char const *argv[])
{
   map<string, string> contact;

//    contact["name"] = "Cleyson Lima";
//    contact["email"] = "cleyson@gmail.com";

//    cout << contact ["name"] << endl;
//    cout << contact ["email"] << endl;

//    contact["name"] = "Cleyson";

//    cout << contact["name"] << endl;
//    cout << contact["email"] << endl;

contact.insert(make_pair("name","Cleyson Lima"));
contact.insert(make_pair("name","Cleyson"));  /// nao funciona para substituir elementos
contact.insert(make_pair("email","cleyson@gmail.com"));

//cout << contact["name"] << endl;

map<string, string>::iterator it;
for(it = contact.begin(); it != contact.end(); it++)
{
    cout << "Key: " << it->first << " ";
    cout << "Value: " << it->second << endl;
}
    

    return 0;
}
