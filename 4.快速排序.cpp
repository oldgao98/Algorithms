/* 插入排序 */
// - **基本思想：
// - 1．先从数列中取出一个数作为基准数。
// - 2．分区过程，将比这个数大的数全放到它的右边，小于或等于它的数全放到它的左边。
// - 3．再对左右区间重复第二步，直到各区间只有一个数。

// - **平均时间复杂度：O(nlogn)
//   **最坏时间复杂度：O(n2)
//   **最佳时间复杂度：O(nlogn)

#include <iostream>
using namespace std;

void PrintAarry(const int *arr, int size);

//获取基准数的索引
int GetBaseIndex(int* arr, int low, int high) 
{
    int base_num = arr[low];
    while (low < high) 
    {
        //找到第一个小于基准数的位置
        //当队尾的元素大于等于基准数时，向前挪动high指针
        while (low < high && arr[high] >= base_num) 
        {
            high--;
        }
        arr[low] = arr[high];
        //找到第一个大于基准数的位置
        //当队头的元素小于基准数时，向后挪动low指针
        while (low < high && arr[low] <= base_num) 
        {
            low++;    
        }
        arr[high] = arr[low];
    }
    arr[low] = base_num;
    return low;
}
//快速排序算法
//升序排列
void QuickSort(int* arr, int low, int high)
{
    if (low < high) 
    {
        int base_index = GetBaseIndex(arr, low, high); 
        QuickSort(arr, low, base_index - 1);
        QuickSort(arr, base_index + 1, high);
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

    //对数组进行快速排序
    QuickSort(arr, 0, arr_len - 1);

    cout << "排序后数组为：" << endl;
    PrintAarry(arr, arr_len);
    return 0;
}
