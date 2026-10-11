class LRUCache : public Cache {

public:
    LRUCache(const int capacity) {
        cp = capacity;
        head = tail = nullptr;
    }
    
    void set(int key, int value) {
        auto it = mp.find(key);
        if (it != mp.end()) {  // exists 
            it->second->value = value;
            detach(it->second);
            replaceHead(it->second);
            
        } else {  // new node
            if ((int)mp.size() == cp) deleteTail();  // evict before inserting
            Node* n = new Node(key, value);
            replaceHead(n);
            mp[key] = n;
        }
    }
    
    void deleteTail() {
        Node* old = tail;
        detach(old);
        mp.erase(old->key);
        delete old;
    }
    
    void replaceHead(Node* n) {
        n->prev = nullptr;
        n->next = head;
        if (head) head->prev = n;
        else tail = n;  // list was empty, so n is also the tail
        head = n;
    }
    
    void detach(Node* n) {
        if (n->prev) {
            n->prev->next = n->next; 
        } else {
            head = n->next;
        }
        
        if (n->next) {
            n->next->prev = n->prev;
        } else {
            tail = n->prev;
        }
        
        n->prev = n->next = nullptr;
    }     
    
    int get(const int key) {
        auto it = mp.find(key);
        if (it == mp.end()) { return -1; }
        detach(it->second);
        replaceHead(it->second);
        return it->second->value;
    }
};
