#ifndef ABSTRACTENEMY_HPP_
#define ABSTRACTENEMY_HPP_
#include<GLFW/glfw3.h>

class AbstractEnemy
{
public:
	AbstractEnemy();
	AbstractEnemy(float, float);
	AbstractEnemy(float, float, float, float);
	virtual~AbstractEnemy();
	constexpr bool intersects(float x, float y, float w, float h)const
	{
		bool intx = x<_m_x+_m_w&&x>_m_x||x+w<_m_x+_m_w&&x+w>_m_x||_m_x<x+w&&_m_x>x||_m_x+_m_w<x+w&&_m_x+_m_w>x;
		bool inty = y<_m_y+_m_h&&y>_m_y||y+h<_m_y+_m_h&&y+h>_m_y||_m_y<y+h&&_m_y>y||_m_y+_m_h<y+h&&_m_y+_m_h>y;
		return intx && inty;
	}
	void run();
	virtual void tick()=0;
	virtual void render(GLFWwindow*)=0;

	constexpr void setX(float x) { _m_x = x; }
	constexpr void setY(float y) { _m_y = y; }
	constexpr void setW(float w) { _m_w = w; }
	constexpr void setH(float h) { _m_h = h; }
	constexpr void setVelX(float vx) { _m_vx = vx; }
	constexpr void setVelY(float vy) { _m_vy = vy; }

	constexpr float getX() { return _m_x; }
	constexpr float getY() { return _m_y; }
	constexpr float getW() { return _m_w; }
	constexpr float getH() { return _m_h; }
	constexpr float getVelX() { return _m_vx; }
	constexpr float getVelY() { return _m_vy; }
private:
	float _m_x, _m_y;
	float _m_w, _m_h;
	float _m_vx, _m_vy;
};

#endif
