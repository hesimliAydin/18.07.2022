#include <iostream>
using namespace std;
#include"Shared_ptr.h"

int main()
{
    SharedPointer<int> sp(new int(11));
    SharedPointer<int> sp2(sp);

    cout << *sp.get() << endl;
    cout << sp2.operator*() << endl;
    
}


