#ifndef FENETRE_H
#define FENETRE_H

#include <QMainWindow>
#include <QApplication>
#include <QMessageBox>
#include <ctime>
#include <QKeyEvent>
#include <QTextStream>
#include <QInputDialog>

#include "demandemot.h"


class FenMotMystere : public QDialog
{
    Q_OBJECT

public:
    FenMotMystere(int mode = 1);//Mode 1 = Choix du mot mystere; Mode 2 = Mot aleatoire
    ~FenMotMystere();

private slots:
    QString MelangerMot(QString motAMelanger);
    void MotAleatoire();
    void VerifierMot();
    void MAJaffCoupsRestants();
    bool CoupsRestants(int nb);
    void DialogRejouer();
    void Fermer();
    void Quitter();
    void keyPressEvent(QKeyEvent *event);

private:

    QLabel *nomJeu;
    QLabel *affCoupsRestants;
    QLabel *affMotMelange;
    QLineEdit *motPropose;
    QPushButton *btnValider;
    QGridLayout *layout;

    QString *motMystere;
    QString *motChoisi;
    QString *motMelange;
    int *nbCoupsRestants;

signals:
    void quitter();
};

#endif // FENETRE_H
