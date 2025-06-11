// Universidad de La Laguna 
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Diseño y Análisis de Algoritmos
//
// @brief Implementation file for the point class
// @since June 5th, 2025
// @see /docs for documentation
// @see {@link https://github.com/MartinMarrero/DAA-5#}

#include "./lib/collection_vehicle.h"

bool CollectionVehicle::CanAddZone(Zone& zone, double estimated_time) const {
  return zone.GetDemand() <= current_capacity_ && estimated_time <= remaining_time_;
}

void CollectionVehicle::AddZone(Zone& zone, double spent_time) {
  current_capacity_ -= zone.GetDemand();
  AddPoint(zone, spent_time);
}

void CollectionVehicle::EmptyOnSWTS(const SWTS& station, double spent_time) {
  current_capacity_ = max_capacity_;
  AddPoint(station, spent_time);
}

void CollectionVehicle::Reset() {
  current_capacity_ = max_capacity_;
  remaining_time_ = max_time_;
  route_.Clear();
}