#include "dustsort.h"



int main()
{
    int arr[]={7,30,15,21,4,23,8,20,5,27,0,18,6,29,13,16,31,3,15,12,22,1,24,10,19,2,26,9,28,14,17,11};

    const int n = sizeof(arr)/4;
    Dustsort dust;

    dust.print(arr,n);

    //insert_sort(arr,n);
    //bubble_sort(arr,n);
    //select_sort(arr,n);
    //shell_sort(arr,n,6);
    dust.shell_sort2(arr,n,dust.setstep,3);

    dust.print(arr,n);

    return 0;
}






