
// shortest path in a binary maze given source cell to a destination cell
#include <bits/stdc++.h>
using namespace std;
#define ROW 6
#define COL 6

//cell cordinates
struct Point
{
	int x;
	int y;
};

//queue used in BFS
struct Nodequeue
{
	Point pt; 
	int dist; 
};

// checking valid row and column

bool Valid(int row, int col)
{
	
	return (row >= 0) && (row < ROW) &&
		(col >= 0) && (col < COL);
}


// 4 neighbours of a given cell
int rowNum[] = {-1, 0, 0, 1};
int colNum[] = {0, -1, 1, 0};


// shortest path between a given source cell to a destination cell.
int search(int mat[][COL], Point src, Point dest)
{
	//source and destination cell must have value 1
	
	if (!mat[src.x][src.y] || !mat[dest.x][dest.y])
		return -1;

	bool visited[ROW][COL];
	memset(visited, false, sizeof visited);
	
	// Markingsource cell as visited
	visited[src.x][src.y] = true;

	//queue for BFS
	queue<Nodequeue> q;
	
	// Distance of source cell is 0
	Nodequeue s = {src, 0};
	q.push(s); 

	// BFS from source cell
	while (!q.empty())
	{
		Nodequeue curr = q.front();
		Point pt = curr.pt;

		// Ifdestination cell is reached
		
		if (pt.x == dest.x && pt.y == dest.y)
			return curr.dist;

		//else dequeue the front
		
		//enqueue adjacent cells
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int row = pt.x + rowNum[i];
			int col = pt.y + colNum[i];
			
			
			// enqueue non visited adjecent cell
			if (Valid(row, col) && mat[row][col] &&
			!visited[row][col])
			{
				
				visited[row][col] = true;
				Nodequeue Adcell = { {row, col},
									curr.dist + 1 };
				q.push(Adcell);
			}
		}
	}

	//destination cannot be reached
	return -1;
}


int driver(int *matrix,int *s1,int *s2, int *d1,int *d2)
{
	int mat[ROW][COL];

    for(int g1=0;g1<6;g1++)
    {
        
        for(int h=0;h<6;h++)
        {
            mat[g1][h]=*((matrix+g1*6) + h);
            
        }
        
    }

	Point source = {*s1, *s2};
	Point dest = {*d1, *d2};

	int dist = search(mat, source, dest);
    

	if (dist != -1)
		cout << "Shortest Path is " << dist ;
	else
		cout << "Path doesn't exist";

	return 0;
}
