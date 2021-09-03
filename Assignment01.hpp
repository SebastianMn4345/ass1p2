//Header file for Assignment 1 
//This will hold the class as well as the function definitions for all of the member functions
//created by Ararat Sebastian Mesrobian
//8/23/2021

//Linked List class - templated class
#ifndef ASSIGNMENT01_HPP
#define ASSIGNMENT01_HPP


#include <iostream>
using namespace std;

template <typename type>
class LL
{
    //A struct that will have the node object, and its members. A node will hold a block of data, and the prev and next pointers will point to other nodes
    struct node
    {
        type data;
        node * prev;
        node * next;
    };

    //the iterator will be used to traverse and manipulate the linked list. it allows the user to not be able to manipulate pointers in main, which is why LL is a friend class
    //the iter
    public:
        class iterator
        {
            public:
                friend class LL;
                iterator();
                iterator(node*);
                type operator*() const;
                const iterator& operator++(int);
                const iterator& operator--(int);
                bool operator==(const iterator&) const;
                bool operator!=(const iterator&) const;
            private:
                node * current;
        };

    LL();
    LL(const LL<type>&);
    const LL<type>& operator=(const LL<type>&);
    ~LL();

    void headInsert(const type&);
    void tailInsert(const type&);
    iterator begin() const;
    iterator end() const;
    void swapNodes(iterator&, iterator&);

    private:
        node * head;
        node * tail;

};

/*Begin definitions of all functions, this will follow the layout as it is on the Assignment pdf*/

//default constructor for iterator
template <typename type>
LL<type>::iterator::iterator()
{
    current = NULL;
}

template <typename type>
LL<type>::iterator::iterator(node * ptr)
{
    current = ptr;
}

template <typename type>
type LL<type>::iterator::operator*() const
{
    if(*this != NULL)
    {
        return current -> data;
    }
    else 
    {
        return 0;
    }
}

//moves the iterator a node to the right
//make sure to check if we are at the end
template <typename type>
const typename LL<type>::iterator& LL<type>::iterator::operator++(int)
{
    if(current -> next != NULL)
    {
        current = current -> next;
    }
    else
    {
        //cout << "Current Node is already at the end!" << endl;
        *this = NULL;
        return *this;
    }
    return *this;
}

//moves iterator one node to the left
//check if we are already at the beggining
template <typename type>
const typename LL<type>::iterator& LL<type>::iterator::operator--(int)
{
    if(current -> prev != NULL)
    {
        current = current -> prev;
        //return current;
    }
    else
    {
        //cout << "Current Node is already at the beginning" << endl;
        *this = NULL;
        return *this;
    }
    return *this;
}

template <typename type>
bool LL<type>::iterator::operator==(const iterator& rhs) const
{
    if(rhs.current == this -> current)
    {
        cout << "rhs is pointing to the same node" << endl;
        return 1;
    }
    else 
    {
        return 0;
    }
}

template <typename type>
bool LL<type>::iterator::operator!=(const iterator& rhs) const
{
    //rhs.current;

    if(rhs.current != this -> current)
    {
        return 1;
    }
    else 
    {
        return 0;
    }

    return 1;
}

//now we are defining the functions of the LL class, not the iterator
//================================================================================================================
template <typename type>
LL<type>::LL()
{
    head = NULL;
    tail = NULL;
}

template <typename type>
LL<type>::LL(const LL<type>& copy)
{
    this = new LL;

    this -> head = copy -> head;
    copy = copy -> head;

    while(copy -> next != nullptr)
    {
        this -> next = copy -> next;
        copy = copy -> next;
        this = this -> next;
    }

    this -> tail = copy -> tail;

    copy = copy -> head;
    copy -> head = NULL;

    while(copy -> next != NULL)
    {
        copy -> next = NULL;
        copy = copy -> next;
    }
    copy = NULL;
}

 template <typename type>
const LL<type>& LL<type>::operator=(const LL<type>& rhs)
{
    if(&rhs != this)
    {
        while(this -> current != NULL)
        {
            this -> current = NULL;
            delete this -> current;
            this = this -> next;
        }
        this -> next = NULL;
        this -> head = NULL;
        delete this -> head;
        //this -> tail = NULL;

        //head = rhs -> head;

        while(rhs -> next != NULL)
        {
            this = rhs -> next;
            rhs = rhs -> next;
        } 
        return *this;
    }
}

