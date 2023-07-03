/*
*****************************************************************************
						  Workshop - #8 (P2)
Full Name  : Lucas Heck Acosta
Student ID#: 165041211
Email      : lheck-acosta@myseneca.ca
Section    : NKK
Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/



#define _CRT_SECURE_NO_WARNINGS


// System Libraries

#include <stdio.h>
// User Libraries
#include "w8p2.h"

data_struc food_struc;
report_struc table_struc;

// ----------------------------------------------------------------------------
// PART-1

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int* number)
{
	int intNumber;

	do
	{
		scanf("%d", &intNumber);
		if ((intNumber == 0) || (intNumber < 0))
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while ((intNumber == 0) || (intNumber < 0));

	if (number != NULL)
		*number = intNumber;
	return intNumber;
}

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double* number)
{
	double doublenumber;

	do
	{
		scanf("%lf", &doublenumber);
		if ((doublenumber == 0) || (doublenumber < 0))
		{
			printf("ERROR: Enter a positive value: ");
		}
	} while ((doublenumber == 0) || (doublenumber < 0));

	if (number != NULL)
		*number = doublenumber;
	return doublenumber;
}


// 3. Opening Message (include the number of products that need entering)
void openingMessege(item_number, servings)
{
	printf("Cat Food Cost Analysis\n");
	printf("======================\n\n");
	servings = SUGGESTED_G;
	printf("Enter the details for %d dry food bags of product data for analysis.\n", item_number);
	printf("NOTE: A 'serving' is %dg\n", servings);

}

// 4. Get user input for the details of cat food product
void getCatFoodInfo(item)
{
	int i;
	for (i = 0; i < item; i++)
	{
		printf("\nCat Food Product #%d\n", i + 1);
		printf("--------------------\n");
		printf("SKU           : ");
		food_struc.sku[i] = getIntPositive(0);
		printf("PRICE         : $");
		food_struc.price[i] = getDoublePositive(0);
		printf("WEIGHT (LBS)  : ");
		food_struc.weight[i] = getDoublePositive(0);
		printf("CALORIES/SERV.: ");
		food_struc.calories[i] = getIntPositive(0);


	}

}


// 5. Display the formatted table header
void displayCatFoodHeader(void)
{
	printf("\nSKU         $Price    Bag-lbs Cal/Serv\n");
	printf("------- ---------- ---------- --------\n");
}

// 6. Display a formatted record of cat food data

void displayCatFoodData(int sku, double price, double weight, int calories)
{
	printf("%07d %10.2lf %10.1lf %8d\n", sku, price, weight, calories);
}


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg (divide by 2.20462)
double convertLbsKg(const double* lbs, double* result)
{
	double kgs;
	kgs = (*lbs) / C_FACTOR;


	if (result != NULL)
	{
		*result = kgs;
	}

	return kgs;
}

// 9. convert lbs: g (call convertKG, then * 1000)
int convertLbsG(const double* lbs, int* result)
{
	double place_holder;
	if (result != NULL)
		place_holder = *result;
	int grams;
	grams = (int)(convertLbsKg(lbs, &place_holder) * 1000);

	if (result != NULL)
	{
		*result = grams;
	}

	return grams;
}

// 10. convert lbs: kg and g
void convertLbs(const double* lbs, double* result_kg, int* result_g)
{
	double kgs, place_holder_kg;
	kgs = convertLbsKg(lbs, &place_holder_kg);

	int grams, place_holder_g;
	grams = convertLbsG(lbs, &place_holder_g);

	if (result_kg != NULL)
	{
		*result_kg = kgs;
	}

	if (result_g != NULL)
	{
		*result_g = grams;
	}

}

// 11. calculate: servings based on gPerServ
double calculateServings(const int size, const int grams, double* address)
{
	double total;
	total = (double)size / (double)grams;
	if (address != NULL)
		*address = total;
	
	return total;
}

// 12. calculate: cost per serving
double calculateCostPerServing(const double* price, const double* number, double* address)
{
	double total = *price / *number;
	if (address != NULL)
		*address = total;

	return total;
}

// 13. calculate: cost per calorie
double calculateCostPerCal(const double* price, const double* calories, double* address)
{
	double total = *price / *calories;
	if (address != NULL)
		*address = total;

	return total;
}


// 14. Derive a reporting detail record based on the cat food product data

void calculateReportData(const int index)
{
	table_struc.sku[index] = food_struc.sku[index];
	table_struc.price[index] = food_struc.price[index];
	table_struc.weight_lb[index] = food_struc.weight[index];
	table_struc.weight_kg[index] = convertLbsKg(&table_struc.weight_lb[index], NULL);
	table_struc.weight_g[index] = convertLbsG(&table_struc.weight_lb[index], NULL);
	table_struc.calories[index] = food_struc.calories[index];
	table_struc.total_servings[index] = calculateServings(table_struc.weight_g[index], SUGGESTED_G, NULL);
	table_struc.cost_serving[index] = calculateCostPerServing(&table_struc.price[index], &table_struc.total_servings[index], NULL);
	double calories = table_struc.total_servings[index] * table_struc.calories[index];
	table_struc.cost_calorie[index] = calculateCostPerCal(&table_struc.price[index], &calories, NULL);

}

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void)
{
	printf("\nAnalysis Report (Note: Serving = %dg)\n", SUGGESTED_G);
	printf("---------------\n");
	printf("SKU         $Price    Bag-lbs     Bag-kg     Bag-g Cal/Serv Servings  $/Serv   $/Cal\n");
	printf("------- ---------- ---------- ---------- --------- -------- -------- ------- -------\n");
}

// 16. Display the formatted data row in the analysis table
void displayReportData(const int index, const int cheap) 
{
	printf("%07d %10.2lf %10.1lf %10.4lf %9d %8d %8.1lf %7.2lf %7.5lf", table_struc.sku[index], table_struc.price[index], table_struc.weight_lb[index], table_struc.weight_kg[index], table_struc.weight_g[index], 
		table_struc.calories[index], table_struc.total_servings[index], table_struc.cost_serving[index], table_struc.cost_calorie[index]);



	if (cheap != 0)
	{
		printf(" ***\n");
	}
	else
	{
		printf("\n");
	}

}

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const int sku, const double price)
{
	printf("\nFinal Analysis\n");
	printf("--------------\n");
	printf("Based on the comparison data, the PURRR-fect economical option is:\n");
	printf("SKU:%07d Price: $%.2lf\n", sku, price);
	printf("\nHappy shopping!\n");
}

// ----------------------------------------------------------------------------

// 7. Logic entry point
void start(void)
{
	openingMessege(N_PRODUCTS, SUGGESTED_G);
	getCatFoodInfo(N_PRODUCTS);
	displayCatFoodHeader();
	int i;
	for (i = 0; i < 3; i++)
	{
		displayCatFoodData(food_struc.sku[i], food_struc.price[i], food_struc.weight[i], food_struc.calories[i]);
		calculateReportData(i);
	}
	displayReportHeader();
	double cheapest = 100000;
	int cheapest_index;
	for (i = 0; i < 3; i++)
	{
		if (cheapest > table_struc.cost_serving[i])
		{
			cheapest = table_struc.cost_serving[i];
			cheapest_index = i;
		}
	}
	for (i = 0; i < 3; i++)
	{
		if (i == cheapest_index)
		{
			displayReportData(i, 1);
		}
		else
		{
			displayReportData(i, 0);
		}
	}

	displayFinalAnalysis(table_struc.sku[cheapest_index], table_struc.price[cheapest_index]);


}