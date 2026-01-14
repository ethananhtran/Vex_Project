#include "vex.h"

using namespace vex;
using namespace mik;

std::string red_left_winpoint(bool calibrate, mik::auto_variation var, bool get_name) { 
    if (get_name) { return "red left winpoint"; }
    if (calibrate) {
        //this will all run in less than 13 seconds; if not, tayvon will pay the consequences set by tne
        chassis.set_coordinates(-51.6, 13.8, 45);

        chassis.drive_distance(5);
        chassis.turn_to_point(-12,25);
        assembly.intake_motor_group.spin(reverse, 12, volt);
        chassis.drive_to_point(-12,25);

        wait(0.5, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        chassis.turn_to_point(-46.7,46.1);
        chassis.drive_to_point(-46.7,46.1);

        chassis.turn_to_point(-21.7,46.1);
        chassis.drive_distance(30);
        assembly.intake_motor_group.spin(reverse, 12, volt);
        assembly.ejection_motor.spin(forward,12,volt);

        wait(0.5, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        assembly.ejection_motor.spin(forward,0,volt);
        chassis.drive_distance(-45);

        assembly.intake_motor_group.spin(reverse, 12, volt);
        
        wait(1, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        chassis.drive_distance(45);

        wait(0.5, seconds);

        assembly.intake_motor_group.spin(reverse, 12, volt);
        assembly.ejection_motor.spin(forward,12,volt);

        wait(1, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        assembly.ejection_motor.spin(forward,0,volt);
        chassis.drive_distance(-25);
        chassis.turn_to_point(-18.3,-25.9);
        assembly.intake_motor_group.spin(reverse, 12, volt);
        chassis.drive_to_point(-18.3,-25.9);

        wait(0.5, seconds);

        chassis.turn_to_point(-46.7,-48);
        chassis.drive_to_point(-46.7,-48);
        chassis.drive_distance(23);
        assembly.intake_motor_group.spin(reverse, 12, volt);
        
        wait(1, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        chassis.drive_distance(-44);

        wait(0.5, seconds);

        assembly.intake_motor_group.spin(reverse, 12, volt);
        
        wait(1, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        chassis.drive_distance(45);

        wait(0.5, seconds);

        assembly.intake_motor_group.spin(reverse, 12, volt);
        assembly.ejection_motor.spin(forward,12,volt);

        wait(1, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        assembly.ejection_motor.spin(forward,0,volt);

        return "";
    }
    
    return "";
}