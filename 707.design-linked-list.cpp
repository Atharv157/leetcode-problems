/*
 * @lc app=leetcode id=707 lang=cpp
 *
 * [707] Design Linked List
 */

// @lc code=start
class MyLinkedList {
public:
    MyLinkedList* head = nullptr;
    MyLinkedList *next;
    int count = 0;
    int value;
    MyLinkedList() {
        value = 0;
        next = nullptr;
    }
    
    int get(int index) {
        if(this->count-1>=index && index>=0){
            int counter = 0;
            MyLinkedList *temp = this->head;
            while(counter != index){
                temp = temp->next;
                counter++;
            }
            return temp->value;
        }
        return -1;
    }
    
    void addAtHead(int val) {
        MyLinkedList *node = new MyLinkedList();
        node->value = val;
        node->next = this->head;
        this->head = node;
        this->count += 1;
    }
    
    void addAtTail(int val) {
        if(this->count == 0){
            addAtHead(val);
            return;
        }
        MyLinkedList *node = new MyLinkedList();
        node->value = val;
        node->next = nullptr;
        
        MyLinkedList *temp = this->head;
        while(temp->next != nullptr)
            temp = temp->next;
        temp->next = node;
        this->count += 1;
        return;
    }
    
    void addAtIndex(int index, int val) {
        if(index == 0){
            this->addAtHead(val);
            return;
        }
        else if(index == count){
            this->addAtTail(val);
            return;
        }
        else if(index > this->count){
            return;
        }
        
        else{
            int counter = 0;
            MyLinkedList *temp = this->head;
            while(counter!=index-1){
                temp = temp->next;
                counter += 1;
            }
            MyLinkedList *node = new MyLinkedList();
            node->value = val;
            node->next = temp->next;
            temp->next = node;
            this->count += 1;
            return;
        }
        
    }
    
    void deleteAtIndex(int index) {
        if(index>=this->count)
            return;
        else if(index == 0){
            MyLinkedList *temp = this->head;
            this->head = this->head->next;
            delete(temp);
            this->count -= 1;
            return;
        }
        else{
            int counter = 0;
            MyLinkedList *temp = this->head;
            while(counter != index-1){
                temp = temp ->next;
                counter++;
            }
            MyLinkedList *delnode = temp->next; 
            temp->next = temp->next->next;
            this->count -= 1;
            delete(delnode);
            return;
        }

    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

