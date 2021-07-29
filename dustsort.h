#ifndef DUSTSORT_H
#define DUSTSORT_H

#include <iostream>
using namespace std;

 ///均为升序排序
typedef int (*psetstep)(int,int);
class Dustsort
{
public:
    Dustsort();

    ///*
    /// 依次比较相邻的两个元素，前一元素比后一元素大就交换
    ///
    ///*/
    void bubble_sort(int* arr,int n);
    ///*
    ///
    /// 1、把首元当作最小元素将其地址记作pmin
    /// 2、从第二个元素起依次和*pmin比较，若大于*pmin，则把该元素地址赋给pmin
    /// 3、一轮比较完成后，pmin指向最小元素的地址,
    /// 4、将pmin指向的元素和未经排序部分的第一个元素交换
    /// 5、重复2~4步骤
    ///
    ///*/
    void select_sort(int* arr,int n);
    ///*
    ///
    /// 1、把第一个元素当作已经排好序的部分
    /// 2、从第二个元素即tmp的前面开始扫描
    /// 3、直到j==0或者tmp大于j-1，停止扫描，并在停止扫描的元素后一位置插入tmp
    /// 4、重复步骤3，直到在已排序的元素中找到小于或等于A的元素，将A插入到这个元素的后面
    /// 5、重复步骤2~5
    ///
    ///*/
    void insert_sort(int* &arr,int &n);
    ///*
    ///
    /// 固定分组长度的希尔排序
    /// 1、先将arr[n]拆分成若干个只有两个元素的组，落单的一个独自成组，分别对每个组进行排序
    /// 2、然后每两个小组合并成更多元素的组，落单的一个独自成组，分别对每个组进行排序
    /// 重复1~2步骤
    /// size为设定的固定分组的大小，若size>n或size<=0,则退化为插入排序
    ///
    ///*/
    void shell_sort(int* arr,int n,int size);

    ///*
    /// 可自由自定义分组长度的希尔排序
    /// count：分组长度的变化次数
    /// 返回值：返回变化长度的分组的第一次的长度
    ///
    /// 此函数可由用户视情况自由定义
    ///*/
    static int setstep(int n,int count);
    ///*
    /// arr:数组名
    /// n:数组的元素数目
    /// pfun:回调函数，旨在自由设定可变长希尔排序分组的长度
    /// count:分组长度的变化次数
    ///*/
    void shell_sort2(int* arr,int n, psetstep pfun,int count=3);


    void print(int* arr,int n);

private:
    int count;
};

#endif // DUSTSORT_H
