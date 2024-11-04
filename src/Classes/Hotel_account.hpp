// Plik: Hotel_account.hpp
// Autor: BŒ
// Data: 04 listopada 2024
// Opis: Definicja klasy Hotel, która przechowuje dane dotycz¹ce hotelu.

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

    /// Dodaje u¿ytkownika do listy kont u¿ytkowników.
    /// @param _user WskaŸnik na obiekt typu User_account, który ma zostaæ dodany do listy kont u¿ytkowników.
    void add_user(const std::shared_ptr<User_account>& _user)
    {
        user_accounts.push_back(_user);
    }

    /// Tworzy nowego u¿ytkownika i dodaje go do listy kont u¿ytkowników.
    /// @param _user_id Unikalny identyfikator u¿ytkownika.
    /// @param _accumulated_cost Skumulowany koszt pobytu u¿ytkownika.
    /// @param _booked_in Czas zameldowania u¿ytkownika.
    /// @param _booked_out Czas wymeldowania u¿ytkownika.
    /// @param _booked_nights Liczba zarezerwowanych nocy przez u¿ytkownika.
    /// @param _user_booked_room_id Identyfikator pokoju zarezerwowanego przez u¿ytkownika.
    /// @param _chosen_services Wektor wybranych us³ug przez u¿ytkownika.
    void add_user(const unsigned int& _user_id, const double& _accumulated_cost, const time_t& _booked_in, const time_t& _booked_out, const unsigned int& _booked_nights, const unsigned int& _user_booked_room_id, const std::vector<Service>& _chosen_services)
    {
        user_accounts.emplace_back(std::make_shared<User_account>(_user_id, _accumulated_cost, _booked_in, _booked_out,
            _booked_nights, _user_booked_room_id, _chosen_services));
    }

    /// Dodaje rezerwacjê pokoju do listy rezerwacji.
    /// @param _room_booking Krotka zawieraj¹ca informacje o pokoju, dacie rozpoczêcia i zakoñczenia rezerwacji.
    void add_booking(const std::tuple<Room, time_t, time_t>& _room_booking)
    {
        room_bookings.push_back(_room_booking);
    }

    /// Tworzy rezerwacjê pokoju i dodaje j¹ do listy rezerwacji.
    /// @param _room Obiekt typu Room reprezentuj¹cy rezerwowany pokój.
    /// @param _booked_from Data rozpoczêcia rezerwacji.
    /// @param _booked_to Data zakoñczenia rezerwacji.
    void add_booking(const Room& _room, const time_t& _booked_from, const time_t& _booked_to)
    {
        room_bookings.emplace_back(_room, _booked_from, _booked_to);
    }

    /// Usuwa rezerwacjê pokoju na podstawie jego identyfikatora.
    /// @param _room_id Identyfikator pokoju, którego rezerwacja ma zostaæ usuniêta.
    /// @throws Wyrzuca wyj¹tek, jeœli rezerwacja dla podanego identyfikatora pokoju nie istnieje.
    void remove_booking(const unsigned int& _room_id)
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

    /// Usuwa u¿ytkownika z listy kont na podstawie jego identyfikatora.
    /// @param _user_id Identyfikator u¿ytkownika, którego konto ma zostaæ usuniête.
    /// @throws Wyrzuca wyj¹tek, jeœli u¿ytkownik o podanym identyfikatorze nie istnieje.
    void remove_user(const unsigned int& _user_id)
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

private:
    std::array<std::shared_ptr<Service>, 5> services;
    std::vector<std::shared_ptr<User_account>> user_accounts;
    std::vector<std::tuple<Room, time_t, time_t>> room_bookings;
};

#endif // HOTEL_ACCOUNT_HPP