#include "Hash.h"

int main(int argc, char* argv[])
{
    string file1, file2;
    file1=argv[1];
    file2= argv[2];
    //cin>>file1 >> file2;
    Hash<string> A(file2);
    string name;
    string funct;
    ifstream in;
    in.open(file1);
    while (in>>funct)
    {
        if (funct == "clear")
        {
            A.clear(0);
        }
        else if(funct=="add")
        {
            in>>name;
            A.add(name);
        }
        else if (funct== "print")
        {
            A.print();
        }
        else if (funct== "find")
        {
            in>>name;
            A.find(name, 0);
        }
        else if(funct=="remove")
        {
            in>>name;
            A.remove(name, 0);
        }
    }
    in.close();
    return 0;
}
