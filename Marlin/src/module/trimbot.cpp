#include "../inc/MarlinConfig.h"

#if ENABLED(TRIMBOT)

#include "trimbot.h"
#include "motion.h"

// For homing:
#include "planner.h"
#include "endstops.h"
//#include "../lcd/marlinui.h"

// forward kinematic model
void forward_kinematics(const float y, const float z, const float theta_b, const float theta_c) {
    cartes.x = D * sin(RADIANS(theta_c)) - sin(RADIANS(theta_c)) * (y + R_B * cos(RADIANS(theta_b)));
    cartes.y = -D * cos(RADIANS(theta_c)) + cos(RADIANS(theta_c)) * (y + R_B * cos(RADIANS(theta_b))) + D;
    cartes.z = z + R_B * sin(RADIANS(theta_b));
}

// homing function
void home_TRIMBOT() {
}

// inverse kinematic model
void inverse_kinematics(const xyz_pos_t &raw) {
    //const float x_t = raw.x, y_t = raw.y, z_t = raw.z;
                    //theta_b = DEGREES(ATAN2(z, (y - d))),
                    //theta_c = DEGREES(ATAN2(x_t, (y_t - D)));

    const float y = SQRT(POW(x_t, 2) + POW((y_t - D), 2)) + D - R_B * cos(RADIANS(theta_b));
    const float z = z_t - R_B * sin(RADIANS(theta_b));
    const float theta_c = ATAN2(x_t, (y_t - D));
    // theta_b is parameter
    delta.set(y, z, theta_c, theta_b);
}

// set axis at home function
void trimbot_set_axis_is_at_home(const AxisEnum axis) {
}

// report positions function
void trimbot_report_positions() {
}


#endif // TRIMBOT