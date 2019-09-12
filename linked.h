#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "iterators/bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
        LinkedList() : List<T>() {}

        T front() {
            return this->head->data;
        }

        T back() {
            return this->tail->data;
        }

        void push_front(T value) {
            auto node = new Node<T>;
            node->data = value;
            if(this->head!=nullptr){
                node->next = this->head;
                this->head = node;
                node->next->prev = node;
            }
            else{
                this->head = node;
                this->tail = node;
            }
            this->nodes++;
        }

        void push_back(T value) {
            auto node = new Node<T>;
            node->data = value;
            if(this->head!=nullptr){
                node->prev = this->tail;
                this->tail = node;
                node->prev->next = node;
            }
            else{
                this->head = node;
                this->tail = node;
            }
            this->nodes++;
        }

        void pop_front() {
            auto temp = this->head;
            if(this->head->next != nullptr){
                this->head = this->head->next;
            }
            delete temp;
            this->nodes--;
        }

        void pop_back() {
            auto temp = this->tail;
            if(this->tail->prev != nullptr){
                this->tail = this->tail->prev;
            }
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
            while(this->nodes != 0){
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
            auto node1 = this->head;
            auto node2 = this->tail;
            for(int i=0; i<size()/2; i++){
                T dataTemp = node1->data;
                node1->data = node2->data;
                node2->data = dataTemp;
                node1=node1->next;
                node2=node2->prev;
            }
        }

        string name() {
            return "Linked List";
        }

        BidirectionalIterator<T> begin() {
            return BidirectionalIterator<T> (this->head);
        }

	    BidirectionalIterator<T> end() {
            return BidirectionalIterator<T> (this->tail->next);
        }

        void merge(LinkedList<T> list) {
            for(int i=0;i<list.size();i++){
                this->push_back(list[i]);
            }
        }
};

#endif