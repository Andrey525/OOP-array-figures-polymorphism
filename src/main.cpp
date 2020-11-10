#include "figures.h"

#define COL_OBJECTS 10

static tPoint* obj[COL_OBJECTS];

void renderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (int i = 0; i < COL_OBJECTS; i++) {
        if (obj[i]->what_is_it() == 0) {
            glPointSize(obj[i]->getSize());
        }
    }
    for (int i = 0; i < COL_OBJECTS; i++) {
        switch (obj[i]->what_is_it()) {
        case 0: // это точка
            glBegin(GL_POINTS);
            glColor3f(obj[i]->getR(), obj[i]->getG(), obj[i]->getB());
            glVertex2f(obj[i]->getX(), obj[i]->getY());
            glEnd();
            break;
        case 1: // это линия
            glBegin(GL_LINES);
            glColor3f(obj[i]->getR(), obj[i]->getG(), obj[i]->getB());
            glVertex2f(obj[i]->getPointAKoordX(), obj[i]->getPointAKoordY());
            glVertex2f(obj[i]->getPointBKoordX(), obj[i]->getPointBKoordY());
            glEnd();
            break;
        case 2: // это треугольник
            glBegin(GL_TRIANGLES);
            glColor3f(obj[i]->getR(), obj[i]->getG(), obj[i]->getB());
            glVertex2f(obj[i]->getPointAKoordX(), obj[i]->getPointAKoordY());
            glVertex2f(obj[i]->getPointBKoordX(), obj[i]->getPointBKoordY());
            glVertex2f(obj[i]->getPointCKoordX(), obj[i]->getPointCKoordY());
            glEnd();
            break;
        case 3: // это четырехугольник
            glBegin(GL_QUADS);
            glColor3f(obj[i]->getR(), obj[i]->getG(), obj[i]->getB());
            glVertex2f(obj[i]->getPointAKoordX(), obj[i]->getPointAKoordY());
            glVertex2f(obj[i]->getPointBKoordX(), obj[i]->getPointBKoordY());
            glVertex2f(obj[i]->getPointCKoordX(), obj[i]->getPointCKoordY());
            glVertex2f(obj[i]->getPointDKoordX(), obj[i]->getPointDKoordY());
            glEnd();
            break;
        }
    }

    glutSwapBuffers();
}

void move(int j = 0)
{
    renderScene();
    for (int i = 0; i < COL_OBJECTS; i++) {
        obj[i]->rotate();
        obj[i]->move();
    }

    glutTimerFunc(5, move, 0);
}

int main(int argc, char** argv)
{
    int flag;
    for (int i = 0; i < COL_OBJECTS; i++) {
        srand(time(NULL) * rand());
        flag = rand() % 6; // каккую фигуру будем создавать
        switch (flag) {
        case 0:
            obj[i] = new tPoint;
            break;
        case 1:
            obj[i] = new tLine;
            break;
        case 2:
            obj[i] = new tTriangle;
            break;
        case 3:
            obj[i] = new tSquare;
            break;
        case 4:
            obj[i] = new tRhombus;
            break;
        case 5:
            obj[i] = new tTrapeze;
            break;
        }
    }
    // инициализация
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(600, 500);
    glutCreateWindow("Lab-4");
    glClearColor(0, 0, 0, 0);

    // регистрация обратных вызовов
    glutDisplayFunc(renderScene);

    move();

    // Основной цикл GLUT
    glutMainLoop();

    return 1;
}
