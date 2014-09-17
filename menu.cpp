
#include "menu.h"


FenMenu::FenMenu()
{
    nomMenu = new QLabel;
    btnPropose = new QPushButton;
    btnAleatoire = new QPushButton;
    btnQuitter = new QPushButton;
    layout = new QVBoxLayout;

    nomMenu->setText(QString::fromUtf8("Le Mot Mystère"));
    btnPropose->setText(QString::fromUtf8("Choix du mot mystère"));
    btnAleatoire->setText(QString::fromUtf8("Mot mystère aléatoire"));
    btnQuitter->setText(QString::fromUtf8("Quitter"));

    layout->addWidget(nomMenu);
    layout->addWidget(btnPropose);
    layout->addWidget(btnAleatoire);
    layout->addWidget(btnQuitter);

    setLayout(layout);

    QObject::connect(btnPropose, SIGNAL(released()), this, SLOT(Propose()));
    QObject::connect(btnAleatoire, SIGNAL(released()), this, SLOT(Aleatoire()));
    QObject::connect(btnQuitter, SIGNAL(released()), qApp, SLOT(quit()));

}

FenMenu::~FenMenu()
{
    delete nomMenu;
    delete btnPropose;
    delete btnAleatoire;
    delete btnQuitter;
    delete layout;

}

void FenMenu::Propose()
{
    this->hide();
    FenMotMystere *motMystere = new FenMotMystere(1);
    motMystere->exec();
    Recommence();
}

void FenMenu::Aleatoire()
{
    this->hide();
    FenMotMystere *motMystere = new FenMotMystere(2);
    motMystere->exec();
    Recommence();
}

void FenMenu::Recommence()
{
    this->show();
}
