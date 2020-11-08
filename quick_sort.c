/*quick sort for C*/
/*
 *date: 20200626
 *version: 1.0
 *author: supermarry
*/

#include <stdio.h>

#define BUF_SIZE 10

/*****************************************************************
 *函数名：display
 *作用：打印数组元素
 *参数：array - 打印得数组 ；maxlen - 数组元素个数
 *返回值： 无
 ****************************************************************/
void display(int array[], int maxlen)
{
    int i = 0;

    for(i; i < maxlen; i++) {
        printf("%-3d", array[i]);
    }
    printf("\n");

    return;
}

/*
原理：
通过一趟排序将要排序的数据分割成独立的两部分，其中一部分的所有数据都比另外一部分的所有数据都要小，然后再按此方法对这两部分数据分别进行快速排序，整个排序过程可以递归进行，以此达到整个数据变成有序序列。

先假设第一个元素为轴值，自右向左找一个比轴值小的数交换，再自左向右找一个比轴值大的数交换，再重复自右向左找一个比轴值小的数交换，自左向右找一个比轴值大的数交换，直到轴值左边没有比其大的数存在，右边也没有比其小的数存在，则第一轮结束。原来的一组数据被划分为以轴值为界的两组新数据
第二轮：取上一轮轴值左边的一组新数据，重复1的操作；取上一轮轴值右边的一组新数据，重复1的操作，则把最初的一组数据分成了四部分，这样便产生一个递归的思想
一直重复操作，直到数据被分的不可再分为止。
*/
/*****************************************************************
 *函数名：QuickSort
 *作用：快速排序算法
 *参数：
 *返回值： 无
 *这个没有直接将基准值和相遇元素全部交换，而是最后当i==j时交换
 ****************************************************************/
void QuickSort(int *arr, int low, int high)
{
    if (low < high) {
        int i = low;
        int j = high;
        int k = arr[low];
        //int maxlen = BUF_SIZE;

        while (i < j)
        {
            /*从右向左找第一个小于k的数*/
            while (i < j && arr[j] >= k)
            {
                j--;
            }
            if (i < j) {
                arr[i++] = arr[j];
            }
            //display(arr, maxlen); 
            //printf("k= %d  i=%d j = %d\n", k, i, j);
            /*从左至右找第一个大于等于k的数*/
            while (i < j && arr[i] < k) {
                i++;
            }
            if (i < j) {
                arr[j--] = arr[i];
            }
            //display(arr, maxlen); 
            //printf("k= %d  i=%d j = %d\n", k, i, j);
        }

        arr[i] = k;
        //printf("\n");

        /*递归调用*/
        QuickSort(arr, low, i - 1);  /*排序k左边*/
        QuickSort(arr, i + 1, high); /*排序k右边*/
    } else {
        //printf("par wrong!!! \n");
    }
    return;
}

int main()
{
    int ret = 0;
    int array[BUF_SIZE] = {12, 85, 25, 16, 34, 23, 49, 95, 17, 61};
    int maxlen = BUF_SIZE;

    printf("array before sort: \n");
    display(array, maxlen); 

    QuickSort(array, 0, maxlen - 1); 

    printf("array after sort: \n");
    display(array, maxlen);

    return ret;
}