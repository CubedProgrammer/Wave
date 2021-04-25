#ifndef BASICENEMY_HPP_
#define BASICENEMY_HPP_
#include<AbstractEnemy.hpp>
class BasicEnemy:public AbstractEnemy
{
public:
	BasicEnemy();
	BasicEnemy(float, float, float, float);
	virtual void tick();
	virtual void render(GLFWwindow*);
	virtual~BasicEnemy();
private:
};
#endif
