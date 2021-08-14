#include <iostream>
#include <fstream>
#include <bits/stdc++.h>
#define ll long long
const int MAX = 1e5;

using namespace std;
ll numInversions(int arr[], int temp[], int left, int right);
ll splitInversions(int arr[], int temp[], int left, int right);
int main() {
    ifstream inFile;
    inFile.open("int.txt");
    if(!inFile){
        cerr << "Unable to open file.";
        exit(1);
    }

    int arr[MAX];
    int tempvar;
    int sz=0;
    while(inFile >> tempvar){
        arr[sz] = tempvar;
        sz++;
    }
    inFile.close();

    int temp[MAX];
    ll Inversions = numInversions(arr, temp, 0, sz-1);
    cout <<"Number of Inversions in the Array is " << Inversions<<endl;

	return 0;
}

ll splitInversions(int arr[], int temp[], int left, int right){
    ll countInv = 0;

    int leftPtr = left;
    int mid = (right + left) / 2 + 1;
    int rightPtr = mid;
    int tempPtr = left;

    while(leftPtr < mid && rightPtr <= right){
        if(arr[leftPtr] <= arr[rightPtr]){
            temp[tempPtr++] = arr[leftPtr++];
        }
        else{
            temp[tempPtr++] = arr[rightPtr++];
            countInv += mid - leftPtr;
        }
    }
    while(leftPtr < mid){
        temp[tempPtr++] = arr[leftPtr++];
    }
    while(rightPtr <= right){
        temp[tempPtr++] = arr[rightPtr++];
    }

    for(int i=left; i<=right; i++){
        arr[i] = temp[i];
    }
    return countInv;
}

ll numInversions(int arr[], int temp[], int left, int right){
    if(right == left) return 0;

    int mid = (right + left) / 2;
    ll leftCount = numInversions(arr, temp, left, mid);
    ll rightCount = numInversions(arr, temp, mid+1, right);
    ll splitCount = splitInversions(arr, temp, left, right);

    return leftCount + rightCount + splitCount;
}
