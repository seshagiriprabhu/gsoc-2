#ifndef CREATEUSERPROFILE_HPP
#define CREATEUSERPROFILE_HPP

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class createUserProfile : public QDialog
{
    Q_OBJECT
private:
    QFrame *frame;
    QPushButton *registerButton;
    QLineEdit *username;
    QLineEdit *password;

public:
    explicit createUserProfile(QWidget *parent = 0);
    QString getUsername();
    QString getPassword();

signals:

public slots:

};

#endif // CREATEUSERPROFILE_HPP
