/* 冒泡排序 */
// - **基本思想：两个数比较大小，较大的数下沉，较小的数冒起来。
// - **过程：
//     - 比较相邻的两个数据，如果第二个数小，就交换位置。
//     - 从后向前两两比较，一直到比较最前两个数据。最终最小数被交换到起始的位置，这样第一个最小数的位置就排好了。
//     - 继续重复上述过程，依次将第2.3...n-1个最小数排好位置。
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
//冒泡排序算法
//升序排列
void BubbleSort(int* arr,int arr_len)
{
    //外层循环，需要执行 （数组元素个数-1）次。每次执行完成一个最小数的冒泡。
    for (int i = 0; i < arr_len - 1; i++)
    {
        //内层循环，执行未安排位置元素的比较工作，第i次外层循环，需要比较（数组个数-1）次比较
        for (int j = arr_len - 1; j > i; j--)
        {
            //升序排列
            if (arr[j] < arr[j-1])
            {
                //对两个元素进行交换
                Swap(arr[j], arr[j-1]);
            }
        }
        cout << "第 " << i+1 << " 次排序结果： " << endl;
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

    //对数组进行冒泡排序
    BubbleSort(arr,arr_len);

    cout << "排序后数组为：" << endl;
    PrintAarry(arr, arr_len);
    return 0;
}
