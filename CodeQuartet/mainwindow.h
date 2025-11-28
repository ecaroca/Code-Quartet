#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_acerca_clicked();

    void on_suma_clicked();

    void on_resta_clicked();

    void on_multiplicar_clicked();

    void on_dividir_clicked();

    void on_potencia_clicked();

    void on_raiz_clicked();

    void on_seno_clicked();

    void on_coseno_clicked();

    void on_exponencial_clicked();

    void on_logaritmo_clicked();

    void on_cuadrado_clicked();

    void on_polinomio_clicked();

    void on_seno_2_clicked();

    void on_coseno_2_clicked();

    void on_exponencial_2_clicked();

    void on_logaritmo_2_clicked();

    void on_cuadrado_2_clicked();

    void on_polinomio_2_clicked();

    void on_limite_clicked();

    void on_derivada_clicked();

    void on_integral_clicked();

private:
    Ui::MainWindow *ui;


    double getA();
    double getB();
    void setResultado(double r);

    int getK();     // qué función f(x) usa
    int getSide();  // lado límite (-1 o +1)
    int getN();
};
#endif // MAINWINDOW_H

