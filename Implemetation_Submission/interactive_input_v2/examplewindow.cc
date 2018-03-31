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
#include <iostream>
#include <fstream>
#include "examplewindow.h"

// #include <vector>
// #include <string>
//using namespace std;
 //using std::vector;
 //using std::string;




ExampleWindow::ExampleWindow()
: m_VBox(Gtk::Orientation::ORIENTATION_VERTICAL),
//m_VBox1(Gtk::Orientation::ORIENTATION_VERTICAL),
 //m_Label("Enter Size"),

  m_Button_print("Enter"),
  
 // m_Button_Close("Close"),

  m_CheckButton_Editable("Editable"),
  m_CheckButton_Visible("Visible")
{
  set_size_request(400, 200);
  set_title("Gtk::Entry");
  i=0;

  add(m_VBox);
 // add(m_VBox1);
  m_Label.set_size_request(100,100);
  m_Label.set_text("Enter Type (1-3D to 2D, 2- 2D to 3D");

  m_Entry.set_max_length(50);
  m_Entry.set_text("hello");
  m_Entry.set_text(m_Entry.get_text() + " world");
  m_Entry.select_region(0, m_Entry.get_text_length());
  m_VBox.add(m_Label);
  //m_VBox.pack_start(m_Entry, Gtk::PackOptions::PACK_EXPAND_WIDGET);
  m_VBox.add(m_Entry);
  // Note that add() can also be used instead of pack_xxx()
  // m_VBox.add(m_HBox);

  // m_HBox.pack_start(m_CheckButton_Editable, Gtk::PackOptions::PACK_EXPAND_WIDGET);
  // m_CheckButton_Editable.signal_toggled().connect( sigc::mem_fun(*this,
  //             &ExampleWindow::on_checkbox_editable_toggled) );
  // m_CheckButton_Editable.set_active(true);

  // m_HBox.pack_start(m_CheckButton_Visible, Gtk::PackOptions::PACK_EXPAND_WIDGET);
  // m_CheckButton_Visible.signal_toggled().connect( sigc::mem_fun(*this,
  //             &ExampleWindow::on_checkbox_visibility_toggled) );
  // m_CheckButton_Visible.set_active(true);

 // m_Button_Close.signal_clicked().connect( sigc::mem_fun(*this,
   //           &ExampleWindow::on_button_close) );
  m_Button_print.signal_clicked().connect( sigc::mem_fun(*this,
              &ExampleWindow::on_button_print) );
  //m_VBox.pack_start(m_Button_Close, Gtk::PackOptions::PACK_EXPAND_WIDGET);
 // m_VBox.pack_start(m_Button_print, Gtk::PackOptions::PACK_EXPAND_WIDGET);
  m_VBox.add(m_Button_print);
 // m_Button_Close.set_can_default();
  //m_Button_Close.grab_default();
 // m_Button_print.set_can_default();
  //m_Button_print.grab_default();
 // m_HBox.set_visible(true);
  m_Label.set_visible(true);
  m_VBox.set_visible(true);
 // m_VBox1.set_visible(true);
  m_Entry.set_visible(true);
  //m_Button_Close.set_visible(true);
  m_Button_print.set_visible(true);
  m_CheckButton_Editable.set_visible(true);
  m_CheckButton_Visible.set_visible(true);
}

ExampleWindow::~ExampleWindow()
{
}

// void ExampleWindow::on_checkbox_editable_toggled()
// {
//   m_Entry.set_editable(m_CheckButton_Editable.get_active());
// }

// void ExampleWindow::on_checkbox_visibility_toggled()
// {
//   m_Entry.set_visibility(m_CheckButton_Visible.get_active());
// }

