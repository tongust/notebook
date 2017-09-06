#include <deque>
#include <iostream>
#include <iterator>
#include <algorithm>

using namespace std;



int main() {
    deque<int> dp;
    ostream_iterator<int> oite(cout, ",");
    istream_iterator<int> iite(cin), eos;
    copy(iite, eos, back_inserter(dp));
    copy(dp.rbegin(), dp.rend(), oite);

    return 0;
}


