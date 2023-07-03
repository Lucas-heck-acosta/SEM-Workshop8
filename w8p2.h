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


// ----------------------------------------------------------------------------
// defines/macros
#define N_PRODUCTS 3
#define SUGGESTED_G 64
#define C_FACTOR 2.20462


// ----------------------------------------------------------------------------
// structures



typedef struct CatFoodInfo
{
	int sku[N_PRODUCTS];
	double price[N_PRODUCTS];
	int calories[N_PRODUCTS];
	double weight[N_PRODUCTS];
} data_struc;

typedef struct ReportData
{
	int sku[N_PRODUCTS];
	double price[N_PRODUCTS];
	int calories[N_PRODUCTS];
	double weight_lb[N_PRODUCTS];
	double weight_kg[N_PRODUCTS];
	int weight_g[N_PRODUCTS];
	double total_servings[N_PRODUCTS];
	double cost_serving[N_PRODUCTS];
	double cost_calorie[N_PRODUCTS];
} report_struc;


// ----------------------------------------------------------------------------
// function prototypes

// 1. Get user input of int type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
int getIntPositive(int*);

// 2. Get user input of double type and validate for a positive non-zero number
//    (return the number while also assigning it to the pointer argument)
double getDoublePositive(double*);

// 3. Opening Message (include the number of products that need entering)
void openingMessage(const int, const int);

// 4. Get user input for the details of cat food product
void getCatFoodInfo(const int);

// 5. Display the formatted table header
void displayCatFoodHeader(void);

// 6. Display a formatted record of cat food data
void displayCatFoodData(const int, const double, const double, const int);


// ----------------------------------------------------------------------------
// PART-2

// 8. convert lbs: kg
double convertLbsKg(const double*, double*);

// 9. convert lbs: g
int convertLbsG(const double*, int*);


// 10. convert lbs: kg / g
void convertLbs(const double*, double*, int*);


// 11. calculate: servings based on gPerServ
double calculateServings(const int, const int, double*);

// 12. calculate: cost per serving
double calculateCostPerServing(const double*, const double*, double*);


// 13. calculate: cost per calorie
double calculateCostPerCal(const double*, const double*, double*);


// 14. Derive a reporting detail record based on the cat food product data
void calculateReportData(const int);

// 15. Display the formatted table header for the analysis results
void displayReportHeader(void);

// 16. Display the formatted data row in the analysis table
void displayReportData(const int, const int);

// 17. Display the findings (cheapest)
void displayFinalAnalysis(const int, const double);

// ----------------------------------------------------------------------------

// 7. Logic entry point 
void start(void);