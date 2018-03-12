/* gtkmm example Copyright (C) 2002 gtkmm development team
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2
 * as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#include "examplewindow.h"
#include <gtkmm/application.h>
#include <iostream>


int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.example");

  ExampleWindow window;

    //   string STRING;
	
    // if(STRING=="1"){
        
    //     int num;
    //     infile>>num;
    //     graph3D g2(num);
    //     string l;
    //     float x,y,z;
    //     for(int i=0;i<num;i++){
    //         infile>>l;
    //         infile>>x;
    //         infile>>y;
    //         infile>>z;
    //         vertex3D* v= new vertex3D(l,x,y,z);
    //         g2.addvertex(v);
    //     }
    //     int c;
    //     for(int i=0;i<num;i++){
    //         for(int j=0;j<num;j++){
    //             infile>>c;
    //             g2.edges[i][j] = c;
    //         }
    //     }
    //     string str;
    //      while(getline(infile, str)) 
    //     {
    //         cout<<str;
    //         g2.addfaces(str);
    // 	}
    //     cout<<"ok\n";
        
    //     for(int i=0;i<4;i++){
    //     vertex3D* k = g2.vertices[i];
    //     cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
    // }
    // for (int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<g2.edges[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }



    // graph2D o11(g2.size);
    // graph2D o21(g2.size);
    // graph2D o31(g2.size);

    // generate_orthographic_projections(&o11,&o21,&o31,&g2);

    //     for(int i=0;i<4;i++){
    //     vertex2D* k = o11.vertices[i];
    //     cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
    // }
    // for (int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<o11.edges[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    //     for(int i=0;i<4;i++){
    //     vertex2D* k = o21.vertices[i];
    //     cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
    // }
    // for (int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<o21.edges[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    //     for(int i=0;i<4;i++){
    //     vertex2D* k = o31.vertices[i];
    //     cout<<k->label<<"   "<<k->x<<"   "<<k->y<<"\n";
    // }
    // for (int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<o31.edges[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // cout<<g2.numfaces<<"\n";
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         cout<<g2.faces[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    // std::vector<string> vq;
    // vq.push_back("b");
    // vq.push_back("a");
    // vq.push_back("c");
    // vq.push_back("b");
    // cout<<g2.isface(vq);
    
    // }


  //Shows the window and returns when it is closed.
  return app->run(window, argc, argv);



}
