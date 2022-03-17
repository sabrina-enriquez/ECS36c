#ifndef _FINDMAX_H
#define	_FINDMAX_H
#include "RunFind.h"
#include "vector.h"


class FindMax {
 public:
  FindMax(int citySize, const StreetBlock *streets, int numStreets);
  void find(Coordinate fireHouses[4], Coordinate *furthest, int *time);
 private:
  int streetCnt;

}; // class FindMax



struct Vertex
    {
    
    int ycoord;
    int xcoord;
    int time;
    bool known; //initialize all as false and only become known when reached using greedy algorithm
    int dist; //  distance to nearest firehouse
    Vertex* pv; // points to previous vertex
    bool firehouse; //if the vertex is a firehouse mark it true
    
    };


struct Edge
{
    Vertex* startVertex;
    Vertex* endVertex;
};


class Graph{
public:
    Graph( int adj_List[1000][1000]); //array of adjacency list of graph
    void addVertex( Vertex v);
    void addEdge( Edge e);
    void dijkstra( Vertex s );
    
}; //class graph
#endif	/* _FINDMAX_H */

