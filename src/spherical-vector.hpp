#ifndef ATP_SPHERICAL_VECTOR
#define ATP_SPHERICAL_VECTOR

#include "vendor\daemonalchemist\atp-vector\src\vector.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			namespace Spherical
			{
				class Vector {
				public:
					Vector(double r, double theta, double psi);

					double r, theta, psi;
				};
			}
		}
	}
}

#endif
