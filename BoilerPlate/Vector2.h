#pragma once

#ifndef _VECTOR2_
#define _VECTOR2_

class Vector2
{
public: 
		//Constructor
		Vector2();
		Vector2(float uniform);
		Vector2(float x, float y);

		//Operators
		Vector2& operator=(const Vector2& rhs);
		Vector2& operator+=(const Vector2& rhs);
		Vector2& operator-=(const Vector2& rhs);
		Vector2& operator*=(const Vector2& rhs);
		Vector2& operator/=(const Vector2& rhs);
		Vector2 operator+(const Vector2& rhs);
		Vector2 operator-(const Vector2& rhs);
		Vector2 operator-();
		Vector2 operator*(const Vector2& rhs);
		Vector2 operator/(const Vector2& rhs);
		bool operator==(const Vector2& rhs);
		bool operator!=(const Vector2& rhs);
		friend Vector2 operator*(float scaleUnit, const Vector2& rhs);
		friend Vector2 operator*(const Vector2& lhs, float scaleUnit);

		//Members
		float X;
		float Y;
		float m_length;

		//Functions
		float Length();
};
#endif // !_VECTOR2_