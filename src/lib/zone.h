// Universidad de La Laguna 
// Escuela Superior de Ingeniería y Tecnología
// Grado en Ingeniería Informática
// Diseño y Análisis de Algoritmos
//
// @brief Header file for the zone class
// @since June 5th, 2025
// @see /docs for documentation
// @see {@link https://github.com/MartinMarrero/DAA-5#}

#include <iostream>
#include <vector>
#include <cmath>
#include <limits>
#include <algorithm>
#include "point.h"

class Zone {
 public:
    Zone(int zone_id, double x_coordinate, double y_coordinate)
        : id_(zone_id), x_coordinate_(x_coordinate), y_coordinate_(y_coordinate) {}
    virtual ~Zone() {}
    int GetZoneId() const { return id_; }
    void SetZoneId(int zone_id) { id_ = zone_id; }
    double GetXCoordinate() const { return x_coordinate_; }
    double GetYCoordinate() const { return y_coordinate_; }
    virtual double GetDemand() const { return 0; }
    virtual double GetProcessingTime() const { return 0; }
    virtual void LoadWaste(double waste_amount) {}
    virtual void Print() {
        std::cout << "Zone ID: " << id_ << std::endl;
        std::cout << "X Coordinate: " << x_coordinate_ << std::endl;
        std::cout << "Y Coordinate: " << y_coordinate_ << std::endl;
    }
 protected:
    int id_;
    double x_coordinate_;
    double y_coordinate_;
};