// file digraph.h
#ifndef DIGRAPH_
#define DIGRAPH_

#include<utility>
#include<vector>
#include<list>
using namespace std;

class Digraph{
    public:
        Digraph();  // create empty diagraph
        bool addVertex(string vertex); // adds vertex to diagraph
        bool addEdge(int start, int term); // adds edge to diagraph
        bool removeEdge(int start, int term); // removes edge from diagraph
        bool findEdge(int start, int term); // find edge in diagraph
        bool findVertex(string vertex); // find vertex in diagraph
        int getNumOfVertices(); // returns number of vertices in diagraph
        int getNumOfEdges(); // returns number of edges in diagraph;
        vector<string> getVertices(); // returns vertices of diagraph;
        vector<list<int> > getEdges(); // returns edges of digraph
        list<int> getSuccessors(int start); // returns successors of a vertex
        int getNumOfPredecessors(int start); // returns number of predecessors of a vertex
        bool removeVertex(string vertex); // removes vertex from digraph

    private:
        vector<string> vertices;
        vector<list<int> > edges;
        int numOfVertices;
        int numOfEdges;
        int counter;
};

#endif



