/**
// * author : Muthia Kartika Putri
// * Student ID: E1800189
// * Date : 18/12/2020
// * Assignment 1
// * BIT205
// * Note: Here I make all the classes into 1 header file
// * Editor : Clion
// * Version : Mingw-w64
// * Note : Username login for Admin = admin
// *        Password login for Admin = admin
*/

//include all libarries needed
#include <iostream>
#include <string>

//using namespace std to help within the cod
using namespace std;

//include the header class to the main cpp
#include "EcoSave.h"

//method for displaying main menu
void mainMenu()
{
    cout << endl;
    cout << "----> Welcome to ECOSAVE Community Recycling System <----"<<endl;
    cout<<endl;
    cout<< "=============================================="<<endl;
    cout<<"                     Menu:\n"
        <<"                  1. Sign Up\n"
        <<"                  2. Sign In\n"
        <<"                  3. Quit\n"
        << "==============================================\n"
        <<"Your Choice: ";
}

//method for displaying login menu
void loginMenu()
{
    cout << endl;
    cout << "========> Sign In <========"<<endl;
    cout << "     1. Ecosave User\n"
         << "     2. Ecosave Admin \n"
         << "     3. Back to Main Menu\n"
         << "===========================\n"
         << "Your Choice: ";
}

//method for displaying signup menu
void signUp()
{
    cout<<endl;
    cout << "=============> Sign Up <=============="<<endl;
    cout << "           1. Recycler \n"
         << "           2. Collector \n"
         << "           3. Back to Main Menu \n"
         << "======================================"<<endl;
    cout << "Your choice: ";
}

//method for displaying material data menu
void materialData()
{
    cout << "======> Material Data <======" <<endl;
    cout << "   1. Add Materials" << endl;
    cout << "   2. Delete Material" << endl;
    cout << "   3. Update Material Data" << endl;
    cout << "=============================="<<endl;
    cout << "Enter Your Choice :";
}

