#include "ttkapplication.h"

#include <QBoxLayout>
#include <QButtonGroup>

TTKApplication::TTKApplication(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300, 270);
    setWindowTitle("TTKApplication");

    initialize();
}

void TTKApplication::euqalButtonClicked()
{
    strcpy(m_first, m_inputEdit->text().toUtf8().data());
    memset(m_second, 0, sizeof(m_second));

    transform(m_first, m_second);
    m_outputLabel->setNum(calculate(m_second));
}

void TTKApplication::backButtonClicked()
{
    QString text = m_inputEdit->text();
    text.chop(1);

    if(text.isEmpty())
    {
        text = '0';
    }

    m_inputEdit->setText(text);
}

void TTKApplication::indexButtonClicked(int index)
{
    QString text = m_inputEdit->text();
    if(text.size() == 1 && text.toInt() == 0)
    {
        if(text != "." && text != "+" && text != "-" && text != "*" && text != "/")
        {
            m_inputEdit->setText(QString());
        }
    }

    text = m_inputEdit->text();
    switch(index)
    {
        case 2:
        {
            m_inputEdit->setText(text + QString("("));
            break;
        }
        case 3:
        {
            m_inputEdit->setText(text + QString(")"));
            break;
        }
        case 4:
        {
            m_inputEdit->setText("0");
            m_outputLabel->setText(QString());
            m_buttons[19]->setEnabled(false);
            numberEnable(true);
            break;
        }
        case 5:
        {
            m_inputEdit->setText(text + QString("7"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 6:
        {
            m_inputEdit->setText(text + QString("8"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 7:
        {
            m_inputEdit->setText(text + QString("9"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 8:
        {
            m_inputEdit->setText(text + QString("+"));
            numberEnable(true);
            operatEnable(false);
            break;
        }
         case 10:
        {
            m_inputEdit->setText(text + QString("4"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 11:
        {
            m_inputEdit->setText(text + QString("5"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 12:
        {
            m_inputEdit->setText(text + QString("6"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 13:
        {
            m_inputEdit->setText(text + QString("-"));
            operatEnable(false);
            numberEnable(true);
            break;
        }
         case 14:
        {
            m_inputEdit->setText(text + QString("%"));
            break;
        }
         case 15:
        {
            m_inputEdit->setText(text + QString("1"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 16:
        {
            m_inputEdit->setText(text + QString("2"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 17:
        {
            m_inputEdit->setText(text + QString("3"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 18:
        {
            m_inputEdit->setText(text + QString("*"));
            operatEnable(false);
            numberEnable(true);
            break;
        }
         case 20:
        {
            m_inputEdit->setText(text + QString("0"));
            numberEnable(false);
            operatEnable(true);
            break;
        }
         case 21:
        {
            m_inputEdit->setText(text + QString("."));
            break;
        }
         case 22:
        {
            m_inputEdit->setText(text + QString("/"));
            operatEnable(false);
            numberEnable(true);
            break;
        }
         default: break;
      }
}

void TTKApplication::initialize()
{
    QHBoxLayout *hBox = new QHBoxLayout;
    m_inputEdit = new QLineEdit(this);
    m_inputEdit->setText("0");
    m_inputEdit->setReadOnly(true);
    m_inputEdit->setFixedHeight(40);
    m_inputEdit->setFont(QFont("Monospace", 14, QFont::Normal, false));
    m_inputEdit->setAlignment(Qt::AlignRight);

    m_outputLabel = new QLabel(this);
    m_outputLabel->setFixedHeight(18);
    m_outputLabel->setFont(QFont("Monospace", 10, QFont::Light, false));
    m_outputLabel->setAlignment(Qt::AlignRight);
    m_outputLabel->setMargin(0);
    hBox->addWidget(m_inputEdit);

    QGridLayout *grid = new QGridLayout;
    QButtonGroup *group = new QButtonGroup(this);

    for(int i = 0; i<23; i++)
    {
        m_buttons[i] = new QPushButton(this);
        m_buttons[i]->setFont(QFont("Monospace", 14, QFont::Normal, false));
        m_buttons[i]->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);
        m_buttons[i]->setCursor(Qt::PointingHandCursor);
        group->addButton(m_buttons[i], i);
    }

    grid->addWidget(m_buttons[0], 0, 0);
    m_buttons[0]->setIcon(QIcon(":/data/icon/xx.png"));//x^2
    m_buttons[0]->setIconSize(QSize(20, 20));
    m_buttons[0]->setCursor(Qt::PointingHandCursor);

    m_buttons[1]->setIcon(QIcon(":/data/icon/genhao.png"));//radical sign
    grid->addWidget(m_buttons[1], 0, 1);
    m_buttons[2]->setText(QString("("));
    m_buttons[2]->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_9));
    grid->addWidget(m_buttons[2], 0, 2);
    m_buttons[3]->setText(QString(")"));
    m_buttons[3]->setShortcut(QKeySequence(Qt::SHIFT + Qt::Key_0));
    grid->addWidget(m_buttons[3], 0, 3);

    m_buttons[4]->setIcon(QIcon(":/data/icon/cc.png"));//clean
    m_buttons[4]->setShortcut(QKeySequence(Qt::Key_C));
    grid->addWidget(m_buttons[4], 0, 4);

    m_buttons[5]->setText(QString("7"));
    m_buttons[5]->setShortcut(QKeySequence(Qt::Key_7));
    grid->addWidget(m_buttons[5], 1, 0);
    m_buttons[6]->setText(QString("8"));
    m_buttons[6]->setShortcut(QKeySequence(Qt::Key_8));
    grid->addWidget(m_buttons[6], 1, 1);
    m_buttons[7]->setText(QString("9"));
    m_buttons[7]->setShortcut(QKeySequence(Qt::Key_9));
    grid->addWidget(m_buttons[7], 1, 2);
    m_buttons[8]->setText(QString("+"));
    m_buttons[8]->setShortcut(QKeySequence(Qt::Key_Plus));
    m_buttons[8]->setFont(QFont("Monospace", 14, QFont::Bold, false));
    grid->addWidget(m_buttons[8], 1, 3);
    m_buttons[9]->setText(QString(""));
    m_buttons[9]->setIcon(QIcon(":/data/icon/arrow.png"));//backspace
    m_buttons[9]->setShortcut(QKeySequence(Qt::Key_Backspace));
    grid->addWidget(m_buttons[9], 1, 4);

    m_buttons[10]->setText(QString("4"));
    m_buttons[10]->setShortcut(QKeySequence(Qt::Key_4));
    grid->addWidget(m_buttons[10], 2, 0);
    m_buttons[11]->setText(QString("5"));
    m_buttons[11]->setShortcut(QKeySequence(Qt::Key_5));
    grid->addWidget(m_buttons[11], 2, 1);
    m_buttons[12]->setText(QString("6"));
    m_buttons[12]->setShortcut(QKeySequence(Qt::Key_6));
    grid->addWidget(m_buttons[12], 2, 2);
    m_buttons[13]->setText(QString("-"));
    m_buttons[13]->setShortcut(QKeySequence(Qt::Key_Minus));
    m_buttons[13]->setFont(QFont("Monospace", 14, QFont::Bold, false));
    grid->addWidget(m_buttons[13], 2, 3);
    m_buttons[14]->setText(QString("%"));
    m_buttons[14]->setShortcut(QKeySequence(Qt::Key_Percent));
    grid->addWidget(m_buttons[14], 2, 4);

    m_buttons[15]->setText(QString("1"));
    m_buttons[15]->setShortcut(QKeySequence(Qt::Key_1));
    grid->addWidget(m_buttons[15], 3, 0);
    m_buttons[16]->setText(QString("2"));
    m_buttons[16]->setShortcut(QKeySequence(Qt::Key_2));
    grid->addWidget(m_buttons[16], 3, 1);
    m_buttons[17]->setText(QString("3"));
    m_buttons[17]->setShortcut(QKeySequence(Qt::Key_3));
    grid->addWidget(m_buttons[17], 3, 2);
    m_buttons[18]->setText(QString("*"));
    m_buttons[18]->setShortcut(QKeySequence(Qt::Key_Asterisk));
    m_buttons[18]->setFont(QFont("Monospace", 14, QFont::Black, false));
    grid->addWidget(m_buttons[18], 3, 3);

    m_buttons[19]->setIcon(QIcon(":/data/icon/equl.png"));//show result
    m_buttons[19]->setIconSize(QSize(20, 20));
    m_buttons[19]->setStyleSheet("background-color:#ffa500;border-radius: 6px;");
    m_buttons[19]->setShortcut(QKeySequence(Qt::Key_Return));
    grid->addWidget(m_buttons[19],3,4,2,1);

    m_buttons[20]->setText(QString("0"));
    m_buttons[20]->setShortcut(QKeySequence(Qt::Key_0));
    grid->addWidget(m_buttons[20], 4, 0, 1, 2);
    m_buttons[21]->setText(QString("."));
    m_buttons[21]->setShortcut(QKeySequence("."));
    grid->addWidget(m_buttons[21], 4, 2);
    m_buttons[22]->setIcon(QIcon(":/data/icon/div.png"));//div
    m_buttons[22]->setShortcut(QKeySequence(Qt::Key_Slash));
    grid->addWidget(m_buttons[22], 4, 3);

    QVBoxLayout *vBox = new QVBoxLayout;
    vBox->addLayout(hBox);
    vBox->addWidget(m_outputLabel);
    vBox->addLayout(grid);
    setLayout(vBox);

    connect(group, SIGNAL(buttonClicked(int)), SLOT(indexButtonClicked(int)));
    connect(m_buttons[19], SIGNAL(clicked()), SLOT(euqalButtonClicked()));
    connect(m_buttons[9], SIGNAL(clicked()), SLOT(backButtonClicked()));
}

void TTKApplication::transform(const char *first, char *second)
{
    int i = 0, j = 0;
    while(first[i])
    {
        if(first[i] == '.' || first[i] == '%')
        {
            continue;
        }

        if(first[i] >= '0' && first[i] <= '9')
        {
            second[j++] = first[i];
        }
        else if(first[i]== '-' || first[i] == '+')
        {
            if(!m_stack.isEmpty())
            {
                while(!m_stack.isEmpty() && (m_stack.top() == '+' || m_stack.top() == '-' || m_stack.top() == '*' || m_stack.top() == '/'))
                {
                    second[j++] = m_stack.pop();
                }
            }
            m_stack.push(first[i]);
        }
        else if(first[i] == '*' || first[i] == '/')
        {
            if(!m_stack.isEmpty())
            {
                while(!m_stack.isEmpty() && (m_stack.top() == '*' || m_stack.top() == '/'))
                {
                    second[j++] = m_stack.pop();
                }
            }
            m_stack.push(first[i]);
        }
        else if('(' == first[i])
        {
            m_stack.push(first[i]);
        }
        else if(')' == first[i])
        {
            if(!m_stack.isEmpty())
            {
                while(!m_stack.isEmpty() && m_stack.top() != '(')
                {
                    second[j++] = m_stack.pop();
                }
            }
            m_stack.pop();
        }
        i++;
    }

    while(!m_stack.isEmpty())
    {
        second[j++] = m_stack.pop();
    }
}

double TTKApplication::calculate(const char *second)
{
    int i=0;
    double a, b;
    while(second[i])
    {
        switch(second[i])
        {
            case '+':
            {
                b = m_stack.pop();
                a = m_stack.pop();
                m_stack.push(a + b);
                break;
            }
            case '-':
            {
                b = m_stack.pop();
                a = m_stack.pop();
                m_stack.push(a - b);
                break;
            }
            case '*':
            {
                b = m_stack.pop();
                a = m_stack.pop();
                m_stack.push(a * b);
                break;
            }
            case '/':
            {
                b = m_stack.pop();
                a = m_stack.pop();
                m_stack.push(a / b);
                break;
            }
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
            {
                m_stack.push(second[i] - '0');
            }
        }
        i++;
    }
    return m_stack.top();
}

void TTKApplication::operatEnable(bool status)
{
    m_buttons[8]->setEnabled(status);
    m_buttons[18]->setEnabled(status);
    m_buttons[13]->setEnabled(status);
    m_buttons[22]->setEnabled(status);
    m_buttons[19]->setEnabled(true);
}

void TTKApplication::numberEnable(bool status)
{
    m_buttons[5]->setEnabled(status);
    m_buttons[6]->setEnabled(status);
    m_buttons[7]->setEnabled(status);
    m_buttons[10]->setEnabled(status);
    m_buttons[11]->setEnabled(status);
    m_buttons[12]->setEnabled(status);
    m_buttons[15]->setEnabled(status);
    m_buttons[16]->setEnabled(status);
    m_buttons[17]->setEnabled(status);
    m_buttons[20]->setEnabled(status);
}
