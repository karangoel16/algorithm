#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>>game;
int game_size;
bool isSafe(int row,int column)
{

    int i,j;
    //to check if upper row has already taken the queen place
    for(i=0;i<game_size;i++)
    {
        if(game[row][i])
        {
            return false;
        }
    }
    for(i=row,j=column;i>=0 && j>=0;i--,j--)
    {
        if(game[i][j])
            return false;
    }
    for(i=row,j=column;i<game_size&&j>=0;i++,j--)
    {
        if(game[i][j])
            return false;
    }
    return true;
}
bool game_(int col)
{
    if(col>=game_size)
    {
        return true;
    }
    for(int i=0;i<game_size;i++)
    {
        if(isSafe(i,col))
        {
            game[i][col]=1;
            if(game_(col+1))
            {
                return true;
            }
            game[i][col]=0;
        }
    }
    return false;
}
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        vector <int> temp;
        for(int j=0;j<n;j++)
        {
            temp.push_back(0);
        }
        game.push_back(temp);
    }
    game_size=n;
    if(game_(0)==false)
    {
        std::cout<<"Solution doesn't exist";
        return 0;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            std::cout<<game[i][j]<<"\t";
        }
        std::cout<<"\n";
    }

}
