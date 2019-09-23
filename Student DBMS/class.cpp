#include "class.h"
ofstream dlt("dust.txt");
ofstream fin("student_info.txt");
ofstream fout;

int cnt = 0, seek = 0;
void mark::save()
{
    system("cls");
    for(int k =0; k<loop; k++)
        write(k);
}

void student::update(int i, char ch)
{
    string nam;
    switch(ch)
    {
    case '1':
        cout<<"ENTER NEW ID NUMBER: ";
        cin>>n_id;
        id[i] = n_id;
        cout<<"THE NEW ID NUMBER OF <"<<name[i]<<"> IS UPDATED SUCCESSFULY."<<endl;
        break;
    case '2':
        cout<<"ENTER NEW ROLL NUMBER: ";
        cin>>n_roll;
        roll[i] = n_roll;
        cout<<"THE NEW ROLL NUMBER OF <"<<name[i]<<"> IS UPDATED SUCCESSFULY."<<endl;
        break;
    case '3':
        cout<<"ENTER NEW PHONE NUMBER: ";
        cin>>n_ph;
        ph[i] = n_ph;
        cout<<"THE NEW PHONE NUMBER OF <"<<name[i]<<"> IS UPDATED SUCCESSFULY."<<endl;
        break;
    case '4':
        cout<<"ENTER NEW NAME: ";
        nam = name[i];
        cin>>n_name;
        name[i] = n_name;
        cout<<"THE NEW NAME OF <"<<nam<<"> IS UPDATED SUCCESSFULY."<<endl;
        break;
    default:
        cout<<"INVALID CHOICE."<<endl;

    }
}
void student::write(int i)
{
    fout<<id[i]<<endl;
    fout<<roll[i]<<endl;
    fout<<ph[i]<<endl;
    fout<<name[i]<<endl;
    fout<<department[i]<<endl;

    fin<<"Id: "<<id[i]<<endl;
    fin<<"Roll: "<<roll[i]<<endl;
    fin<<"Name: "<<name[i]<<endl;
    fin<<"Department: "<<department[i]<<endl;
    fin<<"Phone number: "<<ph[i]<<endl<<endl;
}
void mark:: read()
{
    system("cls");
    for(int k =0; k<loop; k++)
        show(k);
}
void student::set_from()
{
    ifstream input_file;
    input_file.open("input.txt");
    string str;
    int i = 0, p = 1;
    while(getline(input_file, str))
    {
        stringstream sin(str);
        if(p%5==1)
        {
            sin>>id[i];
            p++;
        }
        else if(p%5==2)
        {
            sin>>roll[i];
            p++;

        }
        else if(p%5==3)
        {
            sin>>ph[i];
            p++;

        }
        else if(p%5==4)
        {
            sin>>name[i];
            p++;

        }
        else
        {
            sin>>department[i];
            p++;
            i++;
            cnt = i;
            loop++;
        }
    }
    input_file.close();
    fout.open("input.txt");
}
void mark:: search_by()
{
    system("cls");

    cout<<endl<<"ENTER [1] FOR SEARCH BY ID NUMBER."<<endl;
    cout<<"ENTER [2] FOR SEARCH BY ROLL NUMBER."<<endl;
    cout<<"ENTER [3] FOR SEARCH BY PHONE NUMBER."<<endl;
    cout<<"ENTER [4] FOR SEARCH BY STUDENT  NAME."<<endl;
    cout<<"ENTER [5] FOR SEARCH BY STUDENT DEPARTMENT."<<endl;

    char choice;
    cout<<endl<<"ENTER YOUR CHOICE: ";
    cin>>choice;
    if(choice=='1')
    {
        cout<<"ENTER SEARCH ID NUMBER : ";
        cin>>s_id;
        int i, flag = 1;
        system("cls");
        for( i = 0; i<loop; i++)
        {
            if(id[i]==s_id)
            {
                flag = 0;
                show(i);
            }
        }
        if(flag)
            cout<<"NOTHING MATCH WITH GIVEN INFORMATION."<<endl;
    }
    else if(choice=='2')
    {
        cout<<"ENTER SEARCH ROLL NUMBER : ";
        cin>>s_roll;
        int i, flag = 1;
        system("cls");
        for( i = 0; i<loop; i++)
        {
            if(roll[i]==s_roll)
            {
                flag = 0;
                show(i);
            }

        }
        if(flag)
            cout<<"NOTHING MATCH WITH GIVEN INFORMATION."<<endl;
    }
    else if(choice=='3')
    {
        cout<<"ENTER SEARCH PHONE NUMBER : ";
        cin>>s_ph;
        int i, flag = 1;
        system("cls");
        for( i = 0; i<loop; i++)
        {
            if(ph[i]==s_ph)
            {
                flag = 0;
                show(i);
            }
        }
        if(flag)
            cout<<"NOTHING MATCH WITH GIVEN INFORMATION."<<endl;
    }
    else if(choice=='4')
    {
        cout<<"ENTER SEARCH STUDENT NAME : ";
        cin>>s_name;
        int i, flag = 1;
        system("cls");
        for( i = 0; i<loop; i++)
        {
            if(s_name == name[i])
            {
                flag = 0;
                show(i);
            }
        }
        if(flag)
            cout<<"NOTHING MATCH WITH GIVEN INFORMATION."<<endl;
    }
    else if(choice=='5')
    {
        cout<<"ENTER SEARCH STUDENT DEPARTMENT : ";
        cin>>s_department;
        int i, flag = 1;
        system("cls");
        for( i = 0; i<loop; i++)
        {
            if(s_department == department[i])
            {
                flag = 0;
                show(i);
            }
        }
        if(flag)
            cout<<"NOTHING MATCH WITH GIVEN INFORMATION."<<endl;
    }
}

