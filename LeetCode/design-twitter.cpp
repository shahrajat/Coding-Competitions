class Twitter {
public:
    /** Initialize your data structure here. */
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> following;
    int time;
    Twitter() {
        time=0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back(make_pair(tweetId, time++));
    }
    
    struct compare  
     {  
       bool operator()(const pair<int,int>& l, const pair<int,int>& r)  
       {  
           return l.second > r.second;  
       }  
     };  

    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> result;
        priority_queue<pair<int,int>, vector<pair<int, int>>, compare> pq;
        unordered_set<int> followingIds = following[userId];
        followingIds.insert(userId);
        
        for(int followeeId : followingIds) {
            int count = tweets[followeeId].size();
            for(int i=count-1; i>=0 && i>count-11; i--) {
                pq.push(tweets[followeeId][i]);
                if(pq.size()>10)
                    pq.pop();
            }
        }
        
        while(!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId)
            following[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
