#include "MathRR.hpp"
#include <bits/stdc++.h>
#include <queue>
#include <iterator>
#include <map>
#include <list>

using namespace std;


void PRIM(int matrix[][1000], int n, int  start)
{
	unordered_set <int> Connected, Unconnected;
	int totalweight = 0;
	// them cac dinh tren do thi vao tap chua co tren cay
	for(int i = 0; i < n; i++)
	{
		Unconnected.insert(i);
	}
	Connected.insert(start);
	Unconnected.erase(start);
	int c, u, minc, minu;

	int min;
	while(!Unconnected.empty())
	{
		min = 99999;
		// can tim canh co trogn so nho nhat ma 1 dinh thuoc C và dinh thuoc U
		for (auto itr = Connected.begin(); itr != Connected.end(); ++itr) {
			c = *itr;

			for (int i=0; i<n; i++){
				if(matrix[i][c] != 0){
					if(Unconnected.find(i) != Unconnected.end())
					{
						int edgeweight = matrix[i][c];
						if(min>edgeweight)
						{
							min = edgeweight;
							minc = c;
							minu = i;
						}
					}
				}
					
			}
		}	
		printf(" %d -- %d;   weight %d\n",minu,minc,min);
		// bo sung them canh (minc, minu)
		totalweight = totalweight + min;
		Connected.insert(minu);
		Unconnected.erase(minu);	
	}
	printf("}\nTotal weight : %d\n",totalweight);	
}

void dijkstra(int matrix[][1000], int start, int  end, int n){
	
	// khoang cach tu start đen y[i] laf x[i], và di qua step[i] buoc.
	int x[10000];
	int y[10000];
	int step[10000];
	
	int visit[10000]; 		// danh dau dinh  da tham 
	int cnt = 0;    		// dùng dem buoc
	int l = 0;

	step[start] = 0;
	for(int i = 0; i < n; i++){
		visit[i] = 0;
	}
	
	typedef pair<int, int> pi;
	
	priority_queue<pi, vector<pi>, greater<pi> > Q;
	Q.push(make_pair(0,start));
	int v;
//	unordered_set <int> visitedList ;
	
	int currentWeight;
	while(!Q.empty())
	{
		pair<int, int> top = Q.top();
		v = top.second;

		Q.pop();
		if(visit[v]!= 0) continue;
		visit[v]= 1;
		
		currentWeight = top.first;
//		printf("%d %5d--> , total weight %d\n",step[v], v, currentWeight);
		{
			step[l] = step[v];
			x[l] = currentWeight;
			y[l] = v;
			l++;
		}
		if(v == end)
		{
			printf("Total : %d  \n", currentWeight);
			printf("Road: %d to %d:   ",start , end);
			
			int total =  step[l-1]; 
			int  s; 	  		// lưu vao mangr đuòng đi ngắn nhất			
			s = end;
			printf("%d <-  ", end);

			int h = 1;
			
			while(total){
				for(int i = 1; i < l; i++){

					if((step[i] == total-1) && (matrix[y[i]][s] != 0 )){

						printf("%d <- ", y[i]);
						s = y[i];
						break;
					}
				}
				total--;
		    }
			printf("%d", start);

			printf("\n");
	
			return;
		}
//		char output[10][10];
		for (int i = 0; i < n; i++) {
			if(matrix[v][i] != 0 && visit[i] == 0)
			{
				int edgeweight = matrix[v][i];
				Q.push(make_pair(currentWeight+edgeweight, i ));
				step[i] = step[v] + 1;
			}
		}
	}
}

void BFS(int matrix[][1000], int n, int start)
{
	queue<int> Q;
	Q.push(start);
	int v;
	unordered_set <int> visitedList ;
	
	visitedList.insert(start);
	
	while(!Q.empty())
	{	
		v = Q.front();
		printf("\n\t");
		Q.pop();

		for (int i=0; i<n; i++){
			if(matrix[i][v] != 0){
				if(visitedList.find(i) == visitedList.end())
				{
					printf("%d -- %d; \t", v, i);
					Q.push(i);
					visitedList.insert(i);
				}
			}		
		}
	}
}

//int main(){
//	int n,m;
//	int a, b, c, d;
//	int matrix[100][1000];
//	
//	cin >> n >> m;
//	
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < n; j++){
//			matrix[i][j] = 0;
//		}
//	}
//	for(int i = 0; i < m; i++){
//		cin >> a >> b >> c;
//		matrix[a][b] = c;
//		matrix[b][a] = c;
//	}
//	cin >> a >> b;
//	cin >> c >> d;
//	
//	printf("Dijsktra:\n");
//	dijkstra(matrix,a,c,n);
//	printf("\nPrim: \n");
//	PRIM(matrix, n, 1);
//	printf("\nBFS: ");
//	BFS(matrix, n, 1);
//	return 0;
//}

