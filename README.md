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