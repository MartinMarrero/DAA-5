// Universidad de La Laguna 
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Diseño y Análisis de Algoritmos
//
// @brief Header file for the vehicle base class. This class serves as a base for different types of vehicles in the problem domain.
// @since June 5th, 2025
// @see /docs for documentation
// @see {@link https://github.com/MartinMarrero/DAA-5#}

#ifndef COLLECTION_VEHICLE_H
#define COLLECTION_VEHICLE_H

#include "vehicle.h"
#include "zone.h"

class CollectionVehicle : public Vehicle {
 public:
  CollectionVehicle(int id, double max_capacity, double max_time) : Vehicle(id, max_capacity, max_time) {}
  bool CanAddZone(Zone& zone, double estimated_time) const;
  void AddZone(Zone& zone, double spent_time);
  void EmptyOnSWTS(const SWTS& station, double spent_time);
  void Reset() override;
};

#endif // COLLECTION_VEHICLE_H