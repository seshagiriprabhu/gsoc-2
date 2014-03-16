#include "encrypteduserprofile.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>

encrypteduserprofile::encrypteduserprofile(QWidget *parent) :
    QDialog(parent)
{
       QString btnCSS =
            "QPushButton {"
            "margin: 1px;"
            "border-color: #6BC260;"
            "border-style: outset;"
            "border-radius: 3px;"
            "font-size: 11px;"
            "border-width: 0.2px;"
            "color: white;"
            "font-weight: bold;"
            "background-color: #6BC260;"
            "}"
            "QPushButton:hover {"
            "background-color: #0BC260;"
            "}";
        QVBoxLayout *loginLayout = new QVBoxLayout;
        QHBoxLayout *usernameLayout = new QHBoxLayout;
        QLabel *usernameLabel = new QLabel(tr("Nickname:"));
        username = new QLabel(tr("blob"));
        usernameLabel->setBuddy(username);

        usernameLayout->addWidget(usernameLabel);
        usernameLayout->addWidget(username);

        password = new QLineEdit(this);
        password->setMaximumHeight(30);
        password->setFixedHeight(30);
        password->setMaximumWidth(200);
        password->setFixedWidth(200);
        password->setEchoMode(QLineEdit::Password);
        password->setPlaceholderText(tr("Password"));

        QHBoxLayout *buttonLayout = new QHBoxLayout;
        loginButton = new QPushButton(tr("&Login"));
        loginButton->setStyleSheet(btnCSS);
        loginButton->setFixedHeight(35);
        loginButton->setFixedWidth(80);

        buttonLayout->setAlignment(Qt::AlignRight);
        buttonLayout->addWidget(loginButton);

        loginLayout->addLayout(usernameLayout);
        loginLayout->addWidget(password);
        loginLayout->addLayout(buttonLayout);
        loginLayout->setSizeConstraint(QLayout::SetFixedSize);
        setLayout(loginLayout);
        setWindowIcon(QIcon(":/icons/icon64.png"));
        setWindowTitle("Import encrypted profile");
        setModal(true);
        show();
}
