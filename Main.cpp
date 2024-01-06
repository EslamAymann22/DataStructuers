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
    a.display(); cout << '\n';
    a.reverse(1, 2);
    //a.display(); cout << '\n';

}
