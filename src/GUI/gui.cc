/*!
	\page GuiPage Запуск графики

 	\par Разделы
 	- \ref gui_Common

	\section gui_Common Файл gui.cc
	Реализует программу для запуска графики. Связывает glade файл с конфигурационным файлом configure.xml
*/
#include <iostream>
#include <gtkmm.h>
#include <libglademm.h>
#include <Configuration.h>
#include "Exceptions.h"

using namespace uniset;
using namespace std;

int main (int argc, char **argv)
{
    try
    {
	if (!g_thread_supported())
		g_thread_init(NULL);
    	Gtk::Main Kit(argc, argv);
    	uniset_init(argc,argv);

    	Glib::RefPtr<Gnome::Glade::Xml> gxml = Gnome::Glade::Xml::create("test.glade");
    	Gtk::Window *w;
    	gxml->get_widget("window1", w);

    	if (w == NULL)
    	{
    		cout << "error with the window widget getting" << endl;
    		return 1;
    	}

    	Kit.run(*w);
    }
	catch(Exception& ex)
	{
        cout << ex << endl;
	}
	catch(CORBA::SystemException& ex)
	{
        cout << ex.NP_minorString() << endl;
	}
	catch(...)
	{
        cout << "catch(...)" << endl;
	}
	return 0;
}
