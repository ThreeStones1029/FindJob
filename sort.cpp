#include <iostream>
#include <vector>
#include <algorithm>

// （1）冒泡排序
void bubble_sort(std::vector<int>& array) {
    int n = array.size();
    // i表示比较n轮
    for (int i = 0; i < n - 1; i++) {
        for (int j = 1; j < n - i; j++) {
            if (array[j - 1] > array[j]) {
                int temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
            }
        }
    }
}

// （2）选择排序
void selection_sort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 0; i < n - 1; i++) {
        int min = array[i];
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (array[j] < min) {
                min = array[j];
                min_index = j;
            }
        }
        std::swap(array[i], array[min_index]);
    }
}

// （3）插入排序

void insertion_sort(std::vector<int>& array) {
    int n = array.size();
    // for (int i = 1; i < n; i++) {
    //     // 在已经排序好的有序部分插入元素
    //     int j;
    //     for (j = 0; j < i; j++) {
    //         if (array[j] > array[i]) break;
    //     }
    //     // 移动元素
    //     int temp = array[i];
    //     for (int k = i; k > j; k--) {
    //         array[k] = array[k - 1];
    //     }
    //     array[j] = temp;
    // }

    for(int i = 1; i < n; i++){
        int key = array[i];
        int j = i - 1;
        // 从当前结点的前一个开始比较，小于就继续往前找，同时移动元素
        while((j >= 0) && (key < array[j])){
            array[j + 1] = array[j];
            j--;
        }
        // 最后插入元素
        array[j + 1]=key;
    }
}

// （4）希尔排序

void shell_sort(std::vector<int>& array) {
    int n = array.size();
    // 初始间隔 gap 选择为 n / 2
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // 对每组使用插入排序
        for (int i = gap; i < n; i++) {
            int temp = array[i];
            int j;
            // 对当前组进行插入排序
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = temp;
        }
    }
}

// （5）归并排序

// （6）快速排序

// （7）堆排序

// （8）计数排序

// （9）桶排序

// （10）基数排序

// 打印数组元素
void print_array(std::vector<int>& array) {
    for (auto item: array){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> array = {10, 20, 34, 35, -12, 89, 234, -45, 768, -456, 90, 343, 12, 340};
    // 排序前
    std::cout << "before sorting" << std::endl;
    print_array(array);

    // 冒泡排序后
    // bubble_sort(array);

    // 选择排序
    // selection_sort(array);

    // 插入排序
    // insertion_sort(array);

    // 希尔排序
    shell_sort(array);
 
    print_array(array);


    return 0;
}