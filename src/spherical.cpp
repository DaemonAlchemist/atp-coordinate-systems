
#include "spherical.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			namespace Spherical
			{
				System::System(Vector origin, Vector xAxis, Vector yAxis) {
					_origin = origin;
					_xAxis = xAxis.normalize();
					_zAxis = (xAxis ^ yAxis).normalize();
					_yAxis = (_zAxis ^ _xAxis).normalize();
				}

				Vector System::origin() { return _origin; }
				Vector System::xAxis() { return _xAxis; }
				Vector System::yAxis() { return _yAxis; }
				Vector System::zAxis() { return _zAxis; }
			}
		}
	}
}