#include "Drone.h"
#include <iostream>

#ifdef OPEN_CV_INSTALLED
#include "opencv2/opencv.hpp"
#include "opencv2/highgui/highgui.hpp"
#endif

using namespace std;
using namespace cv;
using namespace DJI::OSKD;

Matrice::Drone::Drone(std::string filename)
{
    std::cout << "Setting up Drone." << std::endl;
}

void Matrice::Drone::getMainCameraStream(int timeInMs)
{
    // Setup OSDK.
    bool enableAdvancedSensing = true;
    LinuxSetup linuxEnvironment(argc, argv, enableAdvancedSensing);
    Vehicle *vehicle = linuxEnvironment.getVehicle();
    const char *acm_dev = linuxEnvironment.getEnvironment()->getDeviceAcm().c_str();
    vehicle->advancedSensing->setAcmDevicePath(acm_dev);
    if (vehicle == NULL)
    {
        std::cout << "Vehicle not initialized, exiting.\n";
        return -1;
    }

    char mainName[] = "MAIN_CAM";

    bool camResult = vehicle->advancedSensing->startMainCameraStream(&show_rgb, &mainName);

    if (!camResult)
    {
        cout << "Failed to open selected camera" << endl;
        return 1;
    }

    CameraRGBImage camImg;

    sleep(timeInMs);

    vehicle->advancedSensing->stopMainCameraStream();
}

void show_rgb(CameraRGBImage img, void *p)
{
    string name = string(reinterpret_cast<char *>(p));
    cout << "#### Got image from:\t" << name << endl;
#ifdef OPEN_CV_INSTALLED
    Mat mat(img.height, img.width, CV_8UC3, img.rawData.data(), img.width * 3);
    cvtColor(mat, mat, COLOR_RGB2BGR);
    imshow(name, mat);
    cv::waitKey(1);
#endif
}
