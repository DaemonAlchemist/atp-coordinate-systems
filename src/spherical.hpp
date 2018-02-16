#ifndef ATP_SHERICAL_SYSTEM
#define ATP_SHERICAL_SYSTEM

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
					System(Vector origin, Vector xAxis, Vector yAxis);

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
