#include "Figures.h"
 
 
#define PI 3.14159265

void paintTriangle()
{

    float coordArray[] = {
    -1.0f, 0.0f, 0.0f,//x=-1; y=0;z=0; /_ triangle edge A
    1.0f, 0.0f, 0.0f,// x=1; y=0;z=0; _\  triangle edge  C
    0.0f, 1.0f, 0.0f// x=0; y=1;z=0;  /_\ triangle height B
    };
    // ��� ����� ��������������� ������ ������ ������
    GLuint vertexbuffer;

    // �������� 1 ����� � �������� � ���������� vertexbuffer ��� �������������
    glGenBuffers(1, &vertexbuffer);

    // ������� ������ ��� ��������� ����� �������
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);

    // ��������� ���������� � �������� � OpenGL
    glBufferData(GL_ARRAY_BUFFER, sizeof(coordArray), coordArray, GL_STATIC_DRAW);
    // ���������, ��� ������ ������� ��������� ����� �������
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
    glVertexAttribPointer(
        0,                  // ������� 0. ��������� �� ���� ����� ���������� � �����, ����������� ��������.
        3,                  // ������
        GL_FLOAT,           // ���
        GL_FALSE,           // ���������, ��� �������� �� �������������
        0,                  // ���
        (void*)0            // �������� ������� � ������
    );

    // ������� �����������!
    glDrawArrays(GL_TRIANGLES, 0, 3); // ������� � ������� 0, ����� 3 ������� -> ���� �����������

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
