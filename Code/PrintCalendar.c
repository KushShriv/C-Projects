#include <stdio.h> 

char* getMonthName(int monthNumber) { 
	char* month; 

	switch (monthNumber) { 
	case 0: 
		month = "January"; 
		break; 
	case 1: 
		month = "February"; 
		break; 
	case 2: 
		month = "March"; 
		break; 
	case 3: 
		month = "April"; 
		break; 
	case 4: 
		month = "May"; 
		break; 
	case 5: 
		month = "June"; 
		break; 
	case 6: 
		month = "July"; 
		break; 
	case 7: 
		month = "August"; 
		break; 
	case 8: 
		month = "September"; 
		break; 
	case 9: 
		month = "October"; 
		break; 
	case 10: 
		month = "November"; 
		break; 
	case 11: 
		month = "December"; 
		break; 
	} 
	return month; 
} 

int numberOfDays(int monthNumber, int year) { 
	if (monthNumber == 0) return (31); 
	if (monthNumber == 1) { 
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) return (29); 
		else return (28); 
	} 
	if (monthNumber == 2) return (31); 
	if (monthNumber == 3) return (30); 
	if (monthNumber == 4) return (31); 
	if (monthNumber == 5) return (30); 
	if (monthNumber == 6) return (31); 
	if (monthNumber == 7) return (31); 
	if (monthNumber == 8) return (30); 
	if (monthNumber == 9) return (31); 
	if (monthNumber == 10) return (30); 
	if (monthNumber == 11) return (31); 
} 

int main() { 
	int year = 2022; 
	printCalendar(year); 
	return 0; 
} 