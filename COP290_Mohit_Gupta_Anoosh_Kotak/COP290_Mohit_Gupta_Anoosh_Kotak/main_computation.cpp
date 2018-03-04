#include <bits/stdc++.h>
using namespace std;

/** @file */

/**
* A class for 3 dimensional vectors.
* Has three projections x y z.
*/
class graph2D;
class myvector{
public:

	float x_i; /**< A public float member representing x-projection.*/

	float y_i; /**< A public float member representing y-projection.*/

	float z_i; /**< A public float member representing z-projection.*/

	/**
	* A Constructor.
	* The constructor initialies the vector.
	* @param x the x-projection.
	* @param x the y-projection.
	* @param x the z-projection.
	*/
	myvector(int x,int y,int z);

	/**
	* A Member function which calculates dot product of two vectors.
	* Calculates dot product of the object vector and the arguement vector and returns a float value.
	* @param p A vector.
	* @return The dot product(float value)
	*/
	float dotproduct(myvector p);

	/**
	* A Member function which calculates cross product of two vectors.
	* Calculates cross product of the object vector and the arguement vector and returns a new vector.
	* @param p A vector.
	* @return The dot product(vector)
	*/
	myvector crossproduct(myvector p);

	myvector add(myvector p);

	myvector multiply(float n);

};

/**
* Class for representing a 3D labelled vertex
* The vertex has a label and 3 coordinates. 
* Used in constructing 3D graph.
*/
class vertex3D{

public:

	string label; /**< A public string label denoting name of each vertex.*/
	float x; /**< A public float member representing x-coordinate.*/
	float y; /**< A public float member representing y-coordinate.*/
	float z; /**< A public float member representing z-coordinate.*/

	/**
	* A Constructor.
	* The constructor which initialies the 3D vertex.
	* @param name the label.
	* @param x the x-coordinate.
	* @param y the y-coordinate.
	* @param z the z-coordinate.
	*/
	vertex3D(string name, float x,float y, float z);

	/**
	* A Member function which calculates the vector passing through two 3D vertices.
	* Calculates difference of the object vertex and the arguement vertex and returns a new vector.
	* @param p A 3D vertex.
	* @return The vector
	*/
	myvector diff_of_vertices(vertex3D* v); 

};

/**
* Class for representing a 2D labelled vertex
* The vertex has a label and 2 coordinates. 
* Used in constructing 2D graph.
*/
class vertex2D{

public:
	string label; /**< A public string label denoting name of each vertex.*/
	float x; /**< A public float member representing x-coordinate.*/
	float y; /**< A public float member representing y-coordinate.*/

	/**
	* A Constructor.
	* The constructor which initialies the 2D vertex.
	* @param name the label.
	* @param x the x-coordinate.
	* @param y the y-coordinate.
	*/
	vertex2D(string name, float x,float y);

	/**
	* A Member function which calculates the vector passing through two 2D vertices.
	* Calculates difference of the object vertex and the arguement vertex and returns a new vector.
	* @param p A 2D vertex.
	* @return The vector
	*/
	myvector diff_of_vertices(vertex2D* v); 

};

/**
* Class for a 3D plane.
* Will be taken from the user.
*/
class plane{

public:
	/**
	* A public myvector object.
	* Normal vector to the plane.
	* @see myvector
	*/
	myvector n;
	/**
	* A public myvector object.
	* 1st Coordinate axis along the plane.
	* @see myvector
	*/
	myvector e1;
	/**
	* A public myvector object.
	* 1st Coordinate axis along the plane.
	* @see myvector
	*/
	myvector e2;
	/**
	* A public vertex3D object.
	* A point on the plane.
	* @see vertex3D
	*/	
	vertex3D rp;

	/**
	* A Constructor.
	* The constructor has three arguements: a normal vector(n), point(rp), and one coordinate axis(e1).
	* The other coordinate axis(e2) is calculated by crossproduct.
	* @param a the normal vector.
	* @param p the point(3D vertex).
	* @param e1 the coordinate vector.
	* @see myvector
	* @see vertex3D
	*/
	plane(myvector a,vertex3D* p,myvector e1);

	/**
	* A Constructor.
	* The constructor has two arguements: a normal vector(n) and point(rp).
	* e1 is intialized ourselves.
	* The other coordinate axis(e2) is calculated by crossproduct.
	* @param a the normal vector.
	* @param p the point(3D vertex).
	* @see myvector
	* @see vertex3D
	*/
	plane(myvector a,vertex3D* p);
};

/**
* Class for 3D graph.
* @see vertex3D
*/
class graph3D{

private:

	int size; /**< A private integer member variable representing number of vertices in graph.*/

	std::vector< vertex3D* > vertices; /**< A private std:: vector of 3D vertices. */

	std::vector< std::vector<int> > edges; /**< A private std:: two dimensional vector of integers representing edge set. */

	std::vector< std::vector<vertex3D*> > faces; /**< A private std:: two dimensional vector of 3D vertices where each inner vertex is a face and thus,the whole member representing face set.*/

public:
	/**
	* A Constructor.
	* The constructor constructs the graph with one arguement: an integer which is the size of graph.
	* @param s the number of vertices.
	*/	
	graph3D(int s);

	/**
	* A Member function which adds the arguement 3D vertex to the graph.
	* @param a The 3D vertex to be added.
	*/
	void addvertex(vertex3D* a);

	/**
	* A Member function which adds an edge to graph.
	* @param a The end vertex of the edge to be added.
	* @param b The other end vertex of the edge to be added.
	* @param c An integer which is either 1(normal edge) or 0(no edge).
	*/
	void addedge(vertex3D* a,vertex3D* b, int c);

