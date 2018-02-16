
#include <math.h>
#include "conversion.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			Vector sphericalToCartesian(Spherical::Vector s) {
				return Vector(
					s.r * sin(s.theta) * cos(s.psi),
					s.r * sin(s.theta) * sin(s.psi),
					s.r * cos(s.theta)
				);
			}

			Vector sphericalToCartesian(Spherical::Vector s, Spherical::System sys) {
				//TODO:  Implement
			}

			Spherical::Vector cartesianToSpherical(Vector v) {
				return Spherical::Vector(
					v.length(),
					acos(v.x / v.length()),
					atan2(v.y, v.z)
				);
			}

			Spherical::Vector cartesianToSpherical(Vector v, Spherical::System sys) {
				//TODO:  Implement
			}
		}
	}
}
