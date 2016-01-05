class LRUCache{
private:
    map<int,list<pair<int, int>>::iterator> keyToListItr;    //key to list node*
    list<pair<int,int>> clist;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        auto itr = keyToListItr.find(key);
        if(itr != keyToListItr.end())
        {
            clist.splice(clist.begin(),clist,itr->second);      //move element to front
            return itr->second->second;     //return the key value
        }
        return -1;
    }
    
    void set(int key, int value) {
        auto itr = keyToListItr.find(key);
        if(itr != keyToListItr.end()) //key exists
        {
            clist.splice(clist.begin(),clist,itr->second);      //move element to front
            itr->second->second = value;
            return;
        }
        if(keyToListItr.size()==capacity) //already full, make space for new key, value
        {
            int del_key = clist.back().first;
            clist.pop_back();
            keyToListItr.erase(del_key);
        }
        clist.emplace_front(key, value);
        keyToListItr[key] = clist.begin();
    }
};
