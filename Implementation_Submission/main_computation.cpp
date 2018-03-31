#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>
#include <fstream>
using namespace std;

/* A class representing a 3D vector. Functions: dotproduct, crossproduct, addvectors, multipybyscalar, mod */
class myvector{
public:

	float x_i; /**< A public float member representing x-projection.*/

	float y_i; /**< A public float member representing y-projection.*/

	float z_i; /**< A public float member representing z-projection.*/

	myvector(){

	}

	myvector(float x,float y,float z){
		x_i = x;
		y_i = y;
		z_i = z;
	}

	float dotproduct(myvector p){
		float a;
		a = (p.x_i)*(x_i) + (p.y_i)*(y_i) + (p.z_i)*(z_i);
		return a;
	}

	myvector crossproduct(myvector p){
		
		float a = (y_i)*(p.z_i) - (p.y_i)*(z_i);
		float b = (z_i)*(p.x_i) - (p.z_i)*(x_i);
		float c = (x_i)*(p.y_i) - (p.x_i)*(y_i);
		myvector temp(a,b,c);
		return temp;
	}

	myvector addvectors(myvector p){
		float a = x_i + p.x_i;
		float b = y_i + p.y_i;
		float c = z_i + p.z_i;
		myvector mw(a,b,c);
		return mw;
	}

	myvector multiplyvectors(float n){
		float a = n*x_i;
		float b = n*y_i;
		float c = n*z_i;
		myvector mw(a,b,c);
		return mw;
	}
	float mod(){
		float a = (x_i)*(x_i) + (y_i)*(y_i) + (z_i)*(z_i);
		float b = sqrtf(a);
		return b;
	}

};
/* A class representing 3D vertices. Functions: diff_of _vertices which returns the vector joining two 3D vertices*/
class vertex3D{

public:

	string label; /**< A public string label denoting name of each vertex.*/
	float x; /**< A public float member representing x-coordinate.*/
	float y; /**< A public float member representing y-coordinate.*/
	float z; /**< A public float member representing z-coordinate.*/

	vertex3D(){

	}

	vertex3D(string name, float xx,float yy, float zz){
		label = name;
		x = xx;
		y = yy;
		z = zz;
	}

	myvector diff_of_vertices(vertex3D* v){
		
		float a = v->x - x;
		float b = (v->y) - (y);
		float c = (v->z) - (z);
		myvector m(a,b,c);
		return m;
	}
};
/* A class representing 2D vertices.*/
class vertex2D{

public:
	string label; /**< A public string label denoting name of each vertex.*/
	float x; /**< A public float member representing x-coordinate.*/
	float y; /**< A public float member representing y-coordinate.*/

	vertex2D(){

	}

	vertex2D(string name, float xx,float yy){
		label = name;
		x = xx;
		y = yy;
	}

};
/* A class representing a 3D Plane. The plane has 3 members specified in the body
Functions: Two Constructors(one taking the orientation axis as input and other calculating it internally*/
class plane{

public:
	myvector n; /* Normal vector to the plane*/
	myvector e1; /* Axis on the plane along orientation of the view*/
	myvector e2; /* Axis on the plane perpendicular orientation of the view*/
	vertex3D* rp; /* A 3D point on the plane*/

	plane(){

	}
	/* User can specify the plane by telling normal vector, a point on the plane and an axis on the plane which specifies the orientation of the view*/
	plane(myvector a,vertex3D* p,myvector e11){
		e1 = e11;
		n = a;
		rp = p;
		e2 = n.crossproduct(e1);
	}
	/* User can specify the plane by telling normal vector and a point on the plane.(Here we choose the orientation internally)*/
	plane(myvector a,vertex3D* p){

		vertex3D* vtempp= new vertex3D("temp*",(p->x + 1),(p->y + 1),(((-a.x_i - a.y_i)/a.z_i) + p->z));
		e1.x_i = 1;
		e1.y_i = 1;
		e1.z_i = ((-a.x_i - a.y_i)/a.z_i);

	 	n = a;
	 	rp = p;
	 	e2 = n.crossproduct(e1);
	}
};
/* A class for storing the 3D graph*/
class graph3D{

public:

