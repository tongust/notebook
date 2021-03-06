[toc]

# const and mutable 

mutable keyword allows the variable to be modified by a const function.
```cpp
class A {
public: 
        mutable int a;

        void foo() const 
        {
                a = 12;
                cout << a << " const foo" << endl;
        }

        void foo() 
        {
                a = 1;
                cout << a << " non-const foo" << endl;
        }
};

int main() {
        A a;
        a.foo();
        const A& b = a;
        b.foo();

        return 0;
}
```
> 1 non-const 
> 2 const

# Lambda expression
\[\]
> = means capture by value
> & means capture by reference

```cpp
[=val, &p] () mutable throw() -> int
{
        /* code */
        return 0;
}
```

# move, rvalue, lvalue
c++11 introduces "rvalue reference", allowing us to detecct rvalue arguments via function overloading.
A rvalue reference is a reference that must be bound to an rvalue. An rvalue reference is obtained by && rather than &. It may be bound only to an object that is about to be destroyed.
Some ops w.r.t lvalue:
- Assignment (non-const)
- address-of operator.
- The built-in dereference and subscript operators.
- build-in and iteator increment and decrement operators.
- ***Cannot bind an rvalue reference to lvalue***

To move an object means to transfer ownership of some resource it manages to another object.

```cpp
int i = 1;
int &r = i;
int &&rr = i; // error: cannot bind an rvalue reference to lvalue

int & r2 = i + 1;// error: cannot bind an reference to a temp value;
const int &cr1 = i + 1; // okay: const reference can be bound to
                        // a rvalue;
int && rr = i + 1; // okay: bind rr to a rvalue
                   // There are no other users of this rvalue;

int && rr1 = rr; // wrong: variable rr is an lvalue!
```
## cast explicitly an lvalue to its rvalue reference type
```cpp
int && rr2 = std::move(rr);
```
> We can destory a moved-from object and can assign a new value to it, but we cannot re-use the value of a moved-from object any more.

## rvalue and lvalue

## pre-increment (lvalue) and post-increment (rvalue)
```cpp
int i = 0;
++i = 12; // okay: pre-increment returns 
          // a reference to the incremented variable;

i++ = 12; // wrong: post-increment returns 
          // a tmp value instead of reference
```

# exception

- never throw any exception out of a destructor
- Can throw an exception out of a (default, copy and assignment) constructor
- never throw any exception out of a move constructor

# initialization
const or reference must be initialized in *member initialization list*
```cpp
class A
{
public:
        int a;
        string b;
        const int c;
        const int d = 1;// this will be ignored.
        A(): /*member initialization list*/a(), b(""), c(12), d(2){}
};
```
# singleton
```cpp
class S
{
    public:
        static S& getInstance()
        {
            static S    instance; // Guaranteed to be destroyed.
                                  // Instantiated on first use.
            return instance;
        }
    private:
        S() {}                    // Constructor? (the {} brackets) are needed here.

        // C++ 03
        // ========
        // Dont forget to declare these two. You want to make sure they
        // are unacceptable otherwise you may accidentally get copies of
        // your singleton appearing.
        S(S const&);              // Don't Implement
        void operator=(S const&); // Don't implement

        // C++ 11
        // =======
        // We can use the better technique of deleting the methods
        // we don't want.
    public:
        S(S const&)               = delete;
        void operator=(S const&)  = delete;

        // Note: Scott Meyers mentions in his Effective Modern
        //       C++ book, that deleted functions should generally
        //       be public as it results in better error messages
        //       due to the compilers behavior to check accessibility
        //       before deleted status
};
```
# local static v.s. non-local static variable
函数内的local static 确保
- 1. 该函数被调用期间
- 2. 首次遇见该对象的定义式时，被初始化。

# 2. Constructor, Destructor, Assignment Operator

## 09. Never call virtual functions during construction and destruction
- 在base class构造期间，virtual不是virtual函数。在base class构造期间，其调用的virtual function是base的，而不是derived的。
- If the virtual one of derived class is called during construction of base, the unique members of derived class is used. However, the derived class construction is still pending!

## 11. Handle Assignment to self in operator=

- 自我复制安全性
> if (this == &rhs) return \*this;
- 异常安全性(exception safety)
```cpp
...
{
        Object* ptmp = pb;// pb: point to data
        pb = new Object(*rhs.pb);
        delete ptmp;
        return *this;
}
```
## 12. copying
- In ***member initialization list***, we can 
        - copy-construct the base-part 
        - and get the private member of rhs.
- Never use the copy-constructor to help copy-assignment.

```cpp
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
        data = rhs.data; // Is valid!
        return;
}
```
```cpp
class B: public A
{
public:
        B(const B&b);
        B& operator=(const B&b){}
private:
        int data;
};
B::B(const B&b): 
        A(b),                   // 1. Important!
        data(b.data){}
B& B::operator=(const B&b) {
        A::operator=(rhs);      // 2. important!
        data = b.data;
        return *this;
}

```

