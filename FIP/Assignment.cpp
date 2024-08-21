#include <iostream>
#include <fstream>

using namespace std;

int opt=0,opt1=0;
int DOB;
// double runs;
string UsrsNme,Nme;
string Fname,Lname,Uname,Pass,Team1,Team2,Pid,RUN_1,RUN_2; //Player Registration variables.
string UN, PW,USR,PWD; //Login variables.
string TeamID,Team; //Team Creation Variables.

    void login(); //Login will be the function to approve user permission.

    void PID(); //Generating Unique Player

    void userReg(); //This function registers Users.

    void dob(); //Date of Birth function which loops until it gets a integer value

    void Register_Player(); //This function is called when the user wants to add player details to database

    void search(); //Used to search players using Player Registration number.

    void Create_T(); //Displays all the players in the team.

    void team(); // Manage Teams 

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

        void userReg(){

        string CheckUname;

    
    cout<<"\n----- Registration Page -----\n\n";

    cout<<"1. Please Enter Your Name: ";
    cin>>UsrsNme;
    cout<<"\n";
   
    cout<<"2. Please choose your username: ";
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
    
    cout<<"3. Please choose your password: ";
    cin>>Pass;

    

        //Saving login details into Credentials.txt
        {string Cred[3]={Uname,Pass,UsrsNme};
        ofstream AuthSave ("Credentials.txt", ios::app);
        AuthSave<<Cred[0]<<"\t"<<Cred[1]<<"\t"<<Cred[2]<<endl;

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


        while(Auth>>UN>>PW>>Nme) {
            if(USR==UN && PW==PWD) {
                counter = true;
                system("cls");
                User_Menu();
                cout<<"\nLogin Successful!\n\n"<<endl;
                break;
            }


        }
        if(!counter==true) {
            cerr<<"\n\nInvalid Username or Password!\nPlease Try Again or Use Forgot Password.\n"<<endl;
            system("pause");
            system("cls");
            Menu();
        }Auth.close();

    }

            void User_Menu() {

        for(;;){

            cout<<"\t\tWelcome [ "<<Nme<<" ]"<<"\n\n";
            cout<<"1. Add New Player\n";
            cout<<"2. Search Player\n";
            cout<<"3. Manage Teams\n";
            cout<<"4. Logout\n";
            cout<<"5. Exit\n\n";
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
                    search();
                break;

                case 3:
                    system("cls");
                    team();

                break;

                case 4:
                //Logout
                system("cls");
                cout<<"Logging out...\n";
                system("pause");;
                Menu();
                break;

                case 5:
                    system("cls");
                cout<<"Leaving...\nThank You\n";
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

                void Register_Player() {

        cout<<"\n==== Player Registration ====\n\n";
        cout<<"Please Enter Player details below\n\n";
        
        cout<<"1. Enter Player First Name: ";
        cin>>Fname;
        cout<<"\n";

        cout<<"2. Enter Player Last Name: ";
        cin>>Lname;
        cout<<"\n";


        dob();

       cout<<"\n4. Enter Team one's Name: ";
        cin>>Team1;
        cout<<"\n";

        cout<<"5. Enter Team two's Name: ";
        cin>>Team2;
        cout<<"\n"; 

        ifstream TeamD("Team.txt"); //Team Integrity Checking - Users can enter only one Team.
        string Tname1,Tname2;       

                    if(TeamD.is_open()){

                    while (TeamD>>Tname1>>Tname2){

                    if (Tname1!=Team1){

                    cout<<"\nTeam 1 doesn't exits\n"<<"Try again.\n\n"<<"Redirecting to main menu\n"<<endl;
                    system("pause");
                    system("cls");
                    TeamD.close();
                    User_Menu();
                    cout<<"DONE";
                    }
                    }
                    }



        cout<<"6. Enter runs scored by player ";
        cout<<"\t\nTeam 1: ";
        cin>>RUN_1;
        cout<<"\tTeam 2: ";
        cin>>RUN_2;
        cout<<"\n";

        PID();

        cout<<"\n\n"<<"Profile created successfully.\n"<<endl;


        //Saving User Details into Database.txt
        {
            string data[8] = {Pid,Fname,Lname,to_string(DOB),Team1,Team2,RUN_1,RUN_2};
            ofstream DataSave ("Database.txt", ios::app);
            DataSave<<data[0]<<"\t"<<data[1]<<"\t"<<data[2]<<"\t"<<data[3]<<"\t"<<data[4]<<"\t"<<data[5]<<"\t"<<data[6]<<"\t"<<data[7]<<endl;
            cout<<"User details saved successfully.\n\n";
            DataSave.close();
        }

        cout<<"\n\n";

        system("pause");
        system("cls");

    }

                    void dob() {
                        while (true) {
    cout<<"3. Enter player Date of Birth (DDMMYYYY): ";
    cin>>DOB;
    if (cin.fail()) {
        cerr<<"Please enter an integer for the date of birth.Try again"<<endl;
        cin.clear();
        cin.ignore(1000, '\n');
    }
    else { break; }
}}

                    void PID() {

                        string CheckPID;

                        cout<<"\nEnter Player Registration Number: ";
                        cin>>Pid;
                        ifstream DB("Database.txt"); //User Integrity Checking - Users can register with only one Player Registration Number.
                        if(DB.is_open()){
                        while (DB>>CheckPID){
                        if (CheckPID==Pid){
                        cout<<"\nPlayer Registration Number already exits\n"<<"Try again.\n\n"<<"Redirecting to menu\n"<<endl;
                        system("pause");
                        system("cls");
                        DB.close();
                        User_Menu();
                        }
                        }
                        }
                        }

          void Forgot_Password() {

        string UNm,UNm_i,Pswd,Pswd_i;
        int check=0;

        cout<<"||----|Change Password|----||\n\n";
        cout<<"1. Please enter your username: ";
        cin>>UNm_i;
        cout<<"\n"<<endl;
        cout<<"2. Please enter your new password: ";
        cin>>Pswd_i;

    //Using fstream to remove the old password, user name and appending new username and password.
        ifstream forgt;
        ofstream temp;
        forgt.open("Credentials.txt", ios::in);
        temp.open("holder.txt", ios::out); // Temporary file which will hold all the username and passwords.

        while(forgt>>UNm>>Pswd) {

            if (UNm_i != UNm) {
             temp << UNm <<"\t"<< Pswd<<endl; //Copies all the username and password to holder.txt (Except the one with the forgotten password)
             check = 1;

            }

            else if (UNm_i == UNm) {
                check=1;
            }
            }

       if(check==1) {

        temp<< UNm_i << "\t" << Pswd_i << endl; //If the username input username found, new password and username is appended
        
        forgt.close();
        temp.close();

        remove("Credentials.txt"); //Old file is removed and holder is renamed as the previous file "Credentials.txt"
        rename("holder.txt", "Credentials.txt");

        cout<<"Password changed successfully\n\n";
        cout<<"Your Username:"<<UNm_i<<endl;
        cout<<"Your new password:"<<Pswd_i<<endl;
        } 

       if (check==0) {
             cout << "\n\nUsername not found.\nPlease Register.";

            }

        cout<<"\n\n";

        int inp;

        

                cout<<"\n1. Register Account\n";
                cout<<"2. Main Menu\n";
                cout<<"3. Try Again\n\n";
                cout<<"Option: ";
                cin>>inp;
                if (inp==1){
                system("cls");
                userReg();
                }

                else if (inp==2){
                system("cls");
                cout<<"Returning to Main Menu...\n\n";
                system("Pause");

                Menu();
                }

                else if (inp==3){
                    system("cls");
                    Forgot_Password();
                }
}

                void search () {
                    string P_ID, ID, P_Fname, P_Lname, dob, P_age, team_1, team_2,runs;
                    int check, check2;

                    cout<<"\n\t[:..:Search Player:..:]\n\n";
                    cout<<"\nPlease Enter Player Registration Number: ";
                    cin>>ID;

                    ifstream db;
                    db.open("Database.txt", ios::in);
                    if (db.is_open()) {
                        
                        check=1;
                        while(db>>P_ID>>P_Fname>>P_Lname>>dob>>team_1>>team_2>>runs){
                            if (P_ID==ID){
                                check2=1;

                                cout<<"\n\tDisplaying Player Details\n\n";
                                
                                cout<<") Player Full Name: "<<P_Fname<<" "<<P_Lname<<endl;
                                cout<<"\n) Player Date Of Birth: "<<dob<<endl;
                                cout<<"\n) Participating Teams: "<<team_1<<","<<team_2<<endl;
                                cout<<"\n) Total Runs Scored: "<<runs<<endl;
                                cout<<"\n";

                                system("pause");
                                system("cls");

                                
                            }
                            
                            }

                            if (check2!=1) {
                                cerr<<"\nPlayer Not Found\nPlease Register Player"<<endl;
                                cout<<"\nRedirecting to Menu...\n";
                                db.close();
                                system("pause");
                                system("cls");
                                
                                User_Menu();
                            }
                         }

                    if (check==0){
                                
                                cerr<<"Error while opening file\nTry again or Restart\n\nRedirecting to menu..\n"<<endl;
                                db.close();
                                system("pause");
                                system("cls");
                                
                                User_Menu();
                            }
                          
                }
                
                void team () {
                    int swt;

                    cout<<"//// Team Management ////\n\n";

                    cout<<"1. Create Teams"<<endl;
                    cout<<"2. List Teams"<<endl;
                    cout<<"3. Return to menu\n"<<endl;

                    cout<<"Choice: ";
                    cin>>swt;

                    

                    switch(swt){

                        case 1: 
                        {
                            system("cls");
                            Create_T();
                               
                        }
                        break;
                        case 2:
                        {
                            // List_T();
                        }
                        break;

                        case 3:
                        {
                            User_Menu();
                        }

                        default: 
                        {
                            cout<<"Invalid Entry, Try again..";
                        }
                        
                    }
                }

                void Create_T()
                {
                    string ID;

                    cout<< "\nCreate Team\n\n";

                    cout<<"Enter Team name: ";
                    cin>>Team;

                    cout<<"\n";

                    cout<<"Enter Team ID: ";
                    cin>>TeamID;

                    ifstream TeamC("Team.txt"); //Team Integrity Checking - Users can enter only one Team.
                    
                    if(TeamC.is_open()){

                    while (TeamC>>ID){

                    if (ID==Team){

                    cout<<"\nTeam already exits\n"<<"Try again.\n\n"<<"Redirecting to main menu\n"<<endl;
                    system("pause");
                    system("cls");
                    TeamC.close();
                    User_Menu();

                }
                }
                }
                ofstream team ("Team.txt",ios::app);
                    team <<Team<<"\t"<<TeamID<<endl;
                    cout<<"\nTeam Created Successfully\n";
                    system("pause");
                    system("cls");
                }

                 
                   
                