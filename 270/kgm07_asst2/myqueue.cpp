#include <vector>
#include <stdexcept>
#include <iostream>

template <typename T>
class Queue {
public:
    // Enqueue: Add an element to the end of the queue
    void Enqueue(const T& item) {
        data.push_back(item);
    }

    // Dequeue: Remove the element at the front of the queue
    void Dequeue() {
        if (!IsEmpty()) {
            data.erase(data.begin());
        }
    }

    // Front: View the element at the front of the queue
    T Front() {
        if (!IsEmpty()) {
            return data.front();
        } else {
            throw std::out_of_range("Queue is empty.");
        }
    }

    // IsEmpty: Check if the queue is empty
    bool IsEmpty() const {
        return data.empty();
    }

    // Size: Return the number of elements in the queue
    size_t Size() const {
        return data.size();
    }

    // Clear: Remove all elements from the queue
    void Clear() {
        data.clear();
    }

    // Const versions of functions where appropriate
    T Front() const {
        if (!IsEmpty()) {
            return data.front();
        } else {
            throw std::out_of_range("Queue is empty.");
        }
    }

    bool IsEmpty() {
        return data.empty();
    }

private:
    std::vector<T> data;
};

int main() {

    Queue<int> intQueue;
    intQueue.Enqueue(1);
    intQueue.Enqueue(2);
    intQueue.Enqueue(3);

    std::cout << "Front: " << intQueue.Front() << std::endl; 

    intQueue.Dequeue();
    std::cout << "Front after Dequeue: " << intQueue.Front() << std::endl; 

    intQueue.Clear();
    std::cout << "Is Queue empty? " << intQueue.IsEmpty() << std::endl; 

    Queue<std::string> stringQueue;
    stringQueue.Enqueue("Hello");
    stringQueue.Enqueue("World");

    std::cout << "Front: " << stringQueue.Front() << std::endl; 

    return 0;
}
