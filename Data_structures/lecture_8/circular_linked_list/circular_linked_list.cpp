#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int d, node *n)
    {
        data = d;
        next = n;
    }
};

class c_list
{
    node *head, *tail;
    public:
        c_list() { head = tail = 0;}
        bool is_empty() { return head == 0;}
        
        void add_end(int v);

        bool delete_end();

        void print_c_list();
        bool search_el(int v);
        int search_pos(int v);
        int c_list_size();

        ~c_list();
};

c_list::~c_list()
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


bool c_list::delete_end()
{
    if(is_empty())
        return false;
    else if(!head->next)
    {
        delete head;
        head = tail = 0;
        return true;
    }
    node *tmp = head;
    while(tmp->next != tail)
        tmp = tmp->next;
    tail = tmp;
    delete tmp->next;
    tail->next = head;
    return true;
}


void c_list::add_end(int v)
{
    if(is_empty())
    {
        tail = head = new node(v, head);
        return ;
    }
    node *tmp = head;
    while(tmp->next)
        tmp = tmp->next;
    tmp->next = new node(v, head);
}

void c_list::print_c_list()
{
    node *tmp = head;
    while(tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

bool c_list::search_el(int v)
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

int c_list::search_pos(int v)
{
    int pos = 1;
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

int c_list::c_list_size()
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

int main()
{
    c_list num;

    num.add_end(1);
    num.add_end(2);
    num.add_end(3);
    num.add_end(4);
    num.add_end(5);

    num.print_c_list();

    num.delete_end();
    num.delete_end();

    num.print_c_list();
    return 0;
}