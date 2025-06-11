// Universidad de La Laguna 
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Diseño y Análisis de Algoritmos
//
// @brief Header file for the problem data class. This class mainly acts as a container for the problem's information
// @since June 5th, 2025
// @see /docs for documentation
// @see {@link https://github.com/MartinMarrero/DAA-5#}

#include <vector>
#include "point.h"
#include "zone.h"

class ProblemData {
 private:
  std::vector<Zone> zones_;
  std::vector<SWTS> swts_;
  Point deposit_;
  Point dump_;
  double capacity_CV_;
  double max_time_CV_;
  double capacity_TV_;
  double max_time_TV_;
 public:
  ProblemData(
    const std::vector<Zone>& zones,
    const std::vector<SWTS>& swts,
    const Point& deposit,
    const Point& dump)
      : zones_(zones),
      swts_(swts),
      deposit_(deposit),
      dump_(dump) {}
      
  const std::vector<Zone>& getZones() const { return zones_; }
  const std::vector<SWTS>& getSWTS() const  { return swts_; }
  std::vector<Zone>& getZonesMutable()      { return zones_; }
  const Point& getVertedero() const         { return dump_; }
  const Point& getDeposito() const          { return deposit_; }
};