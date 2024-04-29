#include <iostream>
#include <cstring>
#include <tuple>

template <typename K, typename V>
class Map {
private:
    struct Node {
        K key;
        V value;
        Node* next;
        Node(const K& k, const V& v, Node* n) : key(k), value(v), next(n) {}
    };
    Node* first;
    Node* last;
    int count;
public:
    Map() : first(nullptr), last(nullptr), count(0) {}
    ~Map() {
        Node* current = first;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        first = nullptr;
        last = nullptr;
        count = 0;
    }
    bool Includes(const Map<K, V>& map) const {
        Node* current = first;
        while (current != nullptr) {
            V map_value;
            if (map.get(current->key, map_value)) {
                if (current->value != map_value) {
                    return false;
                }
            }
            else {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    bool Get(const K& key, V& value){
        Node* current = first;
        while (current != nullptr) {
            if (current->key == key) {
                value = current->value;
                return true;
            }
            current = current->next;
        }
        return false;
    }

    void Set(const K& key, const V& value) {
        if (first == nullptr) {
            first = new Node(key, value, nullptr);
            last = first;
            ++count;
            return;
        }
        Node* current = first;
        while (current->next != nullptr) {
            if (current->key == key) {
                current->value = value;
                return;
            }
            current = current->next;
        }
        Node* new_node = new Node(key, value, nullptr);
        current->next = new_node;
        last = new_node;
        ++count;
    }

    bool Delete(const K& key) {
        Node** current = &first;
        while (*current != nullptr) {
            if ((*current)->key == key) {
                Node* temp = *current;
                *current = temp->next;
                if (temp == first) {
                    last = *current;
                }
                delete temp;
                --count;
                return true;
            }
            current = &(*current)->next;
        }
        return false;
    }

    int Count() const {
        return count;
    }

    void Clear() {
        Node* current = first;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        first = nullptr;
        last = nullptr;
        count = 0;
        printf("Map cleared!");
    }

    class Iterator {
    private:
        Node* current;
        int index;

    public:
        Iterator(Node* ptr, int idx) : current(ptr), index(idx) {}

        bool operator!=(Iterator& other)  {
            return current != other.current;
        }

        void operator++() {
            current = current->next;
            ++index;
        }

        std::tuple<K, V, int> operator*() {
            return std::make_tuple(current->key, current->value, index);
        }
    };

    Iterator begin()  {
        return Iterator(first, 0);
    }

    Iterator end() const {
        return Iterator(nullptr, count);
    }

    V& operator[](const K& key) {
        Node* current = first;
        while (current != nullptr) {
            if (current->key == key) {
                return current->value;
            }
            current = current->next;
        }
        Node* new_node = new Node(key, V(), nullptr);
        if (first == nullptr) {
            first = new_node;
            last = new_node;
        }
        else {
            last->next = new_node;
            last = new_node;
        }
        ++count;
        return new_node->value;
    }
};

int main()
{
    Map<int, const char*> m;
    m[10] = "C++";
    m[20] = "test";
    m[30] = "Poo";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    m[20] = "result";
    for (auto [key, value, index] : m)
    {
        printf("Index:%d, Key=%d, Value=%s\n", index, key, value);
    }
    return 0;
}
