#pragma once

#include <algorithm>
#include <iostream>

#include "mat3.h"
#include "mat4.h"

namespace egc {

    float& mat4::at(int i, int j) {
        return matrixData[4 * j + i];
    }

    const float& mat4::at(int i, int j) const {
        return matrixData[4 * j + i];
    }

    mat4& mat4::operator =(const mat4& srcMatrix) {
        for (int i = 0; i < 16; i++)
        {
            this->matrixData[i] = srcMatrix.matrixData[i];
        }
        return *this;
    }

    mat4 mat4::operator *(float scalarValue) const {
        mat4 aux;
        for (int i = 0; i < 16; i++) {
            aux.matrixData[i] = this->matrixData[i] * scalarValue;
        }
        return aux;
    }

    mat4 mat4::operator +(const mat4& srcMatrix) const {
        mat4 rez;
        for (int i = 0; i < 16; i++) {
            rez.matrixData[i] = this->matrixData[i] + srcMatrix.matrixData[i];
        }
        return rez;
    }

    mat4 mat4::operator *(const mat4& srcMatrix) const {
        mat4 rez;

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j <4; j++) {
                rez.at(i, j) = 0;
            }
        }

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                for (int k = 0; k < 4; k++) {
                    rez.at(i, j) += this->at(i, k) * srcMatrix.at(k, j);

                }
            }
        }
        return rez;
    }

    vec4 mat4::operator *(const vec4& srcVector) const {
        vec4 rez;

        rez.x = this->at(0, 0) * srcVector.x + this->at(0, 1) * srcVector.y + this->at(0, 2) * srcVector.z + this->at(0,3) * srcVector.w;
        rez.y = this->at(1, 0) * srcVector.x + this->at(1, 1) * srcVector.y + this->at(1, 2) * srcVector.z + this->at(1, 3) * srcVector.w;
        rez.z = this->at(2, 0) * srcVector.x + this->at(2, 1) * srcVector.y + this->at(2, 2) * srcVector.z + this->at(2, 3) * srcVector.w;
        rez.w = this->at(3, 0) * srcVector.x + this->at(3, 1) * srcVector.y + this->at(3, 2) * srcVector.z + this->at(3, 3) * srcVector.w;

        return rez;
    }

    mat4 mat4::transpose() const {
        mat4 rez;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                rez.at(i, j) = this->at(j, i);
            }
        }
        return rez;
    }

    mat3 get_mat(mat4 m4, int I, int J) {
        mat3 rez;

        for (int i = 0,i2 =0 ; i2<3 && i < 4; i++, i2++) {
            for (int j = 0, j2 =0; j2<3 && j < 4; j++, j2++) {
                if (i == I)
                    i++;
                if (j == J)
                    j++;
                rez.at(i2, j2) = m4.at(i, j);
            }
        }
       
        return rez;
    }

    float mat4::determinant() const {
     
        float det=0;
            for (int j = 0; j < 4; j++) {
                if (j % 2 == 0) {
                    det += this->at(0,j) * get_mat(*this, 0, j).determinant();  
                }
                else {
                    det -= this->at(0, j) * get_mat(*this, 0, j).determinant();
                }
            }
        return det;
    }

    mat4 mat4::inverse() const {

        mat4 mat;
        mat4 rez;

        float det_aux = 1.0f/this->determinant();

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if ((i + j) % 2 == 0)
                    rez.at(i, j) = get_mat(*this, i, j).determinant();
                else
                    rez.at(i,j) = -1* get_mat(*this, i, j).determinant();
            }
        }


        rez = rez.transpose();
        rez = rez * det_aux;
        return rez;

    }

}