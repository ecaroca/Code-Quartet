/********************************************************************************
** Form generated from reading UI file 'informacion.ui'
**
** Created by: Qt User Interface Compiler version 6.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFORMACION_H
#define UI_INFORMACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_informacion
{
public:
    QTextBrowser *textBrowser;
    QTextEdit *textEdit;

    void setupUi(QDialog *informacion)
    {
        if (informacion->objectName().isEmpty())
            informacion->setObjectName("informacion");
        informacion->resize(860, 608);
        textBrowser = new QTextBrowser(informacion);
        textBrowser->setObjectName("textBrowser");
        textBrowser->setGeometry(QRect(10, 10, 841, 551));
        textEdit = new QTextEdit(informacion);
        textEdit->setObjectName("textEdit");
        textEdit->setGeometry(QRect(400, 570, 461, 61));

        retranslateUi(informacion);

        QMetaObject::connectSlotsByName(informacion);
    } // setupUi

    void retranslateUi(QDialog *informacion)
    {
        informacion->setWindowTitle(QCoreApplication::translate("informacion", "Dialog", nullptr));
        textBrowser->setHtml(QCoreApplication::translate("informacion", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Como usar Code-Cuartet:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-Op basicas: </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Suma(A+B)/Resta(A-B)/Multiplicar(A*B)/Division(A:B)</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; m"
                        "argin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-Funciones:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">En estas opciones solo debes usar A que se usara en la funcion que escogida.</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">SenA,CosA,ExpA... </p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-Derivadas:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">En estas opciones solo debes usar A que se usara en la derivada de la funcion que escogida</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-le"
                        "ft:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Operaciones de calculo:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">-en k usa numeros de 1 a 6 para indicar la funcion que deseas usar <span style=\" font-weight:700;\">k = 1:</span> <span style=\" font-family:'Courier New';\">sin(x) / </span><span style=\" font-weight:700;\">k = 2:</span> <span style=\" font-family:'Courier New';\">cos(x) / </span><span style=\" font-weight:700;\">k = 3:</span> <span style=\" font-family:'Courier New';\">exp(x)/ </span><span style=\" font-weight:700;\">k = 4:</span> <span style=\" font-family:'Courier New';\">log(x) / </span><span style=\" font-weight:700;\">k = 5:</span> <span style=\" font-family:'Courier New';\">x*x</span> \342\206\222 <span style=\" font-weight:700;\">x2x^2x2 / k = 6:</span> <span style=\" font-family:'Courier New';\">x*x*x - x - 2</span> \342\206\222 <span style=\" font-weight:700;\">x3\342\210\222x\342\210"
                        "\2222x^3 - x - 2x3\342\210\222x\342\210\2222</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">-Limites:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ingresa la funcion via <span style=\" font-weight:700;\">k</span>. Ingresa el punto <span style=\" font-weight:700;\">A</span> al que x se aproxima. Elige el lado: <span style=\" font-weight:700;\">-1</span> para l\303\255mite por izquierda y <span style=\" font-weight:700;\">+1</span> para l\303\255mite por derecha</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">-Derivadas:</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ingresa el n\303\272mero de funci\303"
                        "\263n <span style=\" font-weight:700;\">k</span>.</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Ingresa en <span style=\" font-weight:700;\">A</span> el punto <span style=\" font-weight:700;\">x\342\202\200</span> donde quieres derivar. Opcionalmente, puedes ingresar un valor de paso <span style=\" font-weight:700;\">h en N</span>. Si lo dejas en 0, el sistema usa un valor interno recomendado (1e-5).</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Integrales:</p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">N# de F(x):</span> funci\303\263n</p>\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:700;\">A:</span> l\303\255mite inferior "
                        "<span style=\" font-weight:700;\">B:</span> l\303\255mite superior <span style=\" font-weight:700;\">N:</span> n\303\272mero de subdivisiones (debe ser par) <span style=\" font-weight:700;\">Resultado:</span> \342\210\253f(x) dx</p></body></html>", nullptr));
        textEdit->setHtml(QCoreApplication::translate("informacion", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"hr { height: 1px; border-width: 0; }\n"
"li.unchecked::marker { content: \"\\2610\"; }\n"
"li.checked::marker { content: \"\\2612\"; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Proyecto Code-Cuartet creado por Acza Riffo, Maximiliano Lazo y Sebastian Sanchez.</p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:10pt;\"><br /></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class informacion: public Ui_informacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFORMACION_H
