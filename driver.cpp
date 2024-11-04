// Benjamin DeJong
// CS318
// Project 4
// This project simulates Dorothy picking up emeralds
// and measures how many she can pick up based on
// certain criteria.


#include <queue>	// for priority queue to manage baskets
#include <iostream>	// for input and output
#include <random>	// for generating the number of emeralds per basket
using namespace std;

void countAndRefillBaskets(priority_queue<unsigned int>& baskets, unsigned long& collectedEmeralds) {
	unsigned int basketsContent = baskets.top();
	collectedEmeralds += basketsContent;
	baskets.pop();
	baskets.push(basketsContent / 2);
}

long int collectEmeralds(const int& numBaskets, const int& numMinutes) {
	priority_queue<unsigned int> baskets;
	srand(static_cast<unsigned int>(time(0)));

	for (size_t i = 0; i < numBaskets; i++) {
		baskets.push(rand() % 100 + 1); // i decided there can be 1-100 emeralds
	}

	unsigned long collectedEmeralds{ 0 };

	unsigned int basketsContent{ 0 };
	for (size_t i = 0; i < numMinutes; i++) {
		countAndRefillBaskets(baskets, collectedEmeralds);
	}
	return collectedEmeralds;
}


int main() {

	cout << "**** Dorothy and Emeralds ****\n\n";
	cout << "\nEnter the number of baskets: ";
	int numBaskets;
	cin >> numBaskets;
	bool runLoop = true;

	cout << "\nEnter the number of minutes: ";
	int numMinutes;
	cin >> numMinutes;

	if (numBaskets == 0 || numMinutes == 0) {
		cout << "\nDorothy has gathered 0 emeralds!";
		runLoop = false;
	}
	while(numMinutes < 0) {
		cout << "Number of minutes must be greater than or equal to 0\n";
		cout << "\nEnter the number of minutes: ";
		cin >> numMinutes;
	}
	while (numBaskets < 0) {
		cout << "Number of baskets must be greater than or equal to 0\n";
		cout << "\nEnter the number of baskets: ";
		cin >> numBaskets;
	}

	if (runLoop) {
		long int collectedEmeralds = collectEmeralds(numBaskets, numMinutes);
		cout << "\nDorothy has gathered " << collectedEmeralds << " emeralds!";
	}


	return 0;
}