#include "Figures.h"
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
