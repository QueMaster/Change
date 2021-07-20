// Change.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int change(int valDollarValue, int& refFifties, int&refTwenties, int& refTens, int& refFives, int& refOnes)
{
	//variable to store FEB
	int lowest = 0;

	//IF clause to determine the equivelent divisive bill
	if (valDollarValue % 50 == 0)
	{
		refFifties = valDollarValue / 50;
	} else if (valDollarValue % 20 == 0)
	{
		refTwenties = valDollarValue / 20;
	} else if (valDollarValue % 10 == 0)
	{
		refTens = valDollarValue / 10;
	}else if (valDollarValue % 5 == 0)
	{
		refFives = valDollarValue / 5;
	} else if (valDollarValue % 1 == 0)
	{
		refOnes = valDollarValue / 1;
	}

	//Check for the fewest equivelent bills (FEB)
	if (refFifties > 49 && refFifties < 60)
	{
		lowest = refFifties;
	} else if (refTwenties < refFifties)
	{
		lowest = refTwenties;
	} else if (refTens < refTwenties)
	{
		lowest = refTens;
	} else if (refFives < refTens)
	{
		lowest = refFives;
	} else if (refOnes < refFives)
	{
		lowest = refOnes;
	}

	return lowest;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int dollarValue;
	int lowest = 0, fifties = 0, twenties = 0, tens = 0, fives = 0, ones = 0;

	cout << "Please enter a dollar value: ";
	cin >> dollarValue;

	lowest = change(dollarValue,fifties,twenties,tens,fives,ones);

	//IF clause to determine the FEB
	if (lowest == fifties)
	{
		cout << endl << "The Fewest Equivelent Bill: " << fifties << " Fifties ($50)";
	} else if (lowest == twenties)
	{
		cout << endl << "The Fewest Equivelent Bill: " << twenties << " Twenties ($20)";
	} else if (lowest == tens)
	{
		cout << endl << "The Fewest Equivelent Bill: " << tens << " Tens ($10)";
	} else if (lowest == fives)
	{
		cout << endl << "The Fewest Equivelent Bill: " << fives << " Fives ($5)";
	} else if (lowest == ones)
	{
		cout << endl << "The Fewest Equivelent Bill: " << ones << " Ones ($1)";
	}

	system("pause");
	return 0;
}