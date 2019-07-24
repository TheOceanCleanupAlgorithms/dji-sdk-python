#include <string>
#include <dji_vehicle.hpp>
#include <linux_serial_device.hpp>
#include <dji_linux_helpers.hpp>
#include <dji_advanced_sensing.hpp>

using namespace DJI::OSDK;

using namespace DJI;

namespace Matrice {

    class Drone {

        public:
            Drone();

            int getMainCameraStream(std::string userConfigPath, int timeInMs);
    
	    void show_rgb(CameraRGBImage img, void *p);
	};

}
