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
        bool delete_el(int v); //done

        void print_list(); // done
        bool search_el(int v); // done
        int search_pos(int v); // done
        int list_size(); // done
        bool is_sorted(); // done
        bool reverse_list(); // done
        bool delete_all(int v); //done
        int get_middle(); // done
        int count_occur(int v); // done
        bool remove_dup_sorted(); // done
        int get_nth(int n); // done


        void add_last_front();


        ~list();
        list(list &o);
        void operator=(list &o);
};

void list::add_last_front()
{
    node *tmp = head;
    while(tmp->next)
        tmp = tmp->next;
    add_begin(tmp->data);
    // delete_end();
}

int list::get_nth(int n)
{
    if(is_empty())
        return -1;
    node *tmp = head;
    for(int i = 1; i < n; i++)
        tmp = tmp->next;
    return tmp->data;
}

bool list::remove_dup_sorted()
{
    if(!is_sorted())
        return false;
    node *tmp = head;
    while(tmp)
    {
        int c = 0;
        if((c = count_occur(tmp->data)) > 1)
        {
            while(c-- > 1)
            {
                node *saved = tmp->next;
                delete_el(tmp->data);
                tmp = saved;
                continue;
            }
        }
        tmp = tmp->next;
    }
    return true;
}


int list::count_occur(int v)
{
    int res = 0;
    node *tmp = head;
    while(tmp)
    {
        if(tmp->data == v)
            res++;
        tmp = tmp->next;
    }
    return res;
}


bool list::delete_all(int v)
{
    if(is_empty())
        return false;
    node *tmp = head;
    while(tmp)
    {
        node *saved = tmp->next;
        if(tmp->data == v)
            delete_el(v);
        tmp = saved;
    }
    return true;
}

int list::get_middle()
{
    int len = list_size();
    node *tmp = head;
    for(int i = 1; i<=len/2;i++)
        tmp = tmp->next;
    return tmp->data;
}


bool list::reverse_list()
{
    if(is_empty() || !head->next)
        return true;
    node *current = head;
    node *prev = 0;
    node *next_ = 0;
    
    while(current)
    {
        next_ = current->next;
        current->next = prev;
        prev = current;
        current = next_;
    }
    tail = head;
    head = prev;
    return true;
}


bool list::is_sorted()
{
    node *tmp = head;
    while(tmp->next)
    {
        if(tmp->data > tmp->next->data)
            return false;
        tmp = tmp->next;
    }
    return true;
}

bool list::delete_el(int v)
{
    if(is_empty())
        return false;
    int pos = 1;
    node *tmp = head;
    while(tmp)
    {
        if(tmp->data == v)
            return (delete_pos(pos), true);
        pos++;
        tmp = tmp->next;
    }
    return false;
}

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
        return (delete_begin());
    else if(pos == list_len)
        return (delete_end());
    node *tmp = head, *del;
    for(int i = 1; i < pos - 1; i++)
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
    while(tmp)
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

    while(tmp)
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

    while(tmp)
    {
        counter++;
        tmp = tmp->next;
    }
    return counter;
}

int main()
{
    list num;
    
    num.add_end(1);
    num.add_end(0);
    num.add_end(2);
    num.add_end(0);
    num.add_end(3);
    num.add_end(0);
    num.add_end(4);
    num.add_end(0);
    num.add_end(5);
    num.add_end(0);
    
    num.print_list();
    
    int len = num.list_size();
    while(len--)
    {
        int pos;
        if((pos = num.search_pos(0)) != -1)
        {
            num.add_pos(10, pos);
            num.delete_pos(pos);
        }
    }
    num.print_list();
    num.add_last_front();
    num.print_list();
    return 0;
}
