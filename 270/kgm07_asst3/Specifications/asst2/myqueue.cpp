/**
 * Class my_queue represents a queue data structure.
 *
 * @tparam T The data type of the elements in the queue.
 */
template <typename T>
class my_queue {
private:
    std::vector<T> elements;  // Vector to store the elements in the queue.

public:
    /**
     * Enqueues (inserts) an element at the back of the queue.
     *
     * @param element The element to enqueue.
     */
    void Enqueue(const T& element);

    /**
     * Dequeues (removes) the front element from the queue.
     * If the queue is empty, this method has no effect.
     */
    void Dequeue();

    /**
     * Returns a reference to the front element of the queue.
     *
     * @return A reference to the front element.
     */
    const T& Front() const;

    /**
     * Checks if the queue is empty.
     *
     * @return True if the queue is empty, false otherwise.
     */
    bool IsEmpty();

    /**
     * Returns the number of elements in the queue.
     *
     * @return The size of the queue.
     */
    int Size();

    /**
     * Clears the queue, removing all elements.
     */
    void Clear();
};
