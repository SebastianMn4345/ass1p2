//Ararat Mesrobian
//Assignment 01
//CS302
#include "Assignment01.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char * argv[])
{
    LL<int> list1;

    LL<int>::iterator it;

    LL<int>::iterator end(NULL);

    ifstream inFile;

    inFile.open(argv[1]);

    int val;
    
    list1.tailInsert(1);
    //list1.tailInsert(2);
    //list1.tailInsert(3);
    list1.tailInsert(4);

    LL<int>::iterator i;

    for(i = list1.begin(); i != NULL; i++)
    {
        cout << *i << endl;
    }

    LL<int>::iterator it1;
    LL<int>::iterator it2;

    it1 = list1.begin();
    //it1++;
    LL<int>::iterator testit1;

    it2 = list1.end();
    //it2--;

    list1.swapNodes(it1, it2);

    LL<int>::iterator looping;

    cout << "now looping after swapping the nodes" << endl;

    for(looping = list1.begin(); looping != NULL; looping++)
    {
        cout << *looping << endl;
    }

    looping = list1.begin();

    cout << "testing the new head + 1" << endl;
    looping++;
    cout << *looping << endl;

    cout << "holy shit now were gonna try the opposite way" << endl;

    cout << "testing the end - 2" << endl;
    looping = list1.end();
    looping--;
    looping--;
    cout << *looping << endl;

    return 1;
}
