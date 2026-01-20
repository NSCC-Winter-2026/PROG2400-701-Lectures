#include <iostream>

class LinkedList {
    struct Node {
        int data {-1};
        Node* next {nullptr};
    };

    Node* _start {nullptr};

public:
    class iterator {
        Node* _node {nullptr};

    public:
        explicit iterator(Node* node = nullptr) : _node(node) {
        }

        int operator*() const { return _node->data; }
        bool operator!=(const iterator it) const { return this->_node != it._node; }

        iterator& operator++() {
            _node = _node->next;
            return *this;
        }

        iterator operator+(int i) const {
            // for you to try and implement
        };
    };

    iterator begin() { return iterator(_start); }
    iterator end() { return iterator(nullptr); }

    void add(const int data) {
        const auto node = new Node({data});

        // is this the first node?
        if (_start == nullptr) {
            // yes!
            _start = node;
        } else {
            // no, another node in the chain

            // find the end of the chain
            auto prev = static_cast<Node*>(nullptr);
            auto curr = _start;

            // loop until the end of the chain is found
            while (curr != nullptr) {
                prev = curr;
                curr = curr->next;
            }

            // did I find the end of the chain?
            if (prev != nullptr) {
                // attach new node to end of chain
                prev->next = node;
            }
        }
    }

    /// Used to insert data within an existing linked list.
    /// @param data the new node's data
    /// @param index the node index to insert before
    void insert(const int data, const int index) {
        auto node = new Node({data});

        auto curr = _start;
        auto prev = static_cast<Node*>(nullptr);
        // find index to insert before
        for (auto i = 0; curr != nullptr && i < index; ++i) {
            prev = curr;
            curr = curr->next;
        }

        // did I find the index to insert before?

        // yes, but is it the first node?
        if (prev == nullptr) {
            // yep, it sure is.
            node->next = _start;
            _start = node;
        } else {
            // no, so insert in the middle or the end
            node->next = prev->next;
            prev->next = node;
        }
    }

    void remove(const int data) {
        auto prev = static_cast<Node*>(nullptr);
        auto curr = _start;

        // find the node to delete
        while (curr != nullptr) {
            // if node is found, exit loop
            if (curr->data == data) {
                // we found the node!
                break;
            }
            prev = curr;
            curr = curr->next;
        }

        // did we find the node to delete?
        if (curr != nullptr) {
            // we did find it!

            // is it the first node?
            if (prev == nullptr) {
                // yes!
                _start = curr->next;
            } else {
                // disconnect node to delete from chain
                prev->next = curr->next;
            }

            delete curr;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list);
};

std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
    auto node = list._start;

    while (node != nullptr) {
        os << node->data << " ";
        node = node->next;
    }

    return os;
}

int main() {
    LinkedList list;

    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    std::cout << "Test 1: add some data" << std::endl;
    std::cout << "---------------------" << std::endl;

    std::cout << list << std::endl;

    std::cout << "Test 2: delete a node" << std::endl;
    std::cout << "---------------------" << std::endl;

    // delete the node that contains the value 5
    list.remove(5);

    std::cout << list << std::endl;

    std::cout << "Test 3: delete the start node" << std::endl;
    std::cout << "-----------------------------" << std::endl;

    // delete the node that contains the value 1
    list.remove(1);

    std::cout << list << std::endl;

    std::cout << "Test 4: insert a node" << std::endl;
    std::cout << "---------------------" << std::endl;

    // insert the value 9 before the node with index 1
    list.insert(9, 1);

    std::cout << list << std::endl;

    std::cout << "Test 5: insert a node with invalid index" << std::endl;
    std::cout << "----------------------------------------" << std::endl;

    // insert the value 10 before the node with index 100
    list.insert(10, 100);

    std::cout << list << std::endl;

    std::cout << "Test 6: insert a node before index 0" << std::endl;
    std::cout << "------------------------------------" << std::endl;

    // insert the value 11 before the node with index 0
    list.insert(11, 0);

    std::cout << list << std::endl;

    std::cout << "Test 7: using an iterator" << std::endl;
    std::cout << "-------------------------" << std::endl;

    for (auto i = list.begin() + 1; i != list.end(); ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    for (auto n : list) {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    for (auto i = 0; i < list.size(); ++i) {
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
