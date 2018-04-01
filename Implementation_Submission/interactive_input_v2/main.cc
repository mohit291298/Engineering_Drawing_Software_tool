
#include "examplewindow.h"
#include <gtkmm/application.h>
#include <iostream>
#include <fstream>

int main(int argc, char *argv[])
{
  auto app = Gtk::Application::create("org.gtkmm.example");

  ExampleWindow window;
 

  return app->run(window, argc, argv);

}
