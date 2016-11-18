#include <iostream>
#include <vector>
using namespace std;
int game_size;
vector<vector<int>> game;
vector<int> xmov;
vector<int> ymov;
int dest_row;
int dest_col;
bool safe(int row,int col)
{
    if(row>=0 && col>=0 && row<game_size && col<game_size && !game[row][col])
    {
        return true;
    }
    return false;
}
bool game_(int row,int col,int test)
{
    if(row==dest_row && col==dest_col)
    {
        return true;
    }
    for(int i=0;i<4;i++)
    {
        int row_next=row+xmov[i];
        int col_next=col+ymov[i];
        if(safe(row_next,col_next))
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
int print_game()
{
    for(int i=0;i<game_size;i++)
    {
        for(int j=0;j<game_size;j++)
        {
            std::cout<<game[i][j]<<"\t";
        }
        std::cout<<"\n";
    }
}
int main()
{
    xmov={0,0,-1,1};
    ymov={1,-1,0,0};
    game={
        {0, -1, -1, -1},
        {0, 0, 0, -1},
        {0, -1, 0, 0},
        {-1, -1, -1, -1}
    };
    game_size=4;
    int sor_row;
    int sor_col;
    print_game();
    std::cout<<"Enter the source row\n";
    std::cout<<"Enter the source column\n";
    std::cout<<"Enter the destination row\n";
    std::cout<<"Enter the destination column\n";
    std::cin>>sor_row>>sor_col>>dest_row>>dest_col;
    if(game[sor_row][sor_col]==1)
    {
        std::cout<<"Mouse can't be on this block";
        return 0;
    }
    game[sor_row][sor_col]=1;
    if(game_(sor_row,sor_col,2))
    {
        print_game();
    }
    else
    {
        print_game();
        std::cout<<"It can't reach the destination";
    }
    return 0;
}
