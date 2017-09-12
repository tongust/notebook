#include <algorithm>
#include <cmath>
#include <iostream>
#include <iterator>
#include <list>
#include <math.h>       /* log2 */
#include <random>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#ifndef MMIN
#define MMIN(x,y) ((x) > (y) ? (y) : (x))
#endif
#ifndef MMAX
#define MMAX(x,y) ((x) < (y) ? (y) : (x))
#endif

#ifndef PRINT1D
#define PRINT1D(v,d) do {for (auto it_print : v) cout << it_print << d; cout << endl;}while(0)
#endif

#ifdef PRINT1D
#ifndef PRINT2D
#define PRINT2D(v,d)                          \
do {                                          \
    cout << endl;                             \
    for (auto &it_print2d : v) {              \
        for (auto &it_print1d : it_print2d) { \
            cout << it_print1d << d;          \
            } cout << endl;                   \
    }                                         \
} while(0)
#endif
#endif

#ifndef MDebugLog
#define MDebugLog(msg)  std::cout << __FILE__ << ":" << __LINE__ << ": " << msg
#endif

/* Usings */

using std::cin;
using std::cout;
using std::endl;
using std::list;
using std::multiset;
using std::pair;
using std::set;
using std::sqrt;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

/* Typedef */

typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<vvint> vvvint;
typedef vector<vvvint> vvvvint;

class A
{
public:
        A(int d = 1): data(d) {}
        A(const A& rhs) {
                copy(rhs);
                cout << " copy " << rhs.data <<  endl;
        }
        A& operator=(const A& rhs) {
                data = rhs.data;
                cout << " = " << endl;
                return *this;
        }
        ~A() = default;
        void copy(const A& rhs) {
                data = rhs.data;
                cout << "data copied: " << rhs.data << endl;
                return;
        }
private:
        int data;
};
class B
{
public:
        B() = default;
        void foo(const B& rhs);
private:
        int data;
};
void B::foo(const B& rhs)
{
        data = rhs.data;
        return;
}

int main()
{

        A a;
        A b = a;
        b.copy(a);
        return 0;
}
