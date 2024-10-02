#include <iostream>
using namespace std;

template<typename T>
class Deque
{
    struct Node
    {
        T data;
        Node *left;
        Node* right;
        Node(T val) : data(val), left ( nullptr), right(nullptr){}
    };
    Node * front;
    Node * rare;
    int size;

    public:

    Deque()
    {
        front = rare = nullptr;
        size = 0;
    }

    void push_back(T val)
    {
        if(!front)
        {
            Node * temp = new Node(val);
            front  = rare  = temp;
        }
        else{
            Node * temp = new Node(val);
            rare->right = temp;
            rare  = temp;
        }

        size++;
    }
    void push_front(T val)
    {
        if(!front)
        {
            Node * temp = new Node(val);
            front  = rare  = temp;
        }
        else{
            Node * temp = new Node(val);
            front->left = temp;
            front  = temp;
        }

        size++;
    }

    void pop_back()
    {
        if(!rare) 
        {
            cout<<"deque is empty\n";
            return;
        }

         Node * temp = rare;

         
         rare = rare->left;

         if(!rare)
         rare->right  = nullptr;

         delete temp;

         size--;
    }

    void pop_front()
    {
        if(!front)
        {
            cout<<"Deque is empty\n";
        }

        Node * temp = front;

        front = front->right;
        if(!front)
        front->left = nullptr;

        delete temp;

        size--;
    }

    T back()
    {
        if(!rare)
        {
            cout<<"Dequeue is empty\n";
            return -1;
        }

        return rare->data;
    }

    T frontValue()
    {
        if(!front)
        {
            cout<<"Dequeue is empty\n";
            return -1;
        }
        return front->data;
    }



};

int main()
{
    cout<<"Hello World!";

    Deque<int> myDeque;

    myDeque.back();
    myDeque.frontValue();
    myDeque.push_back(1);
    myDeque.push_back(100);
    myDeque.push_front(11);
    myDeque.push_front(22);

    int k = myDeque.back();

    cout<<k<<"\n";

    return 0;
}


// template<typename T>
// class Deque {
// private:
//     struct Node {
//         T data;
//         Node* prev;
//         Node* next;
//         Node(T val) : data(val), prev(nullptr), next(nullptr) {}
//     };

//     Node* head;
//     Node* tail;
//     int size;

// public:
//     Deque() : head(nullptr), tail(nullptr), size(0) {}

//     void push_front(T val) {
//         Node* newNode = new Node(val);
//         if (!head) {
//             head = tail = newNode;
//         } else {
//             newNode->next = head;
//             head->prev = newNode;
//             head = newNode;
//         }
//         size++;
//     }

//     void push_back(T val) {
//         Node* newNode = new Node(val);
//         if (!tail) {
//             head = tail = newNode;
//         } else {
//             tail->next = newNode;
//             newNode->prev = tail;
//             tail = newNode;
//         }
//         size++;
//     }

//     void pop_front() {
//         if (!head) {
//             std::cout << "Deque is empty." << std::endl;
//             return;
//         }
//         if (head == tail) {
//             delete head;
//             head = tail = nullptr;
//         } else {
//             Node* temp = head;
//             head = head->next;
//             head->prev = nullptr;
//             delete temp;
//         }
//         size--;
//     }

//     void pop_back() {
//         if (!tail) {
//             std::cout << "Deque is empty." << std::endl;
//             return;
//         }
//         if (head == tail) {
//             delete tail;
//             head = tail = nullptr;
//         } else {
//             Node* temp = tail;
//             tail = tail->prev;
//             tail->next = nullptr;
//             delete temp;
//         }
//         size--;
//     }

//     void print() {
//         Node* current = head;
//         while (current) {
//             std::cout << current->data << " ";
//             current = current->next;
//         }
//         std::cout << std::endl;
//     }

//     int getSize() {
//         return size;
//     }

//     ~Deque() {
//         Node* current = head;
//         while (current) {
//             Node* temp = current;
//             current = current->next;
//             delete temp;
//         }
//     }
// };

// int main() {
//     Deque<int> myDeque;
//     myDeque.push_back(1);
//     myDeque.push_back(2);
//     myDeque.push_front(0);

//     myDeque.print(); // Output: 0 1 2

//     myDeque.pop_back();
//     myDeque.print(); // Output: 0 1

//     myDeque.pop_front();
//     myDeque.print(); // Output: 1

//     std::cout << "Size: " << myDeque.getSize() << std::endl; // Output: Size: 1

//     return 0;
// }