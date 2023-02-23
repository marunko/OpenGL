#include "Figures.h"
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
