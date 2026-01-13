#include <iostream>

class LinkedList {
    struct Node {
        int data {-1};
        Node* next {nullptr};
    };

    Node* _start {nullptr};

public:
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

    return 0;
}