//main method
int main()
{
    //declare all the variable that will be used in this program
    int choiceMaterialData,choice,choiceMaterial, menuSignup, submissionID,
    weightInKg, option, choiceStatus;
    int menuSignin,choiceHistory, chooseAdmin,chooseCollector,chooseRecycler,
    materialID, pointsPerKg;
    string username, password, fullName, address, ecoLevel, materialName,
    description, proposedDate, currentDate;
    char optionRecycler, optionCollector, optionRegister;
    EcoSave newEcoSave;
    user* User;
    material* dataMaterial;
    collector* dataCollector;
    recycler* dataRecycler;
    submission* dataSubmission;

    // call add the admin method in the ecosave class,
    // here my admin makes it the default data
    // so that the admin does not need to register
    newEcoSave.addAdmin();

    //calling main menu method
    mainMenu();
    cin>>choice;

    //while loop for looping the programme
    while (choice != 3) {
        //switch case for the menu chosen
        switch (choice) {
            case 1:
                //if user choose case 1,
                //the program will call signup method
                signUp();
                cin >> menuSignup;

                //if the user choose the option 1
                //they will register as recycler
                if(menuSignup == 1)
                {
                    cout << endl;
                    cout<<"      Please fill Your: \n";
                    cout<<"==============================\n";
                    //do-while loop to loop if the vector in ecosave
                    // already has the same username
                    do{
                        //input the username
                        cout<<"UserName: ";
                        cin>>username;
                        cout<<endl;
                        //if the username in the vector already has the
                        // same username
                        if(newEcoSave.checkUsername(username)==1)
                        {
                            // it will give notification message and
                            // the program will automatically
                            // tell the user to enter another username
                            cout<<"<!============================!>\n";
                            cout<<"   Username Has already exist\n";
                            cout<<"      Please Try It Again\n";
                            cout<<"<!=============================!>\n";
                        }
                    }
                    //if the username in the vector has not existed yet
                    while(newEcoSave.checkUsername(username)==1);
                    //input password, full name, and mobile number
                    cout<<"Password: ";
                    cin>>password;
                    cout<<endl;
                    cout<<"Full Name: ";
                    getline(cin>>ws,fullName);
                    cout<<endl;

                    //make a recycler pointer and call the parameter
                    // constructor
                    recycler* Recycler = new recycler(username, password, fullName);
                    //add the recycler into method in ecosave class
                    newEcoSave.addRecycler(Recycler);
                    cout<<"==================================\n";
                    //call the recycler's display method
                    cout<<Recycler->Display()<<endl;
                    cout<<endl;
                    cout<<"< Recycler is successfully added > \n";
                    cout<<"==================================\n";
                    cout<<endl;
                }

                //if the user choose option 2
                //they will register as collector
                else if(menuSignup == 2)
                {
                    cout << endl;
                    cout<<"      Please fill Your: \n";
                    cout<<"==============================\n";
                    //do-while loop to loop if the vector in ecosave
                    // already has the same username
                    do{
                        //input the username
                        cout<<"UserName: ";
                        cin>>username;
                        cout << endl;
                        //if the username in the vector already has the same username
                        if(newEcoSave.checkUsername(username)==1)
                            {   // it will give notification message and
                                // the program will automatically
                                // tell the user to enter another username
                                cout<<"<!============================!>\n";
                                cout<<"   Username Has already exist\n";
                                cout<<"      Please Try It Again\n";
                                cout<<"<!=============================!>\n";
                            }
                    }
                    //if the username in the vector has not existed yet
                    while(newEcoSave.checkUsername(username)==1);
                    //input password, full name, and mobile number
                    cout<<"Password: ";
                    cin>>password;
                    cout << endl;
                    cout<<"Full Name: ";
                    getline(cin>>ws,fullName);
                    cout << endl;
                    cout<<"Address: ";
                    getline(cin>>ws,address);
                    cout << endl;

                    //make a collector's pointer and call the parameter
                    // constructor
                    collector* Collector = new collector(username, password, fullName, address);
                    //add the collector into method in ecosave class
                    newEcoSave.addCollector(Collector);
                    cout<<"===================================\n";
                    //call collector's display method
                    cout<<Collector->Display()<<endl;
                    cout<<endl;
                    cout<<"< Collector is successfully added > \n";
                    cout<<"===================================\n";
                    cout<<endl;
                }

                //if the user choose option 3
                //they will be back to main menu method
                else if( menuSignup == 3)
                {
                    mainMenu();
                    cin>>choice;
                }
                break;

            case 2:
                //if the user choose case 2
                //the program will call the login menu method
                loginMenu();
                cin>>menuSignin;
                cout << endl;

                if (menuSignin == 1)
                {
                    //input username and password
                    cout<<"Username: ";
                    cin>>username;
                    cout<<endl;
                    cout<<"Password: ";
                    cin>>password;
                    cout<<endl;

                    //assigning data from method loginUser
                    // in ecosave into variable User
                    User = newEcoSave.loginUser(username, password);
                    //if the user data is equals to nullptr
                    if (User == nullptr) {
                        // it will give notification message and
                        // the program ordered the user to sign up
                        cout << "!========================================"
                                "=====!" << endl;
                        cout << " No Matching Data for the Username or "
                                "Password" << endl;
                        cout << "         Please Sign Up account first \n";
                        cout << "!========================================="
                                "====!" << endl;
                        cout << "Do you want to register: <Y/N>";
                        cin >> optionRegister;
                        //if the user choose option 1
                        if (optionRegister == 'Y' || optionRegister == 'y')
                        {
                            //the program will bring the user into sign up
                            // menu
                            choice = 1;
                            break;
                        }
                        //if the user choose option 2
                        else if(optionRegister == 'n' || optionRegister == 'N')
                        {
                            //the program will bring the user back to main
                            // menu
                            cout <<"======================"<<endl;
                            cout <<"Back to main menu....."<<endl;
                            cout <<"======================"<<endl;
                            mainMenu();
                            cin >> choice;
                            break;
                        }
                    }
                    else
                    {
                        //if the user is not equals to nullptr
                        //*create a pointer for both of object recycler
                        //and collector to know the username belongs to
                        // which class
                        recycler* Recycler = dynamic_cast<recycler*>(User);
                        collector* Collector = dynamic_cast<collector*>(User);
                        //if recycler data is not null
                        while (Recycler != nullptr) {
                            material* listMaterial; // <- matrial* data
                            // type for variable list material
                            //The menu for the recycler is displayed
                            cout << "=======>  Welcome Recycler <=======" << endl;
                            cout << endl;
                            cout << "Fullname: "<<Recycler->getFullName
                            ()+"\n"; //<-displaying recycler username
                            cout << "Total Points: "<<Recycler->getTotalPoints
                            ()+"\n";//<-displaying recycler total points
                            cout << "Ecolevel: "<<Recycler->getEcoLevel
                            ()+"\n";//<-displaying recycler ecolevel
                            cout << endl;
                            cout << "===================================" <<endl;
                            cout << endl;
                            cout << "       Do You want to:\n"
                                 << "       1. Edit Profile\n"
                                 << "       2. Recycle Items\n"
                                 << "       3. View Submission History\n"
                                 << "       4. Quit\n"
                                 << "===================================\n"
                                 << "Your Choice: ";
                            cin >> chooseRecycler;

                            //if the user input the wrong choice
                            while(!(chooseRecycler == 1 || chooseRecycler == 2 || chooseRecycler == 3 || chooseRecycler == 4))
                            {
                                cout << "Wrong choice, please choose the "
                                        "right option \n";
                                cout << "       Do You want to:\n"
                                     << "       1. Edit Profile\n"
                                     << "       2. Recycle Items\n"
                                     << "       3. View Submission History\n"
                                     << "       4. Quit\n"
                                     << "================================"
                                        "===\n"
                                     << "Your Choice: ";
                                cin >> chooseRecycler;
                            }

                            //switch case for recycler menu
                            switch (chooseRecycler) {

                                //if user choose case 1, they will be allowed
                                // to edit their profile data
                                case 1:
                                    cout<<endl;
                                    cout << "What do you want to edit:\n"
                                         << "==============================\n"
                                         << "      1. Fullname\n"
                                         << "      2. Password\n"
                                         << "      3. Back Login Menu\n"
                                         << "==============================\n"
                                         << "Your option: ";
                                    cin >> option;
                                    //if the user choose option 1
                                    if (option == 1)
                                    {
                                        cout<<endl;
                                        cout << "Input new Fullname: ";
                                        getline(cin>>ws, fullName);
                                        //the user fullname will be edit
                                        // and set into the new one
                                        User->setFullName(fullName);
                                        cout<<endl;
                                        //displaying the new fullname
                                        cout<<"Fullname:"+User->getFullName()<<endl;
                                        cout<<endl;
                                        cout<<"===========================\n";
                                        cout<<" Fullname has been update\n";
                                        cout<<"===========================\n";
                                        cout<<endl;
                                    }
                                    //if the user choose option 2
                                    else if (option == 2)
                                    {
                                        cout<<endl;
                                        cout << "Input new Password: ";
                                        cin >> password;
                                        //the user password will be edit
                                        // and set into the new one
                                        User->setPassword(password);
                                        //displaying the new password
                                        cout<<"Password:"+User->getPassword()<<endl;
                                        cout<<endl;
                                        cout<<"===========================\n";
                                        cout<<" Password has been update\n";
                                        cout<<"===========================\n";
                                        cout<<endl;
                                    }
                                    //if the user choose option 3
                                    else if (option == 3)
                                    {
                                        //the program will brings the user
                                        // to recycler menu
                                        menuSignin = 1;
                                    }
                                    //if the user input the wrong data
                                    else
                                    {
                                        //the program will display
                                        // notification message
                                        //and allow them to choose the
                                        // right option
                                        cout<< "Wrong Choice, Please "
                                               "try again\n";
                                        chooseRecycler = 1;
                                    }
                                    break;

                                    //if user choose case 2
                                    //they will be allowed to submit
                                    //the items that they want to submit
                                case 2:
                                    //if the data material is empty
                                    if (newEcoSave.checkMaterial() != 1)
                                    {
                                        //the program will give a
                                        // notification message
                                        cout << "There is no material yet\n";
                                    }
                                    //if not the recycler can submit their
                                    // items
                                    else
                                    {
                                        cout << "====> Available Items <====\n";
                                        //displaying available material data
                                        cout << newEcoSave.listMaterial()<<endl;
                                        cout << endl;
                                        cout << "Input Material ID that you"
                                                " have choosen :";
                                        cin >> materialID;
                                        cout << "=========================="
                                                "=========" <<endl;
                                        //assigning data from method
                                        // getmaterialID into listMaterial
                                        listMaterial = newEcoSave.getMaterialID(materialID);
                                        //if the data is empty
                                        if(listMaterial == nullptr)
                                        {
                                            //the program will give
                                            // notification message
                                            cout << "!================!\n";
                                            cout << "  No material ID \n";
                                            cout << "!================!\n";
                                            //and the program allow the
                                            // user re-input data again
                                            chooseRecycler = 2;
                                        }
                                        //if the data is not empty
                                        else {
                                            //the collector name will be
                                            // displayed
                                            cout << listMaterial->getListCollector() << endl;
                                            cout << endl;
                                            cout << "Do you want to submit "
                                                    "items: <Y>es/<N>o";
                                            char menuItem;
                                            cin >> menuItem;
                                            //if the user want to submit
                                            // the items
                                            if (menuItem == 'Y' || menuItem == 'y') {
                                                //user must input the
                                                // collector username
                                                cout << "Input collector"
                                                        " username :";
                                                cin >> username;
                                                cout << "=================="
                                                        "=========\n";
                                                cout << endl;
                                                //the data of findCollector
                                                // method in ecosave class
                                                //will be assigned to
                                                // dataCollector variable
                                                dataCollector = newEcoSave.findCollector(username);
                                                //if the data is empty
                                                if (dataCollector == nullptr) {
                                                    //the program will give
                                                    // notification message
                                                    cout << "!============="
                                                            "=============="
                                                            "===!\n";
                                                    cout << "       No "
                                                            "Collector Name"
                                                            " \n";
                                                    cout << "     Please "
                                                            "input another "
                                                            "name \n";
                                                    cout << "!============="
                                                            "=============="
                                                            "===!\n";
                                                    //and allow the user to
                                                    // re-input data again
                                                    chooseRecycler = 2;
                                                }
                                                //if the data is not empty
                                                else
                                                {
                                                    //The user enters the
                                                    // proposed date according
                                                    // to the date of
                                                    // submission of the item
                                                    cout << "=============="
                                                            "=============="
                                                            "====\n";
                                                    cout << "Input Proposed"
                                                            " Date <DD/MM/YY> :";
                                                    cin >> proposedDate;
                                                    cout << "=============="
                                                            "=============="
                                                            "====\n";
                                                    //assigning data from
                                                    // submission class
                                                    // contructor to
                                                    // dataSubmission
                                                    dataSubmission = new submission(proposedDate);
                                                    //add the data into
                                                    // Submissiondata
                                                    // method in ecosave
                                                    // class
                                                    newEcoSave.Submissiondata(*dataSubmission, *dataCollector,
                                                                              *listMaterial,
                                                                              *Recycler);
                                                    cout << endl;
                                                    cout << "=============="
                                                            "=======\n";
                                                    cout << " Item has been"
                                                            " added \n";
                                                    cout << "=============="
                                                            "=======\n";
                                                }
                                                //if the user does not want
                                                // to submit items
                                            } else if (menuItem == 'N' || menuItem == 'n') {
                                                //the program will brings
                                                // them into recycler menu
                                                menuSignin = 1;
                                                cout << endl;
                                            }
                                        }
                                    }
                                    break;
                                    //the user chooce case 3 they will be
                                    // allowed to see the submission
                                    // history
                                case 3:
                                    //displays material data that has been
                                    // submitted
                                    // by the recycler and received by the
                                    // collector
                                    cout << newEcoSave.listMaterial()<<endl;
                                    cout << endl;
                                    //user input the material id of the items
                                    // that want to be viewed
                                    cout << "Enter the material ID you want"
                                            " to view : ";
                                    cin >> materialID;
                                    //assigning data from method getMaterialID
                                    // in ecosave class to dataMaterial
                                    dataMaterial = newEcoSave.getMaterialID(materialID);
                                    //if dataMaterial is not empty
                                    if(dataMaterial != nullptr)
                                    {
                                        //the program will display the menu for view history
                                       cout << "Show history of submission "
                                               "based on \n"
                                            << "1. Status of Submission \n"
                                            << "2. Actual Date of Submission \n"
                                            << "3. back to Recycler menu\n"
                                            << "Your choice: ";
                                       cin >> choiceHistory;
                                       //if the user choose option 1
                                       //the data will be sorted based on
                                       // submission status
                                       if ( choiceHistory == 1)
                                       {    //displays history data based
                                           // on the status of the submission
                                           cout << newEcoSave
                                           .viewSubmissionUser
                                           (*dataMaterial,
                                            *dataRecycler, choiceStatus)<<endl;
                                           /*
                                            * the program to display the
                                            * view history is only half done,
                                            * for sorting data using the
                                            * actual date and the status
                                            * cannot be fully used.*/
                                       }
                                       //if the user choose option 1
                                       //the data will be sorted based on actual date
                                       else if(choiceHistory == 2)
                                       {
                                           //displays history data based on the actual date of the submission
                                           cout << newEcoSave
                                           .viewSubmissionUser
                                           (*dataMaterial,
                                            *dataRecycler, choiceStatus)<<endl;
                                           /*
                                            * the program to display the view history is only half done,
                                            * for sorting data using the actual date and the status
                                            * cannot be fully used.*/
                                       }
                                       //if the user choose option 3
                                       else if(choiceHistory == 3)
                                       {
                                           //the program will brings them into recycler menu
                                           menuSignin = 1;
                                           cout << endl;
                                       }
                                       else
                                       {
                                           cout << "Wrong choice \n";
                                       }
                                    }
                                        //if the data is empty
                                    else
                                    {
                                        //the program will give notification
                                        // message and brings the user to
                                        // recycler menu
                                        cout << "There is no data submission"
                                                " yet\n";
                                        menuSignin = 1;
                                        cout << endl;

                                    }
                                    break;
                                case 4:
                                    cout << "Do you want to quit: <Y(yes)"
                                            "/N(no)\n"
                                         << "Your choice: ";
                                    char menuQuit;
                                    cin >> menuQuit;
                                    //if the user choose y or Y
                                    if (menuQuit == 'y' || menuQuit == 'Y')
                                    {
                                        //the program will quit and back to login menu
                                        cout << endl;
                                        cout << "\t=================\n";
                                        cout << "\tQuiting........\n";
                                        cout << "\t=================\n";
                                        cout << endl;
                                        Recycler = nullptr;
                                        delete Recycler;
                                        break;
                                    }
                                    //if the user choose n or N
                                    else if (menuQuit == 'n' || menuQuit == 'N')
                                    {
                                        //the program will brings them into recycler menu
                                        menuSignin = 1;
                                        cout << endl;
                                    }
                            }
                        }

                        //if the collector data is not empty
                        while(Collector != nullptr)
                        {
                            //menu collector will be displayed
                            cout << "=======> Welcome Collector <======= " << endl;
                            cout << endl;
                            cout << "===================================" <<endl;
                            //collector fullname will be shown
                            cout << "Fullname: "<<Collector->getFullName()<< endl;
                            //collector total points will be shown
                            cout << "Total Points: "<<Collector->getTotalPoints()<< endl;
                            cout << "===================================" <<endl;
                            cout << endl;
                            cout << "         Do You want to:\n"
                                 << "         1. Edit Profile\n"
                                 << "         2. Material Data\n"
                                 << "         3. Record Material Submission\n"
                                 << "         4. View Submission History\n"
                                 << "         5. Quit\n"
                                 << "======================================"
                                    "=======\n"
                                 << "Your Choice: ";
                            cin >> chooseCollector;

                            //if the user input the wrong choice
                            while(!(chooseCollector == 1 || chooseCollector == 2 || chooseCollector == 3 || chooseCollector == 4 || chooseCollector == 5))
                            {
                                cout << "Wrong choice, please choose the "
                                        "right option \n";
                                cout << "       Do You want to:\n"
                                        << "         1. Edit Profile\n"
                                        << "         2. Material Data\n"
                                        << "         3. Record Material "
                                           "Submission\n"
                                        << "         4. View Submission"
                                           " History\n"
                                        << "         5. Quit\n"
                                        << "============================"
                                           "=================\n"
                                        << "Your Choice: ";
                                cin >> chooseCollector;
                            }

                            //swicth case for collector menu
                            switch (chooseCollector) {
                                //if user choose case 1
                                //the program will allow them to edit their profile
                                case 1:
                                    cout << "What do you want to edit:\n"
                                         << "==============================\n"
                                         << "      1. Fullname\n"
                                         << "      2. Password\n"
                                         << "      3. Back to Login Menu\n"
                                         << "==============================\n"
                                         << "Your option: ";
                                    cin >> option;
                                    //if the user choose option 1
                                    if (option == 1)
                                    {
                                        cout<<endl;
                                        cout << "Input new Fullname: ";
                                        getline(cin>>ws, fullName);
                                        //the user fullname will be edit
                                        // and set into the new one
                                        User->setFullName(fullName);
                                        cout<<endl;
                                        //displaying the new fullname
                                        cout<<"Fullname:"+User->getFullName()<<endl;
                                        cout<<endl;
                                        cout<<"===========================\n";
                                        cout<<" Fullname has been update\n";
                                        cout<<"===========================\n";
                                        cout<<endl;
                                    }
                                        //if the user choose option 2
                                    else if (option == 2)
                                    {
                                        cout<<endl;
                                        cout << "Input new Password: ";
                                        cin >> password;
                                        //the user password will be edit
                                        // and set into the new one
                                        User->setPassword(password);
                                        //displaying the new password
                                        cout<<"Password:"+User->getPassword()<<endl;
                                        cout<<endl;
                                        cout<<"===========================\n";
                                        cout<<" Password has been update\n";
                                        cout<<"===========================\n";
                                        cout<<endl;
                                    }
                                    //if the user choose option 3
                                    else if (option == 3)
                                    {
                                        //the program will brings them into collector menu
                                        menuSignin = 1;
                                    }
                                    //if the user input the wrong option
                                    else
                                    {
                                        //the program will give
                                        // notification message
                                        //and allow them to choose
                                        // the right option
                                        cout<< "Wrong Choice, Please"
                                               " try again\n";
                                        chooseCollector = 1;
                                    }
                                    break;

                                    //if user choose case 2
                                    //they will be allowed
                                    // to collect the material
                                case 2:
                                    //if the material data is not empty
                                    if (newEcoSave.checkMaterial() == 1) {
                                        cout << "Available Data Materials  \n";
                                        //a list of materials available to
                                        // collect will be displayed
                                        cout << newEcoSave.listMaterial()<< endl;
                                        cout << "What do you want to do: \n"
                                             << "1. Collect Material\n"
                                             << "2. Back to Collector Menu\n"
                                             << "Your choice: ";
                                        cin >> choiceMaterial;
                                        cout << endl;

                                        //if the user choose option 1
                                        if(choiceMaterial == 1)
                                        {
                                            //user will input the
                                            // material ID
                                            cout << "Please input"
                                                    " Material ID: ";
                                            cin >> materialID;
                                            //if material ID is existed
                                            if (newEcoSave.checkMaterial() == 1)
                                            {
                                                material* Material = newEcoSave.getMaterialID(materialID);
                                                //material data will be
                                                // added to collectMaterial
                                                // data for collector
                                                newEcoSave.collectMaterial(*Material, *Collector);
                                                cout << "Material has been"
                                                        " collected\n";
                                            }
                                            //if the material id is
                                            // not available
                                            else
                                            {
                                                //the program will give
                                                // notification message
                                                //and allow the user to
                                                // input another material ID
                                                cout << "\nNo Material ID "
                                                        "with this number\n";
                                                choiceMaterial = 1;
                                            }
                                        }
                                        //if the user choose option 2
                                        else if(choiceMaterial == 2)
                                        {
                                            //the program will brings the
                                            // user to collector menu
                                            menuSignin = 1;
                                        }
                                    }
                                    //if the material data is empty
                                    else
                                    {
                                        //the program will give notification message
                                        cout << "There is no material yet \n";
                                    }
                                    break;
                                    //if the user choose case 3 the program allow
                                    //them to record material submission
                                case 3:
                                    cout << "Recording Material Submission \n"
                                        //recycler username will be displayed
                                        // who has made an appoinment
                                         << newEcoSave.recyclerUsername(dataCollector)+"\n"
                                         << "Input Recycler Username: ";
                                    cin >> username;
                                    //assigning value from method findRecycler into dataRecycler
                                    dataRecycler = newEcoSave.findRecycler(username);
                                    //if the data is not empty
                                    if (dataRecycler != nullptr)
                                    {
                                        //the list of submission data will be displayed
                                        cout<<endl<<newEcoSave.dataSubmissionMaterial(dataRecycler, dataCollector)+"\n";
                                        cout<<endl;
                                        //user will input the submission id
                                        cout << "Input Submission ID: ";
                                        cin >> submissionID;
                                        // if the submission id is not wrong and it's available
                                        if (dataRecycler->checkSubmission(submissionID) != false)
                                        {
                                            //the user will input the weight in kg and current date
                                            cout << endl;
                                            cout << "Enter the Weight in Kg: ";
                                            cin >> weightInKg;
                                            cout << "Enter the current date"
                                                    " <DD/MM/YY>: ";
                                            cin >> currentDate;
                                            cout << endl;
                                            //the data will be accept and it will be displayed
                                            cout << newEcoSave.acceptSubmissionMaterial(dataSubmission, dataCollector, weightInKg, currentDate, dataRecycler);
                                        }
                                        //if the submission id is wrong and unavailable
                                        else
                                        {
                                            //the program will give notification message
                                            //and allow the user to input another submission ID
                                            cout<<endl;
                                            cout << "======================";
                                            cout << "  No Submission ID \n";
                                            cout << "======================";
                                            chooseCollector = 3;
                                        }
                                    }
                                    cout << endl;
                                    break;

                                case 4:
                                    //displays material data that has been submitted
                                    // by the recycler and received by the collector
                                    cout << newEcoSave.listMaterial()<<endl;
                                    cout << endl;
                                    //user input the material id of the items that want to be viewed
                                    cout << "Enter the material ID you want"
                                            " to view : ";
                                    cin >> materialID;
                                    //assigning data from method getMaterialID in ecosave class to dataMaterial
                                    dataMaterial = newEcoSave.getMaterialID(materialID);
                                    //if dataMaterial is not empty
                                    if(dataMaterial != nullptr)
                                    {
                                        //the program will display the menu
                                        // for view history
                                        cout << "Show history of submission based on \n"
                                             << "1. Status of Submission \n"
                                             << "2. Actual Date of Submission \n"
                                             << "3. back to Recycler menu\n"
                                             << "Your choice: ";
                                        cin >> choiceHistory;
                                        //if the user choose option 1
                                        //the data will be sorted based on
                                        // submission status
                                        if ( choiceHistory == 1)
                                        {    //displays history data based
                                            // on the status of the
                                            // submission
                                            cout << newEcoSave.viewSubmissionUser(*dataMaterial,*dataRecycler, choiceStatus)<<endl;
                                        }
                                            //if the user choose option 1
                                            //the data will be sorted based
                                            // on actual date
                                        else if(choiceHistory == 2)
                                        {
                                            //displays history data based
                                            // on the actual date of the
                                            // submission
                                            cout << newEcoSave.viewSubmissionUser(*dataMaterial,*dataRecycler, choiceStatus)<<endl;
                                            /*
                                             * the program to display the
                                             * view history is only half done,
                                             * for sorting data using the
                                             * actual date and the status
                                             * cannot be fully used.*/
                                        }
                                            //if the user choose option 3
                                        else if(choiceHistory == 3)
                                        {
                                            //the program will brings them
                                            // into recycler menu
                                            menuSignin = 1;
                                            cout << endl;
                                        }
                                        else
                                        {
                                            cout << "Wrong choice \n";
                                        }
                                    }
                                        //if the data is empty
                                    else
                                    {
                                        //the program will give notification
                                        // message and brings the user to
                                        // collector menu
                                        cout << "There is no data submission"
                                                " yet\n";
                                        menuSignin = 1;
                                        cout << endl;

                                    }
                                    break;
                                case 5:
                                    cout << "Do you want to quit: <Y(yes)/N(no)\n"
                                         << "Your choice: ";
                                    char menuQuit;
                                    cin >> menuQuit;
                                    //if the user choose y or Y
                                    if (menuQuit == 'y' || menuQuit == 'Y')
                                    {
                                        //the program will quit and back to login menu
                                        cout << endl;
                                        cout << "\t=================\n";
                                        cout << "\tQuiting........\n";
                                        cout << "\t=================\n";
                                        cout << endl;
                                        Collector = nullptr;
                                        delete Collector;
                                        break;
                                    }
                                        //if the user choose n or N
                                    else if (menuQuit == 'n' || menuQuit == 'N')
                                    {
                                        //the program will brings them into
                                        // recycler menu
                                        menuSignin = 1;
                                        cout << endl;
                                    }
                            }
                        }
                    }
                }
                else if(menuSignin == 2)
                {
                    //input username and password
                    cout<<"Username: ";
                    cin>>username;
                    cout<<endl;
                    cout<<"Password: ";
                    cin>>password;
                    cout<<endl;

                    //assigning data from method loginUser
                    // in ecosave into variable User
                    User = newEcoSave.loginUser(username, password);

                    //create a pointer for object admin to know the
                    // username belongs to which class
                    admin* Admin = dynamic_cast<admin*>(User);
                    //if admin data is not null
                    while(Admin != nullptr) {
                        cout << "========> Welcome Admin <========\n";
                        // display the admin fullname
                        cout<<endl;
                        cout << "Fullname :" << Admin->getFullName()
                                                +"\n";
                        cout<<endl;
                        cout << "==================================\n";
                        cout<<endl;
                        cout << "What do you want to do: \n"
                             << "1. Edit Material\n"
                             << "2. View Submission History\n"
                             << "3. Quit\n"
                             << "Your choice: ";
                        cin >> chooseAdmin;

                        //swicth case for admin menu
                        switch (chooseAdmin) {
                            //if the admin choose case 1
                            //the program will allow the admin to
                            // edit material data
                            case 1:
                                //method material data is called
                                materialData();
                                cin >> choiceMaterialData;

                                //if admin choose option 1
                                if (choiceMaterialData == 1) {
                                    //admin allows to add new
                                    // material. the admin will
                                    // input the material name,
                                    // material description and
                                    // material points per kg
                                    cout << "Material Name: ";
                                    getline(cin >> ws, materialName);
                                    cout<<endl;
                                    cout << "Description: ";
                                    getline(cin >> ws, description);
                                    cout<<endl;
                                    cout << "Points per Kg: ";
                                    cin >> pointsPerKg;
                                    cout<<endl;

                                    //make a material pointer and
                                    // call the parameter constructor
                                    material *Material = new material
                                            (materialName, description,
                                             pointsPerKg);
                                    //add the material into method
                                    // addMaterial in ecosave
                                    newEcoSave.addMaterial(Material);
                                    cout << endl;
                                    //call the material's display
                                    // method
                                    cout << Material->Display() << endl;
                                    cout << "Material is successfully "
                                            "added \n";
                                    cout << endl;
                                }
                                    //if the admin choose option 2, the
                                    // program allow the admin to delete
                                    // the material data
                                else if (choiceMaterialData == 2) {
                                    //if material is available
                                    if (newEcoSave.checkMaterial() == 1)
                                    {
                                        cout << "Request ID available "
                                                "to be deleted: ";
                                        //The available material id
                                        // will be shown
                                        cout << newEcoSave.displayID()<< endl;
                                        //admin will input the
                                        // material id that want to
                                        // be deleted
                                        cout << "\n\nInput the material"
                                                " ID: ";
                                        cin >> materialID;
                                        cout << endl;

                                        //call the deleteMaterial
                                        //method which is in the ecosave
                                        // class and will delete the material
                                        // id-data that has been selected
                                        // by the admin
                                        newEcoSave.deleteMaterial(materialID);
                                        cout << "\nMaterial data "
                                                "has been deleted\n";
                                    }
                                        //if the material does not exist
                                    else {
                                        //the program will give
                                        // notification message
                                        // and automatically back to
                                        // admin menu
                                        cout << "\nThere is no Material"
                                                " yet!\n";
                                        menuSignin =2;
                                    }
                                }
                                    //if the admin choose option 3, the
                                    // program allow the admin to update
                                    // the material data that has been
                                    // add before
                                else if (choiceMaterialData == 3) {
                                    //if material data is unavailable
                                    if (newEcoSave.checkMaterial() != 1)
                                    {
                                        //the program will give
                                        // notification message
                                        // and automatically back to
                                        // admin menu
                                        cout << "\nThere is no Material"
                                                " yet!\n";
                                        menuSignin =2;
                                    }
                                        // if the material data is
                                        // available
                                    else {
                                        cout << "Request ID available "
                                                "to be updated: ";
                                        //the material id will be
                                        // displayed
                                        cout << newEcoSave.displayID
                                                ()+"\n";
                                        //admin input the material
                                        // id that want to be update
                                        cout << "\n\nWhich material "
                                                "that you want to edit: ";
                                        cin >> materialID;
                                        cout<<endl;
                                        //displaying data material
                                        // ID that has been inputed
                                        // before
                                        cout << newEcoSave.getMaterialID(materialID)->Display() << endl;
                                        cout << endl;
                                        //the program will allow the
                                        // admin to update the
                                        // material name, material
                                        // description and material
                                        // points per kg
                                        cout << "Material Name: ";
                                        getline(cin >> ws, materialName);
                                        cout << "Description: ";
                                        getline(cin >> ws, description);
                                        cout << "Points per Kg: ";
                                        cin >> pointsPerKg;

                                        //all the data will be
                                        // changed and set to the
                                        // new data that has been
                                        // inputed by admin
                                        newEcoSave.getMaterialID(materialID)->setmaterialName(materialName);
                                        newEcoSave.getMaterialID(materialID)->setdescription(description);
                                        newEcoSave.getMaterialID(materialID)->setpointsPerKg(pointsPerKg);

                                        //the material data that has
                                        //been update is shown
                                        cout << newEcoSave.getMaterialID(materialID)->Display();
                                        cout << "\n\nData Updated\n";
                                    }
                                }
                                break;
                                //if the admin choose case 2 the
                                //program allow admin to view the
                                // record material submission
                            case 2:
                                //displays material data that has been
                                // submitted
                                // by the recycler and received by the
                                // collector
                                cout << newEcoSave.listMaterial()<<endl;
                                cout << endl;
                                //admin input the material id of the
                                // items that want to be viewed
                                cout << "Enter the material ID you want"
                                        " to view : ";
                                cin >> materialID;
                                //assigning data from method
                                // getMaterialID in ecosave class to
                                // dataMaterial
                                dataMaterial = newEcoSave.getMaterialID(materialID);
                                //if the data is not empty
                                if(dataMaterial != nullptr)
                                {
                                    //the program will display the menu
                                    // for view history
                                    cout << "Show history of submission "
                                            "based on \n"
                                         << "1. Status of Submission \n"
                                         << "2. Actual Date of "
                                            "Submission \n"
                                         << "3. back to Recycler menu\n"
                                         << "Your choice: ";
                                    cin >> choiceHistory;
                                    //if the admin choose option 1
                                    //the data will be sorted based on
                                    // submission status
                                    if ( choiceHistory == 1)
                                    {    //displays history data based
                                        // on the status of the submission
                                        cout << newEcoSave.viewSubmissionAdmin(*dataMaterial, choiceStatus)<<endl;
                                    }
                                        //if the admin choose option 1
                                        //the data will be sorted based
                                        // on actual date
                                    else if(choiceHistory == 2)
                                    {
                                        //displays history data based on
                                        // the actual date of the submission
                                        cout << newEcoSave.viewSubmissionAdmin(*dataMaterial, choiceStatus)<<endl;
                                        /*
                                         * the program to display the
                                         * view history is only half done,
                                         * for sorting data using the
                                         * actual date and the status
                                         * cannot be fully used.*/
                                    }
                                        //if the admin choose option 3
                                    else if(choiceHistory == 3)
                                    {
                                        //the program will brings
                                        // the admin into admin menu
                                        menuSignin = 2;
                                        cout << endl;
                                    }
                                    else
                                    {
                                        cout << "Wrong choice \n";
                                    }
                                }
                                //if the data is empty
                                else
                                {
                                    //the program will give notification
                                    // message and brings the admin to
                                    // admin menu
                                    cout << "There is no data submission"
                                            " yet\n";
                                    menuSignin = 2;
                                    cout << endl;

                                }
                                break;
                                //if the admin choose case 3
                            case 3:
                                cout << "Do you want to quit: <Y(yes)"
                                        "/N(no)\n"
                                     << "Your choice: ";
                                char menuQuit;
                                cin >> menuQuit;
                                //if the admin choose y or Y
                                if (menuQuit == 'y' || menuQuit == 'Y')
                                {
                                    //the program will quit and back to
                                    // login menu
                                    cout << endl;
                                    cout << "\t=================\n";
                                    cout << "\tQuiting........\n";
                                    cout << "\t=================\n";
                                    cout << endl;
                                    Admin = nullptr;
                                    delete Admin;
                                    break;
                                }
                                    //if the user choose n or N
                                else if (menuQuit == 'n' || menuQuit == 'N')
                                {
                                    //the program will brings admin
                                    // into admin menu
                                    menuSignin = 2;
                                    cout << endl;
                                }
                        }
                    }
                }
                //if the admin choose option 3
                else if (menuSignin == 3)
                {
                    //the main menu method is called
                    // adn the program will be back into main program
                    mainMenu();
                    cin>>choice;
                }
                break;
                //if the user choose case 3
            case 3:
                //the program is finished
                cout << endl;
                cout << "Thank You for Using our Program \n";
                break;
        }
    }
    //if the user choose option 3 before sign up or sign in
    //the program will automatically finish
    if(choice == 3)
    {
        cout <<endl;
        cout << "Thank You for Using our Program \n";
    }
   return 0;
}