	int size; /**< A integer member variable representing number of vertices in graph.*/

	std::vector< vertex3D* > vertices; /**< A std:: vector of 3D vertices in the object. */

	std::vector< std::vector<int> > edges; /**< A std:: two dimensional vector of integers representing edge set of the object.(0 if no edge, 1 if edge) */

	std::vector< std::vector<string> > faces; /**< A std:: two dimensional vector of 3D vertices where each inner vector is a face and thus,the whole member representing face set of object.*/

	int numfaces; /* An integer storing the number of faces in the object*/

	int nmbvertices; /* An integer storing the number of vertices in the object*/

	graph3D(){

	}
	graph3D(int s){ /* Constructor to intialize the graph with s vertices, no edges, no faces*/
		nmbvertices = 0;
		numfaces = 0;
		size = s;
		vertices.resize(size);
		for (int i=0;i<size;i++)	// init vertices
			vertices[i] = NULL;
		int rows = size;
		int columns = size;
		edges.resize(rows, vector<int>(columns, 0));
	}

	int index_is(string a){ /* Function which tells the index of a vertex(represented by string a) in "vertices" vector. It returns -1 if vertex is not in graph*/
		int i = 0;
		while (i < nmbvertices)
			{
				if (((vertices[i])->label) == a)
					return i;
				i++;
			}
			return -1;
	}

	int addvertex(vertex3D* a){ /* Function which adds a 3D vertex to graph. Also it returns 1 if succedded else returns 0 or -1*/
		if (nmbvertices >= size){
			cout<<"Graph is full!";
			return -1;
		}
		int q = index_is(a->label);
		if(q!=-1){
			vertices[q]->x = a->x;
			vertices[q]->y = a->y;
			vertices[q]->z = a->z;
			return 0;
		}
		else{
			vertices[nmbvertices] = a;
			for (int i=0; i<size; i++)
			{
				edges[nmbvertices][i] = 0;
				edges[i][nmbvertices] = 0;
			}
			nmbvertices++;
			return 1;
		}

	}

	int addedge(string a,string b, int c){ /* Function which adds an edge between two vertices with given labels and weight. Also it returns 1 if succedded else returns -1*/
			int row;
			int column;

			row = index_is(a);
			column = index_is(b);
			if(row==-1){
				cout<<"Vertex 1 not in graph\n";
				return -1;
			}
			else if(column==-1){
				cout<<"Vertex 2 not in graph\n";
				return -1;
			}
			else{
				edges[row][column] = c;
				edges[column][row] = c;
				return 1;
			}

	}

	int weight_is(string a, string b)
	{ /* Function which returns the integer(weight) stored in the edge matrix at the given pair of vertices(strings). Returns -1 if any vertex is not in graph*/
		int row;
		int column;

		row = index_is(a);
		column = index_is(b);
		if(row==-1){
			cout<<"Vertex 1 not in graph\n";
			return -1;
		}
		else if(column==-1){
			cout<<"Vertex 2 not in graph\n";
			return -1;
		}
		else
		return edges[row][column];
	}

	bool isvertex(string a){ /* Function which tells if a vertex with given label is in the graph or not*/
		int i = index_is(a);
		if(i==(-1))
			return false;
		else
			return true;
	}

	bool isedge(string a, string b){ /* Function which tells if an edge joining given labels of vertices is in the graph or not*/
		int f = weight_is(a,b);
		if((f==-1) || (f==0))
			return false;
		else
			return true;
	}

	void addfaces(string str){/* Function which adds a face to the faces set given a string separated by spaces(labels of vertices that make the face in order)*/
		std::istringstream buf(str);
    	std::istream_iterator<std::string> beg(buf), end;
    	std::vector<std::string> l(beg, end);

		// std::sort(l.begin(), l.end());
		numfaces++;
		faces.push_back (l);
	}

