#include <iostream>

void Display_menu() {
    std::cout << "<>-----MENU-----<>\n";
    std::cout << "1. Book an apartment.\"n;
    std::cout << "2. Cancel booking.\n";
    std::cout << "3. Call service.\n";
    std::cout << "4. Extend amenities.\n";
    std::cout << "5. Exit.\n";
    std::cout << "<>--------------<>\n";
}

int main() {

    Display_menu();
    int chosen_option = 0;

    std::cout << "Choose an option: ";
    cin >> chosen_option;

    while(true) {
        switch(chosen) {
        case 1:
        //Rezerwacja pokoju.
        /*

        */
        break;
        case 2:
        //Anuluj rezerwacje
        /*

        */
        break;
        case 3:
        //Zamow usluge
        /*

        */
        break;
        case 4:
        //Dodaj udogodnienie
        /*

        */
        break;
        case 5:
            std::cout << "Exitting.\n";
            return 0;
        break;
        default:
            std::cout << "Chosen option does not exist!\n";
        break;
        }
    }

    return 0;
}
