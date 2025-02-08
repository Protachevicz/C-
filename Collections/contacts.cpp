#include <iostream>
#include <list>
#include <map>

using namespace std;

void show_menu()
{
cout << "============== Menu ================" << endl;
        cout << "1. Novo contato" << endl;
        cout << "2. Listar contatos" << endl;
        cout << "3. Remover contato" << endl;
        cout << "0. Sair" << endl;
}

void get_choice(int &choice)
{
   cout << "> ";
   cin >> choice;
}

void add_contact(list<map<string,string>> &contacts)
{
string name, email, phone;

cin.ignore();

cout << "Nome: ";
getline(cin, name);
cout << "Email ";
getline(cin, email);
cout << "Telefone: ";
getline(cin, phone);

map<string, string> contact;
contact["name"] = name;
contact["email"] = email;
contact["phone"] = phone;

contacts.push_back(contact);

}

void list_contacts(list<map<string,string>> contacts)
{
    for(map<string,string> contact : contacts)
    {
        cout << contact["name"] << ", " << contact["email"] << ", " << contact ["phone"] << endl;
    }
}

void remove_contact(list<map<string, string>> &contacts)
{
string name;
bool found = false;
cin.ignore();

cout << "Nome: ";

getline(cin, name);
for(map<string, string> contact : contacts)
{
if(contact["name"] == name)   {
    found = true;
    contacts.remove(contact);
    break;
} 
}

string message = found ? "Contato Removido": "Contato nao encontrado";
cout << message << endl;
}


int main (int argc, char const *argv[])
{
    int choice =0;
    list<map<string,string>> contacts;

    do
    {
        show_menu();
        get_choice(choice);

        switch(choice)
        {
        case 1:
            //cout << "Funcionalidade de adicionar contato" << endl;
            add_contact(contacts);
            break;
        case 2:
            //cout << "Funcionalidade de listar contatos" << endl;
            list_contacts(contacts);
            break;
        case 3:
            //cout << "Funcionalidade de remover contatos" << endl;
            remove_contact(contacts);
            break;
        case 0:
            cout << "Ate mais, e obrigado pelos peixes" << endl;
            break;
        default:
            cout << "Opcao Invalida" << endl;
        }

        cout << endl;
        cout << "Opcao Selecionada: " << choice << endl;


    } while(choice !=0);

    return 0;
}
