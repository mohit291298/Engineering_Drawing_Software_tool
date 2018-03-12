#include "main_computation.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iterator>
#include <cmath>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <QtCore>
#include <QtGui>

using namespace Qt;

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   QLabel l;
   QPicture pi;
   QPainter p(&pi);

   p.setRenderHint(QPainter::Antialiasing);
   p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
    p.drawLine(-800, 0, 800, 0);
    p.drawLine(0, -600, 0, 600);
    string STRING;
    ifstream infile ( "input.txt" );
    if (!infile)
    {
        cout << "There was a problem opening the file. Press any key to close.\n";
        return 0;
    }
    infile>>STRING;
    if(STRING=="1"){
        
        int num;
        infile>>num;
        graph3D g2(num);
        string l;
        float x,y,z;
        for(int i=0;i<num;i++){
            infile>>l;
            infile>>x;
            infile>>y;
            infile>>z;
            vertex3D* v= new vertex3D(l,x,y,z);
            g2.addvertex(v);
        }
        int c;
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                infile>>c;
                g2.edges[i][j] = c;
            }
        }
        string str;
        getline(infile, str);
         while(getline(infile, str)&&(str!="1")&&(str!="2")) 
        {
            
            g2.addfaces(str);

        }
        cout<<g2.numfaces;
        cout<<"Your input 3D object vertices are:FORMAT(Label x_coordinate y_coordinate z_coordinate)\n";
        for(int i=0;i<num;i++){
        vertex3D* k = g2.vertices[i];
        cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
    }
            cout<<"Your input 3D object edge matrix is :FORMAT(1 if there exists an edge, 0 if there does not)\n";
    for (int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout<<g2.edges[i][j]<<" ";
        }
        cout<<"\n";
    }
            cout<<"No. of faces in 3D object"<<g2.numfaces<<"\n";
            cout<<"The faces in input 3D object are as follows\n";
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                cout<<g2.faces[i][j]<<" ";
            }
            cout<<"\n";
        }


    if(str=="1"){
            graph2D o11(g2.size);
    graph2D o21(g2.size);
    graph2D o31(g2.size);
        generate_orthographic_projections(&o11,&o21,&o31,&g2);
        vertex2D* v1;
        vertex2D* v2;
        for(int i=0;i<o11.size;i++){
            for(int j=i;j<o11.size;j++){
                if(o11.edges[i][j]!=0){
                    if(o11.edges[i][j]==2){
                           p.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
                    }
                    v1 = o11.vertices[i];
                    v2 = o11.vertices[j];
                    p.drawLine(100*v1->x, -100*(v1->y ), 100*v2->x , -100*(v2->y));
                       p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
                }
            }
        }
        for(int i=0;i<o21.size;i++){
            for(int j=i;j<o21.size;j++){
                if(o21.edges[i][j]!=0){
                    if(o21.edges[i][j]==2){
                           p.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
                    }

                    v1 = o21.vertices[i];
                    v2 = o21.vertices[j];
                    p.drawLine(-100*(v1->x), 100*(v1->y), -100*(v2->x), 100*(v2->y));
                       p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
                }
            }
        }
        for(int i=0;i<o31.size;i++){
            for(int j=i;j<o31.size;j++){
                if(o31.edges[i][j]!=0){
                    if(o31.edges[i][j]==2){
                           p.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
                    }
                    v1 = o31.vertices[i];
                    v2 = o31.vertices[j];
                    p.drawLine(100*v1->y, 100*(v1->x), 100*v2->y, 100*(v2->x));
                       p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
                }
            }
        }
        cout<<"Here's the x-y projection\n";
        cout<<"The vertices of x-y projection are:\n";
                    for(int i=0;i<num;i++){
            vertex2D* k = o11.vertices[i];
            cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
        }
        cout<<"The edge matrix of x-y projection is:(0 if no edge,1 is edge,2 if hidden line)\n";
        for (int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                cout<<o11.edges[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"Here's the y-z projection\n";
        cout<<"The vertices of x-y projection are:\n";
            for(int i=0;i<num;i++){
            vertex2D* k = o21.vertices[i];
            cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
        }
                cout<<"The edge matrix of y-z projection is:(0 if no edge,1 is edge,2 if hidden line)\n";
        for (int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                cout<<o21.edges[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"Here's the z-x projection\n";
        cout<<"The vertices of z-x projection are:\n";
            for(int i=0;i<num;i++){
            vertex2D* k = o31.vertices[i];
            cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
        }
                cout<<"The edge matrix of z-x projection is:(0 if no edge,1 is edge,2 if hidden line)\n";
        for (int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                cout<<o31.edges[i][j]<<" ";
            }
            cout<<"\n";
        }
    }
    else if(str=="2"){
        graph2D plane_graph(g2.size);
        float c1,c2,c3;
        string la1;
        infile>>c1;
        infile>>c2;
        infile>>c3;
        myvector n_tem(c1,c2,c3);
        infile>>c1;
        infile>>c2;
        infile>>c3;
        myvector e1_tem(c1,c2,c3);
        infile>>la1;
        infile>>c1;
        infile>>c2;
        infile>>c3;
        vertex3D* coor = new vertex3D(la1,c1,c2,c3);
        plane pla(n_tem,coor,e1_tem);
        plane_graph.make_2Dgraph_with_vertices(g2,pla);
        cout<<"kk\n";
        plane_graph.join_2D_edges(g2);
        cout<<"kk\n";
        plane_graph.filter_hidden_lines(g2,pla);

        vertex2D* v1;
        vertex2D* v2;
        for(int i=0;i<plane_graph.size;i++){
            for(int j=i;j<plane_graph.size;j++){
                if(plane_graph.edges[i][j]!=0){
                    if(plane_graph.edges[i][j]==2){
                           p.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
                    }
                    v1 = plane_graph.vertices[i];
                    v2 = plane_graph.vertices[j];
                    p.drawLine(100*v1->x +10, -100*(v1->y ) -10, 100*v2->x + 10, -100*(v2->y) -10);
                       p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
                }
            }
        }
                cout<<"Here's the projected figure\n";
        cout<<"The vertices of projection are:\n";

        for(int i=0;i<plane_graph.size;i++){
            vertex2D* k = plane_graph.vertices[i];
            cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
        }
        cout<<"The edge matrix of projection is:(0 if no edge,1 is edge,2 if hidden line)\n";
        for (int i=0;i<plane_graph.size;i++){
            for(int j=0;j<plane_graph.size;j++){
                cout<<plane_graph.edges[i][j]<<" ";
            }
            cout<<"\n";
        }

    }
    }
    else if(STRING=="2"){
        int num;
        infile>>num;
        graph2D h1(num);
        graph2D h2(num);
        graph2D h3(num);
        string l;
        float x,y;
        for(int i=0;i<num;i++){
            infile>>l;
            infile>>x;
            infile>>y;
            vertex2D* v= new vertex2D(l,x,y);
            h1.addvertex(v);
        }
        int c;
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                infile>>c;
                h1.edges[i][j] = c;
            }
        }
        for(int i=0;i<num;i++){
            infile>>l;
            infile>>x;
            infile>>y;
            vertex2D* v= new vertex2D(l,x,y);
            h2.addvertex(v);
        }
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                infile>>c;
                h2.edges[i][j] = c;
            }
        }
        for(int i=0;i<num;i++){
            infile>>l;
            infile>>x;
            infile>>y;
            vertex2D* v= new vertex2D(l,x,y);
            h3.addvertex(v);
        }
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                infile>>c;
                h3.edges[i][j] = c;
            }
        }

        graph3D h(num);
        make_3Dgraph_with_vertices(h1,h2,h3,&h);
        intersection_method_add_edges(h1,h2,h3,&h);
        add_faces_from_projections(&h);
        //remove_pseudo_faces_edges(h1,h2,h3,&h);
        cout<<"Here's the generated 3D object\n";
        cout<<"The vertices of 3D object are:\n";
        for(int i=0;i<num;i++){
        vertex3D* k = h.vertices[i];
        cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"  "<<k->z<<"\n";
    }
                cout<<"The 3D object edge matrix is :FORMAT(1 if there exists an edge, 0 if there does not)\n";
    for (int i=0;i<num;i++){
        for(int j=0;j<num;j++){
            cout<<h.edges[i][j]<<" ";
        }
        cout<<"\n";
    }            cout<<"No. of faces in 3D object"<<"\n";

       cout<<h.numfaces<<"\n";
                   cout<<"The faces in the 3D object are as follows\n";
    for(int i=0;i<h.numfaces;i++){
        for(int j=0;j<h.faces[i].size();j++){
            cout<<h.faces[i][j]<<" ";
        }
        cout<<"\n";
    }
    graph2D cdef(h.size);
    myvector df(1,2,3);
    vertex3D* gh = new vertex3D("a",0,0,0);
    myvector we(1,1,-1);
    plane pw(df,gh,we);
    cdef.make_2Dgraph_with_vertices(h,pw);
        cdef.join_2D_edges(h);
        cdef.filter_hidden_lines(h,pw);

        vertex2D* v1;
        vertex2D* v2;
        for(int i=0;i<cdef.size;i++){
            for(int j=i;j<cdef.size;j++){
                if(cdef.edges[i][j]!=0){
                    if(cdef.edges[i][j]==2){
                           p.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
                    }
                    v1 = cdef.vertices[i];
                    v2 = cdef.vertices[j];
                    p.drawLine(100*v1->x, -100*(v1->y ), 100*v2->x, -100*(v2->y));
                                           p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
                }
            }
        }




    }

   
   // float x, y, prev_x=0, prev_y=0 ;

   // for (int i = 1; i < SIZE; ++i){
   //      x = i*STEP;
   //      y = sin(x);
   //      p.drawLine(FACTOR*prev_x, FACTOR*prev_y, FACTOR*x, FACTOR*y);

   //      prev_x = x;
   //      prev_y = y;
   //  }

   p.end(); // Don't forget this line!

   l.setPicture(pi);
   l.show();
   return a.exec();
}

