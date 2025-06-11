// Universidad de La Laguna 
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Diseño y Análisis de Algoritmos
//
// @brief Header file for the vehicle base class. This class serves as a base for different types of vehicles in the problem domain.
// @since June 5th, 2025
// @see /docs for documentation
// @see {@link https://github.com/MartinMarrero/DAA-5#}

#ifndef VEHICLE_H
#define VEHICLE_H

#include "route.h"
#include "zone.h"
#include "task.h"
#include "map.h"

class Vehicle {
 public:
  Vehicle(int id, double coord_x, double coord_y, double capacity, double time_limit, double speed)
      : id_(id),
        x_coordinate_(coord_x),
        y_coordinate_(coord_y),
        capacity_(capacity),
        total_capacity_(capacity),
        max_time_(time_limit),
        time_(time_limit),
        speed_(speed),
        route_(nullptr) {}

  Vehicle(Vehicle* vehicle)
      : id_(vehicle->id_),
        x_coordinate_(vehicle->x_coordinate_),
        y_coordinate_(vehicle->y_coordinate_),
        capacity_(vehicle->capacity_),
        total_capacity_(vehicle->total_capacity_),
        max_time_(vehicle->max_time_),
        time_(vehicle->time_),
        speed_(vehicle->speed_),
        route_(vehicle->route_) {}

  virtual ~Vehicle() {}

  int GetId() const              { return id_; }
  double GetRemainingTime()      { return time_; }
  Route* GetRoute() const        { return route_; }
  double GetX() const            { return x_coordinate_; }
  double GetY() const            { return y_coordinate_; }
  double GetRemainingCapacity()  { return capacity_; }
  double GetTotalCapacity()      { return total_capacity_; }
  double GetInstant() const      { return max_time_ - time_; }
  double GetSpeed() const        { return speed_; }
  double GetTimeLimit() const    { return max_time_; }
  bool Loaded() const            { return capacity_ < total_capacity_; }
  bool IsAt(const Zone* zone)    { return x_coordinate_ == zone->GetX() && y_coordinate_ == zone->GetY(); }
  void ClearRoute()              { if(route_) route_->Clear(); }
  void InsertToRoute(Zone* zone, double time_to_zone);
  void SetRoute(Route* route)    { route_ = route; }
  void TravelTo(Zone* zone);
  double GetTimeTo(const Zone* zone, const Zone* origin);

  virtual void Print();
  virtual void PrintRoute();
  virtual void AddTask(Task* task, Map* map) {}
  virtual bool CanInsertTask(Task* task, Map* map, double& min_insertion_cost) { return false; }
  virtual void Load(double demand) { capacity_ -= demand; }
  virtual bool NeedsToUnload() { return capacity_ < threshold_; }
  virtual void Unload(Zone* destination);

 protected:
  int id_;
  double x_coordinate_;
  double y_coordinate_;
  double capacity_;
  double total_capacity_;
  double max_time_;
  double time_;
  double speed_;
  Route* route_;
  double threshold_ = 100;
};

#endif // VEHICLE_H