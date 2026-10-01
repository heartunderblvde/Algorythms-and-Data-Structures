#include <iostream>

struct Node{
    int data;
    Node* next;
};

Node* head = nullptr;

void printList(){
    Node* current = head;

    while(current != nullptr){
        std::cout << current->data << ' ';
        current = current->next;
    }
    std::cout << std::endl;
}

void inputList(){
    int n;
    std::cin >> n;

    if(n <= 0){
        return;
    }

    Node* head = nullptr;
    Node* tail = nullptr;

    for(int i = 0; i < n; i++){
        Node* newNode = new Node();
        std::cin >> newNode->data;
        newNode->next = nullptr;
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } else{
            tail->next = nullptr;
            tail = newNode;
        }
    }
}
// Task 1
// int main(){
//     Node* first = new Node;
//     first->data = 10;

//     Node* second = new Node;
//     second->data = 20;

//     Node* third = new Node;
//     third->data = 30;

//     Node* fourth = new Node;
//     fourth->data = 40;

//     Node* fifth = new Node;
//     fifth->data = 50;

//     first->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = fifth;
//     fifth->next = nullptr;

//     Node* current = first;
//     while(current != nullptr){
//         std::cout << current->data << ' ';
//         current = current->next;
//     }
// }

// Task 2
void insertAtBeginning(const int& value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

// Task 3
void insertAtEnd(const int& value){
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
        return;
    }

    Node* current = head;
    while(current->next != nullptr){
        current = current->next;
    }
    current->next = newNode;
}

// Task 4
int getLength(){
    int counter = 0;
    Node* current = head;

    while(current != nullptr){
        current = current->next;
        counter++;
    }

    return counter;
}

// Task 5
bool search(const int& value){
    Node* current = head;

    while(current != nullptr){
        if(current->data == value){
            return true;
        }
        current = current->next;
    }

    return false;
}

// task 6
void deleteFirst(){
    if(head == nullptr){
        return;
    }

    Node* temp = head;
    head = head->next;
    delete temp;
}

// task 7
void deleteLast()
{
    if (head == nullptr)
    {
        return;
    }

    if (head->next == nullptr)
    {
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    Node* temp = head;

    while (current->next != nullptr)
    {
        temp = current;
        current = current->next;
    }

    temp->next = nullptr;
    delete current;
}

// task 8
void deleteValue(const int& value){
    if(head == nullptr){
        return;
    }

    Node* current = head;
    Node* temp = head;
    while(current != nullptr && current->data != value){
        temp = current;
        current = current->next;
    }
    
    if(current == nullptr){
        return;
    }

    if(current->data == value){
        if(head->data == value){
            head = current->next;
            delete current;
        }
        else if(current->next == nullptr){
            temp->next = nullptr;
            delete current; 
        } else{
            temp->next = current->next;
            delete current;
        }
    }
}

// task 9
int findMax(){
    if(head == nullptr){
        return -1;
    }

    int maxElement = INT_MIN;
    Node* current = head;

    while(current != nullptr){
        if(current->data > maxElement){
            maxElement = current->data;
        }

        current = current->next;
    }

    return maxElement;
}

// task 10
int findMin(){
    if(head == nullptr){
        return -1;
    }

    int minElement = INT_MAX;
    Node* current = head;

    while(current != nullptr){
        if(current->data < minElement){
            minElement = current->data;
        }

        current = current->next;
    }

    return minElement;
}

// taks 11
int countEvenNumbers(){
    Node* current = head;
    int count = 0;

    while(current != nullptr){
        if(current->data % 2 == 0){
            count++;
        }
        current = current->next;
    }

    return count;
}

// task 12
void reverseList(){
    if(head == nullptr){
        return;
    }

    Node* current = head;
    Node* prev = nullptr;

    while(current != nullptr){
        Node* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    head = prev;
}

// task 13
int findMiddle(){
    if (head == nullptr){
        return -1;
    }

    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

// task 14
void removeDuplicate(){
    if (head == nullptr){
        return;
    }

    Node* current = head;
    while(current != nullptr){
        bool isDuplicate = false;
        Node* temp = current->next;
        Node* prev = current;
        while(temp != nullptr){
            if(temp->data == current->data){
                isDuplicate = true;
                break;
            }
            prev = prev->next;
            temp = temp->next;
        }

        if(isDuplicate){
            prev->next = temp->next;
            delete temp;
            continue;
        }
        current = current->next;
    }
}

// task 15
void sortList(){
    if (head == nullptr){
        return;
    }
    Node* current = head;
    Node* prevCurrent = nullptr;

    while (current != nullptr)
    {
        Node* min = current;
        Node* prevMin = prevCurrent;

        Node* temp = current->next;
        Node* prevTemp = current;

        while (temp != nullptr){
            if (temp->data < min->data){
                min = temp;
                prevMin = prevTemp;
            }
            prevTemp = temp;
            temp = temp->next;
        }

        if (min != current){
            prevMin->next = min->next;
            min->next = current;

            if (prevCurrent == nullptr){
                head = min;
            }
            else{
                prevCurrent->next = min;
            }
        }

        prevCurrent = current;
        current = current->next;
    }
}

int main(){
    insertAtBeginning(30);
    insertAtBeginning(10);
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtBeginning(10);

    sortList();
    printList();
}

