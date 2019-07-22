# DJISDKPY
DJI SDK python interface

DJISDKPY is a python module interface to DJI's Onboard and Guidance SDKs on linux platforms. It is built with pybind11 and uses the DJI SDK
apis to provide full control of supported DJI vehicles Matrices 100, Matrice 600, Matrice 210/210-RTK or flight
controllers A3 or N3.

## Dependencies

This module has the following depenendencies:

* python3
* python3-dev
* pip3
* setuptools
* build-essential
* cmake

## Compilation and Usage

### Install dependencies

```
sudo apt-get update
sudo apt-get install python3 python3-dev python3-pip build-essential cmake
pip install setuptools
```

### Update the .bashrc file
Add the following lines to the bottom of your `~\.bashrc` file to make python commands run python3 (as opposed to python 2). 
```
alias python=python3
alias pip=pip3
```

### Compilation

```
git clone https://github.com/drmaj/dji-sdk-python
cd dji-sdk-python
git submodule update --init --recursive
python setup.py build_ext -i
```

### Usage

After compilation, djisdkpy.so module will be available in the root directory of the repo. Use the module as follows:

```python

import djisdkpy
import time

drone = djisdkpy.Drone('UserConfig.txt')
drone.initialize()
time.sleep(1)
drone.takeControl()
drone.arm()
drone.takeoff()
time.sleep(5)
drone.land()
drone.disarm()
drone.releaseControl()
drone.shutdown()
```

## TODO

* Add support for Guidance SDK
* Update to support v3.3 of the Onboard SDK
* Add support for RPi3 raspbian
* Add move by position and move by velocity full support

## About

This package was created by [Miguel Alonso Jr](http://www.drmiguelalonsojr.com) with the purpose of providing a simply python interface to DJI's drones and guidance platforms.
It runs on debian linux platforms like the L4T Jetson TX1/TX2.

## License

DJISDKPY is provided under the GNU GPL V3 that can be found in the `LICENSE` file. By using, distributing, or
contributing to this project, you agree to the terms and conditions of this license.

