// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<unordered_set>
#include<stack>
#include<set>

using namespace std;

typedef map<int, vector<int> >::iterator it_type;

unordered_map<string, int> dp;


int flag = 0;

vector<pair<int, int> > edges;

struct Node
{
	int data = 0;
	int rank = 0;

	struct Node* parent;	
};


struct Node* findSet(Node &node)
{
	if (node.parent == &node)
	{
		return node.parent;
	}


	node.parent = findSet(*node.parent);

	return node.parent;


}

void unionSet()
{

}

void makeSet()
{

}



void enterNewNode(int a, map<int, vector<int> > &g)
{
	vector<int> temp;
	g[a] = temp;
	
	map<int, vector<int> >::iterator i;

	return;

}


void viewAllConnectedNodes(map<int, vector<int> > &g, int a)
{
	for (unsigned int i = 0; i < g[a].size(); i++)
	{
		cout << g[a][i] << " ";
	}
	cout << endl;
}

/*

void bfs(map<int, vector<int> > &g, int a)
{
	unordered_map<int, int> visited;


	list<int> queue;

	queue.push_back(a);

	while (!queue.empty())
	{
		int s = queue.front();
		cout << s << " ";
		queue.pop_front();
		visited[s] = 1;

		for (int i = 0; i < g[s].size(); i++)
		{
			if (!visited[g[s][i]])
			{
				queue.push_back(g[s][i]);
			}
		}


	}

	cout << endl;

}


void dfs(unordered_map<int, int> &visited, map<int, vector<int> > &g, int s)
{
	visited[s] = 1;
	cout << s << " ";

	for (int i = 0; i < g[s].size(); i++)
	{
		if (!visited[g[s][i]])
		{
			dfs(visited, g, g[s][i]);
		}
	}
}

void DFS(map<int, vector<int> > &g, int s)
{
	unordered_map<int, int> visited;

	map<int, vector<int> >::iterator i;

	for (i = g.begin(); i != g.end(); i++)
	{
		if (!visited[i->first])
		{
			dfs(visited, g, i->first);
		}
	}

}

int cyclicUtil(unordered_map<int, int> &visited, unordered_map<int, int> &recStack, map<int, vector<int> > &g, int s)
{
	if (!visited[s])
	{
		recStack[s] = 1;
		visited[s] = 1;

		//cout << s << endl;

		for (int i = 0; i < g[s].size(); i++)
		{
			if (!visited[g[s][i]] && (cyclicUtil(visited, recStack, g, g[s][i]) == 1))
			{
				return 1;
			}
			else
				if (recStack[g[s][i]] == 1)
				{
					return 1;
				}

			recStack[g[s][i]] = 0;
		}
	}

	recStack[s] = 0;

	return 0;
}

int isCyclic(map<int, vector<int> > &g)
{
	unordered_map<int, int> visited;
	unordered_map<int, int> recStack;

	map<int, vector<int> >::iterator i;

	for (i = g.begin(); i != g.end(); i++)
	{

		if (!visited[i->first])
		{
			if (cyclicUtil(visited, recStack, g, i->first))
				return 1;
		}

	}

	return 0;
}

*/

void addEdge(map<int, vector<int> > &g, int a, int b)
{
	g[a].push_back(b);
	//g[b].push_back(a);

	edges.push_back(pair<int, int>(a, b));

}

struct Node* createNode()
{
	Node* node = new Node;
	return node;
}

map<int,Node*> makeDisjointSet(map<int, vector<int> > &g)
{
	map<int,Node*> sets;

	for (it_type i = g.begin(); i != g.end(); i++)
	{
		Node *node = createNode();
		
		node->data = i->first;
		node->parent = node;
		node->rank = 0;

		sets[i->first] = node;

	}


	return sets;



}

int ifCycle(map<int, vector<int> > &g, map<int, Node*> &set)
{
	Node* one;
	Node* two;

	for (int i = 0; i < edges.size(); i++)
	{
		
		one = findSet(*set[edges[i].first]);	
		
		two = findSet(*set[edges[i].second]);
		
		

		if (one->parent == two->parent)
		{
			return 1;
		}


		if (one->rank >= two->rank)
		{
			one->rank = (one->rank == two->rank) ? one->rank + 1 : one->rank;
			two->parent = one->parent;	
		

		}
		else
		{
			one->parent = two->parent;
		}


	}



	return 0;
}

void sortUtil(map<int, vector<int> > &g,stack<int> &s, vector<int> &visited,int i)
{
	visited[i] = 1;
	if (i == 0)
	
	for (int j = 0; j < g[i].size(); j++)
	{
		//cout << i << " " << j << endl;

		if(!visited[g[i][j]])
		sortUtil(g, s, visited, g[i][j]);
	}

	
	s.push(i);

}

