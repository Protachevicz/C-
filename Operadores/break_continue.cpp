#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    // for (int i =0; i<= 100; i++)
    // {
    // if(i % 10 == 0)
    // {continue;}
    // cout << i << " ";
    // }

        for (int i =0; i<= 100; i++)
    {
    if(i % 10 == 17) break;
  
    cout << i << " ";
    }

    return 0;
}
