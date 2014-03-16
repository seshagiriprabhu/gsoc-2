#include "importdialog.hpp"
#include "createuserprofile.hpp"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ImportDialog w;
    w.show();

    return a.exec();
}
