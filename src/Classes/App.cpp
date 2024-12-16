//
// Created by Konrad Marcinkowski on 13/12/2024.
//

#include "App.h"

void App::display_rooms() const
{
    std::cout << "Oto lista dostepnych pokoi: \n";
    for (const Room &room : available_rooms) {
        std::cout << "Numer pokoju: " << room.room_id << ", Wolny: " << ((room.is_vacant) ? "Tak" : "Nie") << ", Cena za noc: " << room.room_cost << "zl" << "\n";
    }
}

void App::display_services() const
{
    std::cout << "Oto lista dostepnych uslug: " << "\n";
    for (const Service &service : available_services) {
        std::cout << "Nr. " << service.service_id << ", " << service.service_name << " - " << service.service_description << " : " << service.price << "\n";
    }
}

void App::display_amenities() const
{
    std::cout << "Oto lista dostepnych udogodnien: " << "\n";
    for (const Amenities &amenity : available_amenities) {
        std::cout << "Nr. " << amenity.amenity_id << ", " << amenity.amenity_name << " - " << amenity.amenity_description << " : " << amenity.amenity_price << "\n";
    }
}

void App::display_booking_data() const
{
    std::cout << "--- Dane ---" << "\n";
    std::cout << "Pokoj nr: " << new_user->get_user_booked_room_id() << "\n";
    std::cout << "Rezerwacja od: " << ((new_user->get_booked_in() != 0) ? convert_time_to_date(new_user->get_booked_in()) : "brak" )
    << " do " << ((new_user->get_booked_out() != 0) ? convert_time_to_date(new_user->get_booked_out()) : "brak") << "\n";
    std::cout << "Liczba nocy: " << new_user->get_booked_nights() << "\n";
    std::cout << "Wybrane uslugi: ";
    for (const Service &service : new_user->get_chosen_services()) {
        std::cout << service.service_name << ", ";
    }
    
    std::cout << "\n";
    std::cout << "Wybrane udogodnienia: ";
    
    for (const Amenities &amenity : chosen_amenities) {
        std::cout << amenity.amenity_name << ", ";
    }
    
    std::cout << "\n" << "\n";

    char answer = 'n';
    std::cout << "Kontynuowac (t): ";
    std::cin >> answer;
}

void App::display_main_menu()
{
    std::cout << "--- Menu ---" << "\n";
    std::cout << "1. Zarezerwuj pokoj" << "\n";
    std::cout << "2. Wyjdz" << "\n";

    int answer = 0;
    std::cout << "Co chcesz zrobic: ";
    std::cin >> answer;

    switch(answer) {
    case 1:
        {
            #ifdef _WIN32
	            system("cls");
            #else
	            std::cout << "\033[2J\033[H";
            #endif
            select_room();
            display_booking_menu();
            break;
        }
    case 2:
        {
            exit(0);
        }
    default:
        {
            std::cerr << "Invalid input.\n";
            break;
        }
    }
}

void App::display_booking_menu()
{
    int answer = 0;

    do {
        std::cout << "--- Booking ---" << "\n";
        std::cout << "1. " << "Zmien pokoj" << "\n";
        std::cout << "2. " << ((new_user->get_chosen_services().empty()) ? "Wybierz" : "Zmien") << " uslugi" << "\n";
        std::cout << "3. " << ((chosen_amenities.empty()) ? "Wybierz" : "Zmien") << " dodatki" << "\n";
        std::cout << "4. Pokaz dane rezerwacji" << "\n";
        if (new_user->get_user_booked_room_id() != -1) std::cout << "5. Zakoncz rezerwacje" << "\n";

        std::cout << "Co chcesz zrobic: ";
        std::cin >> answer;

        #ifdef _WIN32
	        system("cls");
        #else
	        std::cout << "\033[2J\033[H";
        #endif

        switch(answer) {
        case 1:
            {
                select_room();
                break;
            }
        case 2:
            {
                select_services();
                break;
            }
        case 3:
            {
                select_amenities();
                break;
            }
        case 4:
            {
                display_booking_data();
                break;
            }
        case 5:
            {
                save_current_booking();
                break;
            }
        default:
            {
                std::cerr << "Invalid input.\n";
                break;
            }
        }
        
        #ifdef _WIN32
	        system("cls");
        #else
	        std::cout << "\033[2J\033[H";
        #endif
    } while(answer != 5);

    std::cout << "Calkowity koszt pobytu: " << calculate_total_cost(new_user->get_user_booked_room_id(), new_user->get_chosen_services(), chosen_amenities, new_user->get_booked_nights()) << "zl" << "\n";
}

