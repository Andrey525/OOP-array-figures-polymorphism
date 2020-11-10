#ifndef POINT_H
#define POINT_H

#include <GL/freeglut.h>
#include <GL/glut.h>
#include <cmath>
#include <cstdlib>
#include <ctime>

class Abstract {

public:
    virtual void move() = 0;
    virtual void rotate() = 0;
    virtual float getPointAKoordX() = 0;
    virtual float getPointAKoordY() = 0;
    virtual float getPointBKoordX() = 0;
    virtual float getPointBKoordY() = 0;
    virtual float getPointCKoordX() = 0;
    virtual float getPointCKoordY() = 0;
    virtual float getPointDKoordX() = 0;
    virtual float getPointDKoordY() = 0;

    virtual int what_is_it() = 0;
};

class tPoint : public Abstract {
protected:
    /* Координаты */
    float x;
    float y;

    /* Размер */
    float size;

    /* Цвет */
    float r;
    float g;
    float b;

    /* Направление движения */
    float vector_x;
    float vector_y;

    /* Коэффициент скорости*/
    float koef;

public:
    tPoint();
    int what_is_it()
    {
        return 0;
    }

    void setX(float rx);
    void setY(float ry);
    void setSize(float rsize);
    void setR(float mr);
    void setG(float mg);
    void setB(float mb);
    void setVX(float v_x);
    void setVY(float v_y);
    void setKoef(float koef);

    float getX();
    float getY();
    float getSize();
    float getR();
    float getG();
    float getB();
    float getVX();
    float getVY();
    float getKoef();

    /* Движение */
    void move();
    void rotate()
    {
        return;
    }
    float getPointAKoordX()
    {
        return 0;
    }
    float getPointAKoordY()
    {
        return 0;
    }
    float getPointBKoordX()
    {
        return 0;
    }
    float getPointBKoordY()
    {
        return 0;
    }
    float getPointCKoordX()
    {
        return 0;
    }
    float getPointCKoordY()
    {
        return 0;
    }
    float getPointDKoordX()
    {
        return 0;
    }
    float getPointDKoordY()
    {
        return 0;
    }

    void set_chaos_vector();
};

class tLine : public tPoint {
protected:
    tPoint A, B;
    float alpha;

public:
    tLine();
    int what_is_it()
    {
        return 1;
    }
    void setPointA(float rx, float ry);
    void setPointB(float rx, float ry);
    void setAlpha(float a);

    float getAlpha();
    float getPointAKoordX();
    float getPointAKoordY();
    float getPointBKoordX();
    float getPointBKoordY();

    void move();
    void rotate();
};

class tTriangle : public tLine {
protected:
    tPoint C;

public:
    tTriangle();
    int what_is_it()
    {
        return 2;
    }

    void setPointC(float rx, float ry);

    float getPointCKoordX();
    float getPointCKoordY();

    void move();
    void rotate();
};

class tSquare : public tTriangle {
protected:
    tPoint D;

public:
    tSquare();
    int what_is_it()
    {
        return 3;
    }
    void setPointD(float rx, float ry);

    float getPointDKoordX();
    float getPointDKoordY();

    void move();
    void rotate();
};

class tRhombus : public tSquare {
public:
    tRhombus();
};

class tTrapeze : public tSquare {
public:
    tTrapeze();
};

#endif

