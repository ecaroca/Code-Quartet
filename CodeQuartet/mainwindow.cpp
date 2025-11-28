#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "informacion.h"
#include "calculus.h"
#include "functions.h"

double MainWindow::getA()
{
    return ui->avalor->text().toDouble();
}

double MainWindow::getB()
{
    return ui->bvalor->text().toDouble();
}

void MainWindow::setResultado(double r)
{
    ui->resultado->setText(QString::number(r));
}

int MainWindow::getK() {
    return ui->kvalor->text().toInt();  // 1=sin, 2=cos, etc.
}

int MainWindow::getSide(){
    int s = ui->nvalor->text().toInt();
    return (s >= 0 ? 1 : -1);
}

//Funciones extra
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

void MainWindow::on_acerca_clicked()
{
    informacion* ventana2 = new informacion(this);
    ventana2->show();
}

//FUNCIONES PARA OPERACIONES BASICAS
void MainWindow::on_suma_clicked()
{
    double A = getA();
    double B = getB();
    setResultado(A + B);
}


void MainWindow::on_resta_clicked()
{
    double A = getA();
    double B = getB();
    setResultado(A - B);
}


void MainWindow::on_multiplicar_clicked()
{
    double A = getA();
    double B = getB();
    setResultado(A * B);
}

void MainWindow::on_dividir_clicked()
{
    double A = getA();
    double B = getB();
    if (B == 0) {
        ui->resultado->setText("Error: B=0");
        return;
    }
    setResultado(A / B);
}


void MainWindow::on_potencia_clicked()
{
    double A = getA();
    double B = getB();

    setResultado(std::pow(A, B));
}

void MainWindow::on_raiz_clicked()
{
    double A = getA();
    if (A<0){
        ui->resultado->setText("Error: A<0");
    return;
    }

    double B = getB();

    setResultado(std::pow(A, 1/B));
}

//FUNCIONES TRIGONOMETRICAS


void MainWindow::on_seno_clicked()
{
    double A = getA();
    setResultado(std::sin(A));
}

void MainWindow::on_coseno_clicked()
{
    double A = getA();
    setResultado(std::cos(A));
}

void MainWindow::on_exponencial_clicked()
{
    double A = getA();
    setResultado(std::exp(A));
}

void MainWindow::on_logaritmo_clicked()
{
    double A = getA();
    if (A<0){
        ui->resultado->setText("Error: A<0");
        return;
    }
    setResultado(std::log(A));
}

void MainWindow::on_cuadrado_clicked()
{
    double A = getA();
    setResultado(A*A);
}

void MainWindow::on_polinomio_clicked()
{
    double A = getA();
    setResultado(A*A*A - A - 2.0);
}

//FUINCIONES TRIGONOMICAS DERIVADAS

void MainWindow::on_seno_2_clicked()
{
    double A = getA();
    setResultado(std::cos(A));
}


void MainWindow::on_coseno_2_clicked()
{
    double A = getA();
    setResultado(-std::sin(A));
}


void MainWindow::on_exponencial_2_clicked()
{
    double A = getA();
    setResultado(std::exp(A));
}

void MainWindow::on_logaritmo_2_clicked()
{
    double A = getA();
    setResultado(1/A);
}

void MainWindow::on_cuadrado_2_clicked()
{
    double A = getA();
    setResultado(2*A);
}

void MainWindow::on_polinomio_2_clicked()
{
    double A = getA();
    setResultado(3*A*A - 1.0);
}

//FUNCIONES DE CALCULO

void MainWindow::on_limite_clicked()
{
    int k = getK();        // qué función f_k(x) usar
    double a = getA();     // punto al que se aproxima
    int side = getSide();  // -1 izquierda, +1 derecha

    double lim = Calculus::limit_numeric(k, a, side);
    setResultado(lim);
}

void MainWindow::on_derivada_clicked()
{
    int k = getK();
    double x0 = getA();   // Punto donde derivar
    double h  = getB();   // Paso (si 0 → usa interno 1e-5)

    double d = Calculus::deriv_central(k, x0, h);
    setResultado(d);
}

void MainWindow::on_integral_clicked()
{
    int k = getK();

    double a = getA();
    double b = getB();
    int n = getSide();  // subdivisiones

    double I = Calculus::integral_simpson(k, a, b, n);
    setResultado(I);
}

