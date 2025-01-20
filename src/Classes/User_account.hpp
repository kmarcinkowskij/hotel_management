//
// Created by Konrad Marcinkowski on 04/11/2024.
//

#ifndef USER_ACCOUNT_HPP
#define USER_ACCOUNT_HPP

#include <ctime>
#include <vector>

#include "Service.hpp"

class User_account {
private:
	unsigned int user_id;
	double accumulated_cost;
	time_t booked_in;
	time_t booked_out;
	unsigned int booked_nights;
	unsigned int user_booked_room_id;
	std::vector<Service> chosen_services;
public:
	// Konstruktor inicjujący konto użytkownika z podanymi wartościami
	User_account(const unsigned int &_user_id, const double &_accumulated_cost, const time_t &_booked_in, const time_t &_booked_out, const unsigned int &_booked_nights,
		const unsigned int &_user_booked_room_id, const std::vector<Service> &_chosen_services)
		: user_id(_user_id),
		  accumulated_cost(_accumulated_cost),
		  booked_in(_booked_in),
		  booked_out(_booked_out),
		  booked_nights(_booked_nights),
		  user_booked_room_id(_user_booked_room_id),
		  chosen_services(_chosen_services) {
	}
	//gettery dla prywatnych zmiennych 
	[[nodiscard]] unsigned int get_user_id() const {
		return user_id;
	}

	[[nodiscard]] double get_accumulated_cost() const {
		return accumulated_cost;
	}

	[[nodiscard]] time_t get_booked_in() const {
		return booked_in;
	}

	[[nodiscard]] time_t get_booked_out() const {
		return booked_out;
	}

	[[nodiscard]] unsigned int get_booked_nights() const {
		return booked_nights;
	}

	[[nodiscard]] unsigned int get_user_booked_room_id() const {
		return user_booked_room_id;
	}

	[[nodiscard]] std::vector<Service> get_chosen_services() const {
		return chosen_services;
	}

	//settery dla prywatnych zmiennych członkowskich
	void set_accumulated_cost(const double &_accumulated_cost) {
		this->accumulated_cost = _accumulated_cost;
	}

	void set_booked_in(const time_t &_booked_in) {
		this->booked_in =_booked_in;
	}

	void set_booked_out(const time_t &_booked_out) {
		this->booked_out = _booked_out;
	}

	void set_booked_nights(const unsigned int &_booked_nights) {
		this->booked_nights = _booked_nights;
	}

	void set_user_booked_room_id(const unsigned int &_user_booked_room_id) {
		this->user_booked_room_id = _user_booked_room_id;
	}

	void set_chosen_services(const std::vector<Service> &_chosen_services) {
		this->chosen_services =_chosen_services;
	}
};

#endif //USER_ACCOUNT_HPP
