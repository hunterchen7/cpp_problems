#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

#include <unordered_map>


bool canSum(vector<int>& nums, int target, unordered_map<int, bool>& memo) {
    if (target == 0) {
        return true;
    } else if (target < 0) {
        return false;
    } else if (memo.find(target) != memo.end()) {
        return memo.at(target);
    }
    for (int i = 0; i < nums.size(); i++) {
        int rem = target - nums[i];
        if (canSum(nums, rem, memo)) {
            memo.insert({target, true});
            return true;
        }
    }
    return false;
}

int main()
{
    /*string input;
    getline(cin, input);

    stringstream ss(input); // Use stringstream to process the input
    int n, m;
    ss >> n >> m;*/
    vector<int> n = {5, 67, 77, 7, 11};
    int m = 30000;

    // function name here
    unordered_map<int, bool> memo;

    clock_t start, end;
    start = clock();

    std::cout << canSum(n, m, memo) << "\n";

    end = clock();
    auto time_taken = double(end - start);
    std::cout << "time: " << fixed << time_taken << setprecision(6);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}
