#ifndef ATP_SHERICAL_SYSTEM
#define ATP_SHERICAL_SYSTEM

#ifndef ATP_LIB
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
				class System {
				public:
					System(Math::Vector origin, Math::Vector xAxis, Math::Vector yAxis);

					Math::Vector origin();
					Math::Vector xAxis();
					Math::Vector yAxis();
					Math::Vector zAxis();

				private:
					Math::Vector _origin, _xAxis, _yAxis, _zAxis;
				};
			}
		}
	}
}

#endif
