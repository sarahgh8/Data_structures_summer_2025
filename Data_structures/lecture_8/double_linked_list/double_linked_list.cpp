#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;

    node(int d, node *n, node *p)
    {
        data = d;
        next = n;
        prev = p;
    }
};

class d_list
{
    node *head, *tail;
    public:
        d_list() { head = tail = 0;}
        bool is_empty() { return head == 0;}
        
        void add_end(int v);
        void add_begin(int v);
        bool add_pos(int v, int pos);

        bool delete_end();
        bool delete_begin();
        bool delete_pos(int pos); 

        void print_d_list();
        bool search_el(int v);
        int search_pos(int v);
        int d_list_size();

        ~d_list();
        d_list(d_list &o);
        void operator=(d_list &o);
};

void d_list::add_end(int v)
{
    if(is_empty())
    {
        head = tail = new node(v, 0, 0);
        return ;
    }
    tail = tail->next = new node(v, 0, tail);
}

void d_list::add_begin(int v)
{
    if(is_empty())
    {
        head = tail = new node(v, 0, 0);
        return ;
    }
    head = head->prev = new node(v, head, 0);
}

bool d_list::add_pos(int v, int pos)
{
    int len = d_list_size();
    if(pos <= 0 || pos > len + 1)
        return false;
    else if(pos == 1)
        return(add_begin(v), true);
    else if(pos == len + 1)
        return(add_end(v), true);
    node *tmp = head;
    for(int i = 1; i < pos - 1; i++)
        tmp = tmp->next;
    tmp->next = new node(v, tmp->next, tmp);
    tmp->next->next->prev = tmp->next;
    return true;
}


bool d_list::delete_end()
{
    if(is_empty())
        return false;
    if(!head->next)
    {
        delete head;
        head = tail = 0;
        return true;
    }
    node *tmp = tail;
    tail = tail->prev;
    tail->next = 0;
    delete tmp;
    return true;
}

bool d_list::delete_begin()
{
    if(is_empty())
        return false;
    if(!head->next)
    {
        delete head;
        head = tail = 0;
        return 0;
    }
    node *tmp = head;
    head = head->next;
    head->prev = 0;
    delete tmp;
    return true;
}

bool d_list::delete_pos(int pos)
{
    int len = d_list_size();
    if(pos <= 0 || pos > len)
        return false;
    else if(pos == 1)
        return(delete_begin(), true);
    else if(pos == len)
        return(delete_end(), true);
    node *tmp = head;
    for(int i = 1; i < pos; i++)
        tmp = tmp->next;
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
    delete tmp;
    return true;
}


void d_list::print_d_list()
{
    node *tmp = head;
    while(tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

bool d_list::search_el(int v)
{
    node *tmp = head;
    while(tmp)
    {
        if(tmp->data == v)
            return true;
        tmp = tmp->next;
    }
    return false;
}

int d_list::search_pos(int v)
{
    int pos = 0;
    node *tmp = head;
    while(tmp)
    {
        if(tmp->data == v)
            return pos;
        pos++;
        tmp = tmp->next;

    }
    return -1;
}

int d_list::d_list_size()
{
    int counter = 0;
    node *tmp = head;
    while(tmp)
    {
        counter++;
        tmp = tmp->next;
    }
    return counter;
}


d_list::~d_list()
{
    node *tmp = head;
    while(tmp)
    {
        node *saved = tmp->next;
        delete tmp;
        tmp = saved;
    }
    head = tail = 0;
}

d_list::d_list(d_list &o)
{
    this->head = 0;
    this->tail = 0;
    node *tmp = o.head;
    while(tmp)
    {
        this->add_end(tmp->data);
        tmp = tmp->next;
    }
}

void d_list::operator=(d_list &o)
{
    while(!is_empty())
        delete_end();
    node *tmp = o.head;
    while(tmp)
    {
        this->add_end(tmp->data);
        tmp = tmp->next;
    }
}

int main()
{
    d_list num;
    num.add_end(1);
    num.add_end(2);
    num.add_end(3);
    num.add_end(4);

    num.print_d_list();

    d_list num2 = num;
    num2.print_d_list();

    d_list num3;
    num3.add_end(33);
    num3.add_end(73);
    num3.add_end(93);
    num3.add_end(13);
    num3.print_d_list();

    num3 = num2;
    num3.print_d_list();
    return 0;
}
