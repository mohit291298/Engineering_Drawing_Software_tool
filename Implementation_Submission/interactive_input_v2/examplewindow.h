#ifndef GTKMM_EXAMPLEWINDOW_H
#define GTKMM_EXAMPLEWINDOW_H

#include <gtkmm.h>
#include <string>
#include <vector>
using std::vector;
using std::string;



class ExampleWindow : public Gtk::Window
{
public:
  ExampleWindow();
  virtual ~ExampleWindow();

protected:
  //Signal handlers:
  void on_checkbox_editable_toggled();
  void on_checkbox_visibility_toggled();
  void on_button_print();

  //Child widgets:
  Gtk::Box m_VBox;
  int i,j,k;
  int vertex_size,type_operation,edge_number,face_number,edge_number_xy,edge_number_yz, edge_number_zx, type_operation_3D;
  std::vector<std::string> vertices_temp;
  std::vector<std::string> edges_temp;
  std::vector<std::string> faces_temp;
  std::vector<std::string> vertices_temp_xy;
  std::vector<std::string> edges_temp_xy;
  std::vector<std::string> vertices_temp_yz;
  std::vector<std::string> edges_temp_yz;
  std::vector<std::string> vertices_temp_zx;
  std::vector<std::string> edges_temp_zx;
  std::vector<std::string> plane_projection;



  Gtk::Entry m_Entry;
  Gtk::Label m_Label;
  Gtk::Button m_Button_print;
  Gtk::CheckButton m_CheckButton_Editable, m_CheckButton_Visible;
};

#endif //GTKMM_EXAMPLEWINDOW_H
