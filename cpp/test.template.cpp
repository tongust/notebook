#include <iostream>
#include <string>
template <typename T>
int compare(const T &lhs, const T &rhs)
{
        if (lhs < rhs)  return -1;
        if (lhs > rhs)  return 1;
        return 0;
}

int main()
{
        using std::string;
        string s1 = "hello",s2 = "world";
        std::cout << compare(s1, s2) << std::endl;
        return 0;
}
	s

