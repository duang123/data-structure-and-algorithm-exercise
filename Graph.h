#include<list>
#include<iostream>
//#include<new>

class Graph{
public:
	Graph(int v):V(v),adj(new std::list<int>[v]){}
	void addEdge(int v,int w){
		adj[v].push_back(w);
	}
	void bfs(int v);
	void dfs(int v);
private:
	int V;
	std::list<int>*adj;
	void dfs_helper(int v,bool visited[]);
};
