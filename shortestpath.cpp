
#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;

class pt
{
 public :
 int x;
int y;
};

int main()
{
int grid[10][10] = {
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
    {-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}
};
int rows,cols;
cout<<"Enter rows: ";
cin>> rows;
cout<<"Enter columns: ";
cin>>cols;
for(int i=0;i<rows;i++){
    for(int j=0;j<cols;j++){
	cin>>grid[i][j];
    }
}
int dist[rows][cols];

for(int m = 0;m<rows;m++)
{
    for(int n =0;n<cols;n++)
    {
        dist[m][n] = -1;
    }
}
queue<pt> iterator;
pt xy;
xy.x = 0;
xy.y = 0;
dist[0][0] = 0;
iterator.push(xy);

while(!iterator.empty())
{
    xy = iterator.front();
    iterator.pop();
    for(int p = -1;p<2;p++)
    {
        for(int q = -1;q<2;q++)
        {
            if(p == q)continue;
            int i = xy.x + p;
            int j = xy.y + q;
            if(i<0)i=0;
            if(j<0)j=0;
            if(i>rows-1)i=rows-1;
            if(j>cols-1)j=cols-1;
            if(i== xy.x && j == xy.y)continue;
            if(dist[i][j] == -1)
            {
                if(grid[i][j] != 0)
                { 
                dist[i][j] = dist[xy.x][xy.y] + 1;
                pt xy2;
                xy2.x = i;
                xy2.y = j;  
                iterator.push(xy2);
                }
            }

        }
    }
}
struct path{
int a;
int b;
}ob[15];
int g,o,k,s,d;

for(s=0;s<rows;s++){
	for(d=0;d<cols;d++){
		if(grid[s][d]==2){
			o=s;
			k=d;
			break;
		}
	}
}
g=dist[o][k]-1;
ob[g+1].a=o;
ob[g+1].b=k;	
s=o;
d=k;
for(int i=dist[s][d]-1;i>-1;i--){
	if(g==dist[o-1][k])
		o--;
	else if(g==dist[o+1][k])
		o++;
	else if(g==dist[o][k-1])
		k--;
	else if(g==dist[o][k+1])
		k++;
	ob[i].a=o;
	ob[i].b=k;
	g--;
}
/*for (int i=0;i<rows;i++){
	for(int j=0;j<cols;j++){
		cout<<dist[i][j]<<" ";
	}
	cout<<"\n";
}*/
for(int i=1;i<=dist[s][d];i++){
	printf("Step %d:(%d,%d)\n",i,ob[i].a,ob[i].b);
}
printf("Shortest Distance: %d\n",dist[s][d]);
return 0;
}
