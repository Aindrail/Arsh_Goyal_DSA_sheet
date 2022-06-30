class RandomizedCollection {
public:
    vector<int> v;
    vector<int>::iterator it;
    RandomizedCollection() {
        v.clear();
    }
    
    bool insert(int val) {
        if(v.empty()){
            v.push_back(val);
            return true;
        }
        bool chk = true;
        it = lower_bound(v.begin(), v.end(), val);
        if(it != v.end() && *it == val) chk = false;
        v.insert(it, val);
        return chk;
    }
    
    bool remove(int val) {
        it = lower_bound(v.begin(), v.end(), val);
        if(it != v.end() && *it == val){
            v.erase(it);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int tmp = rand() % v.size();
        return v[tmp];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */