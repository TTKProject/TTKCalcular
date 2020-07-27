#ifndef TTKAPPLICATION_H
#define TTKAPPLICATION_H

/* =================================================
 * This file is part of the TTKCalcular project
 * Copyright (C) 2017 - 2020 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include <QStack>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class TTKApplication : public QWidget
{
    Q_OBJECT
public:
    explicit TTKApplication(QWidget *parent = nullptr);

public Q_SLOTS:
    void euqalButtonClicked();
    void backButtonClicked();
    void indexButtonClicked(int index);

private:
    void initialize();
    void transform(const char *first, char *second);
    double calculate(const char *second);
    void operatEnable(bool status);
    void numberEnable(bool status);

private:
    QLineEdit *m_inputEdit;
    QLabel *m_outputLabel;
    QPushButton *m_buttons[24];
    char m_first[50], m_second[50];
    QStack<double> m_stack;

};

#endif
