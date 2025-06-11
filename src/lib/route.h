// Universidad de La Laguna 
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Diseño y Análisis de Algoritmos
//
// @brief Header file for the route class
// @since June 5th, 2025
// @see /docs for documentation
// @see {@link https://github.com/MartinMarrero/DAA-5#}

#include "point.h"
#include <vector>

class Route {
 private:
  double load = 0;
  double time = 0;
  std::vector<Point> nodes_;
 public:
  Route() = default;
  const std::vector<Point>& GetNodes() const { return nodes_; }
  double GetLoad() const                     { return load; }
  double GetTime() const                     { return time; }
  void SetLoad(double new_load) { load = new_load; }
  void SetTime(double new_time) { time = new_time; }
  void AddPoint(const Point& point) { nodes_.push_back(point); }
  void Clear() { nodes_.clear(); load = 0; time = 0; }
};