//#include<bits/stdc++.h>
#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<fstream>
#include<windows.h>
#include<ctime>
using namespace std;


class bank{
    private:
    int pin;
    float balance;
    string id, password, f_name, l_name,address ,phone;    


    public:
    void already_user();  
    void menu();
    void bank_management();
    void atm_management();
    void new_user();
    void deposit();
    void withdraw();
    void transfer();
    void payment();
    void search();
    void edit();
    void del();
    void show_records();
    void show_payment();
    void user_balance();
    void withdraw_atm();
    void check_detail();
};

void bank::menu()
{
    p:
    //system("cls");
    int c;
    cout<<endl<<endl<<"\t\t\t";
    cout<<endl<<"1. Bank management";
    cout<<endl<<"2. ATM management";
    cout<<endl<<"3. Exit";
    cout<<endl<<endl<<"Enter Your Choice: ";
    cin>>c;
    switch(c)
    {
        case 1:
        /*If statement wasre for verification of user*//*remove upper portion ad put that in bank_management fuction*/
            bank_management();
            break;
        case 2:
            atm_management();
            break;
        case 3:
            exit(0);
            break;
        default:
            cout<<endl<<endl<<"Invalid Choice"<<endl;
            break;
    }
    getch();
    goto p;
}

void bank :: bank_management()
{
    p:
    //system("cls");
    int c;
    string email,pin,pass;
    cout<<endl<<endl<<"\t\t\t";
    cout<<endl<<"\t\t\tBank Management";
    cout<<endl<<"1. New User ";
    cout<<endl<<"2. Existing User";
    cout<<endl<<"3. Deposit";
    cout<<endl<<"4. Withdraw";
    cout<<endl<<"5. Transfer";
    cout<<endl<<"6. Bill Payment";
    cout<<endl<<"7. Search User Record";
    cout<<endl<<"8. Edit User Record";
    cout<<endl<<"9. Delete User Record";
    cout<<endl<<"10. Show All Records";
    cout<<endl<<"11. All Payment Records";
    cout<<endl<<"12. Go To Menu";
    cout<<endl<<endl<<"Enter Your Choice: ";
    cin>>c;
    //system("cls");
    switch(c)
    {
        case 1:
            new_user();
            break;
        case 2:
            already_user();
            break;
        case 3:
            deposit();
            break;
        case 4:
            withdraw();
            break;
        case 5:
            transfer();
            break;
        case 6:
            payment();
            break;
        case 7:
            search();
            break;
        case 8:
            edit();
            break;
        case 9:
            del();
            break;
        case 10:
            show_records();
            break;
        case 11:
            show_payment();
            break;
        case 12:
            menu();
            break;
        default:
            cout<<endl<<"Invalid Choice:: Please try again"<<endl;
            break;
    }
    getch();
    goto p;
}

void bank :: atm_management()
{
    p:
    //system("cls");
    int c;
    cout<<endl<<endl<<"\t\t\t";
    cout<<endl<<"\t\t\tATM Management";
    cout<<endl<<"1. User Login & Balance";
    cout<<endl<<"2. Withdraw";
    cout<<endl<<"3. Account Details";
    cout<<endl<<"4. Go To Menu";
    cout<<endl<<endl<<"Enter Your Choice: ";
    cin>>c;
    //system("cls");
    switch(c)
    {
        case 1:
            user_balance();
            break;
        case 2:
            withdraw_atm();
            break;
        case 3:
            check_detail();
            break;
        case 4:
            menu();
            break;
        default:
            cout<<"Invalid Choice:: Please Try Again"<<endl;
            break;
    }
    getch();
    goto p;
}

