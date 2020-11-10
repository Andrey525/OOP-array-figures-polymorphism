#include "figures.h"

tLine::tLine()
{
    srand(time(NULL) * rand());
    float koord1, koord2;
    koord1 = 1 + rand() % 5;
    koord2 = 1 + rand() % 5;
    koord1 = koord1 / 10;
    koord2 = koord2 / 10;
    setPointA(koord1, koord2);
    koord1 = 1 + rand() % 5;
    koord2 = 1 + rand() % 5;
    koord1 = koord1 / 10;
    koord2 = koord2 / 10;
    setPointB(koord1, koord2);

    int sign = rand() % 4; // в какой четверти будет расположен

    if (sign == 1) { //вторая четверть
        setPointA(-1 * getPointAKoordX(), getPointAKoordY());
        setPointB(-1 * getPointBKoordX(), getPointBKoordY());
    } else if (sign == 2) { //третья четверть
        setPointA(getPointAKoordX(), -1 * getPointAKoordY());
        setPointB(getPointBKoordX(), getPointBKoordY());
    } else if (sign == 3) { // четвертая четверть
        setPointA(-1 * getPointAKoordX(), -1 * getPointAKoordY());
        setPointB(-1 * getPointBKoordX(), -1 * getPointBKoordY());
    }

    sign = rand() % 2; // какой будет угол

    if (sign == 0) {
        setAlpha(1);
    } else {
        setAlpha(2);
    }
}

void tLine::setAlpha(float a)
{
    this->alpha = a;
}

float tLine::getAlpha()
{
    return this->alpha;
}

void tLine::setPointA(float rx, float ry)
{
    this->A.setX(rx);
    this->A.setY(ry);
}

void tLine::setPointB(float rx, float ry)
{
    this->B.setX(rx);
    this->B.setY(ry);
}

void tTriangle::setPointC(float rx, float ry)
{
    this->C.setX(rx);
    this->C.setY(ry);
}

float tLine::getPointAKoordX()
{
    return this->A.getX();
}

float tLine::getPointAKoordY()
{
    return this->A.getY();
}

float tLine::getPointBKoordX()
{
    return this->B.getX();
}

float tLine::getPointBKoordY()
{
    return this->B.getY();
}

void tLine::rotate()
{
    float eps = 3.14 / 180;
    float x, y; // координаты центра отрезка

    x = (getPointAKoordX() + getPointBKoordX()) / 2;
    y = (getPointAKoordY() + getPointBKoordY()) / 2;

    float xn1, yn1; // новые координаты первого конца отрезка
    float xn2, yn2; // новые координаты второго конца отрезка

    xn1 = -sin(this->getAlpha() * eps) * (this->getPointAKoordY() - y) + cos(this->getAlpha() * eps) * (this->getPointAKoordX() - x) + x;
    yn1 = cos(this->getAlpha() * eps) * (this->getPointAKoordY() - y) + sin(this->getAlpha() * eps) * (this->getPointAKoordX() - x) + y;

    xn2 = -sin(this->getAlpha() * eps) * (this->getPointBKoordY() - y) + cos(this->getAlpha() * eps) * (this->getPointBKoordX() - x) + x;
    yn2 = cos(this->getAlpha() * eps) * (this->getPointBKoordY() - y) + sin(this->getAlpha() * eps) * (this->getPointBKoordX() - x) + y;

    this->setPointA(xn1, yn1);
    this->setPointB(xn2, yn2);
}

void tLine::move() // готовая!
{
    this->setPointA(this->getPointAKoordX() + this->getVX() * getKoef(), this->getPointAKoordY() + this->getVY() * getKoef());
    this->setPointB(this->getPointBKoordX() + this->getVX() * getKoef(), this->getPointBKoordY() + this->getVY() * getKoef());

    if ((this->getPointAKoordX() > 1 || this->getPointBKoordX() > 1) || (this->getPointAKoordX() < -1 || this->getPointBKoordX() < -1) || (this->getPointAKoordY() > 1 || this->getPointBKoordY() > 1) || (this->getPointAKoordY() < -1 || this->getPointBKoordY() < -1)) {
        srand(time(NULL) * rand());
        float value = 3 + rand() % 5;
        value = value / 1000;

        int sign = rand() % 2; // какой будет угол вращения

        if (sign == 0) {
            this->setAlpha(1);
        } else {
            this->setAlpha(2);
        }
        if (this->getPointAKoordX() > 1) {
            float raznica = 1 - getPointAKoordX();
            setPointA(1, getPointAKoordY());
            setPointB(getPointBKoordX() + raznica, getPointBKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointBKoordX() > 1) {
            float raznica = 1 - getPointBKoordX();
            setPointB(1, getPointBKoordY());
            setPointA(getPointAKoordX() + raznica, getPointAKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointAKoordX() < -1) {
            float raznica = -1 - getPointAKoordX();
            setPointA(-1, getPointAKoordY());
            setPointB(getPointBKoordX() + raznica, getPointBKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointBKoordX() < -1) {
            float raznica = -1 - getPointBKoordX();
            setPointB(-1, getPointBKoordY());
            setPointA(getPointAKoordX() + raznica, getPointAKoordY());
            this->setKoef(value);
            this->setVX(this->getVX() * (-1));
        } else if (this->getPointAKoordY() > 1) {
            float raznica = 1 - getPointAKoordY();
            setPointA(getPointAKoordX(), 1);
            setPointB(getPointBKoordX(), getPointBKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointBKoordY() > 1) {
            float raznica = 1 - getPointBKoordY();
            setPointB(getPointBKoordX(), 1);
            setPointA(getPointAKoordX(), getPointAKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointAKoordY() < -1) {
            float raznica = -1 - getPointAKoordY();
            setPointA(getPointAKoordX(), -1);
            setPointB(getPointBKoordX(), getPointBKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        } else if (this->getPointBKoordY() < -1) {
            float raznica = -1 - getPointBKoordY();
            setPointB(getPointBKoordX(), -1);
            setPointA(getPointAKoordX(), getPointAKoordY() + raznica);
            this->setKoef(value);
            this->setVY(this->getVY() * (-1));
        }
    }
}
