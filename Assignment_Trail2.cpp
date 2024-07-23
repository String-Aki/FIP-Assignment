#include <iostream>
using namespace std;

int opt=0;

void Register_Player() {
    int DOB;
    string Fname,Lname,Uname,Pass;/*Team1,Team2,Pid*/
    cout<<"\n==== Player Registration ====\n\n";
    cout<<"Please Enter your details below\n\n";
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
            cin.ignore(10000000, '\n');
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

void menu() {
    cout<<":::::::: Upcountry Warriors Registration Page ::::::::\n"<<endl;
    cout<<"Select an option below:\n"<<endl;

    cout<<"1. Registration as a Player"<<endl;
    cout<<"2. Registration as a Manager/Couch"<<endl;
    cout<<"3. Login"<<endl;
    cout<<"4. Exit\n"<<endl;

    cout<<"Please enter your choice:  ";
    cin>>opt;
    system("cls");
}

int main() {

    menu();//Calling the menu function to display the options. For the first time.


    switch(opt) {
        case 1:

            system("cls");
            Register_Player(); //This function registers the players
            menu();//This loops back to the main menu after registration.

            break;


            case 2:
            cout<<"Still Under Development."<<endl;
            cout<<"Manager/Couch Registration Sucessful!"<<endl;
            // Register_MC(); Register Mc will be the function to register manager/couch.
            menu();
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
