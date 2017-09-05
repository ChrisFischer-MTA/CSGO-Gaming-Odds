// csgoGamSim.cpp : Defines the entry point for the console application.
//

#include "stdafx.h";
#include <time.h>
#include <iostream>
#include <malloc.h>
#include <Windows.h>
int arr[1000];
int bet[20] = {1,1,2,3,5, 8, 13, 21, 34, 55, 89, 144,233,377,610,987,1597,2584,4181,6765};
int getRand() {
	return (rand() % 101);
}
void game(FILE* file, float sum, int index) {
	//printf("\nGame - %f", sum);
	fprintf(file, "%f ", sum);
	if (getRand() > 45) {
		game(file, sum*bet[index+1], index+1);
	}
	else {
		fputs("\n",file);
		if (index < 20) {
			arr[index] = arr[index] + 1;
		}
		return;
	}

}

void game(FILE* file, float currentBet, int index, float totalmoney) {
	if (index != 20) {
		fprintf(file, "%i,%f,%f,%f", index, currentBet, totalmoney, currentBet*2);
		game(file, currentBet*bet[index], index, totalmoney + (currentBet));
	}
}

int main()
{
	srand(time(NULL));
	for (int i = 0; i < 1000; i++) {
		arr[i] = 0;
	}
	const char datName[8] = "ped.dat"; // hehe
	const char* writingMode = "a";
	FILE* stream = fopen(datName, writingMode);
	//fprintf(stream, );
	//1073741824
	/*
	for (int i = 0; i < 600000; i++) {
		game(stream, (float)0.5, 0);
		if (i % 50000 == 0)
			printf("%i\n", i);
	}
	int sum = 0;
	for (int i = 0; i < 1000; i++) {
		sum += arr[i];
	}
	fprintf(stream, "Total games %i\n", sum);
	for (int i = 0; i < 20; i++) {
		fprintf(stream, "Games won in index %i, %i\n", i, arr[i]);
	}
	*/
	game(stream, 0.5, 0, 0.5);
	fclose(stream);
	

}


