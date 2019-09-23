#include "class.h"
#include "code.h"

int main()
{
    student *ptr;
    mark m;
    ptr = &m;
    static int cont;
    ifstream code("code.txt");
    string temp, cmp;
    getline(code, temp);
Again:
    system("cls");
    system("COLOR 1F");
    cout<<"\n\n\n\t\t\t>><<ENTER YOUR PASSWORD: ";
    cin>>cmp;
    if ( temp == cmp)
    {

main:
        system("cls");
        system("COLOR 2F");
        cout<<endl<<"\n\t\t>>>WELCOME TO STUDENT DATA MANAGEMENT SYSTEM<<<"<<endl;
        cout<<endl<<"\t\tEnter 1 for Add student information."<<endl;
        cout<<"\t\tEnter 2 for Searching information."<<endl;
        cout<<"\t\tEnter 3 for Updating information."<<endl;
        cout<<"\t\tEnter 4 for View all student information."<<endl;
        cout<<"\t\tEnter 5 for Delete student information."<<endl;
        cout<<"\t\tEnter 6 for Change Password."<<endl;
        cout<<"\t\tEnter 7 for Exit."<<endl;



        cout<<endl<<"\n\t\tENTER YOUR CHOICE: ";
        int op, k = 1;
        cin>>op;
        switch(op)
        {

        case 1:
            ptr ->setInfo();
            break;
        case 2:
            ((mark*)ptr)->search_by();
            break;
        case 3:
            ((mark*)ptr)->update_by();
            break;
        case 4:
            ((mark*)ptr)->read();
            break;
        case 5:
            ((mark*)ptr)->delet();
            break;

        case 7:
            cout<<endl<<"DO YOU WANT TO SAVE INFORMATION."<<endl;
            cout<<"ENTER 1 FOR YES OR 0 FOR NO . ."<<endl;
            cout<<endl<<"ENTER YOUR CHOICE: ";
            char ch;
            cin>>ch;
            if(ch == '0')
            {
                k = 0;
                break;
            }
            else
            {
                ((mark*)ptr)->save();
                cout<<endl<<"\n\n\t...INFORMATION WAS SAVE SUCCESSFULLY..."<<endl;
                k = 0;
                break;
            }
        default:
            cout<<"INVALID CHOICE."<<endl;
            return 0;


        case 6:
            system("cls");
            cout<<"\n\n\t\tEnter your Old password: ";
            cin>>cmp;
            if(cmp == temp)
                change();
            else
                cout<<"\n\t\tIncorrect password"<<endl;
            break;
        }
        if(k)
        {
            system("pause");
            goto main;
        }
        else
        {
            cout<<"\n\t >>>THANKS FOR USING THIS SOFTWARE<<<"<<endl;
            return 0;
        }
    }
    else
    {
        system("COLOR 4F");
        printf("\n\n\t\tINVALID PASSWORD\n");
        cont++;
        if(cont == 4)
        {
            cout<<"\t>>DENIED TO ACCESS THE SYSTEM<<"<<endl;
            goto Ed;
        }
        cout<<"\n\t\tWOULD YOU LIKE TO TRY AGAIN"<<endl;
        cout<<"\n\t\tPRESS 1 FOR CONTINUE OR ANY OTHER KEY FOR EXIT"<<endl;
        char choose;
        cin>>choose;
        if(choose == '1')
            goto Again;
        else
            goto Ed;
    }
Ed:
    return 0;
}

