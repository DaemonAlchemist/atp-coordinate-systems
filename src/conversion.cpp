
#include <math.h>
#include "conversion.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			Vector cartesianToCartesian(Vector v, Cartesian::System sys1, Cartesian::System sys2) {
				return absoluteToCartesian(cartesianToAbsolute(v, sys1), sys2);
			}

			Vector cartesianToAbsolute(Vector v, Cartesian::System sys) {
				return v.x * sys.xAxis() + v.y * sys.yAxis() + v.z * sys.zAxis() + sys.origin();
			}

			Vector absoluteToCartesian(Vector v, Cartesian::System sys) {
				v -= sys.origin();
				return Vector(
					v.projectionOnto(sys.xAxis()).length(),
					v.projectionOnto(sys.yAxis()).length(),
					v.projectionOnto(sys.zAxis()).length()
				);
			}

			Vector sphericalToCartesian(Spherical::Vector s) {
				return Vector(
					s.r * sin(s.theta) * cos(s.psi),
					s.r * sin(s.theta) * sin(s.psi),
					s.r * cos(s.theta)
				);
			}

			Vector sphericalToCartesian(Spherical::Vector s, Spherical::System sys) {
				return cartesianToAbsolute(sphericalToCartesian(s), Cartesian::System(sys.origin(), sys.xAxis(), sys.yAxis(), sys.zAxis()));
			}

			Vector sphericalToCartesian(Spherical::Vector s, Cartesian::System sys) {
				return absoluteToCartesian(sphericalToCartesian(s), sys);
			}

			Vector sphericalToCartesian(Spherical::Vector s, Spherical::System sys1, Cartesian::System sys2) {
				return absoluteToCartesian(sphericalToCartesian(s, sys1), sys2);
			}

			Vector sphericalToCartesian(Spherical::Vector s, Spherical::System sys) {
				Vector c = sphericalToCartesian(s);
				return c.x * sys.xAxis() + c.y * sys.yAxis() + c.z * sys.zAxis() + sys.origin();
			}

			Spherical::Vector cartesianToSpherical(Vector v) {
				return Spherical::Vector(
					v.length(),
					acos(v.x / v.length()),
					atan2(v.y, v.z)
				);
			}

			Spherical::Vector cartesianToSpherical(Vector v, Spherical::System sys) {
				return cartesianToSpherical(absoluteToCartesian(v, Cartesian::System (sys.origin(), sys.xAxis(), sys.yAxis(), sys.zAxis())));
			}

			Spherical::Vector cartesianToSpherical(Vector v, Cartesian::System sys) {
				return cartesianToSpherical(cartesianToAbsolute(v, sys));
			}

			Spherical::Vector cartesianToSpherical(Vector v, Cartesian::System sys1, Spherical::System sys2) {
				return cartesianToSpherical(cartesianToAbsolute(v, sys1), sys2);
			}

			Spherical::Vector sphericalToSpherical(Spherical::Vector s, Spherical::System sys1, Spherical::System sys2) {
				return cartesianToSpherical(sphericalToCartesian(s, sys1), sys2);
			}
		}
	}
}
