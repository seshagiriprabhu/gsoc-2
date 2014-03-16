#include "createuserprofile.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>

void createUserProfile::on_create_button_clicked()
{
    if (username->text().isEmpty() || password->text().isEmpty()) {
        hint->setText(tr("Invalid username or password"));
    }
}

createUserProfile::createUserProfile(QWidget *parent) :
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
    QString hintCSS =
        "QLabel {"
        "color: red"
        "}";

    QVBoxLayout *registerLayout = new QVBoxLayout;
    QLabel *usernameLabel = new QLabel(tr("Create &Nickname"));
    username = new QLineEdit(this);
    username->setMaximumHeight(30);
    username->setFixedHeight(30);
    username->setMaximumWidth(200);
    username->setFixedWidth(200);
    usernameLabel->setBuddy(username);

    QLabel *passwordLabel = new QLabel(tr("Create &Password"));
    password = new QLineEdit(this);
    password->setMaximumHeight(30);
    password->setFixedHeight(30);
    password->setMaximumWidth(200);
    password->setFixedWidth(200);
    password->setEchoMode(QLineEdit::Password);
    passwordLabel->setBuddy(password);

    registerLayout->addWidget(usernameLabel);
    registerLayout->addWidget(username);
    registerLayout->addWidget(passwordLabel);
    registerLayout->addWidget(password);

    QHBoxLayout *buttonLayout = new QHBoxLayout;

    registerButton = new QPushButton(tr("&Create profile"));
    registerButton->setStyleSheet(btnCSS);
    registerButton->setFixedHeight(35);
    registerButton->setFixedWidth(120);
    registerButton->setCursor(Qt::PointingHandCursor);

    hint = new QLabel;
    hint->setStyleSheet(hintCSS);
    hint->setAlignment(Qt::AlignHCenter);

    buttonLayout->setAlignment(Qt::AlignRight);
    buttonLayout->addWidget(registerButton);

    registerLayout->addWidget(hint);
    registerLayout->addLayout(buttonLayout);
    registerLayout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(registerLayout);
    setWindowIcon(QIcon(":/icons/icon64.png"));
    setWindowTitle("Import profile");
    setModal(true);
    show();
}

QString createUserProfile::getUsername()
{

}

QString createUserProfile::getPassword()
{

}
