#include "Figures.h"
 
 
#define PI 3.14159265

void paintTriangle()
{

    float coordArray[] = {
    -1.0f, 0.0f, 0.0f,//x=-1; y=0;z=0; /_ triangle edge A
    1.0f, 0.0f, 0.0f,// x=1; y=0;z=0; _\  triangle edge  C
    0.0f, 1.0f, 0.0f// x=0; y=1;z=0;  /_\ triangle height B
    };
    // Это будет идентификатором нашего буфера вершин
    GLuint vertexbuffer;

    // Создадим 1 буфер и поместим в переменную vertexbuffer его идентификатор
    glGenBuffers(1, &vertexbuffer);

    // Сделаем только что созданный буфер текущим
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

    // Передадим информацию о вершинах в OpenGL
    glBufferData(GL_ARRAY_BUFFER, sizeof(coordArray), coordArray, GL_STATIC_DRAW);
    // Указываем, что первым буфером атрибутов будут вершины
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,                  // Атрибут 0. Подробнее об этом будет рассказано в части, посвященной шейдерам.
        3,                  // Размер
        GL_FLOAT,           // Тип
        GL_FALSE,           // Указывает, что значения не нормализованы
        0,                  // Шаг
        (void*)0            // Смещение массива в буфере
    );

    // Вывести треугольник!
    glDrawArrays(GL_TRIANGLES, 0, 3); // Начиная с вершины 0, всего 3 вершины -> один треугольник

    glDisableVertexAttribArray(0);
}
void paintSquare()
{
   
}
void paintCircle()
{

}

void getCoordinates()
{
    float d = (45 * PI) / 180;
    std::cout <<d << "\n";
    std::cout << (2.82 * cos(d)) << "\n";
    std::cout << (2.82 * sin(d)) << "\n";
    std::cout <<(2.82*cos(d)) - (2.82*sin(d)) << "\n";
    std::cout <<(2.82*sin(d)) + (2.82*cos(d)) << "\n";

}

void rotateTriangle(float x1, float y1, float x2, float y2, int angle)
{
    float d = (angle * PI) / 180;

    glBegin(GL_TRIANGLES);

    glColor3f(0.1, 0.2, 0.3);
    glVertex3f(0, 0, 0);
    glVertex3f(x1, y1, 0);
    glVertex3f(x2, y2, 0);

    int xx1 = x1-(x1*2), xx2 = x2 - (x2 * 2), yy1 = y1 - (y1 * 2), yy2 = y2 - (y2 * 2);
    glColor3f(0.2, 0.2, 0.2);
    glVertex3f(0.0,0.0, 0);
    glVertex3f(xx1, yy1, 0);
    glVertex3f(xx2, yy2, 0);
    glEnd();

    glFlush();
}
