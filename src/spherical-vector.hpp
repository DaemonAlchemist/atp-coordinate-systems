#ifndef ATP_SPHERICAL_VECTOR
#define ATP_SPHERICAL_VECTOR

#ifndef ATP_COORDINATE_SYSTEMLIB
#pragma comment(lib, "atp-coordinate-systems.lib")
#endif

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
