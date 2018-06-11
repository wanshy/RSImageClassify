#include "uav_viewer.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	UAV_Viewer w;
	w.show();

	return a.exec();
}
