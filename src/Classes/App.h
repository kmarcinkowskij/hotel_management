//
// Created by Konrad Marcinkowski on 13/12/2024.
//

#ifndef APP_H
#define APP_H
#include <iomanip>
#include <memory>
#include <sstream>

#include "Amenities.hpp"
#include "Hotel_account.hpp"

class App {
private:
    std::vector<Room> available_rooms;
    std::vector<Service> available_services;
    std::vector<Amenities> available_amenities;
    Hotel_account hotel_account;

    unsigned int current_user_id;
    std::shared_ptr<User_account> new_user;
    std::vector<Amenities> chosen_amenities;

public:
    App() {
        current_user_id = 0;
        new_user = std::make_shared<User_account>(current_user_id, 0.0, 0, 0, 0, -1, std::vector<Service>());

        available_rooms = {
            {0, true, 100.0},
            {1, true, 200.0},
            {2, true, 300.0},
            {3, true, 400.0},
            {4, true, 500.0},
            {5, true, 600.0},
        };

        available_services = {
            {0, "posilki", "Sniadania, obiad, kolacja, w hotelowej restauracji.", 30.00},
            {1, "sprzatanie", "Sprzatanie pokoju pod nieobecnosc.", 20.00},
            {2, "serwis", "Poscielenie lozka, wymiana recznikow.", 10.00},
            {3, "transport", "transport na zlecnie.", 50.00},
            {4, "pranie", "Chemiczne czysczenie odziezy.", 40.00},
        };

        available_amenities = {
            {0, "basen", "dostep do basenu hotelowego.", 70.00},
            {1, "spa", "dostep do spa hotelowego.", 80.00},
            {2, "silownia", "dostep do silowni hotelowej.", 50.00},
            {3, "wi-fi", "dostep do wifi w hotelu.", 20.00},
            {4, "parking", "dostep do parkingu strzezonego.", 70.00},
        };
    }

    void display_rooms() const;

    void display_services() const;

    void display_amenities() const;

    void display_booking_data() const;

    void display_main_menu();

    void display_booking_menu();

    void select_room() const;

    void select_services() const;

    void select_amenities();

    [[nodiscard]] double calculate_total_cost(unsigned int room_id, const std::vector<Service> &chosen_services,const std::vector<Amenities> &chosen_amenities, int booked_nights) const;

    static time_t convert_date_to_time(const std::string& date);

    static std::string convert_time_to_date(const time_t& date);

    [[nodiscard]] std::vector<Service> get_selected_services(const std::string& selected_services) const;

    std::vector<Amenities> get_selected_amenities(const std::string& selected_amenities) const;

    void add_new_user(const std::shared_ptr<User_account> &new_user);

    void add_new_booking(std::tuple<unsigned int, time_t, time_t> room_booking);

    void run();

    void save_current_booking();
};

#endif //APP_H
