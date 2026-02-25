#pragma once

#include "../core/types.h"
#include "../core/macros.h"

extern float segments_per_second;

float constexpr D = DIST_TT_BASE, R_B = DIST_ROT_TRIM;  // Float constants for TrimBot calculations

void forward_kinematics(const float y, const float z, const float theta_b, const float theta_c);
void home_TRIMBOT();
void inverse_kinematics(const xyz_pos_t &raw);
void trimbot_set_axis_is_at_home(const AxisEnum axis);
void trimbot_report_positions();