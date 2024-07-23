#include <iostream>
using namespace std;

void Register_Player() {
    int DOB;
    string Fname,Lname,Uname,Pass;/*Team1,Team2,Pid*/
    cout<<"Enter your First Name: ";
    cin>>Fname;
    cout<<"\n";

    cout<<"Enter your Last Name: ";
    cin>>Lname;
    cout<<"\n";

    //using a while loop to validate Date of birth
    while (true) {
        cout<<"Enter Your Date of Birth (DDMMYYYY): ";
        cin>>DOB;
        if (cin.fail()) {
            cout<<"Please enter an integer for the date of birth.Try again"<<endl;
            cin.clear();
            // cin.ignore(10000000, '\n');
        }
        else {
            break;
        }
    }
    cout<<"\n";

    cout<<"Please choose your username: ";
    cin>>Uname;
    cout<<"\n";

    cout<<"Please choose your password: ";
    cin>>Pass;

    cout<<"\n\n"<<"Please Make Sure to Remember Your Username and Password.\n";


    // Generating a unique player ID

    cout<<"Your Player ID is: ";;
    cout<<"\n\n";
    system("pause");
    system("cls");
}

int main() {
    int opt;

    {


        cout<<":::::::: Upcountry Warriors Registration Page ::::::::\n"<<endl;
        cout<<"Select an option below:\n"<<endl;

        cout<<"1. Registration as a Player"<<endl;
        cout<<"2. Registration as a Manager/Couch"<<endl;
        cout<<"3. Login"<<endl;
        cout<<"4. Exit\n"<<endl;

        cout<<"Please enter your choice:  ";
        cin>>opt;
    }

        switch(opt) {
            case 1:
                system("cls");
            cout<<"    Player Registration    \n"<<endl;
            cout<<"Please Enter your details below:\n"<<endl;
            Register_Player();

            // system("pause");
            // main();//main() will be replaced by login() function. main is temporarily here as a placeholder.
            system("cls");
            break;


            case 2:

                cout<<"Still Under Development."<<endl;
            cout<<"Manager/Couch Registration Sucessful!"<<endl;
            // Register_MC(); Register Mc will be the function to register manager/couch.
            break;


            case 3:
                cout<<"    Login Page    \n";
            // Login(); Login will be the function to approve user permission.
            break;


            case 4:
                cout<<"Exiting the Program...\n";
            break;



            default:
                system("cls");
            cout<<"Please choice one of the given options."<<endl;
        }




    system("pause");
    return 0;
}
