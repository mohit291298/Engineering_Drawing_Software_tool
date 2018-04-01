/* This set of files is to take the input for 3D to 2D in interactive format and print it on a file using gtkmm package
*/
#include <iostream>
#include <fstream>
#include "examplewindow.h"





// Here we setup the initial window with dimensions of of text boxes and entry box, and initial values to be displayed on the textbox.
ExampleWindow::ExampleWindow()
: m_VBox(Gtk::Orientation::ORIENTATION_VERTICAL),
  m_Button_print("Enter"),
  m_CheckButton_Editable("Editable"),
  m_CheckButton_Visible("Visible")
{
  set_size_request(400, 200);
  set_title("Gtk::Entry");
  i=0;

  add(m_VBox);
  m_Label.set_size_request(100,100);
  m_Label.set_text("Enter Type (1-3D to 2D, 2- 2D to 3D");

  m_Entry.set_max_length(50);
  m_Entry.set_text("hello");
  m_Entry.set_text(m_Entry.get_text() + " world");
  m_Entry.select_region(0, m_Entry.get_text_length());
  m_VBox.add(m_Label);
  
  m_VBox.add(m_Entry);
  m_Button_print.signal_clicked().connect( sigc::mem_fun(*this,
              &ExampleWindow::on_button_print) );
  m_VBox.add(m_Button_print);
 
  m_Label.set_visible(true);
  m_VBox.set_visible(true);
  m_Entry.set_visible(true);
  m_Button_print.set_visible(true);
  m_CheckButton_Editable.set_visible(true);
  m_CheckButton_Visible.set_visible(true);
}

ExampleWindow::~ExampleWindow()
{
}

/*This is set of the actions to be taken(based upon the mentioned conditions) to be taken when the button 'Enter' is pressed
  type_operation saves the type of operation(3D to 2D or 2D to 3D)
  i stores the counter of the number of times the button is presses
  j stores the number if vertices in the figure
  The other variable can be understood from the variable names
*/
void ExampleWindow::on_button_print()
{
 i++;
 //Check operation type
   if(i==1){
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

    else if(i<j+2){

      if(type_operation==1){
        vertices_temp.push_back (m_Entry.get_text());
      }
      else if(type_operation==2){
        vertices_temp_xy.push_back (m_Entry.get_text());
      }

   }

   else if(i==(j+2)){

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

        m_Label.set_text("Enter Edge matrix (1 0 ...)");
         edge_number= vertex_size;

       }

       if(type_operation==2){
        m_Label.set_text("Enter XY Edge matrix(1 0 ...)");
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

           for(k=0;k<vertex_size;k++){
              myFile<<edges_temp[k];
              myFile <<std::endl ;
          }

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
           for(k=0;k<vertex_size;k++){
              myFile<<edges_temp[k];
              myFile <<std::endl ;
            }
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
            for(k=0;k<vertex_size;k++){
              myFile<<edges_temp[k];
              myFile <<std::endl ;
            }

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
            m_Label.set_text("Enter YZ Edge matrix (1 0 ...)");
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
            m_Label.set_text("Enter ZX Edge matrix (1 0 ...)");
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
           for(k=0;k<vertex_size;k++){
              myFile<<edges_temp_xy[k];
              myFile <<std::endl ;
            }
            for(k=0;k<vertex_size;k++){
              myFile<<vertices_temp_yz[k];
              myFile <<std::endl ;
            }

            for(k=0;k<vertex_size;k++){
              myFile<<edges_temp_yz[k];
              myFile <<std::endl ;
            }

           for(k=0;k<vertex_size;k++){
              myFile<<vertices_temp_zx[k];
              myFile <<std::endl ;
            }

            for(k=0;k<vertex_size;k++){
              myFile<<edges_temp_zx[k];
              myFile <<std::endl ;
            }

            myFile.close();
            hide();
          }
      }
    }

