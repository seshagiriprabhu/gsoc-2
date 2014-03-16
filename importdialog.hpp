#ifndef IMPORTDIALOG_HPP
#define IMPORTDIALOG_HPP

#include "createuserprofile.hpp"
#include "encrypteduserprofile.hpp"
#include <QDialog>
#include <QLineEdit>
#include <QLabel>

class ImportDialog : public QDialog
{
    Q_OBJECT

private:
    QWidget *importProfile;
    QFrame *frame;
    QPushButton *importSideButton;
    QPushButton *importBtn;
    QLineEdit *chosenFile;
    QLabel *profileName;
    QLabel *timeAccessed;
    QLabel *dataType;
    createUserProfile *userProfileDialog;
    encrypteduserprofile *existingProfileDialog;
    void parseFile();

private slots:
    void on_browse_clicked();
    void on_import_clicked();
    void show_createProfile_dialog();

public:
    ImportDialog(QWidget *parent = 0);

    ~ImportDialog();
};

#endif // IMPORTDIALOG_HPP
