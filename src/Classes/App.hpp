//
// Created by Konrad Marcinkowski on 13/12/2024.
//

#ifndef APP_HPP
#define APP_HPP
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

    /// Wy�wietla dost�pne pokoje w hotelu.
    /// Funkcja pokazuje list� wszystkich dost�pnych pokoi, ich ceny i status dost�pno�ci.
    void display_rooms() const;

    /// Wy�wietla dost�pne us�ugi oferowane przez hotel.
    /// Funkcja pokazuje list� us�ug, ich opis oraz cen�.
    void display_services() const;

    /// Wy�wietla dost�pne udogodnienia oferowane przez hotel.
    /// Funkcja pokazuje list� dost�pnych udogodnie�, ich opis oraz cen�.
    void display_amenities() const;

    /// Wy�wietla dane rezerwacji.
    /// Funkcja pokazuje szczeg�y aktualnej rezerwacji, w tym wybrany pok�j, us�ugi oraz udogodnienia.
    void display_booking_data() const;

    /// Wy�wietla g��wne menu aplikacji.
    /// Funkcja umo�liwia u�ytkownikowi wyb�r dost�pnych opcji w aplikacji.
    void display_main_menu();

    /// Wy�wietla menu rezerwacji.
    /// Funkcja pozwala u�ytkownikowi na wyb�r pokoju, us�ug i udogodnie� podczas rezerwacji.
    void display_booking_menu();

    /// Wybiera pok�j na podstawie preferencji u�ytkownika.
    /// Funkcja umo�liwia u�ytkownikowi wyb�r pokoju z dost�pnej listy na podstawie jego preferencji.
    /// @throws Wyrzuca wyj�tek, je�li nie ma dost�pnych pokoi.
    void select_room() const;

    /// Wybiera us�ugi dla rezerwacji na podstawie preferencji u�ytkownika.
    /// Funkcja pozwala u�ytkownikowi na wyb�r dodatkowych us�ug do rezerwacji.
    /// @throws Wyrzuca wyj�tek, je�li nie ma dost�pnych us�ug.
    void select_services() const;

    /// Wybiera udogodnienia dla rezerwacji na podstawie preferencji u�ytkownika.
    /// Funkcja pozwala u�ytkownikowi na wyb�r dodatkowych udogodnie� do rezerwacji.
    void select_amenities();

    /// Oblicza ca�kowity koszt rezerwacji na podstawie wybranego pokoju, us�ug, udogodnie� oraz liczby nocleg�w.
    /// @param room_id Identyfikator wybranego pokoju.
    /// @param chosen_services Lista wybranych us�ug.
    /// @param chosen_amenities Lista wybranych udogodnie�.
    /// @param booked_nights Liczba nocleg�w.
    /// @return Ca�kowity koszt rezerwacji.
    [[nodiscard]] double calculate_total_cost(unsigned int room_id, const std::vector<Service>& chosen_services,
        const std::vector<Amenities>& chosen_amenities, int booked_nights) const;

    /// Konwertuje dat� w formacie string na czas typu time_t.
    /// @param date Data w formacie string (np. "2024-12-16").
    /// @return Czas w formacie time_t.
    static time_t convert_date_to_time(const std::string& date);

    /// Konwertuje czas typu time_t na dat� w formacie string.
    /// @param date Czas w formacie time_t.
    /// @return Data w formacie string (np. "2024-12-16").
    static std::string convert_time_to_date(const time_t& date);

    /// Pobiera list� wybranych us�ug na podstawie wprowadzonego ci�gu znak�w.
    /// @param selected_services Ci�g znak�w reprezentuj�cy wybrane us�ugi.
    /// @return Lista wybranych us�ug.
    [[nodiscard]] std::vector<Service> get_selected_services(const std::string& selected_services) const;

    /// Pobiera list� wybranych udogodnie� na podstawie wprowadzonego ci�gu znak�w.
    /// @param selected_amenities Ci�g znak�w reprezentuj�cy wybrane udogodnienia.
    /// @return Lista wybranych udogodnie�.
    std::vector<Amenities> get_selected_amenities(const std::string& selected_amenities) const;

    /// Dodaje nowego u�ytkownika do systemu.
    /// @param new_user Wska�nik na obiekt u�ytkownika, kt�ry ma zosta� dodany.
    void add_new_user(const std::shared_ptr<User_account>& new_user);

    /// Dodaje now� rezerwacj� do systemu.
    /// @param room_booking Krotka zawieraj�ca identyfikator pokoju, daty pocz�tkow� i ko�cow� rezerwacji.
    void add_new_booking(std::tuple<unsigned int, time_t, time_t> room_booking);

    /// Uruchamia aplikacj�.
    /// Funkcja inicjuje interakcj� u�ytkownika z aplikacj�, w tym menu rezerwacji.
    void run();

    /// Zapisuje bie��c� rezerwacj� w systemie.
    /// Funkcja zapisuje szczeg�y aktualnej rezerwacji, w tym dane pokoju, us�ug i udogodnie�.
    void save_current_booking();
};

#endif //APP_HPP
