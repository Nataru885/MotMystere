#ifndef MENU_H
#define MENU_H

#include <QVBoxLayout>

#include "fenetre.h"

class FenMenu : public QWidget
{
    Q_OBJECT

public:
    FenMenu();
    ~FenMenu();

public slots:
    void Recommence();

private slots:
    void Propose();
    void Aleatoire();

private:
    QLabel *nomMenu;
    QPushButton *btnPropose;
    QPushButton *btnAleatoire;
    QPushButton *btnQuitter;
    QVBoxLayout *layout;

};



#endif // MENU_H
