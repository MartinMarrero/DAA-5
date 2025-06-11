// Universidad de La Laguna 
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Diseño y Análisis de Algoritmos
//
// @brief Implementation file for the point class
// @since June 5th, 2025
// @see /docs for documentation
// @see {@link https://github.com/MartinMarrero/DAA-5#}

#include "./lib/vehicle.h"

Vehicle::Vehicle(int id, double coord_x, double coord_y, double capacity, double time_limit, double speed) {
  id_ = id;
  x_coordinate_ = coord_x;
  y_coordinate_ = coord_y;
  capacity_ = capacity;
  total_capacity_ = capacity;
  time_limit_ = time_limit;
  time_ = time_limit;
  speed_ = speed / 60.0; // km/h to km/min
  route_ = new Route();
}

Vehicle::Vehicle(Vehicle* vehicle) {
  id_ = vehicle->GetId();
  x_coordinate_ = vehicle->GetX();
  y_coordinate_ = vehicle->GetY();
  capacity_ = vehicle->GetRemainingCapacity();
  total_capacity_ = vehicle->GetTotalCapacity();
  time_limit_ = vehicle->GetTimeLimit();
  speed_ = vehicle->GetSpeed();
  route_ = new Route(*vehicle->GetRoute());
}

Vehicle::~Vehicle() {}

void Vehicle::InsertToRoute(Zone* zone, double time_to_zone) {
  route_->Insert(zone, time_to_zone);
}

void Vehicle::TravelTo(Zone* zone) {
  double time_to_zone = GetTimeTo(zone, route_->GetLast());
  time_ -= time_to_zone;
  x_coordinate_ = zone->GetX();
  y_coordinate_ = zone->GetY();
  route_->Insert(zone, time_to_zone);
  // std::cout << "Vehicle " << id_ << " traveled to zone " << zone->GetId() << std::endl;
  // std::cout << "At coordinates: (" << x_coordinate_ << ", " << y_coordinate_ << ")" << std::endl;
  // std::cout << "Time remaining: " << time_ << " Time taken: " << time_to_zone << std::endl;
  // std::cout << "Capacity remaining: " << capacity_ << std::endl;
}

double Vehicle::GetTimeTo(const Zone* zone, const Zone* origin) {
  double first_term = pow(zone->GetX() - origin->GetX(), 2);
  double second_term = pow(zone->GetY() - origin->GetY(), 2);
  double distance = sqrt(first_term + second_term);
  double time_to_arrive = distance / speed_;
  double processing_time = zone->GetProcessingTime();
  return time_to_arrive + processing_time;
}

void Vehicle::Print() {
  std::cout << "ID: " << id_ << std::endl;
  std::cout << "Coord X: " << x_coordinate_ << std::endl;
  std::cout << "Coord Y: " << y_coordinate_ << std::endl;
  std::cout << "Capacity: " << capacity_ << std::endl;
  std::cout << "Time Limit: " << time_limit_ << std::endl;
  std::cout << "Speed: " << speed_ << std::endl;
}

void Vehicle::PrintRoute() { 
  route_->Print(); 
}

void Vehicle::Unload(Zone* destination) {
  destination->LoadWaste(total_capacity_ - capacity_);
  capacity_ = total_capacity_;
}
