## Dokumentacja

### struct `Amenities`

**Atrybuty:**
- `unsigned int amenity_id` - identyfikator udogodnienia.
- `std::string amenity_name` - nazwa udogodnienia.
- `std::string amenity_description` - opis udogodnienia.
- `double amenity_price` - cena udogodnienia.

**Metody:**
- **Konstruktor**: `Amenities(unsigned int id, const std::string& name, const std::string& description, double price)`
    - Inicjalizuje atrybuty `amenity_id`, `amenity_name`, `amenity_description` oraz `amenity_price` podanymi wartościami.

**Przeznaczenie:**
- Struktura `Amenities` reprezentuje pojedyncze udogodnienie dostępne w hotelu, przechowując jego identyfikator, nazwę, opis oraz cenę.

### struct `Service`

**Atrybuty:**
- `unsigned int service_id` - identyfikator serwisu.
- `std::string service_name` - nazwa serwisu.
- `std::string service_description` - opis serwisu.
- `double service_price` - cena serwisu.

**Metody:**
- **Konstruktor**: `(const unsigned int& _service_id, const std::string& _service_name, const std::string& _service_description, const double& _price)`
    - Inicjalizuje atrybuty `_service_id`, `_service_name`, `_service_description` oraz `amenity_price` podanymi _price.

**Przeznaczenie:**
- Struktura `Service` reprezentuje pojedyncze serwisy dostępne w hotelu, przechowując jego identyfikator, nazwę, opis oraz cenę.

### class `Hotel_account`

**Atrybuty:**
- `std::array<std::shared_ptr<Service>, 5> services` - tablica wskaźników do obiektów typu `Service`, reprezentująca dostępne usługi w hotelu.
- `std::vector<std::shared_ptr<User_account>> user_accounts` - wektor wskaźników do obiektów typu `User_account`, przechowujący informacje o wszystkich kontach użytkowników w hotelu.
- `std::vector<std::tuple<Room, time_t, time_t>> room_bookings` - wektor krotek przechowujących informacje o rezerwacjach pokoi w hotelu, w tym szczegóły pokoju oraz czas rozpoczęcia i zakończenia rezerwacji.

**Metody:**

- **Konstruktor domyślny**: `Hotel_account()`
  - Inicjalizuje tablicę `services` pięcioma obiektami `Service`, nadając im domyślne wartości (np. identyfikatory, nazwy, opisy oraz ceny). Służy do ustawienia początkowych usług dostępnych w hotelu.

- **add_user**: 
  - `void add_user(const std::shared_ptr<User_account>& _user)`
    - Dodaje istniejące konto użytkownika do listy kont użytkowników w hotelu.
    - **Parametry**: `_user` - wskaźnik na obiekt typu `User_account`, który ma zostać dodany.
  
  - `void add_user(const unsigned int& _user_id, const double& _accumulated_cost, const time_t& _booked_in, const time_t& _booked_out, const unsigned int& _booked_nights, const unsigned int& _user_booked_room_id, const std::vector<Service>& _chosen_services)`
    - Tworzy nowego użytkownika z podanymi parametrami i dodaje go do listy kont użytkowników.
    - **Parametry**:
      - `_user_id` - identyfikator użytkownika.
      - `_accumulated_cost` - skumulowany koszt pobytu.
      - `_booked_in` - czas zameldowania.
      - `_booked_out` - czas wymeldowania.
      - `_booked_nights` - liczba zarezerwowanych nocy.
      - `_user_booked_room_id` - identyfikator zarezerwowanego pokoju.
      - `_chosen_services` - wybrane usługi.

- **add_booking**:
  - `void add_booking(const std::tuple<Room, time_t, time_t>& _room_booking)`
    - Dodaje nową rezerwację pokoju do listy rezerwacji.
    - **Parametry**: `_room_booking` - krotka zawierająca pokój oraz daty rozpoczęcia i zakończenia rezerwacji.

  - `void add_booking(const Room& _room, const time_t& _booked_from, const time_t& _booked_to)`
    - Tworzy nową rezerwację dla podanego pokoju oraz dat rozpoczęcia i zakończenia.
    - **Parametry**:
      - `_room` - obiekt reprezentujący pokój.
      - `_booked_from` - data rozpoczęcia rezerwacji.
      - `_booked_to` - data zakończenia rezerwacji.

- **remove_booking**:
  - `void remove_booking(const unsigned int& _room_id)`
    - Usuwa rezerwację pokoju na podstawie identyfikatora pokoju.
    - **Parametry**: `_room_id` - identyfikator pokoju do usunięcia.
    - **Wyjątek**: Wyrzuca wyjątek, jeśli rezerwacja dla podanego identyfikatora pokoju nie istnieje.

- **remove_user**:
  - `void remove_user(const unsigned int& _user_id)`
    - Usuwa użytkownika z listy kont na podstawie jego identyfikatora.
    - **Parametry**: `_user_id` - identyfikator użytkownika, którego konto ma zostać usunięte.
    - **Wyjątek**: Wyrzuca wyjątek, jeśli użytkownik o podanym identyfikatorze nie istnieje.

**Przeznaczenie:**
- Klasa `Hotel_account` reprezentuje hotel, zarządzając kontami użytkowników, rezerwacjami pokoi oraz dostępnymi usługami. Oferuje metody do dodawania, usuwania i przeglądania rezerwacji oraz informacji o użytkownikach, co wspomaga bieżące zarządzanie hotelowymi operacjami.

### class `App`

