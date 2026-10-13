
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {

        int n = nums1.size();

        long long total = 1LL * k1 + k2;

        unordered_map<long long, long long> freq;
        vector<long long> vec;

        for (int i = 0; i < n; i++) {
            long long x = abs(1LL * nums1[i] - nums2[i]);

            freq[x]++;

            if (freq[x] == 1) {
                vec.push_back(x);
            }
        }

        sort(vec.rbegin(), vec.rend());

        if (!freq.count(0)) {
            vec.push_back(0);
        }

        // Use vec.size(), not n
        for (int i = 0; i + 1 < (int)vec.size() && total > 0; i++) {

            long long first = vec[i];
            long long second = vec[i + 1];

            long long count = freq[first];
            long long sop = first - second;

            if (total >= count * sop) {

                total -= count * sop;

                freq[second] += count;
                freq.erase(first);

            } else {

                long long how_far = total / count;
                long long remaining = total % count;

                long long new_val = first - how_far;

                freq.erase(first);

                // Elements reduced by how_far
                freq[new_val] += count - remaining;

                // Elements reduced by how_far + 1
                if (remaining > 0) {
                    freq[new_val - 1] += remaining;
                }

                total = 0;
                break;
            }
        }

        long long ans = 0;

        for (auto& p : freq) {
            long long u = p.first;
            long long v = p.second;

            ans += v * u * u;
        }

        return ans;
    }
};