	bool isface(std::vector<string> z){/* Function which tells if a face is in the graph or not*/
		std::vector<string> v1;
		v1 = z;
		v1.pop_back();
		std::sort(v1.begin(), v1.end());
		for(int i=0;i<numfaces;i++){
			std::vector<string> v2;
			v2 = faces[i];
			v2.pop_back();
			std::sort(v2.begin(), v2.end());
			if(v1==v2)
				return true;
		}
		return false;
	}
};
/* A class for storing the 2D graph*/
class graph2D{

public:
	int size; /**< A integer member variable representing number of vertices in graph.*/
	std::vector< vertex2D* > vertices; /**< A std:: vector of 2D vertices in the graph. */
	std::vector< std::vector<int> > edges; /**< A std:: two dimensional vector of integers representing edge set in the graph.(0 if no edge, 1 if edge, 2 if hidden edge) */
	int nmbvertices; /* An integer storing the number of vertices in the graph*/
	std::vector< std::vector<int> > overlapvertices; /**< A std:: two dimensional vector of integers. It has 1 at index i,j if vertices[i] and vertices[j] overlap in the projection else 0. */
	vector<bool> marks; /* A std:: vector of bools of size "size" which has true at index i if vertices[i] is a hidden vertex in the projection.*/

	graph2D(){

	}
	graph2D(int s){ /* Constructor to intialize the graph with s vertices, no edges, no marked vertices*/
		nmbvertices = 0;
		size = s;
		vertices.resize(size);
		for (int i=0;i<size;i++)	// init vertices
			vertices[i] = NULL;
		int rows = size;
		int columns = size;
		marks.resize(size);
		edges.resize(rows, vector<int>(columns, 0));
		overlapvertices.resize(rows, vector<int>(columns, 0));
	}

	int index_is(string a){ /* Function which tells the index of a vertex(represented by string a) in "vertices" vector. It returns -1 if vertex is not in graph*/
		int i = 0;
		while (i < nmbvertices)
			{
				if(((vertices[i])->label) == a)
					return i;
				i++;
			}
			return -1;
	}

	int addvertex(vertex2D* a){ /* Function which adds a 3D vertex to graph. Also it returns 1 if succedded else returns 0 or -1*/
		if (nmbvertices >= size){
			cout<<"Graph is full!";
			return -1;
		}
		int q = index_is(a->label);
		if(q!=-1){
			cout<<"Vertex already there!";
			return 0;
		}
		else{
			vertices[nmbvertices] = a;
			for (int i=0; i<size; i++)
			{
				edges[nmbvertices][i] = 0;
				edges[i][nmbvertices] = 0;
			}
			overlapvertices[nmbvertices][nmbvertices]=1;
			/* Loop for checking overlapping vertices to current vertex and modifying the edge set accordingly.*/
			for(int i=0;i<nmbvertices;i++){
				if(vertices[i]->x==a->x){
					if(vertices[i]->y==a->y){
						overlapvertices[i][nmbvertices]=1;
						overlapvertices[nmbvertices][i] = 1;
						edges[i][nmbvertices]=1;
						edges[nmbvertices][i]=1;
					}
				}
			}
			nmbvertices++;
			return 1;
		}
	}

	int addedge(string a,string b, int c){ /* Function which adds an edge between two vertices with given labels and weight. Also it returns 1 if succedded else returns -1*/
			int row;
			int column;

			row = index_is(a);
			column = index_is(b);
			if(row==-1){
				cout<<"Vertex 1 not in graph\n";
				return -1;
			}
			else if(column==-1){
				cout<<"Vertex 2 not in graph\n";
				return -1;
			}
			else if(edges[row][column]==1)
				return 1;
			else{
				edges[row][column] = c;
				edges[column][row] = c;
			/* Also, add the edges between any overlapping vertices to complete the edge set with all possible edges beteen overlapping ones.*/
			for(int i=0;i<size;i++){
				if(overlapvertices[row][i]==1){
					for(int j=0;j<size;j++){
						if(overlapvertices[column][j]==1){
							edges[i][j] = c;
							edges[j][i] = c;
						}
					}
				}
			}
			return 1;
		}
	}

