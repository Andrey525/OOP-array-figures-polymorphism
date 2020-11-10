#include "figures.h"

tSquare::tSquare()
{

    srand(time(NULL) * rand());
    float koef, koord;

    int sign = rand() % 4; // в какой четверти будет расположен

    do {
        koef = 1 + rand() % 2; // коэффициент размера
        setSize(koef);
        koord = rand() / (float(RAND_MAX)); // смещение
    } while (0.1 * getSize() + koord > 1);
    if (sign == 0) { // 1-ая четверть
        setPointA(0 + koord, 0 + koord);
        setPointB(0 + koord, 0.1 * getSize() + koord);
        setPointC(0.1 * getSize() + koord, 0.1 * getSize() + koord);
        setPointD(0.1 * getSize() + koord, 0 + koord);
    } else if (sign == 1) { // 2-ая четверть
        setPointA(0 - koord, 0 + koord);
        setPointB(0 - koord, 0.1 * getSize() + koord);
        setPointC(-0.1 * getSize() - koord, 0.1 * getSize() + koord);
        setPointD(-0.1 * getSize() - koord, 0 + koord);
    } else if (sign == 2) { // 3-ья четверть
        setPointA(0 - koord, 0 - koord);
        setPointB(0 - koord, -0.1 * getSize() - koord);
        setPointC(-0.1 * getSize() - koord, -0.1 * getSize() - koord);
        setPointD(-0.1 * getSize() - koord, 0 - koord);
    } else if (sign == 3) { // 4-ая четверть
        setPointA(0 + koord, 0 - koord);
        setPointB(0 + koord, -0.1 * getSize() - koord);
        setPointC(0.1 * getSize() + koord, -0.1 * getSize() - koord);
        setPointD(0.1 * getSize() + koord, 0 - koord);
    }
    float value = 5 + rand() % 8;
    value = value / 1000;
    setKoef(value);
}

void tSquare::setPointD(float rx, float ry)
{
    this->D.setX(rx);
    this->D.setY(ry);
}

float tSquare::getPointDKoordX()
{
    return this->D.getX();
}

float tSquare::getPointDKoordY()
{
    return this->D.getY();
}

