#include "traversalUtil.h"


/** add the airport for the traversal to visit
 * airport - vertex to travel
 */
void BFS::add(const Vertex & airport) {
    travelPath.push(airport);
}