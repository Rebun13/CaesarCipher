#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s
 *  2. INTEGER k
 */

string caesarCipher(string s, int k) {
    int l = 'z' - 'a' + 1;
    if(k >= l) {
        k -= l * (k / l);
    }
    string res = "";
    for(char x : s) {
        if(x >= 'a' && x <= 'z') { // lower case
            char y = x + k;
            if((unsigned int) y > 'z') {
                res.push_back((char) (y - l));
            } else {
                res.push_back((char) y);
            }
        } else if(x >= 'A' && x <= 'Z') { // upper case
            char y = x + k;
            if((unsigned int) y > 'Z') {
                res.push_back((char) (y - l));
            } else {
                res.push_back((char) y);
            }
        } else { // other characters
            res.push_back(x);
        }
    }
    return res;
}

int main()
{

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string s;
    getline(cin, s);

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    string result = caesarCipher(s, k);

    cout << result << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), [](int c) {return !std::isspace(c);})
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), [](int c) {return !std::isspace(c);}).base(),
        s.end()
    );

    return s;
}
