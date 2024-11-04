#include "Hotel_account.hpp"

void Hotel_account::add_user(const std::shared_ptr<User_account>& _user)
{
    user_accounts.push_back(_user);
}

void Hotel_account::add_user(const unsigned int& _user_id, const double& _accumulated_cost, const time_t& _booked_in, const time_t& _booked_out, const unsigned int& _booked_nights, const unsigned int& _user_booked_room_id, const std::vector<Service>& _chosen_services)
{
    user_accounts.emplace_back(std::make_shared<User_account>(_user_id, _accumulated_cost, _booked_in, _booked_out, 
        _booked_nights, _user_booked_room_id, _chosen_services));
}

void Hotel_account::add_booking(const std::tuple<Room, time_t, time_t>& _room_booking)
{
    room_bookings.push_back(_room_booking);
}
void Hotel_account::add_booking(const Room& _room, const time_t& _booked_from, const time_t& _booked_to)
{
    room_bookings.emplace_back(_room, _booked_from, _booked_to);
}

void Hotel_account::remove_booking(const unsigned int& _room_id)
{
    auto iter = std::find_if(room_bookings.begin(), room_bookings.end(), [&](const std::tuple<Room, time_t, time_t>& _current) {
        return std::get<0>(_current).room_id == _room_id;
        });

    if (iter == room_bookings.end())
    {
        throw "Room doesn't exist. \n";
    }

    room_bookings.erase(iter);
}

void Hotel_account::remove_user(const unsigned int& _user_id)
{
    auto iter = std::find_if(user_accounts.begin(), user_accounts.end(), [&](const std::shared_ptr<User_account>& _user) {
        return _user->get_user_id() == _user_id;
        });

    if (iter == user_accounts.end())
    {
        throw "User doesn't exist. \n";
        return;
    }

    user_accounts.erase(iter);
}