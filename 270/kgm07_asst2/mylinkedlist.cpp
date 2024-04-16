#include <iostream>

template <typename T>
class ListNode {
public:
    T data;
    ListNode* next;

    ListNode(const T& newData, ListNode* nextNode = nullptr) : data(newData), next(nextNode) {
    }
};

template <typename T>
class LinkedList {
public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {
    }

    ~LinkedList() {
        clear();
    }

    void push_back(const T& newData) {
        ListNode<T>* newNode = new ListNode<T>(newData);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void push_front(const T& newData) {
        ListNode<T>* newNode = new ListNode<T>(newData);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void pop_back() {
        if (head == nullptr) {
            return;
        }
        if (head == tail) {
            delete head;
            head = nullptr;
            tail = nullptr;
        } else {
            ListNode<T>* current = head;
            while (current->next != tail) {
                current = current->next;
            }
            delete tail;
            tail = current;
            tail->next = nullptr;
        }
        size--;
    }

    void pop_front() {
        if (head == nullptr) {
            return;
        }
        ListNode<T>* temp = head;
        head = head->next;
        delete temp;
        size--;
    }

    void insert_after(const T& newData, const T& targetData) {
        ListNode<T>* current = head;
        while (current != nullptr && current->data != targetData) {
            current = current->next;
        }
        if (current != nullptr) {
            ListNode<T>* newNode = new ListNode<T>(newData, current->next);
            current->next = newNode;
            size++;
        }
    }

    void remove(const T& targetData) {
        if (head == nullptr) {
            return;
        }
        if (head->data == targetData) {
            pop_front();
            return;
        }
        ListNode<T>* current = head;
        while (current->next != nullptr && current->next->data != targetData) {
            current = current->next;
        }
        if (current->next != nullptr) {
            ListNode<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }

    int get_size() const {
        return size;
    }

    void clear() {
        while (head != nullptr) {
            pop_front();
        }
    }

    void print() const {
        ListNode<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

private:
    ListNode<T>* head;
    ListNode<T>* tail;
    int size;
};

int main() {
    LinkedList<int> intList;
    intList.push_back(1);
    intList.push_back(2);
    intList.push_back(3);
    intList.push_front(0);
    intList.insert_after(4, 2);
    intList.remove(3);
    intList.print();

    LinkedList<char> charList;
    charList.push_back('A');
    charList.push_back('B');
    charList.push_front('Z');
    charList.insert_after('C', 'A');
    charList.remove('B');
    charList.print();

    return 0;
}
