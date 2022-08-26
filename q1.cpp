//Sakshi Shah
//2010992075
//Set-05
//Q1
//Given an integer array, find the maximum length subarray having a given sum.

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubarray(int arr[],int n,int p)
{
    // unordered_map 'um' implemented as hash table
    unordered_map<int, int> um;
    int sum = 0, maxLeng = 0;


    // traverse the given array
    for (int i = 0; i < n; i++)
    {

        // accumulate sum
        sum += arr[i];

        // when subarray starts from index '0'
        if (sum == p)
            maxLeng = i + 1;

        // make an entry for 'sum' if it is not present in 'um'
        if (um.find(sum) == um.end())
            um[sum] = i;

        // check if 'sum-p' is present in 'um' or not
        if (um.find(sum - p) != um.end())
        {

            // update maxLength
            if (maxLeng < (i - um[sum - p]))
                maxLeng = i - um[sum - p];
        }
    }

    // required maximum length
    return maxLeng;
}


//Code
int main()
{
    int arr[] = {5, 6, -5, 5, 3, 5, 3, -2, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int p = 8;
    int res;

    try
    {
        res = lengthOfLongestSubarray(arr, n, p);
        if (!res)
            throw("No subarray found");
    }
    catch (int error)
    {
        cout << "Error: " << error << endl;
    }

    cout << "Length = " << res;
    return 0;
}
