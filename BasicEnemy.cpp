#include <BasicEnemy.hpp>
#include<utils.hpp>

BasicEnemy::BasicEnemy():
	AbstractEnemy(0, 0, 5.0 / 64, 5.0 / 64)
{}
BasicEnemy::BasicEnemy(float x, float y, float vx, float vy):
	AbstractEnemy(x, y, 5.0 / 64, 5.0 / 64)
{
	setVelX(vx);
	setVelY(vy);
}

BasicEnemy::~BasicEnemy()
{
}

void BasicEnemy::tick()
{}

void BasicEnemy::render(GLFWwindow *window)
{
	glColor3f(0, 0.5, 0.5);
	FillRect(getX() - getW() / 2, getY() - getH() / 2, getW(), getH());
}
