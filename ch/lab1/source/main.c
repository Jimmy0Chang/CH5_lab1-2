#include <stdio.h>
#include <stdlib.h>
#define STUDENTS 3
#define EXAMS 4

void mini(int grade[][EXAMS], int pupils, int tests);
void maxi(int grade[][EXAMS], int pupils, int tests);
void ave(int grade[][EXAMS], int pupils, int tests);
void pria(int grade[][EXAMS], int pupils, int tests);
void printMenu();

int main() {
	int studentGrades[STUDENTS][EXAMS] = { {77,68,86,73},
										  {96,87,89,78},
										  {70,90,86,81} };
	void(*processGrages[4])(int[STUDENTS][EXAMS], int, int)
		= { pria,mini,maxi,ave };

	int choice = 0;
	while (choice != 4) {
		do {
			printMenu(); scanf_s("%d", &choice);
		} while (choice < 0 || choice >4);
		if (choice != 4) {
			(*processGrages[choice])(studentGrades,STUDENTS,EXAMS);
		}
		else {
			printf("\tProgram ended. \n");
		}
	}
	system("pause");
	return 0;
}
void mini(int grade[][EXAMS], int pupils, int tests) {
	int i, j;
	int lowg = 100;
	for (i = 0; i < pupils; i++) {
		for (j = 0; j < tests; j++) {
			if (grade[i][j] < lowg)
				lowg = grade[i][j];
		}
	}
	printf("\n\tThe lowest grade is %d", lowg);
	printf("\n");
}
void maxi(int grade[][EXAMS], int pupils, int tests) {
	int i, j;
	int highg = 0;
	for (i = 0; i < pupils; i++) {
		for (j = 0; j < tests; j++) {
			if (grade[i][j] > highg)
				highg = grade[i][j];
		}
	}
	printf("\n\tThe highest grade is %d", highg);
	printf("\n");
}
void ave(int grade[][EXAMS], int pupils, int tests) {
	int i, j;
	int total = 0;
	for (i = 0; i < pupils; i++) {
		total = 0;
		for (j = 0; j < tests; j++) {
			total += grade[i][j];
		}
		printf("\n\tThe ave grade for student %d is %.1f", i+1,(double)total/tests);
	}	
	printf("\n");
}
void pria(int grade[][EXAMS], int pupils, int tests) {
	int i, j;
	printf("\n\t\t\t[0]		[1]		[2]		[3]");
	for (i = 0; i < pupils; i++) {
		printf("\n\tstudentGrades[%d]", i);
		for (j = 0; j < tests; j++) {
			printf("%-7d", grade[i][j]);
		}
	}
	printf("\n");
}
void printMenu() {
	printf("\n");
	printf("\tEnter a choice:\n");
	printf("\t0 Print the array of grades\n");
	printf("\t1 Find the minimum grades\n");
	printf("\t2 Find the maximum grades\n");
	printf("\t3 Print the average onall tests for each student\n");
	printf("\t4 End the program\n");
	printf("Choice:");
}
