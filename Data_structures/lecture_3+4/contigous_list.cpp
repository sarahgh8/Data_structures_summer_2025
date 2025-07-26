#include <iostream>
using namespace std;

const int Size = 5;

class list
{
    int c_list[Size];
    int len;

    public:
        list() {len = 0;}

        bool is_empty();
        bool is_full();

        void print();
        bool search(int v);

        bool add_begin(int v);
        bool add_end(int v);
        bool add_pos(int v, int pos);

        bool delete_begin();
        bool delete_end();
        bool delete_pos(int pos);
};

bool list::is_empty()
{
    return len == 0;
}
bool list::is_full()
{
    return len == Size;
}

void list::print()
{
    for(int i = 0; i < len; i++)
        cout << c_list[i] << " ";
    cout << endl;
}

/**
 * @brief: we start shifting the numbers from the last one
 *          so we can keep the first pos empty
 */
bool list::add_begin(int v)
{
    if(is_full())
        return 0;
    for(int i = len - 1; i >= 0; i--)
        c_list[i + 1] = c_list[i];
    c_list[0] = v;
    len++;
    return 1;
}
bool list::add_end(int v)
{
    if(is_full())
        return 0;
    c_list[len++] = v;
    return 1;
}
bool list::add_pos(int v, int pos)
{
    if(is_full() || pos < 0 || pos > len)   
        return 0;
    for(int i = len - 1; i >= pos; i--)
        c_list[i + 1] = c_list[i];
    c_list[pos] = v;
    len++;
    return 1;
}

bool list::delete_begin()
{
    if(is_empty())
        return 0;
    for(int i = 1; i < len; i++)
        c_list[i - 1] = c_list[i];
    len--;
    return 1;
}
bool list::delete_end()
{
    if(is_empty())
        return 0;
    len--;
    return 1;
}
bool list::delete_pos(int pos)
{
    if(is_empty() || pos < 0 || pos > len - 1)
        return 0;
    for(int i = pos; i < len; i++)
        c_list[i - 1] = c_list[i];
    len--;
    return 1;
}

bool list::search(int v)
{
    for(int i = 0; i < len; i++)
    {
        if(c_list[i] == v)
            return 1;
    }
    return 0;
}

int main()
{
    list num;

    num.add_begin(1);
    num.add_begin(2);
    num.add_begin(3);

    num.print();
}



