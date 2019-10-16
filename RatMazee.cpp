#include <iostream>
using namespace std;

void printSolution(int **solution, int N){
	for(int i=0; i<N;i++){
		for(int j=0; j<N; j++)
			cout<<solution[i][j]<<"\t";
		cout<<endl;
	}//end of for
}//end of method

void ratMaze(int **maze, int **solution, int N, int x,int y){
	if(x==N-1 && y==N-1){
		solution[x][y] = 1;
		printSolution(solution,N);
		return;
	}//end of if
	if(x<0 || x>N-1 || y<0 || y>N-1 || maze[x][y]==0 || solution[x][y]==1) return;
	
	solution[x][y]=1;
	ratMaze(maze,solution,N,x,y+1); //right, i.e, forward
	ratMaze(maze,solution,N,x+1,y); //down
	
	
	solution[x][y]=0;
}//end of method

int main(){
	int N, **maze, **solution;
	cout<<"Enter size of matrix :";
	cin>>N;
	maze = new int*[N];
	for(int i =0; i<N; i++)
		maze[i] = new int[N];
	solution = new int*[N];
	for(int i =0; i<N; i++)
		solution[i] = new int[N];
	cout<<"Enter maze :\n";
	for(int i=0; i<N; i++)
		for(int j=0;j<N;j++)
			cin>>maze[i][j];
	ratMaze(maze,solution,N,0,0);
	return 0;
}//end of main

/*
OUTPUT:
Enter size of matrix :4
Enter maze :
1 0 0 0
1 1 0 1
0 1 0 0
1 1 1 1
1	0	0	0	
1	1	0	0	
0	1	0	0	
0	1	1	1
*/










/* #include<iostream>
using namespace std;
bool isSafe(int r,int c,int n,int **maze)
{
   if( r < 0 || r >= n )
       return false;
   if( c < 0 || c >= n )
       return false;
   if(maze[r][c])
       return true;
   return false;
}
bool solvemaze(int ** maze,int i,int j,int ** soln,int n)
{
   if(i == n-1 && j == n-1)
   {
       soln[i][j]=1;
       return true;
   }
   if(isSafe(i,j,n,maze))
   {
       soln[i][j]=1;
       if(solvemaze(maze,i+1,j,soln,n))
           return true;
       if(solvemaze(maze,i,j+1,soln,n))
           return true;
       soln[i][j]=0;
   }
   return false;
}
int main()
{
   int n;
   cin>>n;
   int** maze = new int*[n];
   for(int i = 0; i < n; ++i)
       maze[i] = new int[n];
   int** soln = new int*[n];
   for(int i = 0; i < n; ++i)
       soln[i] = new int[n];
   for(int i=0;i<n;i++)
   {
       for(int j=0;j<n;j++)
       {
           cin>>maze[i][j];
           soln[i][j]=0;
       }
   }
   if(solvemaze(maze,0,0,soln,n))
   {
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
               cout<<soln[i][j]<<"\t";
           cout<<endl;
       }
   }
   else
   {

       return -1;
   }
} */
