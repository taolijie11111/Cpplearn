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
//对于树这一块有一点新的认识，这个堆排序一知半解，继续吧
class HeapSort{
public:
    void AdjustDown(int *A,int root,int n){//从root到n弄一个堆排序
        int parent = root;
        int child = parent*2+1;
        while (child<n)
        {
            if((child+1)<n && A[child+1]>A[child]){
                ++child;
            }
            if(A[child]>A[parent]){
                swap(A[child],A[parent]);
                parent=child;
                child=parent*2+1;
            }
        }   
    }
    int* heapSort(int* A,int n){
        for(int i=(n-2)/2;i>=0;i--){
            AdjustDown(A,i,n);
        }
        int end = n-1;
        while (end>0)
        {
            swap(A[0],A[end]);
            AdjustDown(A,0,end);
            end--;
        }
        return A;
    }
private:
};

//冒泡排序
void BubbleSort(int* a,size_t n){
    size_t end=n;
    int exchange =0;
    while (end>0)
    {
        for(size_t i=1;i<end;i++){
            if(a[i-1]>a[i]){
            swap(a[i-1],a[i]);
            exchange=1;
            }
        }
        if(0==exchange){
            break;
        }
        --end;
    }
    
}

//快速排序
int PartSort1(int* a,int left,int right)
{
    int begin=left;
    int end=right;
    int key=right;

    while (begin<end)
    {
        while(begin < end && a[begin] <= a[key]){
            ++begin;
        }
        while (begin < end && a[end] >= a[key])
        {
            --end;
        }
        swap(a[begin],a[end]);
    }
    swap(a[begin],a[right]);
    return begin;
}

//归并排序
void __MergeSort(int* a,int left,int right,int* tmp){
    if(left >= right){
        return ;
    }
    // if(right-left+1 < 10){
    //     InsertSort(a+left,right-left+1);
    // }
    int mid=left+((right-left)>>1);
    __MergeSort(a,left,mid,tmp);
    __MergeSort(a,mid+1,right,tmp);

    //归并
    int begin1 = left,end1 = mid;
    int begin2 = mid+1,end2 = right;

    int index=left;

    while (begin1<=end1 && begin2<=end2)
    {
        if( a[begin1]<=a[begin2]){
            tmp[index++] =a[begin1++];
        }
        else{
            tmp[index++] = a[begin2++];
        }
    }
    while (begin1 <=end1)
    {
        tmp[index++]=a[begin1++];
    }
    while (begin2 <=end2)
    {
        tmp[index++]=a[begin2++];
    }
    
    index =left;
    while (index<=right)
    {
        a[index] = tmp[index];
        ++index;
    }
}
void MergeSort(int* a,size_t n){
    int* tmp=new int[n];
    __MergeSort(a,0,n-1,tmp);
    delete[] tmp;
}