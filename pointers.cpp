#include <iostream>
using namespace std;

class Node{
    public:
        Node(){
         SetData(0);
         SetNext(nullptr);
        }
        Node(int data, Node *next){
            SetData(data);
            SetNext(next);
        }
        int GetData(){ return m_data; }
        Node* GetNext(){ return m_next; }
        void SetData(int data){ m_data = data; }
        void SetNext(Node *next){ m_next = next; }

    
    
    private:
        int m_data;
        Node *m_next;
};
class LinkedList{
    public:    
        LinkedList(){m_head = nullptr;}
        LinkedList(Node *head) { 
            m_head = head;
        }
        ~LinkedList(){
            
            while(m_head != nullptr){
                Node *curr = m_head;
                m_head = m_head -> GetNext();
                delete curr;
            }
        }
        void addNode(int data){
            if(m_head == nullptr){
                m_head = new Node(data, nullptr);
            }
            else{
                Node *curr = m_head;
                while(curr -> GetNext() != nullptr){
                    curr = curr -> GetNext();
                }
                Node *lastNode = new Node(data, nullptr);
                curr -> SetNext(lastNode);
                }
            
        }
        Node* GetHead(Node *head){
            return m_head;
        }
        void removeFront(){
            Node *curr = m_head;
            //remove from front.
            if(m_head == nullptr) return;
            else if(m_head != nullptr){
                m_head = m_head -> GetNext();
                delete curr;
            }
        }
        void removBack(){
            //remove from back.
            Node *curr = m_head;
            Node *temp = curr;
            if(m_head == nullptr) return;
            else if(m_head -> GetNext() == nullptr){ 
                delete m_head;
                m_head = nullptr;
            }
            else{
                while(curr -> GetNext() != nullptr){
                    temp = curr;
                    curr = curr -> GetNext(); 
                }
                delete curr;
                temp -> SetNext(nullptr);             
            }  
        }
        void removeAt(int index){
            Node *curr = m_head;
            int counter = 0;
            if(index < 0){
                cout << "the index is out of bound or negative." << endl;
                return;
            }
            else if(m_head == nullptr){
                cout << "list is empty" << endl;
                return;
            }
            else if(index == 0){
                removeFront();
                cout << "removed at index: " << index << endl;
            }
            else{
                Node *temp = curr;
                while(curr != nullptr){                   
                    if(counter == index){
                        temp -> SetNext(curr -> GetNext());
                        int tempData = curr -> GetData();
                        delete curr;
                        curr = nullptr;
                        cout << "node removed at index " << index << " that contains data " << tempData << "." << endl; 
                        return;
                    }
                    temp = curr;
                    curr = curr -> GetNext();
                    counter++;
                }
                cout << "the index is out of bound or negative." << endl;
            }

        }
        void printList(){
            Node *curr = m_head;
            while(curr != nullptr){
                cout << curr-> GetData() << " ";
                curr = curr -> GetNext();
            }
            cout << endl;
        }
        private:
            Node *m_head;
  
};

int main() {
   LinkedList linkedL;
   linkedL.addNode(1);
   linkedL.addNode(12); 
   linkedL.addNode(3); 
   linkedL.addNode(4);   
   linkedL.printList();
   linkedL.removeAt(5);
   linkedL.printList();

    return 0;
}

