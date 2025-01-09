#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

class Dialog : public QDialog
{
public:
    Dialog(QWidget* parent=nullptr) noexcept;
    ~Dialog() noexcept;

private:
};

#endif