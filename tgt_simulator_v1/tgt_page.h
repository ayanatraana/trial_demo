#ifndef TGT_PAGE_H
#define TGT_PAGE_H

#include <QWidget>
#include <QLinkedList>

namespace Ui {
class tgt_page;
}

class tgt_page : public QWidget
{
    Q_OBJECT

public:
    explicit tgt_page(QWidget *parent = nullptr);
    ~tgt_page();

private slots:

    void on_save_pushButton_pressed();

    void on_tgt_typ_comboBox_currentIndexChanged(int index);

    void on_cancel_pushButton_pressed();

private:
    Ui::tgt_page *ui;
};

#endif // TGT_PAGE_H
