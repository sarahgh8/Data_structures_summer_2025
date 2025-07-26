#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int d, node *n = 0)
    {
        data = d;
        next = n;
    }
};

class list
{
    node *head, *tail;
    public:
        list() { head = tail = 0;}
        bool is_empty() { return head == 0;}
        
        void add_end(int v); // done
        void add_begin(int v); // done
        bool add_pos(int v, int pos);

        bool delete_end(); // done
        bool delete_begin(); // done
        bool delete_pos(int pos); // pos
        bool delete_el(int v);

        void print_list(); // done
        bool search_el(int v); // done
        int search_pos(int v); // done
        int list_size(); // done

        ~list();
        list(list &o);
        void operator=(list &o);
};

void list::operator=(list &o)
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

list::~list()
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

list::list(list &o)
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

bool list::add_pos(int v, int pos)
{
    int list_len = list_size();
    if(pos <= 0 || pos > list_len + 1)
        return false;
    if(is_empty())
    {
        head = tail = new node(v, 0);
        return true;
    }
    else if(pos == 1)
        return (add_begin(v), true);
    else if(pos == list_len + 1)
        return (add_end(v), true);
    node *tmp = head;
    for(int i = 1; i < pos; i++)
        tmp = tmp->next;
    tmp->next = new node(v, tmp->next);
    return true;
}

bool list::delete_pos(int pos)
{
    int list_len = list_size();
    if(pos <= 0 || pos > list_len)
        return false;
    else if(pos == 1)
        return (delete_begin(), true);
    else if(pos == list_len)
        return (delete_end(), true);
    node *tmp = head, *del;
    for(int i = 1; i < pos; i++)
        tmp = tmp->next;
    del = tmp->next;
    tmp->next = del->next;
    delete del;
    return true;
}


void list::add_begin(int v)
{
    if(is_empty())
    {
        head = tail = new node(v, 0);
        return ;
    }
    head = new node(v, head);
}

bool list::delete_begin()
{
    if(is_empty())
        return false;
    if(!head->next)
    {
        delete head;
        head = tail = 0;
        return true;
    }
    node *tmp = head;
    head = head->next;
    delete tmp;
    return true;
}


void list::add_end(int v)
{
    if(is_empty())
    {
        head = tail = new node(v, 0);
        return ;
    }
    tail->next = new node(v, 0);
    tail = tail->next;
}

bool list::delete_end()
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
    tmp->next = 0;
    return true;
}

void list::print_list()
{
    node *tmp = head;
    while(tmp)
    {
        cout << tmp->data << " ";
        tmp = tmp->next;
    }
    cout << endl;
}
bool list::search_el(int v)
{
    node *tmp = head;
    while(tmp->next)
    {
        if(tmp->data == v)
            return true;
        tmp = tmp->next;
    }
    return false;
}
int list::search_pos(int v)
{
    int pos = 1;
    node *tmp = head;

    while(tmp->next)
    {
        if(tmp->data == v)
            return pos;
        pos++;
        tmp = tmp->next;
    }
    return -1;
}
int list::list_size()
{
    int counter = 0;
    node *tmp = head;

    while(tmp->next)
    {
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

int main()
{
    list num;

    num.add_begin(2);
    num.add_end(3);
    num.add_begin(1);
    num.add_end(4);

    num.print_list();

    list new_num;
    new_num.add_begin(4);
    new_num.add_end(47);
    new_num.add_begin(9);
    new_num.add_end(11);
    new_num.print_list();

    new_num = num;
    new_num.print_list();

    list num3 = new_num;
    num3.print_list();
    return 0;
}
