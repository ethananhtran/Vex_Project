#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_right_sawp(bool calibrate, mik::auto_variation var, bool get_name) { 
    if (get_name) { return "blue right sawp"; }
    if (calibrate) {
        chassis.set_coordinates(-47, 0, 270);
        chassis.turn_to_point(-47,48);
        chassis.drive_to_point(-47,48);

        chassis.turn_to_point(64,48);
        chassis.drive_distance(15);
        assembly.intake_motor_group.spin(reverse, 12, volt);

        wait(3, seconds);

        wait(0.5, seconds);

        chassis.drive_distance(-30);
        assembly.intake_motor_group.spin(reverse, 12, volt);
        assembly.ejection_motor.spin(forward,12,volt); 

        wait(10, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        assembly.ejection_motor.spin(forward,0,volt); 

        return "";
    }

    return "";
}