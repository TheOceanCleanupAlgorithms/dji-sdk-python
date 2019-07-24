#include "Drone.h"
#include <iostream>

#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>

using namespace std;
using namespace cv;

Matrice::Drone::Drone()
{
    std::cout << "Setting up Drone." << std::endl;
}

int Matrice::Drone::getMainCameraStream(std::string userConfigPath, int timeInMs)
{
    // Setup OSDK.
    bool enableAdvancedSensing = true;
    LinuxSetup linuxEnvironment(userConfigPath, enableAdvancedSensing);
    Vehicle *vehicle = linuxEnvironment.getVehicle();
    const char *acm_dev = linuxEnvironment.getEnvironment()->getDeviceAcm().c_str();
    vehicle->advancedSensing->setAcmDevicePath(acm_dev);
    if (vehicle == NULL)
    {
        std::cout << "Vehicle not initialized, exiting.\n";
        return -1;
    }

    char mainName[] = "MAIN_NAME";
    bool camResult = vehicle->advancedSensing->startMainCameraStream((CameraImageCallback)&Matrice::Drone::show_rgb, &mainName);

    if (!camResult)
    {
        cout << "Failed to open selected camera" << endl;
        return 1;
    }

    CameraRGBImage camImg;

    sleep(timeInMs);

    vehicle->advancedSensing->stopMainCameraStream();

    return 0;
}

void Matrice::Drone::show_rgb(CameraRGBImage img, void* p)
{
    string name = "MAIN_CAM";
    cout << "#### Got image from:\t" << name << endl;
    Mat mat(img.height, img.width, CV_8UC3, img.rawData.data(), img.width * 3);
    cvtColor(mat, mat, COLOR_RGB2BGR);
    imshow(name, mat);
    cv::waitKey(1);
}
