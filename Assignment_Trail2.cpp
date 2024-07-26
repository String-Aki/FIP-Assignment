#include <iostream>
#include <fstream>
using namespace std;

int opt=0;
int DOB;
string Fname,Lname,Uname,Pass,Team1,Team2,Pid;


void PID() {
    //Generating Unique Player ID
}

void Register_Player() {

    cout<<"\n==== Player Registration ====\n\n";
    cout<<"Please Enter your details below\n\n";
    cout<<"1. Enter your First Name: ";
    cin>>Fname;
    cout<<"\n";

    cout<<"2. Enter your Last Name: ";
    cin>>Lname;
    cout<<"\n";

    //using a while loop to validate Date of birth
    while (true) {
        cout<<"3. Enter Your Date of Birth (DDMMYYYY): ";
        cin>>DOB;
        if (cin.fail()) {
            cerr<<"Please enter an integer for the date of birth.Try again"<<endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
        else { break; }

    }
    cout<<"\n";

    cout<<"4. Please choose your username: ";
    cin>>Uname;
    cout<<"\n";

    cout<<"5. Please choose your password: ";
    cin>>Pass;

    cout<<"\n\n";

    PID();

    {
        ofstream AuthSave ("Credentials.txt", ios::app); //Saving login details into Credentials.txt
        AuthSave<<Uname<<"\t"<<Pass<<endl;

        cout<<"Profile created successfully.\n"<<"Please Make Sure to Remember Your Username and Password.\n"<<endl;
        AuthSave.close();

    }

     cout<<"\n\n";

    system("pause");
    system("cls");

}

void login() {

    string UN, PW,USR,PWD;
    bool counter=false;
    cout<<"\n==== Login Page ====\n\n";
    cout<<"Please Enter your Username and Password\n\n";

    cout<<"1. Enter your Username: ";
    cin>>USR;
    cout<<"\n";

    cout<<"2. Enter your Password: ";
    cin>>PWD;



    ifstream Auth;
    Auth.open("Credentials.txt", ios::in);
    if(!Auth.is_open()) {cerr<<"File doesn't exist/couldn't be opened...";}

    //Auth.seekg(8,ios::cur); //The file pointer reads from the 8th position.


    while(Auth>>UN>>PW) {
        if(USR==UN && PW==PWD) {
            counter = true;
            break;
        }
        else if (USR==UN && PWD=="Admin") {
            counter=true;
            cout<<"Welcome Admin"<<endl;
            break;
        }




    }Auth.close();
        if(!counter==true) {
            cerr<<"\n\nInvalid Username or Password!\nPlease Try Again"<<endl;

        }
        else {

            cout<<"\nLogin Successful!"<<endl;
            // Player_Profile();
        }




    cout<<"\n\n";
    system("pause");
    system("cls");

}

int main() {

    //Running the main menu on a loop until the user chooses to exit.
    while(true) {
        cout<<":::::::: Upcountry Warriors Registration Page ::::::::\n"<<endl;
        cout<<"Select an option below:\n"<<endl;

        cout<<"1. Registration as a Player"<<endl;
        cout<<"2. Registration as a Manager/Couch"<<endl;
        cout<<"3. Login"<<endl;
        cout<<"4. Exit\n"<<endl;

        cout<<"Please enter your choice:  ";
        cin>>opt;



        switch(opt) {
            case 1:
                system("cls");
                Register_Player(); //This function registers the players
                login();
            break;


            case 2:
                system("cls");
                cout<<"Still Under Development."<<endl;
                cout<<"Manager/Couch Registration Sucessful!"<<endl;
            // Register_MC(); Register Mc will be the function to register manager/couch.

                break;
            case 3:
                system("cls");
                login(); //Login will be the function to approve user permission.
            break;


            case 4:
                cout<<"Exiting the Program...\n";
            system("pause");
            return 0;

            default: {
                if (cin.fail() || opt>4 || opt<1){
                    cin.clear();
                    cin.ignore(1000, '\n');
                    cout<<"Please choice one of the given options."<<endl;
                    system("pause");
                    system ("cls");
                }
            }

            }
        }
    }
