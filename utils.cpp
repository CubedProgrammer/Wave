#include<random>
#include<GLFW/glfw3.h>
void FillRect(float x, float y, float w, float h)
{
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
	glVertex2f(x,y+h);
	glVertex2f(x+w,y+h);
	glVertex2f(x+w,y);
	glEnd();
}
double rfloat(std::mt19937_64& rng)
{
	double d = rng()&0xffffffffffff;
	return d/0x1000000000000;
}
