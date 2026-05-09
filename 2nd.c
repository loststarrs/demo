#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function using the first element as pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= j && arr[i] <= pivot)
            i++;
        while (i <= j && arr[j] >= pivot)
            j--;
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

// Recursive Quicksort function
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

int main()
{
    int a[500000], i, n, m, ch, c, j=0, p;
    double extime;

    FILE *fp, *fp1;

    clock_t start, end;

    while(1)
    {
        printf("\n1. Quick Sort");
        printf("\n2. Record execution time");
        printf("\n3. Exit");

        printf("\nEnter your choice : ");
        scanf("%d",&ch);

        switch(ch)
        {

            // -------- QUICK SORT --------
            case 1:

                printf("Enter number of elements : ");
                scanf("%d",&n);

                j = 0;

                // Generate random numbers
                fp = fopen("input.txt","w");

                for(i=0;i<n;i++)
                {
                    m = rand()%10000;
                    fprintf(fp,"%d\t",m);
                }

                printf("\nRandom numbers stored in input.txt\n");

                fclose(fp);

                // Read numbers into array
                fp = fopen("input.txt","r");

                while(fscanf(fp,"%d",&c)!=EOF)
                {
                    a[j++] = c;
                }

                fclose(fp);

                // Sorting
                

                quicksort(a,0,n-1);

                

                extime = (double)(end-start)/CLOCKS_PER_SEC;

                printf("\nExecution time : %lf\n",extime);

                // Store sorted elements
                fp = fopen("output.txt","w");

                for(i=0;i<n;i++)
                {
                    fprintf(fp,"%d\t",a[i]);
                }

                fclose(fp);

                printf("Sorted elements stored in output.txt\n");

                break;

            // -------- TIME ANALYSIS --------
            case 2:

                fp1 = fopen("plot.dat","w");

                for(p=10000;p<=100000;p+=10000)
                {

                    for(i=0;i<p;i++)
                    {
                        a[i] = rand()%10000;
                    }

                    start = clock();

                    quicksort(a,0,p-1);

                    end = clock();

                    extime = (double)(end-start)/CLOCKS_PER_SEC;

                    printf("n = %d\tTime = %lf\n",p,extime);

                    fprintf(fp1,"%d\t%lf\n",p,extime);
                }

                fclose(fp1);

                printf("\nData stored in plot.dat\n");

                break;

            // -------- EXIT --------
            case 3:

                exit(0);

            default:

                printf("Invalid choice\n");
        }
    }

    return 0;
}