void mark:: update_by()

{
    system("cls");

    cout<<endl<<"THE LIST OF STUDENT NAME IS GIVEN BELOW: "<<endl;
    for(int i = 0; i<loop; i++)
        cout<<" ["<<i+1<<"] "<<name[i]<<endl;

    cout<<endl<<"WHICH CONTACT DO YOU WANT TO UPDATE."<<endl;
    cout<<"ENTER A STUDENT NAME TO UPDATE FROM THE LIST: ";
    cin>>s_name;
    int i, flag = 1, hold;
    for( i = 0; i<loop; i++)
    {
        if(s_name == name[i])
        {
            flag = 0;
            hold = i;
            break;
        }
    }
    if(flag)
        cout<<"NOTHING MATCH WITH GIVEN INFORMATION."<<endl;

    else
    {
        cout<<endl<<"Updating  student:  "<<s_name;
        show(hold);

        cout<<endl<<"ENTER [1] FOR UPDATE  ID NUMBER."<<endl;
        cout<<"ENTER [2] FOR UPDATE  ROLL NUMBER."<<endl;
        cout<<"ENTER [3] FOR UPDATE  PHONE NUMBER."<<endl;
        cout<<"ENTER [4] FOR UPDATE  STUDENT NAME."<<endl;

        char choice;
        cout<<endl<<"ENTER YOUR CHOICE: ";
        cin>>choice;
        if(choice=='1')
            update(hold, choice);

        else if(choice=='2')
            update(hold, choice);

        else if(choice=='3')
            update(hold, choice);

        else if(choice=='4')
            update(hold, choice);
    }
}

void mark::delet()
{
    system("cls");

    cout<<endl<<"THE LIST OF STUDENT NAME IS GIVEN BELOW: "<<endl;
    for(int k = 0; k<loop; k++)
        cout<<" ["<<k+1<<"] "<<name[k]<<endl;

    cout<<endl<<"WHICH CONTACT DO YOU WANT TO DELETE."<<endl;
    cout<<"ENTER A STUDENT NAME TO DELETE FROM THE LIST: ";
    cin>>d_name;
    int i;
    for(  i = 0; i<loop; i++)
    {
        if(name[i] == d_name)
        {
            cout<<endl<<"ARE YOU SURE YOU WANT TO DELETE STUDENT <"<<d_name<<"> INFORMATION."<<endl;
            cout<<"ENTER 1 FOR YES OR 0 FOR NO."<<endl;
            char op;
            cin>>op;
            if(op == '1')
            {

                dlt<<"Id: "<<id[i]<<endl;
                dlt<<"Roll: "<<roll[i]<<endl;
                dlt<<"Name: "<<name[i]<<endl;
                dlt<<"Department: "<<department[i]<<endl;
                dlt<<"Phone Number: "<<ph[i]<<endl;
                dlt<<endl;
                for(int j = i; j<loop-1; j++)
                {
                    id[j] = id[j+1];
                    roll[j] = roll[j+1];
                    ph[j] = ph[j+1];
                    name[j] = name[j+1];
                    department[j] = department[j+1];
                }
                cnt--;
                loop--;
                seek = 1;
                cout<<"THE INFORMATION OF STUDENT <"<<d_name<<"> IS SUCCESSFULLY DELETED"<<endl;
                break;
            }
            else if (op == '0')
            {
                seek = 0;
                return;
            }
        }
    }
    if(seek == 0)
    {
        cout<<"NOTHING MATCH WITH GIVEN INFORMATION."<<endl;
        return;
    }
    seek = 0;
}

void student::setInfo()
{
    int i;
    loop++;
    system("cls");
    for( i = cnt; i<loop; i++)
    {
        cout<<"ENTER ID: ";
        cin>>id[i];
        cout<<"ENTER ROLL: ";
        cin>>roll[i];
        cout<<"PHONE NUMBER: ";
        cin>>ph[i];
        cout<<"ENTER NAME: ";
        cin>>name[i];
        cout<<"ENTER DEPARTMENT: " ;
        cin>>department[i];
        cout<<endl<<"DO YOU WANT TO ADD ANY STUDENT INFO."<<endl;
        cout<<"PRESS 1 FOR CONTINUE OR 0  FOR NO."<<endl;
        char option;
        cin>>option;
        if(option=='0')
            break;
        else if(option == '1')
            loop++;
        else
            cout<<"INVALID CHOICE"<<endl;
    }
    cnt = ++i;
}
void student::show(int i)
{
    cout<<endl<<"Id: "<<id[i]<<endl;
    cout<<"Roll: "<<roll[i]<<endl;
    cout<<"Name: "<<name[i]<<endl;
    cout<<"Department: "<<department[i]<<endl;
    cout<<"Phone number: "<<ph[i]<<endl;
}
