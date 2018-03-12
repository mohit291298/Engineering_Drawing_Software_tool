//$Id: examplewindow.h 705 2006-07-19 02:55:32Z jjongsma $ -*- c++ -*-

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

#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include <string>
#include <vector>
using std::vector;
using std::string;
// using namespace std;


class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  //Signal handlers:
  void on_checkbox_editable_toggled();
  void on_checkbox_visibility_toggled();
  //void on_button_close();
  void on_button_print();

  //Child widgets:
  //Gtk::Box m_HBox;
  Gtk::Box m_VBox;
  int i,j;
  int vertex_size,type_operation,edge_number,face_number,edge_number_xy,edge_number_yz, edge_number_zx;
  std::vector<std::string> vertices_temp;
  std::vector<std::string> edges_temp;
  std::vector<std::string> faces_temp;
  // std::vector<std::string> vertices_temp_xy;
  // std::vector<std::string> edges_temp_xy;
  // std::vector<std::string> vertices_temp_yz;
  // std::vector<std::string> edges_temp_yz;
  // std::vector<std::string> vertices_temp_zx;
  // std::vector<std::string> edges_temp_zx;

  
  //std::string temp_string;

  //Gtk::Box m_VBox1;
  Gtk::Entry m_Entry;
  Gtk::Label m_Label;
  //Gtk::Button m_Button_Close;
  Gtk::Button m_Button_print;
  Gtk::CheckButton m_CheckButton_Editable, m_CheckButton_Visible;
};

#endif //GTKMM_EXAMPLEWINDOW_H
