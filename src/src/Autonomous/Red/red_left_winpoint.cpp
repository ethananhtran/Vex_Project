#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_left_winpoint(bool calibrate, mik::auto_variation var, bool get_name) { 
    if (get_name) { return "red left winpoint"; }
    if (calibrate) {
        chassis.set_coordinates(-51.6, 11, 45);
        chassis.drive_distance(5);
        chassis.turn_to_point(-18.316,25.585);
        assembly.intake_motor_group.spin(reverse, 12, volt);
        chassis.drive_to_point(-18.316,25.585);
        wait(0.5, seconds);
        assembly.intake_motor_group.spin(reverse, 0, volt);
        chassis.turn_to_point(-58,47);
        chassis.drive_to_point(-58,47);

        chassis.turn_to_point(-67.5,46.816);
        chassis.drive_distance(-30);

        assembly.intake_motor_group.spin(reverse, 12, volt);
        assembly.ejection_motor.spin(forward,12,volt);
    

        return "";
    }
    
    return "";
}