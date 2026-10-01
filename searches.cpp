#include <iostream>
#include <vector>

// Linear Search
// Time Complexity: O(n)
// Space Complexity: O(1)
//
// Example:
// Input:
// 10
// 1 2 3 4 5 6 7 8 9 10
// 10
//
// Output:
// 9
//
// In the worst case, all n elements are checked.

int linearly_search(const int& target, const std::vector<int>& arr){
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

// Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
//
// Example:
// Input:
// 16
// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
// 15
//
// Output:
// 14
//
// Each iteration cuts the search range approximately in half.
// Binary Search requires a sorted array.

int binary_search(const int& target, const std::vector<int>& arr){
    int left = 0;
    int right = arr.size() - 1;
    while(left <= right){
        int middle = (left + right) / 2;
        if(target == arr[middle]){
            return middle;
        }
        if(target < arr[middle]){
            right = middle - 1;
        }
        else{
            left = middle + 1;
        }
    }
    return -1;
}

int main(){
    int n, target;
    std::cin >> n;
    std::vector<int> arr(n);
    
    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }
    std::cin >> target;
    std::cout << linearly_search(target, arr);
    return 0;
}