class LRUCache {
private:
    int cap;
    list<pair<int, int>> items;  // front = most recent, back = least recent
    unordered_map<int, list<pair<int, int>>::iterator> pos;

public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = pos.find(key);
        if (it == pos.end()) return -1;
        items.splice(items.begin(), items, it->second);  // move to front
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = pos.find(key);
        if (it != pos.end()) {
            it->second->second = value;
            items.splice(items.begin(), items, it->second);
            return;
        }

        items.emplace_front(key, value);
        pos[key] = items.begin();

        if ((int)items.size() > cap) {
            pos.erase(items.back().first);
            items.pop_back();
        }
    }
};