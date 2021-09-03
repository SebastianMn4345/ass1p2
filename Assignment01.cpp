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

    LL<int>::iterator nil(NULL);

    ifstream inFile;

    inFile.open(argv[1]);

    int val;
    
    if(!inFile)
    {
        cout << "Error opening file" << endl;
        return 0;
    }

    while(inFile >> val)
    {
        list1.tailInsert(val);
    }

    for(it = list1.begin(); it != NULL; it++)
    {
        cout << *it << endl;
    }
    cout << "Now begin the sort" << endl;

    //time to start the selection sort....
    LL<int>::iterator i, j;
    LL<int>::iterator maxPos;
    int max;

    j = nil;

    for(i = list1.begin(); i != j; j--)     //we are going to set j to a new node
    {
        max = *i;
        maxPos = i;
        i++;
        cout << "this is j" << *j << endl;
        while(i != j)
        {
            if(max < *i)
            {
                max = *i;
                maxPos = i;//update the max and maxPos, maxPos poits ot nod ewith the biggest value
            }
            i++;    //once i = j, we found the max element
            if(i == j)
            {
                if(*j < *i)
                {
                    max = *j;
                    maxPos = j;
                }
            }
        }
        //since j might be the last max element

        //j MIGHT contain the max element if it is not the end of the list.
        if(j == nil)
        {
            j = list1.end();    //now that j is the rightmost element (the first loop its going to be nil); swap that with the maxPos.
            list1.swapNodes(maxPos, j);
            j = list1.end();
        }
        else
        {
            if(*j < *maxPos)
            {
                list1.swapNodes(maxPos, j);
                LL<int>::iterator temp;
                temp = maxPos;
                j = maxPos;
                maxPos = j;
            }
            //list1.swapNodes(maxPos, j);
            else
            {

            }
            
        }
        i = list1.begin();
    }
    
    i = list1.begin();
    j = list1.begin();
    j++;
    if(*i > *j)
    {
        list1.swapNodes(i, j);
    }

    for(it = list1.begin(); it != NULL; it++)
    {
        cout << *it << endl;
    }

    /*
    list1.tailInsert(1);
    list1.tailInsert(2);
    list1.tailInsert(3);
    list1.tailInsert(4);
    list1.tailInsert(5);
    list1.tailInsert(6);
    list1.tailInsert(7);
    list1.tailInsert(8);
    list1.tailInsert(9);
    list1.tailInsert(10);

    LL<int>::iterator i;

    for(i = list1.begin(); i != NULL; i++)
    {
        cout << *i << endl;
    }

    LL<int>::iterator it1;
    LL<int>::iterator it2;

    it1 = list1.begin();
    it1++;
    it1++;
    it1++;
    it1++;
    it1++;
    cout << "testing OG it1... " << *it1 << endl;

    //testing when they are adjacent DONT FORGET TO CHANGE
    it2 = list1.end();
    it2--;
    it2--;
    //it2++;
    //it2++;
    cout << "testing OG it2... " << *it2 << endl;

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
*/





    return 1;
}