
#include <math.h>
#include "spherical-vector.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			namespace Spherical
			{
				Vector::Vector(double r, double theta, double psi) {
					this->r = r;
					this->theta = theta;
					this->psi = psi;
				}
			}
		}
	}
}
