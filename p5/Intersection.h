//
// Created by Haley Chung on 3/10/2020.
//

#ifndef CITYFINDMAX__INTERSECTION_H_
#define CITYFINDMAX__INTERSECTION_H_

#include "RunFind.h"
#include "BinaryHeap.h"

class Intersection {
  struct Vertex
  {
    int ycoord;
    int xcoord;
    int time;
//    bool isKnown; //initialize all as false and only become known when reached using greedy algorithm
//    int dist; //  distance to nearest firehouse
//    bool firehouse; //if the vertex is a firehouse mark it true
  };

//  struct Edge
//  {
//    Vertex* startVertex;
//    Vertex* endVertex;
//  };

//  class Graph{
//   public:
//    Graph( int adj_List[1000][1000]); //array of adjacency list of graph
//    void addVertex( Vertex v);
//    void addEdge( Edge e);
//    void dijkstra( Vertex s );
//
//  }; //class graph
 public:
  explicit Intersection();
  Vertex adj[4];
  int count = 0;

//  void createDijkstras(int citySize, const StreetBlock *streets, int numStreets); // not sure about parameters
//  void addVertex( Vertex v);
//  void insertAdjList( Vertex adjVertex);
//  void createDijkstra( Vertex s );

 private:


};

#endif //CITYFINDMAX__INTERSECTION_H_