	int weight_is(string a, string b)
	{/* Function which returns the integer(weight) stored in the edge matrix at the given pair of vertices(strings). Returns -1 if any vertex is not in graph*/
		int row;
		int column;

		row = index_is(a);
		column = index_is(b);
		if(row==-1){
			cout<<"Vertex 1 not in graph\n";
			return -1;
		}
		else if(column==-1){
			cout<<"Vertex 2 not in graph\n";
			return -1;
		}
		else
		return edges[row][column];
	}

	bool isvertex(string a){ /* Function which tells if a vertex with given label is in the graph or not*/
		int i = index_is(a);
		if(i==(-1))
			return false;
		else
			return true;
	}

	bool isedge(string a, string b){/* Function which tells if an edge joining given labels of vertices is in the graph or not*/
		int f = weight_is(a,b);
		if((f==-1) || (f==0))
			return false;
		else
			return true;
	}

	void clear_marks()
	{/* An extra function to reset the marks vector to false i.e no Hidden vertices or edges.*/
		for (int i=0;i<size;i++)
			marks[i] = false;
	}

	void mark_vertex(string a)
	{/* Function which marks a vertex as hidden.*/
		int ix = index_is(a);
		marks[ix] = true;
	}
	/* Function which given a 3D object and plane adds the corresponding projected vertices to the graph.*/
	void make_2Dgraph_with_vertices(graph3D g,plane p){
		int i;
		float a,b;
		vertex3D* v3 = p.rp;
		std::vector< vertex3D* > vs = g.vertices;
		myvector mv;
		int n = g.size;

		for (i=0;i < n;i++){
			mv = (*v3).diff_of_vertices((vs[i]));
			a = (p.e1).dotproduct(mv);
			b = (p.e2).dotproduct(mv);
			vertex2D* v2 = new vertex2D((vs[i]->label),a,b);
			addvertex((v2));
		}
	}
	/* Function which given a 3D object, then adds the corresponding edges between the projected vertices to the graph.*/
	void join_2D_edges(graph3D g){
		int s = g.size;
		for(int i=0;i<s;i++){
			for(int j=0;j<s;j++){
				if(g.edges[i][j]==1){
					if((vertices[i]->x)==(vertices[j]->x)&&(vertices[i]->y)==(vertices[j]->y))
						continue;
					else
						edges[i][j] = 1;
				}
			}
		}
	}
	/* A temporary function which is called by Filter_hidden =_lines function. Role is given a 2D vertex and a face. return 1 if the vertex lies inside the projected face else 0.*/
	int cn_PnPoly(vertex2D P, std::vector<string> Vstring )
	{	
		int n = Vstring.size() - 1;
	    int cn = 0;    // the  crossing number counter

	    // loop through all edges of the polygon
	    for (int i=0; i<n; i++) {    // edge from V[i]  to V[i+1]
	    	int a = index_is(Vstring[i]);
	    	int b = index_is(Vstring[i+1]);
	        if (((vertices[a]->y <= P.y) && (vertices[b]->y > P.y))     // an upward crossing
	         || ((vertices[a]->y > P.y) && (vertices[b]->y <=  P.y))) { // a downward crossing
	            // compute  the actual edge-ray intersect x-coordinate
	            float vt = (float)(P.y  - vertices[a]->y) / (vertices[b]->y - vertices[a]->y);
	            if (P.x <  vertices[a]->x + vt * (vertices[b]->x - vertices[a]->x)) // P.x < intersect
	                 ++cn;   // a valid crossing of y=P.y right of P.x
	        }
	    }
	    return (cn&1);    // 0 if even (out), and 1 if  odd (in)
	}
	/* Function which given a 3D object and plane, then filters out the hidden lines in the graph.*/
	void filter_hidden_lines(graph3D g,plane p){
		int i;
		for(i=0;i<size;i++){
			vertex3D* q = g.vertices[i];

			/* Find the 3D coordinates of 2D vertex(temp) i.e q_prime. */
			vertex2D* temp = vertices[i];
			myvector e11,e22;
			e11 = (p.e1).multiplyvectors(temp->x);
			e22 = (p.e2).multiplyvectors(temp->y);
			vertex3D* rptemp = p.rp;
			myvector d = myvector(rptemp->x,rptemp->y,rptemp->z);
			myvector e = e11.addvectors(e22);
			myvector f = d.addvectors(e);
			vertex3D* q_prime = new vertex3D(q->label,f.x_i,f.y_i,f.z_i);

			/* A loop which for given 2D vertex iterates to all the 3D faces of the 3D object and marks it if occluded by any face.*/ 
			for(int j=0;j<g.numfaces;j++){
				int lp = index_is((g.faces[j])[0]);
				int mp = index_is((g.faces[j])[1]);
				int np = index_is((g.faces[j])[2]);
				myvector e_1 = (*(g.vertices[lp])).diff_of_vertices(g.vertices[mp]);
				myvector e_2 = (*(g.vertices[lp])).diff_of_vertices(g.vertices[np]);
				myvector e_3 = (*(g.vertices[lp])).diff_of_vertices(q);
				myvector e_4 = (*(g.vertices[lp])).diff_of_vertices(q_prime);

				/* Condition to check 3D point and the projected point are on the same side of the face*/
				float det1 = (e_1.x_i)*((e_2.y_i)*(e_3.z_i) - (e_2.z_i)*(e_3.y_i)) - (e_1.y_i)*((e_2.x_i)*(e_3.z_i) - (e_2.z_i)*(e_3.x_i)) + (e_1.z_i)*((e_2.x_i)*(e_3.y_i) - (e_2.y_i)*(e_3.x_i));
				float det2 = (e_1.x_i)*((e_2.y_i)*(e_4.z_i) - (e_2.z_i)*(e_4.y_i)) - (e_1.y_i)*((e_2.x_i)*(e_4.z_i) - (e_2.z_i)*(e_4.x_i)) + (e_1.z_i)*((e_2.x_i)*(e_4.y_i) - (e_2.y_i)*(e_4.x_i));
				if((det1)*(det2)>0){
					int mn = cn_PnPoly(*temp,g.faces[j]);
					if(mn==1){
						mark_vertex(temp->label);
						break;
					}
				}
			}
		}
		/* Updates the edges passing from the vertex i.e makes the edges passing from a hidden vertex as hidden*/
		for(int rowt = 0;rowt<size;rowt++){
			for(int colt = 0;colt<size;colt++){
				if((edges[rowt][colt]==1)&&(rowt!=colt)){
					if(marks[rowt]||marks[colt]){
						edges[rowt][colt] = 2;
						edges[colt][rowt] = 2;
					}
				}
			}
		}
	}
};
	/* Special Function which given a 3D object generates the 3 orthographic projections using the functions above.*/
	void generate_orthographic_projections(graph2D* o1, graph2D* o2, graph2D* o3,graph3D* o){
		myvector xaxis(1,0,0);
		myvector yaxis(0,1,0);
		myvector zaxis(0,0,1);
		vertex3D* origin = new vertex3D("Origin",0,0,0);
		plane p1(zaxis,origin,xaxis);
		plane p2(xaxis,origin,yaxis);
		plane p3(yaxis,origin,zaxis);
		cout<<"kk\n";

		o1->make_2Dgraph_with_vertices(*o,p1);
		cout<<"kk\n";
		o1->join_2D_edges(*o);
		cout<<"kk\n";
		o1->filter_hidden_lines(*o,p1);
		cout<<"kk\n";

		o2->make_2Dgraph_with_vertices(*o,p2);
		o2->join_2D_edges(*o);
		o2->filter_hidden_lines(*o,p2);

		o3->make_2Dgraph_with_vertices(*o,p3);
		o3->join_2D_edges(*o);
		o3->filter_hidden_lines(*o,p3);

	}
	/* Function which given 3 orthographic projections, adds the vertices to the 3D object graph. Returns -1 if the given projections are inconsistent.*/
	int make_3Dgraph_with_vertices(graph2D o1, graph2D o2, graph2D o3,graph3D* o){
		if(o1.size!=o2.size){
			cout<<"Invalid projections";
			return -1;
		}
		else if(o1.size!=o3.size){
			cout<<"Invalid projections";
			return -1;
		}

		for (int i = 0; i < o1.size; i++)
		{	vertex2D* v_o1 = o1.vertices[i];
			vertex2D* v_o2 = o2.vertices[i];
			vertex2D* v_o3 = o3.vertices[i];

			if((v_o1->label==v_o2->label)&&(v_o2->label==v_o3->label)&&(v_o1->x==v_o3->y)&&(v_o1->y==v_o2->x)&&(v_o2->y==v_o3->x)){
			 float x = v_o1->x;
			 float y = v_o2->x;
			 float z = v_o3->x;
			 string sz = v_o1->label;
			 vertex3D* v = new vertex3D(sz,x,y,z);
			 o->addvertex(v);
			}
			else{
				cout<<"NON Matching Projections";
				return -1;
			}

		}
		return 1;
	}
	/* Function which given 3 orthographic projections, adds the edges to the 3D object graph.*/
	void intersection_method_add_edges(graph2D o1, graph2D o2, graph2D o3, graph3D* o){
		for(int i=0;i<o1.size;i++){
			for(int j=0;j<o1.size;j++){
				if((o1.edges[i][j]!=0)&&(o2.edges[i][j]!=0)&&(o3.edges[i][j]!=0)){
					o->edges[i][j] = 1;
					o->edges[j][i] = 1;
				}
			}
		}
	}
	/* Function which given 3D graph with vertices and edges, generates the true faces in the 3D graph.*/
	void add_faces_from_projections(graph3D* o){
		for(int i=0;i<o->size;i++){
			for(int j=0;j<o->size;j++){
				if((o->edges[i][j]==1)&&(i!=j)){
					for(int k=0;k<o->size;k++){
						if((k==j)||(k==i))
							continue;
						if((o->edges[j][k]==1)){
							std::vector<string> f1;
							f1.push_back ((o->vertices[i])->label);
							f1.push_back ((o->vertices[j])->label);
							f1.push_back ((o->vertices[k])->label);
							myvector e_i = (*(o->vertices[i])).diff_of_vertices(o->vertices[j]);
							myvector e_j = (*(o->vertices[j])).diff_of_vertices(o->vertices[k]);
							myvector n = e_i.crossproduct(e_j);
							int kt = k;
							int jt = j;
							while((kt!=i)&&(o->edges[jt][kt]==1)){
								myvector e_jtemp = (*(o->vertices[jt])).diff_of_vertices(o->vertices[kt]);
								float min = 0;
								int ind = -1;
								myvector e_k;
								for(int l=0;l<o->size;l++){
									if((l==jt)||(l==kt))
										continue;
									if(o->edges[kt][l]==1){
										myvector e_ktemp = (*(o->vertices[kt])).diff_of_vertices(o->vertices[l]);
										float fgh = e_ktemp.dotproduct(n);
										if(std::abs(fgh)<0.001){
											float zx = std::abs(e_ktemp.dotproduct(e_jtemp));
											zx = zx/(e_ktemp.mod());
											zx = zx/(e_jtemp.mod());
											if((zx - min)>=0){
												min = zx;
												ind = l;
												e_k = e_ktemp;
											}
										}
									}
								}
								if(ind==-1)
									break;
								jt = kt;
								kt = ind;
								f1.push_back ((o->vertices[kt])->label);
							}
							if(kt==i){
								bool bo = o->isface(f1);
								if(!bo){
								(o->faces).push_back(f1);
								o->numfaces++;
								}
							}
						}
					}
				}
			}
		}
	}
	/*---------------------------------------------------------------------------------------------
	The below commented code depicts the implementation of an approach to generate 3D object given that the input projections may be inconsistent
	or there are holes in the graph which then removes extre pseudo faces and edges.
	The purpose of these have been covered in the above functions.*/

	// int check_occlude(graph2D o1, graph3D g,int v1,int v2,plane p){
	// 	int i = v1;
	// 	while((i==v1)||(i==v2)){
	// 		vertex3D* q = g.vertices[i];
	// 		vertex2D* temp = o1.vertices[i];
	// 		// myvector e1temp = (p.e1);
	// 		// myvector e2temp = p.e2;
	// 		myvector e11,e22;
	// 		e11 = (p.e1).multiplyvectors(temp->x);
	// 		e22 = (p.e2).multiplyvectors(temp->y);
	// 		vertex3D* rptemp = p.rp;
	// 		myvector d = myvector(rptemp->x,rptemp->y,rptemp->z);
	// 		myvector e = e11.addvectors(e22);
	// 		myvector f = d.addvectors(e);
	// 		vertex3D* q_prime = new vertex3D(q->label,f.x_i,f.y_i,f.z_i); 
	// 		int flag = 0;
	// 		for(int j=0;j<g.numfaces;j++){
	// 			int lp = o1.index_is((g.faces[j])[0]);
	// 			int mp = o1.index_is((g.faces[j])[1]);
	// 			int np = o1.index_is((g.faces[j])[2]);
	// 			myvector e_1 = (*(g.vertices[lp])).diff_of_vertices(g.vertices[mp]);
	// 			myvector e_2 = (*(g.vertices[lp])).diff_of_vertices(g.vertices[np]);
	// 			myvector e_3 = (*(g.vertices[lp])).diff_of_vertices(q);
	// 			myvector e_4 = (*(g.vertices[lp])).diff_of_vertices(q_prime);

	// 			float det1 = (e_1.x_i)*((e_2.y_i)*(e_3.z_i) - (e_2.z_i)*(e_3.y_i)) - (e_1.y_i)*((e_2.x_i)*(e_3.z_i) - (e_2.z_i)*(e_3.x_i)) + (e_1.z_i)*((e_2.x_i)*(e_3.y_i) - (e_2.y_i)*(e_3.x_i));
	// 			float det2 = (e_1.x_i)*((e_2.y_i)*(e_4.z_i) - (e_2.z_i)*(e_4.y_i)) - (e_1.y_i)*((e_2.x_i)*(e_4.z_i) - (e_2.z_i)*(e_4.x_i)) + (e_1.z_i)*((e_2.x_i)*(e_4.y_i) - (e_2.y_i)*(e_4.x_i));
	// 			if((det1)*(det2)>0){
	// 				int mn = o1.cn_PnPoly(*temp,g.faces[j]);
	// 				if(mn==1){
	// 					flag = 1;
	// 					break;
	// 				}
	// 			}
	// 		}
	// 		if(flag==1){
	// 			if(i==v1){
	// 				i=v2;
	// 			}
	// 			else
	// 				break;
	// 		}
	// 		else{
	// 			return 0;
	// 		}
	// 	}
	// 	return 1;

	// }
	
	// void remove_pseudo_faces_edges(graph2D o1, graph2D o2, graph2D o3, graph3D* o){
	// 	myvector xaxis(1,0,0);
	// 	myvector yaxis(0,1,0);
	// 	myvector zaxis(0,0,1);
	// 	vertex3D* origin = new vertex3D("Origin",0,0,0);
	// 	plane p1(zaxis,origin,xaxis);
	// 	plane p2(xaxis,origin,yaxis);
	// 	plane p3(yaxis,origin,zaxis);

	// 	int i,j;
	// 	for(i=0;i<o->size;i++){
	// 		for(j=0;j<o->size;j++){
	// 			if(o->edges[i][j]==1){
	// 				string s_i = (o->vertices[i])->label;
	// 				string s_j = (o->vertices[j])->label;
	// 				if((o1.edges[i][j]==2)){
	// 					int o1_check= check_occlude(o1,*o,i,j,p1);
	// 					if(o1_check==0){
	// 						o->edges[i][j]=0;
	// 						o->edges[i][j]=0;
	// 						for(int k=0;k<(o->faces).size();k++){
	// 							int ff =0;
	// 							std::vector<string> vtemp;
	// 							vtemp = o->faces[k];
	// 							for(int l=0;l<vtemp.size();l++){
	// 								if(vtemp[l]==s_i){
	// 									if(l==0){
	// 										if((vtemp[vtemp.size()-2]==s_j)||(vtemp[1]==s_j)){
	// 											ff=1;
	// 											break;
	// 										}
	// 									}
	// 									else if((vtemp[l+1]==s_j)||(vtemp[l-1]==s_j)){
	// 										ff=1;
	// 										break;
	// 									}

	// 								}
	// 							}
	// 							if(ff==1){
	// 								(o->faces).erase ((o->faces).begin()+k);
	// 								o->numfaces--;
	// 							}
	// 						}
	// 						continue;
	// 					}
	// 				}
	// 				if((o2.edges[i][j]==2)){
	// 					int o2_check= check_occlude(o2,*o,i,j,p1);
	// 					if(o2_check==0){
	// 						o->edges[i][j]=0;
	// 						o->edges[i][j]=0;
	// 						for(int k=0;k<(o->faces).size();k++){
	// 							int ff =0;
	// 							std::vector<string> vtemp;
	// 							vtemp = o->faces[k];
	// 							for(int l=0;l<vtemp.size();l++){
	// 								if(vtemp[l]==s_i){
	// 									if(l==0){
	// 										if((vtemp[vtemp.size()-2]==s_j)||(vtemp[1]==s_j)){
	// 											ff=1;
	// 											break;
	// 										}
	// 									}
	// 									else if((vtemp[l+1]==s_j)||(vtemp[l-1]==s_j)){
	// 										ff=1;
	// 										break;
	// 									}

	// 								}
	// 							}
	// 							if(ff==1){
	// 								(o->faces).erase ((o->faces).begin()+k);
	// 								o->numfaces--;
	// 							}
	// 						}
	// 						continue;
	// 					}
	// 				}
	// 				if((o3.edges[i][j]==2)){
	// 					int o3_check= check_occlude(o3,*o,i,j,p1);
	// 					if(o3_check==0){
	// 						o->edges[i][j]=0;
	// 						o->edges[i][j]=0;
	// 						for(int k=0;k<(o->faces).size();k++){
	// 							int ff =0;
	// 							std::vector<string> vtemp;
	// 							vtemp = o->faces[k];
	// 							for(int l=0;l<vtemp.size();l++){
	// 								if(vtemp[l]==s_i){
	// 									if(l==0){
	// 										if((vtemp[vtemp.size()-2]==s_j)||(vtemp[1]==s_j)){
	// 											ff=1;
	// 											break;
	// 										}
	// 									}
	// 									else if((vtemp[l+1]==s_j)||(vtemp[l-1]==s_j)){
	// 										ff=1;
	// 										break;
	// 									}

	// 								}
	// 							}
	// 							if(ff==1){
	// 								(o->faces).erase ((o->faces).begin()+k);
	// 								o->numfaces--;
	// 							}
	// 						}							
	// 						continue;
	// 					}
	// 				}
	// 				int adjfaces = 0;
	// 				int faceindex = 0;
	// 				for(int r=0;r<(o->faces).size();r++){
	// 					std::vector<string> vtemp;
	// 					vtemp = o->faces[r];
	// 					for(int l=0;l<vtemp.size();l++){
	// 						if(vtemp[l]==s_i){
	// 							if(l==0){
	// 								if((vtemp[vtemp.size()-2]==s_j)||(vtemp[1]==s_j)){
	// 									adjfaces++;
	// 									faceindex = r;
	// 									break;
	// 								}
	// 							}
	// 							else if((vtemp[l+1]==s_j)||(vtemp[l-1]==s_j)){
	// 								adjfaces++;
	// 								faceindex =r;
	// 								break;
	// 							}
	// 						}
	// 					}
	// 				}
	// 				if(adjfaces==1){
	// 					o->edges[i][j]=0;
	// 					o->edges[i][j]=0;
	// 					(o->faces).erase ((o->faces).begin()+faceindex);
	// 					o->numfaces--;
	// 					continue;
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	// void filter_holes(graph3D* o);

