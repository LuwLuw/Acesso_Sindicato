#include "tela_inicial.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSqlDatabase Cadastro_DB=QSqlDatabase::addDatabase("QSQLITE","DadosDB");
    QFile arquivo("ender.txt");
    QString texto;
    if(!arquivo.open(QFile::ReadOnly|QFile::Text)){
}
    else{
        QTextStream entrada(&arquivo);
        texto = entrada.readAll();
    }
    QString loc = texto + "DadosCadastro.db";
    Cadastro_DB.setDatabaseName(loc);
    arquivo.close();
    if(!Cadastro_DB.open()){
    }
    else{
        Tela_Inicial w;
    w.show();
    return a.exec();
    }
}
