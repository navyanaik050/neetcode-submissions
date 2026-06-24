class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map <int , int> freqMap;
        vector<int> res;
        for(auto num: nums){
            freqMap[num]++;
        }

        priority_queue<pair<int , int>>maxHeap;
        for(auto &pair : freqMap){
            maxHeap.push({pair.second,pair.first});
        }
        for(int i=0; i<k; i++){
            res.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return res;
    }
};
