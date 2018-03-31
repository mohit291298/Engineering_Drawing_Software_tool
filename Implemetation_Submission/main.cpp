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
#include <QString>
#include <map>

using namespace Qt;
#define PI 3.14159265

struct avvertex{
    string f,g;
    float e,b,c,d;
    int hl;
};

int main(int argc, char *argv[])
{
   QApplication a(argc, argv);
   QLabel l;
   QPicture pi;
   QPainter p(&pi);

   p.setRenderHint(QPainter::Antialiasing);
   p.setPen(QPen(Qt::black, 2.5, Qt::SolidLine, Qt::RoundCap));
    // p.drawLine(-800, 0, 800, 0);
    // p.drawLine(0, -600, 0, 600);
   cout<<"\n"<<"***************            FILE SPECIFICATION            *******************\n"<<"Enter 1(for 3D to 2D) or 2(for 2D to 3D) in the first line.\n";
   cout<<"\n"<<"****************            3D to 2D         ******************************\n\n\n";
   cout<<"Enter 1 i.e you want to project a 3D object, you now give the details of the 3D object\n";
   cout<<"Enter the number of vertices in 3D object in next line\n";
   cout<<"Now enter the vertices each in a single line: Format LABEL <space> x-coordinate <space> y-coordinate <space> z-coordinate.\n";
   cout<<"Next enter the nxn edge matrix( each entry 0 or 1 separated by spaces ) in which ith row and jth column entry 1 \n";
   cout<<"if there is edge between ith vertex and jth vertex(in order you have given the vertices.\n";
   cout<<"Enter the faces with each face in a new line: Format Labels separated by spaces in order of cycic face with first and last label the same.\n";
   cout<<"In new line, enter 1(if you want orthographic projections), 2(If you want projections of rotated object), 3(if you want projection on a specified plane.\n";
   cout<<"If 2, then mention the angles of rotation about x,y,z axis in degrees separated by faces in the next line.\n";
   cout<<"If 3, enter the normal vector in next line(x <space> y <space> z), a point on the plane in next line(x <space> y <space> z) and 1 axis on plane for orientation((x <space> y <space> z).\n";
   cout<<"\n"<<"\n"<<"****************            2D to 3D         ******************************\n";
   cout<<"\n"<<"\n"<<"if the first line of the file is 2 i.e. you want to generate 3D object from projections enter the xy,yz,zx projections in order.\n";
   cout<<"For xy proj. enter the no. of vertices in the next line and then enter each vertex in subsequent lines(Format LABEL <space> x-coordinate <space> y-coordinate <space> z-coordinate)\n";
   cout<<"Next enter the nxn edge matrix( each entry 0, 1 or 2 separated by spaces ) in which ith row and jth column entry 1 \n";
   cout<<"if there is edge between ith vertex and jth vertex(in order you have given the vertices and 2 if it is a hidden edge.\n";
   cout<<"Similarly enter the details of the yz and zx projections.\n";
    string fname;
    string STRING;
    cout<<"\n"<<"\n"<<"\n"<<"Enter the file nane:\n";
    cin>>fname;
    char fn[fname.length()];
    strcpy(fn, fname.c_str());
    ifstream infile(fn);
    if (!infile)
    {
        cout << "There was a problem opening the file. Press any key to close.\n";
        return 0;
    }
    infile>>STRING;
    if(STRING=="1"){ /* 3D to 2D drawing*/        
        p.setPen(QPen(Qt::black, 3, Qt::SolidLine, Qt::RoundCap));
        p.drawLine(-800, 0, 800, 0);
        p.drawLine(0, -515, 0, 515);
        p.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
        p.drawLine(-800, -515, 800, -515);
        p.drawLine(-800, 515, 800, 515);
        p.drawLine(-800, -515, -800, 515);
        p.drawLine(800, -515, 800, 515);
        p.setPen(QPen(Qt::red, 4, Qt::SolidLine, Qt::RoundCap));
        QString view1 = QString::fromStdString("Front View");
        p.drawText(710, 500, view1);
        view1 = QString::fromStdString("Top View");
        p.drawText(720, -495, view1);
        view1 = QString::fromStdString("Side View");
        p.drawText(-790, 500, view1);

        p.setPen(QPen(Qt::black, 2.5, Qt::SolidLine, Qt::RoundCap));
        
        int num;
        infile>>num;
        graph3D g2(num);
        string l;
        float x,y,z;
        float min_x = 0;
        float min_y = 0;
        float min_z = 0;
        for(int i=0;i<num;i++){
            infile>>l;
            infile>>x;
            infile>>y;
            infile>>z;
            if(x<min_x)
                min_x=x;
            if(y<min_y)
                min_y=y;
            if(z<min_z)
                min_z=z;            
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
         while(getline(infile, str)&&(str!="1")&&(str!="2")&&(str!="3")) 
        {            
            g2.addfaces(str);
        }
        cout<<g2.numfaces;

        if(str=="3"){ /* Case of rotating a 3D object.*/
            float theta_x,theta_y,theta_z;
            float ctheta_x,ctheta_y,ctheta_z;
            float stheta_x,stheta_y,stheta_z;
            infile>>theta_x;
            infile>>theta_y;
            infile>>theta_z;
            theta_x = (theta_x*PI)/180.0;
            theta_y = (theta_y*PI)/180.0;
            theta_z = (theta_z*PI)/180.0;
            ctheta_x = cos(theta_x);
            ctheta_y = cos(theta_y);
            ctheta_z = cos(theta_z);
            stheta_x = sin(theta_x);
            stheta_y = sin(theta_y);
            stheta_z = sin(theta_z);
            float rotationx[3][3] = {};
            float rotationy[3][3] = {};
            float rotationz[3][3] = {};
            float temp1[3][3] = {};
            float temp2[3][3] = {};
            rotationx[0][0] = 1;
            rotationx[1][1] = ctheta_x;
            rotationx[2][2] = ctheta_x;
            rotationx[1][2] = stheta_x;
            rotationx[2][1] = -1*stheta_x;
            rotationy[0][0] = ctheta_y;
            rotationy[1][1] = 1;
            rotationy[2][2] = ctheta_y;
            rotationy[0][2] = -1*stheta_y;
            rotationy[2][0] = stheta_y;
            rotationz[0][0] = ctheta_z;
            rotationz[1][1] = ctheta_z;
            rotationz[2][2] = 1;
            rotationz[0][1] = stheta_z;
            rotationz[1][0] = -1*stheta_z;

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        temp1[i][j] += rotationx[i][k] * rotationy[k][j];
                    }
                }
            }
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    for (int k = 0; k < 3; k++)
                    {
                        temp2[i][j] += temp1[i][k] * rotationz[k][j];
                    }
                }
            }
            for(int i=0;i<num;i++){
                float cof[3] = {};
                float mat[3] = {g2.vertices[i]->x,g2.vertices[i]->y,g2.vertices[i]->z};
                for(int j=0;j<3;j++){
                    for(int k=0;k<3;k++){
                        cof[j] += temp2[j][k]*mat[k];
                    }
                }
                g2.vertices[i]->x = cof[0];
                g2.vertices[i]->y = cof[1];
                g2.vertices[i]->z = cof[2];
                if(cof[0]<min_x)
                    min_x=cof[0];
                if(cof[1]<min_y)
                    min_y=cof[1];
                if(cof[2]<min_z)
                    min_z=cof[2];
            }

            str="1";

        }

        cout<<"Your input/rotated 3D object vertices are:FORMAT(Label x_coordinate y_coordinate z_coordinate)\n";
        for(int i=0;i<num;i++){
            vertex3D* k = g2.vertices[i];
            cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"   "<<k->z<<"\n";
        }
        cout<<"Your input/rotated 3D object edge matrix is :FORMAT(1 if there exists an edge, 0 if there does not)\n";
        for (int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                cout<<g2.edges[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"No. of faces in 3D object"<<g2.numfaces<<"\n";
        cout<<"The faces in input/rotated 3D object are as follows\n";
        for(int i=0;i<num;i++){
            for(int j=0;j<num;j++){
                cout<<g2.faces[i][j]<<" ";
            }
            cout<<"\n";
        }

        if(str=="1"){ /* Case of genreating orthographic projections. */
            std::map<string, float> map1_xy;
            std::map<string, float> map2_xy;
            std::map<string, float> map1_yz;
            std::map<string, float> map2_yz;
            std::map<string, float> map1_zx;
            std::map<string, float> map2_zx;
            graph2D o11(g2.size);
            graph2D o21(g2.size);
            graph2D o31(g2.size);
            generate_orthographic_projections(&o11,&o21,&o31,&g2);
            vertex2D* v1;
            vertex2D* v2;
            float flag1_x;
            float flag1_y;
            float flag2_x;
            float flag2_y;
            std::vector< avvertex > avx;
            float flag_min_y = 0.0;
            float flag_max_y = 0.0;
            for(int i=0;i<o11.size;i++){
                for(int j=i;j<o11.size;j++){
                    if(o11.edges[i][j]!=0){
                        avvertex xy_edge;
                        // if(o11.edges[i][j]==2){
                        //        p.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
                        // }
                        v1 = o11.vertices[i];
                        v2 = o11.vertices[j];
                        if(min_x<0.1){
                            flag1_x = 100*(v1->x -min_x +0.1);
                            flag2_x = 100*(v2->x - min_x +0.1);
                        }
                        else{
                            flag1_x = 100*(v1->x +0.1);
                            flag2_x = 100*(v2->x +0.1);
                        }
                        if(min_y<0.1){
                            flag1_y = 100*(v1->y -min_y +0.1);
                            flag2_y = 100*(v2->y - min_y +0.1);
                        }
                        else{
                            flag1_y = 100*(v1->y +0.1);
                            flag2_y = 100*(v2->y +0.1);
                        }
                        xy_edge.f = v1->label;
                        xy_edge.g = v2->label;
                        xy_edge.e = flag1_x;
                        xy_edge.b = flag1_y;
                        xy_edge.c = flag2_x;
                        xy_edge.d = flag2_y;
                        xy_edge.hl = o11.edges[i][j];
                        avx.push_back(xy_edge);
                        if(avx.size()==1){
                            if(xy_edge.b<xy_edge.d)
                                flag_min_y = xy_edge.b;
                            else
                                flag_min_y = xy_edge.d;
                        }
                        if(flag_max_y<xy_edge.b)
                            flag_max_y = xy_edge.b;
                        if(flag_max_y<xy_edge.d)
                            flag_max_y = xy_edge.d;
                        if(flag_min_y>xy_edge.b)
                            flag_min_y = xy_edge.b;
                        if(flag_min_y>xy_edge.d)
                            flag_min_y = xy_edge.d;
                    }
                }
            }
            for(int i=0;i<avx.size();i++){
                if(avx[i].hl==2){
                       p.setPen(QPen(Qt::black, 2.5, Qt::DashDotLine, Qt::RoundCap));
                }
                p.drawLine(avx[i].e,flag_max_y + flag_min_y - avx[i].b ,avx[i].c ,flag_max_y + flag_min_y - avx[i].d );
                map1_xy[avx[i].f] = avx[i].e;
                map2_xy[avx[i].f] = flag_max_y + flag_min_y - avx[i].b;
                map1_xy[avx[i].g] = avx[i].c;
                map2_xy[avx[i].g] = flag_max_y + flag_min_y - avx[i].d;
               p.setPen(QPen(Qt::blue, 2.5, Qt::SolidLine, Qt::RoundCap));
                 QString lab1 = QString::fromStdString(avx[i].f);
                  QString lab2 = QString::fromStdString(avx[i].g);
                p.drawText(avx[i].e + 5, flag_max_y + flag_min_y - avx[i].b - 5, lab1);
                 p.drawText(avx[i].c + 5, flag_max_y + flag_min_y - avx[i].d - 5, lab2);
                 p.setPen(QPen(Qt::black, 2.5, Qt::SolidLine, Qt::RoundCap));
            }
            std::vector< avvertex > avy;
            flag_min_y = 0.0;
            flag_max_y = 0.0;
            for(int i=0;i<o21.size;i++){
                for(int j=i;j<o21.size;j++){
                    if(o21.edges[i][j]!=0){
                        // if(o21.edges[i][j]==2){
                        //        p.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
                        // }
                        avvertex yz_edge;
                        v1 = o21.vertices[i];
                        v2 = o21.vertices[j];
                        if(min_y<0.1){
                            flag1_x = 100*(v1->x -min_y +0.1);
                            flag2_x = 100*(v2->x - min_y +0.1);
                        }
                        else{
                            flag1_x = 100*(v1->x +0.1);
                            flag2_x = 100*(v2->x +0.1);
                        }
                        if(min_z<0.1){
                            flag1_y = 100*(v1->y -min_z +0.1);
                            flag2_y = 100*(v2->y - min_z +0.1);
                        }
                        else{
                            flag1_y = 100*(v1->y +0.1);
                            flag2_y = 100*(v2->y +0.1);
                        }
                        yz_edge.f = v1->label;
                        yz_edge.g = v2->label;
                        yz_edge.e = flag1_x;
                        yz_edge.b = flag1_y;
                        yz_edge.c = flag2_x;
                        yz_edge.d = flag2_y;
                        yz_edge.hl = o21.edges[i][j];
                        avy.push_back(yz_edge);
                        if(avy.size()==1){
                            if(yz_edge.e<yz_edge.c)
                                flag_min_y = yz_edge.e;
                            else
                                flag_min_y = yz_edge.c;
                        }
                        if(flag_max_y<yz_edge.e)
                            flag_max_y = yz_edge.e;
                        if(flag_max_y<yz_edge.c)
                            flag_max_y = yz_edge.c;
                        if(flag_min_y>yz_edge.e)
                            flag_min_y = yz_edge.e;
                        if(flag_min_y>yz_edge.c)
                            flag_min_y = yz_edge.c;
                        // p.drawLine(-100*(flag1_x), 100*(flag1_y), -100*(flag2_x), 100*(flag2_y));
                        //    p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
                    }
                }
            }
            for(int i=0;i<avy.size();i++){
                if(avy[i].hl==2){
                       p.setPen(QPen(Qt::black, 2.5, Qt::DashDotLine, Qt::RoundCap));
                }
                p.drawLine(-avy[i].b,flag_max_y + flag_min_y - avy[i].e ,-avy[i].d ,flag_max_y + flag_min_y - avy[i].c );
                map1_yz[avy[i].f] = -avy[i].b;
                map2_yz[avy[i].f] = flag_max_y + flag_min_y - avy[i].e;
                map1_yz[avy[i].g] = -avy[i].d;
                map2_yz[avy[i].g] = flag_max_y + flag_min_y - avy[i].c;

               p.setPen(QPen(Qt::blue, 2.5, Qt::SolidLine, Qt::RoundCap));
                 QString lab1 = QString::fromStdString(avy[i].f);
                 QString lab2 = QString::fromStdString(avy[i].g);
                p.drawText(-avy[i].b - 5, flag_max_y + flag_min_y - avy[i].e - 5, lab1);
                p.drawText(-avy[i].d - 5, flag_max_y + flag_min_y - avy[i].c - 5, lab2);
                p.setPen(QPen(Qt::black, 2.5, Qt::SolidLine, Qt::RoundCap));
            }
            std::vector< avvertex > avz;
            flag_min_y = 0.0;
            flag_max_y = 0.0;
            for(int i=0;i<o31.size;i++){
                for(int j=i;j<o31.size;j++){
                    if(o31.edges[i][j]!=0){
                        // if(o31.edges[i][j]==2){
                        //        p.setPen(QPen(Qt::black, 2, Qt::DashDotLine, Qt::RoundCap));
                        // }
                        avvertex zx_edge;
                        v1 = o31.vertices[i];
                        v2 = o31.vertices[j];
                        if(min_z<0.1){
                            flag1_x = 100*(v1->x -min_z +0.1);
                            flag2_x = 100*(v2->x - min_z +0.1);
                        }
                        else{
                            flag1_x = 100*(v1->x +0.1);
                            flag2_x = 100*(v2->x +0.1);
                        }
                        if(min_x<0.1){
                            flag1_y = 100*(v1->y -min_x +0.1);
                            flag2_y = 100*(v2->y - min_x +0.1);
                        }
                        else{
                            flag1_y = 100*(v1->y +0.1);
                            flag2_y = 100*(v2->y +0.1);
                        }
                        zx_edge.f = v1->label;
                        zx_edge.g = v2->label;
                        zx_edge.e = flag1_y;
                        zx_edge.b = flag1_x;
                        zx_edge.c = flag2_y;
                        zx_edge.d = flag2_x;
                        zx_edge.hl = o31.edges[i][j];
                        avz.push_back(zx_edge);
                        
                        if(avz.size()==1){
                        if(zx_edge.b<zx_edge.d)
                                flag_min_y = zx_edge.b;
                            else
                                flag_min_y = zx_edge.d;
                        }
                        if(flag_max_y<zx_edge.b)
                            flag_max_y = zx_edge.b;
                        if(flag_max_y<zx_edge.d)
                            flag_max_y = zx_edge.d;
                        if(flag_min_y>zx_edge.b)
                            flag_min_y = zx_edge.b;
                        if(flag_min_y>zx_edge.d)
                            flag_min_y = zx_edge.d;
                        // p.drawLine(100*flag1_y, 100*(flag1_x), 100*flag2_y, 100*(flag2_x));
                        //    p.setPen(QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
                    }
                }
            }
            for(int i=0;i<avz.size();i++){
                if(avz[i].hl==2){
                       p.setPen(QPen(Qt::black, 2.5, Qt::DashDotLine, Qt::RoundCap));
                }
                p.drawLine(avz[i].e,-flag_max_y - flag_min_y + avz[i].b ,avz[i].c ,-flag_max_y - flag_min_y + avz[i].d );
                map1_zx[avz[i].f] = avz[i].e;
                map2_zx[avz[i].f] = -flag_max_y - flag_min_y + avz[i].b;
                map1_zx[avz[i].g] = avz[i].c ;
                map2_zx[avz[i].g] = -flag_max_y - flag_min_y + avz[i].d;

               p.setPen(QPen(Qt::blue, 2.5, Qt::SolidLine, Qt::RoundCap));
                 QString lab1 = QString::fromStdString(avz[i].f);
                 QString lab2 = QString::fromStdString(avz[i].g);
                p.drawText(avz[i].e + 5, -flag_max_y - flag_min_y + avz[i].b + 5, lab1);
                p.drawText(avz[i].c + 5, -flag_max_y - flag_min_y + avz[i].d + 5, lab2);
                p.setPen(QPen(Qt::black, 2.5, Qt::SolidLine, Qt::RoundCap));
            }

            /* Adding corresponding lines between different views. */
            p.setPen(QPen(Qt::black, 0.5, Qt::DashDotLine, Qt::RoundCap));
            string corres;
            for(int i=0;i<num;i++){
                corres = g2.vertices[i]->label;
                p.drawLine(map1_xy[corres],map2_xy[corres],map1_yz[corres],map2_yz[corres]);
                p.drawLine(map1_xy[corres],map2_xy[corres],map1_zx[corres],map2_zx[corres]);
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
            cout<<"The vertices of y-z projection are:\n";
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
        else if(str=="2"){ /* Case of generating projection across an arbitrary plane. */
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
    /* 2D to 3D Drawing */
    else if(STRING=="2"){
        p.setPen(QPen(Qt::transparent, 0, Qt::SolidLine, Qt::RoundCap));
        p.drawLine(-800, 0, 800, 0);
        p.drawLine(0, -515, 0, 515);
        p.setPen(QPen(Qt::black, 5, Qt::SolidLine, Qt::RoundCap));
        p.drawLine(-800, -515, 800, -515);
        p.drawLine(-800, 515, 800, 515);
        p.drawLine(-800, -515, -800, 515);
        p.drawLine(800, -515, 800, 515);

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
        }
        cout<<"No. of faces in 3D object"<<"\n";

        cout<<h.numfaces<<"\n";
        cout<<"The faces in the 3D object are as follows\n";
        for(int i=0;i<h.numfaces;i++){
            for(int j=0;j<h.faces[i].size();j++){
                cout<<h.faces[i][j]<<" ";
            }
            cout<<"\n";
        }
        graph2D cdef(h.size);
        myvector df(1,1,1);
        vertex3D* gh = new vertex3D("a",0,0,0);
        myvector we(0.5,0.5,-1);
        plane pw(df,gh,we);
        cdef.make_2Dgraph_with_vertices(h,pw);
        cdef.join_2D_edges(h);
        cdef.filter_hidden_lines(h,pw);

        vertex2D* v1;
        vertex2D* v2;
        p.setPen(QPen(Qt::black, 2.5, Qt::SolidLine, Qt::RoundCap));
        for(int i=0;i<cdef.size;i++){
            for(int j=i;j<cdef.size;j++){
                if(cdef.edges[i][j]!=0){
                    if(cdef.edges[i][j]==2){
                        p.setPen(QPen(Qt::black, 2.5, Qt::DashDotLine, Qt::RoundCap));
                    }
                    v1 = cdef.vertices[i];
                    v2 = cdef.vertices[j];
                    p.drawLine(100*v1->x, -100*(v1->y ), 100*v2->x, -100*(v2->y));
                    p.setPen(QPen(Qt::blue, 2, Qt::DashDotLine, Qt::RoundCap));
                    QString coo = QString::fromStdString(v1->label);
                    p.drawText(100*v1->x + 5, -100*(v1->y ) - 5, coo);
                    coo = QString::fromStdString(v2->label);
                    p.drawText(100*v2->x + 5, -100*(v2->y ) - 5, coo);
                    p.setPen(QPen(Qt::black, 2.5, Qt::SolidLine, Qt::RoundCap));
                }
            }
        }
        cout<<"Here's the isometric projection\n";
        cout<<"The vertices of isometric projection are:\n";
        for(int i=0;i<cdef.size;i++){
            vertex2D* k = cdef.vertices[i];
            cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
        }
        cout<<"The edge matrix of isometric projection is:(0 if no edge,1 is edge,2 if hidden line)\n";
        for (int i=0;i<cdef.size;i++){
            for(int j=0;j<cdef.size;j++){
                cout<<cdef.edges[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

   p.end(); // Don't forget this line!

   l.setPicture(pi);
   l.show();
   return a.exec();
}

