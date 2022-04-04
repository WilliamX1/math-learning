#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

int mul(vector<int> v) { // 将数组中所有元素相乘，若数组为空则报错
	assert(!v.empty());
    int ans = 1;
    for (const int& ele : v)
        ans *= ele;
    return ans;
};

int find_y(int M, int m) {
	int M_div_m = M / m;
	assert(M == M_div_m * m); // 验证 M 一定是 m 的倍数
	int y = 1;
	while (true) {
		if ((y * M_div_m % m) == 1) return y;
		else y++;
	};
	return -1;
};

vector<int> chinese_reminder_theorem(vector<int> a, vector<int> m) {
	vector<int> answer(2, 0); // answer[0] = c, answer[1] = d
	int M = mul(m); // 将所有除数相乘
	
	int n = a.size(); // 条件总数
	for (int i = 0; i < n; i++) {
		int y = find_y(M, m[i]); // 获得 y，满足 y * M / m[i] 除余 m[i] 余 1
		answer[0] += a[i] * y * M / m[i];
	};
	
	int lcm_m = mul(m); // 我们规定 a 中元素是两两互素的，所以相乘即得最小公倍数
	answer[0] -= (answer[0] / lcm_m) * lcm_m; // 寻找满足条件的最小值
	answer[1] = lcm_m;
	
	return answer;
};
int main()
{
    vector<int> a = {3, 1, 6}, m = {5, 7, 8};
    vector<int> ans = chinese_reminder_theorem(a, m);
    cout << ans[0] << ' ' << ans[1] << endl;
   
   return 0;
}