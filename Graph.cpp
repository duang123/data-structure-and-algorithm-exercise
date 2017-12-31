#include"Graph.h"

using namespace std;

void Graph::bfs(int v){
	bool* visited=new bool[V]();
	visited[v]=true;
	list<int>dq;
	dq.push_front(v);
	while(!dq.empty()){
		int i=dq.front();
		cout<<i<<",";
		dq.pop_front();
		for(auto it=adj[i].begin();it!=adj[i].end();++it)
			if(visited[*it]==false){
				dq.push_back(*it);
				visited[*it]=true;
			}  
	}
	delete[] visited;
	cout<<endl;
}

void Graph::dfs_helper(int v,bool visited[]){
	visited[v]=true;
	cout<<v<<",";
	for(auto i=adj[v].begin();i!=adj[v].end();++i){
		if(visited[*i]==false)
			dfs_helper(*i,visited);
	}
}

void Graph::dfs(int v){
	bool* visited=new bool[V]();
	dfs_helper(v,visited);
	delete[] visited;
	cout<<endl;
}
