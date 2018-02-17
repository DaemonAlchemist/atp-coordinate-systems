#ifndef ATP_CARTESIAN_SYSTEM
#define ATP_CARTESIAN_SYSTEM

#ifndef ATP_LIB
#pragma comment(lib, "atp-coordinate-systems.lib")
#endif

#include "vendor/daemonalchemist/atp-vector/src/vector.hpp"

namespace ATP
{
	namespace Math
	{
		namespace CoordinateSystems
		{
			namespace Cartesian
			{
				class System {
				public:
					System(Vector origin, Vector xAxis, Vector yAxis, Vector zAxis);

					Vector origin();
					Vector xAxis();
					Vector yAxis();
					Vector zAxis();

				private:
					Vector _origin, _xAxis, _yAxis, _zAxis;
				};
			}
		}
	}
}

#endif
