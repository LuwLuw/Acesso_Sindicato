#include "tela_inicial.h"
#include "ui_tela_inicial.h"

Tela_Inicial::Tela_Inicial(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Tela_Inicial)
{
    ui->setupUi(this);
}

Tela_Inicial::~Tela_Inicial()
{
    delete ui;
}


void Tela_Inicial::on_BTN_Pesquisar_clicked()
{
    t_pes = new pesquisar();
    t_pes->show();
}


void Tela_Inicial::on_BTN_Sair_clicked()
{
    QSqlDatabase Database = QSqlDatabase::database("DadosDB");
    Database.close();
    this->close();
}

