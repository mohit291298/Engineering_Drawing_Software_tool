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
#include <iostream>
// #include <vector>
// #include <string>
//using namespace std;
 //using std::vector;
 using std::string;




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
   std::cout << "Value of str is : " << m_Entry.get_text() << std::endl;
   
   i++;
   // if(i==2){
   //  std::string a[vertex_size];

   // }
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
    if(type_operation==1)

    vertices_temp.push_back (m_Entry.get_text());
   }
   else if(i==(j+2)){
  // std::cout<<vertices_temp[1]<<std::endl;
    vertices_temp.push_back (m_Entry.get_text());

    if(type_operation==1){
      m_Label.set_text("Enter number of edges");

    }
    else{
      m_Label.set_text("Enter number of edges in XY projection(including hidden edges)");

      }

    
    


       }

      else if (i==j+3){
        if(type_operation==1){
        m_Label.set_text("Enter Edge (Label A <space> Label B)");
         edge_number= atoi(m_Entry.get_text().c_str());
       }
       if(type_operation==2){
        m_Label.set_text("Enter XY Edge (Label A <space> Label B)");
        edge_number_xy= atoi(m_Entry.get_text().c_str());


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

          m_Label.set_text("Thank You!");
        //   std::cout<<vertices_temp[1]<<std::endl;
        // std::cout<<edges_temp[1]<<std::endl;
        // std::cout<<faces_temp[1]<<std::endl;




        }

    }

    if(type_operation==2){
      if(i==j+3+edge_number_xy){
         m_Label.set_text("Enter projection Vertex - YZ (Label <space> y-coordinate <space> z-coordinate)");


      }
      else if(i==j+3+edge_number_xy+j){
         m_Label.set_text("Enter number of edges in YZ projection(including hidden edges)");


      }
      else if(i==j+3+edge_number_xy+j+1){
        m_Label.set_text("Enter YZ Edge (Label A <space> Label B)");
        edge_number_yz= atoi(m_Entry.get_text().c_str());


      }
      else if(i==j+3+edge_number_xy+j+1 + edge_number_yz){
          m_Label.set_text("Enter projection Vertex - ZX (Label <space> z-coordinate <space> x-coordinate)");

      }
      else if(i==j+3+edge_number_xy+j+1 + edge_number_yz + j){
          m_Label.set_text("Enter number of edges in ZX projection(including hidden edges)");

      }
      else if(i==j+3+edge_number_xy+j+1 + edge_number_yz + j+1){
        m_Label.set_text("Enter ZX Edge (Label A <space> Label B)");
        edge_number_zx= atoi(m_Entry.get_text().c_str());


      }

      else if(i==j+3+edge_number_xy+j+1 + edge_number_yz + j+1+edge_number_zx){

        m_Label.set_text("Thank You!");



      }





    }
    // else if(type_operation==2){



    // }

   //std::cout<<i<<std::endl;



  
}

