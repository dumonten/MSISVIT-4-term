#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "lexer.h"


std::map<QString, int> operators, operands;

using namespace lexer;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initTables()
{
    ui->tableOperands->setColumnCount(3);
    ui->tableOperators->setColumnCount(3);
    ui->tableOperators->setHorizontalHeaderLabels(QStringList() << "j" << "Оператор" << "f1j");
    ui->tableOperands->setHorizontalHeaderLabels(QStringList()  << "i" << "Операнд" << "f2i");
    ui->tableOperands->verticalHeader()->setVisible(false);
    ui->tableOperators->verticalHeader()->setVisible(false);

    ui->tableOperands->horizontalHeader( )->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableOperators->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    ui->tableOperands->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableOperators->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableOperands->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableOperands->setFocusPolicy(Qt::NoFocus);
    ui->tableOperands->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableOperators->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableOperators->setFocusPolicy(Qt::NoFocus);
    ui->tableOperators->setSelectionMode(QAbstractItemView::NoSelection);
}

void MainWindow::clearAllFields()
{
    ui->tableOperands->clear();
    ui->tableOperators->clear();
    ui->resText->clear();
    operators.clear();
    operands.clear();
}

void MainWindow::on_btnStart_clicked()
{
    clearAllFields();

    initTables();

    char error = getData(operators, operands);
    if (error == -1)
    {
        QMessageBox::critical(this, tr("Предупреждение"), tr("Ошибка: исходный файл поврежден."));
        return;
    }
    ui->tableOperators->setRowCount(1+operators.size());
    ui->tableOperands->setRowCount(1+operands.size());

    /**OPERATORS**/
    uint64_t cntDictJ = 0;
    std::map<QString, int> :: iterator it = operators.begin();
    uint64_t operatorsSize = operators.size();
    for (uint64_t i = 0; i < operatorsSize; i++)
    {
        QTableWidgetItem* index, *itemName, *itemCount;
        index     = new QTableWidgetItem(QString::number(i+1));
        itemName  = new QTableWidgetItem;
        itemCount = new QTableWidgetItem;

        ui->tableOperators->setItem(i, 0, index);
        ui->tableOperators->setItem(i, 1, itemName);  itemName->setText(it->first);
        ui->tableOperators->setItem(i, 2, itemCount); itemCount->setText(QString::number(it->second));

        index->setTextAlignment( Qt::AlignCenter );
        itemName->setTextAlignment( Qt::AlignCenter );
        itemCount->setTextAlignment( Qt::AlignCenter );

        cntDictJ  += it->second;

        it++;
    }
    QTableWidgetItem *resRow1Cell = new QTableWidgetItem("-1 = " + QString::number(operatorsSize)),
                     *resRow2Cell = new QTableWidgetItem(" ___ "),
                     *resRow3Cell = new QTableWidgetItem("N1 = " + QString::number(cntDictJ));

    ui->tableOperators->setItem(operatorsSize, 0, resRow1Cell); resRow1Cell->setForeground(Qt::green);    resRow1Cell->setTextAlignment( Qt::AlignCenter );
    ui->tableOperators->setItem(operatorsSize, 1, resRow2Cell); resRow2Cell->setForeground(Qt::green);    resRow2Cell->setTextAlignment( Qt::AlignCenter );
    ui->tableOperators->setItem(operatorsSize, 2, resRow3Cell); resRow3Cell->setForeground(Qt::green);    resRow3Cell->setTextAlignment( Qt::AlignCenter );

    /**OPERANDS**/
    uint64_t cntDictI = 0;
    it = operands.begin();
    uint64_t operandsSize = operands.size();
    for (uint64_t i = 0; i < operandsSize; i++)
    {
        QTableWidgetItem* index, *itemName, *itemCount;
        index     = new QTableWidgetItem(QString::number(i+1));
        itemName  = new QTableWidgetItem;
        itemCount = new QTableWidgetItem;

        ui->tableOperands->setItem(i, 0, index);
        ui->tableOperands->setItem(i, 1, itemName);  itemName->setText(it->first);
        ui->tableOperands->setItem(i, 2, itemCount); itemCount->setText(QString::number(it->second));

        index->setTextAlignment( Qt::AlignCenter );
        itemName->setTextAlignment( Qt::AlignCenter );
        itemCount->setTextAlignment( Qt::AlignCenter );

        cntDictI  += it->second;

        it++;
    }
    resRow1Cell = new QTableWidgetItem("-2 = " + QString::number(operandsSize));
    resRow2Cell = new QTableWidgetItem(" ___ ");
    resRow3Cell = new QTableWidgetItem("N2 = " + QString::number(cntDictI));

    ui->tableOperands->setItem(operandsSize, 0, resRow1Cell); resRow1Cell->setForeground(Qt::green);    resRow1Cell->setTextAlignment( Qt::AlignCenter );
    ui->tableOperands->setItem(operandsSize, 1, resRow2Cell); resRow2Cell->setForeground(Qt::green);    resRow2Cell->setTextAlignment( Qt::AlignCenter );
    ui->tableOperands->setItem(operandsSize, 2, resRow3Cell); resRow3Cell->setForeground(Qt::green);    resRow3Cell->setTextAlignment( Qt::AlignCenter );

    ui->resText->setPlainText("Словарь программы = "   + QString::number(operatorsSize) + " + " + QString::number(operandsSize) + " = " + QString::number(operandsSize + operatorsSize)
                            + "\nДлина программы N = "  + QString::number(cntDictJ) + " + "      + QString::number(cntDictI)     + " = " + QString::number(cntDictJ + cntDictI)
                            + "\nОбъем программы V = " + QString::number(cntDictJ + cntDictI) + "*log2(" + QString::number(operandsSize + operatorsSize) + ") = " + QString::number(round((cntDictJ + cntDictI) * log2(operandsSize + operatorsSize))));
}


void MainWindow::on_pushButton_clicked()
{
    fsrc.setModal(true);
    fsrc.exec();
    if (fsrc.isChanged())
    {
        clearAllFields();
        initTables();
    }
}

