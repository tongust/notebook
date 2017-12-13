#ifndef LIBTEST_TESTA_H
#define LIBTEST_TESTA_H

#include <iostream>

#include <libtest/testb.h>


void foo_a()
{
        std::cout << "I used foo_a() \n\r";
        foo_b();

        std::cout << "foo_a() " <<
                __LINE__ <<
                " " <<
                __FILE__ <<
                std::endl;
        return;
}

#endif /* LIBTEST_TESTA_H */
