// lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include "LinkedList.h"
#include <cctype>
using namespace std;

string removePunctuation(string line);
void addValues(LinkedList*& myList,string line);

int main()
{
    ifstream fin("input1.txt");
    ofstream fout("output1.txt");

    LinkedList* myList = new LinkedList;

 
    string line; int lineCount = 0;

    while (getline(fin, line)) {

        cout << "We are on line " << lineCount << endl;  cout << line << endl;
        line = removePunctuation(line);
        cout << "Line " << lineCount << " with removed punctuation and uppercased letters:" << endl; cout << line << endl;
        lineCount++;

        //add to linked list--- add to count if found in linked list
        addValues(myList, line);

    }
    myList->Print(cout);
    myList->InsertionSort();
    cout << "Insertion Sorted... " << endl;
    myList->Print(cout);

    return 0;
}

void addValues(LinkedList*& myList,string line) {
    string tempData;
    for (int i = 0; i < line.size();i++) {
        if ((line[i] == ' ')) {
            myList->Search(tempData);
            tempData.clear();
        }
        else if (i == (line.size() - 1)) {
            tempData += line[i];
            myList->Search(tempData);
            tempData.clear();
        }
        else {
            tempData += line[i];
        }
    }
}

string removePunctuation(string line) {
    string result;
    for (int i = 0; i < line.size();i++) {
        if (line[i] == ' ' || line[i] == '-' || line[i] == '\'') { //appropriate punctuation
            result += line[i];
        }
        else if (isalpha(line[i])) {
                result += toupper(line[i]); //add uppercased version to result
            }
        else {
            cout << "NOT CHAR ON index " << i << " " << line[i] << endl;
        }
    }
    return result;
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
