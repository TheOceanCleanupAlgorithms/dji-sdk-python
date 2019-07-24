#include <string>
#include <dji_vehicle.hpp>
#include <linux_serial_device.hpp>
#include <dji_linux_helpers.hpp>

using namespace DJI::OSDK;

using namespace DJI;

namespace Matrice {

    class Drone {

        public:
            Drone(std::string);

            void getMainCameraStream(int timeInMs);
    };

}
