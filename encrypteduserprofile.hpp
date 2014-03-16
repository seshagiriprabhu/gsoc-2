#ifndef ENCRYPTEDUSERPROFILE_HPP
#define ENCRYPTEDUSERPROFILE_HPP

#include <QDialog>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class encrypteduserprofile : public QDialog
{
    Q_OBJECT

private:
    QFrame *frame;
    QPushButton *loginButton;
    QLabel *username;
    QLineEdit *password;

public:
    explicit encrypteduserprofile(QWidget *parent = 0);

signals:

public slots:

};

#endif // ENCRYPTEDUSERPROFILE_HPP
