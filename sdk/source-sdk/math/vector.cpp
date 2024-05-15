#include "vector.h"

c_vector::c_vector()
{
	make_zero();
}

c_vector::c_vector(float _x, float _y, float _z) : x(_x), y(_y), z(_z)
{

}

void c_vector::make_inf()
{
	x = y = z = std::numeric_limits<float>::infinity();
}

void c_vector::make_zero()
{
	x = y = z = 0.f;
}

void c_vector::normalize()
{
	float magnitude = length();

	x /= magnitude;
	y /= magnitude;
	z /= magnitude;
}

c_vector c_vector::normalized()
{
	float magnitude = length();

	c_vector vector = *this;
	vector.x /= magnitude;
	vector.y /= magnitude;
	vector.z /= magnitude;

	return vector;
}

void c_vector::clamp()
{
	while (y < -180.0f)
		y += 360.0f;

	while (x < -89.0f)
		x += 180.f;

	z = 0.0f;
}

float c_vector::dot(const c_vector& other) const
{
	return (x * other.x + y * other.y + z * other.z);
}

float c_vector::dot(const float* other) const
{
	return (x * other[0] + y * other[1] + z * other[2]);
}

float c_vector::length_sqr() const
{
	return (x * x + y * y + z * z);
}

float c_vector::length_2d_sqr() const
{
	return (x * x + y * y);
}

float c_vector::length() const
{
	return sqrt(length_sqr());
}

float c_vector::length_2d() const
{
	return sqrt(length_2d_sqr());
}

float c_vector::distance_to(const c_vector& to) const
{
	return (*this - to).length();
}

float c_vector::operator[](int idx) const
{
	return ((float*)this)[idx];
}

float& c_vector::operator[](int idx)
{
	return ((float*)this)[idx];
}

c_vector& c_vector::operator=(const c_vector& other)
{
	x = other.x; y = other.y; z = other.z;

	return *this;
}

bool c_vector::operator==(const c_vector& other) const
{
	return x == other.x && y == other.y && z == other.z;
}

c_vector c_vector::operator+(const c_vector& other) const
{
	return { x + other.x, y + other.y, z + other.z };
}

c_vector c_vector::operator-(const c_vector& other) const
{
	return { x - other.x, y - other.y, z - other.z };
}

c_vector c_vector::operator*(const c_vector& other) const
{
	return { x * other.x, y * other.y, z * other.z };
}

c_vector c_vector::operator/(const c_vector& other) const
{
	return { x / other.x, y / other.y, z / other.z };
}

c_vector c_vector::operator+(const float& other) const
{
	return { x + other, y + other, z + other };
}

c_vector c_vector::operator-(const float& other) const
{
	return { x - other, y - other, z - other };
}

c_vector c_vector::operator*(const float& other) const
{
	return { x * other, y * other, z * other };
}

c_vector c_vector::operator/(const float& other) const
{
	return { x / other, y / other, z / other };
}

c_vector& c_vector::operator+=(const c_vector& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

c_vector& c_vector::operator-=(const c_vector& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

c_vector& c_vector::operator*=(const c_vector& other)
{
	x *= other.x;
	y *= other.y;
	z *= other.z;
	return *this;
}

c_vector& c_vector::operator/=(const c_vector& other)
{
	x /= other.x;
	y /= other.y;
	z /= other.z;
	return *this;
}

c_vector& c_vector::operator+=(const float& other)
{
	x += other;
	y += other;
	z += other;
	return *this;
}

c_vector& c_vector::operator-=(const float& other)
{
	x -= other;
	y -= other;
	z -= other;
	return *this;
}

c_vector& c_vector::operator*=(const float& other)
{
	x *= other;
	y *= other;
	z *= other;
	return *this;
}

c_vector& c_vector::operator/=(const float& other)
{
	x /= other;
	y /= other;
	z /= other;
	return *this;
}

c_vector::operator std::string() const 
{
	return std::string("x: " + std::to_string(this->x) + " y: " + std::to_string(this->y) + " z: " + std::to_string(this->z));
}