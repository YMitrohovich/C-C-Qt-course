#include <stdio.h>
#include <stdlib.h>
#include <time.h>	// Used 'time.h' to use 'clock ()' function.

#define STR_H "Here 4 types of sort algorithms (Bubble sort, Selection sort, Insertion sort and Quick sort) will be represented.\n\n\
The goal of sort algorithms is to sort 100 arrays of 100.000 random numbers from 0 to 10.000.000\n\
Keep in mind that the whole operation can take more than \e[93m80 min\e[0m.\n\n\
Press any key to start the sort test\n\n"

#define MAX_SIZE 100000		// Value of the array.
#define LOOP_VALUE 100		// Number of loops for sorting algorithms.

int bubble_sort (double *);	// Creating prototypes for sorting algorithms.
int select_sort (double *);
int insert_sort (double *);
int quick_sort (double *);
int time_sort (double *);

void qs (int *, int, int);

int count_bubble = 0;		// Initializing global variables to record data in the array elements.
int count_select = 0;
int count_insert = 0;
int count_qsort = 0;

int main () {

	double array_bubble [LOOP_VALUE];	// Initializing arrays for each sorting algorithm to store loop time.
	double array_select [LOOP_VALUE];
	double array_insert [LOOP_VALUE];
	double array_qsort [LOOP_VALUE];

	clock_t start, end;	// Initializing variables (start, end) to measure time in seconds

	printf (STR_H);		// Prints text defined above as a text constant.
	getchar ();

	start = clock ();	// Start to meassure total time of all algorithms.
	// '\a' - makes a sound when text appears. \e[94m - changes colour of the text, \e[0m - returns color to default.	
	printf ("\a\e[94mThe Bubble sort\e[0m is now opearating. Please, stand by\n\n");
	bubble_sort (array_bubble);	// Calls a sort function with array argument which will store time in future, now it's empty.

	printf ("\a\n\e[92mThe Selection sort\e[0m is now opearating. Please, stand by\n\n");	
	select_sort (array_select);

	printf ("\a\n\e[96mThe Insertion sort\e[0m is now opearating. Please, stand by\n\n");	
	insert_sort (array_insert);

	printf ("\a\n\e[95mThe Quick sort\e[0m is now opearating. Please, stand by\n\n");
	quick_sort (array_qsort);

	printf ("\n--- \e[94mBubble sort time info\e[0m ---\n");
	time_sort (array_bubble);	// When sorting is finished, time sort function will be called where all the gathered time will be sorted.

	printf ("\n--- \e[92mSelection sort time info\e[0m ---\n");
	time_sort (array_select);

	printf ("\n--- \e[96mInsertion sort time info\e[0m ---\n");
	time_sort (array_insert);

	printf ("\n--- \e[95mQuick sort time info\e[0m ---\n");
	time_sort (array_qsort);	
	end = clock ();		// End of total time meassuring.

	int total_time = (end - start + .0) / CLOCKS_PER_SEC;	// Transforms of processor tick rate into seconds and saving the value in the variable total_time.
	total_time = total_time/60;	// Divides total amount of seconds by 60 to get minutes.

	printf ("\nTotal time taken: \e[93m%d min\e[0m\n", total_time);
	printf ("\nFinished!\n");
}

int bubble_sort (double *array_bubble) {	// Bubble sort algorithm. The slowest. Avg. time ~ 30-32 seconds.
	
	srand (time(NULL));

	int array[MAX_SIZE];	// Initializing array with size 100.000 numbers.
	clock_t start, end;

	for (int i = 1; i <= LOOP_VALUE; i++) {		// 'for' loop will repeat sorting function 100 times (according to LOOP_VALUE) with new random numbers each time. 

		for (int i = 0; i < MAX_SIZE; i++) {	// Generates random numbers from 0 to 10.000.000 and records numbers in the 'array'
			array[i] = rand()%10000000;
		}

		start = clock ();	// Start of sort algorithm time measuring
		for (int i = 0; i < MAX_SIZE - 1; i++) {	// Start of sorting algorithm
			for (int j = 0; j < MAX_SIZE - i - 1 ; j++) {  
				if (array[j] > array[j + 1]) {
					int tmp = array[j]; 
					array[j] = array[j + 1] ;
					array[j + 1] = tmp; 
				}
			}
		}		// End of sorting algorithm
		end = clock ();		// End of time measuring

		double bubble_time = (end - start + .0) / CLOCKS_PER_SEC;	// Stores gathered time in 'double' array to get more percise data
		
		printf ("\tLoops remaining (%d/%d). Time of \e[93mloop %d\e[0m: \e[94m%f sec\e[0m\n", i, LOOP_VALUE, i, bubble_time);

		array_bubble [count_bubble] = bubble_time;	// Saves the gathered time in the array. 'count_bubble' represents array element
		count_bubble++;		// Changes array element to the next one
	}

	return array_bubble [count_bubble];	// When all sort runs are finished returns the time of all loops back
}

int select_sort (double *array_select) {	// Selection sort algorithm. Avg. time ~ 11-12 seconds.

	srand (time(NULL));

	int array[MAX_SIZE];
	clock_t start, end;

	for (int i = 1; i <= LOOP_VALUE; i++) {

		for (int i = 0; i < MAX_SIZE; i++) {
			array[i] = rand()%10000000;
		}

		int x[MAX_SIZE];	// Varibles, required for the sort algorithm
		long n, j, k;

		start = clock ();
		for(n = 0; n < MAX_SIZE; n++) {
			k = n;
			x[n] = array[n];
			for( j = n + 1; j < MAX_SIZE; j++)
				if (array[j] < x[n]) {
					k = j;
					x[n] = array[j];
				}
			array[k] = array[n];
			array[n] = x[n];
		}
		end = clock ();

		double select_time = (end - start + .0) / CLOCKS_PER_SEC;
		
		printf ("\tLoops remaining (%d/%d). Time of \e[93mloop %d\e[0m: \e[92m%f sec\e[0m\n", i, LOOP_VALUE, i, select_time);

		array_select [count_select] = select_time;
		count_select++;
	}

	return array_select [count_select];	

}

int insert_sort (double *array_insert) {	// Insertion sort algorithm. Quite unstable. Avg. time ~ 7-12 seconds.
	
	srand (time(NULL));

	int array[MAX_SIZE];
	clock_t start, end;

	for (int i = 1; i <= LOOP_VALUE; i++) {

		for (int i = 0; i < MAX_SIZE; i++) {
			array[i] = rand()%10000000;
		}

		int a, key, j;		// Varibles, required for the sort algorithm

		start = clock ();
		for (a = 1; a < MAX_SIZE; a++) { 
			key = array[a]; 
			j = a - 1;  
			while (j >= 0 && array[j] > key) { 
				array[j + 1] = array[j]; 
				j = j - 1; 
			} 
			array[j + 1] = key; 
		} 
		end = clock ();

		double insert_time = (end - start + .0) / CLOCKS_PER_SEC;
		
		printf ("\tLoops remaining (%d/%d). Time of \e[93mloop %d\e[0m: \e[96m%f sec\e[0m\n", i, LOOP_VALUE, i, insert_time);

		array_insert [count_insert] = insert_time;
		count_insert++;
	}

	return array_insert [count_insert];
}

int quick_sort (double *array_qsort) {		// Quick sort (T.Hoare sort) algorithm. The fastest algorithm represented in the program. Avg. time ~ 0.013-0.016 seconds.

	srand (time(NULL));

	int array[MAX_SIZE];
	clock_t start, end;

	for (int i = 1; i <= LOOP_VALUE; i++) {

		for (int i = 0; i < MAX_SIZE; i++) {
			array[i] = rand()%10000000;
		}

		start = clock ();
		qs (array, 0, MAX_SIZE - 1);		// Calls the actual Quick sort function
		end = clock ();

		double qsort_time = (end - start + .0) / CLOCKS_PER_SEC;
		
		printf ("\tLoops remaining (%d/%d). Time of \e[93mloop %d\e[0m: \e[95m%f sec\e[0m\n", i, LOOP_VALUE, i, qsort_time);

		array_qsort [count_qsort] = qsort_time;
		count_qsort++;
	}

	return array_qsort [count_qsort];	
}

void qs (int *array, int first, int last) {	// Actual Quick sort algorithm

	if (first < last) {
		int left = first, right = last, middle = array[(left + right) / 2];
		do {
			while (array[left] < middle) left++;
			while (array[right] > middle) right--;
           
			if (left <= right){
				int tmp = array[left];
				array[left] = array[right];
				array[right] = tmp;
				left++;
				right--;
			}
		} while (left <= right);

	qs (array, first, right);
	qs (array, left, last);
	}
}

int time_sort (double *array_time) {		// Time sort function. Sorts the gathered time from other functions and divides it in the best, worst and average time. Used Bubble sort algorithm.

	double sum = 0;		// Variable 'sum' collects the summary of all time stored in the array
	for (int i = 0; i < LOOP_VALUE; i++)
		sum += array_time[i];

	sum = sum/LOOP_VALUE;	// The value of 'sum' divided by number of loops to get average time

	for (int i = 0; i < LOOP_VALUE - 1; i++) {
		for (int j = 0; j < LOOP_VALUE - i - 1 ; j++) {  
			if (array_time[j] > array_time[j + 1]) {
				double tmp = array_time[j]; 
				array_time[j] = array_time[j + 1] ;
				array_time[j + 1] = tmp; 
			}
		}
	}

	double MIN = array_time[0];	// After sorting of the array is finished, initializing 'MIN' variable that stores the best time of the array 
	double MAX = array_time[0];	// Variable 'MAX' will store the worst time of the array. For now value will be the same as 'MIN'

	for (int i = 1; i < LOOP_VALUE; i++) {		// 'for' loop is used to go through the whole array to find the worst time there. At the end 'MAX' will store the worst time
		if (MAX < array_time[i]) MAX = array_time[i];
	}

	printf ("Best time: %f sec \tWorst time: %f sec \tAverage time: %f sec\n", MIN, MAX, sum); 	// Prints the best, the worst and the average time from the array		
}
