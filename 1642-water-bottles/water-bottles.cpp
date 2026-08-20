class Solution {
public:
    int numWaterBottles(int n, int m) {
        int full=n;
        int emp=full;
        int drk=full;

        while(emp>=m){
            full=emp/m;
            emp=emp%m;
            drk+=full;
            emp+=full;
        }
        return drk;
        
        
    }
    
    
};