#ifndef PESQUISAR_H
#define PESQUISAR_H

#include <QWidget>
#include <QDate>
#include <QWidget>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QMessageBox>

namespace Ui {
class pesquisar;
}

class pesquisar : public QWidget
{
    Q_OBJECT

public:
    explicit pesquisar(QWidget *parent = nullptr);
    ~pesquisar();
    QString ModoPesquisa;
    QString Dado;
    QString res;
    QString nome;
    QString Cpf;
    QString Ender;
    QString tel;
    QString Func;
    QString Emp;
    QString estado;
    int quantidade;
private slots:
    void on_BTN_Voltar_clicked();

    void on_BTN_Visu_clicked();

    void on_BTN_pesquisar_clicked();

    void on_BTN_VoltarVisu_clicked();

private:
    Ui::pesquisar *ui;
};

#endif // PESQUISAR_H
