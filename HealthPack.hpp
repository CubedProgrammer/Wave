#ifndef HEALTHPACK_HPP_
#define HEALTHPACK_HPP_
class HealthPack
{
public:
	HealthPack();
	HealthPack(float, float, unsigned);
	~HealthPack();
	unsigned&getStrength();
	float getX();
	float getY();
private:
	float _m_x;
	float _m_y;
	unsigned _m_strength;
};
#endif
