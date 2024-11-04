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
    double accumulated_cost;
    time_t booked_in;
    time_t booked_out;
    unsigned int booked_nights;
    unsigned int user_booked_room_id;
    std::vector<Service> chosen_services;
public:
    User_account(const double &_accumulated_cost, const time_t &_booked_in, const time_t &_booked_out, const unsigned int &_booked_nights,
        const unsigned int &_user_booked_room_id, const std::vector<Service> &_chosen_services)
        : accumulated_cost(_accumulated_cost),
          booked_in(_booked_in),
          booked_out(_booked_out),
          booked_nights(_booked_nights),
          user_booked_room_id(_user_booked_room_id),
          chosen_services(_chosen_services) {
    }


};



#endif //USER_ACCOUNT_HPP
