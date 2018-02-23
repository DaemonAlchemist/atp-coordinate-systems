
#include <math.h>
#include "conversion.hpp"
#include "vendor/daemonalchemist/atp-matrix/src/matrix.hpp"

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
				Matrix m(3, 3);
				m(0, 0) = sys.xAxis().x; m(0, 1) = sys.yAxis().x; m(0, 2) = sys.zAxis().x;
				m(1, 0) = sys.xAxis().y; m(1, 1) = sys.yAxis().y; m(1, 2) = sys.zAxis().y;
				m(2, 0) = sys.xAxis().z; m(2, 1) = sys.yAxis().z; m(2, 2) = sys.zAxis().z;

				Matrix vFinal(3, 1);
				vFinal(0, 0) = v.x - sys.origin().x;
				vFinal(1, 0) = v.y - sys.origin().y;
				vFinal(2, 0) = v.z - sys.origin().z;

				Matrix mRelative = m.inverse() * vFinal;

				return Vector(mRelative(0, 0), mRelative(1, 0), mRelative(2, 0));
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

			Spherical::Vector cartesianToSpherical(Vector v) {
				return Spherical::Vector(
					v.length(),
					acos(v.z / v.length()),
					atan2(v.y, v.x)
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
