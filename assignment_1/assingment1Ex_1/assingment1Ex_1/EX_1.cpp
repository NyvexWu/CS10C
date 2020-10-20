// assingment1Ex_1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//Exercise 1 A
#include <iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
    vector<string> polyno;
    string poly;
    cout << "Enter a polynomial: " << endl;
    getline(cin, poly);
    //get rid of space in polynomial
    for (int i = 0; i < poly.length(); i++)
    {
        if(poly.at(i) == ' ')
        {
            for (int j = i; j < poly.length(); j++)
            {
                poly.at(j) = poly.at(j + 1);
            }  
        }
    }
    //input numbers into vectors
    for (int i = 0; i < poly.length(); i++)
    {
        for (int j = 0; i < poly.length(); i++)
        {
            if (poly.at(j) != '+' || poly.at(j) != '-')
            {
            }
            else {
                for (int k = i; k < j-1; k++)
                {
                    polyno[i] = polyno[i] + poly.at(k);
                }
            }
        }
    }
    //checking for valid
    for (int i = 1; i < poly.length(); i++)
    {
        if (poly[i] == 'n')
        {
            if (poly[i - 1] == '*')
            {
                cout << "valid" << endl;
            }
            else {
                cout << "invalid" << endl;
            }
        }
    }
    //find the biggest power
    for (int i = 0; i < poly.length(); i++)
    {
        int exp = 0;
        if (poly.at(i) == '^')
        {
            int expo = stoi(polyno[i + 1]);
            if (exp < expo)
            {
                exp = expo;
            }
        }
        cout << "O(n^" << exp << ")"<< endl;
    }
}
//B
//the complexity will be depend on m since the complexity is depends on the expononets

//c
int main()
{
    vector<string> polyno;
    string poly;
    cout << "Enter a polynomial: " << endl;
    getline(cin, poly);
    //get rid of space in polynomial
    for (int i = 0; i < poly.length(); i++)
    {
        if (poly.at(i) == ' ')
        {
            for (int j = i; j < poly.length(); j++)
            {
                poly.at(j) = poly.at(j + 1);
            }
        }
    }
    //input numbers into vectors
    for (int i = 0; i < poly.length(); i++)
    {
        for (int j = 0; i < poly.length(); i++)
        {
            if (poly.at(j) != '+' || poly.at(j) != '-')
            {
            }
            else {
                for (int k = i; k < j - 1; k++)
                {
                    polyno[i] = polyno[i] + poly.at(k);
                }
            }
        }
    }
    //checking for valid
    for (int i = 1; i < poly.length(); i++)
    {
        if (poly[i] == 'n')
        {
            if (poly[i - 1] == '*')
            {
                cout << "valid" << endl;
            }
            else {
                cout << "invalid" << endl;
            }
        }
    }
    //find the biggest power
    for (int i = 0; i < poly.length(); i++)
    {
        int exp = 0;
        if (poly.at(i) == '^')
        {
            int expo = stoi(polyno[i + 1]);
            if (exp < expo)
            {
                exp = expo;
            }
        }
        cout << "O(n^" << exp << ")" << endl;
    }
    //checking if there's more than 1 of the same degree
    for (int i = 0; i < poly.length(); i++)
    {
        int exp = 0;
        if (poly.at(i) == '^')
        {
            int expo = stoi(polyno[i + 1]);
            if (exp == expo)
            {
                exp = expo;
            }
        }
        cout << "theres more than one of the same degree" << endl;
    }
}