/*
* 
* @author: Manish Kumar
* @institute: IIIT Allahabad, INDIA
*
* @problem: https://leetcode.com/problems/median-of-two-sorted-arrays/
* @refer: https://www.youtube.com/watch?v=LPFhl65R7ww&ab_channel=TusharRoy-CodingMadeSimple
* @desc: see video
*/


class Solution {
public:
    double findMedianSortedArrays(vector<int> a, vector<int> b) {
        int n1 = a.size(), n2 = b.size();
        if(n1 > n2)
            return findMedianSortedArrays(b, a);
        
        int lo = 0, hi = n1, partX, partY;
        while(lo <= hi){
            partX = (lo + hi) / 2;
            partY = (n1 + n2 + 1) / 2 - partX;

            int maxPartX = (partX == 0) ? INT_MIN : a[partX-1];
            int minPartX = (partX == n1) ? INT_MAX : a[partX];

            int maxPartY = (partY == 0) ? INT_MIN : b[partY-1];
            int minPartY = (partY == n2) ? INT_MAX : b[partY];

            if(maxPartX <= minPartY && maxPartY <= minPartX){
                if((n1 + n2) % 2 == 0){
                    return ((double)max(maxPartX, maxPartY) + min(minPartX, minPartY)) / 2.0;
                }
                else{
                    return (double)max(maxPartX, maxPartY);
                }
            }
            else if(maxPartX > minPartY){
                hi = partX - 1;
            }
            else{
                lo = partX + 1;
            }
        }

        return 0.0;
    }
};