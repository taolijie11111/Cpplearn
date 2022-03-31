#include <array>
using namespace std;
int PartSort(int* a,int left,int right){
    int begin=left;
    int end=right;
    int key=right;
    while (begin<end)
    {
        while (begin <end && a[begin]<=a[key])
        {
            /* code */
            ++begin;
        }
        while (begin < end && a[end] >=a[key])
        {
            /* code */
            --end;
        }
        swap(a[begin],a[end]);
    }
    swap(a[begin],a[right]);
    return begin;   
}
