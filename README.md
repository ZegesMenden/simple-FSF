# simple-FSF
A simple 1-dimensional full state feedback controller

### How to use
This FSF controller works basically the same as a PD controller but with extra steps. The controller takes radians as an input and outputs two different values - angular acceleration and angle. The angular acceleration is simply how fast and in what direction the controller wants your vehicle to accelerate. The angle output is the angle that you must set your thrust vector control mount to in order to obtain the desired angular acceleration.
