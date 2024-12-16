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

	/// Wyświetla dostępne pokoje w hotelu.
	/// Funkcja pokazuje listę wszystkich dostępnych pokoi, ich ceny i status dostępności.
	void display_rooms() const;

	/// Wyświetla dostępne usługi oferowane przez hotel.
	/// Funkcja pokazuje listę usług, ich opis oraz cenę.
	void display_services() const;

	/// Wyświetla dostępne udogodnienia oferowane przez hotel.
	/// Funkcja pokazuje listę dostępnych udogodnień, ich opis oraz cenę.
	void display_amenities() const;

	/// Wyświetla dane rezerwacji.
	/// Funkcja pokazuje szczegóły aktualnej rezerwacji, w tym wybrany pokój, usługi oraz udogodnienia.
	void display_booking_data() const;

	/// Wyświetla główne menu aplikacji.
	/// Funkcja umożliwia użytkownikowi wybór dostępnych opcji w aplikacji.
	void display_main_menu();

	/// Wyświetla menu rezerwacji.
	/// Funkcja pozwala użytkownikowi na wybór pokoju, usług i udogodnień podczas rezerwacji.
	void display_booking_menu();

	/// Wybiera pokój na podstawie preferencji użytkownika.
	/// Funkcja umożliwia użytkownikowi wybór pokoju z dostępnej listy na podstawie jego preferencji.
	/// @throws Wyrzuca wyjątek, jeśli nie ma dostępnych pokoi.
	void select_room() const;

	/// Wybiera usługi dla rezerwacji na podstawie preferencji użytkownika.
	/// Funkcja pozwala użytkownikowi na wybór dodatkowych usług do rezerwacji.
	/// @throws Wyrzuca wyjątek, jeśli nie ma dostępnych usług.
	void select_services() const;

	/// Wybiera udogodnienia dla rezerwacji na podstawie preferencji użytkownika.
	/// Funkcja pozwala użytkownikowi na wybór dodatkowych udogodnień do rezerwacji.
	void select_amenities();

	/// Oblicza całkowity koszt rezerwacji na podstawie wybranego pokoju, usług, udogodnień oraz liczby noclegów.
	/// @param room_id Identyfikator wybranego pokoju.
	/// @param chosen_services Lista wybranych usług.
	/// @param chosen_amenities Lista wybranych udogodnień.
	/// @param booked_nights Liczba noclegów.
	/// @return Całkowity koszt rezerwacji.
	[[nodiscard]] double calculate_total_cost(unsigned int room_id, const std::vector<Service>& chosen_services,
		const std::vector<Amenities>& chosen_amenities, int booked_nights) const;

	/// Konwertuje datę w formacie string na czas typu time_t.
	/// @param date Data w formacie string (np. "2024-12-16").
	/// @return Czas w formacie time_t.
	static time_t convert_date_to_time(const std::string& date);

	/// Konwertuje czas typu time_t na datę w formacie string.
	/// @param date Czas w formacie time_t.
	/// @return Data w formacie string (np. "2024-12-16").
	static std::string convert_time_to_date(const time_t& date);

	/// Pobiera listę wybranych usług na podstawie wprowadzonego ciągu znaków.
	/// @param selected_services Ciąg znaków reprezentujący wybrane usługi.
	/// @return Lista wybranych usług.
	[[nodiscard]] std::vector<Service> get_selected_services(const std::string& selected_services) const;

	/// Pobiera listę wybranych udogodnień na podstawie wprowadzonego ciągu znaków.
	/// @param selected_amenities Ciąg znaków reprezentujący wybrane udogodnienia.
	/// @return Lista wybranych udogodnień.
	std::vector<Amenities> get_selected_amenities(const std::string& selected_amenities) const;

	/// Dodaje nowego użytkownika do systemu.
	/// @param new_user Wskaźnik na obiekt użytkownika, który ma zostać dodany.
	void add_new_user(const std::shared_ptr<User_account>& new_user);

	/// Dodaje nową rezerwację do systemu.
	/// @param room_booking Krotka zawierająca identyfikator pokoju, daty początkową i końcową rezerwacji.
	void add_new_booking(std::tuple<unsigned int, time_t, time_t> room_booking);

	/// Uruchamia aplikację.
	/// Funkcja inicjuje interakcję użytkownika z aplikacją, w tym menu rezerwacji.
	void run();

	/// Zapisuje bieżącą rezerwację w systemie.
	/// Funkcja zapisuje szczegóły aktualnej rezerwacji, w tym dane pokoju, usług i udogodnień.
	void save_current_booking();
};

#endif //APP_HPP
