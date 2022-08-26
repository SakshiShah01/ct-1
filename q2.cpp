//Sakshi Shah
//2010992075
//Set-05
//Q2
//Print all subarrays with 0 sum. Given an integer array, print all subarrays with zero-sum.

#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findSubArrays(int arr[], int p)
{
    // create an empty map
    unordered_map<int, vector<int>> map;

    //create an empty vector of pairs to store subarray starting and ending index
    vector<pair<int, int>> out;

    int summ = 0;

    for (int i = 0; i < p; i++)
    {
        // add current element to sum
        summ += arr[i];

        // if sum is 0, we found a subarray starting from index 0 and ending at index i
        if (summ == 0)
            out.push_back(make_pair(0, i));

        // If sum already exists in the map there exists at-least one subarray ending at index i with 0 sum
        if (map.find(summ) != map.end())
        {
            // map[sum] stores starting index of all subarrays
            vector<int> vc = map[summ];
            for (auto it = vc.begin(); it != vc.end(); it++)
                out.push_back(make_pair(*it + 1, i));
        }

        // Imp - no else
        map[summ].push_back(i);
    }

    // return output vector
    return out;
}


// Utility function to print all subarrays with sum 0
void print(vector<pair<int, int>> out, int arr[])
{
    for (auto it = out.begin(); it != out.end(); it++)
    {
        for (int i = it->first; i <= it->second; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}


//code
int main()
{
    int arr[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    int p = sizeof(arr) / sizeof(arr[0]);

    vector<pair<int, int>> out;

    try
    {
        out = findSubArrays(arr, p);
        if (out.size() == 0)
            throw(0);
    }
    catch (int size)
    {
        cout << "Size is " << size << endl;
    }

    // if we didn’t find any subarray with 0 sum, then subarray doesn’t exists
    if (out.size() == 0)
        cout << "No subarray exists";
    else
        print(out, arr);

    return 0;
}