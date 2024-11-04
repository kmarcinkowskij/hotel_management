// Plik: Amenities.hpp
// Autor: Łukasz Stępień
// Data: 04 listopada 2024
// Opis: Definicja struktury Amenities, która przechowuje dane dotyczące udogodnień dostępnych w hotelu.

#ifndef AMENITIES_HPP
#define AMENITIES_HPP

#include <iostream>
#include <string>

struct Amenities {
  unsigned int amenity_id;
  std::string amenity_name;
  std::string amenity_description;
  double amenity_price;

  // Konstruktor inicjalizuje atrybuty amenity_id, amenity_name, amenity_description oraz amenity_price podanymi wartościami.
  Amenities(unsigned int id, const std::string& name, const std::string& description, double price)
  : amenity_id(id), amenity_name(name), amenity_description(description), amenity_price(price) {}
};

#endif //AMENITIES_HPP