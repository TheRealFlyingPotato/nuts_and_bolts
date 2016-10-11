using namespace std;
#include <stdlib.h>
#include <iostream>
#include <ctime>

const long c_NUMOFPAIRS = 10; 

bool is_in(const int value, const int ARR[]);


int main()
{
	srand(time(NULL));

	int bolts[c_NUMOFPAIRS] = {};
	int nuts[c_NUMOFPAIRS] = {}; //initialize both arrays w/ values of zero

	//generate the bolts and nut sizes
	for (int k = 0; k < c_NUMOFPAIRS; k++)
	{
		//generate a unique bolt/nut size
		int newSize = 0;
		do {
			newSize = rand() % (c_NUMOFPAIRS*10);
		} while (!is_in(newSize, bolts));

		//insert value into bolts at a random location
		int location = rand() % c_NUMOFPAIRS;
		while (bolts[location] != 0)
			location = (location + 1) % c_NUMOFPAIRS;
		bolts[k] = newSize;

		//insert value into nuts at a random location
		location = rand() % c_NUMOFPAIRS;
		while (bolts[location] != 0)
			location = (location + 1) % c_NUMOFPAIRS;
		nuts[k] = newSize;
	}
	//display starting arrays
	cout << "-----Original piles-----\nBolts\tNuts" << endl;
	for (int k = 0; k < c_NUMOFPAIRS; k++)
		cout << bolts[k] << "\t" << nuts[k] << endl;

}

bool is_in(const int value, const int ARR[])
{
	for (int k = 0; k < c_NUMOFPAIRS; k++)
		if (ARR[k] == value)
			return true;
	return false;
}