void bank::new_user()
{
    p:
    //system("cls");
    fstream file;
    int pi;
    float b;
    string fn, ln, pa, ph, i,a;
    cout<<endl<<endl<<"\t\t\tAdd New User";
    cout<<endl<<"Enter User ID:";
    cin>>id;
    cout<<endl<<"Enter First Name :";
    cin>>f_name;
    cout<<endl<<"Enter Last Name :";
    cin>>l_name;
    cout<<endl<<"Enter Pin Code (5 digits) :";
    cin>>pin;
    cout<<endl<<"Enter Password (5 characters):";
    cin>>password;
    cout<<endl<<"Enter Phone Number :";
    cin>>phone;
    cout<<endl<<"Enter city :";
    cin>>address;
    cout<<endl<<"Enter balance :";
    cin>>balance;

    file.open("bank.txt",ios::in);
    if(!file)
    {
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<f_name<<" "<<l_name<<" "<<pin<<" "<<password<<" "<<phone<<" "<<address<<" "<<balance<<endl;
        file.close();
    }
    else{
        file>>i>>fn>>ln>>pi>>pa>>ph>>a>>b;
        while(file)
        {
            if(i == id)
            {
                cout<<endl<<endl<<"User ID already exists please try through another ID"<<endl;
                getch();
                goto p;
            }
            file>>i>>fn>>ln>>pi>>pa>>ph>>a>>b;
        }
        file.close();
        file.open("bank.txt",ios::app|ios::out);
        file<<" "<<id<<" "<<f_name<<" "<<l_name<<" "<<pin<<" "<<password<<" "<<phone<<" "<<address<<" "<<balance;
        file.close();
    }
    cout<<endl<<"New user ID has been created"<<endl;


}

void bank:: already_user()
{
    //system("cls");
    cout<<endl<<"\t\t\tExisting User Information";
    fstream file;
    int pi;
    float b;
    string fn, ln, pa, ph, i,a;
    string t_id;
    int found=0;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl; 
    }
    else
    {
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        file>>i>>fn>>ln>>pi>>pa>>ph>>a>>b;
        
        while(file)
        {
            if(t_id==i)
            {
                //system("cls");
                //cout<<endl<<endl<<"Already Exsiting User Account";
                cout<<endl<<endl<<"User ID: "<<i<<endl<<"Pin Code: "<<pi<<endl<<"Password: "<<pa;
                found++;
            }
            file>>i>>fn>>ln>>pi>>pa>>ph>>a>>b;
        }
        file.close();
        if(found==0)
        {
            cout<<endl<<"No such User exists."<<endl;
            cout<<"To create an ID Please go to new User:"<<endl;
        }
    }
}

void bank:: deposit()
{
    fstream file, file1;
    string t_id;
    int found=0;
    float dep;
    //system("cls");
    cout<<"\n \t\t\tDeposit Amount";
    file.open("bank.txt", ios::in);

    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl; 
    }
    else
    {
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        file1.open("bank1.txt", ios::app| ios::out);

        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        
        while(file)
        {
            if(t_id==id)
            {
                cout<<"\n Enter Amount to be deposited: ";
                cin>>dep;
                balance+=dep;
                found++;
                cout<<"\n Current updated balance: "<<balance;
            }
            file1<<" "<<id<<" "<<f_name<<" "<<l_name<<" "<<pin<<" "<<password<<" "<<phone<<" "<<address<<" "<<balance;
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if(found==0)
        {
            cout<<endl<<"No such User exists."<<endl;
            //cout<<"To create an ID Please go to new User:"<<endl;
        }
    }
}

void bank:: withdraw()
{
    fstream file, file1;
    string t_id;
    int found=0;
    float with;
    //system("cls");
    cout<<"\n \t\t\tWithdraw Page";
    file.open("bank.txt", ios::in);

    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl; 
    }
    else
    {
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        file1.open("bank1.txt", ios::app| ios::out);

        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        
        while(file)
        {
            if(t_id==id)
            {
                cout<<"\n Enter Amount to be withdrawed: ";
                cin>>with;
                if(with<=balance)
                {
                    balance-=with;
                    cout<<"\n Current updated balance: "<<balance;
                }
                else
                    cout<<"\n Insufficient Funds";
                found++;
            }
            file1<<" "<<id<<" "<<f_name<<" "<<l_name<<" "<<pin<<" "<<password<<" "<<phone<<" "<<address<<" "<<balance;
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if(found==0)
        {
            cout<<endl<<"Invalid User Id"<<endl;
        }
    }
}

