#include<bits/stdc++.h>
using namespace std;

extern int cnt, seek;

class student
{
protected:
    string name[100], department[100], s_name, n_name, s_department, d_name;
    long int roll[100], id[100], ph[100];
    long int s_roll, s_id, s_ph, n_roll, n_id, n_ph;
public:
    int loop;
    student() : loop(0) { }
    void setInfo();
    void set_from();
    void show(int i);
    void write(int i);
    void update(int k, char ch);
};

class mark : public student
{
public:
    mark() : student()
    {
        set_from();
    }
    void delet();
    void save();
    void read();
    void update_by();
    void search_by();
};
