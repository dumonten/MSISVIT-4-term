#include "dialogopenfsrc.h"
#include "ui_dialogopenfsrc.h"

DialogOpenFSrc::DialogOpenFSrc(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogOpenFSrc)
{
    ui->setupUi(this);
    ischanged = false;
    srcFile.setFileName("/home/dumonten/Documents/GitHub/MSISVIT-4-term/lab1/qt/data/goexample.txt");
    if (initFSrcField() == -1)
        QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка: невозможно прочитать исходный файл."));
}


char DialogOpenFSrc::initFSrcField()
{
    if (!srcFile.open(QIODevice::ReadOnly))
        return -1;

    QTextStream stream(&srcFile);
    ui->initFSrcField->setPlainText(stream.readAll());
    srcFile.close();
    return 1;
}

DialogOpenFSrc::~DialogOpenFSrc()
{
    delete ui;
}

bool DialogOpenFSrc::isChanged()
{
    return ischanged;
}

void DialogOpenFSrc::showEvent( QShowEvent* event ) {
    ischanged = false;
    initFSrcField();
    QWidget::showEvent( event );
}


void DialogOpenFSrc::on_btnSave_clicked()
{
    if (!srcFile.open(QIODevice::WriteOnly))
        QMessageBox::critical(this, tr("Ошибка"), tr("Ошибка: невозможно записать данные в исходный файл."));

    ischanged = true;
    QTextStream stream(&srcFile);
    stream << ui->initFSrcField->toPlainText();
    srcFile.close();
}

