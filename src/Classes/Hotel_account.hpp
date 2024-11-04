#ifndef HOTEL_ACCOUNT_HPP
#define HOTEL_ACCOUNT_HPP

#include "Service.hpp"
#include "User_account.hpp"

#include <array>
#include <ctime>
#include <tuple>
#include <memory>
#include <vector>

struct Room {
    Room(const unsigned int& _room_id, const bool& _is_vacant = true, const double& _room_cost = 0.0) : room_id(_room_id), is_vacant(_is_vacant), room_cost(_room_cost) {}

    unsigned int room_id;
    bool is_vacant;
    double room_cost;
};

class Hotel_account {
public:
    Hotel_account() 
    {
        services[0] = std::make_shared<Service>(1, "Lorem", "Impsum1", 1.0);
        services[1] = std::make_shared<Service>(2, "Lorem", "Impsum2", 2.0);
        services[2] = std::make_shared<Service>(3, "Lorem", "Impsum3", 3.0);
        services[3] = std::make_shared<Service>(4, "Lorem", "Impsum4", 4.0);
        services[4] = std::make_shared<Service>(5, "Lorem", "Impsum5", 5.0);
    }

    void add_user(const std::shared_ptr<User_account>& _user);
    void add_user(const unsigned int& _user_id, const double& _accumulated_cost, const time_t& _booked_in, const time_t& _booked_out, const unsigned int& _booked_nights, const unsigned int& _user_booked_room_id, const std::vector<Service>& _chosen_services);

    void add_booking(const std::tuple<Room, time_t, time_t>& _room_booking);
    void add_booking(const Room& _room, const time_t& _booked_from, const time_t& _booked_to);

    void remove_booking(const unsigned int& _room_id);
    void remove_user(const unsigned int& _user_id);
private:
    std::array<std::shared_ptr<Service>, 5> services;
    std::vector<std::shared_ptr<User_account>> user_accounts;
    std::vector<std::tuple<Room, time_t, time_t>> room_bookings;
};

#endif //HOTEL_ACCOUNT_HPP
