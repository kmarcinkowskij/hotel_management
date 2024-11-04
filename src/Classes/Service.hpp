// Plik: Service.hpp
// Autor: BŒ
// Data: 04 listopada 2024
// Opis: Definicja struktury Service, która przechowuje dane dotycz¹ce serwisow dostêpnych w hotelu.

#ifndef SERVICE_HPP
#define SERVICE_HPP

#include <string>

struct Service
{
	// Konstruktor inicjalizuje atrybuty service_id, service_name, service_description oraz service_price podanymi wartoœciami.
	Service(const unsigned int& _service_id, const std::string& _service_name, const std::string& _service_description, const double& _price)
		: service_id(_service_id), service_name(_service_name), service_description(_service_description), price(_price) {}

	unsigned int service_id;
	std::string service_name;
	std::string service_description;
	double price;
};

#endif SERVICE_HPP // SERVICE_HPP