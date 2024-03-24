#include "vec2.h"
#include "vec3.h"
#include <math.h>
namespace egc {

	vec2& vec2::operator =(const vec2& srcVector) { //"::" ca sa stim ca ne referim la clasa...de implementat toti operatorii si functiile neimplementate

		this->x = srcVector.x;
		this->y = srcVector.y;

		return *this;
	}


	vec2 vec2::operator +(const vec2& srcVector) const
	{
		vec2 result;
		result.x = this->x + srcVector.x;
		result.y = this->y + srcVector.y;

		return result;
	}

	vec2 vec2::operator -(const vec2& srcVector) const
	{
		vec2 result;
		result.x = this->x - srcVector.x;
		result.y = this->y - srcVector.y;

		return result;
	}

	vec2& vec2::operator +=(const vec2& srcVector)
	{
		this->x = this->x + srcVector.x;
		this->y = this->y + srcVector.y;

		return *this;
	}

	vec2 vec2::operator *(float scalarValue) const
	{
		vec2 result;
		result.x = scalarValue * this->x;
		result.y = scalarValue * this->y;
		return result;
	}

	vec2& vec2::operator -=(const vec2& srcVector)
	{
		this->x = this->x - srcVector.x;
		this->y = this->y - srcVector.y;

		return *this;
	}

	float vec2::length() const
	{
		return sqrt(this->x * this->x + this->y * this->y);
	}

	vec2& vec2::normalize()
	{

		int aux = this->length();
		this->x = this->x / aux;
		this->y = this->y / aux;
		return *this;
	}

	float dotProduct(const vec2& v1, const vec2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}
}