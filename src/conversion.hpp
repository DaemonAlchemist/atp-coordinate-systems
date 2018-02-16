#ifndef ATP_COORDINATE_CONVERSION
#define ATP_COORDINATE_CONVERSION

#include "vendor\daemonalchemist\atp-vector\src\vector.hpp"
#include "spherical-vector.hpp"
#include "spherical.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			Vector sphericalToCartesian(Spherical::Vector s);
			Vector sphericalToCartesian(Spherical::Vector s, Spherical::System sys);

			Spherical::Vector cartesianToSpherical(Vector v);
			Spherical::Vector cartesianToSpherical(Vector v, Spherical::System sys);
		}
	}
}

#endif
