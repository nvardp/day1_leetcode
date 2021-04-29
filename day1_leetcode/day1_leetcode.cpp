#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <fstream>
#include <string>
#include <bitset>
using namespace std;
vector<int> sortArray(vector<int>& nums)
{
	for (int j = 0; j < nums.size() - 1; ++j)
	{
		for (int i = 0; i < nums.size() - j - 1; i++)
		{
			if (nums[i] > nums[i + 1])
				std::swap(nums[i], nums[i + 1]);
		}
	}
	return nums;
}


vector<int>  merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
	int i = 0, j = 0;
	vector<int> result;
	while (i < m && j < n)
	{
		if (nums1[i] > nums2[j])
		{
			result.push_back(nums2[j]);
			++j;
		}
		else if (nums1[i] < nums2[j])
		{
			result.push_back(nums1[i]);
			++i;
		}
		else
		{
			result.push_back(nums1[i++]);
			result.push_back(nums2[j++]);
		}
	}
	if (i < m)
	{
		while (i < m)
		{
			result.push_back(nums1[i]);
			++i;
		}
	}
	if (j < n)
	{
		while (j < n)
		{
			result.push_back(nums2[j]);
			++j;
		}
	}
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << "\t";
	}
	return result;
}


void read_10th_Line()
{
	ifstream file;
	file.open("file.txt");
	string result;
	for (int i = 0; i < 10; i++)
	{
		std::getline(file, result);
	}
	cout << result;
}


void valid_Phone_numbers()
{
	ifstream file;
	file.open("file.txt");
	string result;
	while (std::getline(file, result))
	{
		if (result[3] == '-' && result[7] == '-')
			cout << result << endl;
		else if (result[0] == '(' && result[4] == ')' && result[5] == ' ' && result[9] == '-')
			cout << result << endl;
	}
}

vector<int> sortedSquares(vector<int>& nums)
{
	vector<int> result;
	for (int i = 0; i < nums.size(); i++)
	{
		result.push_back(pow(nums[i], 2));
	}
	sort(result.begin(), result.end());
	return result;
}

vector<int> sortArrayByParity(vector<int>& A) // skzbic zuyger@ heto kenter@
{
	vector<int> result;
	vector<int> tmp;
	for (int i = 0; i < A.size(); i++)
	{
		if (A[i] & 1 == 1)
			tmp.push_back(A[i]);
		else result.push_back(A[i]);  
	}
	result.insert(result.end(), tmp.begin(), tmp.end());
	return result;
}


vector<int> sortArrayByParityII(vector<int>& nums)
{
	vector<int> result;
	vector<int> tmp_odd;
	vector<int> tmp_even;
	bool even = true;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] & 1) //kent
			tmp_odd.push_back(nums[i]);
		else tmp_even.push_back(nums[i]);
	}
	for (int i = 0; i < nums.size()/2; i++)
	{
		result.push_back(tmp_even[i]);
		result.push_back(tmp_odd[i]);
	}
	return result;
}


int minDeletionSize(vector<string>& strs) {
	int count = 0;
	for (int i = 0; i < strs[0].size(); ++i) //column= length of string in vector
		for (int r = 0; r < strs.size() - 1; ++r) // row= vector size
			if (strs[r][i] > strs[r + 1][i]) {
				++count;
				break;
			}
	return count;
}
bool isBadVersion(int m)
{
	return true;
}
int firstBadVersion(int n) {
	int left = 1;
	int right = n;
	while (left < right) {
		int mid = left + (right - left) / 2;
		if (isBadVersion(mid)) { //leetcode function
			right = mid;
		}
		else {
			left = mid + 1;
		}
	}
	return left;
}

struct For_sorting
{
	int value;
	int bites;
	void sortByValues()
	{
		
	}
	bool operator<(const For_sorting& rhs) const
	{
		return rhs.bites > bites;
	}

};
vector<int> sortByBits(vector<int>& arr) {
	unsigned int count = 0; 
	vector<int> result;
	vector<For_sorting> tmp;
	int tmp_value;
	for (int i = 0; i < arr.size(); i++)
	{
		count = 0;
		 tmp_value = arr[i];
		while (arr[i]) {
			count += arr[i] & 1;
			arr[i] >>= 1;
		}
		For_sorting obj;
		obj.bites = count;
		obj.value = tmp_value;
		tmp.push_back(obj);
	}
	bool equalBites=true;
	/*for (int i = 0; i < tmp.size()-1; i++)
	{
		if (tmp[i].bites != tmp[i + 1].bites)
		{
			equalBites = false; break;
		}
	}
	if(!equalBites)*/
	sort(tmp.begin(), tmp.end()); // sranic heto ete havasar en, minchev et tex@ tver@ sortavorel
	int i = 0;
	while (tmp.begin() != tmp.end())
	{
		int start = i;
		while (tmp[i].bites == tmp[i + 1].bites)
		{
			++i;
		}
		++tmp.begin();
	}
	for (int i = 0; i < tmp.size(); i++)
	{
		result.push_back(tmp[i].value);
	}
	if(equalBites)
		sort(result.begin(), result.end());
	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	
	return result;

}
int main()
{
	vector<string> vec{ "cba","daf","ghi" };
	vector<int> vec2{ 2,5,6 };
	minDeletionSize(vec);

	//valid_Phone_numbers();


}

