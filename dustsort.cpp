#include "dustsort.h"

Dustsort::Dustsort()
{

}

void Dustsort::bubble_sort(int *arr, int n)
{
    int tmp;
    for(int i=0;i<n-1;i++)//i:0到n-2
    {
        for(int j=i;j<n-i;j++)//j:1到n-1
        {
            if(arr[j]>arr[j+1])
            {
                tmp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=tmp;
            }
        }
    }
}

void Dustsort::select_sort(int *arr, int n)
{
    int tmp;
    int* pmin;
    for(int i=0;i<n;i++)//i:0到n-1
    {
        pmin=&arr[i];
        for(int j=i+1;j<n;j++)//j:1到n-1
        {
            if(*pmin>=arr[j])
            {
                pmin=&arr[j];
            }
        }
        tmp=*pmin;
        *pmin=arr[i];
        arr[i]=tmp;
    }
}

void Dustsort::insert_sort(int *&arr, int &n)
{
    int tmp;
    for(int i=0;i<n-1;++i)
    {
        tmp=arr[i+1];
        for(int j=i+1;j>=0;--j)//从第二个元素即tmp的前面开始扫描
        {
            if(j==0||tmp>=arr[j-1])//直到j==0或者tmp大于j-1，停止扫描，并在停止扫描的元素后一位置插入tmp
            {
                arr[j]=tmp;
                break;
            }
            else//tmp小于j-1
            {
                //j-1后移一个位置，继续往前扫描
                arr[j]=arr[j-1];
            }
        }
    }
}

void Dustsort::shell_sort(int *arr, int n, int size)
{
    if(size>n)size=n;
    bool turn=false;
    for(int g=size;g<=n+size;g+= size)//为插入排序分组
    {
        if(turn)
            break;
        if(g>n)
        {
            //cout<<"g= "<<g<<endl;
            turn=true;
            g=n;
        }
        //cout<<"\ng= "<<g<<endl;
        insert_sort(arr,g);
    }
}

int Dustsort::setstep(int n, int count)
{
    int size;
    //...


    switch (count)
    {
    case 12:
        size=528;
        break;
    case 11:
        size=388;
        break;
    case 10:
        size=256;
        break;
    case 9:
        size=192;
        break;
    case 8:
        size=160;
        break;
    case 7:
        size=128;
        break;
    case 6:
        size=96;
        break;
    case 5:
        size=64;
        break;
    case 4:
        size=32;
        break;
    case 3:
        size=16;
        break;
    case 2:
        size=8;
        break;
    case 1:
        size=4;
        break;
    default:
        size=2;
        break;
    }

    return size;
}

void Dustsort::shell_sort2(int *arr, int n, psetstep fun,int count)
{
    bool turn=false;
    int size=fun(n,count);
    if(size>n||size<=0)size=n;

    for(int g=size;g<=n+size;g+=size)//为插入排序分组
    {
        if(turn)
            break;
        if(g>=n)
        {
            turn=true;
            g=n;
        }
        //cout<<"size="<<size<<"\tg= "<<g<<"\n"<<endl;
        insert_sort(arr,g);
        size=fun(n,--count);
    }
}

void Dustsort::print(int *arr, int n)
{

    int i;
    for(i=0;i<=n-1;i++)
    {
        cout<<arr[i]<<",";
    }
    cout<<"\n"<<endl;
}




