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
    int d,i,j,temp;
	for(d = n/2;d >= 1;d = d/2){
		for(i = d;i < n;i++){//增量为i++，即各个子表交错处理 
			if(array[i]<array[i-d]){
				temp=array[i];
				for(j = i - d;j >= 0 && temp < array[j];j -= d){
					array[j + d] = array[j];
				}
				array[j + d] = temp;
			}
		}
	}
}

// （5）归并排序
// 递归法
void merge(std::vector<int>& array, int left, int mid, int right) {
    std::vector<int> left_array(array.begin() + left, array.begin() + mid + 1);
    std::vector<int> right_array(array.begin() + mid + 1, array.begin() + right + 1);

    int left_index = 0;
    int right_index = 0;
    // 插入哨兵值可以省去判断某个数组是否遍历完成的判断
    left_array.insert(left_array.end(), std::numeric_limits<int>::max());
    right_array.insert(right_array.end(), std::numeric_limits<int>::max());

    for (int i = left; i <= right; i++) {
        if (left_array[left_index] < right_array[right_index]) {
            array[i] = left_array[left_index];
            left_index++;
        }
        else {
            array[i] = right_array[right_index];
            right_index++;
        }
    }
}

void merge_sort(std::vector<int>& array, int left, int right) {
    if (left >= right) return;
    int mid = (left + right) / 2;
    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);
    merge(array, left, mid, right);
}

// （6）快速排序
int paritition(std::vector<int>& array, int left, int right) {
    int pivot = array[left];
    while (left < right) {
        while (left < right && array[right] >= pivot) {
            --right;
        }
        array[left] = array[right];
        while (left < right && array[left] <= pivot) {
            ++left;
        }
        array[right] = array[left];
    }
    array[left] = pivot;
    return left;
}

void quick_sort(std::vector<int>& array, int left, int right) {
    if (left < right) {
        int pivot = paritition(array, left, right);
        quick_sort(array, left, pivot - 1);
        quick_sort(array, pivot + 1, right);
    }
}

// （7）堆排序
// 维护大顶堆
void max_heapify(std::vector<int>& array, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { 
        if (son + 1 <= end && array[son] < array[son + 1]) // 先比较两个子结点，选择其中最大的
            son++;
        if (array[dad] > array[son]) // 父结点大于这个最大的子结点，结束循环
            return;
        else {
            std::swap(array[dad], array[son]); // 交换父子结点
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(std::vector<int>& array) {
    int n = array.size();

    // 构造大顶堆
    for (int i = n / 2 - 1; i >= 0; i--)
        max_heapify(array, i, n - 1);

    // 开始排序
    for (int i = n - 1; i > 0; i--) {
        std::swap(array[0], array[i]);
        max_heapify(array, 0, i - 1);
    }
}

// （8）计数排序

void counting_sort(std::vector<int>& array) {
    int n = array.size();

    int max = INT16_MIN, min = INT16_MAX;
    // 找到数组里面的最大最小值
    for (int i = 0; i < n; i++) {
        max = max > array[i] ? max : array[i];
        min = min < array[i] ? min : array[i];
    }
    // 创建计数数组，长度为最大值-最小值 + 1
    std::vector<int> count_list;
    int len = max - min + 1;
    for (int i = 0; i < len; i++) {
        count_list.push_back(0);
    }
    // 遍历数组，在对应位置自增
    for (int i = 0; i < n; i++) {
        count_list[array[i] - min]++;
    }
    // 重新排列原始数组
    int index = 0;
    for (int i = 0; i < len; i++) {
        while (count_list[i]--) {
            array[index++] = i + min;
        }
    }
}

// （9）桶排序

void bucket_sort(std::vector<int>& array) {
    int n = array.size();
    if (n <= 1) return;

    int max = INT16_MIN, min = INT16_MAX;
    // 找到数组里面的最大最小值
    for (int i = 0; i < n; i++) {
        max = max > array[i] ? max : array[i];
        min = min < array[i] ? min : array[i];
    }

    int bucket_size = max - min + 1;
    // 桶的数量
    int bucket_count = 10;

    std::vector<std::vector<int>> bucket(bucket_count);

    for (int num : array) {
        int index = (num - min) * bucket_count / bucket_size;
        bucket[index].push_back(num);
    }
    // 对每个桶的元素进行排序
    for (auto& b: bucket) {
        sort(b.begin(), b.end());
    }

    // 将排序后的元素依次放回原数组
	int index = 0;
	for (auto& b : bucket) {
		for (int num : b) {
			array[index++] = num;
		}
    }
}


// （10）基数排序

void radix_sort(std::vector<int>& array) {
    // 先找到最大的数
    int n = array.size();
    int max = INT16_MIN;
    // 找到数组里面的最大最小值
    for (int i = 0; i < n; i++) {
        max = max > array[i] ? max : array[i];
    }
    // 得到最大的数的位数
    int d = 0;
	while (max) {
		max /= 10;
		d++;
	}
    std::vector<int> count_list;

    // 初始化十个桶
    int *tmp = new int[n];
    int *count = new int[10]; //计数器
    int i, j, k;
    int radix = 1;
    for(i = 1; i <= d; i++) //进行d次排序
    {
        for(j = 0; j < 10; j++)
            count[j] = 0; //每次分配前清空计数器
        for(j = 0; j < n; j++)
        {
            k = (array[j] / radix) % 10; //统计每个桶中的记录数
            count[k]++;
        }
        for(j = 1; j < 10; j++)
            count[j] = count[j - 1] + count[j]; //将tmp中的位置依次分配给每个桶
        for(j = n - 1; j >= 0; j--) //将所有桶中记录依次收集到tmp中
        {
            k = (array[j] / radix) % 10;
            tmp[count[k] - 1] = array[j];
            count[k]--;
        }
        for(j = 0; j < n; j++) //将临时数组的内容复制到array中
            array[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}


// 打印数组元素
void print_array(std::vector<int>& array) {
    for (auto item: array){
        std::cout << item << " ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> array = {10, 20, 34, 35, 12, 89, 234, 45, 768, 456, 90, 343, 12, 340};
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
    // shell_sort(array);

    // 归并排序
    // merge_sort(array, 0, array.size() - 1);
    
    // 快速排序
    // quick_sort(array, 0, array.size() - 1);

    // 堆排序
    // heap_sort(array);

    // 计数排序
    // counting_sort(array);

    // 桶排序
    // bucket_sort(array);

    // 基数排序
    radix_sort(array);

    print_array(array);
    return 0;
}