template <typename type>
LL<type>::~LL()
{
    node * curr;

    while(head != NULL)
    {
        curr = head;

        head = head -> next;

        delete curr;
    }
    //curr = NULL;
    tail = NULL;
    delete tail;
    //delete tail;
}



template <typename type> 
void LL<type>::headInsert(const type& item)
{
    node * headNode = new node;

    if(head == NULL && tail == NULL)
    {
        headNode -> data = item;
        head = headNode;
        tail = headNode;
        headNode -> prev = NULL;
        headNode -> next = NULL;
    }
    else
    {
        headNode -> data = item;

        head -> prev = headNode;

        headNode -> next = head;

        headNode -> prev = NULL;

        head = headNode;
    }

    
}

//create new node
//this node will take item as its data
//insert this node at the very end
//to do this, tail must be pushed to previous 
//this new node's previous will be pointing to the old "tail"
//the next will be pointing to NULL to signify it is the end
template <typename type> 
void LL<type>::tailInsert(const type& item)
{
    node * tailNode = new node;

    if(head == NULL && tail == NULL)
    {
        tailNode -> data = item;
        head = tailNode;
        tail = tailNode;
        tailNode -> next = NULL;
        tailNode -> prev = NULL;
    }
    else
    {
        tailNode -> data = item;

        tail -> next = tailNode;

        tailNode -> prev = tail; //Now, the last element "tail", who's next points to NULL, will now instead point to the new headNode

        tailNode -> next = NULL; 

        tail = tailNode;
    }

    
}

template <typename type>
typename LL<type>::iterator LL<type>::begin() const
{
    iterator * curr = new iterator;
    curr -> current = head;         
    return *curr;
}

template <typename type>
typename LL<type>::iterator LL<type>::end() const
{
    iterator * curr = new iterator;
    curr -> current = tail;
    return *curr;
}


//hardest part (maybe)
//swap the LOCATION, not the data field itself
//so, by location, need to swap the previous, and the next, and the currents.
//Also make sure to account for all cases
//First case we can account for
//if the prev and/or next of the parameters are NULL
//which makes either or the head/tail.
//simply change the prev/next to NULL so that they are the "head" or "tail"
//CANNOT ACCESS STUFF THAT IS NULL
//-----------------------------------------------------------------------
//If they are adjacent
//if theyre next to eachother then, respectively, their next and prev pointers will point to eachother
//account for this, you will have to swap these
//as well as swap the PREV and NEXT
//-----------------------------------------------------------------------

template <typename type>
void LL<type>::swapNodes(iterator& it1, iterator& it2)
{
    
    node * iter1 = it1.current;
    node * iter2 = it2.current;
    node * iter1_left = iter1 -> prev;
    node * iter1_next = iter1 -> next;
    node * iter2_left = iter2 -> prev;
    node * iter2_next = iter2 -> next;
    
    if((iter1_left == NULL) && (iter2_next == NULL) && (iter1_next != iter2))
    {
        cout << "inside this case 1" << endl;
        node * temp;
        temp = iter1_next;
        //cout << "inside swap nodes" << " testing iter1next " << iter1_next -> data << endl;
        iter1_next = iter2_next;
        iter2_next = temp;
        //iter2_prev -> next needs to point to iter2
        temp = iter1_left;
        iter1_left = iter2_left;
        iter2_left = temp;

        iter1_left -> next = iter1;
        iter2_next -> prev = iter2;


        //swapping the head and the tail
        head = it2.current;
        tail = it1.current;
        //s============================
        head -> prev = NULL;
        head -> next = iter2_next;
        tail -> prev = iter1_left;
        tail -> next = NULL;
        //=========================
    }  
    else if((iter1_next == iter2) && (iter2_left == iter1))
    {
        cout << "inside this case 2" << endl;
        node * temp;

        iter2_next = iter1;
        iter1_left = iter2;

        //iter2_left -> prev = iter2;
        //iter1_next -> next = iter1;

        if(iter2_next -> prev == NULL && iter1_left -> next == NULL)
        {
            iter1_next = NULL;
            iter2_left = NULL;

            head = iter2;
            tail = iter1;
            tail -> next = NULL;
            head -> prev = NULL;
            tail -> prev = head;
            head -> next = tail;
        }
        else if(iter2_next != NULL)
        {
            



        }
    }
   
    



    return;
}



#endif