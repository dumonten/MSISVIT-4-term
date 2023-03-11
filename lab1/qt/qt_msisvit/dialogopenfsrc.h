#ifndef DIALOGOPENFSRC_H
#define DIALOGOPENFSRC_H

#include <QDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QEvent>

namespace Ui {
class DialogOpenFSrc;
}

class DialogOpenFSrc : public QDialog
{
    Q_OBJECT

public:
    explicit DialogOpenFSrc(QWidget *parent = nullptr);
    ~DialogOpenFSrc();
    bool isChanged();

private slots:
    void on_btnSave_clicked();

private: //Objects
     QFile srcFile;
     bool ischanged;

private: // Methods
    char initFSrcField();
private:
    void showEvent( QShowEvent* event );
    Ui::DialogOpenFSrc *ui;
};

#endif // DIALOGOPENFSRC_H
