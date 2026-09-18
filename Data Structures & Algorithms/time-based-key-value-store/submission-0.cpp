class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> data;

public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        data[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (!data.count(key)) return "";
        
        auto& vec = data[key];
        auto it = upper_bound(vec.begin(), vec.end(), make_pair(timestamp, string("~")));
        
        if (it == vec.begin()) return "";
        return prev(it)->second;
    }
};