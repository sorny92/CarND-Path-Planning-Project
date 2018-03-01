#include "path_planner.hpp"


void PathPlanner::set_new_points(std::vector<double>& next_x_vals, std::vector<double>& next_y_vals) {
  double pos_x;
  double pos_y;
  double angle;
  int path_size = previous_path_x_.size();

  for(int i = 0; i < path_size; i++)
  {
      next_x_vals.push_back(previous_path_x_[i]);
      next_y_vals.push_back(previous_path_y_[i]);
  }

  if(path_size == 0)
  {
      pos_x = car_x_;
      pos_y = car_y_;
      angle = deg2rad(car_yaw_);
  }
  else
  {
      pos_x = previous_path_x_[path_size-1];
      pos_y = previous_path_y_[path_size-1];

      double pos_x2 = previous_path_x_[path_size-2];
      double pos_y2 = previous_path_y_[path_size-2];
      angle = atan2(pos_y-pos_y2,pos_x-pos_x2);
  }

  double dist_inc = 0.1;
  for(int i = 0; i < 50-path_size; i++)
  {    
      next_x_vals.push_back(pos_x+(dist_inc)*cos(angle+(i+1)*(pi()/100)));
      next_y_vals.push_back(pos_y+(dist_inc)*sin(angle+(i+1)*(pi()/100)));
      pos_x += (dist_inc)*cos(angle+(i)*(pi()/1000));
      pos_y += (dist_inc)*sin(angle+(i)*(pi()/1000));
  }

}

void PathPlanner::update_car_status(double car_x, double car_y, double car_s, 
    double car_d, double car_yaw, double car_speed, std::vector<double> previous_path_x, 
    std::vector<double> previous_path_y, double end_path_s, double end_path_d) {
  car_x_ = car_x;
  car_y_ = car_y;
  car_s_ = car_s;
  car_d_ = car_d;
  car_yaw_ = car_yaw;
  car_speed_ = car_speed;
  previous_path_x_ = previous_path_x;
  previous_path_y_ = previous_path_y;
  end_path_s_ = end_path_s;
  end_path_d_ = end_path_d;
}