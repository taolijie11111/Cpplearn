/**
 * @file 2.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//排序算法默写
//插入排序
using namespace std;
#include <stddef.h>
void InserSort(int* a,size_t n){
    for(size_t i=1;i<n;i++){
        int tmp=a[i];
        int end=i-1;
        while (end>=0)
        {        
        if(a[end]>tmp){
            a[end+1]=a[end];
            end--;
        }
        else{
            break;
        }
        }
        a[end+1]=tmp;
    }
}

//希尔排序
//gep不为1的排序
//不稳定，平均复杂度为O(n^(1.3))
void ShellInsort(int* a,int n){
    int gep=n;
    while (gep>1)
    {
        /* code */
        gep=gep/3+1;
        for(int i=1;i<n-gep;i++){
            int end=i;
            int tmp=a[end+gep];
            while (end>=0 && a[end]>tmp)
            {
                /* code */
                a[end+gep]=a[end];
                end=end-gep;
            }
            a[end+gep]=tmp;
        }
    }
    
}

#include <iostream>
//选择排序
void SelectSort(int* a,int n){
    int begin=0;
    int end=n-1;
    while (begin<end)
    {
        /* code */
        int max=begin,min=begin;
        for(int i=begin;i<=end;i++){
            if(a[min]>a[i]){
                min=i;//查找出最大最小的索引
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
//对里面的元素进行调整
void Adjust(int* a,int root, int n){
    int parent = root;
    int child = parent*2+1;
    while (child<n)
    {
        /* code */
        if((child+1)<n && a[child+1]>a[child]){
            ++child;
        }
        if(a[child]>a[parent]){
            swap(a[child],a[parent]);
            parent=child;
            child=parent*2+1;
        }
    }
}
int* heapsort(int* a,int n){
    for(int i=(n-2)/2;i>=0;i--){
        Adjust(a,i,n);
    }
    int end= n-1;
    while (end>0)
    {
        swap(a[0],a[end]);
        Adjust(a,0,end);
        end--;
    }
    
}

//冒泡排序
void BubbleSort(int* a,int n){
    int end=n;
    int exchange=0;
    while (end>0)
    {
        for(int i=1;i<end;i++){
            if(a[i-1]>a[i]){
                swap(a[i-1],a[i]);
                exchange=1;
            }
        }
        if(0==exchange){
            break;
        }
        end--;
    }
}
