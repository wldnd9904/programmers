#include <vector>
#include <string>
#include <iostream>
#define INF 2147483647
using namespace std;
vector<char> sign;
vector<int> nums;
vector<vector<int>> minC;
vector<vector<int>> maxC;
int dmin(int, int);
int dmax(int, int);
int solution(vector<string> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (i % 2 == 0)
            nums.push_back(stoi(arr[i]));
        else
            sign.push_back(arr[i][0]);
    }
    minC = vector<vector<int>>(nums.size(), vector<int>(nums.size(), INF));
    maxC = vector<vector<int>>(nums.size(), vector<int>(nums.size(), -INF));
    int answer = dmax(0, nums.size() - 1);
    return answer;
}
int dmin(int start, int end)
{
    if (start == end)
        return nums[start];
    if (minC[start][end] != INF)
        return minC[start][end];
    int ret = INF;
    for (int i = start; i < end; i++)
    {
        int tmp;
        if (sign[i] == '+')
            tmp = dmin(start, i) + dmin(i + 1, end);
        else
            tmp = dmin(start, i) - dmax(i + 1, end);
        ret = min(tmp, ret);
    }
    minC[start][end] = ret;
    return ret;
}
int dmax(int start, int end)
{
    if (start == end)
        return nums[start];
    if (maxC[start][end] != -INF)
        return maxC[start][end];
    int ret = -INF;
    for (int i = start; i < end; i++)
    {
        int tmp;
        if (sign[i] == '+')
            tmp = dmax(start, i) + dmax(i + 1, end);
        else
            tmp = dmax(start, i) - dmin(i + 1, end);
        ret = max(tmp, ret);
    }
    maxC[start][end] = ret;
    return ret;
}