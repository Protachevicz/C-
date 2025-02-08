#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{   
    // int cont=0;

    // while (cont <= 1000) 
    //     {
    //         cout << cont << " ";
    //         cont++;
    //     }

    //     cout << endl;

    srand(time(0));
    int min = 0, max = 10;
    int random = (rand() % (max - min+1) + min);

    int choice, guesses=1;
    
    cout << "Qual o seu palpite? De 0 a 10: ";
    cin >> choice;

    //cout << random << endl;

    while (choice != random)
    {
        cout << "Voce errou" << endl;
        if(random > choice) cout << "Tente um numero maior! ";
        else cout << "Tente um numero menor! ";

        cout << "Faca o seu palpite novamente: ";
        cin >> choice;
        guesses++;
    }

    cout << "Voce acertou com " << guesses << " palpites" << endl;

    // int random = rand(1);

    return 0;
}
