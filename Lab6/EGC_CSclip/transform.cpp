#include "vec2.h"
#include "vec3.h"
#include "mat3.h"
#include "mat4.h"
#include "transform.h"

namespace egc {
	
	mat3 get_identityM3() {
		mat3 rez;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i == j) {
					rez.at(i, j) = 1;
				}
				else {
					rez.at(i, j) = 0;
				}
			}
		}
		return rez;
	}

	mat4 get_identityM4() {
		mat4 rez;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == j) {
					rez.at(i, j) = 1;
				}
				else {
					rez.at(i, j) = 0;
				}
			}
		}
		return rez;
	}

	mat3 translate(const vec2 translateArray) {
		mat3 rez = get_identityM3();
		rez.at(0, 2) = translateArray.x;
		rez.at(1, 2) = translateArray.y;
		return rez;
	}

	mat3 translate(float tx, float ty) {
		mat3 rez = get_identityM3();
		rez.at(0, 2) = tx;
		rez.at(1, 2) = ty;
		return rez;
	}

	mat3 scale(const vec2 scaleArray) {
		mat3 rez = get_identityM3();
		rez.at(0, 0) = scaleArray.x;
		rez.at(1, 1) = scaleArray.y;
		return rez;
	}

	mat3 scale(float sx, float sy) {
		mat3 rez = get_identityM3();
		rez.at(0, 0) = sx;
		rez.at(1, 1) = sy;
		return rez;
	}

	mat3 rotate(float angle) {
		mat3 rez = get_identityM3();
		float rad = PI * angle / 180;
		rez.at(0, 0) = cos(rad);
		rez.at(1, 1) = cos(rad);
		rez.at(0, 1) = -sin(rad);
		rez.at(1, 0) = sin(rad);
		return rez;
	}

	mat4 translate(const vec3 translateArray) {
		mat4 rez = get_identityM4();
		rez.at(0, 3) = translateArray.x;
		rez.at(1, 3) = translateArray.y;
		rez.at(2, 3) = translateArray.z;
		return rez;
	}

	mat4 translate(float tx, float ty, float tz) {
		mat4 rez = get_identityM4();
		rez.at(0, 3) = tx;
		rez.at(1, 3) = ty;
		rez.at(2, 3) = tz;
		return rez;
	}

	mat4 scale(const vec3 scaleArray) {
		mat4 rez = get_identityM4();
		rez.at(0, 0) = scaleArray.x;
		rez.at(1, 1) = scaleArray.y;
		rez.at(2, 2) = scaleArray.z;
		return rez;
	}
	mat4 scale(float sx, float sy, float sz) {
		mat4 rez = get_identityM4();
		rez.at(0, 0) = sx;
		rez.at(1, 1) = sy;
		rez.at(2, 2) = sz;
		return rez;
	}


	mat4 rotateX(float angle) {
		mat4 rez = get_identityM4();
		float rad = PI * angle / 180;
		rez.at(1, 1) = cos(rad);
		rez.at(2, 2) = cos(rad);
		rez.at(1, 2) = -sin(rad);
		rez.at(2, 1) = sin(rad);
		return rez;
	}



	mat4 rotateY(float angle) {

		mat4 rez = get_identityM4();
		float rad = PI * angle / 180;
		rez.at(0, 0) = cos(rad);
		rez.at(2, 2) = cos(rad);
		rez.at(2, 0) = -sin(rad);
		rez.at(0, 2) = sin(rad);
		return rez;

	}


	mat4 rotateZ(float angle) {

		mat4 rez = get_identityM4();
		float rad = PI * angle / 180;
		rez.at(0, 0) = cos(rad);
		rez.at(1, 1) = cos(rad);
		rez.at(0, 1) = -sin(rad);
		rez.at(1, 0) = sin(rad);
		return rez;

	}

}
