/**
 * @file one.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#include <iostream>
using namespace std;

//插入排序
//n比较小
//当元素分布有序，直接插入排序将大大减少比较次数和移动记录的次数。
//稳定
void InsertSort(int* a, size_t n){
for(size_t i=1;i<n;i++){
    int end=i-1;
    int tmp=a[i];
    while (end>=0)
    {
        if(a[end]>tmp){
            a[end+1]=a[end];
            --end;
        }else{
            break;
        }
    }
    a[end+1]=tmp;
}
}

//希尔排序
//不稳定
void ShellSort(int* a,size_t n){
    int gap=n;
    while (gap>1)
    {
        gap=gap/3+1;
        for(size_t i=0;i<n-gap;i++){
            int end=i;
            int tmp=a[end+gap];
            while (end>=0 && a[end]>tmp)
            {
                a[end+gap]=a[end];
                end-=gap;
            }
            a[end+gap] =tmp;   
        }
    }
    
}

//选择排序
void SelectSort(int *a,size_t n){
    int begin=0;
    int end=n-1;
    while (begin<end)
    {
        int min=begin,max=begin;
        for(int i=begin;i<end;i++){
            if(a[min]>a[i]){
                min=i;
            }
            if(a[max]<a[i]){
                max=i;
            }
        }
        swap(a[min],a[begin]);
        if(max==begin){
            max=min;
        }
        swap(a[max],a[end]);
        begin++;
        end--;
    }
}

//堆排序