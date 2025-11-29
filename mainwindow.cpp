#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "informacion.h"
#include "calculus.h"
#include "functions.h"
#include <QtCharts/QChartView>
#include <QtCharts/QChart>
#include <QtCharts/QLineSeries>
#include <QMessageBox>

//using namespace QtCharts;

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

void MainWindow::setResultado2(double r)
{
    ui->resultado2->setText(QString::number(r));
}

int MainWindow::getK() {
    return ui->kvalor->text().toInt();
}

int MainWindow::getSide(){
    int s = ui->nvalor->text().toInt();
    return (s >= 0 ? 1 : -1);
}
//
struct Matrix2x2
{
    double a11, a12;
    double a21, a22;

    // Determinante
    double det() const {
        return a11 * a22 - a12 * a21;
    }

    // Inversa
    Matrix2x2 inv() const {
        double d = det();
        Matrix2x2 r;

        if (d == 0) {
            // regresa matriz cero si no existe inversa
            r.a11 = r.a12 = r.a21 = r.a22 = 0;
            return r;
        }

        r.a11 =  a22 / d;
        r.a12 = -a12 / d;
        r.a21 = -a21 / d;
        r.a22 =  a11 / d;

        return r;
    }

    // Resolver Ax=b con b = (b1, b2)
    void solve(double b1, double b2, double& x, double& y) const {
        double d = det();
        if (d == 0) {
            x = 0;
            y = 0;
            return;
        }

        // Cramer
        x = (b1 * a22 - a12 * b2) / d;
        y = (a11 * b2 - b1 * a21) / d;
    }
};

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

void MainWindow::on_resolverAxB_clicked()
{
    Matrix2x2 A;

    A.a11 = getA();
    A.a12 = 1;
    A.a21 = 2;
    A.a22 = getB();

    double b1 = 1;      // puedes poner lo que quieras
    double b2 = getK(); // valor desde el UI

    double x, y;
    A.solve(b1, b2, x, y);

    QString r = QString("x=%1  y=%2").arg(x).arg(y);
    ui->resultado->setText(r);
}



void MainWindow::on_determinante_clicked()
{
    Matrix2x2 A;

    A.a11 = getA();
    A.a12 = 1;
    A.a21 = 2;
    A.a22 = getB();

    double d = A.det();
    setResultado(d);
}

void MainWindow::on_inversa_clicked()
{
    Matrix2x2 A;

    A.a11 = getA();
    A.a12 = 1;
    A.a21 = 2;
    A.a22 = getB();

    Matrix2x2 I = A.inv();

    QString text = QString("(%1, %2 ; %3, %4)")
                       .arg(I.a11)
                       .arg(I.a12)
                       .arg(I.a21)
                       .arg(I.a22);
    QMessageBox::information(this,"Matrices","Slot Inversa conectado correctamente");

    ui->resultado->setText(text);
}

void MainWindow::on_evaluarFk_clicked()
{
    int k = getK();
    double x = getA();

    double y = Functions::f_eval(k, x);
    setResultado(y);
}

void MainWindow::on_graficarFk_clicked()
{
    QMessageBox::information(this,"Gráfico","Slot Graficar f_k(x) conectado correctamente");
}
