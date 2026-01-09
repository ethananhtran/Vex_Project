#include "vex.h"

using namespace vex;
using namespace mik;

enum LB_state : int { active = 206, inactive = 229, holding = 170, scoring = 43, hang = 345 };

std::string skills(bool calibrate, mik::auto_variation var, bool get_name) {
    if (get_name) { return "skills"; }
    if (calibrate) {
        chassis.set_coordinates(-47, 0, 270);
        return "";
    }
    
        chassis.turn_to_point(-47,-48);
        chassis.drive_to_point(-47,-48);

        chassis.turn_to_point(64,-48);
        chassis.drive_to_point(-64,-48);
        assembly.intake_motor_group.spin(reverse, 12, volt);

        wait(3, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);

        wait(0.5, seconds);

        chassis.drive_to_point(-25,-48);
        assembly.intake_motor_group.spin(reverse, 12, volt);
        assembly.ejection_motor.spin(forward,12,volt); 

        wait(3, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        assembly.ejection_motor.spin(forward,0,volt); 
            
    return "";
}