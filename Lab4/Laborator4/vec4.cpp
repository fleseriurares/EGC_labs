#include "vec2.h"
#include "vec3.h"
#include <math.h>
namespace egc {

vec4& vec4::operator =(const vec4& srcVector) { //"::" ca sa stim ca ne referim la clasa...de implementat toti operatorii si functiile neimplementate

	this->x = srcVector.x;
	this->y = srcVector.y;
	this->z = srcVector.z;
	this->w = srcVector.w;

	return *this;
}


vec4 vec4::operator +(const vec4& srcVector) const
{
	vec4 result;
	result.x = this->x + srcVector.x;
	result.y = this->y + srcVector.y;
	result.z = this->z + srcVector.z;
	result.w = this->w + srcVector.w;

	return result;
}

vec4 vec4::operator -(const vec4& srcVector) const
{
	vec4 result;
	result.x = this->x - srcVector.x;
	result.y = this->y - srcVector.y;
	result.z = this->z - srcVector.z;
	result.w = this->w - srcVector.w;

	return result;
}

vec4& vec4::operator +=(const vec4& srcVector)
{
	this->x = this->x + srcVector.x;
	this->y = this->y + srcVector.y;
	this->z = this->z + srcVector.z;
	this->w = this->w + srcVector.w;

	return *this;
}

vec4 vec4::operator *(float scalarValue) const
{
	vec4 result;
	result.x = scalarValue * this->x;
	result.y = scalarValue * this->y;
	result.z = scalarValue * this->z;
	result.w = scalarValue * this->w;
	return result;
}

vec4& vec4::operator -=(const vec4& srcVector)
{
	this->x = this->x - srcVector.x;
	this->y = this->y - srcVector.y;
	this->z = this->z - srcVector.z;
	this->w = this->w - srcVector.w;

	return *this;
}

float vec4::length() const
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
}

vec4& vec4::normalize()
{

	float aux = this->length();
	this->x = this->x / aux;
	this->y = this->y / aux;
	this->z = this->z / aux;
	this->w = this->w / aux;
	return *this;
}

}
