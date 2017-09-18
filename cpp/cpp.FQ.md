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


# template

## total template specialization

*template<>*是全特化*total template specialization*的关键字。
such
```cpp
namespace std {
        template<>
        void swap<myClass>( myClass &lhs,
                            myClass &rhs )
        {
                /* user swap version */
        }
}
```
## partially specialization



## class vs typename

Stroustrup originally used ***class*** to specify types in templates to avoid introducing a new keyword. Some in the committee worried that this ***overloading of the keyword led to confusion***. Later, the committee introduced a new keyword ***typename*** to resolve syntactic ambiguity, and decided to let it also be used to specify template types to reduce confusion, but for ***backward compatibility***, class kept its overloaded meaning.
