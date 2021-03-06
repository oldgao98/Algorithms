/* 插入排序 */
// - **基本思想：在要排序的一组数中，假定前n-1个数已经排好序，
//       现在将第n个数插到前面的有序数列中，使得这n个数也是排好顺序的。如此反复循环，直到全部排好顺序。

// - **平均时间复杂度：O(n2)

#include <iostream>
using namespace std;

void PrintAarry(const int *arr, int size);
//交换算法
void Swap(int & a, int & b)
{
    int temp = a;
    a = b;
    b = temp;
}
//插入排序算法
//升序排列
void InsertSort(int* arr,int arr_len)
{
    //外层循环，需要执行 （数组元素个数-1）次。每次执行完成一个最小数的查找。
    for (int i = 1; i < arr_len; i++)
    {
        //内层循环，执行未安排位置元素的比较工作，第i次外层循环，需要比较（数组个数-1）次比较
        //每次找到插入一个数字到前面已经排好序的数组中
        for (int j = i; j > 0; j--)
        {
            //升序排列
            if (arr[j] < arr[j-1])
            {
                Swap(arr[j], arr[j-1]);
            }  
        }
        cout << "第 " << i << " 次排序结果： " << endl;
        PrintAarry(arr, arr_len);
    }
}
//打印数组
void PrintAarry(const int *arr, int size) 
{
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[] = {4,2,8,0,5,7,1,3,9,6};
    int arr_len = sizeof(arr) / sizeof(arr[0]);
    cout << "原数组为：" << endl;
    PrintAarry(arr, arr_len);

    //对数组进行选择排序
    InsertSort(arr,arr_len);

    cout << "排序后数组为：" << endl;
    PrintAarry(arr, arr_len);
    return 0;
}
