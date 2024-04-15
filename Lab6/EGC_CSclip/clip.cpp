#include "clip.h"

namespace egc {

	std::vector<int> computeCSCode(std::vector<vec3> clipWindow, const vec3 p) {
		std::vector<int> code;
		
		float ymin = clipWindow.at(0).y, ymax = clipWindow.at(0).y;
		float xmin = clipWindow.at(0).x, xmax = clipWindow.at(0).x;

		for (int i = 1; i < 4; i++)
		{
			if (clipWindow.at(i).x >= xmax)
			{
				xmax = clipWindow.at(i).x;
			}
			else
			{
				xmin = clipWindow.at(i).x;
			}

			if (clipWindow.at(i).y >= ymax)
			{
				ymax = clipWindow.at(i).y;
			}
			else
			{
				ymin = clipWindow.at(i).y;
			}
		}

		if (p.y < ymin) //U
		{
			code.push_back(1);
		}
		else
		{
			code.push_back(0);
		}

		if (p.y > ymax) //D
		{
			code.push_back(1);
		}
		else
		{
			code.push_back(0);
		}

		if (p.x > xmax) //R
		{
			code.push_back(1);
		}
		else
		{
			code.push_back(0);
		}

		if (p.x < xmin) //L
		{
			code.push_back(1);
		}
		else
		{
			code.push_back(0);
		}

		return code;
	}

	bool simpleRejection(std::vector<int> cod1, std::vector<int> cod2) {
		
		for (int i = 0; i < 4; i++)
		{
			if (cod1.at(i) == 1 && cod2.at(i) == 1)
			{
				return true;
			}
		}

		return false;
	}

	bool simpleAcceptance(std::vector<int> cod1, std::vector<int> cod2) {
		
		for (int i = 0; i < 4; i++)
		{
			if (cod1.at(i) == 1 || cod2.at(i) == 1)
			{
				return false;
			}
		}

		return true;
	}

	bool pointInZone(std::vector<int> cod)
	{
		for (int i = 0; i < 4; i++)
		{
			if (cod.at(i) == 1)
				return false;
		}
		return true;
	}

	std::vector<int> getMinMax(std::vector<vec3> clipWindow)
	{
		std::vector<int> aux;

		float ymin = clipWindow.at(0).y, ymax = clipWindow.at(0).y;
		float xmin = clipWindow.at(0).x, xmax = clipWindow.at(0).x;

		for (int i = 1; i < 4; i++)
		{
			if (clipWindow.at(i).x >= xmax)
			{
				xmax = clipWindow.at(i).x;
			}
			else
			{
				xmin = clipWindow.at(i).x;
			}

			if (clipWindow.at(i).y >= ymax)
			{
				ymax = clipWindow.at(i).y;
			}
			else
			{
				ymin = clipWindow.at(i).y;
			}
		}

		aux.push_back(xmin);
		aux.push_back(xmax);
		aux.push_back(ymin);
		aux.push_back(ymax);
		
		return aux;
	}

	//function returns -1 if the line segment cannot be clipped
	int lineClip_CohenSutherland(std::vector<vec3> clipWindow, vec3& p1, vec3& p2) {
		
		std::vector<int> cod_p1 = computeCSCode(clipWindow, p1);
		std::vector<int> cod_p2 = computeCSCode(clipWindow, p2);
		std::vector<int> minmax = getMinMax(clipWindow);
		int xmin = minmax.at(0);
		int xmax = minmax.at(1);
		int ymin = minmax.at(2);
		int ymax = minmax.at(3);
		int ind = 0;
		while (ind == 0)
		{
			std::vector<int> cod_p1 = computeCSCode(clipWindow, p1);
			std::vector<int> cod_p2 = computeCSCode(clipWindow, p2);
			if (simpleRejection(cod_p1, cod_p2))
			{
				ind = 1;
				return -1;
			}

			if (simpleAcceptance(cod_p1, cod_p2))
			{
				ind = 1;
				return 1;
			}

			if (pointInZone(cod_p1))
			{
				vec3 aux = p1;
				p1 = p2;
				p2 = aux;
			}

			if (cod_p1.at(0) == 1)
			{
				p1.x = p1.x + (p2.x - p1.x) * (ymin - p1.y) / (p2.y - p1.y);
				p1.y = ymin;
			}
			else if (cod_p1.at(1) == 1)
			{
				p1.x = p1.x + (p2.x - p1.x) * (ymax - p1.y) / (p2.y - p1.y);
				p1.y = ymax;
			}
			else if (cod_p1.at(2) == 1)
			{
				p1.y = p1.y + (p2.y - p1.y) * (xmax - p1.x) / (p2.x - p1.x);
				p1.x = xmax;
			}
			else if (cod_p1.at(3) == 1)
			{
				p1.y = p1.y + (p2.y - p1.y) * (xmin - p1.x) / (p2.x - p1.x);
				p1.x = xmin;
			}
		}
		return 0;
	}
}

