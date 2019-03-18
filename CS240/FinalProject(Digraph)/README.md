# CS240
## Final Project Digraph friend circle implementation
### Implementation of Digraph
- In our case each vertex of the Digraph is a persons name and the directed edges connecting
each vertex is a friendship between 2 people.

1. bool addVertex(string vertex); // adds vertex to diagraph
2. bool addEdge(int start, int term); // adds edge to diagraph
3. bool removeEdge(int start, int term); // removes edge from diagraph
4. bool findEdge(int start, int term); // find edge in diagraph
5. bool findVertex(string vertex); // find vertex in diagraph
6. int getNumOfVertices(); // returns number of vertices in diagraph
7. int getNumOfEdges(); // returns number of edges in diagraph;
8. vector<string> getVertices(); // returns vertices of diagraph;
9. vector<list<int> > getEdges(); // returns edges of digraph
10. list<int> getSuccessors(int start); // returns successors of a vertex
11. int getNumOfPredecessors(int start); // returns number of predecessors of a vertex
12. bool removeVertex(string vertex); // removes vertex from digraph

### Implementation of Circle.h

1. bool addMember(string name);
2. bool addFriendship(string friend1, string friend2);
3. void displayMembers();
4. void displayNumOfPeopleInCircle();
5. void displayNumOfFriendships();
6. bool isMember(string name);
7. void displayPersonsFriends(string name);
8. bool isP1FriendOfP2(string name1, string name2);
9. bool isP2FriendOfP1(string name1, string name2);
10. bool removePerson1FromPerson2(string name1, string name2);
11. void numOfPeopleFriendsOfPerson(string name);
12. bool removePersonFromCircle(string name);
13. int convertNameToNum(string name);
14. void quit();


### Testing
- To run this do
``` make
    ./run
```
