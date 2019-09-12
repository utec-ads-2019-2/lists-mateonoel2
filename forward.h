#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
        ForwardList() : List<T>() {}

        T front() {
            if(this->head != nullptr){
             return this->head->data;
            }
            throw out_of_range("This list is empty");
        }

        T back() {
            if(this->tail != nullptr){
                return this->tail->data;
            }
            throw out_of_range("This list is empty");
        }

        void push_front(T value) {
            auto node = new Node<T>;
            node->data=value;
            this->nodes++;
            if(this->head!=nullptr){
                node->next = this->head;
                this->head = node;
            }
            else{
                this->tail = node;
                this->head = node;
            }
        }

        void push_back(T value) {
            auto node = new Node<T>;
            node->data=value;
            this->nodes++;
            if(this->head!=nullptr){
                this->tail->next = node;
                this->tail = node;
            }
            else{
                this->tail = node;
                this->head = node;
            }
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
            auto node = this->head;
            while(node->next!=this->tail){
                node = node->next;
            }
            delete temp;
            this->tail = node;
            this->nodes--;
        }

        T operator[](int index) {
            if(index < size()){
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
            while(this->nodes>0){
                pop_front();
            }
        }

        void sort() {
            for(int j=0; j<size()-1; j++){
                auto node = this->head;
                for(int i=0; i<size()-j-1; i++){
                    if(node->data > node->next->data){
                        T dataTemp = node->data;
                        node->data = node->next->data;
                        node->next->data = dataTemp;
                    }
                    node = node->next;
                }
            }
        }
    
        void reverse() {
            auto node1 = this->head;
            auto node2 = this->tail;
            for(int i = 0;i<size()/2;i++){
                T Data_temp = node1->data;
                node1->data = node2->data;
                node2->data = Data_temp;

                auto node_temp = node1;
                while(node_temp->next!=node2){
                    node_temp = node_temp->next;
                }
                node2 = node_temp;

                node1 = node1->next;
            }
        }

        string name() {
            return "Forward List";
        }

        ForwardIterator<T> begin() {
            return ForwardIterator<T> (this->head);
        }

	    ForwardIterator<T> end() {
            return ForwardIterator<T> (this->tail->next);
        }

        void merge(ForwardList<T> list) {
            for(int i=0;i<list.size();i++){
                this->push_back(list[i]);
            }
        }
};

#endif