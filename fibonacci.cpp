#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



/*
 * Complete the 'fizzBuzz' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

unsigned long long int fib[1024] = {0, 1};
unsigned long long int fibonacci(int n) {
    if (n == 0 or fib[n] != 0) {
        return fib[n];
    } else {
        fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
        return fib[n];
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    // function name here
    std::cout << "fib " << n << " is: " << fibonacci(n) << "\n";

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
