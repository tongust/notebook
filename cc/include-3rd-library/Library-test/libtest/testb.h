#ifndef LIBTEST_TESTB_H
#define LIBTEST_TESTB_H

#include <iostream>

void foo_b()
{
        std::cout << "foo_b() " <<
                __LINE__ <<
                " " <<
                __FILE__ <<
                std::endl;
        return;
}

#endif /* LIBTEST_TESTB_H */
