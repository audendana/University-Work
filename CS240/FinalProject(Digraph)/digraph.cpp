#include <iostream>
#include<algorithm>
#include "digraph.h"
using namespace std;

Digraph::Digraph(){
    vertices = vector<string>(20);
    edges = vector<list<int> >(20);
    numOfVertices = 0;
    numOfEdges = 0;
    counter = 0;
}

bool Digraph::addVertex(string vertex){
    // if count == 0 this means the vertex is not in the list so we add it
    int countOf = count(vertices.begin(), vertices.end(), vertex);
    if(countOf != 0){
        return false;
    }
    vertices.at(counter) = vertex;
    counter++;
    numOfVertices++;
    return true;
}

bool Digraph::addEdge(int start, int term){
    // if count == 0 this means the edge is not in our list so we add it
    int countOf = count(edges[start].begin(), edges[start].end(), term);
    if(countOf != 0){
        return false;
    }
    edges[start].push_back(term);
    numOfEdges++;
    return true;
}

bool Digraph::removeEdge(int start, int term){
    int countOf = count(edges[start].begin(), edges[start].end(), term);
    if(countOf == 0){
        return false;
    }
    list<int>::iterator it = find(edges[start].begin(), edges[start].end(), term);
    edges[start].erase(it);
    numOfEdges--;
    return true;
}
bool Digraph::findEdge(int start, int term){
    int countOf = count(edges[start].begin(), edges[start].end(), term);
    if(countOf == 0){
        return false;
    }
    return true;
}
bool Digraph::findVertex(string vertex){
    int countOf = count(vertices.begin(), vertices.end(), vertex);
    if(countOf != 0){
        return true;
    }
    return false;
}

int Digraph::getNumOfVertices(){
    return numOfVertices;
}

int Digraph::getNumOfEdges(){
    return numOfEdges;
}

vector<string> Digraph::getVertices(){
    return vertices;
}

vector<list<int> > Digraph::getEdges(){
    return edges;
}

list<int> Digraph::getSuccessors(int start){
    return edges[start];
}

int Digraph::getNumOfPredecessors(int start){
    int retVal = 0;

    for(auto person : edges){
        int countOf = count(person.begin(), person.end(), start);
        retVal+= countOf;
    }
    return retVal;
}

bool Digraph::removeVertex(string name){
    if(!findVertex(name)){
        return false;
    }
    vector<string>::iterator it = find(vertices.begin(), vertices.end(), name);
    vertices.erase(it);
    numOfVertices--;
    return true;

}
