#include <iostream>
using namespace std;

/**
 * @class c: A study case for pointer in a class 
 * @private p: the pointer we're gonna work on
 * @public:
 *      @brief constructor: has the name of the class
 *              no return type or void, it gets called
 *              once the obj is declared to intialize private members
 *      @brief set: to set the value that p points to
 *      @brief print: to print the value of p and its address
 *      @brief destructor: when the class has a pointer and we
 *              dynamically allocate it, then we need something
 *              to free that memory to avoid memory leaks
 *       @brief operator: Triggered when an *already existing* object is assigned 
 *              the value of another existing object using the '=' sign.
 *              Used to perform a deep copy to avoid shallow copies 
 *              and double deletion (double free) of shared memory.
 *      @brief copy: Triggered when a *new object* is created as a copy of 
 *              an existing object, e.g., `c obj2 = obj1;`.
 *              Allocates new memory and copies the data to avoid 
 *              sharing the same pointer (which would cause shallow copy 
 *              and potential double free errors).
 * 
 * 
 * 🧠 Your Understanding:

    “I need to pass the object a as a reference to tell C++:
    ‘Oh, this is the original object that I need to make a copy from.’”

✅ Perfect. That’s the right mental model.

🔁 Why reference (&)?
Because C++ says:

    “If you give me a reference, I’ll just use the original object directly
        I won’t try to copy it first (which would need a copy constructor... 
            which is what we’re defining right now... infinite loop 🚨).”
 */
class c
{
    int *p;
    public:
        c(){p = 0;}
        void set(int v);
        void print()
        {
            if(p)
                cout << p << " ==> " << *p << endl;
        }
        ~c(){delete p;}
        void operator=(c &o);
        c(c &o);
};

void c::set(int v) // perfect
{
    if(p)   
        delete p;
    p = new int;
    *p = v;
}

void c::operator=(c &o)
{
    if(p)   
        delete p;
    p = new int;
    *p = *(o.p);
}

int main()
{
    c o1;
    o1.set(8);
    o1.print();
    
    c o2;
    o2.set(9);
    o2.print();
}



