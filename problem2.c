#include <stdio.h>

// declare function for compiler know it
// void doesnt return anything, datatype return
void sortPrices(float prices[], int n);
int findPrice(float prices[], int n, float target);
float findMax(float prices[], int n);
float findMin(float prices[], int n);
void displayPrices(float prices[], int n);

int main(void)
{
    int n, i;          // n for total input product, i for loop counter
    float searchPrice; // variable for store price when user search
    int searchResult;  // variable for store index result

    // this for input total product
    printf("=== Product Prices Inventory ===\n"); // it will display/print output in the string ""
    printf("Enter number of products : ");        // will display too but can type/input bcs there is a scanf for input
    // if doesnt success read 1 input so
    if (scanf("%d", &n) != 1) //(!= 1: if not equal 1) return 0 = mean exit
        return 0;

    // if user input less than equal 0 or like -1 etc.(or negative), will display
    if (n <= 0)
    {
        printf("Number of products must be positive\n"); // thiss output in string
        return 0;
    }

    // its array without size declaration
    float prices[n];

    // for input price for all product
    for (i = 0; i < n; i++)
    {                                                  // start i=0, if i(0) less than n value, loop i (i+1) until i not less than n
        printf("Enter price for product %d: ", i + 1); // print string enter price for product + value i but + 1 bcs array start from 0 and it not human behavior so +1 and i will start from 1
        // ex: n=3, i+1= 1, i+1= 2, i+1=3, so it will print the string enter price for product + value i+1 until i not less than n(3).
        //		        Enter price for product 1:
        //		        Enter price for product 2:
        //		        Enter price for product 3:
        //				the output will look like this

        //			scanf listen/read user input
        if (scanf("%f", &prices[i]) != 1)
            //      if success read 1 float numb, result=1
            return 0; // return 0 if fail
        //		if price at index i is less than or equal to zero, then
        if (prices[i] <= 0)
        {
            printf("Price must be positive. Try again.\n"); // print this/display this
            i--;                                            // cancel increment, and force loop
        }
    }

    //	display price before sorting
    printf("==== Original Prices ====\n");
    displayPrices(prices, n);

    //	find max and min
    // call function for search highest prices
    float maxPrice = findMax(prices, n);
    // call function for search lowest prices
    float minPrice = findMin(prices, n);

    printf("\nMost expensive product: %.2f\n", maxPrice); // print string most expensive product + value func maxPrice
    printf("Least expensive product: %.2f\n", minPrice);  // display output most expensive product and value func minPrice

    //	print prices after descending order
    printf("==== Sorting Prices Descending ====\n");
    //	call func for descending
    sortPrices(prices, n);
    printf("Prices sorted successfully!\n"); // print this

    //	print prices before descending
    printf("==== Sorted Prices Descending ====\n");
    displayPrices(prices, n);

    // searching price
    printf("\n==== Search for a Price ====\n"); // display this
    printf("Enter price to search: ");          // print this
    if (scanf("%f", &searchPrice) != 1)
        return 0; // if success read 1 float numb, result=1

    //  call funct for searching prices
    searchResult = findPrice(prices, n, searchPrice);

    // check searchin result
    if (searchResult == -1)
    {
        //  if searchResult is -1 (not found)
        printf("Price %.2f not found in inventory.\n", searchPrice); // print this + input searchPrice usernya
    }
    else
    {
        // 	if found, show index position
        printf("Price %.2f found at position %d (index %d).\n", searchPrice, searchResult + 1, searchResult); // print Price + input searchPrice user, found at position searchResult +1, + searchResult
    }

    printf("\nthank you for using the inventory system!\n");
    return 0;
}

// function sort price
// sort array prices descending
void sortPrices(float prices[], int n)
{
    int i, j;   // counter for nested loop
    float temp; // temporary variable for swap
                // bubble sort
    // outer loop
    for (i = 0; i < n - 1; i++)
    {
        //	start i=0, if i less than n-1, loop i i+1 until i not less than n-1
        // inner loop
        for (j = 0; j < n - 1 - i; j++)
        {
            //		start j=0, if j less than (n-1-i), loop j (j+1) until j not less than (n-1-i)
            //			if left less than right, swap. soo it will be swap untill it descending (bigger number in left)
            if (prices[j] < prices[j + 1])
            {
                //            	bcs it swap 2 variables, its need temporary variable. like swapping drinks between 2 cups and need 3rd cup
                temp = prices[j];          // save prices j to temp
                prices[j] = prices[j + 1]; // move prices j+1 to prices j
                prices[j + 1] = temp;      // move temp to prices j+1
            }
        }
    }
}

// search target price from array prices
//			 prices array, size of array, price want to find
int findPrice(float prices[], int n, float target)
{
    int i; // counter for loop

    // linear search algorithm
    //   check every element one by one from start to end
    for (i = 0; i < n; i++)
    {
        // start i=0, if i less than n, loop i (i+1) until i not less than n
        //       if prices at index i already equal to target
        if (prices[i] == target)
        {
            return i; // return the index
        }
    }

    return -1; // if loop end whithout finding anything, return notfounf
}

// find highest prices
//              array prices, size of array
float findMax(float prices[], int n)
{
    int i; // counter loop
    // first elemen is the max
    float max = prices[0];
    //      start i=1, bcs index 0 already max)
    for (i = 1; i < n; i++)
    { // if i less than n, loop i (i+1) until i not less than n
        if (prices[i] > max)
        {                    // if i more than current max
            max = prices[i]; // update max with new prices
        }
    }
    // return real price value
    return max;
}

// find lowest prices
//              array prices, size of array
float findMin(float prices[], int n)
{
    int i; // counter for loop
    // first elemen is the lowest
    float min = prices[0];
    //  start i=1, bcs index 0 already max)
    for (i = 1; i < n; i++)
    {
        if (prices[i] < min)
        {                    // if i less than current min
            min = prices[i]; // update min with new prices
        }
    }

    return min; // return lowest price
}

void displayPrices(float prices[], int n)
{
    int i; // counter loop
    //  start i=0, if i less than n, loop i (i+1) until i not less than n
    for (i = 0; i < n; i++)
    {
        printf("Product %d: %.2f\n", i + 1, prices[i]); // print this + i+1, + value prices i
    }
}