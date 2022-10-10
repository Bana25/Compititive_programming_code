class Solution {
   public:
    // store minimum & maximum products to calculate real maximum product.
    int maxProduct(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        int real_max = *max_element(nums.begin(), nums.end());
        int cur_min{1}, cur_max{1};
        for (auto ele : nums) {
            int temp_max{cur_max};
            cur_max = max({ele * cur_max, ele * cur_min, ele});
            cur_min = min({ele * temp_max, ele * cur_min, ele});
            real_max = max(real_max, cur_max);
        }
        return real_max;
    }
};