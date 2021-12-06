#include <ctype.h> // Include ctype.h for strcasecmp 
#include <stdio.h> 
#include <string.h> 

struct Hospital { 
	char name[50]; 
	char city[50]; 
	int beds; 
	float price; 
	float rating; 
	int reviews; 
}; 

struct Patient { 
	char name[50]; 
	int age; 
}; 

int main() { 
	struct Hospital hospitals[5] = { { "Hospital A", "X", 100, 250.0, 4.5, 100 }, 
                                    { "Hospital B", "Y", 150, 200.0, 4.2, 80 }, 
                                    { "Hospital C", "X", 200, 180.0, 4.0, 120 }, 
                                    { "Hospital D", "Z", 80, 300.0, 4.8, 90 }, 
                                    { "Hospital E", "Y", 120, 220.0, 4.6, 110 } }; 

	struct Patient patients[5][3] = { { { "Amar", 35 }, 
										{ "Manish", 45 }, 
										{ "Atul", 28 } }, 
									{ { "Elvish", 62 }, 
										{ "Debolina", 18 }, 
										{ "Shruti", 55 } }, 
									{ { "Zafar", 50 }, 
										{ "Rahul", 30 }, 
										{ "Priya", 40 } }, 
									{ { "Amir", 22 }, 
										{ "Asif", 38 }, 
										{ "Prince", 60 } }, 
									{ { "Aditya", 28 }, 
										{ "Aman", 48 }, 
										{ "Sahil", 33 } } }; 

	int n = 5; // Number of hospitals 

	int choice; 
	char city[50]; 

	do {
		switch (choice) { 
		case 1: 
			printf("\nPrinting Hospital Data:\n\n"); 
			for (int i = 0; i < n; i++) { 
				printHospital(hospitals[i]); 
			} 
			break; 
		case 2: 
			printf("Printing Patients Data:\n\n"); 
			for (int i = 0; i < n; i++) { 
				printf("Hospital: %s\n", hospitals[i].name); 
				for (int j = 0; j < 3; j++) { 
					printPatient(patients[i][j]); 
				} 
			} 
			break; 
		case 3: 
			printf("Sorting Hospitals by Beds Price (Ascending):\n"); 
			sortByBeds(hospitals, n); 
			for (int i = 0; i < n; i++) { 
				printHospital(hospitals[i]); 
			} 
			break; 
		case 4: 
			printf("Sorting Hospitals by Available Beds (Descending):\n"); 
			sortByBeds(hospitals, n); // Fix: Sorting by available beds 
			for (int i = 0; i < n; i++) { 
				printHospital(hospitals[i]); 
			} 
			break; 
		case 5: 
			printf("Sorting Hospitals by Name (Ascending):\n"); 
			sortByName(hospitals, n); 
			for (int i = 0; i < n; i++) { 
				printHospital(hospitals[i]); 
			} 
			break; 
		case 6: 
			printf("Sorting Hospitals by Rating and Reviews (Descending):\n"); 
			sortByRating(hospitals, n); 
			for (int i = 0; i < n; i++) { 
				printHospital(hospitals[i]); 
			} 
			break; 
		case 7: 
			printHospitalsInCity(hospitals); 
			break; 
		case 8: 
			printf("Exiting the program.\n"); 
			break; 
		default: 
			printf("Invalid choice. Please enter a valid option.\n"); 
		} 
	} while (choice != 8); 
	return 0; 
}
