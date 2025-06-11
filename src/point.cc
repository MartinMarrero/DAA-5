// Universidad de La Laguna 
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Diseño y Análisis de Algoritmos
//
// @brief Implementation file for the point class
// @since June 5th, 2025
// @see /docs for documentation
// @see {@link https://github.com/MartinMarrero/DAA-5#}

#include "./lib/point.h"

double Point::Distance(const Point& point_a, const Point& point_b) {
  return hypot(point_a.x_coordinate_ - point_b.x_coordinate_, point_a.y_coordinate_ - point_b.y_coordinate_);
}
