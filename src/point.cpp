#include "figures.h"

tPoint::tPoint()
{
    float point_size = 9.0;
    srand(time(NULL) * rand());
    int sign = rand() % 4;
    if (sign == 1) {
        setX(float(rand()) / (float(RAND_MAX)) * (-1));
        setY(float(rand()) / (float(RAND_MAX)));
    } else if (sign == 2) {
        setX(float(rand()) / (float(RAND_MAX)));
        setY(float(rand()) / (float(RAND_MAX)) * (-1));
    } else if (sign == 3) {
        setX(float(rand()) / (float(RAND_MAX)) * (-1));
        setY(float(rand()) / (float(RAND_MAX)) * (-1));
    } else {
        setX(float(rand()) / (float(RAND_MAX)));
        setY(float(rand()) / (float(RAND_MAX)));
    }

    float mr = 0, mg = 0, mb = 0;
    while (mr + mg + mb == 0) {
        mr = float(rand() % 2);
        mg = float(rand() % 2);
        mb = float(rand() % 2);
    }
    setR(mr);
    setG(mg);
    setB(mb);
    setSize(point_size);
    if (sign == 0) {
        setVX(1);
        setVY(1);
    } else if (sign == 1) {
        setVX(-1);
        setVY(1);
    } else if (sign == 2) {
        setVX(1);
        setVY(-1);
    } else {
        setVX(-1);
        setVY(-1);
    }
    float value = 3 + rand() % 7;
    value = value / 1000;
    setKoef(value);
}

void tPoint::setX(float rx)
{
    this->x = rx;
}

void tPoint::setY(float ry)
{
    this->y = ry;
}

void tPoint::setSize(float rsize)
{
    this->size = rsize;
}

void tPoint::setR(float mr)
{
    this->r = mr;
}

void tPoint::setG(float mg)
{
    this->g = mg;
}

void tPoint::setB(float mb)
{
    this->b = mb;
}

void tPoint::setVX(float v_x)
{
    this->vector_x = v_x;
}

void tPoint::setVY(float v_y)
{
    this->vector_y = v_y;
}

void tPoint::setKoef(float kf)
{
    this->koef = kf;
}

float tPoint::getX()
{
    return this->x;
}

float tPoint::getY()
{
    return this->y;
}

float tPoint::getSize()
{
    return this->size;
}

float tPoint::getR()
{
    return this->r;
}

float tPoint::getG()
{
    return this->g;
}

float tPoint::getB()
{
    return this->b;
}

float tPoint::getVX()
{
    return this->vector_x;
}

float tPoint::getVY()
{
    return this->vector_y;
}

float tPoint::getKoef()
{
    return this->koef;
}

void tPoint::move()
{
    this->setX(this->getX() + this->getVX() * this->getKoef());
    this->setY(this->getY() + this->getVY() * this->getKoef());
    if (this->getX() > 1 - 0.02 || this->getX() < -1 + 0.02 || this->getY() > 1 - 0.02 || this->getY() < -1 + 0.02) {
        srand(time(NULL) * rand());
        float value = 3 + rand() % 7;
        value = value / 1000;
        if (this->getX() > 1 - 0.02) {
            this->setKoef(value);
            this->setX(1 - 0.02);
            this->setVX(this->getVX() * (-1));
        }
        if (this->getX() < -1 + 0.02) {
            this->setKoef(value);
            this->setX(-1 + 0.02);
            this->setVX(this->getVX() * (-1));
        }
        if (this->getY() > 1 - 0.02) {
            this->setKoef(value);
            this->setY(1 - 0.02);
            this->setVY(this->getVY() * (-1));
        }
        if (this->getY() < -1 + 0.02) {
            this->setKoef(value);
            this->setY(-1 + 0.02);
            this->setVY(this->getVY() * (-1));
        }
    }
}

void tPoint::set_chaos_vector()
{
    srand(time(NULL) * rand());
    int value1 = rand() % 100;
    int value2 = rand() % 100;
    int value3 = rand() % 100;
    if (value1 == value2) {
        this->setKoef(0.002);
        this->setVY(this->getVY() * (-1));
    } else if (value1 == value3) {
        this->setKoef(0.003);
        this->setVX(this->getVX() * (-1));
    }
}
