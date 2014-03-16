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
    QLabel *hint;

private slots:
    void on_create_button_clicked();

public:
    explicit createUserProfile(QWidget *parent = 0);
    QString getUsername();
    QString getPassword();

signals:

public slots:

};

#endif // CREATEUSERPROFILE_HPP
