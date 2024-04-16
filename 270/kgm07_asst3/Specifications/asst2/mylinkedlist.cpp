/**
 * Class ListNode represents a node in a linked list.
 *
 * @tparam T The data type of the elements in the linked list.
 */
template <typename T>
class ListNode {
public:
    T data;            // Data stored in the node.
    ListNode* next;    // Pointer to the next node in the list.

    // Constructor to create a new ListNode with the given data and an optional next node.
    ListNode(const T& newData, ListNode* nextNode = nullptr);
};

/**
 * Class my_linkedlist represents a singly linked list.
 *
 * @tparam T The data type of the elements in the linked list.
 */
template <typename T>
class my_linkedlist {
private:
    ListNode<T>* head;  // Pointer to the head of the linked list.

public:
    // Constructor to create an empty linked list.
    my_linkedlist();

    /**
     * Inserts an element at the end of the linked list.
     *
     * @param data The element to insert.
     */
    void push_back(const T& data);

    /**
     * Inserts an element at the front of the linked list.
     *
     * @param data The element to insert.
     */
    void push_front(const T& data);

    /**
     * Removes the last element from the linked list.
     */
    void pop_back();

    /**
     * Removes the first element from the linked list.
     */
    void pop_front();

    /**
     * Inserts an element after a target element in the linked list.
     *
     * @param data The element to insert.
     * @param target The element after which to insert the new element.
     */
    void insert_after(const T& data, const T& target);

    /**
     * Removes all occurrences of a specified element from the linked list.
     *
     * @param data The element to remove.
     */
    void remove(const T& data);

    /**
     * Returns the number of elements in the linked list.
     *
     * @return The size of the linked list.
     */
    int get_size();

    /**
     * Clears the linked list, removing all elements.
     */
    void clear();

    /**
     * Prints the elements of the linked list.
     */
    void print();
};
