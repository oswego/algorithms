#include <iostream>
#include <string>
#include <math.h>

// below method comes from http://blog.csdn.net/lllcfr/article/details/18083757
std::string repeated_substring(std::string &str) {
    int len = str.length();

    int **c = new int*[len + 1];
    for (int i = 0; i <= len; ++i)
        c[i] = new int[len + 1];
    for (int i = 0; i <= len; ++i) {
        c[i][0] = 0;
        c[0][i] = 0;
    }

    int max_len = 0, index = len + 1;
    for (int i = 1; i <= len; ++i) {
        for (int j = 1; j <= len; ++j) {
            if (str[i-1] == str[j-1] && abs(i-j) > c[i-1][j-1]) {
                c[i][j] = c[i-1][j-1] + 1;
                if (c[i][j] > max_len) {
                    max_len = c[i][j];
                    index = std::min(i, j);
                }
            } else {
                c[i][j] = 0;
            }
        }
    }

    for (int i = 0; i <= len; ++i)
        delete[] c[i];
    delete[] c;

    if (max_len > 0) {
        std::string ret = str.substr(index - max_len, max_len);
        for (int i = 0; i < max_len; ++i)
            if(ret[i] != ' ')
                return ret;
    }

    return "NONE";
}

int main()
{
    while(true)
    {
        std::string str;
        std::cin >> str;
        if (str == "0")
            break;
        std::cout << repeated_substring(str) << std::endl;
    }

    return 0;
}