/*void ExampleWindow::on_button_close()
{
   
  hide();
}*/
void ExampleWindow::on_button_print()
{
    std::cout << "Value of str is123 : " << m_Entry.get_text() << std::endl;
    std::cout <<  m_Entry.get_text()<< std::endl;
 
    
	
	 

	
   
   i++;
   // if(i==2){
   //  std::string a[vertex_size];
// if (i>1){
//   myFile <<m_Entry.get_text() ;
//   myFile <<std::endl<<std::endl ;
// }
   // }
   if(i==1){
   




   	// FILE *outFile;


    // if( ( ( outFile = fopen( "example.txt", "wb" ) ) == NULL ) )
    // {
    //     cerr << "Unable to open " << "example.txt"<< endl;
    // }

    // cout << "Writing out: " << "example.txt"<< endl;

    // fwrite( "Yo", 2, 1, outFile );

    // cout << "example.txt" << " writen out!" << endl;

    // fclose( outFile ); 
	
    if(m_Entry.get_text()=="1"){
     
      m_Label.set_text("Enter 3D object Size (number of vertices)");
      type_operation = 1;
      


    }
    else if(m_Entry.get_text()=="2"){
       m_Label.set_text("Enter object Size (number of vertices)");
       type_operation = 2;


    }
    
    

   }

   else if(i==2)
   {

    if(type_operation== 1)
    {
    m_Label.set_text("Enter 3D object Vertex (Label <space> x-coordinate <space> y-coordinate <space> z-coordinate)");
    j = atoi(m_Entry.get_text().c_str());
    vertex_size=j;
  }

  else if(type_operation== 2){
    m_Label.set_text("Enter projection Vertex - XY (Label <space> x-coordinate <space> y-coordinate)");
    j = atoi(m_Entry.get_text().c_str());
    vertex_size=j;


  }
  else{
    m_Label.set_text("Error: Wrong Type");

  }

   }


   
   // else if(i<=(j)){
   //   temp_string=m_Entry.get_text();
   //   // std::istringstream buf(temp_string);
   //   //  std::istream_iterator<std::string> beg(buf), end;
   //   //  std::vector<std::string> l(beg, end);
   //    // vertices_temp.push_back (temp_string);
   //  // a[i-2]=temp_string;



   //   //std::cout<<temp_string<<std::endl;


   // }
   else if(i<j+2){
    if(type_operation==1){

    vertices_temp.push_back (m_Entry.get_text());
  }
  else if(type_operation==2){

    vertices_temp_xy.push_back (m_Entry.get_text());
  }

   }
   else if(i==(j+2)){
  // std::cout<<vertices_temp[1]<<std::endl;
    

    if(type_operation==1){
      vertices_temp.push_back (m_Entry.get_text());
      m_Label.set_text("Enter number of edges");

    }
    else{
      vertices_temp_xy.push_back (m_Entry.get_text());

      m_Label.set_text("Enter number of edges in XY projection(including hidden edges)");

      }

    
    


       }

      else if (i==j+3){
        if(type_operation==1){
        m_Label.set_text("Enter Edge matrix");
         edge_number= vertex_size;
       }
       if(type_operation==2){
        m_Label.set_text("Enter XY Edge (Label A <space> Label B)");
        edge_number_xy= vertex_size;


       }



      }
      if(type_operation==1){
        if(i<j+3+edge_number&&i>j+3){
          edges_temp.push_back (m_Entry.get_text());


        }
       if (i==j+3+edge_number){
        edges_temp.push_back (m_Entry.get_text());
        m_Label.set_text("Enter number of faces");



       }

       else if (i==j+3+edge_number+1){
        face_number= atoi(m_Entry.get_text().c_str());
         m_Label.set_text("Enter Faces (Label A <space> Label B <space> Label C .....)");


       }
       else if(i<j+3+edge_number+1+face_number&&i>j+3+edge_number+1){
        std::cout<<"Check Face:"<<m_Entry.get_text()<<std::endl;
        faces_temp.push_back (m_Entry.get_text());

       }

        else if (i==j+3+edge_number+1+face_number){
          faces_temp.push_back (m_Entry.get_text());

          m_Label.set_text("Enter the operation to be done (1-Orthographic projection, 2-Rotate, 3-Project across arbit plane");
                  //   std::cout<<vertices_temp[1]<<std::endl;
        // std::cout<<edges_temp[1]<<std::endl;
        // std::cout<<faces_temp[1]<<std::endl;




        }

        else if (i==j+3+edge_number+1+face_number+1){
          type_operation_3D = atoi(m_Entry.get_text().c_str());

          if(type_operation_3D==1){

             m_Label.set_text("Thank You");

              std::ofstream myFile;
 
         myFile.open("example.txt");
         myFile <<type_operation ;
           myFile <<std::endl;
           myFile<<vertex_size;
            myFile <<std::endl ;

           for(k=0;k<vertex_size;k++){
              myFile<<vertices_temp[k];
            myFile <<std::endl ;

           }
           // myFile<<edge_number;
            //myFile <<std::endl ;

            for(k=0;k<vertex_size;k++){
              myFile<<edges_temp[k];
            myFile <<std::endl ;



           }
           // myFile<<face_number;
           //  myFile <<std::endl ;

            for(k=0;k<face_number;k++){
              myFile<<faces_temp[k];
            myFile <<std::endl ;



           }
           myFile<<type_operation_3D;





           myFile.close();

             hide();




          }
          else if(type_operation_3D==2){
            m_Label.set_text("Enter the rotation angle (rotation about x <space> rotation about y <space> rotation about z");


          } 
           else if(type_operation_3D==3){
             m_Label.set_text("Enter the normal vector of plane(x <space> y <space> z");


           }




        }

        else if (i==j+3+edge_number+1+face_number+2){
          if(type_operation_3D==2){
			   plane_projection.push_back (m_Entry.get_text());
            m_Label.set_text("Thank You");
			
			 std::ofstream myFile;
 
         myFile.open("example.txt");
         myFile <<type_operation ;
           myFile <<std::endl;
           myFile<<vertex_size;
            myFile <<std::endl ;

           for(k=0;k<vertex_size;k++){
              myFile<<vertices_temp[k];
            myFile <<std::endl ;

           }
           // myFile<<edge_number;
            //myFile <<std::endl ;

            for(k=0;k<vertex_size;k++){
              myFile<<edges_temp[k];
            myFile <<std::endl ;



           }
           // myFile<<face_number;
           //  myFile <<std::endl ;

            for(k=0;k<face_number;k++){
              myFile<<faces_temp[k];
            myFile <<std::endl ;



           }
           myFile<<type_operation_3D;
		   myFile <<std::endl ;
		   myFile <<plane_projection[0] ;
		   
		   





           myFile.close();

             hide();

			
			
            
          }
          else if(type_operation_3D==3)
          {
            m_Label.set_text("Enter a point on a plane");
            plane_projection.push_back (m_Entry.get_text());





          }


		  
		  




        }
         else if (i==j+3+edge_number+1+face_number+3)
         {
             m_Label.set_text("Enter an axis on plane of rotation");
             plane_projection.push_back (m_Entry.get_text());

         }
          else if (i==j+3+edge_number+1+face_number+4){
            m_Label.set_text("Thank You");
             plane_projection.push_back (m_Entry.get_text());

             std::ofstream myFile;
 
         myFile.open("example.txt");
         myFile <<type_operation ;
           myFile <<std::endl;
           myFile<<vertex_size;
            myFile <<std::endl ;

           for(k=0;k<vertex_size;k++){
              myFile<<vertices_temp[k];
            myFile <<std::endl ;

           }
           // myFile<<edge_number;
            //myFile <<std::endl ;

            for(k=0;k<vertex_size;k++){
              myFile<<edges_temp[k];
            myFile <<std::endl ;



           }
           // myFile<<face_number;
           //  myFile <<std::endl ;

            for(k=0;k<face_number;k++){
              myFile<<faces_temp[k];
            myFile <<std::endl ;



           }
           myFile<<type_operation_3D;
       myFile <<std::endl ;
       myFile << plane_projection[0];
       myFile <<std::endl ;
       myFile << plane_projection[1];
       myFile <<std::endl ;
       myFile << plane_projection[2];
       myFile <<std::endl ;

       myFile.close();

       hide();







          }



    }

    if(type_operation==2){
      if(i<j+3 +edge_number_xy&&i>j+3){
        edges_temp_xy.push_back (m_Entry.get_text());


      }
      else if(i==j+3+edge_number_xy){
        edges_temp_xy.push_back (m_Entry.get_text());
         m_Label.set_text("Enter projection Vertex - YZ (Label <space> y-coordinate <space> z-coordinate)");


      }
      else if(i<j+3+edge_number_xy+j&&i>j+3+edge_number_xy){
        vertices_temp_yz.push_back (m_Entry.get_text());


      }
      else if(i==j+3+edge_number_xy+j){
        vertices_temp_yz.push_back (m_Entry.get_text());
         m_Label.set_text("Enter number of edges in YZ projection(including hidden edges)");


      }
      else if(i==j+3+edge_number_xy+j+1){
        m_Label.set_text("Enter YZ Edge matrix");
        edge_number_yz= vertex_size;


      }
      else if(i<j+3+edge_number_xy+j+1 + edge_number_yz&& i>j+3+edge_number_xy+j+1){
          edges_temp_yz.push_back (m_Entry.get_text());

      }
      else if(i==j+3+edge_number_xy+j+1 + edge_number_yz){
        edges_temp_yz.push_back (m_Entry.get_text());
          m_Label.set_text("Enter projection Vertex - ZX (Label <space> z-coordinate <space> x-coordinate)");

      }
      else if(i<j+3+edge_number_xy+j+1 + edge_number_yz + j&&i>j+3+edge_number_xy+j+1 + edge_number_yz){
          vertices_temp_zx.push_back (m_Entry.get_text());

      }
      else if(i==j+3+edge_number_xy+j+1 + edge_number_yz + j){
        vertices_temp_zx.push_back (m_Entry.get_text());
          m_Label.set_text("Enter number of edges in ZX projection(including hidden edges)");

      }
      else if(i==j+3+edge_number_xy+j+1 + edge_number_yz + j+1){
        m_Label.set_text("Enter ZX Edge matrix");
        edge_number_zx= vertex_size;


      }
      else if(i<j+3+edge_number_xy+j+1 + edge_number_yz + j+1+edge_number_zx && i>j+3+edge_number_xy+j+1 + edge_number_yz + j+1 ){
        edges_temp_zx.push_back (m_Entry.get_text());

      }

      else if(i==j+3+edge_number_xy+j+1 + edge_number_yz + j+1+edge_number_zx){
         edges_temp_zx.push_back (m_Entry.get_text());
        m_Label.set_text("Thank You!");

        std::ofstream myFile;
 
         myFile.open("example.txt");
         myFile <<type_operation ;
           myFile <<std::endl;
           myFile<<vertex_size;
            myFile <<std::endl ;

           for(k=0;k<vertex_size;k++){
              myFile<<vertices_temp_xy[k];
            myFile <<std::endl ;

           }
           // myFile<<edge_number;
            //myFile <<std::endl ;

            for(k=0;k<vertex_size;k++){
              myFile<<edges_temp_xy[k];
            myFile <<std::endl ;



           }

           for(k=0;k<vertex_size;k++){
              myFile<<vertices_temp_yz[k];
            myFile <<std::endl ;

           }
           // myFile<<edge_number;
            //myFile <<std::endl ;

            for(k=0;k<vertex_size;k++){
              myFile<<edges_temp_yz[k];
            myFile <<std::endl ;



           }

           for(k=0;k<vertex_size;k++){
              myFile<<vertices_temp_zx[k];
            myFile <<std::endl ;

           }
           // myFile<<edge_number;
            //myFile <<std::endl ;

            for(k=0;k<vertex_size;k++){
              myFile<<edges_temp_zx[k];
            myFile <<std::endl ;



           }
          
          
          

       myFile.close();

       hide();



      }





    }
    // else if(type_operation==2){



    // }

   //std::cout<<i<<std::endl;



  
}

