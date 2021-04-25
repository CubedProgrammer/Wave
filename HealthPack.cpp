#include<HealthPack.hpp>
HealthPack::HealthPack()
	:HealthPack(0,0,0)
{}
HealthPack::HealthPack(float x, float y, unsigned strength)
	:_m_x(x), _m_y(y), _m_strength(strength)
{}
HealthPack::~HealthPack()=default;

unsigned&HealthPack::getStrength()
{
	return _m_strength;
}
float HealthPack::getX()
{
	return _m_x;
}
float HealthPack::getY()
{
	return _m_y;
}