**Atrybuty:**
- `std::vector<Room> available_rooms` - wektor dostępnych pokoi w hotelu.
- `std::vector<Service> available_services` - wektor dostępnych usług w hotelu.
- `std::vector<Amenities> available_amenities` - wektor dostępnych udogodnień w hotelu.
- `std::vector<Amenities> chosen_amenities` - wektor wybranych przez użytkownika udogodnień.
- `std::shared_ptr<User_account> new_user` - wskaźnik do obiektu reprezentującego nowego użytkownika.
- `unsigned int current_user_id` - identyfikator obecnego użytkownika.
- `Hotel_account hotel_account` - obiekt klasy `Hotel_account`, zarządzający kontami użytkowników oraz rezerwacjami.

**Metody:**

- **display_rooms**:
  - `void display_rooms() const`
    - Wyświetla listę dostępnych pokoi wraz z informacjami o numerze pokoju, jego dostępności oraz cenie za noc.

- **display_services**:
  - `void display_services() const`
    - Wyświetla listę dostępnych usług, w tym ich identyfikatory, nazwy, opisy oraz ceny.

- **display_amenities**:
  - `void display_amenities() const`
    - Wyświetla listę dostępnych udogodnień, w tym ich identyfikatory, nazwy, opisy oraz ceny.

- **display_booking_data**:
  - `void display_booking_data() const`
    - Wyświetla dane o bieżącej rezerwacji użytkownika, w tym numer pokoju, daty rezerwacji, liczbę nocy oraz wybrane usługi i udogodnienia.

- **display_main_menu**:
  - `void display_main_menu()`
    - Wyświetla główne menu aplikacji, umożliwiając użytkownikowi wybór między rezerwacją pokoju a wyjściem.

- **display_booking_menu**:
  - `void display_booking_menu()`
    - Wyświetla menu rezerwacji, pozwalające na zmianę pokoju, usług, udogodnień, przeglądanie danych rezerwacji oraz zakończenie rezerwacji.

- **select_room**:
  - `void select_room() const`
    - Umożliwia użytkownikowi wybór pokoju z dostępnej listy. Sprawdza, czy pokój jest wolny, oraz zbiera dane dotyczące daty rezerwacji.

- **select_services**:
  - `void select_services() const`
    - Umożliwia użytkownikowi wybór usług z dostępnej listy, na podstawie numerów usług oddzielonych przecinkiem.

- **select_amenities**:
  - `void select_amenities()`
    - Umożliwia użytkownikowi wybór udogodnień z dostępnej listy, na podstawie numerów udogodnień oddzielonych przecinkiem.

- **calculate_total_cost**:
  - `double calculate_total_cost(unsigned int room_id, const std::vector<Service>& chosen_services, const std::vector<Amenities>& chosen_amenities, int booked_nights) const`
    - Oblicza całkowity koszt rezerwacji na podstawie wybranego pokoju, usług, udogodnień oraz liczby nocy pobytu.

- **convert_date_to_time**:
  - `time_t convert_date_to_time(const std::string& date)`
    - Konwertuje datę w formacie "YYYY-MM-DD" na wartość typu `time_t` (czas w sekundach).

- **convert_time_to_date**:
  - `std::string convert_time_to_date(const time_t& date)`
    - Konwertuje czas w formacie `time_t` na datę w formacie "YYYY-MM-DD".

- **get_selected_services**:
  - `std::vector<Service> get_selected_services(const std::string& selected_services) const`
    - Zwraca wektor wybranych usług na podstawie podanego ciągu znaków, zawierającego numery usług oddzielone przecinkami.

- **get_selected_amenities**:
  - `std::vector<Amenities> get_selected_amenities(const std::string& selected_amenities) const`
    - Zwraca wektor wybranych udogodnień na podstawie podanego ciągu znaków, zawierającego numery udogodnień oddzielone przecinkami.

- **add_new_user**:
  - `void add_new_user(const std::shared_ptr<User_account>& new_user)`
    - Dodaje nowe konto użytkownika do systemu.

- **add_new_booking**:
  - `void add_new_booking(std::tuple<unsigned int, time_t, time_t> room_booking)`
    - Dodaje nową rezerwację pokoju do systemu.

- **run**:
  - `void run()`
    - Uruchamia główną pętlę aplikacji, wyświetlając menu i pozwalając użytkownikowi na interakcję z aplikacją.

- **save_current_booking**:
  - `void save_current_booking()`
    - Zapisuje bieżącą rezerwację, obliczając jej całkowity koszt oraz aktualizując dane użytkownika i rezerwacji w systemie.

**Przeznaczenie:**
- Klasa `App` reprezentuje główną logikę aplikacji hotelowej, umożliwiając użytkownikowi interakcję z systemem rezerwacji. Obsługuje menu aplikacji, wybór pokoi, usług, udogodnień oraz rejestrację rezerwacji. Dodatkowo, oblicza całkowity koszt pobytu oraz zapisuje dane użytkownika i rezerwacji.


### class `User_account`
  Przechowuje dane użytkownika: Klasa zawiera prywatne zmienne członkowskie, które przechowują informacje takie jak unikalny identyfikator użytkownika (user_id), całkowity koszt naliczony przez użytkownika (accumulated_cost), czas zameldowania (booked_in), czas wymeldowania (booked_out), liczbę zarezerwowanych nocy (booked_nights), identyfikator zarezerwowanego pokoju (user_booked_room_id) oraz listę wybranych usług (chosen_services).
