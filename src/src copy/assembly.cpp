#include "vex.h"

using namespace vex;

// Pass in the devices we want to use
Assembly::Assembly(
    mik::motor_group intake_motor_group,
    mik::motor ejection_motor, 
    vex::rotation lift_arm_encoder,
    mik::piston long_piston,
    mik::piston piston_man
) :
    // Assign the ports to the devicMakees
    intake_motor_group(intake_motor_group),
    ejection_motor(ejection_motor),
    lift_arm_encoder(lift_arm_encoder),
    long_piston(long_piston), //  sure when using a 3 wire device that isnt mik::piston you convert the port. `to_triport(PORT_A)`.
    piston_man(piston_man)
{};

// You want to call this function once in the user control function in main.
void Assembly::init() {
    // Create the task to move the lift arm. We only want one task to be created
    lift_task = vex::task([](){
        assembly.long_piston.open();
        assembly.long_piston_control();
        assembly.piston_man_control();
        return 0;
    });
    // To stop the task do `assembly.lift_task.stop();`
} 

// You want to put this function inside the user control loop in main.
void Assembly::control() {
    ejection_motor_control();
    intake_motors_control();
    long_piston_control();
    piston_man_control();
}


// Spins intake forward if L1 is being held, reverse if L2 is being held; stops otherwise
void Assembly::intake_motors_control() {
    if (Controller.ButtonR1.pressing()) {
        intake_motor_group.spin(fwd, 12, volt);
    } else if (Controller.ButtonR2.pressing()) {
        intake_motor_group.spin(fwd, -12, volt);
    } else {
        intake_motor_group.stop();
    }
}
// Spins intake forward if L1 is being held, reverse if L2 is being held; stops otherwise
void Assembly::ejection_motor_control() {
    if (Controller.ButtonL1.pressing()) {
        ejection_motor.spin(fwd, -12, volt);
    } else if (Controller.ButtonL2.pressing()) {
        ejection_motor.spin(fwd, 12, volt);
    } else {
        ejection_motor.stop();
    }
}


// Extends or retracts piston when button A is pressed, can only extend or retract again until button A is released and pressed again
void Assembly::long_piston_control() {
    if (btnA_new_press(Controller.ButtonX.pressing())) {
        long_piston.close();

    }
    if (btnY_new_press(Controller.ButtonY.pressing())) {
        long_piston.open();
    }
}


void Assembly::piston_man_control() {
    if (btnA_new_press(Controller.ButtonA.pressing())) {
        piston_man.close();
    }
    if (btnA_new_press(Controller.ButtonB.pressing())) {
        piston_man.open();
    }
}