//
// Created by Łukasz Stępień on 04/11/2024.
//

#ifndef AMENITIES_HPP
#define AMENITIES_HPP

#include <iostream>
#include <string>

struct Amenities {
  unsigned int amenity_id;
  std::string amenity_name;
  std::string amenity_description;
  double amenity_price;

  Amenities(unsigned int id, const std::string& name, const std::string& description, double price)
  : amenity_id(id), amenity_name(name), amenity_description(description), amenity_price(price) {}

};



#endif //AMENITIES_HPP
