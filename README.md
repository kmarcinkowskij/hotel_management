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
- Klasa `Amenities` reprezentuje pojedyncze udogodnienie dostępne w hotelu, przechowując jego identyfikator, nazwę, opis oraz cenę.