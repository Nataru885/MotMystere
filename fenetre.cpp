#include "fenetre.h"

FenMotMystere::FenMotMystere(int mode)
{

    nomJeu = new QLabel;
    affMotMelange = new QLabel;
    affCoupsRestants = new QLabel;
    motPropose = new QLineEdit;
    btnValider = new QPushButton;
    motChoisi = new QString;
    motMystere = new QString;

    motMelange = new QString;
    nbCoupsRestants = new int;


    if (mode == 1)
    {
        FenDemandeMot DemandeMot;
        DemandeMot.exec();

        *motChoisi = DemandeMot.GetMot();
    }
    else
    {
        MotAleatoire();
    }

    *motMystere = *motChoisi;
    *motMelange = MelangerMot(*motChoisi);
    *nbCoupsRestants = 5;

    nomJeu->setText(QString::fromUtf8("Le Mot Mystère"));
    MAJaffCoupsRestants();
    affMotMelange->setText("Quel est ce mot ? : " + *motMelange);
    btnValider->setText("Valider");

    layout = new QGridLayout;
    layout->addWidget(nomJeu,1,2);
    layout->addWidget(affCoupsRestants,2,3);
    layout->addWidget(affMotMelange,3,1);
    layout->addWidget(motPropose,3,3);
    layout->addWidget(btnValider,4,2);

    setLayout(layout);

    QObject::connect(btnValider, SIGNAL(clicked()), this, SLOT(VerifierMot()));
    QObject::connect(this, SIGNAL(quitter()), qApp, SLOT(quit()));

}

FenMotMystere::~FenMotMystere()
{

    delete nomJeu;
    delete affMotMelange;
    delete affCoupsRestants;
    delete motMelange;
    delete motPropose;
    delete motMystere;
    delete motChoisi;
    delete nbCoupsRestants;
    delete btnValider;
    delete layout;
}

void FenMotMystere::MotAleatoire() //Choisi un mot au hazard parmis la liste
{
    // Création d'un objet QFile
    QFile fichier("Dictionnaire.mm");
    // On ouvre notre fichier en lecture seule et on vérifie l'ouverture
    if (fichier.open(QIODevice::ReadOnly | QIODevice::Text))
    {

        // Création d'un objet QTextStream à partir de notre objet QFile
        QTextStream flux(&fichier);

        QString mot;
        int nbLignes(0);

        while(!flux.atEnd())
        {
            QString temp = flux.readLine();
            nbLignes += 1;
        }

        flux.seek(0);

        int nbAleatoire = rand() % nbLignes;
        nbAleatoire += 1;

        int ligne(0);

        do
        {
            mot = flux.readLine();
            ligne += 1;
        }while(ligne < nbAleatoire);

        QString affNbLigne = QString::number(nbAleatoire);

        *motChoisi = mot;

    }
}

QString FenMotMystere::MelangerMot(QString motAMelanger) //Melange les lettres du mot mystère
{
    QString mot;
    while(motAMelanger.size() > 0)
    {
        int position = rand() % motAMelanger.size();

        mot += motAMelanger[position];

        motAMelanger.remove(position,1);
    }
    return mot;
}

void FenMotMystere::VerifierMot() //Vérification du mot proposé
{
    if (motPropose->text().toUpper() == *motMystere)
    {
        affMotMelange->setText(QString::fromUtf8("Vous avez trouvé le mot mystère !!"));

        btnValider->setText("Menu");
        QObject::connect(btnValider, SIGNAL(clicked()), this, SLOT(Fermer()));
    }
    else
    {
        if(!CoupsRestants(-1)) //Nombre de coups restant 0
        {
            affMotMelange->setText("Vous avez perdu !!");
            DialogRejouer();
        }
    }
}

void FenMotMystere::MAJaffCoupsRestants() // Mise à jour de l'affichage des coups restants
{
        affCoupsRestants->setText("Coups restants : " + QString::number(*nbCoupsRestants));
}

bool FenMotMystere::CoupsRestants(int nb) // Gestion des coups restants
{
    *nbCoupsRestants = *nbCoupsRestants + nb;
    if(*nbCoupsRestants <= 0)
    {
        *nbCoupsRestants = 0;
        MAJaffCoupsRestants();
        return false;
    }
    else
    {
        MAJaffCoupsRestants();
        return true;
    }

}

void FenMotMystere::DialogRejouer()
{
    int reponse = QMessageBox::question(this,"Rejouer ?", "Vous avez perdu. Souhaitez-vous rejouer ?", QMessageBox::Yes | QMessageBox::No);
    if(reponse == QMessageBox::Yes)
    {
        Fermer();
    }
    else
    {
        emit quitter();
    }

}

void FenMotMystere::Fermer()
{
    this->close();
}
void FenMotMystere::Quitter()
{
    qApp->quit();
}
void FenMotMystere::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Return) // si c'est entrer
    {
        VerifierMot();
    }
}
