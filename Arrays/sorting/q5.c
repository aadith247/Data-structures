//quick sort

#include<time.h>
#include<stdio.h>

void info(){
	time_t t;
	time(&t);
	printf("Harshit Srivastava\nBT23CSH051\n\n%s\n",ctime(&t));
	return;
}

// Function to take input from the user
void input(int n, int A[]) {
    printf("\n");
    for(int i = 0; i < n; i++) {
        printf("Enter element %d ... ", i + 1);
        scanf("%d", &A[i]);
    }
    return;
}

// Function to display elements of an array
void output(int n, int A[]) {
    for(int i = 0; i < n; i++) {
        printf("%d\t", A[i]);
    }
    printf("\n");
    return;
}

// Function to swap two integers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to partition the array and return the pivot index
int partition(int lb, int ub, int A[]) {
    int pivot = A[lb];
    int st = lb + 1;
    int en = ub;

    while (st <= en) {
        while (st <= ub && A[st] <= pivot) {
            st++;
        }
        while (en > lb && A[en] >= pivot) {
            en--;
        }
        if (st < en) {
            swap(&A[st], &A[en]);
        }
    }
    swap(&A[lb], &A[en]);
    return en;
}

// Function to perform quicksort on the array
void quick(int lb, int ub, int A[]) {
    if (lb < ub) {
        int loc = partition(lb, ub, A);
        quick(lb, loc - 1, A); // Recursively sort the left subarray
        quick(loc + 1, ub, A); // Recursively sort the right subarray
    }
    return;
}

int main() {
    info();
    int n;
    printf("Enter number of elements...");
    scanf("%d", &n);
    int A[n];
    printf("Enter elements...\n");
    input(n, A);
    printf("Entered array is...\n");
    output(n, A);
    quick(0, n - 1, A);
    printf("Sorted array is...\n");
    output(n, A);
    return 0;
}
