#include "Vector2.h"

//Math
#include <cmath>

Vector2::Vector2()
	: X(0.0f)
	, Y(0.0f)
	, m_length(0.0f)
{}

Vector2::Vector2(float uniform)
	: X(uniform)
	, Y(uniform)
	, m_length(0)
{
	Length();
}

Vector2::Vector2(float x, float y)
	: X(x)
	, Y(y)
	, m_length(0)
{
	Length();
}

float Vector2::Length()
{
	float squareDistance = std::sqrt(X * X + Y * Y);
	m_length = squareDistance;
	return m_length;
}

Vector2 & Vector2::operator=(const Vector2 & rhs)
{
	if (this == &rhs)
	{
		return *this;
	}

	X = rhs.X;
	Y = rhs.Y;

	return *this;
}

Vector2 & Vector2::operator+=(const Vector2 & rhs)
{
	X = X + rhs.X;
	Y = Y + rhs.Y;

	return *this;
}

Vector2 & Vector2::operator-=(const Vector2 & rhs)
{
	X = X - rhs.X;
	Y = Y - rhs.Y;

	return *this;
}

Vector2 & Vector2::operator*=(const Vector2 & rhs)
{
	X = X * rhs.X;
	Y = Y * rhs.Y;

	return *this;
}

Vector2 & Vector2::operator/=(const Vector2 & rhs)
{
	X = X / rhs.X;
	Y = Y / rhs.Y;

	return *this;
}

Vector2 Vector2::operator+(const Vector2 & rhs)
{
	Vector2 sum;

	sum.X = X + rhs.X;
	sum.Y = Y + rhs.Y;

	return sum;
}

Vector2 Vector2::operator-(const Vector2 & rhs)
{
	Vector2 sub;
	sub.X = X - rhs.X;
	sub.Y = Y - rhs.Y;

	return sub;
}

Vector2 Vector2::operator-()
{
	return Vector2(-X, -Y);
}

Vector2 Vector2::operator*(const Vector2 & rhs)
{
	Vector2 scaled;

	scaled.Y = Y * rhs.Y;
	scaled.X = X * rhs.X;

	return scaled;
}

Vector2 Vector2::operator/(const Vector2 & rhs)
{
	Vector2 inverseScaled;

	inverseScaled.X = X / rhs.X;
	inverseScaled.Y = Y / rhs.Y;

	return inverseScaled;
}

bool Vector2::operator==(const Vector2 & rhs)
{
	if (this->X == rhs.X && this->Y == rhs.Y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Vector2::operator!=(const Vector2 & rhs)
{
	if (this->X != rhs.X || this->Y != rhs.Y)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Vector2 operator*(float scaleUnit, const Vector2 & rhs)
{
	Vector2 scaled;
	scaled.X = scaleUnit * rhs.X;
	scaled.Y = scaleUnit * rhs.Y;

	return scaled;
}

Vector2 operator*(const Vector2 & lhs, float scaleUnit)
{
	Vector2 scaled;
	scaled.X = scaleUnit * lhs.X;
	scaled.Y = scaleUnit * lhs.Y;

	return scaled;
}