#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> game;
vector<int>xmov;
vector<int>ymov;
int game_size;
bool check(int row,int column)
{
    if(row>=0 && column>=0 && column<game_size && row<game_size && !game[row][column])
    {
        return true;
    }
    return false;
}
bool game_(int row,int column,int test)
{
    if(test>(game_size*(game_size)))
    {
        return true;
    }
    for(int i=0;i<8;i++)
    {
        int row_next=row+xmov[i];
        int col_next=column+ymov[i];
        if(check(row_next,col_next))
        {
            game[row_next][col_next]=test;
            if(game_(row_next,col_next,test+1))
                return true;
            else
                game[row_next][col_next]=0;
        }
    }
    return false;
}
int main()
{
    int n;
    std::cin>>n;
    game_size=n;
    xmov={2,1,-1,-2,-2,-1,1,2};
    ymov={1,2,2,1,-1,-2,-2,-1};
    for(int i=0;i<n;i++)
    {
        vector <int> temp;
        for(int j=0;j<n;j++)
        {
            temp.push_back(0);
        }
        game.push_back(temp);
    }
    game[0][0]=1;
    if(game_(0,0,2))
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout<<game[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
    return 0;
}
