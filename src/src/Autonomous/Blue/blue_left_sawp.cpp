#include "vex.h"

using namespace vex;
using namespace mik;

std::string blue_left_sawp(bool calibrate, mik::auto_variation var, bool get_name) { 
    if (get_name) { return "blue left sawp"; }
    if (calibrate) {
        chassis.set_coordinates(-43.75, -0.5, 90);
        assembly.long_piston.close();
        chassis.drive_distance(5);
        chassis.turn_to_point(-47.5,48);
        chassis.drive_to_point(-47.5,48);

        chassis.turn_to_point(-64,48);
        chassis.drive_distance(-30);
        chassis.drive_distance(30);
        assembly.intake_motor_group.spin(reverse, 12, volt);

        wait(2, seconds);

        chassis.drive_distance(-32);
        assembly.intake_motor_group.spin(reverse, 12, volt);
        assembly.ejection_motor.spin(forward,12,volt); 
        /*for (int i=0; i<=5; i++){
            chassis.drive_distance(-0.25);
            chassis.drive_distance(0.25);
        };
        */
        wait(2, seconds);
        assembly.intake_motor_group.spin(reverse, 0, volt);
        assembly.ejection_motor.spin(forward,0,volt); 

        chassis.drive_distance(5);
        chassis.turn_to_point(-35,-47.6);
        chassis.drive_to_point(-35,-47.6);

        chassis.turn_to_point(-80,-47.6);
        chassis.drive_distance(-25);
        chassis.drive_distance(35);
        assembly.intake_motor_group.spin(reverse, 12, volt);

        wait(3, seconds);

        chassis.drive_distance(-30);
        assembly.intake_motor_group.spin(reverse, 12, volt);
        assembly.ejection_motor.spin(forward,12,volt); 

        wait(2, seconds);

        assembly.intake_motor_group.spin(reverse, 0, volt);
        assembly.ejection_motor.spin(forward,0,volt); 

        return "";
    }

    return "";
}