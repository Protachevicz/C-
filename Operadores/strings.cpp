#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    string s = "Ola, Mundo";
    // cout << s << endl;
    // cout << s[0] << endl;
    // cout << s[6] << endl;
    // cout << s[2] << endl;
    // cout << s[3] << endl;

    // s.at(0) = 'o';
    // cout << s.at(0) << endl;

    // // lengh
    // cout << s.length() << endl;
    // cout << s.size() << endl;

    // cout << s.empty() << endl;

    // s.clear();   /// limpa a string s
    // cout << s << endl;
    // cout << s.empty() << endl;  /// Pertunta se a string s esta vazia

    cout << s.substr(5,6) << endl;

    cout << s.find("M") << endl;
    cout << s.substr(s.find("M"), s.size()-1) << endl;

    s.replace(5,5,"Treina Web");

    cout << s << endl;

    //s.insert(s.size(), "!");
    s.append("!");
    cout << s << endl;

    s.erase(3);

    string s2 = "Teste";
    string s3 = "Teste2";

    cout << (s2 == s3) << endl;
    cout << s2.compare(s3) << endl;


    return 0;
}