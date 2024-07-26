#include <iostream>
#include <fstream>

using namespace std;

int opt=0,opt1=0;
int DOB;
double runs;
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

        //Saving login details into Credentials.txt
        {
            ofstream AuthSave ("Credentials.txt", ios::app);
            AuthSave<<Uname<<"\t"<<Pass<<endl;

            cout<<"Profile created successfully.\n"<<"Please Make Sure to Remember Your Username and Password.\n"<<endl;
            AuthSave.close();

        }

        //Saving User Details into Database.txt
        {
            string data[8] = {Pid,Fname,Lname,to_string(DOB)};
            ofstream DataSave ("Database.txt", ios::app);
            DataSave<<data[0]<<"\t"<<data[1]<<"\t"<<data[2]<<"\t"<<data[3]<<endl;
            cout<<"User details saved successfully.\n\n";
            DataSave.close();
        }

        cout<<"\n\n";

        system("pause");
        system("cls");

    }

class LoggedIn {
    public:
      static  void PlayerMenu(int opt1) {

                cout<<"\nLogin Successful!\n\n"<<endl;
            for(;;){

                cout<<"\t\tWelcome [ Player FName ]\n\n";
                cout<<"1. View Profile\n";
                cout<<"2. View Runs Scored\n";
                cout<<"3. Request Change Team \n";
                cout<<"4.Change Password\n";
                cout<<"5. Logout\n\n";
                cout<<"Enter your choice: ";
                cin>>opt1;

                switch (opt1) {
                    case 1:
                        system("cls");
                        //View_Profile();
                            cout<<"Profile";
                    // player_info();
                    break;

                    case 2:
                        system("cls");
                        //View_Runs();
                            cout<<"Runs";
                    // player_info();
                    break;

                    case 3:
                        system("cls");
                        //Change_Team();
                            cout<<"Team";
                    // player_info();
                    break;

                    case 4:
                        system("cls");
                        //Change_Password();
                            cout<<"Password";
                    // player_info();
                    break;

                    case 5:
                        system("cls");
                        cout<<"Logging out...\n";
                    system("pause");
                    exit(0);

                    default: {
                        if (cin.fail() || opt>5 || opt<1)
                            cin.clear();
                        cin.ignore(1000, '\n');
                        cout<<"Please choice one of the given options."<<endl;
                        system("pause");
                        system ("cls");
                    }
                }
            }
        }

        void Profile ();
    };

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

        LoggedIn menu;

        ifstream Auth;
        Auth.open("Credentials.txt", ios::in);
        if(!Auth.is_open()) {cerr<<"File doesn't exist/couldn't be opened...";}


        while(Auth>>UN>>PW) {
            if(USR==UN && PW==PWD) {
                counter = true;
                system("cls");
                menu.PlayerMenu(opt1);
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


        cout<<"\n\n";
        system("pause");
        system("cls");
    }



    int main() {

        //Running the main menu on a loop until the user chooses to exit.
        for(;;) {
            cout<<":::::::: Upcountry Warriors Registration Page ::::::::\n"<<endl;
            cout<<"Select an option below:\n"<<endl;

            cout<<"1. Registration as a Player"<<endl;
            cout<<"2. Registration as a Manager/Couch"<<endl;
            cout<<"3. Login"<<endl;
            cout<<"4. Exit\n"<<endl;

            cout<<"Please enter your choice:  ";
            cin>>opt;

            LoggedIn Play;



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
                Play.PlayerMenu(opt1); //This function will be called when user logs in.
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





