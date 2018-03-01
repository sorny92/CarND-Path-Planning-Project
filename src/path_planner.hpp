#ifndef PATH_PLANNER_H_
#define PATH_PLANNER_H_

#include <math.h>
#include <vector>

#include "json.hpp"
#include "utils.hpp"

class PathPlanner {
public:
  void decode_input_data(nlohmann::json j);
  void set_new_points(std::vector<double>& next_x_vals, std::vector<double>& next_y_vals);
  void update_car_status(double car_x, double car_y, double car_s, double car_d, 
      double car_yaw, double car_speed, std::vector<double> previous_path_x, 
      std::vector<double> previous_path_y, double end_path_s, double end_path_d);

private:  
  double car_x_;
  double car_y_;
  double car_s_;
  double car_d_;
  double car_yaw_;
  double car_speed_;

  std::vector<double> previous_path_x_;
  std::vector<double> previous_path_y_;

  double end_path_s_;
  double end_path_d_;
};

#endif /* PATH_PLANNER_H_ */