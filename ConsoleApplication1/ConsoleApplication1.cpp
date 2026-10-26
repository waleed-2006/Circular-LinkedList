// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;


template <typename V>
class SNode {
public:
    V _value;
    SNode* _Next;
    template <typename V>
    friend class CLinkedList;


    SNode() {
        _Next = nullptr;
    }
    SNode(const V & v) {
        _Next = nullptr;
        _value = v;
    }
 
};

template <typename V>
class CLinkedList {
private:
    SNode<V>* _cursor;
public:
    CLinkedList() {
        _cursor = NULL;
    }
    void add(const V& v) {
        SNode<V>* New = new SNode(v) ;
        if (_cursor == NULL) {
            New->_Next = New;
            _cursor = New;
            return;
        }
        New->_Next = _cursor->_Next;
        _cursor->_Next = New;
    }
    void remove() {
        if (_cursor == NULL) {
            return;
        }
        if (_cursor->_Next==_cursor) {
            delete _cursor->_Next;
            _cursor = NULL;
    
            return;
        }
        SNode<V>* old = _cursor->_Next;
        _cursor->_Next = old->_Next;
        delete old;
    }
    bool search(V elem) {
        SNode<V>* current = _cursor;
        SNode<V>* start = _cursor;
        while (current != NULL)  {
            if (elem == current->_value) {
                return true;
            }
            current = current->_Next;
            if (current == start) {
                break;
            }

        }
        return false;
    }

};
int main()
{
    std::cout << "Hello World!\n";
}

