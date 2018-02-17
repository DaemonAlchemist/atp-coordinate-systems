#ifndef ATP_COORDINATE_CONVERSION
#define ATP_COORDINATE_CONVERSION

#ifndef ATP_LIB
#pragma comment(lib, "atp-coordinate-systems.lib")
#endif

#include "vendor\daemonalchemist\atp-vector\src\vector.hpp"
#include "spherical-vector.hpp"
#include "spherical.hpp"
#include "cartesian.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			Vector cartesianToCartesian(Vector v, Cartesian::System sys1, Cartesian::System sys2);
			Vector cartesianToAbsolute(Vector v, Cartesian::System sys);
			Vector absoluteToCartesian(Vector v, Cartesian::System sys);

			Vector sphericalToCartesian(Spherical::Vector s);
			Vector sphericalToCartesian(Spherical::Vector s, Spherical::System sys);

			Spherical::Vector cartesianToSpherical(Vector v);
			Spherical::Vector cartesianToSpherical(Vector v, Spherical::System sys);

			Spherical::Vector sphericalToSpherical(Spherical::Vector s, Spherical::System sys1, Spherical::System sys2);
		}
	}
}

#endif
