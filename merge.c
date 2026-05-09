#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void merge(int a[],int low,int mid,int high)
{
  int i=low, j=mid+1, k=0;
  int c[500000];
  while(i<=mid && j<=high)
  {
    if(a[i] <a[j])
      c[k++]=a[i++];
    else
      c[k++]=a[j++];
   }
  while(i<=mid)
    c[k++]=a[i++];
  while(j<=high)
    c[k++]=a[j++];
  for(i=low, j=0;i<=high;i++, j++)
    a[i]=c[j];
 }
 
 
void MergeSort(int a[], int low, int high)
  {
     int mid;
      if(low >=high) return;
      else
        {
          mid=(low+high)/2;
          MergeSort(a,low,mid);
          MergeSort(a, mid+1, high);
          merge(a,low,mid,high);
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
    printf("1. Merge sort \n 2. Recording time for differnt n \n 3. Exit \n");
    printf("Enter your choice :");
    scanf("%d",&ch);
    switch(ch)
     {
       case 1 : printf("Enter the number of elements to be sorted:");
                scanf("%d",&n);
                fp=fopen ("input.txt","a");
                for(i=0;i<n;i++)
                 {
                  m=rand()%10000;
                  fprintf(fp,"%d\t",m);
                 }
                 printf("\n Random numbers generated are stored in file \n");
                 fclose(fp);
                 fp=fopen("input.txt","r"); 
                 while(fscanf(fp,"%d", &c)!=EOF)
                     a[j++]=c;
                     
                  fclose(fp);
                  MergeSort(a,0,n-1);
                  fp=fopen("output.txt","w");
                  for(i=0;i<n;i++)
                    fprintf(fp,"%d\t", a[i]);
                    printf("Sorted elements are stored in file\n");
                    fclose(fp);
                    
                    break;
        case 2:
                for(p=10000;p<=100000;p+=10000)
                {
                  for(i=0;i<p;i++)
                 {
                  m=rand()%10000;
                  a[i]=m;
                  //printf("%d",m);
                 }
                 //for(i=0;i<n;i++)
                  //printf("%d", a[i]);
                fp1=fopen("plot.dat","w");
                start=clock();
                MergeSort(a,0,p-1);
                end=clock();
                extime=(double)(end-start)/CLOCKS_PER_SEC;
                printf("\nExecution time : %f\n",extime);
                fprintf(fp1,"%d\t%lf\n",p,extime);
                fclose(fp1);
              
               }
               break;
               case 3:exit(0); 
       }//end of switch
     }//end of while(1)
  
  return 0;
  } //end of main
  
  
          
