#ifndef DEMANDEMOT_H
#define DEMANDEMOT_H

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QString>


class FenDemandeMot : public QDialog
{
    Q_OBJECT

public:
    FenDemandeMot();
    ~FenDemandeMot();
    QString GetMot();

private slots:
    void VerifierMot();

private:
    QLabel *titre;
    QLineEdit *mot;
    QPushButton *btnValider;
    QGridLayout *layout;
    QString *motVerifie;
};

#endif // DEMANDEMOT_H
