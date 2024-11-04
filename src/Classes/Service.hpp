#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <string>

struct Service
{
	Service(unsigned int _amenity_id, const std::string& _amenity_name, const std::string& _amenity_description, const double& _price)
		: amenity_id(_amenity_id), amenity_name(_amenity_name), amenity_description(_amenity_description), price(_price) {}

	unsigned int amenity_id;
	std::string amenity_name;
	std::string amenity_description;
	double price;
};

#endif SERVICE_HPP // SERVICE_HPP