void topologicalSort(map<int,vector<int>> &g)
{
	vector<int> visited(g.size());

	stack<int> s;

	for (it_type i = g.begin(); i != g.end(); i++)
	{
		
		if (!visited[i->first])
		{		
			//cout << i->first << endl;
			sortUtil(g, s,visited,i->first);
		}
	}

	while (!s.empty())
	{
		cout << s.top() << endl;
		s.pop();
	}

}

struct GraphNode
{
	int data;
	vector<pair<GraphNode *,int>> neighbours;

	GraphNode(int x) : data(x) {};

};

void dijsktra(map<int, GraphNode*> &graph, GraphNode* node)
{
	set<pair<int,GraphNode*>> final;
	map<GraphNode*, int> dist;

	for (map<int, GraphNode*>::iterator i = graph.begin(); i != graph.end(); i++)
	{
		dist[i->second] = INT_MAX;

	}

	dist[node] = 0;

	final.insert(make_pair(0,node));

	while (!final.empty())
	{
		pair<int, GraphNode*> temp = *(final.begin());
		final.erase(final.begin());

		for (int i = 0; i < temp.second->neighbours.size(); i++)
		{
			//cout << temp.first << endl;
			if (temp.second->neighbours[i].second + temp.first < dist[temp.second->neighbours[i].first])
			{
				
				if (dist[temp.second->neighbours[i].first] != INT_MAX)
				{
					final.erase(final.find(make_pair(dist[temp.second->neighbours[i].first], temp.second->neighbours[i].first)));
				}

				dist[temp.second->neighbours[i].first] = temp.second->neighbours[i].second + temp.first;
				final.insert(make_pair(dist[temp.second->neighbours[i].first], temp.second->neighbours[i].first));
			}
		}

	}


	for (map<GraphNode*, int>::iterator i = dist.begin(); i != dist.end(); i++)
	{
		cout<< i->first->data <<" "<< i->second<< endl;
	}




}


/*   BELLMAN FORD	
INPUT: GRAPH,SRC,NUMBER OF EDGES
OUTPUT: DISTANCE MAP CORRESPONDING TO SHORTEST DISTANCE FROM SRC FROM EACH NODE
*/

map<GraphNode*, int> bellmanFord(map<int, GraphNode*> &graph, GraphNode* node)
{
	//instantiating the distance map and edge list
	map<GraphNode*, int> dist;
	vector<pair<pair<GraphNode*,GraphNode*>,int>> edgeList;

	for (map<int, GraphNode* >::iterator i = graph.begin(); i != graph.end(); i++)
	{
		dist[i->second] = INT_MAX;
		for (int j = 0; j < i->second->neighbours.size(); j++)
		{
			int weight = i->second->neighbours[j].second;
			GraphNode* v = i->second->neighbours[j].first;

			edgeList.push_back(make_pair(make_pair(i->second, v), weight));
		}
		

	}

	dist[node] = 0;

	for (int i = 0; i < graph.size(); i++)
	{
		for (int j = 0; j < edgeList.size();j++)
		{
			if (dist[edgeList[j].first.second] > dist[edgeList[j].first.first] + edgeList[j].second)
			{
				dist[edgeList[j].first.second] = dist[edgeList[j].first.first] + edgeList[j].second;
			}
		}
	}

	for (int j = 0; j < edgeList.size(); j++)
	{
		if (dist[edgeList[j].first.second] > dist[edgeList[j].first.first] + edgeList[j].second)
		{
			cout << "Edge cycle detected,Invcalid Graph" << endl;
			break;
		}
	}

	return dist;

}

int main()
{

	map<int, GraphNode*> graph;

	GraphNode* root = new GraphNode(1);
	GraphNode* node = new GraphNode(2);
	GraphNode* node1 = new GraphNode(3);
	GraphNode* node2 = new GraphNode(4);

	graph[1] = root;
	graph[2] = node;
	graph[3] = node1;
	graph[4] = node2;

	root->neighbours.push_back(make_pair(node,2));
	root->neighbours.push_back(make_pair(node2, 3));
	node->neighbours.push_back(make_pair(node1, 3));
	node1->neighbours.push_back(make_pair(node2, 1));
	node2->neighbours.push_back(make_pair(node1, 1));

	//cout << ifCycle(g, sets) << endl;
	dijsktra(graph, root);
	cout << endl;
	map<GraphNode*, int> dist = bellmanFord(graph, root);

	for (map<GraphNode*, int>::iterator i = dist.begin(); i != dist.end(); i++)
	{
		cout << i->first->data << " " << i->second << endl;
	}


	system("PAUSE");
	return 0;
}
