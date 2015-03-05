#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int list[], int n);
void insertion_sort(int list[], int n);
void selection_sort(int list[], int n);
void quick_sort(int list[],int first,int last);

int main()
{
    int n = 15;
    int c,menu;

    int list[15] = {2,3,5,34,54,65,76,87,-45,43,32,120,76,99,-21};
    printf("Type 1 for bubble sort\n");
    printf("Type 2 for insertion sort\n");
    printf("Type 3 for selection sort\n");
    printf("Type 4 for quick sort\n");
    printf(">>");

    scanf("%d",&menu);
    if(menu == 1)
    {
        //bubble sort example
        bubble_sort(list, n);
        printf("Bubble sorted list: \n");

        for ( c = 0 ; c < n ; c++ )
            printf("%d\n", list[c]);
    }
    else if(menu == 2)
    {
        //insertion sort example
        insertion_sort(list, n);
        printf(" insertion sorted list: \n");

        for ( c = 0 ; c < n ; c++ )
            printf("%d\n", list[c]);
    }
    else if(menu == 3)
    {
        //selection sort example
        selection_sort(list, n);
        printf("selection sorted list: \n");

        for ( c = 0 ; c < n ; c++ )
            printf("%d\n", list[c]);
    }
    else if(menu == 4)
    {
        //quick sort example
        quick_sort(list,0,n-1);
        printf("quick sorted list: \n");

        for ( c = 0 ; c < n ; c++ )
            printf("%d\n", list[c]);
    }
    else
    {
        printf("Are you an idiot? I said 1,2,3 or 4\n");
    }




    return 0;

}

// bubble sort stuff
void bubble_sort(int list[], int n)
{
    int i, j, temp;

    for (i = 0 ; i < ( n - 1 ); i++)
    {
        for (j = 0 ; j < n - i - 1; j++)
        {
            if (list[j] > list[j+1])
            {
                /* Swapping */

                temp      = list[j];
                list[j]   = list[j+1];
                list[j+1] = temp;
            }
        }
    }
}
// insertion sort stuff
void insertion_sort(int list[], int n)
{
    int i,j,temp;
    for (i = 1 ; i <= n - 1; i++)
    {
        j = i;

        while ( j > 0 && list[j] < list[j-1])
        {
            temp          = list[j];
            list[j]   = list[j-1];
            list[j-1] = temp;

            j--;
        }
    }

}

// selection sort stuff
void selection_sort(int list[], int n)
{
    int i,j,swap,position;

    for ( i = 0 ; i < ( n - 1 ) ; i++ )
    {

        position = i;

        for ( j = i + 1 ; j < n ; j++ )
        {
            if ( list[position] > list[j] )
                position = j;
        }
        if ( position != i )
        {
            swap = list[i];
            list[i] = list[position];
            list[position] = swap;
        }
    }


}
// quick sort stuff
void quick_sort(int list[],int first,int last)
{
    int pivot,j,temp,i;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;

        while(i<j)
        {
            while(list[i]<=list[pivot]&&i<last)
                i++;
            while(list[j]>list[pivot])
                j--;
            if(i<j)
            {
                temp=list[i];
                list[i]=list[j];
                list[j]=temp;
            }
        }

        temp=list[pivot];
        list[pivot]=list[j];
        list[j]=temp;
        quick_sort(list,first,j-1);
        quick_sort(list,j+1,last);

    }
}
