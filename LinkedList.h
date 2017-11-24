#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
template <typename value>
class List
{
private:
    struct Node
    {
        value item;
        Node* prev;
        Node* next;
    };
    int count;
    int e;
    Node* head;
    Node* tail;
   // ofstream out;
    value stuff;
public:
List<value>()
    {
        head=NULL;
        tail=NULL;
        stuff=value();
        e=0;
        count=0;
    }
~List()
    {
        e=1;
        clear();
        //out.close();
    }
void clear()
    {
        if(e == 0)
        {
            //out<<"clear"<<endl;
        }
        e=1;
        while (count != 0)
        {
            remove(0);
        }
        e=0;
    }
void insert(int i, value n)
    {
        Node* node=new Node();
        node->item=n;
        if (i==0)
        {
            head=node;
            tail=node;
        }
       /* else if (i>count || i < 0)
        {
        }*/
        else
        {
            /*if (i == 0)
            {
                head->prev=node;
                node->next=head;
                node->prev=NULL;
                head=node;
            }
            else if (i == count)
            {*/
                tail->next=node;
                node->prev=tail;
                node->next=NULL;
                tail=node;
           /* }
           else
           {
               interInsert(i, n, node);
           }*/
        }
        count++;
    }
    
void interInsert(int i, value n, Node* node)
{
    int med=count/2;
        if (i>med)
            {
                int num = count-1;
                Node* temp2=tail->prev;
                Node* temp=tail;
                while(num != i)
                {
                    temp2=temp2->prev;
                    temp=temp->prev;
                    num--;
                }
                temp2->next=node;
                node->prev=temp2;
                temp->prev=node;
                node->next=temp;
               // delete temp;
                //delete temp2;//how do I delete these without causing more problems
                //node->next=temp->next;
            }
            else if (i<=med)
            {
                int num =1;
                Node* temp2=head->next;
                Node* temp=head;
                while(num != i)
                {
                    temp2=temp2->next;
                    temp=temp->next;
                    num++;
                }
                node->next=temp2;
                temp2->prev=node;
                node->prev=temp;
                temp->next=node;
            }
           // out<<"insert "<<i<<" "<<n<<endl;
}
    
    
int size()
    {
        return count;
    }

string print()
    {
        stringstream ss;
        Node* temp=head;
        for(int i =0; i<count; i++)
        {
         ss<<temp->item<<" ";
            if (temp->next != NULL)
            {
            temp=temp->next;
            }
        }
        return ss.str();
    }
value find(value n)
    {
        Node* temp =head;
        for (int i=0; i<count; i++)
        {
            if (temp->item == n)
            {
               // out<<"find "<<n<<" "<<i<<endl;
                return temp->item;
            }
            temp=temp->next;
        }
        return value();
       // out<<"find "<<n<<" "<<-1<<endl;
    }
    
    
    value finder(int n)
    {
        int i=0;
        //cout<<n<<endl;
        Node* temp =head;
        while (i != n)
        {
            temp=temp->next;
            i++;
        }
        return temp->item;
        // out<<"find "<<n<<" "<<-1<<endl;
    }

    int index(value n)
    {
        Node* temp =head;
        for (int i=0; i<count; i++)
        {
            if (temp->item == n)
            {
                // out<<"find "<<n<<" "<<i<<endl;
                return i;
            }
            temp=temp->next;
        }
        return -1;
        // out<<"find "<<n<<" "<<-1<<endl;
    }
    
    value iter(int n)
    {
        Node* temp =head;
        for (int i=0; i<count; i++)
        {
            if (i == n)
            {
                // out<<"find "<<n<<" "<<i<<endl;
                return temp->item;
            }
            temp=temp->next;
        }
        return NULL;
        // out<<"find "<<n<<" "<<-1<<endl

    }
value remove(int i)
    {
        Node* temp;
        if (i<0 || i > count || count == 0)
        {
        }
        else if (count ==1)
        {
            temp=head;
            temp->prev=NULL;
            temp->next=NULL;
            stuff=head->item;
            delete temp;
            head=NULL;
            tail=NULL;
        }
        else if (i == 0)
        {
            temp=head->next;
            stuff=head->item;
            delete head;
            temp->prev=NULL;
            head=temp;
            //out<<"remove "<<i<<" "<<stuff<<endl;
        }
        else if (i== count-1)
        {
            temp=tail->prev;
            stuff=tail->item;
            delete tail;
            temp->next=NULL;
            tail=temp;
           // out<<"remove "<<i<<" "<<stuff<<endl;
        }
        else
        {
            interRemove(i);
        }
        if (e == 0)
        {
        //out<<"remove "<<i<<" "<<stuff<<endl;
        }
        count--;
        return stuff;
    }
    
    value getHead()
    {
        return head->item;
    }
    
    void interRemove(int i)
    {
        int med= count/2;
        Node* temp;
        Node* temp2;
        Node* gone;
         if(i > med)
            {
                temp2=tail->prev->prev;
                temp =tail;
                gone=tail->prev;
                int num =count-2;
                while(num != i)
                {
                    temp2=temp2->prev;
                    temp=temp->prev;
                    gone=gone->prev;
                    num--;
                }
                temp2->next=temp;
                temp->prev=temp2;
                gone->next=NULL;
                gone->prev=NULL;
                stuff=gone->item;
                delete gone;
                //out<<"remove "<<i<<" "<<stuff<<endl;
            }
            else if (i <= med)
            {
                temp2=head->next->next;
                temp=head;
                gone=head->next;
                int num=1;
                while (num != i)
                {
                    temp2=temp2->next;
                    temp=temp->next;
                    gone=gone->next;
                    num++;
                }
                //cout<<temp2->item<<endl;
                temp2->prev=temp;
                temp->next=temp2;
                gone->prev=NULL;
                gone->next=NULL;
                stuff=gone->item;
                delete gone;
                //out<<"remove "<<i<<" "<<stuff<<endl;
            }
    }
};