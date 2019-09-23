#include "code.h"
void change()
{
    string ch, ch2;
    cout<<"\t\tEnter your New Password: ";
    cin>>ch;
    cout<<"\t\tEnter your New Password Again: ";
    cin>>ch2;
    if(ch == ch2)
    {
        ofstream file("code.txt");
        file<<ch;
        cout<<"\n\\t\tPassword Has Been Successfully Changed."<<endl;
        file.close();

    }
    else
        cout<<"\n\t\tPassword Doesn't Match"<<endl;

    return;
}
