
#include "spherical.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			namespace Spherical
			{
				System::System(Math::Vector origin, Math::Vector xAxis, Math::Vector yAxis) {
					_origin = origin;
					_xAxis = xAxis.normalize();
					_zAxis = (xAxis ^ yAxis).normalize();
					_yAxis = (_zAxis ^ _xAxis).normalize();
				}

				Math::Vector System::origin() { return _origin; }
				Math::Vector System::xAxis() { return _xAxis; }
				Math::Vector System::yAxis() { return _yAxis; }
				Math::Vector System::zAxis() { return _zAxis; }
			}
		}
	}
}