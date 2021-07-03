#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

char* returnwhat(const char *p)
{
    char *q = new char[strlen(p)+1];
    strcpy(q, p);
}

class A
{
    public:
        void my_cout()
        {
            cout << "ceshi" << endl;
        }
};

int main()
{
//     std::string s("hello");
//     std::string s1 = s;
//     std::cout << s1;
//     char *p = "nihao";
//    cout << returnwhat(p) << endl;
    // vector<A*> p;

    // p.push_back(new A);

    // p[0]->my_cout();

    char* name{"nihaoa"};
    string s{"nihaoa"};
    cout << name << endl;
    cout << s.length() << endl;
    cout << strlen(name) << endl;
    


    if(name==s) cout << "fuck" << endl;
    
    system("pause");
    return 0;
}

