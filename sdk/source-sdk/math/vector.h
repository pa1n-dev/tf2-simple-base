#pragma once
#include <string>

struct box_t
{
	float left, top, right, bottom;
};

class c_vector
{
public:
	float x, y, z;

	c_vector();
	c_vector(float _x, float _y, float _z);

	void make_inf();
	void make_zero();

	void normalize();
	c_vector normalized();
	void clamp();

	float dot(const c_vector& other) const;
	float dot(const float* other) const;

	float length_sqr() const;
	float length_2d_sqr() const;
	float length() const;
	float length_2d() const;
	float distance_to(const c_vector& to) const;

	float operator[] (int index) const;
	float& operator[] (int index);

	c_vector& operator=(const c_vector& other);
	bool operator==(const c_vector& other) const;

	c_vector operator+(const c_vector& other) const;
	c_vector operator-(const c_vector& other) const;
	c_vector operator*(const c_vector& other) const;
	c_vector operator/(const c_vector& other) const;

	c_vector operator+(const float& other) const;
	c_vector operator-(const float& other) const;
	c_vector operator*(const float& other) const;
	c_vector operator/(const float& other) const;

	c_vector& operator+=(const c_vector& other);
	c_vector& operator-=(const c_vector& other);
	c_vector& operator*=(const c_vector& other);
	c_vector& operator/=(const c_vector& other);

	c_vector& operator+=(const float& other);
	c_vector& operator-=(const float& other);
	c_vector& operator*=(const float& other);
	c_vector& operator/=(const float& other);

	operator std::string() const;
};

using q_angle = c_vector;