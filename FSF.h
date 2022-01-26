#ifndef FSF_H
#define FSF_H

// for pico C++ SDK
// #include <pico/stdlib.h>
// #include <math.h>

// for arduino
#include <Arduino.h>

class FSF {

    public:

        FSF();
        FSF(float gain_p, float gain_d); // initializer with gains
        FSF(float gain_p, float gain_d, float lever, float inertia); // initializer with gains and properties of the vehicle

        void set_gain_p(float gain_p) { this-> p = gain_p; };
        void set_gain_d(float gain_d) { this-> d = gain_d; };

        void set_lever(float lever) { this-> lever = lever; };
        void set_inertia(float inertia) { this-> inertia = inertia; };

        void set_setpoint(float setpoint) { this-> setpoint = setpoint; };

        float get_lever() { return(this->lever); };
        float get_inertia() { return(this->inertia); };
        float get_gain_p() { return(this->p); };
        float get_gain_d() { return(this->d); };

        float get_torque_output() { return(this->out_torque); };
        float get_angle_output() { return(this->out_angle); };

        float get_setpoint() { return(this->setpoint); };

        void update(float theta, float theta_dot, float thrust)
        {
            float error = theta - this->setpoint;
            this->out_torque = (this->p * error) - (this->d * theta_dot);
            this->out_angle = angle_from_torque(this->out_torque, thrust);
        }

    private:

        float setpoint; // setpoint of the system

        float p, d; // proportional and derivative gains
        float lever; // lever arm
        float inertia; // moment of inertia of the vehicle

        float out_torque; // output torque
        float out_angle; // output angle

        float angle_from_torque(float torque, float thrust) // convert desired torque input to angle output
        {
            if (thrust != 0.0 && this->lever != 0.0, && this->inertia != 0.0) { // make sure all the properties are set
                float calculated_value = torque * this->inertia / thrust / this->lever; // calculate the value to get the arcsin of
                abs(calculated_value) <= 1.0 ? calculated_value = asin(calculated_value) : calculated_value = 0.0;
                return(calculated_value);
                // if the value will not return a real number return 0, otherwise return the angle output
            }
        }

};

#endif