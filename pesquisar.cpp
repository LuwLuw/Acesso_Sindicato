#include "pesquisar.h"
#include "ui_pesquisar.h"
QSqlDatabase Database = QSqlDatabase::database("DadosDB");
pesquisar::pesquisar(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::pesquisar)
{
    ui->setupUi(this);
    ui->Pes_VisuDados->hide();
}

pesquisar::~pesquisar()
{
    delete ui;
}

void pesquisar::on_BTN_Voltar_clicked()
{
    this->hide();
}


void pesquisar::on_BTN_Visu_clicked()
{
    ui->Pes_VisuDados->show();
    int linha = ui->Pes_TabelaResultado->currentRow();
    nome = ui->Pes_TabelaResultado->item(linha,0)->text();
    Cpf = ui->Pes_TabelaResultado->item(linha,1)->text();
    QSqlQuery query(QSqlDatabase::database("DadosDB"));
    if(query.exec("SELECT * FROM Filiados WHERE CPF = '"+Cpf+"'")){
        while(query.next()){
       ui->InputName->setText(query.value(0).toString());
       ui->InputCPF->setText(query.value(1).toString());
       ui->InputRG->setText(query.value(2).toString());
       ui->InputEndereco->setText(query.value(3).toString());
       ui->InputNasc->setText(query.value(4).toString());
       ui->InputTelefone->setText(query.value(5).toString());
       ui->InputFuncao->setText(query.value(6).toString());
       ui->InputEmpresa->setText(query.value(7).toString());
       ui->InputFiliacao->setText(query.value(8).toString());
       ui->InputMatricula->setText(query.value(9).toString());
       ui->InputEstado->setText(query.value(10).toString());
       }
    }
    else{
        QMessageBox::about(this,"Erro ao ler banco de dados ","Não foi possivel ler o banco de dados");
    }
    Cpf = ' ';
    nome = ' ';
}


void pesquisar::on_BTN_pesquisar_clicked()
{
    ui->Pes_TabelaResultado->clearContents();
    Dado = ui->Pes_DadoPesquisa->text();
    ModoPesquisa = ui->Pes_ModoPesquisa->currentText();
    QSqlQuery query(QSqlDatabase::database("DadosDB"));
    if(query.exec("SELECT Nome, CPF FROM Filiados WHERE "+ModoPesquisa+" LIKE '%"+Dado+"%'")){
        quantidade = 0;
        while(query.next()){
            quantidade++;

        }

    if(quantidade == 0){
        QMessageBox::about(this,"Erro ao ler banco de dados ","Não foram encontrados resultados para sua pesquisa,por favor verifique");
    }
    else{
        if(query.exec("SELECT Nome, CPF FROM Filiados WHERE "+ModoPesquisa+" LIKE '%"+Dado+"%'")){
            int cont =0;
            ui->Pes_TabelaResultado->setColumnCount(2);
            while(query.next()){
               ui->Pes_TabelaResultado->insertRow(cont);
               ui->Pes_TabelaResultado->setItem(cont,0,new QTableWidgetItem(query.value(0).toString()));
               ui->Pes_TabelaResultado->setItem(cont,1,new QTableWidgetItem(query.value(1).toString()));
               ui->Pes_TabelaResultado->setRowHeight(cont,20);
               cont++;
            }
            }
            QStringList cabecalhos ={"Nome","CPF"};
            ui->Pes_TabelaResultado->setHorizontalHeaderLabels(cabecalhos);
            ui->Pes_TabelaResultado->setEditTriggers(QAbstractItemView::NoEditTriggers);
            ui->Pes_TabelaResultado->setSelectionBehavior(QAbstractItemView::SelectRows);
            ui->Pes_TabelaResultado->verticalHeader()->setVisible(false);
            ui->Pes_TabelaResultado->setColumnWidth(0,700);
            ui->Pes_TabelaResultado->setColumnWidth(1,120);
        }
    }

    else{
        QMessageBox::about(this,"Banco de Dados","Erro ao acessar o banco de dados");
    }



}
void pesquisar::on_BTN_VoltarVisu_clicked()
{
    Cpf = ' ';
    nome = ' ';
    ui->Pes_VisuDados->hide();
}

