#include <algorithm>
#include <queue>
using namespace std;
class MedianFinder {
private:
    priority_queue<int, vector<int>> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
public: 
    // Adds a number into the data structure.
    void addNum(int num) {
        if(min_heap.size()==0 && max_heap.size()==0)    //first element, push in any
        {
            max_heap.push(num);
        }
        else if(min_heap.size()==1 && max_heap.size()==0)   //2nd element, max heap has smaller of these 2
        {
            int prev = min_heap.top();
            min_heap.pop();
            min_heap.push(max(prev,num));
            max_heap.push(min(prev,num));
        }
        else if(min_heap.size()==0 && max_heap.size()==1)   //2nd element
        {
            int prev = max_heap.top();
            max_heap.pop();
            min_heap.push(max(prev,num));
            max_heap.push(min(prev,num));
        }
        else        //past 2 elements
        {
            if(num < max_heap.top())
                max_heap.push(num);
            else
                min_heap.push(num);
        }
        if( (int)max_heap.size()-(int)min_heap.size() > 1)    //resize
        {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        else if( (int)min_heap.size()-(int)max_heap.size() > 1)  //resize
        {
            max_heap.push(min_heap.top());
            min_heap.pop();
        } 
    }

    // Returns the median of current data stream
    double findMedian() {
        if(min_heap.size()==max_heap.size() && min_heap.size()>0)
            return (min_heap.top()+max_heap.top())/2.0;
        else if(max_heap.size() > min_heap.size())
            return max_heap.top();
        else
            return min_heap.top();
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();