void tSquare::move() // готовая!
{
    this->setPointA(this->getPointAKoordX() + this->getVX() * getKoef(), this->getPointAKoordY() + this->getVY() * getKoef());
    this->setPointB(this->getPointBKoordX() + this->getVX() * getKoef(), this->getPointBKoordY() + this->getVY() * getKoef());
    this->setPointC(this->getPointCKoordX() + this->getVX() * getKoef(), this->getPointCKoordY() + this->getVY() * getKoef());
    this->setPointD(this->getPointDKoordX() + this->getVX() * getKoef(), this->getPointDKoordY() + this->getVY() * getKoef());
    if (this->getPointAKoordX() > 1 || this->getPointAKoordY() > 1 || this->getPointBKoordX() > 1 || this->getPointBKoordY() > 1 || this->getPointCKoordX() > 1 || this->getPointCKoordY() > 1 || this->getPointDKoordX() > 1 || this->getPointDKoordY() > 1 || this->getPointAKoordX() < -1 || this->getPointAKoordY() < -1 || this->getPointBKoordX() < -1 || this->getPointBKoordY() < -1 || this->getPointCKoordX() < -1 || this->getPointCKoordY() < -1 || this->getPointDKoordX() < -1 || this->getPointDKoordY() < -1) {
        srand(time(NULL) * rand());
        float value = 5 + rand() % 8;
        value = value / 1000;
        int sign = rand() % 2; // какой будет угол вращения

        if (sign == 0) {
            this->setAlpha(1);
        } else {
            this->setAlpha(2);
        }
        if (this->getPointAKoordX() > 1) {
            float raznica = 1 - getPointAKoordX();
            this->setPointA(1, getPointAKoordY());
            this->setPointB(getPointBKoordX() + raznica, getPointBKoordY());
            this->setPointC(getPointCKoordX() + raznica, getPointCKoordY());
            this->setPointD(getPointDKoordX() + raznica, getPointDKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointAKoordY() > 1) {
            float raznica = 1 - getPointAKoordY();
            this->setPointA(getPointAKoordX(), 1);
            this->setPointB(getPointBKoordX(), getPointBKoordY() + raznica);
            this->setPointC(getPointCKoordX(), getPointCKoordY() + raznica);
            this->setPointD(getPointDKoordX(), getPointDKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointBKoordX() > 1) {
            float raznica = 1 - getPointBKoordX();
            this->setPointB(1, getPointBKoordY());
            this->setPointA(getPointAKoordX() + raznica, getPointAKoordY());
            this->setPointC(getPointCKoordX() + raznica, getPointCKoordY());
            this->setPointD(getPointDKoordX() + raznica, getPointDKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointBKoordY() > 1) {
            float raznica = 1 - getPointBKoordY();
            this->setPointB(getPointBKoordX(), 1);
            this->setPointA(getPointAKoordX(), getPointAKoordY() + raznica);
            this->setPointC(getPointCKoordX(), getPointCKoordY() + raznica);
            this->setPointD(getPointDKoordX(), getPointDKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointCKoordX() > 1) {
            float raznica = 1 - getPointCKoordX();
            this->setPointC(1, getPointCKoordY());
            this->setPointA(getPointAKoordX() + raznica, getPointAKoordY());
            this->setPointB(getPointBKoordX() + raznica, getPointBKoordY());
            this->setPointD(getPointDKoordX() + raznica, getPointDKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointCKoordY() > 1) {
            float raznica = 1 - getPointCKoordY();
            this->setPointC(getPointCKoordX(), 1);
            this->setPointA(getPointAKoordX(), getPointAKoordY() + raznica);
            this->setPointB(getPointBKoordX(), getPointBKoordY() + raznica);
            this->setPointD(getPointDKoordX(), getPointDKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointDKoordX() > 1) {
            float raznica = 1 - getPointDKoordX();
            this->setPointD(1, getPointDKoordY());
            this->setPointA(getPointAKoordX() + raznica, getPointAKoordY());
            this->setPointB(getPointBKoordX() + raznica, getPointBKoordY());
            this->setPointC(getPointCKoordX() + raznica, getPointCKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointDKoordY() > 1) {
            float raznica = 1 - getPointDKoordY();
            this->setPointD(getPointDKoordX(), 1);
            this->setPointA(getPointAKoordX(), getPointAKoordY() + raznica);
            this->setPointB(getPointBKoordX(), getPointBKoordY() + raznica);
            this->setPointC(getPointCKoordX(), getPointCKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointAKoordX() < -1) {
            float raznica = -1 - getPointAKoordX();
            this->setPointA(-1, getPointAKoordY());
            this->setPointB(getPointBKoordX() + raznica, getPointBKoordY());
            this->setPointC(getPointCKoordX() + raznica, getPointCKoordY());
            this->setPointD(getPointDKoordX() + raznica, getPointDKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointAKoordY() < -1) {
            float raznica = -1 - getPointAKoordY();
            this->setPointA(getPointAKoordX(), -1);
            this->setPointB(getPointBKoordX(), getPointBKoordY() + raznica);
            this->setPointC(getPointCKoordX(), getPointCKoordY() + raznica);
            this->setPointD(getPointDKoordX(), getPointDKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointBKoordX() < -1) {
            float raznica = -1 - getPointBKoordX();
            this->setPointB(-1, getPointBKoordY());
            this->setPointA(getPointAKoordX() + raznica, getPointAKoordY());
            this->setPointC(getPointCKoordX() + raznica, getPointCKoordY());
            this->setPointD(getPointDKoordX() + raznica, getPointDKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointBKoordY() < -1) {
            float raznica = -1 - getPointBKoordY();
            this->setPointB(getPointBKoordX(), -1);
            this->setPointA(getPointAKoordX(), getPointAKoordY() + raznica);
            this->setPointC(getPointCKoordX(), getPointCKoordY() + raznica);
            this->setPointD(getPointDKoordX(), getPointDKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointCKoordX() < -1) {
            float raznica = -1 - getPointCKoordX();
            this->setPointC(-1, getPointCKoordY());
            this->setPointA(getPointAKoordX() + raznica, getPointAKoordY());
            this->setPointB(getPointBKoordX() + raznica, getPointBKoordY());
            this->setPointD(getPointDKoordX() + raznica, getPointDKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointCKoordY() < -1) {
            float raznica = -1 - getPointCKoordY();
            this->setPointC(getPointCKoordX(), -1);
            this->setPointA(getPointAKoordX(), getPointAKoordY() + raznica);
            this->setPointB(getPointBKoordX(), getPointBKoordY() + raznica);
            this->setPointD(getPointDKoordX(), getPointDKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointDKoordX() < -1) {
            float raznica = -1 - getPointDKoordX();
            this->setPointD(-1, getPointDKoordY());
            this->setPointA(getPointAKoordX() + raznica, getPointAKoordY());
            this->setPointB(getPointBKoordX() + raznica, getPointBKoordY());
            this->setPointC(getPointCKoordX() + raznica, getPointCKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointDKoordY() < -1) {
            float raznica = -1 - getPointDKoordY();
            this->setPointD(getPointDKoordX(), -1);
            this->setPointA(getPointAKoordX(), getPointAKoordY() + raznica);
            this->setPointB(getPointBKoordX(), getPointBKoordY() + raznica);
            this->setPointC(getPointCKoordX(), getPointCKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        }
    }
}

void tSquare::rotate()
{
    float eps = 3.14 / 180;
    float x, y; // координаты центра квадрата

    x = (getPointAKoordX() + getPointCKoordX()) / 2;
    y = (getPointAKoordY() + getPointCKoordY()) / 2;

    float xn1, yn1; // новые координаты первой вершины
    float xn2, yn2; // новые координаты второй вершины
    float xn3, yn3; // новые координаты третьей вершины
    float xn4, yn4; // новые координаты четвертой вершины

    xn1 = -sin(this->getAlpha() * eps) * (this->getPointAKoordY() - y) + cos(this->getAlpha() * eps) * (this->getPointAKoordX() - x) + x;
    yn1 = cos(this->getAlpha() * eps) * (this->getPointAKoordY() - y) + sin(this->getAlpha() * eps) * (this->getPointAKoordX() - x) + y;

    xn2 = -sin(this->getAlpha() * eps) * (this->getPointBKoordY() - y) + cos(this->getAlpha() * eps) * (this->getPointBKoordX() - x) + x;
    yn2 = cos(this->getAlpha() * eps) * (this->getPointBKoordY() - y) + sin(this->getAlpha() * eps) * (this->getPointBKoordX() - x) + y;

    xn3 = -sin(this->getAlpha() * eps) * (this->getPointCKoordY() - y) + cos(this->getAlpha() * eps) * (this->getPointCKoordX() - x) + x;
    yn3 = cos(this->getAlpha() * eps) * (this->getPointCKoordY() - y) + sin(this->getAlpha() * eps) * (this->getPointCKoordX() - x) + y;

    xn4 = -sin(this->getAlpha() * eps) * (this->getPointDKoordY() - y) + cos(this->getAlpha() * eps) * (this->getPointDKoordX() - x) + x;
    yn4 = cos(this->getAlpha() * eps) * (this->getPointDKoordY() - y) + sin(this->getAlpha() * eps) * (this->getPointDKoordX() - x) + y;

    this->setPointA(xn1, yn1);
    this->setPointB(xn2, yn2);
    this->setPointC(xn3, yn3);
    this->setPointD(xn4, yn4);
}

tRhombus::tRhombus()
{
    srand(time(NULL) * rand());
    float koef, koord;

    int sign = rand() % 4; // в какой четверти будет расположен

    do {
        koef = 1 + rand() % 2; // коэффициент размера
        setSize(koef);
        koord = rand() / (float(RAND_MAX)); // смещение
    } while (0.2 * getSize() + koord > 1);
    if (sign == 0) { // 1-ая четверть
        setPointA(0 + koord, 0.1 * getSize() + koord);
        setPointB(0.05 * getSize() + koord, 0.2 * getSize() + koord);
        setPointC(0.1 * getSize() + koord, 0.1 * getSize() + koord);
        setPointD(0.05 * getSize() + koord, 0 + koord);
    } else if (sign == 1) { // 2-ая четверть
        setPointA(0 - koord, 0.1 * getSize() + koord);
        setPointB(-0.05 * getSize() - koord, 0.2 * getSize() + koord);
        setPointC(-0.1 * getSize() - koord, 0.1 * getSize() + koord);
        setPointD(-0.05 * getSize() - koord, 0 + koord);
    } else if (sign == 2) { // 3-ья четверть
        setPointA(0 - koord, -0.1 * getSize() - koord);
        setPointB(-0.05 * getSize() - koord, -0.2 * getSize() - koord);
        setPointC(-0.1 * getSize() - koord, -0.1 * getSize() - koord);
        setPointD(-0.05 * getSize() - koord, 0 - koord);
    } else if (sign == 3) { // 4-ая четверть
        setPointA(0 + koord, -0.1 * getSize() - koord);
        setPointB(0.05 * getSize() + koord, -0.2 * getSize() - koord);
        setPointC(0.1 * getSize() + koord, -0.1 * getSize() - koord);
        setPointD(0.05 * getSize() + koord, 0 - koord);
    }
    float value = 5 + rand() % 8;
    value = value / 1000;
    setKoef(value);
}

tTrapeze::tTrapeze()
{
    srand(time(NULL) * rand());
    float koef, koord;

    int sign = rand() % 4; // в какой четверти будет расположен

    do {
        int flag = 1 + rand() % 2;
        if (flag == 1) {
            koef = 0.5;
        } else {
            koef = 1;
        }
        setSize(koef);
        koord = rand() / (float(RAND_MAX)); // смещение
    } while (0.3 * getSize() + koord > 1);
    if (sign == 0) { // 1-ая четверть
        setPointA(0 + koord, 0 + koord);
        setPointB(0.1 * getSize() + koord, 0.15 * getSize() + koord);
        setPointC(0.2 * getSize() + koord, 0.15 * getSize() + koord);
        setPointD(0.3 * getSize() + koord, 0 + koord);
    } else if (sign == 1) { // 2-ая четверть
        setPointA(0 - koord, 0 + koord);
        setPointB(-0.1 * getSize() - koord, 0.15 * getSize() + koord);
        setPointC(-0.2 * getSize() - koord, 0.15 * getSize() + koord);
        setPointD(-0.3 * getSize() - koord, 0 + koord);
    } else if (sign == 2) { // 3-ья четверть
        setPointA(0 - koord, 0 - koord);
        setPointB(-0.1 * getSize() - koord, -0.15 * getSize() - koord);
        setPointC(-0.2 * getSize() - koord, -0.15 * getSize() - koord);
        setPointD(-0.3 * getSize() - koord, 0 - koord);
    } else if (sign == 3) { // 4-ая четверть
        setPointA(0 + koord, 0 - koord);
        setPointB(0.1 * getSize() + koord, -0.15 * getSize() - koord);
        setPointC(0.2 * getSize() + koord, -0.15 * getSize() - koord);
        setPointD(0.3 * getSize() + koord, 0 - koord);
    }
    float value = 5 + rand() % 8;
    value = value / 1000;
    setKoef(value);
}
