#include <iostream>
using namespace std;
bool game[101][101];
int game_size;
int result;
int *xmov;
int *ymov;
void game_(int row,int col)
{
	if(row>=game_size-1 && col>=game_size-1)
	{
		result++;
		return;
	}
	int row_next;
	int col_next;
		for(int i=0;i<4;++i)
		{
			row_next=row+xmov[i];
			col_next=col+ymov[i];
			if(row_next>=0 && col_next>=0 && row_next<game_size && col_next<game_size && !game[row_next][col_next])
			{
				game[row_next][col_next]=true;
				game_(row_next,col_next);
				game[row_next][col_next]=false;
			}
		}
}
int main()
{
	std::cin>>game_size;
	result=0;
	xmov=new int[4]{0,0,-1,1};
	ymov=new int[4]{-1,1,0,0};
	for(int i=0;i<game_size;++i)
	{
		for(int j=0;j<game_size;++j)
		{
            std::cin>>game[i][j];
		}
	}
	game[0][0]=1;
	game_(0,0);

	std::cout<<result;
    return 0;
}
