/**
 * @file 3.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//插入排序
//稳定的排序
//分布有序时
using namespace std;
void InsertSort(int* a,int n){
    for(int i=1;i<n;i++){
        int tmp=a[i];
        int end=i-1;
        while (end>=0)
        {
            if(a[end]>tmp){
                a[end+1]=a[end];//相当于把元素后移
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
void Shellsort(int* a,int n){
    int gep=n;
    while (gep>1)
    {
        gep=gep/3+1;
        for(int i=0;i<n-gep;i++){
            int end=i;
            int tmp=a[end+gep];
            while(end>=0 && a[end]>tmp)
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
            if(a[max]<a[i]){
                max=i;
            }
            if(a[min]>a[i]){
                min=i;
            }
        }
        swap(a[min],a[begin]);
        if(begin==max){
            max=min;
        }
        swap(a[max],a[end]);
        begin++;
        end--;
    }
    
}

//堆排序
/*
堆排序的基本思想是：将待排序序列构造成一个大顶堆，此时，整个序列的最大值就是堆顶的根节点。将其与末尾元素进行交换，此时末尾就为最大值。然后将剩余n-1个元素重新构造成一个堆，这样会得到n个元素的次小值。如此反复执行，便能得到一个有序序列了
*/

//所以，树就只是一种方法，一种很奇妙的“方法”，一种结构，妙阿

void Adjust(int* a,int root,int n){
    int parent=root;
    int child=parent*2+1;
    while (child<n)
    {
        /* code */
        if((child+1)<n && a[child+1]>a[child]){
            ++child;
        }
        if(a[parent]<a[child]){
            swap(a[parent],a[child]);
            parent=child;
            child = parent*2+1;
        }
    }
}
void heapsort(int* a,int n){//这一步是构造大顶堆的过程
    for(int i=(n-2)/2;i>=0;i--){
        Adjust(a,i,n);
    }
    int end=n-1;
    while (end>0)//这一步是进行输出
    {
        swap(a[0],a[end]);
        Adjust(a,0,end);
        end--;
    }
}

