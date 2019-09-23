#include<bits/stdc++.h>
using namespace std;
ofstream fout;
ifstream fin;
int cnt = 0;
string s_roll, s_id, s_ph, s_name;
class student
{
    string name, department;
    string roll, id, ph;
public:

    void save();
    friend void setFile(student s1[]);
    string getName() { return name; }
    friend istream& operator>>(istream& cin, student &s);
    friend ostream& operator<<(ostream& cout, student &s);
    bool operator == (string st);
    int updateInfo();

};

    void student:: save()
    {
        fout.open("input.txt", ios::app);
        fout<<id<<endl;
        fout<<roll<<endl;
        fout<<ph<<endl;
        fout<<name<<endl;
        fout<<department<<endl;
        fout.close();

        fout.open("data.txt",ios::app);
        fout<<"Id: "<<id<<endl;
        fout<<"Roll: "<<roll<<endl;
        fout<<"Name: "<<name<<endl;
        fout<<"Department: "<<department<<endl;
        fout<<"Phone number: "<<ph<<endl;
        fout<<endl;
        fout.close();
    }

    bool student:: operator == (string st)
    {
        if(name == st)
            return true;
        else
            return false;
    }

istream& operator>>(istream& cin, student &s)
{
    cout<<"Enter id: ";
    cin>>s.id;
    cout<<"Enter roll: ";
    cin>>s.roll;
    cout<<"Phone number: ";
    cin>>s.ph;
    cout<<"Enter name: ";
    cin>>s.name;
    cout<<"Enter department: " ;
    cin>>s.department;
    return cin;
}

    ostream& operator<<(ostream& cout, student &s)
    {
        cout<<"Id: "<<s.id<<endl;
        cout<<"Roll: "<<s.roll<<endl;
        cout<<"Name: "<<s.name<<endl;
        cout<<"Department: "<<s.department<<endl;
        cout<<"Phone number: "<<s.ph<<endl;
        return cout;

    }
int student::updateInfo()
{
    cout<<"Enter 1 to update id"<<endl;
    cout<<"Enter 2 to update roll"<<endl;
    cout<<"Enter 3 to update name"<<endl;
    cout<<"Enter 4 to update phone number"<<endl;

    char option;
    cin>>option;
    switch(option)
    {
    case '1':
        cout<<"Enter new id : ";
        cin>>id;
        break;
    case '2':
        cout<<"Enter new roll : ";
        cin>>roll;
        break;
    case '3':
        cout<<"Enter new name : ";
        cin>>name;
        break;
    case '4':
        cout<<"Enter new phone number : ";
        cin>>ph;
        break;

    default:
        cout<<"Invalid choice"<<endl;
        return 0;
    }
    return 1;
}

void setFile(student s1[])
{
    fin.open("input.txt");
    string str;
    int p = 1;
    while(getline(fin, str))
    {
        stringstream sin(str);
        if(p%5==1)
        {
            sin>>s1[cnt].id;
            p++;
        }
        else if(p%5==2)
        {
            sin>>s1[cnt].roll;
            p++;

        }
        else if(p%5==3)
        {
            sin>>s1[cnt].ph;
            p++;

        }
        else if(p%5==4)
        {
            sin>>s1[cnt].name;
            p++;

        }
        else
        {
            sin>>s1[cnt].department;
            p++;
            cnt++;
        }
    }
    fin.close();

}

int main()
{

    student s1[100];
    vector<student> st;

    setFile(s1);
    for(int j = 0; j<cnt; j++)
        st.push_back(s1[j]);

    cnt--;
    int srt = cnt;
main:
    //system("cls");
    cout<<"Enter 1 for add info"<<endl;
    cout<<"Enter 2 for show"<<endl;
    cout<<"Enter 3 for search"<<endl;
    cout<<"Enter 4 for update"<<endl;
    cout<<"Enter 5 for delete"<<endl;

    int flag = 1, flag1 = 1, flag2 = 1, m;
    char option;
    cin>>option;
    switch(option)
    {
    case '1':
add:
        srt++;
        cin>>s1[srt];
        st.push_back(s1[srt]);
        cout<<"Do you want to add another info"<<endl;
        cout<<"Enter 1 for YES of 0 for NO"<<endl;
        char op;
        cin>>op;
        if(op == '1')
            goto add;
        else
            break;
    case '2':
        system("cls");
        if(st.empty())
        {
            cout<<"The list is empty..."<<endl;
            break;
        }
        cout<<endl<<">>>ALL STUDENT INFORMATION ARE SHOWN BELOW<<<"<<endl;
        for(int it=0; it<st.size(); it++)
        {
            cout<<endl;
            cout<<st[it];
        }

        break;
    case '3':
        if(st.empty())
        {
            cout<<"The list is empty..."<<endl;
            break;
        }
        cout<<"Enter a name to search"<<endl;
        cin>>s_name;
        for( int i=0; i<st.size(); i++)
        {
            if(st[i] == s_name)
            {
                flag = 0;
                cout<<st[i];
                break;
            }

        }
        if(flag)
            cout<<"Didn't match with any student information"<<endl;
        break;

    case '4':
        system("cls");
        if(st.empty())
        {
            cout<<"The list is empty..."<<endl;
            break;
        }
        cout<<"The list of the student "<<endl;
        for(int i = 0; i<st.size(); i++)
            cout<<s1[i].getName()<<endl;

        cout<<endl<<"Enter a name to update from the list"<<endl;
        cin>>s_name;
        for( int i=0; i<st.size(); i++)
        {
            if(st[i] == s_name)
            {
                flag1 = 0;
                cout<<st[i]<<endl;
                cout<<endl<<"Updating: "<<s_name<<endl;
                m = s1[i].updateInfo();
                st[i] = s1[i];
                if(m)
                    cout<<"The student <"<<s_name<<"> information is successfully updated"<<endl;
            }
        }
        break;
        if(flag1)
            cout<<"Didn't match with any student information"<<endl;
        break;
    case '5':
        system("cls");
        if(st.empty())
        {
            cout<<"The list is empty..."<<endl;
            break;
        }

        cout<<endl<<"Enter a name you want to delete:"<<endl;
        cin>>s_name;
        vector<student>::iterator itr = st.begin();
        for(itr; itr!=st.end(); itr++)
        {
            if(*itr == s_name)
            {
                flag2 = 0;
                st.erase(itr);
                cout<<"The student <"<<s_name<<"> information is successfully deleted"<<endl;
                break;
            }
        }
        if(flag2)
            cout<<"Didn't match with any student information"<<endl;
        break;
    }
    remove("input.txt");
    remove("data.txt");
    for(int it=0; it<st.size(); it++)
        st[it].save();
    system("pause");
    cout<<"Enter <e> for exit or other any key for continue"<<endl;
    cin>>option;
    if(option == 'e')
    {
        cout<<"THANKS FOR USING  THIS SOFTWARE"<<endl;
        return 0;
    }
    else
        goto main;
}

