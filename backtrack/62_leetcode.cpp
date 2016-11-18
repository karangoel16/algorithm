//this question has been solved using backtracking to calculate the unique path
//this is not the way this code has to be done , but it was a good learning experience
#include <iostream>
#include <vector>
using namespace std;
class Solution {
    int path;
    vector<int> x;
    vector<int> y;
public:
    Solution()
    {
        path=0;
        x={1,0};
        y={0,1};
    }
    bool check(int m,int n,int col,int row)
    {
        if(col>0 && col<=m && row>0 && row<=n)
        {
            return true;
        }
        return false;
    }
    void back_track(int m,int n,int row,int col)
    {
        if(row==n && col==m)
        {
            path++;
            return;
        }
        for(int i=0;i<2;i++)
        {
            int row_next=row+y[i];
            int col_next=col+x[i];
            if(check(m,n,col_next,row_next))
            {
                back_track(m,n,row_next,col_next);
            }
        }
    }
    int uniquePaths(int m, int n) {
        back_track(m,n,1,1);
        return path;
    }
};
int main()
{
    Solution t;
    std::cout<<t.uniquePaths(3,7);
}
