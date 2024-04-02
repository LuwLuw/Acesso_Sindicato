#ifndef TELA_INICIAL_H
#define TELA_INICIAL_H

#include <QMainWindow>
#include <QDate>
#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>
#include "pesquisar.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Tela_Inicial; }
QT_END_NAMESPACE

class Tela_Inicial : public QMainWindow
{
    Q_OBJECT

public:
    Tela_Inicial(QWidget *parent = nullptr);
    ~Tela_Inicial();

private slots:
    void on_BTN_Pesquisar_clicked();

    void on_BTN_Sair_clicked();

private:
    Ui::Tela_Inicial *ui;
    pesquisar *t_pes;

};
#endif // TELA_INICIAL_H
