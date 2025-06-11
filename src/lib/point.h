// Universidad de La Laguna 
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Diseño y Análisis de Algoritmos
//
// @brief Header file for the point class
// @since June 5th, 2025
// @see /docs for documentation
// @see {@link https://github.com/MartinMarrero/DAA-5#}

#include <string>
#include <cmath>

class Point {
 public:
  Point(int x_coordinate, int y_coordinate, std::string id) : id_(id), x_coordinate_(x_coordinate), y_coordinate_(y_coordinate) {}
  int GetXCoordinate() { return x_coordinate_; }
  int GetYCoordinate() { return y_coordinate_; }
  std::string GetID()  { return id_;           }
  static double Distance(const Point& point_a, const Point& point_b);
 private:
  int x_coordinate_;
  int y_coordinate_;
  std::string id_;
};