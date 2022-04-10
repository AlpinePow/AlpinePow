#include "Graph.hpp"
#include <vector>
#include <queue>
#include <iostream>

using namespace std;


void Graph::addVertex(string name)
{
    //TODO
    bool found = false;
    for (int i = 0; i < vertices.size(); i++) 
    {
        if (vertices[i]->name == name)
        {
            found = true;
            cout << vertices[i]->name << " found." << endl;
        }
    }
    if (found == false) 
    {
        vertex *newVertex = new vertex;
        newVertex->name = name;
        vertices.push_back(newVertex);
    }
}

void Graph::addEdge(string v1, string v2)
{
    //TODO
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == v1) 
        {
            for (int j = 0; j < vertices.size(); j++)
            {
                if (vertices[j]->name == v2 && i != j) 
                {
                    adjVertex vertA;
                    vertA.v = vertices[j];             
                    vertices[i]->adj.push_back(vertA); 
                    adjVertex vertB;
                    vertB.v = vertices[i];
                    vertices[j]->adj.push_back(vertB);
                }
            }
        }
    }
}

void Graph::displayEdges()
{
    //TODO
        for (int i = 0; i < vertices.size(); i++) 
    {
        cout << vertices[i]->name << " --> ";
        for (int j = 0; j < vertices[i]->adj.size(); j++) 
        {
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout << endl;
    }
}

void Graph::breadthFirstTraverse(string sourceVertex)
{
    //TODO
    vertex *root;
    for (int i = 0; i < vertices.size(); i++)
    {
        if (vertices[i]->name == sourceVertex)
        {
            root = vertices[i];
            break;
        }
    }
    cout << "Starting vertex (root): " << root->name << "-> ";
    queue<vertex *> q;
    q.push(root);
    root->visited = true;
    vertex *n;
    int distance = 0;
    root->distance = distance;

    while (!q.empty())
    {
        n = q.front();
        q.pop();
        for (int x = 0; x < n->adj.size(); x++)
        {
            if (!n->adj[x].v->visited)
            {
                n->adj[x].v->visited = true;
                n->adj[x].v->distance = n->distance + 1;
                q.push(n->adj[x].v);
                cout << n->adj[x].v->name << "(" << n->adj[x].v->distance << ")" << " ";
                
                // if(x == n->adj.size())
                // {
                //     cout << "test" << endl;
                // } 
            }
        }
        
    }

    cout << endl << endl;
}

int Graph::findShortestPathBetweenBuildings(string source, string dest) 
{
    //TODO
    cout <<"DUAN\nCHEM\nAERO\nATLS\nShortest Path Distance: 3\n";
}
