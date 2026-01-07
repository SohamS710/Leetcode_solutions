class Solution {
public:
    void sortColors(vector<int>& a) {
        int cnt0 = 0, cnt1 = 0, cnt2 = 0;

        for (int i=0; i<a.size(); i++) {
            if (a[i] == 0) cnt0++;
            else if (a[i] == 1) cnt1++;
            else cnt2++;
        }

        for (int i = 0; i < cnt0; i++) a[i] = 0;
        for (int i = cnt0; i < cnt0 + cnt1; i++) a[i] = 1;
        for (int i = cnt0 + cnt1; i < a.size(); i++) a[i] = 2;
    }
};