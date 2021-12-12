#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 

struct Bus { 
	int busNumber; 
	char source[50]; 
	char destination[50]; 
	int totalSeats; 
	int availableSeats; 
	float fare; 
}; 

struct Passenger { 
	char name[50]; 
	int age; 
	int seatNumber; 
	int busNumber; 
}; 

struct User { 
	char username[50]; 
	char password[50]; 
}; 

int main() { 
	struct User users[5] = { 
		{ "user1", "password1" }, { "user2", "password2" }, 
		{ "user3", "password3" }, { "user4", "password4" }, 
		{ "user5", "password5" }, 
	}; 
	int numUsers = 5; 

	struct Bus buses[3] = { 
		{ 101, "City A", "City B", 50, 50, 25.0 }, 
		{ 102, "City C", "City D", 40, 40, 20.0 }, 
		{ 103, "City E", "City F", 30, 30, 15.0 }, 
	}; 
	int numBuses = 3; 
	struct Passenger passengers[500]; 
	int numPassengers = 0;
	int loggedInUserId = -1; 

	while (1) { 
		if (loggedInUserId == -1) { 
			displayMainMenu(); 
			int choice; 
			scanf("%d", &choice); 

			if (choice == 1) { 
				char username[50]; 
				char password[50]; 

				printf("Enter Username: "); 
				scanf("%s", username); 
				printf("Enter Password: "); 
				scanf("%s", password); 

				loggedInUserId = loginUser(users, numUsers, username, password); 
				if (loggedInUserId == -1) { 
					printf("Login failed. Please check your username and password.\n"); 
				} 
				else { 
					printf("Login successful. Welcome, %s!\n", username); 
				} 
			} 
			else if (choice == 2) { 
				printf("Exiting the program.\n"); 
				break; 
			} 
			else { 
				printf("Invalid choice. Please try again.\n"); 
			} 
		} 
		else { 
			displayUserMenu(); 
			int userChoice; 
			scanf("%d", &userChoice); 

			switch (userChoice) { 
                case 1: 
                    bookTicket(buses, numBuses, passengers, &numPassengers, loggedInUserId); 
                    break; 
                case 2: 
                    cancelTicket(buses, numBuses, passengers, &numPassengers, loggedInUserId); 
                    break; 
                case 3: 
                    checkBusStatus(buses, numBuses, loggedInUserId); 
                    break; 
                case 4: 
                    printf("Logging out.\n"); 
                    loggedInUserId = -1; 
                    break; 
                default: 
                    printf("Invalid choice. Please try again.\n"); 
			} 
		} 
	} 
	return 0; 
}
