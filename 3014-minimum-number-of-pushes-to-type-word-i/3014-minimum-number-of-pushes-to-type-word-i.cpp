class Solution {
public:
    int minimumPushes(string word) {
        if(word.length() <= 8) {
            return word.length();
        }
        
        int count = 0;
        unordered_map<int, int> mp; //You can use an array of size 10 also and use index 2 to 9
        
        int assign = 2;
        for(char &ch : word) {
            
            if(assign > 9) {
                assign = 2;
            }
            
            mp[assign]++;
            count += mp[assign];
            assign++;
        }
        
        return count;
        
    }
};