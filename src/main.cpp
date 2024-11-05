#include <iostream>
#include <string_view>

std::string_view menu = 
    "<>-----MENU-----<>\n"
    "1. Book an apartment.\n"
    "2. Cancel booking.\n"
    "3. Call service.\n"
    "4. Extend amenities.\n"
    "5. Exit.\n"
    "<>--------------<>\n";

int main() {
    std::cout << "Welcome to the X Hotel!\n"; // TODO: We still haven't thought of a name.
    
    while(true) {
        std::cout << menu;
    
        unsigned int chosen_option = 0;
    
        std::cout << "Choose an option: ";
        std::cin >> chosen_option;
        
        switch(chosen_option) {
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
            std::cout << "Thank you for using our sevices.\n";
            return 0;
        break;
        default:
            std::cout << "The option you selected does not exist. Please choose a valid option and try again.\n";
        break;
        }
    }

    return 0;
}
