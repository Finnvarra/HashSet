#include "LinkedList.h"
template <typename value>
class Hash
{
    List<string> queue;
    List<value>* ar;
    unsigned itemnum;
    ofstream out;
    unsigned amount;
public:
    Hash (string file2)
    {
        out.open(file2);
        amount =0;
        itemnum=0;
        ar= NULL;
    }
    ~Hash()
    {
        clear(1);
        out.close();
    }
    void clear(int print)
    {
        if (print == 0)
        {
        out<<"clear"<<endl;
        }
        delete[] ar;
       /* while(itemnum != 0)
        {
            for (int i=0; i<amount; i++)
            {
                if(ar[i].size() != 0)
                {
                    remove(ar[i].getHead(), 1);
                    itemnum--;
                }
            }
        }*/
        amount=0;
        ar=NULL;
    }
    
    void add(value name)
    {
        out<<"add "<<name<<endl;
       if (find(name, 1) != true)
        {
            //cout<<"number of items and size "<<itemnum<<" "<<amount<<endl;
            if (itemnum == amount)
            {
               // cout<<"made it to rehash"<<endl;
                rehash();
            }
        itemnum++;
       // cout<<"increased size "<<itemnum<<endl;
        int place=hash(name, amount);
       // cout<<ar[place].size()<<endl;
        ar[place].insert(ar[place].size(), name);
        }
    }
    int hash(value n, int s)
    {
        unsigned hashindex=0;
        for (int i=0; i<n.length(); i++)
        {
            hashindex*=31;
            hashindex+=n[i];
        }
        //cout<<hashindex<<endl;
        hashindex=hashindex%s;
        //cout<<hashindex<<endl;
        return hashindex;
    }
    void rehash()
    {
        
        int n= amount*2+1;
        //cout<<"new array size"<<n<<endl;
        List<value>* temp= new List<value>[n];
        for (int i=0; i<itemnum; i++)
        {
            for(int j=0; j<amount; j++)
            {
                if(ar[j].size()!=0)
                {
                   int place=hash(ar[j].getHead(), n);
                    
                    temp[place].insert(temp[place].size(), ar[j].getHead());
                    remove(ar[j].getHead(), 1);
                    break;
                }
            }
        }
        amount=n;
        delete[] ar;
        ar=temp;
    }
    
    void print()
    {
        out<<"print"<<endl;
        //cout<<"num of items "<<itemnum<<endl;
        if (itemnum == 0)
        {
            return;
        }
        for(int i=0; i<amount; i++)
        {
            if (i != 0)
            {
                out<<endl;
            }
            out<<"hash "<<i<<": ";
            int num=ar[i].size()/8;
            //cout<<"num "<<num<<endl;
            int leftover=ar[i].size()%8;
            //cout<<"leftover "<<leftover<<endl;
           printcont (num, leftover, i, amount);
        }
        out<<endl;
    }
    
    void printcont(int num, int leftover, int i, int amount)
    {
        int size=0;
        int plus=0;
         while (num != 0 || leftover != 0)
           {
            if (num != 0)
            {
                size =8;
                num--;
            }
            else
            {
                size = leftover;
                leftover=0;
            }
               for (int j=0; j<size; j++)
               {
                   out<<ar[i].finder(j+plus)<<" ";
               }
               if (i !=amount -1 && (num != 0 || leftover != 0))
               {
                   out<<endl<<"hash "<<i<<": ";
               }
               plus+=8;
           }
    }
    
    bool find(value name, int print)
    {
        if (amount == 0)
        {
            if (print == 0)
            {
            out<<"find "<<name<<" false"<<endl;
            }
            return false;
        }
        int place=hash(name, amount);
        //cout<<"place"<<place<<" "<<ar[place].size()<<endl;
        for (int i=0; i<ar[place].size(); i++)
        {
            if (ar[place].find(name)== name)
            {
                if (print == 0)
                {
                out<<"find "<<name<<" "<<"true"<<endl; 
                return true;
                }
               return true;
            }
        }
        if (print == 0)
        {
            out<<"find "<<name<<" false"<<endl;
        }
       // cout<<"not here"<<endl;
        return false;
    }
    void remove(value name, int print)
    {
        //cout<<"amount "<<amount<<endl;
        //cout<<"itemnum "<<itemnum<<endl;
        if(find(name, 1)==false)
        {
            out<<"remove "<<name<<endl;
            return;
        }
        int place=hash(name, amount);
        for (int i=0; i<ar[place].size(); i++)
        {
            int index= ar[place].index(name);
            if (index != -1)
            {
                ar[place].remove(index);
                //cout<<"removed"<<endl;
            }
        }
         if (print == 0)
        {
        out<<"remove "<<name<<endl;//num/size=size/2

        itemnum--;
      //  cout<<itemnum<<endl;
        //cout<<"destuff "<<itemnum/(amount-itemnum)<<" "<<amount/2<<endl;
        if (itemnum == amount/2)
        {
            //cout<<"dehashing"<<endl;
            dehash();
        }
        }
    }
    void dehash()
    {
        int n= amount/2;
       // cout<<"new array size"<<n<<endl;
        List<value>* temp= new List<value>[n];
        for (int i=0; i<itemnum; i++)
        {
            for(int j=0; j<amount; j++)
            {
                if(ar[j].size()!=0)
                {
                   // cout<<"new smaller array size "<<n<<endl;
                    if(n != 0)
                    {
                    int place=hash(ar[j].getHead(), n);
                    temp[place].insert(temp[place].size(), ar[j].getHead());
                    }
                    remove(ar[j].getHead(), 1);
                    break;
                }
            }
        }
        amount=n;
        delete[] ar;
        ar=temp;
    }
};