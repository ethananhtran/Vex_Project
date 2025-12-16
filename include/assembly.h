#pragma once

#include "vex.h"

using namespace vex;

enum lift_positions : int { IDLE = 229, LOADING = 206, SCORING = 99 };

class Assembly {
public:
    Assembly(
        mik::motor_group intake_motor_group,
        mik::motor ejection_motor, 
        vex::rotation lift_arm_encoder,
        mik::piston long_piston,
        mik::piston piston_man
    );
    
    void init();
    void control();

    void move_lift_arm();
    void lift_arm_control();
    void intake_motors_control();
    void long_piston_control();
    void piston_man_control();
    void ejection_motor_control();

    int lift_arm_position = IDLE;
    vex::task lift_task;
    
    mik::motor_group intake_motor_group;
    mik::motor ejection_motor;
    vex::rotation lift_arm_encoder;
    mik::piston long_piston;
    mik::piston piston_man;
};