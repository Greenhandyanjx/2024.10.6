#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
        priority_queue<int> small;
        priority_queue<int, vector<int>, greater<int> > big;
        unordered_map<int, int> mp;
        double get(int& k) {
            if (k % 2) return small.top();
            else return ((long long)small.top() + big.top()) * 0.5;
        }
        vector<double> medianSlidingWindow(vector<int>& nums, int k) {
            for (int i = 0; i < k; i++) { small.push(nums[i]); };
            for (int i = 0; i < k / 2; i++) { big.push(small.top()); small.pop(); }
            vector<double> ans{ get(k) };
            for (int i = k; i < nums.size(); i++) {
                int balance = 0;
                int l = nums[i - k];
                mp[l]++;
                if (!small.empty() && l <= small.top()) { balance--; }
                else { balance++; }
                if (!small.empty() && nums[i] <= small.top()) {
                    small.push(nums[i]);
                    balance++;
                }
                else {
                    big.push(nums[i]);
                    balance--;
                }
                if (balance > 0) {
                    big.push(small.top());
                    small.pop();
                }
                if (balance < 0) {
                    small.push(big.top());
                    big.pop();
                }
                while (!small.empty() && mp[small.top()] > 0) {
                    mp[small.top()]--;
                    small.pop();
                }
                while (!big.empty() && mp[big.top()] > 0) {
                    mp[big.top()]--;
                    big.pop();
                }
                ans.push_back(get(k));

            }
            return ans;
        }
    //优先队列超时
        double findKthLargest(vector<double>& nums, double k) {
            priority_queue<double, vector<double>, greater<double>> pq;   // 将数组加入小顶堆，堆中维护当前值最大的k个数
            for (auto& num : nums) {
                pq.emplace(num);
                if (pq.size() > k) {
                    pq.pop();   // 堆中元素超过k个，弹出最小的那个
                }
            }
            return pq.top();    // 最后堆顶的即为第k大的数
        }
        vector<double> medianSlidingWindow(vector<int>& nums, int k) {
            vector<double>temp;
            vector<double>res;
            int left = 0, right = k - 1;
            for (int i = 0; i < k; i++) {
                temp.push_back(nums[i]);
            }
            if (k % 2 == 1)
            {
                while (right < nums.size()) {
                    temp[right % k] = nums[right];
                    res.push_back(findKthLargest(temp, k / 2));
                }
            }
            else {
                while (right < nums.size()) {
                    temp[right % k] = nums[right];
                    res.push_back((findKthLargest(temp, k / 2) + findKthLargest(temp, k / 2 - 1)) / 2);
                }
            }
            return res;
        }
    //      sort超时
    //vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    //    vector<double>temp;
    //    vector<double>res;
    //    int left = 0, right = k - 1;
    //    for (int i = 0; i < k; i++) {
    //        temp.push_back(nums[i]);
    //    }
    //    if(k%2==1)
    //    {
    //        while (right < nums.size()) {
    //            temp[right % 3] = nums[right];
    //            vector<double>t(temp);
    //            sort(t.begin(), t.end());
    //            res.push_back(t[k / 2]);
    //            right++;
    //        }
    //    }
    //    else {
    //        while (right < nums.size()) {
    //            temp[right % 3] = nums[right];
    //            vector<double>t(temp);
    //            sort(t.begin(), t.end());
    //            res.push_back((t[k / 2]+t[k/2-1])/2);
    //            right++;
    //        }
    //    }
    //    return res;
    //}
};
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int slow = 0, fast = 1;
        while (fast < nums.size()) {
            if (nums[slow] != nums[fast]) {
                slow++;
                fast++;
            }
            else return nums[slow];
        }
        return nums[slow];
    }
};
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow = 0, fast = 0;
        while (fast < nums.size()) {
            if (nums[slow] != 0 && nums[fast] != 0) {
                slow++;
                fast++;
            }
            else if (nums[slow] == 0 && nums[fast] == 0)fast++;
            else if (nums[slow] == 0 && nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
                fast++;
            }
            else {
                break;
            }
        }
    }
};
int main() {
    vector<int>nums{ 0,1,0,3,12 };
}