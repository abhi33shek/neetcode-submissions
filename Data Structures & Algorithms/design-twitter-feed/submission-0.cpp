class Twitter {
private:
    unordered_map<int, unordered_set<int>> followList;
    unordered_map<int, vector<pair<int, int>>> tweetsMap;
    int universalTime;
    static constexpr int RECENT_TWEET_COUNT = 10;

public:
    Twitter() : universalTime(0) {}

    void postTweet(int userId, int tweetId) {
        tweetsMap[userId].push_back({tweetId, universalTime++});
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minH;

        auto addTweets = [&](int uid) {
            int n = tweetsMap[uid].size();
            for (int i = n - 1; i >= 0 && i >= n - RECENT_TWEET_COUNT; --i) {
                int time = tweetsMap[uid][i].second;
                int tweetId = tweetsMap[uid][i].first;

                if ((int)minH.size() < RECENT_TWEET_COUNT) {
                    minH.push({time, tweetId});
                } else if (time > minH.top().first) {
                    minH.pop();
                    minH.push({time, tweetId});
                } else {
                    break;
                }
            }
        };

        addTweets(userId);
        for (int followeeId : followList[userId]) {
            addTweets(followeeId);
        }

        int idx = minH.size() - 1;
        vector<int> result(minH.size());
        while (!minH.empty()) {
            result[idx--] = minH.top().second;
            minH.pop();
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followList[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        followList[followerId].erase(followeeId);
    }
};