void bank:: transfer()
{
    fstream file, file1;
    //system("cls");
    string s_id, r_id;
    int found=0;
    float amt;
    cout<<"\n \t\t\t Transfer Page";
    file.open("bank.txt", ios::in);

    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl; 
    }
    else
    {
        cout<<endl<<"Enter Sender User ID:";
        cin>>s_id;
        cout<<endl<<"Enter Reciever User ID:";
        cin>>r_id;
        cout<<endl<<"Enter amount to be transferred: ";
        cin>>amt;

        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        
        while(file)
        {
            if(s_id==id && amt<=balance)
                found++;
            else if(r_id==id)
                found++;
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();

        if(found==2)
        {
            file1.open("bank1.txt", ios::app| ios::out);
            file.open("bank.txt", ios::in);
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        
            while(file)
            {
                if(s_id==id)
                {
                    balance-=amt; 
                }
                else if(r_id==id)
                {
                    balance+=amt; 
                }
                file1<<" "<<id<<" "<<f_name<<" "<<l_name<<" "<<pin<<" "<<password<<" "<<phone<<" "<<address<<" "<<balance;

                file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
            }
            cout<<"\n Transaction done successfully...";
            file.close();
            file1.close();
            remove("bank.txt");
            rename("bank1.txt", "bank.txt");
        }
        else
        {
            cout<<"\n\n Invalid IDs or amount...";
        }

    }
}

void bank:: payment()
{
    //system("cls");
    fstream file,file1;
    string t_id, b_name;
    SYSTEMTIME x={0};
    GetLocalTime(&x);
    float amt;
    int found=0;
    //time_t t=time(NULL);
    //char *ltm=ctime(&now);
    cout<<"\n\t\t\t Bills payment option";
    file.open("bank.txt", ios::in);

    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl; 
    }
    else
    {
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        cout<<"\n\n Bill Name: ";
        cin>>b_name;
        cout<<"\n\n Bill Amount: ";
        cin>>amt;
        file1.open("bank1.txt", ios::app| ios::out);

        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        
        while(file)
        {
            if(t_id==id && balance>=amt)
            {
                balance-=amt;
                found++;
            }
            file1<<" "<<id<<" "<<f_name<<" "<<l_name<<" "<<pin<<" "<<password<<" "<<phone<<" "<<address<<" "<<balance;

            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if(found==1)
        {
            file.open("bill.txt", ios::app| ios::out);
            file<<" "<<t_id<<" "<<b_name<<" "<<amt<<" "<<x.wDay<<" "<<x.wMonth<<" "<<x.wYear;
            file.close();
            cout<<"\n\n"<<b_name<<" Bill paid successfully";
        }
        else
        {
            cout<<"\n\n Invalid ID or Amount...";
        }
    }
}

void bank:: search()
{
    //system("cls");
    fstream file;
    string t_id;
    cout<<"\n\t\t\t Search User Records";
    
    file.open("bank.txt", ios::in);

    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl; 
    }
    else
    {
        int found=0;
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        
        while(file)
        {
            if(t_id==id)
            {
                found++;
                //system("cls");
                cout<<"\n\t\tUser ID: "<<id<<" \n\t\tName: "<<f_name<<" \n\t\tLast Name: "<<l_name;
                cout<<"\n\t\tAddress: "<<address<<" \n\t\tPin: "<<pin<<" \n\t\tPassword: "<<password;
                cout<<"\n\t\t Phone: "<<phone<<" \n\t\tBalance: "<<balance;
            }
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();

        if(!found)
            cout<<endl<<"Invalid User ID";
    }
}

void bank:: edit()
{
    //system("cls");
    fstream file, file1;
    string t_id;
    cout<<"\n\t\t\t Edit User Record";

    file.open("bank.txt", ios::in);

    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl; 
    }
    else
    {
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        int found=0;
        file1.open("bank1.txt", ios::app| ios::out);

        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        
        while(file)
        {
            if(t_id==id)
            {
                found++;
                cout<<endl<<"Enter First Name :";
                cin>>f_name;
                cout<<endl<<"Enter Last Name :";
                cin>>l_name;
                cout<<endl<<"Enter Pin Code :";
                cin>>pin;
                cout<<endl<<"Enter Password :";
                cin>>password;
                cout<<endl<<"Enter Phone Number :";
                cin>>phone;
                cout<<endl<<"Enter city :";
                cin>>address;

                cout<<"\n\n Record edited successfully...";
            }
            
            file1<<" "<<id<<" "<<f_name<<" "<<l_name<<" "<<pin<<" "<<password<<" "<<phone<<" "<<address<<" "<<balance;

            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if(found==0)
        {
            cout<<endl<<"Invalid User Id"<<endl;
        }
    }
}

