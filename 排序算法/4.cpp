/**
 * @file 4.cpp
 * @author your name (you@domain.com)
 * @brief 
 * @version 0.1
 * @date 2022-03-30
 * 
 * @copyright Copyright (c) 2022
 * 
 */

//希尔排序
void Shellsort(int* a,int n){
    int gep=n;
    while (gep>1)
    {
        /* code */
        for (int i = 0; i < n-gep; i++)
        {
            int end=i;
            int tmp=a[end+gep];
            while (end>=0 && a[end]>tmp)
            {
                a[end+gep]=a[end];
                end-=gep;
            }
            a[end+gep]=tmp;
        }
        
    }
    
}
