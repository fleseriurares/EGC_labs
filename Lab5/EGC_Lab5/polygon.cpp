//
// Created by adi on 09.03.2022.
//

#include "polygon.h"

namespace egc {


    polygon::polygon() {

    }

    void polygon::addVertex(vec3 vertex) {

        this->vertices.push_back(vertex);
    }


    float polygon::getCx()
    {
        float rez;
        int sum = 0;
        for (size_t i = 0; i < this->vertices.size(); i++)
        {
            sum += this->vertices.at(i).x;
        }

        return sum / this->vertices.size();
    }

    float polygon::getCy()
    {
        float rez;
        int sum = 0;
        for (size_t i = 0; i < this->vertices.size(); i++)
        {
            sum += this->vertices.at(i).y;
        }

        return sum / this->vertices.size();
    }

    void polygon::clearVertices() {

        this->vertices.clear();
    }

    void polygon::draw(SDL_Renderer *windowRenderer) {

        std::vector<vec3> transformedVertices = vertices;

        for (size_t i = 0; i < this->vertices.size(); i++)
        {
            transformedVertices.at(i) = transformationMatrix * vertices.at(i);
        }

        if (this->vertices.size() >= 2) {
            size_t I;
            SDL_SetRenderDrawColor(windowRenderer, 0, 0, 255, 255);
            for (I = 0; I < vertices.size() -1; I++)
            {

                SDL_RenderDrawLine(
                    windowRenderer,
                    /* static_cast<int>(this->vertices.at(0).x),
                     static_cast<int>(this->vertices.at(0).y),
                     static_cast<int>(this->vertices.at(1).x),
                     static_cast<int>(this->vertices.at(1).y));*/

                    static_cast<int>(transformedVertices.at(I).x),
                    static_cast<int>(transformedVertices.at(I).y),
                    static_cast<int>(transformedVertices.at(I+1).x),
                    static_cast<int>(transformedVertices.at(I+1).y));
            }

            SDL_RenderDrawLine(
                windowRenderer,
                static_cast<int>(transformedVertices.at(I).x),
                static_cast<int>(transformedVertices.at(I).y),
                static_cast<int>(transformedVertices.at(0).x),
                static_cast<int>(transformedVertices.at(0).y));

        }
    }


}