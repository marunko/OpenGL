#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include  <tgmath.h>
void paintTriangle();
void paintSquare();
void paintCircle();

void getCoordinates();
void rotateTriangle(float x1, float y1, float x2, float y2, int angle);