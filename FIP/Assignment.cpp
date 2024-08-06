#include <iostream>
#include <fstream>

using namespace std;

int opt=0,opt1=0;
int DOB;
double runs;
string Fname,Lname,Uname,Pass,Team1,Team2,Pid;


    void login();

    void PID() {
        //Generating Unique Player
                }

    void userReg(){

    cout<<"\n----- Registration Page -----\n\n";

    cout<<"4. Please choose your username: ";
    cin>>Uname;
    cout<<"\n";

    cout<<"5. Please choose your password: ";
    cin>>Pass;

        //Saving login details into Credentials.txt
        {
        ofstream AuthSave ("Credentials.txt", ios::app);
        AuthSave<<Uname<<"\t"<<Pass<<endl;

        cout<<"\n\nAccount Registered Successfully.\n"<<endl;
        AuthSave.close();

        system("pause");
        system("cls");

        }
}

    void dob() {while (true) {
    cout<<"3. Enter player Date of Birth (DDMMYYYY): ";
    cin>>DOB;
    if (cin.fail()) {
        cerr<<"Please enter an integer for the date of birth.Try again"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cerr.clear();
    }
    else { break; }
}}



    void Register_Player() {

        cout<<"\n==== Player Registration ====\n\n";
        cout<<"Please Enter player details below\n\n";
        cout<<"1. Enter player First Name: ";
        cin>>Fname;
        cout<<"\n";

        cout<<"2. Enter player Last Name: ";
        cin>>Lname;
        cout<<"\n";

        //using a while loop to validate Date of birth
        /*while (true) {
            cout<<"3. Enter player Date of Birth (DDMMYYYY): ";
            cin>>DOB;
            if (cin.fail()) {
                cerr<<"Please enter an integer for the date of birth.Try again"<<endl;
                cin.clear();
                cin.ignore(1000, '\n');
            }
            else { break; }
        }*/
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

    void User_Menu();
    void Forgot_Password();

    void Menu (){
            //Running the main menu on a loop until the user chooses to exit.
            for(;;) {
                cout<<":::::::: Upcountry Warriors Registration Page ::::::::\n"<<endl;
                cout<<"Select an option below:\n"<<endl;

                cout<<"1. User Registeration"<<endl;
                cout<<"2. Login"<<endl;
                cout<<"3. Forgot Password"<<endl;
                cout<<"4. Exit\n"<<endl;

                cout<<"Please enter your choice:  ";
                cin>>opt;


                switch(opt) {
                    case 1:

                        system("cls");
                    userReg(); //This function registers Users.
                    Menu();

                    break;

                    case 2:

                        system("cls");
                    login(); //Login will be the function to approve user permission.
                    User_Menu(); //This function will be called when user logs in.

                    break;

                    case 3:
                        system("cls");
                        Forgot_Password(); //This function is called when user forgets their password.
                        Menu();

                    break;

                    case 4:
                        cout<<"Exiting the Program...\n";
                    system("pause");
                    exit(0);

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

            void Forgot_Password() {
        string UNm,UNm_i,Pswd;
        bool check=false;
        cout<<"---Forgot Your Password ?..---\n\n";
        cout<<"Please enter your usernanme: ";
        cin>>UNm_i;
        
        
        

        ifstream forg;
        forg.open("Credentials.txt");


        while(forg>>UNm>>Pswd) {
            if (UNm_i==UNm) {
                check=true;
                break;
            }
            } forg.close();

           

        

        if(check==true) {
            cout<<"\n\nYour Password is: "<<Pswd<<endl;
            }

             else {
                
                cout << "\n\nUsername not found.\nPlease Register. \n\n";
                cout<<UNm<<UNm_i;
                
                system ("Pause");
                system("cls");
                }  

        cout<<"\n\n";

        int inp;
                
                cout<<"1. Register Account\n";
                cout<<"2. Main Menu\n\n";
                cout<<"Option: ";
                cin>>inp;
                if (inp==1){system("cls");
                userReg();}

                else if (inp==2){
                system("cls");
                cout<<"Returning to Main Menu...\n\n";
                system("Pause");
                
                Menu();}
}

    int main() {

        Menu();
        return 0;
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


        while(Auth>>UN>>PW) {
            if(USR==UN && PW==PWD) {
                counter = true;
                system("cls");
                User_Menu();
                break;
            }



        }Auth.close();
        if(!counter==true) {
            cerr<<"\n\nInvalid Username or Password!\nPlease Try Again or Use Forgot Password."<<endl;
             cout<<UN<<PWD<<"\n\n";
            system("pause");
            system("cls");
            Menu();
        }


    }

    void User_Menu() {

        cout<<"\nLogin Successful!\n\n"<<endl;
        for(;;){

            cout<<"\t\tWelcome [ "<<Uname<<" ]"<<"\n\n";
            cout<<"1. Add Player\n";
            cout<<"2. Search Player\n";
            cout<<"3. Change Team\n";
            cout<<"4. Change Password\n";
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
                cout<<"Exit";
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