#include <stdio.h>
#define GRADE 100
int choose, flag = 0, n, counter = 1, src, flag2 = 0;

//
void greet();
void shortingArr(int[], int);
void showGrade(int[], int);
void showGradeB(int[], int);
void search(int[], int, int);

int error();

int main()
{
	int arr[GRADE];	 // array utama
	int arrB[GRADE]; // array untuk disimpan (before)

	do
	{
		printf("\n\nthese are the grades now: \n");
		if (flag != 0)
		{
			showGrade(arr, n);
		}
		else
			printf("you're not input any grades\n\n");

		greet();
		if (scanf("%d", &choose) != 1)
			return error();

		switch (choose)
		{
		case 1:
			flag = 1; // turn-on flag1
			printf("input how much grades did you want to input: ");
			if (scanf("%d", &n) != 1)
				return error(); // when input not int, clossed
			for (int i = 0; i < n; i++)
			{
				printf("Enter grade %d (0 - 100): ", i + 1);
				while (scanf("%d", &arr[i]) != 1 || arr[i] < 0 || arr[i] > 100) // when input are not beetween 0 - 100, input again
				{
					printf("Invalid! Enter a number between 0 - 100: \n");
					printf("Enter grade %d (0 - 100): ", i + 1);
				}
				arrB[i] = arr[i];
			}
			flag2 = 0; // return flag2 into 0
			break;

		case 2:
			if (flag != 0)
			{ // untuk shorting
				flag2 = 1; // turn on the flag2
				shortingArr(arr, n);
				break;
			}
			else
				printf("you are not input any grades");
			break;

		case 3:
			if (flag != 0 && flag2 != 0)
			{ // untuk mencari
				printf("Enter number to search: ");
				while (scanf("%d", &src) != 1 || src < 0 || src > 100)
				printf("invalid grades value to search!!\n(search a grades between 0 - 100): ");
					search(arr, n, src);
				break;
			}
			else
			{
				printf("=== Please input the grades and shorting it ===");

				break;
			}

		case 4:
			if (flag2 == 1 && flag != 0) // only after shorting and after input
			{ // untuk menampilkan sebelum before dan setelah after
				for (int i = 0; i < n; i++)
				{
					printf("=="); // for cool stuff
				}
				showGradeB(arrB, n);
				printf("\n");
				printf("here's your grades after: \n");
				showGrade(arr, n);
				for (int i = 0; i < n; i++)
				{
					printf("=="); // for cool stuff
				}
				break;
			}
			else
			{
				printf("== you are not input any grades and not shorting it ==");
				break;
			}

		case 5:
			printf("\n== thank you ==");
			counter = 0;
			break;
		default:
			printf("input not valid");
			break;
		}
	} while (counter != 0);
	return 0;
}

void greet()
{

	printf("== Choose menu here ==\n");
	printf("1. input or change array\n");
	printf("2. shorting the grade now\n");
	printf("3. searching the grade\n");
	printf("4. displaying grade before and after shorting\n");
	printf("5. exit\n");
	printf("Choose: ");
};

void showGradeB(int gradeB[GRADE], int sizeB)
{
	printf("\nThese are your grade before:\n");
	for (int j = 0; j < sizeB; j++)
		printf("%d ", gradeB[j]);
	printf("\n");
}
void showGrade(int gradeA[GRADE], int sizeA)
{
	for (int k = 0; k < sizeA; k++)
		printf("%d ", gradeA[k]);
	printf("\n");
}

void shortingArr(int a[], int aSize)
{
	int h, i, j;
	for (i = 1; i < aSize; i++)
		for (j = 0; j < aSize - 1; j++)
			if (a[j] > a[j + 1])
			{
				h = a[j];
				a[j] = a[j + 1];
				a[j + 1] = h;
			}
}

int error()
{
	printf("\nProgram error or data is not integer, program clossed\n");
	return 1;
}

void search(int a[], int n, int value){
	int low = 0, high = n-1;
	int found = 0;
	
	while(low <= high){
	int mid = (low+high)/2;
		if(a[mid] == value){
		printf("\n===========================\n");
		printf("your grades are in index: %d\nand in the position: %d", mid, mid+1);
		printf("\n===========================\n");
		return; }
		else if(a[mid] < value)
			low = mid + 1;
		else
		 high = mid - 1;
	} printf("== Grades not found!! ==");
	
}


