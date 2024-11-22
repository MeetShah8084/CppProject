#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Reservationsystem {
private:
    int available_seats, total, booked_seats;

public:
    Reservationsystem(int seats) {
        total = seats;
        available_seats = total;
        booked_seats = 0;
    }

    void bookticket(int seats) {
        if (seats <= available_seats) {
            available_seats -= seats;
            booked_seats += seats;
            cout << seats << " seats are booked successfully." << endl;
        } else {
            cout << "Not enough seats." << endl;
        }
        cout << endl;
    }

    void cancelticket(int seats) {
        if (booked_seats < seats) {
            cout << "You can't cancel more seats than booked!" << endl << endl;
            return;
        }
        available_seats += seats;
        booked_seats -= seats;
        cout << seats << " seats are cancelled." << endl;
        cout << endl;
    }

    void displayseats() {
        cout << "Available Seats: " << available_seats << endl;
        cout << endl;
    }

    inline int getAvailableSeats() {
        return available_seats;
    }

    inline int getBookedSeats() {
        return booked_seats;
    }
};

class Passenger {
public:
    char name[100];
    int age;
    string gender;
    int booked_seats;

    Passenger() : booked_seats(0) {}

    // Function to validate name (no numbers allowed)
    bool validateName(const string &input) {
        for (char ch : input) {
            if (isdigit(ch)) {
                return false;
            }
        }
        return true;
    }

    // Function to validate gender (only Male or Female)
    bool validateGender(const string &input) {
        return (input == "Male" || input == "Female");
    }

    void inputDetails() {
        cout << "Enter Passenger details:\n";

        // Validate name input
        do {
            cout << "Name of passenger: ";
            cin.getline(name,100);
            if (!validateName(name)) {
                cout << "Invalid name. Name cannot contain numbers. Please try again." << endl;
            }
        } while (!validateName(name));

        // Validate age input
        cout << "Age of passenger: ";
        while (!(cin >> age) || age <= 0) {
            cout << "Invalid input. Age must be a positive number. Try again: ";
            cin.clear();
            // cin.ignore(10000, '\n');
        }

        // Validate gender input
        do {
            cout << "Gender of passenger (Male/Female): ";
            cin >> gender;
            if (!validateGender(gender)) {
                cout << "Invalid gender. Please enter 'Male' or 'Female'." << endl;
            }
        } while (!validateGender(gender));

        cout << endl;
    }

    void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Gender: " << gender << endl;
        cout << "This user has booked " << booked_seats << " seats in the train." << endl << endl;
    }

    void bookSeats(int seats) {
        booked_seats += seats;
    }

    void cancelSeats(int seats) {
        booked_seats -= seats;
    }
};

int main() {
    const int USER_COUNT = 1;
    Passenger passengers[USER_COUNT];
    Reservationsystem reservation(50);  // Shared pool of 50 seats
    int current_user = 0;
    int choice, seats;

    // Input details for all passengers
    for (int i = 0; i < USER_COUNT; i++) {
        cout << "Enter details for Passenger " << i + 1 << ":" << endl;
        passengers[i].inputDetails();
        cin.ignore(100,'\n');
    }

    do {
        cout << "\t\tRAILWAY RESERVATION SYSTEM - Passenger " << current_user + 1 << endl;
        cout << "Press 1. Book Ticket" << endl;
        cout << "Press 2. Cancel Ticket" << endl;
        cout << "Press 3. Available Tickets" << endl;
        cout << "Press 4. Change User" << endl;
        cout << "Press 5. Display User Details" << endl;
        cout << "Press 6. Exit" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;
        cout << endl;

        switch (choice) {
            case 1:
                cout << "Enter the number of seats to book: ";
                cin >> seats;
                if (seats <= reservation.getAvailableSeats()) {
                    reservation.bookticket(seats);
                    passengers[current_user].bookSeats(seats);
                } else {
                    cout << "Not enough seats available!" << endl << endl;
                }
                break;

            case 2:
                cout << "Enter the number of seats to cancel: ";
                cin >> seats;
                if (seats <= passengers[current_user].booked_seats) {
                    reservation.cancelticket(seats);
                    passengers[current_user].cancelSeats(seats);
                } else {
                    cout << "You can't cancel more seats than you have booked!" << endl << endl;
                }
                break;

            case 3:
                reservation.displayseats();
                break;

            case 4:
                cout << "Select User (1-" << USER_COUNT << "): ";
                cin >> current_user;
                current_user--;  // Adjust for 0-based index
                if (current_user < 0 || current_user >= USER_COUNT) {
                    cout << "Invalid user selection. Please select a valid user." << endl;
                    current_user = 0;
                }
                break;

            case 5:
                cout << "Passenger Details:\n";
                for (int i = 0; i < USER_COUNT; i++) {
                    cout << "Passenger " << i + 1 << ":\n";
                    passengers[i].displayDetails();
                }
                break;

            case 6:
                cout << "Exiting...." << endl;
                break;

            default:
                cout << "Invalid Choice" << endl;
                cout << endl;
                break;
        }
    } while (choice != 6);

    return 0;
}