void bank:: del()
{
    //system("cls");
    fstream file, file1;
    int found=0;
    string t_id;
    cout<<"\n\t\t\t Delete User Record";

    file.open("bank.txt", ios::in);

    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl; 
    }
    else
    {
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        file1.open("bank1.txt", ios::app| ios::out);

        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        
        while(file)
        {
            if(t_id==id)
            {
                found++;
                cout<<"\n\n Record deleted successfully...";
            }
            else
                {
                    file1<<" "<<id<<" "<<f_name<<" "<<l_name<<" "<<pin<<" "<<password<<" "<<phone<<" "<<address<<" "<<balance;
                }
            
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;

            //file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");

        if(found==0)
        {
            cout<<endl<<"Invalid User Id"<<endl;
        }
    }
}

void bank::show_payment()
{
    //system("cls");
    fstream file;
    string b_name,ti; //some modificatioins remain
    int found=0, c_date,c_month, c_year;
    float amount;
    cout<<endl<<"\t\t\tShow All Paymet Records";
    //file.open("bank.txt",ios::in);
    file.open("bill.txt",ios::in);

    if(!file)
    {
        cout<<endl<<"File Opening Error";
    }
    else
    {
        //file1<<t_id<<" "<<b_name<<" "<<amount<<" "<<
        file>>id>>f_name>>amount>>c_date>>c_month>>c_year; 
        while(file)
        {
            cout<<endl<<"User ID :"<<id<<endl;
            cout<<"Bill Name :"<<f_name<<endl;
            cout<<"Amount :"<<amount<<endl;
            //cout<<"time :"<<amount<<endl;
            cout<<"Date :"<<c_date<<endl;
            cout<<"Month :"<<c_month<<endl;
            cout<<"Year :"<<c_year<<endl;
            cout<<"\n--------------------------------------------------------------------------------------\n ";
            file>>id>>f_name>>amount>>c_date>>c_month>>c_year;
            found++;
        }
        file.close();
        if(found==0)
        {
            cout<<endl<<"There are no current transactions."<<endl;
        }
    }
};

 void bank::show_records(){
    //system("cls");
    cout<<endl<<"\t\t\tShow All User's Records";
    fstream file;
    file.open("bank.txt",ios::in);
    int found=0;  
    if(!file)
    {
        cout<<endl<<"File Opening Error.";
    }
    else
    {
       
        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        while(file)
        {
            cout<<endl<<"User ID :"<<id<<endl;
            cout<<"First Name :"<<f_name<<endl;
            cout<<"Last Name :"<<l_name<<endl;
            cout<<"Pin :"<<pin<<endl;
            cout<<"Password :"<<password<<endl;
            cout<<"Phone Number :"<<phone<<endl;
            cout<<"City :"<<address<<endl;
            cout<<"Balance :"<<balance<<endl;
            cout<<"\n--------------------------------------------------------------------------------------\n ";
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
            found++;
        }
        file.close();
        if(found==0)
        {
            cout<<endl<<"There are no current users"<<endl;
        }
    }
};