	/**
	* A Member function which adds a face to graph.
	* the vercor of 3D vertices is added to faces set of graph.
	* @param v The face to be added.
	*/
	void addface(std::vector<vertex3D*> v);

	/**
	* A Member function which returns the index of the arguement vertex else -1
	* @param a The 3D vertex.	
	* @return The index.
	*/

	int indexis(vertex3D* a);

	/**
	* A Member function which tells if a vertex is in the graph or not.
	* @param a The 3D vertex to be checked.
	* @return boolean type variable.
	*/
	bool isvertex(vertex3D* a);

	/**
	* A Member function which tells if an edge is in the graph or not.
	* @param a One end of the edge to be checked.
	* @param b Other end of the edge to be checked.
	* @return boolean type variable.
	*/
	bool isedge(vertex3D* a, vertex3D* b);

	/**
	* A Member function which tells if a face is in the graph or not.
	* @param v The face to be checked.
	* @return boolean type variable.
	*/
	bool isface(std::vector<vertex3D*> v);

	/**
	* A Member function which adds the 3D graph(only vertices) corresponding to a given set of three orthographic views (2D graph).
	* @param o1 The front view 2D graph.
	* @param o2 The top view 2D graph.
	* @param o3 The top view 2D graph.
	* @see graph2D
	*/
	void make_3Dgraph_with_vertices(graph2D o1, graph2D o2, graph2D o3);

	/**
	* A Member function which adds superset of edges to the 3D graph corresponding to a given set of three orthographic views (2D graph) by finding common edges.
	* This function will always be called after calling the make_3D_graph_with_vertices function.
	* @param o1 The front view 2D graph.
	* @param o2 The top view 2D graph.
	* @param o3 The top view 2D graph.
	* @see graph2D
	*/
	void intersection_method_add_edges(graph2D o1, graph2D o2, graph2D o3);

	/**
	* A Member function which adds superset of faces to the 3D graph from given edges, using minimum angle searching method.
	* This function will always be called after calling the intersection_method_add_edges function.
	* No parameters needed.
	*/
	void add_faces_from_projections();

	/**
	* A Member function which detects and removes the pseudo faces and edges, using the decision making rules.
	* This function will always be called after calling the add_faces_from_projections function.
	* No parameters needed
	*/
	void remove_pseudo_faces_edges();

	/**
	* A Member function which detects and removes the holes from the remaining faces using odd even rule.
	* This function will always be called after calling the remove_pseudo_faces_edges function.
	* No parameters needed
	*/
	void filter_holes();
	 
};

/**
* Class for 2D graph.
* @see vertex2D
*/
class graph2D{

private:
	int size; /**< A private integer member variable representing number of vertices in graph.*/
	std::vector< vertex2D* > vertices; /**< A private std:: vector of 3D vertices. */
	std::vector< std::vector<int> > edges; /**< A private std:: two dimensional vector of integers representing edge set. */

public:

	/**
	* A Constructor.
	* The constructor constructs the graph with one arguement: an integer which is the size of graph.
	* @param s the number of vertices.
	*/	
	graph2D(int s);

	/**
	* A Member function which adds the arguement 2D vertex to the graph.
	* @param a The 2D vertex to be added.
	*/
	void addvertex(vertex2D* a);

	/**
	* A Member function which adds an edge to graph.
	* @param a The end vertex of the edge to be added.
	* @param b The other end vertex of the edge to be added.
	* @param c An integer which is either 1(normal edge) or 2(hidden edge) or 0(no edge).
	*/
	void addedge(vertex2D* a,vertex2D* b, int c);

	/**
	* A Member function which returns the index of the arguement vertex else -1
	* @param a The 2D vertex.	
	* @return The index.
	*/
	int indexis(vertex2D* a);

	/**
	* A Member function which tells if a vertex is in the graph or not.
	* @param a The 2D vertex to be checked.
	* @return boolean type variable.
	*/
	bool isvertex(vertex2D* a);

	/**
	* A Member function which tells if an edge is in the graph or not.
	* @param a One end of the edge to be checked.
	* @param b Other end of the edge to be checked.
	* @return boolean type variable.
	*/
	bool isedge(vertex2D* a, vertex2D* b);

	/**
	* A Member function which adds the 2D graph(only vertices) corresponding to a given 3D graph and a projection plane.
	* Here we have taken the point(rp) in the plane as origin, so we get a 2D graph with asix (e1) and (e2).
	* @param g The 3D graph to be projected.
	* @param p The plane on which it is to be projected.
	* @see plane
	* @see vertex3D
	*/
	void make_2Dgraph_with_vertices(graph3D g,plane p);

	/**
	* A Member function which adds the corresponding edges in 2D graph(which has the projected vertices) w.r.t to a given 3D graph.
	* This function will always be called after calling the make_2D_graph_with_vertices function.
	* @param g The 3D graph though which edge are to be projected.
	* @see make_2Dgraph_with_vertices()
	*/
	void join_2D_edges(graph3D g);

	/**
	* A Member function filters hidden lines from the 2D graph.
	* This function will always be called after calling the make_2D_graph_with_vertices and join_2D_edges function.
	* Here, first we convert the 2D coordinates of 2D graph into 3D vertex, then we see if the projected 3Dvertex and 3Dvertex are on same side of any face in face set.
	* If yes, then edges from the vertex are done hidden.
	* @param g The 3D graph which contains the set of faces.
	* @param p The projected plane
	* @see join_2D_edges()
	* @see make_2Dgraph_with_vertices()
	*/
	void filter_hidden_lines(graph3D g,plane p);
};
