#include<iostream>
#include<vector>

using namespace std;
int bin_search(vector<int> arr, int left, int right, int target){
    if (left > right){
        return -1;
    }
    int mid = (int)((left + right) / 2);
    if(arr[mid] == target){
        return mid;
    }
    if (arr[mid] <= target){
        return bin_search(arr, mid + 1, right, target);
    }
    else if (arr[mid] > target){
        return bin_search(arr, left, mid - 1, target);
    }
}

int main(){
    vector<int> a = {1,2,3,4,5,6,7,8};
    int resoult = bin_search(a, 0, a.size()-1, 6);
    cout<<resoult<<endl;
}
