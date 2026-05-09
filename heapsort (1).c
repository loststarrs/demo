#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int *a,int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void heapify(int H[], int n, int low){
    int i,j,k,v,heap;
    for(i = n/2; i >= low; i--){
        k = i;
        v = H[k];
        heap = 0;

        while(!heap && (2*k) <= n){
            j = 2*k;

            if(j < n){
                if(H[j] < H[j+1])
                    j = j+1;
            }

            if(v >= H[j])
                heap = 1;
            else{
                H[k] = H[j];
                k = j;
            }
        }

        H[k] = v;
    }
}

void heapsort(int H[], int n){
    int i;
    heapify(H, n, 1);

    for(i = n; i >= 2; i--){
        swap(&H[1], &H[i]);
        heapify(H, i-1, 1);
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
        printf("1. Heap sort \n 2. Recording time for different n \n 3. Exit \n");
        printf("Enter your choice :");
        scanf("%d",&ch);

        switch(ch)
        {
            case 1:
                printf("Enter the number of elements to be sorted:");
                scanf("%d",&n);

                j = 0; // IMPORTANT reset

                fp = fopen("input.txt","w");
                for(i=0;i<n;i++)
                {
                    m = rand()%10000;
                    fprintf(fp,"%d\t",m);
                }
                printf("\n Random numbers generated are stored in file \n");
                fclose(fp);

                fp = fopen("input.txt","r");
                while(fscanf(fp,"%d",&c)!=EOF)
                    a[++j] = c;   // 1-based indexing for heap

                fclose(fp);

                heapsort(a, j);  // use heap sort

                fp = fopen("output.txt","w");
                for(i=1;i<=j;i++)
                    fprintf(fp,"%d\t",a[i]);

                printf("Sorted elements are stored in file\n");
                fclose(fp);

                break;

            case 2:
                for(p=10000;p<=100000;p+=10000)
                {
                    for(i=1;i<=p;i++)   // 1-based indexing
                    {
                        m = rand()%10000;
                        a[i] = m;
                    }

                    fp1 = fopen("plot.dat","a");

                    start = clock();
                    heapsort(a, p);   // heap sort timing
                    end = clock();

                    extime = (double)(end-start)/CLOCKS_PER_SEC;

                    printf("\nExecution time : %f\n",extime);
                    fprintf(fp1,"%d\t%lf\n",p,extime);

                    fclose(fp1);
                }
                break;

            case 3:
                exit(0);
        }
    }

    return 0;
}
