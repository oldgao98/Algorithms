/* 插入排序 */
// - **基本思想：遍历数组，每次找到最小的一个数与第一个数字交换。

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
//选择排序算法
//升序排列
void BubbleSort(int* arr,int arr_len)
{
    //外层循环，需要执行 （数组元素个数-1）次。每次执行完成一个最小数的查找。
    for (int i = 0; i < arr_len - 1; i++)
    {
        int min_index = arr_len - 1;
        int min_num = arr[arr_len - 1];
        //内层循环，执行未安排位置元素的比较工作，第i次外层循环，需要比较（数组个数-1）次比较
        //每次找到最小的一个数与第一个数字交换
        for (int j = arr_len - 1; j > i; j--)
        {
            //升序排列
            if (arr[j] < min_num)
            {
                min_index = j;
                min_num = arr[j];
            }    
        }
        Swap(arr[i], arr[min_index]);
        cout << "第 " << i + 1 << " 次排序结果： " << endl;
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
    BubbleSort(arr,arr_len);

    cout << "排序后数组为：" << endl;
    PrintAarry(arr, arr_len);
    return 0;
}
