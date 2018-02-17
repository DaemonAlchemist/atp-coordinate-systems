
#include "cartesian.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			namespace Cartesian
			{
				System::System(Vector origin, Vector xAxis, Vector yAxis, Vector zAxis) {
					_origin = origin;
					_xAxis = xAxis;
					_yAxis = yAxis;
					_zAxis = zAxis;
				}

				Vector System::origin() { return _origin; }
				Vector System::xAxis() { return _xAxis; }
				Vector System::yAxis() { return _yAxis; }
				Vector System::zAxis() { return _zAxis; }
			}
		}
	}
}
