
#include "demandemot.h"

FenDemandeMot::FenDemandeMot()
{
    titre = new QLabel;
    mot = new QLineEdit;
    btnValider = new QPushButton;
    layout = new QGridLayout;
    motVerifie = new QString;

    titre->setText(QString::fromUtf8("Inscrire le mot mystère"));
    btnValider->setText("Valider");

    layout->addWidget(titre,1,1);
    layout->addWidget(mot,2,1);
    layout->addWidget(btnValider,3,1);

    this->setLayout(layout);

    QObject::connect(btnValider, SIGNAL(clicked()), this, SLOT(VerifierMot()));
}

FenDemandeMot::~FenDemandeMot()
{
    delete titre;
    delete mot;
    delete btnValider;
    delete layout;
    delete motVerifie;
}

void FenDemandeMot::VerifierMot() //Verifie que le mot inscrit ne contient que des lettres
{
    QString motInscrit = mot->text();
    motInscrit = motInscrit.toUpper();

    // Liste des lettres autorisé
    QString lettres = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    bool motValide = true;
    bool lettreValide;

    for(int i = 0; i < motInscrit.size(); i++)
    {
        lettreValide = false;

        for(int j = 0; j < lettres.size(); j++)
        {
            if(motInscrit[i] == lettres[j])
            {
                lettreValide = true;
            }
        }

        if(lettreValide == false)
        {
            motValide = false;
        }

    }

    if(motInscrit.isEmpty())
    {
        motValide = false;
    }

    if(motValide == true)
    {
        *motVerifie = motInscrit;

        this->hide();
    }

}

QString FenDemandeMot::GetMot()
{
    return *motVerifie;
}
