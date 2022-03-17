// Author Sean Davis

#include "FindMax.h"
#include "Intersection.h"
#include <cstdlib>

FindMax::FindMax(int citySize, const StreetBlock *streets, int numStreets)
{
  Intersection intersections[1000][1000];
  for (int i = 0; i < numStreets; i++) {
    Intersection &startInt = intersections[streets[i].startY][streets[i].startX];
    startInt.adj[startInt.count].xcoord = streets[i].endX;
    startInt.adj[startInt.count].ycoord = streets[i].endY;
    if (startInt.adj[startInt.count].xcoord != streets[i].endX && startInt.count <= 4) {
      startInt.adj[startInt.count++].time = (1000000 * std::abs(startInt.adj[startInt.count].xcoord - streets[i].startX)) / streets[i].speed;
    }
    else {
      startInt.adj[startInt.count++].time = (1000000 * std::abs(startInt.adj[startInt.count].ycoord - streets[i].startY)) / streets[i].speed;
    }

    Intersection &endInt = intersections[streets[i].endY][streets[i].endX];
    endInt.adj[endInt.count].xcoord = streets[i].startX;
    endInt.adj[endInt.count].ycoord = streets[i].startY;
    if (endInt.adj[startInt.count].xcoord != streets[i].startX && startInt.count <= 4) {
      endInt.adj[endInt.count++].time = (1000000 * std::abs(endInt.adj[endInt.count].xcoord - streets[i].endX)) / streets[i].speed;
    }
    else {
      endInt.adj[endInt.count++].time = (1000000 * std::abs(endInt.adj[endInt.count].ycoord - streets[i].endY)) / streets[i].speed;
    }
  }

} // FindMax()

void FindMax::find(Coordinate fireHouses[4], Coordinate *furthest, int *time)
{

} // find()




//
//
//   void Graph::dijkstra( Vertex s ) //add vertex v to the heap and update
//  {
//      for (int i = 0; i < 1000000; i++)
//        {
//            vertices[i].dist = INFINITY;
//        v.known = false;
//        }
//    s.dist = 0;
//    while( there is an unknown distance vertex )
//    {
//      Vertex v = smallest unknown distance vertex;
//      v.known = true;
//      for each Vertex w adjacent to v
//      if( !w.known )
//      {
//        DistType cvw = cost of edge from v to w;
//        if( v.dist + cvw < w.dist )
//        {
//// Update w
//          decrease( w.dist to v.dist + cvw );
//          w.path = v;
//        }
//      }
//    }
//  }
//

