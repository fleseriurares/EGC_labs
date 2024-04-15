#pragma once

#include <algorithm>
#include <iostream>

#include "mat3.h"

namespace egc {
    
    float& mat3::at(int i, int j) {
        return matrixData[3 * j + i];
    }

    const float& mat3::at(int i, int j) const {
        return matrixData[3 * j + i];
    }

    mat3& mat3::operator =(const mat3& srcMatrix) {
        for (int i = 0; i < 9; i++)
        {
            this->matrixData[i] = srcMatrix.matrixData[i];
        }
        return *this;
    }

    mat3 mat3::operator *(float scalarValue) const {    
        mat3 aux;
        for (int i = 0; i < 9; i++) {
            aux.matrixData[i] = this->matrixData[i] * scalarValue;
        }
        return aux;
    }

    mat3 mat3::operator +(const mat3& srcMatrix) const {
        mat3 rez;
        for (int i = 0; i < 9; i++) {
            rez.matrixData[i] = this->matrixData[i] + srcMatrix.matrixData[i];
        }
        return rez;
    }

    mat3 mat3::operator *(const mat3& srcMatrix) const {
        mat3 rez;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                rez.at(i, j) = 0;
            }
        }

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
               for(int k=0; k<3; k++){
                   rez.at(i, j) += this->at(i, k) * srcMatrix.at(k, j);
                
                }
            }
        }
        return rez;
    }

    vec3 mat3::operator *(const vec3& srcVector) const {
        vec3 rez;

        rez.x = this->at(0, 0) * srcVector.x + this->at(0, 1) * srcVector.y + this->at(0, 2) * srcVector.z;
        rez.y = this->at(1, 0) * srcVector.x + this->at(1, 1) * srcVector.y + this->at(1, 2) * srcVector.z;
        rez.z = this->at(2, 0) * srcVector.x + this->at(2, 1) * srcVector.y + this->at(2, 2) * srcVector.z;

        return rez;
    }

    mat3 mat3::transpose() const {
        mat3 rez;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                rez.at(i, j) = this->at(j, i);
            }
        }
        return rez;
    }

    float mat3::determinant() const {
        return this->at(0, 0) * this->at(1, 1) * this->at(2, 2) + this->at(1, 0) * this->at(2, 1) * this->at(0, 2) +
            this->at(0, 1) * this->at(1, 2) * this->at(2, 0) - this->at(0, 2) * this->at(1, 1) * this->at(2, 0) -
            this->at(0, 0) * this->at(1, 2) * this->at(2, 1) - this->at(1, 0) * this->at(0, 1) * this->at(2, 2);
    }

    mat3 mat3::inverse() const {
        
        mat3 mat;
        mat3 rez;

        float det = this->determinant();
        mat = *this;
        
        rez.at(0, 0) = (mat.at(1, 1) * mat.at(2, 2) - mat.at(2, 1) * mat.at(1, 2)) / det;
        rez.at(0, 1) = -1.0f*(mat.at(1, 0) * mat.at(2, 2) - mat.at(2, 0) * mat.at(1, 2)) / det;
        rez.at(0, 2) = (mat.at(1, 0) * mat.at(2, 1) - mat.at(2, 0) * mat.at(1, 1)) / det;
        rez.at(1, 0) = -1.0f*(mat.at(0, 1) * mat.at(2, 2) - mat.at(2, 1) * mat.at(0, 2)) / det;
        rez.at(1, 1) = (mat.at(0, 0) * mat.at(2, 2) - mat.at(2, 0) * mat.at(0, 2)) / det;
        rez.at(1, 2) = -1.0f * (mat.at(0, 0) * mat.at(2, 1) - mat.at(2, 0) * mat.at(0, 1)) / det;
        rez.at(2, 0) = (mat.at(0, 1) * mat.at(1, 2) - mat.at(1, 1) * mat.at(0, 2)) / det;
        rez.at(2, 1) = -1.0f * (mat.at(0, 0) * mat.at(1, 2) - mat.at(1, 0) * mat.at(0, 2)) / det;
        rez.at(2, 2) = (mat.at(0, 0) * mat.at(1, 1) - mat.at(1, 0) * mat.at(0, 1) )/ det;
        
        rez = rez.transpose();

        return rez;
    
    }

}