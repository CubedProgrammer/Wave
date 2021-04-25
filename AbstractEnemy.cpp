#include <AbstractEnemy.hpp>
AbstractEnemy::AbstractEnemy()
	:AbstractEnemy(0,0)
{}

AbstractEnemy::AbstractEnemy(float x, float y)
	: AbstractEnemy(x, y, 5.0/64, 5.0/64)
{}

AbstractEnemy::AbstractEnemy(float x, float y, float w, float h)
	:_m_x(x), _m_y(y), _m_vx(), _m_vy(), _m_w(w), _m_h(h)
{}

AbstractEnemy::~AbstractEnemy()
{}

void AbstractEnemy::run()
{
	_m_x += _m_vx;
	_m_y += _m_vy;
	tick();
}
