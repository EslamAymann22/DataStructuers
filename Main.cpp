// DataSrucures.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;
int main()
{
    LinkedList a;
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.display(); cout << '\n';
    a.erase_back();
    a.insert(9);
    a.insert(8, 2);
    a.display(); cout << '\n';
    a.erase();
    a.display(); cout << '\n';
    a.erase(3);
    a.display(); cout << '\n';

    //cout << "\nES\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
