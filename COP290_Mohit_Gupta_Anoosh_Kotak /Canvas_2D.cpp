#include <bits/stdc++.h>
using namespace std;
/** @file */

/**
*An input file is converted into 3 2D graphs.
*/

class inputfile_to_2D_graphs{
public:
	/** The input file will consist of 3 lists and each element of a list will consists of 2 co-ordinates having edges between them.
	* The co-ordinates of the first list will be stored in the Vertex set of the first graph.
	* The edges will be stored in the edge set after giving them weight according to the distance(which will be calculated) between 2 vertices.
	* Similarly, the graphs for other lists will also be generated.
	* The graphs generated will be objects graph2D class.
	* @see graph2D
	*/
	void generate_2D_graph();
		
};
