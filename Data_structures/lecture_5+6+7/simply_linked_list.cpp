#include <iostream>
using namespace std;

/**
 * Simply linked list 
*/

typedef struct s_node
{
    int data;
    s_node *next;

    s_node(int d, struct s_node *n)
    {
        data = d;
        next = n;
    }
}t_node ;

class list
{
    t_node *head, *tail;
    public:
        list();
        bool is_empty();
        
        void print();
        bool search(int v);
        int list_size();
        
        void add_begin(int v);
        void add_end(int v); // homework
        bool add_pos(int v, int pos); // homework
        
        bool delete_begin();
        bool delete_end();
        bool delete_pos(int pos);
        ~list();
        void operator=(list &o);
        list(list &o); //homework
};

void list::operator=(list &o)
{
    while(!is_empty())
        delete_end();
    if(!o.is_empty())
    {
        t_node *tmp = o.head;
        head = tail = new t_node(tmp->data);
        while(tmp->)

    }
    
}

list::~list()
{
    while(!is_empty())
        delete_end();
    cout << "list is now empty\n";
}


bool list::search(int v)
{
    t_node *tmp = head;
    while(tmp->next)
    {
        if(tmp->data == v)
            return true;
        tmp = tmp->next;
    }
    return false;
}

int list::list_size()
{
    int res = 0;
    t_node *tmp = head;
    while(tmp->next)
    {
        res++;
        tmp = tmp->next;
    }
    return res;
}

bool list::delete_begin()
{
    if(is_empty())
        return false;
    t_node *tmp = head;
    head = head->next;
    delete tmp;
    return true;
}

bool list::delete_pos(int pos)
{
    if(is_empty() || pos < 1 || pos > list_size())
        return false;
    t_node *before = head;
    t_node *after;
    t_node *del;
    for(int i = 1; i < pos - 1; i++)
        before = before->next;
    del = before->next;
    after = del->next;
    before->next = after;
    delete del;
    return true;
}

list::list()
{
    head = tail = 0;
}

/* bool list::search(int v)
{
} */


void list::add_end(int v)
{
    if(is_empty())
    {
        head = tail = new t_node(v, NULL);
        return ;
    }
    tail->next = new t_node(v, NULL);
    tail = tail->next;
}
bool list::add_pos(int v, int pos)
{
    if(is_empty())
    {
        head = tail = new t_node(v, NULL);
        return true;
    }
    t_node *tmp = head;
    for(int i = 1; i < pos; i++)
        tmp = tmp->next;
    t_node *after = tmp->next;
    tmp->next = new t_node(v, after);
    return false;
}

bool list::is_empty()
{
    return (head == 0 && tail == 0);
}

void list::add_begin(int v)
{
    if(is_empty())
        head = tail = new t_node(v, NULL);
    else    
        head = new t_node(v, head);
}

void list::print()
{
    t_node *tmp;

    tmp = head;
    while(tmp->next)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

bool list::delete_end()
{
    if(is_empty())
        return false;
    if(!head->next)
        head = tail = 0;
    t_node *t = head;
    for(;t->next != tail; t = t->next);
    delete tail;
    tail = t;
    t->next = 0;
    return true;
}

int main()
{
    list num;

    num.add_end(1);
    num.add_end(2);
    num.add_end(3);
    num.add_end(4);
    num.add_end(5);
    num.print();

    num.print();

    list num1;
    num1.add_begin(10);
    num1.add_begin(20);
    num1.print();

    return 0;
}