void bank::user_balance(){
    //system("cls");
    cout<<endl<<"\t\t\tUser Login and Check Balance"<<endl;
    fstream file;
    string t_id,t_password;
    int found=0,t_pin;
    file.open("bank.txt",ios::in);
    if(!file)
    {
        cout<<endl<<"File could not open"<<endl;
    }
    else
    {
        string st;
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        cout<<"\nEnter Pin Code (5 Digits):";
        for(int i=0;i<5;i++)
        {
            char ch=getch();
            st+=ch;
            cout<<"*";
        }//12345
        getch();
        t_pin=stoi(st);

        cout<<endl<<"Enter Password (5 characters):";
        for(int i=0;i<5;i++)
        {
            char ch=getch();
            t_password+=ch;
            cout<<"*";
        }
        cout<<endl;
        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        while(file)
        {
            if(t_id==id&&t_password==password&&t_pin==pin)
            {
                cout<<endl<<"Your current balance is: "<<balance;
                found++;
            }
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();
        if(found==0)
        {
            cout<<endl<<"User ID, Pin or Password is Invalid"<<endl;
        }
    }
}

void bank ::withdraw_atm()
{
    //system("cls");
    //cout<<endl<<"\t\t\tWithdraw Amount"<<endl;
    fstream file, file1;
    string t_id, t_password, st;
    int t_pin;
    int found=0;
    float with;
    ////system("cls");
    cout<<"\n \t\t\tWithdraw Page";
    file.open("bank.txt", ios::in);

    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl;
    }
    else
    {
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        cout<<"\nEnter Pin Code (5 Digits) :";
        for(int i=0;i<5;i++)
        {
            char ch=getch();
            st+=ch;
            cout<<"*";
        }
        t_pin=stoi(st);
        getch();
        cout<<endl<<"Enter Password (5 characters):";
        for(int i=0;i<5;i++)
        {
            char ch=getch();
            t_password+=ch;
            cout<<"*";
        }
        cout<<endl;
        file1.open("bank1.txt", ios::app| ios::out);

        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
       
        while(file)
        {
            if(t_id==id&&t_password==password&&t_pin==pin)
            {
                cout<<"\n Enter Amount to be withdrawed: ";
                cin>>with;
                if(with<=balance)
                {
                    balance-=with;
                }
                else
                    cout<<"\n Insufficient Funds";
                found++;
                cout<<"\n Current balance: "<<balance;
            }
            file1<<" "<<id<<" "<<f_name<<" "<<l_name<<" "<<pin<<" "<<password<<" "<<phone<<" "<<address<<" "<<balance;
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();
        file1.close();
        remove("bank.txt");
        rename("bank1.txt", "bank.txt");


        if(found==0)
        {
            cout<<endl<<"No such User isre."<<endl;
            //cout<<"To create an ID Please go to new User:"<<endl;
        }
    }
   
}

void bank::check_detail()
{
    //system("cls");
    cout<<endl<<"\t\t\t Check Details"<<endl;
    fstream file;
    string t_id, t_password, st;
    int t_pin;
    int found=0;
    float with;
    ////system("cls");
    //cout<<"\n Withdraw Page";
    file.open("bank.txt", ios::in);
    if(!file)
    {
        cout<<endl<<"File Opening Error"<<endl;
    }
    else
    {
        cout<<endl<<"Enter User ID:";
        cin>>t_id;
        cout<<"\nEnter Pin Code (5 Digits) :";
        for(int i=0;i<5;i++)
        {
            char ch=getch();
            st+=ch;
            cout<<"*";
        }
        t_pin=stoi(st);
        getch();
        cout<<endl<<"Enter Password (5 characters):";
        for(int i=0;i<5;i++)
        {
            char ch=getch();
            t_password+=ch;
            cout<<"*";
        }
        cout<<endl;
        file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
       
        while(file)
        {
            if(t_id==id&&t_password==password&&t_pin==pin)
            {
                cout<<endl<<"User ID :"<<id<<endl;
                cout<<"First Name :"<<f_name<<endl;
                cout<<"Last Name :"<<l_name<<endl;
                cout<<"Pin :"<<pin<<endl;
                cout<<"Password :"<<password<<endl;
                cout<<"Phone Number :"<<phone<<endl;
                cout<<"City :"<<address<<endl;
                cout<<"Balance :"<<balance<<endl;
                cout<<"\n--------------------------------------------------------------------------------------\n ";
                file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
                found++;
            }
            file>>id>>f_name>>l_name>>pin>>password>>phone>>address>>balance;
        }
        file.close();

        if(found==0)
        {
            cout<<endl<<"Invalid User."<<endl;
            //cout<<"To create an ID Please go to new User:"<<endl;
        }
    }
}

int main(){
    
    bank obj;
    obj.menu();
    return 0;

}
