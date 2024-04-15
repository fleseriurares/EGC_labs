
#include "vec2.h"
#include "vec3.h"
#include <math.h>
namespace egc {

	vec3& vec3::operator =(const vec3& srcVector) { //"::" ca sa stim ca ne referim la clasa...de implementat toti operatorii si functiile neimplementate

		this->x = srcVector.x;
		this->y = srcVector.y;
		this->z = srcVector.z;

		return *this;
	}


	vec3 vec3::operator +(const vec3& srcVector) const
	{
		vec3 result;
		result.x = this->x + srcVector.x;
		result.y = this->y + srcVector.y;
		result.z = this->z + srcVector.z;

		return result;
	}

	vec3 vec3::operator -(const vec3& srcVector) const
	{
		vec3 result;
		result.x = this->x - srcVector.x;
		result.y = this->y - srcVector.y;
		result.z = this->z - srcVector.z;

		return result;
	}

	vec3& vec3::operator +=(const vec3& srcVector)
	{
		this->x = this->x + srcVector.x;
		this->y = this->y + srcVector.y;
		this->z = this->z + srcVector.z;

		return *this;
	}

	vec3 vec3::operator *(float scalarValue) const
	{
		vec3 result;
		result.x = scalarValue * this->x;
		result.y = scalarValue * this->y;
		result.z = scalarValue * this->z;
		return result;
	}

	vec3& vec3::operator -=(const vec3& srcVector)
	{
		this->x = this->x - srcVector.x;
		this->y = this->y - srcVector.y;
		this->z = this->z - srcVector.z;

		return *this;
	}

	float vec3::length() const
	{
		return sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
	}

	vec3& vec3::normalize()
	{
		float aux = this->length();
		this->x = this->x / aux;
		this->y = this->y / aux;
		this->z = this->z / aux;
		return *this;
	}
	/*
	vec2& vec2::normalize()
	{
		vec2 result;
		result.x = this->x / this->length();
		result.y = this->y / this->length();
		return result;
	}
	*/

	float dotProduct(const vec3& v1, const vec3& v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	vec3 crossProduct(const vec3& v1, const vec3& v2)
	{
		vec3 result;
		result.x = v1.y * v2.z - v1.z * v2.y;
		result.y = -v1.y * v2.x + v1.x * v2.z;
		result.z = v1.x * v2.y - v1.y * v2.x;
		return result;
	}
}
