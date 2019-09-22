#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            // Caso vacío?
            return this->head->data;
        }

        T back() {
            // Caso vacío?
            return this->head->prev->data;
        }

        void push_front(T value) {
            auto node = new Node<T>;
            node->data=value;
            this->nodes++;
            if(this->head!=nullptr){
                auto last = this->head->prev;
                node->next = this->head;
                this->head = node;
                this->head->prev = last;
                last->next = this->head;
            }
            else{
                this->head = node;
                this->head->next = node;
                this->head->prev = node;
            }
        }

        void push_back(T value) {
            auto node = new Node<T>;
            node->data=value;
            this->nodes++;
            if(this->head!=nullptr){
                auto last = this->head->prev;
                node->next = this->head;
                this->head = node;
                this->head->prev = last;
                last->next = this->head;
                this->head->next->prev = this->head;
                this->head = this->head->next;
            }
            else{
                this->head = node;
                this->head->next = node;
                this->head->prev = node;
            }
        }

        void pop_front() {
            auto temp = this->head;
            this->head->prev->next = this->head->next;
            this->head->next->prev = this->head->prev;
            this->head = this->head->next;
            delete temp;
            this->nodes--;
        }

        void pop_back() {
            auto temp = this->head->prev;
            this->head->prev = this->head->prev->prev;
            this->head->prev->next = this->head;
            delete temp;
            this->nodes--;
        }

        T operator[](int index) {
            if(index<size()){
                auto temp = this->head;
                for(int i=0; i<index; i++){
                    temp = temp->next;
                }
                return temp->data;
            }
        }

        bool empty() {
            return this->nodes==0;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            while(this->nodes!=0){
                pop_front();
            }
        }

        void sort() {
            auto node = this->head->next;
            auto node2 = node;
            for(int i = 1; i<size(); i++){
                for(int j = i; j>0; j--){
                    if(node->data < node->prev->data){
                        T dataTemp = node->data;
                        node->data = node->prev->data;
                        node->prev->data = dataTemp;
                    }
                    node=node->prev;
                }
                node2 = node2->next;
                node = node2;
            }
        }

        void reverse() {
            if(this->nodes>1){
                Node<T>* anterior= this->head->prev;
                Node<T>* node= this->head;
                Node<T>* siguiente= node->next;
                for(int i=0;i<this->size();i++){
                    node->next=anterior;
                    node->prev=siguiente;
                    anterior=node;
                    node=siguiente;
                    siguiente=siguiente->next;}
                this->head=this->head->next;
            }
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T>(this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T>(this->head);
        }

        void merge(CircularLinkedList<T> list) {
            for(int i=0;i<list.size();i++){
                this->push_back(list[i]);
            }
        }
};

#endif