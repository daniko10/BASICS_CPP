#include "Student.h"

void show(TStudent* head) {
    std::cout<<"Aktualny stan listy: "<<std::endl;

    if(!head) {
        std::cout<<"Lista jest pusta"<<std::endl;
        return;
    }

    for(; head ; head = head->_next )
        std::cout<<"id: "<<head->_id<<std::endl;
    std::cout<<std::endl;
    
    return;
}

TStudent* InitTStudent() {
    return new TStudent;
}

void push_front(TStudent** head , int id) {
    if(!*head) {
        *head = InitTStudent();
        (*head)->_id = id;
    }
    else {
        TStudent *temp = InitTStudent();
        temp->_id = id;
        temp->_next = *head;
        *head = temp;
    }

    return;
}

void clear(TStudent** head) {
    if(!*head)
        return;
    
    TStudent* temp = nullptr;
    while(*head) {
        temp = (*head)->_next;
        delete *head;
        *head = temp;
    }
}