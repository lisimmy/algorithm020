学习笔记

两种高级的数据结构      布隆过滤器     LUR

布隆过滤器 Bloom filter

一个很长的二进制向量和一系列随机映射函数。布隆过滤器可以用于检索一个元素是否在一个集合中。

优点是空间效率和查询时间都远远超过一般的算法，

缺点是有一定的误识别率和删除困难。

哈希表： 不仅能识别元素是否在一个集合中，而且能存储额外的信息

查询效率很高（1-N，最优能逼近于1）。

应用场景
1. 网页爬虫对URL的去重，避免爬取相同的URL地址；
2. 反垃圾邮件，从数十亿个垃圾邮件列表中判断某邮箱是否垃圾邮箱（同理，垃圾短信）；
3. 缓存击穿，将已存在的缓存放到布隆中，当黑客访问不存在的缓存时迅速返回避免缓存及DB挂掉。



class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 选择排序， 每次选择子数组中最小的放到子数组的前面
        int n = nums.size();
        
        int minIndex;  // 存放最小值的index
        for(int i = 0; i < n - 1; ++i) {
            minIndex = i;
            for(int j = i + 1; j < n; ++j) {
                if(nums[minIndex] > nums[j]) {
                    minIndex = j;
                }
            }
            if(minIndex != i) {
                nums[i] = nums[i] ^ nums[minIndex];
                nums[minIndex] = nums[i] ^ nums[minIndex];
                nums[i] = nums[i] ^ nums[minIndex];
            }
        }
        return nums;
    }
};


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        // 插入排序
        for(int i = 1; i < n; ++i) {
            int temp = nums[i];
            for(int j = i - 1; j >= 0; --j) {
                if(nums[j] > temp) {
                    nums[j + 1] = nums[j];
                }else {
                    break;
                }
                nums[j] = temp;
            }
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 插入排序
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            int key = nums[i];
            int j = i - 1;
            while(j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                --j;
            }
            nums[j + 1] = key;
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 冒泡排序
        int n = nums.size();
        for(int i = n - 1; i >= 0; --i) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] > nums[j + 1]) {
                    nums[j] = nums[j] ^ nums[j + 1];
                    nums[j + 1] = nums[j] ^ nums[j + 1];
                    nums[j] = nums[j] ^ nums[j + 1];
                }
            }
        }
        return nums;
    }
};


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // 快速排序 quick sort
        // 分治思想， 选取标杆， 以标杆为分界， 将数组分为左右两部分， 左侧小于标杆，右侧大于标杆， 再将左侧和右侧作为子问题进行分治
        int n = nums.size();
        quickSort(nums, 0, n - 1);
        return nums;
    }

    void quickSort(vector<int>& nums, int begin, int end) {
        // terminater
        if(begin >= end) return;

        // 逻辑处理
        int pivot = 0;
        pivot = partition(nums, begin, end);

        // 下探 处理左边子数组和右边子数组
        quickSort(nums, begin, pivot - 1);
        quickSort(nums, pivot + 1, end);

    }
    int partition(vector<int>& nums, int& begin, int& end) {
        int pivot = end;
        int counter = begin;
        for(int i = begin; i <= end; ++i) {
            if(nums[i] < nums[pivot]) {
                // nums[i] = nums[i] ^ nums[counter];
                // nums[counter] = nums[i] ^ nums[counter];
                // nums[i] = nums[i] ^ nums[counter];
                int temp = nums[i];
                nums[i] = nums[counter];
                nums[counter] = temp;
                ++counter;
            }
        }
        // 以 pivot 和 counter 为下标的元素互换   
        // ---使用 ^ 错误，counter 可能等于 pivot
        // nums[i] = nums[i] ^ nums[i] 导致 nums[i] = 0
        // nums[pivot] = nums[pivot] ^ nums[counter];
        // nums[counter] = nums[pivot] ^ nums[counter];
        // nums[pivot] = nums[pivot] ^ nums[counter];
        int temp = nums[pivot];
        nums[pivot] = nums[counter];
        nums[counter] = temp;

        return counter;
    }
};


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        // merge sort 归并排序
        // 分治思想， 将数组一分为2，然后合并结果， 左右子数组作为子问题再一分为2，
        int n = nums.size() - 1;
        mergeSort(nums, 0, n);
        return nums;
    }
    void mergeSort(vector<int>& nums, int left, int right) {
        // terminater
        if(left >= right) return;
        // proc
        int mid = left + (right - left) / 2;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        // 合并当前递归层
        merge(nums, left, mid, right);
    }
    void merge(vector<int>& nums, int left, int mid, int right) {
        vector<int> temp(right - left + 1);
        int i = left, j = mid + 1, k = 0;
        // 处理完一个子数组就结束，保证其中一个子数组是有序放入temp中
        while(i <= mid && j <= right) 
            temp[k++] = nums[i] > nums[j] ? nums[j++] : nums[i++];
        // 未处理完的子数组放入到temp中--未处理完的子数组所有元素是大于当前temp中的所有元素的
        while(i <= mid)  temp[k++] = nums[i++];
        while(j <= right) temp[k++] = nums[j++];
        // 将temp中的数据放入 nums中
        for(int i = 0; i < temp.size(); ++i) {
            nums[left + i] = temp[i];
        }
    }
};