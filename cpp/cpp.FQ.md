# class

## explicit constructor
Implicit conversion
```cpp
class foo 
{
public:
        int mem;
        /* signle parameter constructor, can be used
           an implicit conversion*/
        foo(int a): mem(a) {}

        /* cannot be use as an implicit conversion  */
        explicit foo(long a): mem(a) {}
};

```
Prefixing the explicit to the constructor prevents the compiler from using implicit conversion.


