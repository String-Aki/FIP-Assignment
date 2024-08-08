#include <iostream>
#include <fstream>

using namespace std;

int opt=0,opt1=0;
int DOB;
double runs;
string Fname,Lname,Uname,Pass,Team1,Team2,Pid; //Player Registration variables.
string UN, PW,USR,PWD; //Login variables.
    int exitFile(); // function is used to exit the program

    void login(); //Login will be the function to approve user permission.

    void PID(); //Generating Unique Player

    void userReg(); //This function registers Users.

    void dob(); //Date of Birth function which loops until it gets a integer value

    void Register_Player(); //This function is called when the user wants to add player details to database

    void User_Menu(); //This function will be called when user logs in.

    void Forgot_Password(); //This function is called when user forgets their password.

    void Menu(); //Main menu


    int main() {

        Menu();
        return 0;
    }

    void Menu (){
            //Running the main menu on a loop until the user chooses to exit.
            for(;;) {
                cout<<":::::::: Upcountry Warriors Registration Page ::::::::\n"<<endl;
                cout<<"Select an option below:\n"<<endl;

                cout<<"1. User Registration"<<endl;
                cout<<"2. Login"<<endl;
                cout<<"3. Forgot Password"<<endl;
                cout<<"4. Exit\n"<<endl;

                cout<<"Please enter your choice:  ";
                cin>>opt;


                switch(opt) {
                    case 1:

                        system("cls");
                    userReg();
                    Menu();

                    break;

                    case 2:

                        system("cls");
                    login();
                    User_Menu();

                    break;

                    case 3:
                        system("cls");
                        Forgot_Password();
                        Menu();

                    break;

                    case 4:
                    system("cls");
                        cout<<"Exiting the Program...\nThank You\n";
                    system("pause");
                    exitFile();

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

        void userReg(){
            string CheckUname;

    
    cout<<"\n----- Registration Page -----\n\n";
   
    cout<<"4. Please choose your username: ";
    cin>>Uname;
    cout<<"\n";
    
    ifstream File("Credentials.txt"); //User Integrity Checking - Users can register with only one username.
    if(File.is_open()){
        while (File>>CheckUname){
            if (CheckUname==Uname){
                cout<<"Username already exits\n"<<"Try again.\n\n"<<"Redirecting to main menu\n"<<endl;
                system("pause");
                system("cls");
                File.close();
                Menu();
            }
        }
    }
    
    cout<<"5. Please choose your password: ";
    cin>>Pass;

        //Saving login details into Credentials.txt
        {string Cred[2]={Uname,Pass};
        ofstream AuthSave ("Credentials.txt", ios::app);
        AuthSave<<Cred[0]<<"\t"<<Cred[1]<<endl;

        cout<<"\n\nAccount Registered Successfully.\n"<<endl;
        AuthSave.close();

        system("pause");
        system("cls");
        

        }
}

        void login() {

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
        if(!Auth.is_open()) {cerr<<"\n\nFile doesn't exist/couldn't be opened...";}


        while(Auth>>UN>>PW) {
            if(USR==UN && PW==PWD) {
                counter = true;
                system("cls");
                User_Menu();
                break;
            }


        }Auth.close();
        if(!counter==true) {
            cerr<<"\n\nInvalid Username or Password!\nPlease Try Again or Use Forgot Password.\n"<<endl;
            system("pause");
            system("cls");
            Menu();
        }
    }

            void User_Menu() {

        cout<<"\nLogin Successful!\n\n"<<endl;
        for(;;){

            cout<<"\t\tWelcome [ "<<USR<<" ]"<<"\n\n";
            cout<<"1. Add Player\n";
            cout<<"2. Search Player\n";
            cout<<"3. Remove Player\n";
            cout<<"4. Teams\n";
            cout<<"5. Logout\n";
            cout<<"6. Exit\n\n";
            cout<<"Enter your choice: ";
            cin>>opt1;

            switch (opt1) {
                case 1:
                    system("cls");
                Register_Player();
                User_Menu();
                break;

                case 2:
                    system("cls");
                //Search();
                cout<<"Change Teams";
                break;

                case 3:
                    system("cls");
                //Change_Team();

                break;

                case 4:
                    // change_password();
                    cout<<"Change password";
                break;

                case 5:
                system("cls");
                //Logout
                cout<<"Logging out...\n";
                system("pause");;
                Menu();
                break;

                case 6:
                    system("cls");
                cout<<"Leaving...\nThank You\n";
                system("pause");
                exitFile();


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

                void Register_Player() {

        cout<<"\n==== Player Registration ====\n\n";
        cout<<"Please Enter player details below\n\n";
        
        cout<<"1. Enter player First Name: ";
        cin>>Fname;
        cout<<"\n";

        cout<<"2. Enter player Last Name: ";
        cin>>Lname;
        cout<<"\n";


        dob();

        cout<<"\n\n"<<"Profile created successfully.\n"<<endl;

        PID();

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

                    void dob() {while (true) {
    cout<<"3. Enter player Date of Birth (DDMMYYYY): ";
    cin>>DOB;
    if (cin.fail()) {
        cerr<<"Please enter an integer for the date of birth.Try again"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else { break; }
}}

                    void PID() { }

          void Forgot_Password() {

        string UNm,UNm_input,Pswd,Pswd_input;
        bool check=false;
        cout<<"||----|Change Password|----||\n\n";
        cout<<"1. Please enter your username: ";
        cin>>UNm_input;
        cout<<"2. Please enter your new password: ";
        cin>>Pswd_input;

    //Using fstream to remove the old password, user name and appending new username and password.
        ifstream forgt;
        ofstream temp;
        forgt.open("Credentials.txt");
        temp.open("holder.txt"); // Temporary file which will hold all the username and passwords.

        while(forgt>>UNm>>Pswd) {

            if (UNm_input != UNm) {
             temp << UNm <<"\t"<< Pswd<<endl; //Copies all the username and password to holder.txt (Except the one with the forgotten password)
             check = true;
                break;
            }
            } 

        if(check==true) {

        temp<< UNm_input << "\t" << Pswd_input << endl; //If the username input username found, new password and username is appended
        
        forgt.close();
        temp.close();

        remove("Credentials.txt"); //Old file is removed and holder is renamed as the previous file "Credentials.txt"
        rename("holder.txt", "Credentials.txt");
        } 

        else {
            cout << "\n\nUsername not found.\nPlease Register.";
            }

        cout<<"\n\n";

        int inp;

        cout<<"Password changed successfully\n\n";
        cout<<"Your Username:"<<UNm_input<<endl;
        cout<<"Your new password:"<<Pswd_input<<endl;

                cout<<"\n1. Register Account\n";
                cout<<"2. Main Menu\n";
                cout<<"3. Try Again\n\n";
                cout<<"Option: ";
                cin>>inp;
                if (inp==1){system("cls");
                userReg();}

                else if (inp==2){
                system("cls");
                cout<<"Returning to Main Menu...\n\n";
                system("Pause");

                Menu();}

                else if (inp==3){
                    system("cls");
                    Forgot_Password();
                }
}

    int exitFile(){
        return 0;
    }

