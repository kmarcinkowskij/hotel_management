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

    /// Wyœwietla dostêpne pokoje w hotelu.
    /// Funkcja pokazuje listê wszystkich dostêpnych pokoi, ich ceny i status dostêpnoœci.
    void display_rooms() const;

    /// Wyœwietla dostêpne us³ugi oferowane przez hotel.
    /// Funkcja pokazuje listê us³ug, ich opis oraz cenê.
    void display_services() const;

    /// Wyœwietla dostêpne udogodnienia oferowane przez hotel.
    /// Funkcja pokazuje listê dostêpnych udogodnieñ, ich opis oraz cenê.
    void display_amenities() const;

    /// Wyœwietla dane rezerwacji.
    /// Funkcja pokazuje szczegó³y aktualnej rezerwacji, w tym wybrany pokój, us³ugi oraz udogodnienia.
    void display_booking_data() const;

    /// Wyœwietla g³ówne menu aplikacji.
    /// Funkcja umo¿liwia u¿ytkownikowi wybór dostêpnych opcji w aplikacji.
    void display_main_menu();

    /// Wyœwietla menu rezerwacji.
    /// Funkcja pozwala u¿ytkownikowi na wybór pokoju, us³ug i udogodnieñ podczas rezerwacji.
    void display_booking_menu();

    /// Wybiera pokój na podstawie preferencji u¿ytkownika.
    /// Funkcja umo¿liwia u¿ytkownikowi wybór pokoju z dostêpnej listy na podstawie jego preferencji.
    /// @throws Wyrzuca wyj¹tek, jeœli nie ma dostêpnych pokoi.
    void select_room() const;

    /// Wybiera us³ugi dla rezerwacji na podstawie preferencji u¿ytkownika.
    /// Funkcja pozwala u¿ytkownikowi na wybór dodatkowych us³ug do rezerwacji.
    /// @throws Wyrzuca wyj¹tek, jeœli nie ma dostêpnych us³ug.
    void select_services() const;

    /// Wybiera udogodnienia dla rezerwacji na podstawie preferencji u¿ytkownika.
    /// Funkcja pozwala u¿ytkownikowi na wybór dodatkowych udogodnieñ do rezerwacji.
    void select_amenities();

    /// Oblicza ca³kowity koszt rezerwacji na podstawie wybranego pokoju, us³ug, udogodnieñ oraz liczby noclegów.
    /// @param room_id Identyfikator wybranego pokoju.
    /// @param chosen_services Lista wybranych us³ug.
    /// @param chosen_amenities Lista wybranych udogodnieñ.
    /// @param booked_nights Liczba noclegów.
    /// @return Ca³kowity koszt rezerwacji.
    [[nodiscard]] double calculate_total_cost(unsigned int room_id, const std::vector<Service>& chosen_services,
        const std::vector<Amenities>& chosen_amenities, int booked_nights) const;

    /// Konwertuje datê w formacie string na czas typu time_t.
    /// @param date Data w formacie string (np. "2024-12-16").
    /// @return Czas w formacie time_t.
    static time_t convert_date_to_time(const std::string& date);

    /// Konwertuje czas typu time_t na datê w formacie string.
    /// @param date Czas w formacie time_t.
    /// @return Data w formacie string (np. "2024-12-16").
    static std::string convert_time_to_date(const time_t& date);

    /// Pobiera listê wybranych us³ug na podstawie wprowadzonego ci¹gu znaków.
    /// @param selected_services Ci¹g znaków reprezentuj¹cy wybrane us³ugi.
    /// @return Lista wybranych us³ug.
    [[nodiscard]] std::vector<Service> get_selected_services(const std::string& selected_services) const;

    /// Pobiera listê wybranych udogodnieñ na podstawie wprowadzonego ci¹gu znaków.
    /// @param selected_amenities Ci¹g znaków reprezentuj¹cy wybrane udogodnienia.
    /// @return Lista wybranych udogodnieñ.
    std::vector<Amenities> get_selected_amenities(const std::string& selected_amenities) const;

    /// Dodaje nowego u¿ytkownika do systemu.
    /// @param new_user WskaŸnik na obiekt u¿ytkownika, który ma zostaæ dodany.
    void add_new_user(const std::shared_ptr<User_account>& new_user);

    /// Dodaje now¹ rezerwacjê do systemu.
    /// @param room_booking Krotka zawieraj¹ca identyfikator pokoju, daty pocz¹tkow¹ i koñcow¹ rezerwacji.
    void add_new_booking(std::tuple<unsigned int, time_t, time_t> room_booking);

    /// Uruchamia aplikacjê.
    /// Funkcja inicjuje interakcjê u¿ytkownika z aplikacj¹, w tym menu rezerwacji.
    void run();

    /// Zapisuje bie¿¹c¹ rezerwacjê w systemie.
    /// Funkcja zapisuje szczegó³y aktualnej rezerwacji, w tym dane pokoju, us³ug i udogodnieñ.
    void save_current_booking();
};

#endif //APP_HPP
