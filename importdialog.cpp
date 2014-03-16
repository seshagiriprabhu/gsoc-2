#include "importdialog.hpp"
#include "createuserprofile.hpp"

#include <QDialog>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QPalette>
#include <QLine>
#include <QDebug>
#include <QSettings>
#include <QFileDialog>
#include <QDir>

void ImportDialog::show_createProfile_dialog()
{


}

void ImportDialog::on_browse_clicked()
{
    QString selfilter = tr("TOX (*.tox)");
    const QString DEFAULT_DIR_KEY("default_dir");
    QSettings MySettings;
    QString selectedFile = QFileDialog::getOpenFileName(this, tr("Select a file"),
                                                        MySettings.value(DEFAULT_DIR_KEY).toString(),
                                                        tr("TOX(*.tox);;All files (*.*)"), &selfilter);
    if (!selectedFile.isEmpty()) {
        QDir CurrentDir;
        MySettings.setValue(DEFAULT_DIR_KEY, CurrentDir.absoluteFilePath(selectedFile));
        importBtn->setEnabled(true);
        chosenFile->setText(selectedFile);
    }
}

void ImportDialog::on_import_clicked()
{
    // Call the validation function
    /* if (dataType == "encrypted") {
     *
     * } else { // code for raw profile import */
    qDebug() << "Created profile dialog";
    userProfileDialog = new createUserProfile;
    userProfileDialog->show();
    /*}*/
}

ImportDialog::ImportDialog(QWidget *parent)
    : QDialog(parent)
{
    importProfile = new QWidget;

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
        "}"
        "QPushButton:disabled {"
        "background-color: #c1c1c1;"
         "}";

    QVBoxLayout *pageLayout = new QVBoxLayout;
    QHBoxLayout *fileSelectLayout = new QHBoxLayout;
    QHBoxLayout *buttonLayout = new QHBoxLayout;

    QLabel *chooseFile = new QLabel(tr("Choose File:"), this);
    chosenFile = new QLineEdit(this);
    chosenFile->setFixedHeight(30);
    chosenFile->setMaximumWidth(200);
    chosenFile->setFixedWidth(220);
    chosenFile->setReadOnly(true);

    QPushButton *chooseFileBtn = new QPushButton(tr("&Browse"), this);
    chooseFile->setBuddy(chooseFileBtn);
    chooseFileBtn->setStyleSheet(btnCSS);
    chooseFileBtn->setMaximumHeight(30);
    chooseFileBtn->setFixedHeight(35);
    chooseFileBtn->setMaximumWidth(80);
    chooseFileBtn->setFixedWidth(80);
    chooseFileBtn->setCursor(Qt::PointingHandCursor);

    fileSelectLayout->addWidget(chooseFile);
    fileSelectLayout->addWidget(chosenFile);
    fileSelectLayout->addWidget(chooseFileBtn);

    QHBoxLayout *profileNameLayout = new QHBoxLayout;
    QLabel *profileNameLabel = new QLabel(tr("Profile Name\t\t:"), this);
    profileName = new QLabel;
    profileName->setText(tr("blob"));
    profileName->setFixedWidth(200);
    profileNameLayout->addWidget(profileNameLabel);
    profileNameLayout->addWidget(profileName);
    profileNameLabel->setBuddy(profileName);

    QHBoxLayout *timeAccessLayout = new QHBoxLayout;
    QLabel *timeAccessLabel = new QLabel(tr("Time of last access\t:"), this);
    timeAccessed = new QLabel;
    timeAccessed->setText(tr("3 / 16 / 2014 @ 00:25:07 UTC"));
    timeAccessed->setFixedWidth(200);
    timeAccessLayout->addWidget(timeAccessLabel);
    timeAccessLayout->addWidget(timeAccessed);
    timeAccessLabel->setBuddy(timeAccessed);

    QHBoxLayout *dataTypeLayout = new QHBoxLayout;
    QLabel *dataTypeLabel = new QLabel(tr("Profile type\t\t:"), this);
    dataType = new QLabel;
    dataType->setText(tr("Raw"));
    dataType->setFixedWidth(200);
    dataTypeLayout->addWidget(dataTypeLabel);
    dataTypeLayout->addWidget(dataType);
    dataTypeLabel->setBuddy(dataType);

    importBtn = new QPushButton(tr("&Import"), this);
    importBtn->setStyleSheet(btnCSS);
    importBtn->setMaximumHeight(30);
    importBtn->setFixedHeight(35);
    importBtn->setMaximumWidth(80);
    importBtn->setFixedWidth(80);
    importBtn->setDisabled(true);
    importBtn->setCursor(Qt::PointingHandCursor);

    buttonLayout->addSpacerItem(new QSpacerItem(1, 30));
    buttonLayout->addSpacerItem(new QSpacerItem(300, 1));
    buttonLayout->addWidget(importBtn);

    pageLayout->addLayout(fileSelectLayout);
    pageLayout->addSpacerItem(new QSpacerItem(1, 20));
    pageLayout->addLayout(profileNameLayout);
    pageLayout->addLayout(timeAccessLayout);
    pageLayout->addLayout(dataTypeLayout);
    pageLayout->addSpacerItem(new QSpacerItem(1, 20));
    pageLayout->addLayout(buttonLayout);
    pageLayout->setContentsMargins(0,0,30,0);
    pageLayout->setAlignment(Qt::AlignCenter);
    importProfile->setLayout(pageLayout);

    QLabel *toxLogo = new QLabel(this);
    toxLogo->setPixmap(QPixmap(":/icons/toxlogo.png"));
    toxLogo->setAlignment(Qt::AlignVCenter);
    toxLogo->setContentsMargins(0,0,0,0);

    connect(chooseFileBtn, &QPushButton::clicked, this, &ImportDialog::on_browse_clicked);
    connect(importBtn, &QPushButton::clicked, this, &ImportDialog::on_import_clicked);

    QVBoxLayout *sideLayout = new QVBoxLayout();
    sideLayout->addWidget(toxLogo);

    frame = new QFrame();
    frame->setMinimumHeight(250);
    frame->setMinimumWidth(200);
    frame->setStyleSheet("QFrame{border-image:url(:/icons/arrowuc.png);}");
    frame->setAutoFillBackground(true);
    frame->setContentsMargins(0,0,0,0);
    frame->setLayout(sideLayout);

    QHBoxLayout *mainLayout = new QHBoxLayout();
    mainLayout->addWidget(frame);
    mainLayout->addWidget(importProfile);
    mainLayout->setContentsMargins(0,0,0,0);
    mainLayout->setSizeConstraint(QLayout::SetFixedSize);

    setLayout(mainLayout);
    setWindowIcon(QIcon(":/icons/icon64.png"));
    setWindowTitle("Import profile");
}

ImportDialog::~ImportDialog()
{

}