void App::select_room() const
{
    int selected_room = -1;
    do {
        #ifdef _WIN32
	        system("cls");
        #else
	        std::cout << "\033[2J\033[H";
        #endif
        
        display_rooms();

        if (selected_room != -1) {
            if (available_rooms[selected_room].is_vacant != true) std::cout << "Wybrany pokoj jest zajety." << "\n";
        }

        std::cout << "Wybierz numer pokoju: ";
        std::cin >> selected_room;
        new_user->set_user_booked_room_id(selected_room);

    } while(available_rooms[selected_room].is_vacant != true);

    std::string booked_from;
    time_t date_converted_to_time = -1;

    do {
        std::cout << "Na kiedy zarezerwowac (YYYY-MM-DD): ";
        std::cin >> booked_from;

        try {
            date_converted_to_time = convert_date_to_time(booked_from);
        } catch (const std::invalid_argument& e) {
            std::cout << "Podano date w zlym formacie.\n\t" << "exception: \t" << e.what() <<  "\n";
        }

    } while(date_converted_to_time == -1);

    new_user->set_booked_in(date_converted_to_time);

    int nights_count = 0;
    std::cout << "Na ile dni: ";
    std::cin >> nights_count;
    new_user->set_booked_nights(nights_count);
    new_user->set_booked_out(new_user->get_booked_in() + nights_count * 864000);

    #ifdef _WIN32
	    system("cls");
    #else
	    std::cout << "\033[2J\033[H";
    #endif
}

void App::select_services() const
{
    std::string selected_services;

    display_services();
    std::cout << "Wybierz numery uslug (oddzielone przecinkiem): ";
    std::cin >> selected_services;
    new_user->set_chosen_services(get_selected_services(selected_services));

    #ifdef _WIN32
	    system("cls");
    #else
	    std::cout << "\033[2J\033[H";
    #endif
}

void App::select_amenities()
{
    {
        std::string selected_amenities;

        display_amenities();
        std::cout << "Wybierz numery udogodnien (oddzielone przecinkiem): ";
        std::cin >> selected_amenities;
        chosen_amenities = get_selected_amenities(selected_amenities);
    }
}

double App::calculate_total_cost(unsigned int room_id, const std::vector<Service>& chosen_services,
                                 const std::vector<Amenities>& chosen_amenities, int booked_nights) const
{
    double total_cost = 0.0;
    total_cost += available_rooms[room_id].room_cost;
    for (const Service &service : chosen_services) {
        total_cost += service.price;
    }
    
    for (const Amenities &amenity : chosen_amenities) {
        total_cost += amenity.amenity_price * booked_nights;
    }

    return total_cost;
}

time_t App::convert_date_to_time(const std::string& date)
{
    std::tm tm = {};
    std::stringstream ss(date);

    ss >> std::get_time(&tm, "%Y-%m-%d");
    if (ss.fail()) {
        throw std::invalid_argument("Podano nieprawidlowy format. Oczekiwano: YYYY-MM-DD.");
    }

    tm.tm_hour = 0;
    tm.tm_min = 0;
    tm.tm_sec = 0;

    return std::mktime(&tm);
}

std::string App::convert_time_to_date(const time_t& date)
{
    std::tm tm;
    if (std::localtime_r(&date, &tm) == nullptr) {
        throw std::runtime_error("Nastapil blad podczas konwersji czasu.");
    }

    std::stringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d");

    return oss.str();
}

std::vector<Service> App::get_selected_services(const std::string& selected_services) const
{
    std::vector<Service> chosen_services;
    std::stringstream ss(selected_services);
    std::string service_id;

    while (getline(ss, service_id, ',')) {
        int id = stoi(service_id);
        if (id >= 0 && id < available_services.size()) {
            chosen_services.push_back(available_services[id]);
        }
    }

    return chosen_services;
}

std::vector<Amenities> App::get_selected_amenities(const std::string& selected_amenities) const
{
    std::vector<Amenities> chosen_amenities;
    std::stringstream ss(selected_amenities);
    std::string amenity_id;

    while (getline(ss, amenity_id, ',')) {
        int id = stoi(amenity_id);
        if (id >= 0 && id < available_amenities.size()) {
            chosen_amenities.push_back(available_amenities[id]);
        }
    }

    return chosen_amenities;
}

void App::add_new_user(const std::shared_ptr<User_account>& new_user)
{
    this->hotel_account.add_user(new_user);
}

void App::add_new_booking(std::tuple<unsigned int, time_t, time_t> room_booking)
{
    this->hotel_account.add_booking(room_booking);
}

void App::run()
{
    std::cout << "Witaj w naszym hotelu uzytkowniku!\n\n";

    char answer = 'n';
    do {
        display_main_menu();

        std::cout << "\nWrocic do menu (t/n): ";
        std::cin >> answer;
        if (answer == 't') {
            current_user_id += 1;
            new_user = std::make_shared<User_account>(current_user_id, 0.0, 0, 0, 0, -1, std::vector<Service>());
        }
        #ifdef _WIN32
	        system("cls");
        #else
	        std::cout << "\033[2J\033[H";
        #endif
    } while(answer == 't');
}

void App::save_current_booking()
{
    const double accumulated_cost = calculate_total_cost(new_user->get_user_booked_room_id(), new_user->get_chosen_services(), chosen_amenities, new_user->get_booked_nights());
    new_user->set_accumulated_cost(accumulated_cost);
    add_new_user(new_user);
    add_new_booking(std::tuple<unsigned int, time_t, time_t> (new_user->get_user_booked_room_id(), new_user->get_booked_in(), new_user->get_booked_out()));
    available_rooms[new_user->get_user_booked_room_id()].is_vacant = false;
}
