// Plik: main.cpp
// Autor: Antoni Maciejewski 4E
// Data: 12 grudnia 2024
// Opis: Zawiera glowna petle aplikacji i laczy ze soba pozostale pliki.


#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

#include "Classes/User_account.hpp"
#include "Classes/Service.hpp"
#include "Classes/Hotel_account.hpp"
#include "Classes/Amenities.hpp"

using namespace std;

class App {
private:
    vector<Room> available_rooms;
    vector<Service> available_services;
    vector<Amenities> available_amenities;
    Hotel_account hotel_account;

    unsigned int current_user_id;
    shared_ptr<User_account> new_user;
    vector<Amenities> chosen_amenities;

public:
    App() {
        current_user_id = 0;
        new_user = make_shared<User_account>(current_user_id, 0.0, 0, 0, 0, -1, vector<Service>());

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

    void display_rooms() {
        cout << "Oto lista dostepnych pokoi: \n";
        for (Room room : available_rooms) {
            cout << "Numer pokoju: " << room.room_id << ", Wolny: " << ((room.is_vacant) ? "Tak" : "Nie") << ", Cena za noc: " << room.room_cost << "zl" << endl;
        }
    }

    void display_services() {
        cout << "Oto lista dostepnych uslug: " << endl;
        for (Service service : available_services) {
            cout << "Nr. " << service.service_id << ", " << service.service_name << " - " << service.service_description << " : " << service.price << endl;
        }
    }

    void display_amenities() {
        cout << "Oto lista dostepnych udogodnien: " << endl;
        for (Amenities amenity : available_amenities) {
            cout << "Nr. " << amenity.amenity_id << ", " << amenity.amenity_name << " - " << amenity.amenity_description << " : " << amenity.amenity_price << endl;
        }
    }

    void display_booking_data() {
        cout << "--- Dane ---" << endl;
        cout << "Pokoj nr: " << new_user->get_user_booked_room_id() << endl;
        cout << "Rezerwacja od: " << ((new_user->get_booked_in() != 0) ? convert_time_to_date(new_user->get_booked_in()) : "brak" )
        << " do " << ((new_user->get_booked_out() != 0) ? convert_time_to_date(new_user->get_booked_out()) : "brak") << endl;
        cout << "Liczba nocy: " << new_user->get_booked_nights() << endl;
        cout << "Wybrane uslugi: ";
        for (Service service : new_user->get_chosen_services()) {
            cout << service.service_name << ", ";
        }
        cout << endl;
        cout << "Wybrane udogodnienia: ";
        for (Amenities amenity : chosen_amenities) {
            cout << amenity.amenity_name << ", ";
        }
        cout << endl << endl;

        char answer = 'n';
        cout << "Kontynuowac (t): ";
        cin >> answer;
    }

    void display_main_menu() {
        cout << "--- Menu ---" << endl;
        cout << "1. Zarezerwuj pokoj" << endl;
        cout << "2. Wyjdz" << endl;

        int answer = 0;
        cout << "Co chcesz zrobic: ";
        cin >> answer;

        switch(answer) {
        case 1:
            system("cls");
            select_room();
            display_booking_menu();
        break;
        case 2:
            exit(0);
        break;
        }

    }

    void display_booking_menu() {
        int answer = 0;

        do {
            cout << "--- Booking ---" << endl;
            cout << "1. " << "Zmien pokoj" << endl;
            cout << "2. " << ((new_user->get_chosen_services().size() <= 0) ? "Wybierz" : "Zmien") << " uslugi" << endl;
            cout << "3. " << ((chosen_amenities.size() <= 0) ? "Wybierz" : "Zmien") << " dodatki" << endl;
            cout << "4. Pokaz dane rezerwacji" << endl;
            if (new_user->get_user_booked_room_id() != -1) cout << "5. Zakoncz rezerwacje" << endl;

            cout << "Co chcesz zrobic: ";
            cin >> answer;

            system("cls");

            switch(answer) {
            case 1:
                select_room();
            break;
            case 2:
                select_services();
            break;
            case 3:
                select_amenities();
            break;
            case 4:
                display_booking_data();
            break;
            case 5:
                save_current_booking();
            break;
            }
            system("cls");
        }while(answer != 5);

        cout << "Calkowity koszt pobytu: " << calculate_total_cost(new_user->get_user_booked_room_id(), new_user->get_chosen_services(), chosen_amenities, new_user->get_booked_nights()) << "zl" << endl;
    }

    void select_room() {
        int selected_room = -1;
        do{
            system("cls");
            display_rooms();

            if (selected_room != -1) {
                    if (available_rooms[selected_room].is_vacant != true) cout << "Wybrany pokoj jest zajety." << endl;
            }

            cout << "Wybierz numer pokoju: ";
            cin >> selected_room;
            new_user->set_user_booked_room_id(selected_room);

        }while(available_rooms[selected_room].is_vacant != true);

        string booked_from = "";
        time_t date_converted_to_time = -1;

        do {
            cout << "Na kiedy zarezerwowac (YYYY-MM-DD): ";
            cin >> booked_from;

            try {
                date_converted_to_time = convert_date_to_time(booked_from);
            } catch (const std::invalid_argument& e) {
                cout << "Podano date w zlym formacie." << endl; 
            }

        }while(converted_to_time == -1);

        new_user->set_booked_in(date_converted_to_time);

        int nights_count = 0;
        cout << "Na ile dni: ";
        cin >> nights_count;
        new_user->set_booked_nights(nights_count);
        new_user->set_booked_out(new_user->get_booked_in() + nights_count * 864000);

        system("cls");
    }

    void select_services() {
        string selected_services;

        display_services();
        cout << "Wybierz numery uslug (oddzielone przecinkiem): ";
        cin >> selected_services;
        new_user->set_chosen_services(get_selected_services(selected_services));

        system("cls");
    }

    void select_amenities() {
        string selected_amenities;

        display_amenities();
        cout << "Wybierz numery udogodnien (oddzielone przecinkiem): ";
        cin >> selected_amenities;
        chosen_amenities = get_selected_amenities(selected_amenities);

        system("cls");
    }

    double calculate_total_cost(unsigned int room_id, vector<Service> chosen_services, vector<Amenities> chosen_amenities, int booked_nights) {
        double total_cost = 0.0;
        total_cost += available_rooms[room_id].room_cost;
        for (Service service : chosen_services) {
            total_cost += service.price;
        }
        for (Amenities amenity : chosen_amenities) {
            total_cost += amenity.amenity_price * booked_nights;
        }

        return total_cost;
    }

    time_t convert_date_to_time(const std::string& date) {
        std::tm tm = {};
        std::istringstream ss(date);

        ss >> std::get_time(&tm, "%Y-%m-%d");
        if (ss.fail()) {
            throw std::invalid_argument("Podano nieprawidlowy format. Oczekiwano: YYYY-MM-DD.");
        }

        tm.tm_hour = 0;
        tm.tm_min = 0;
        tm.tm_sec = 0;

        return std::mktime(&tm);
    }

    string convert_time_to_date(const time_t& date) {
        std:tm* tm = std::localtime(&date);

        std::ostringstream oss;
        oss << std::put_time(tm, "%Y-%m-%d");

        return oss.str();
    }

    vector<Service> get_selected_services(const string& selected_services) {
        vector<Service> chosen_services;
        stringstream ss(selected_services);
        string service_id;

        while (getline(ss, service_id, ',')) {
            int id = stoi(service_id);
            if (id >= 0 && id < available_services.size()) {
                chosen_services.push_back(available_services[id]);
            }
        }

        return chosen_services;
    }

    vector<Amenities> get_selected_amenities(const string& selected_amenities) {
        vector<Amenities> chosen_amenities;
        stringstream ss(selected_amenities);
        string amenity_id;

        while (getline(ss, amenity_id, ',')) {
            int id = stoi(amenity_id);
            if (id >= 0 && id < available_amenities.size()) {
                chosen_amenities.push_back(available_amenities[id]);
            }
        }

        return chosen_amenities;
    }

    void add_new_user(shared_ptr<User_account> new_user) {
        this->hotel_account.add_user(new_user);
    }

    void add_new_booking(tuple<unsigned int, time_t, time_t> room_booking) {
        this->hotel_account.add_booking(room_booking);
    }

    void run() {
        cout << "Witaj w naszym hotelu uzytkowniku!\n\n";

        char answer = 'n';
        do{
            display_main_menu();

            cout << "\nWrocic do menu (t/n): ";
            cin >> answer;
            if (answer == 't') {
              current_user_id += 1;
              new_user = make_shared<User_account>(current_user_id, 0.0, 0, 0, 0, -1, vector<Service>());
            }
            system("cls");
        }while(answer == 't');
    }

    void save_current_booking() {
        double accumulated_cost = calculate_total_cost(new_user->get_user_booked_room_id(), new_user->get_chosen_services(), chosen_amenities, new_user->get_booked_nights());
        new_user->set_accumulated_cost(accumulated_cost);
        add_new_user(new_user);
        add_new_booking(tuple<unsigned int, time_t, time_t> (new_user->get_user_booked_room_id(), new_user->get_booked_in(), new_user->get_booked_out()));
        available_rooms[new_user->get_user_booked_room_id()].is_vacant = false;
    }
};

int main()
{
    App app;
    app.run();

    return 0;
}
