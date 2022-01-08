/*
 * @lc app=leetcode id=380 lang=cpp
 *
 * [380] Insert Delete GetRandom O(1)
 */

// @lc code=start
class RandomizedSet {
public:
    unordered_set<int> hashset;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(hashset.count(val))
            return false;
        else
            hashset.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(hashset.count(val)){
            hashset.erase(val);
            return true;
        }
        return false;
    }
    
    int getRandom() {
        auto iter = hashset.begin();
        int random = rand() % hashset.size();
        while(random){
            iter++;
            random--;
        }
        return *iter;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
// @lc code=end

