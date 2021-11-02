/**
// * author : Muthia Kartika Putri
// * Student ID: E1800189
// * Date : 18/12/2020
// * Assignment 1
// * BIT205
// * Note: Here I make all the classes into 1 header file
// * Editor : Clion
// * Version : Mingw-w64
*/


#ifndef E1800189_ECOSAVE_H
#define E1800189_ECOSAVE_H
//includ library of iostream
#include <iostream>
//include library for vector where this is a dynamic array
#include <vector>

//all classes prototype
class user;
class submission;
class collector;
class material;
class recycler;
class admin;
class EcoSave;


//<------------------------------------class user-------------------------------->
class user{
    //here I use the protected class access modifier
    // so that it can be accessed by the child classes
    // of the user class
protected:
    //in using string data type, I add std::
    // because I do not use namespace std
    std::string userName;//<- Varible Username
    std::string password;//<- Variable Password
    std::string fullName;//<- Variable Fullname
    int totalPoints;//<- Variable totalPoints
public:

    user()//Default constructor of user class
    {
        userName = "";
        password = "";
        fullName = "";
        totalPoints = 0;
    }
    //Constructor with parameter of user class
    user(std::string userName, std::string password, std::string fullName)
    {
        this->userName = userName;
        this->password = password;
        this->fullName = fullName;
        this->totalPoints = 0;
    }
    //Destructor of user class
    ~user(){}

    //getter method of Username in user class
    std::string getUsername()
    {
        //return data of Username
        return userName;
    }

    //getter method of Password in user class
    std::string getPassword()
    {
        //return data of Password
        return password;
    }

    //getter method of Fullname in user class
    std::string getFullName()
    {
        // return data of Fullname
        return fullName;
    }

    //getter method of Total Points in user class
    int getTotalPoints()
    {
        // return value of total points
        return totalPoints;
    }

    //setter method of Username in user class
    void setUsername(std::string userName)
    {
        //Username data that will be set
        this->userName = userName;
    }

    //setter method of Password in user class
    void setPassword(std::string password)
    {
        //Password data that will be set
        this->password = password;
    }

    //setter method of Fullname in user class
    void setFullName(std::string fullName)
    {
        //Fullname data that will be set
        this->fullName = fullName;
    }

    //setter method of Total Points in user class
    void setTotalPoints(int totalPoints)
    {
        //total points value that will be set
        this->totalPoints = totalPoints;
    }

    //virtual Display to declare this class
    // as an abstract class
    virtual std::string Display() = 0;

};


//<------------------------------------class submission-------------------------------->
class submission
{
private:
    static int id;//<- static variable of submission ID to make it into auto generate
    int submissionID;// <- int variable of sumbission ID
    std::string proposedDate;// <- string variable of proposed date
    std::string actualDate;// <- string variable of actual date
    int weightInKg; // <- int variable of weight in kg
    int pointsAwarded;// <- int variable of points awarded
    std::string status;// <- string variable of status

public:

    //constructor with parameter of submission class
    submission(std::string proposedDate)
    {
        submissionID = id++ ;// <- this id auto generate ID
        this->proposedDate = proposedDate;
        this->actualDate = "";
        this->weightInKg = 0;
        this->pointsAwarded = 0;
        this->status = "proposed";
    }

    //destructor of submission class
    ~submission(){}

    //getter method of submissionID in submission class
    int getsubmissionID(){
        //return data of submission ID
        return submissionID;
    }

    //getter method of proposed in submission class
    std::string getproposedDate(){
        //return data of proposed date
        return proposedDate;
    }

    //setter method of proposed date in submission class
    void setproposedDate(std::string proposedDate){

        //proposed date that will be set
       this->proposedDate = proposedDate;
    }

    //getter method of actual date in submission class
    std::string getactualDate(){
        //return data of actual date
        return actualDate;
    }

    //setter method of actual date in submission class
    void setactualDate(std::string actualDate){

        //actual date will be set
        this->actualDate = actualDate;
    }

    //getter method od weight in kg in submission class
    int getweightInKg(){
        //return data of weight in kg
        return weightInKg;
    }

    //setter method of weight in kg in submission class
    void setweightInKg(int weightInKg){
        //weight in kg will be set
        this->weightInKg = weightInKg;
    }

    //getter method of points awarded in submission class
    int getpointsAwarded(){
        //return data of points awarded
        return pointsAwarded;
    }

    //setter method of points awarded in submission class
    void setpointsAwarded(int pointsAwarded){
        //points awarded will be set
        this->pointsAwarded = pointsAwarded;
    }

    //getter method of status in submission class
    std::string getstatus(){
        //return data of status
        return status;
    }

    //setter method of status in submission class
    void setstatus(std::string status){
        //status will be set
        this->status = status;
    }

    //method for displaying data of submission class
    std::string Display()
    {
        //if the points awarded is less than 0
        if(pointsAwarded <= 0)
        {
            //it will return submission ID, proposed date, and submission status
            return "Submission ID :"+std::to_string(submissionID)+
            "\nProposed Date :"+proposedDate+
            "\nStatus : "+status+"\n";
                                                                                                                                                                                                                         "Status :"+status+"\n";
        }
        //if the points awarded is more than 0
        else{
            //it will return submission ID, proposed date, actual date
            //weight in kg, points awarded and submission status
            return "=======================\n"
            "Submission ID :"+std::to_string(submissionID)+
            "\nProposed Date :"+proposedDate+
            "\nActual Date :"+actualDate+
            "\nWight in Kg :"+std::to_string(weightInKg)+
            "\nPoints Awarded :"+std::to_string(pointsAwarded)+
            "\nStatus :"+status+"\n";
        }
    }

    // method with submission * data type for accepting submission
    submission* acceptSubmission(int weightInKg, string acctualDate, int weigtPerKgMaterial)
    {
          setweightInKg(weightInKg); // <- set the weight in kg with new data of weight in kg that has been inputted by user
          setactualDate(acctualDate); // <- set the actual date with new data of actual date that has been inputted by user
          setpointsAwarded(weigtPerKgMaterial*weightInKg);// <- set the total points awarded  with new data
            // based on the multiplication of the material weight per kg with the weight in kg entered by the collector
          setstatus("Submitted"); // <- set the status from proposed into submitted
        return this; // the object of this method will be return
    }

};
int submission:: id = 1; //<-assigning variable value


//<------------------------------------ class collector -------------------------------->
// This class is a child class of the user class
class collector : public user
{
private:
    std::string address; //<- Variable address
    std::vector<material*> dataMaterial; // <-vector variable of class material in collector class
    std::vector<submission*> dataSubmission; //<-vector variable of class submission in collector class

public:
    collector() // default constructor of collector class
    {
        address = "";
    }

    //constructor with parameter and combine with
    // user class data in collector class
    collector(std::string userName, std::string password, std::string fullName, std::string address)
            : user(userName, password, fullName)
    {
        this->address = address;
    }

    //destructor in collector class
    ~collector(){}


    //getter method of Address in collector class
    std::string getAddress()
    {
        //return data of address
        return address;
    }

    //setter method of Address in collector class
    void setAddress(std::string address)
    {
        //Address value that will be set
        this->address = address;
    }

    //Display method for showing collector data list
    std::string Display()
    {
        //return the data of collector
        return "=======================\n"
               "->Username : "+userName
               +"\n->Password : "+password
               +"\n->Full name : "+fullName
               +"\n->Total Points : "+std::to_string(totalPoints)
               +"\n->Address : "+address;
    }

    //method getMaterial with vector data type
    vector<material*> &getMaterial()
    {
        //return the material's vector variable
        return dataMaterial;
    }

    //method getSubmission with vector data type
    vector<submission*> &getSubmission()
    {
        //return the submmission
        return dataSubmission;
    }

    //method for checking submission data
    bool checkingSubmission(int idSubmission)
    {
        //looping to find existing submission data
        for(int m = 0; m < dataSubmission.size(); m ++)
        {
            //if the submission data gets the same submission id
            // as the submission id entered by the user
            if(dataSubmission[m]->getsubmissionID() == idSubmission)

                //it will return true
                return true;
        }
        //if not, it will return false
        return false;

    }
};

//<------------------------------------class material-------------------------------->
class material
{
private:
    int materialID; // <- int variable of material ID
    static int numID; // <- static variable of material ID to make it into auto generate
    std::string materialName;// <- string variable of material name
    std::string description;// <- string variable of description
    int pointsPerKg;// <- int variable of points per kg
    std::vector<collector*> dataCollector;// <- vector variable of collector class in material class
    std::vector<submission*> dataSubmission;// <- vector variable of submission class in material class

public:
    //default constructor
    material()
    {
        materialID = numID++;
        materialName = "";
        description = "";
        pointsPerKg = 0;
    }

    //contructor with parameter in material class
    material(std::string materialName, std::string description, int pointsPerKg)
    {
        materialID = numID++; //<- this is auto generate Id
        this->materialName = materialName;
        this->description = description;
        this->pointsPerKg = pointsPerKg;
    }

    //getter method of material ID in material class
    int getmaterialID()
    {
        //return data of material ID
        return materialID;
    }

    //getter method of material name in material class
    std::string getmaterialName()
    {
        //return data of material name
        return materialName;
    }

    //getter method of points per kg in material class
    int getpointsPerKg(){
        //return data of points per kg
        return pointsPerKg;
    }

    //getter method of description in material class
    std::string getdescription(){
        //return data of description
        return description;
    }

    //setter method of material name in material class
    void setmaterialName(std::string materialName)
    {
        //material name will be set
        this->materialName = materialName;
    }

    //setter method of description in material name
    void setdescription (std::string description){

        //description will be set
        this->description = description;
    }

    //setter method of points per kg in material name
    void setpointsPerKg (int pointsPerKg)
    {
        //points per kg will be set
        this->pointsPerKg = pointsPerKg;
    }

    //method for displaying material data
    std::string Display()
    {
        //return all material data
        return "=====================\n"
               "Material ID : "+std::to_string(materialID)
        +"\nMaterial Name : "+materialName
        +"\nDescription : "+description
        +"\nPoints Per Kg : "+std::to_string(pointsPerKg);
    }

    //a method to get data collectors in the form of full names
    std::string getListCollector()
    {
        std::string display = "";//<- string data type of display variable

        //looping to find existing collector data
        for (int m = 0; m < dataCollector.size(); m++) {
            //if the data is found, assigning collector name to display varibale
           display += "Collector Name: "+ dataCollector[m]->getUsername()+"\n";
        }
        //it will return the display data
        return display;
    }

    //method getCollector with vector data type
    vector<collector*> &getColletor()
    {
        //return the collector's vector variable
        return dataCollector;
    }

    //method getSubmission with vector data type
    vector<submission*> &getSubmission()
    {
        //return the submmission
        return dataSubmission;
    }

 };
int material :: numID = 1; // <- assigning variable value

//<------------------------------------class recycler-------------------------------->
// This class is a child class of the user class
class recycler : public user
{
private:
    std::string ecoLevel; // <-variable Ecolevel
    std::vector<submission*> dataSubmission; // vector variable of class submission in recycler class

public:
    recycler() // default constructor of recycler class
    {
        ecoLevel = "newbie";
    }

    //contructor with parameter and combine with
    // user class data in recycler class
    recycler(std::string userName, std::string password, std::string fullName)
            : user(userName, password, fullName)
    {
        this-> ecoLevel = "newbie";
    }

    //destructor of recycler class
    ~recycler(){}

    //getter of Ecolevel in recycler class
    std::string getEcoLevel()
    {
        // return data of Ecolevel
        return ecoLevel;
    }

    //setter of Ecolevel in recycler class
    void setEcoLevel(std::string ecoLevel)
    {
        // set Ecolevel data
        this->ecoLevel = ecoLevel;
    }

    //method for displaying data of recycler
    std::string Display()
    {
        // return all the member variable
        return "=======================\n"
                "->Username : "+userName
               +"\n->Password : "+password
               +"\n->Full name : "+fullName
               +"\n->Total Points : "+std::to_string(totalPoints)
               +"\n->Eco level : "+ecoLevel;
    }

    // method retrieves the getSubmission data
    // data type is a vector containing
    // a submission pointer
    vector<submission*> &getSubmission()
    {
        //return variable dataSubmission from vector submission class
        return dataSubmission;
    }

    //method for displaying data submission that has been submitted by collector
    //here accepts parameter of type data material* to
    // find a list of material data that has been submitted by the recycler
    std::string dataSubmissionRecycler(material* dataMaterial)
    {
        std::string displayData = "";
        submission* newDataSubmission;
        //The first loop is used to find the number of data
        // recyclers that have made material submissions
        for(int m = 0; m < dataSubmission.size(); m++)
        {
            //The second loop is used to find the amount
            // of material data that has been submitted by the recycler
            for(int u = 0; u < dataMaterial->getSubmission().size(); u++)
            {
                //Assigning the results from submitted material data
                // into the newDataSubmission variable
                newDataSubmission = dataMaterial->getSubmission()[u];

                //if the submission ID data matches the newDataSubmission ID
                // and the submission status data has the proposed status
                if(dataSubmission[m]->getsubmissionID() == newDataSubmission->getsubmissionID() && dataSubmission[m]->getstatus() == "proposed")
                {
                    //data of data submission will be stored in displayData variable
                    displayData += dataSubmission[m]->Display();
                }
            }
        }
        //return value of displayData variable
        return displayData;
    }

    // method for checking the submission data
    // with accept int parameter for submissionID
    bool checkSubmission(int submissionID)
    {
        //looping to find existing submission data
        for( int m = 0; m < dataSubmission.size(); m++)
        {
            //if the data getsubmission matches the
            // submission id entered by the user
            if(dataSubmission[m]->getsubmissionID() == submissionID)
                //it will return true
                return true;
        }
        //if not, it will return false
        return false;
    }

    //method for accpeting submission data for recycler
    // with accept int parameter for totalPoint
    void acceptSubmissionData(int totalPoint)
    {
        //it will set the total point awarded
        // and set the ecolevel based on the total point awarded
        setTotalPoints(totalPoint + getTotalPoints());
        if(getTotalPoints() >= 100 && getTotalPoints() < 500)
            setEcoLevel("Eco-Saver");
        else if (getTotalPoints() >= 500 && getTotalPoints() < 1000)
            setEcoLevel("Eco-Hero");
        else if(getTotalPoints() >= 1000 )
            setEcoLevel("Eco-Warrior");
    }

    //method for checking submission data
    bool checkingSubmission(int idSubmission)
    {
        //looping to find existing submission data
        for(int m = 0; m < dataSubmission.size(); m ++)
        {
            //if the submission data gets the same submission id
            // as the submission id entered by the user
            if(dataSubmission[m]->getsubmissionID() == idSubmission)

                //it will return true
                return true;
        }
        //if not, it will return false
        return false;
    }
};

//<------------------------------------class admin-------------------------------->
// This class is a child class of the user class
class admin : public user
{

public:

    //constructor with parameter of admin class
    admin(std::string userName, std::string password, std::string fullName)
    : user(userName, password, fullName){}

    //desctructor of admin class
    ~admin(){}

    //method for displaying admin data
    std::string Display()
    {
        //return all admin data
        return "=======================\n"
               "Username : "+userName
               +"\nPassword : "+password
               +"\nFullname :"+fullName;
    }

};

//<------------------------------------class ecosave-------------------------------->
class EcoSave {
private:
    std::vector<user*> newUsers; // <- vector variable of class user
    std::vector<material*> newMaterial; // <- vector variable of class material
public:
    EcoSave(){}//default constructor of class ecosave
    ~EcoSave(){}//destructor constructor of class ecosave

    //this method is used to adding recycler
    void addRecycler(user* addDataRecycler)
    {
        newUsers.push_back(addDataRecycler);
    }

    //this method is used to adding recycler
    void addCollector(user* addDataCollector)
    {
        newUsers.push_back(addDataCollector);
    }

    //this method is used to adding recycler
    void addAdmin()
    {
        //here I
        admin* Admin = new admin("admin", "admin", "Ecosave Admin");
        newUsers.push_back(Admin);
    }

    //this method is used to adding recycler
    void addMaterial(material* addDataMaterial)
    {
        newMaterial.push_back(addDataMaterial);
    }

    //this method is used to delete material
    void deleteMaterial(int Id)
    {
        vector<material*>::iterator dataMaterial;//<- iterator of class material
        // for loop to find material data
        for(dataMaterial=newMaterial.begin(); dataMaterial != newMaterial.end(); )
        {
            //if the material data iterator gets the same
            // material id the user entered,
            if((*dataMaterial)->getmaterialID()== Id)
            {
                //material data according to material id
                // will be deleted
                delete *dataMaterial;
                dataMaterial = newMaterial.erase(dataMaterial);
            } else
            { //if the material data iterator does not get a suitable
                // material id, then it will keep looking until
                // the material id is found
                dataMaterial++;
            }
        }
    }

    //method for user login
    user* loginUser(std::string username, std::string password){
        //for loop to find user data
        for(user* User:newUsers)
        {
            //if the user data obtained matches the username
            // and password entered by the user
            if(username == User->getUsername()&&password == User->getPassword())
                //it will return the user data
                return User;
        }
        //if not, it will return empty data
        return nullptr;
    }

    //method for checking userusername
    int checkUsername(std::string userName)
    {
        //for loop to find user data
        for (int m = 0; m<newUsers.size(); m++)
        {
            //if the user data matches the username
            // entered by the user
            if (userName == newUsers[m]->getUsername())
                //it will return 1, which means the data is found
                return 1;
        }
        //if not, it will return 0
        return 0;
    }

    //method for displaying materialID
    std::string displayID()
    {
        //string data type for display variable
        std::string display ="";
        //for loop to find material data
        for(int m = 0; m<newMaterial.size();m++)
        {
            //if the data is found, assigning material data to display variable
            display += "\n-"+std::to_string(newMaterial[m]->getmaterialID())+"\n<===========================>\n";
        }
        //return the data of display variable
        return display;
    }

    //method to get material id
    material* getMaterialID(int id)
    {
        //for loop to find material data
        for(int m = 0; m < newMaterial.size(); m++)
        {
            //if material data matches the materia
            // l id entered by the user
            if(newMaterial[m]->getmaterialID() == id)
                //it will return the data of material data
                return newMaterial[m];
        }
        //if not, it will return an empty data
        return nullptr;
    }

    //method to check available material
    int checkMaterial()
    {
        //if data meterial is not equals to 0,
        // which means it is empty
        if(newMaterial.size()!=0)
            //it will return 1, which means the data is exist
            return 1;
        //if not, it will return 0
        return 0;
    }

    //method to collect material
    void collectMaterial(material& collectDataMaterial, collector& dataCollector)
    {
        //collector will add the material data that want to be collected
        dataCollector.getMaterial().push_back(&collectDataMaterial);
        //material will also add a data collector
        // that has successfully collected material data
        collectDataMaterial.getColletor().push_back(&dataCollector);
    }

    //method to display list of material which are availbel
    std::string listMaterial()
    {
        std::string display ="";// <-string data type for variable display
        //for loop to find data material
        for (int m = 0; m<newMaterial.size(); m++)
        {
            //if the data is found, assigning material data to display variable
            display += "\n"+newMaterial[m]->Display()+"\n<======================================>\n";
        }
        //return the display data
        return display;
    }

    //method to add submission data
    void Submissiondata( submission& dataSubmission, collector& collectorSubmission, material& materialSubmission, recycler& recyclerSubmission)
    {

        //the collector will add the submission data
        collectorSubmission.getSubmission().push_back(&dataSubmission);
        //the material will also add the submission data
        materialSubmission.getSubmission().push_back(&dataSubmission);
        //the collector will also add the submission data
        recyclerSubmission.getSubmission().push_back(&dataSubmission);
    }

    //method to find existing collector
    collector* findCollector(std::string collectorName)
    {
        //for loop to find user data
        for(int m = 0; m < newUsers.size(); m++)
        {
            //if user data matches the username entered by the user
            if(newUsers[m]->getUsername() == collectorName)

                //This will return the user data in the form
                //of a dynamic cast from the collector class
                //because the collector class is a class child
                //of the user class so I return the data in the
                //form of its dynamic cast
               return dynamic_cast<collector*>(newUsers[m]);
        }
        //if the user data doesn't matches the username
        //it will return empty data
        return nullptr;
    }

    //method to display data submission material
    std::string dataSubmissionMaterial(recycler* dataRecycler, collector* dataCollector)
    {
        std::string display = ""; // <-string data type for variable display
        material* materialData; // <- material* data type for variable materialData

        //for loop to find collector data that has been collected material
        for(int m = 0; m < dataCollector->getMaterial().size(); m++)
        {
            //if the data is found, the data is assigned to materialData
            materialData = dataCollector->getMaterial()[m];
            //the data that has been found before will be assigned into display variable
            display += "Material Name : "+materialData->getmaterialName()+"\n"+dataRecycler->dataSubmissionRecycler(materialData);
        }
        //return the display data
        return display;
    }

    //method to find recycler
    recycler* findRecycler(std::string user)
    {
        //for loop to find user data
        for(int m = 0; m < newUsers.size(); m++)
        {
            //if the user data matches
            // the username entered by the user
            if(newUsers[m]->getUsername() == user)
            {
                //This will return the user data in the form
                //of a dynamic cast from the recycler class
                //because the recycler class is a class child
                //of the user class so I return the data in the
                //form of its dynamic cast
                return dynamic_cast<recycler*>(newUsers[m]);
            }
        }
        //if the user data does not matches the user data,
        // than will return empty data
        return nullptr;
    }

    //method to find proposed date
    std::string dataSubmissionProposedDate()
    {
        submission* dataSubmission;//<-submission* data type for variable data submission
        std::string display = "";//<- string data type for display variable
        //for loop to find data submission that has inputed the proposed date
        for(int m = 0; m < dataSubmission->getproposedDate().size(); m++)
        {
            //if the data is found, it will be assigned into display variable
            display += "Proposed Date : "+dataSubmission->getproposedDate()+"\n";
        }
        //return the  display data
        return display;
    }

    //method to find recycler username
    std::string recyclerUsername(collector* collectorOwn)
    {
        std::string dataDisplay = ""; //<- string data type for dataDisplay variable
        //the first for loop is to find user data
        for(int m = 0 ; m < newUsers.size(); m++)
        {
            //the second for loop is to find collector who has the data submission
            for(int u = 0; u < collectorOwn->getSubmission().size(); u++)
            {
                int submissionID = collectorOwn->getSubmission()[u]->getsubmissionID();
                recycler* dataRecycler = dynamic_cast<recycler*>(newUsers[m]);
                if(dataRecycler != nullptr && dataRecycler->checkSubmission(submissionID))
                {
                    //if the data is found, it will be assigned into dataDisplay variable
                    dataDisplay += "Recycler Username : " + dataRecycler->getUsername()+"\n";
                }
            }
        }
        //return the value of dataDisplay
        return  dataDisplay;
    }

    //method for accepting submission material
    std::string acceptSubmissionMaterial(submission* dataSubmission, collector* dataCollector, int weightInKg, string actualDateData, recycler* dataRecycler)//mengubah totpoint di recycler)
    {
        material* dataMaterial; // <- material* data type  for variable data material
        int dataPointPerKg; // <- int data type for variable data point per kg
        int totPointsAwarded; // <- int data type for variable total points awarded

        // the first for loop is to find collector data who has material
        for(int m = 0; m < dataCollector->getMaterial().size(); m++)
        {
            dataMaterial = dataCollector->getMaterial()[m];
            // the second for loop is to find material data that has been submitted
            for(int u = 0; u < dataMaterial->getSubmission().size(); u++)
            {
                if (dataMaterial->getSubmission()[u]->getsubmissionID() == dataSubmission->getsubmissionID())
                {
                    //if the data is found, it will be
                    // assigned into variable data point per kg
                    dataPointPerKg = dataMaterial->getpointsPerKg();
                }
            }
        }
        submission* listSubmission = dataSubmission->acceptSubmission(weightInKg, actualDateData, dataPointPerKg);
        totPointsAwarded = listSubmission->getpointsAwarded();
        //it will calculated the final total points that has been reached for collector
        dataCollector->setTotalPoints(totPointsAwarded + dataCollector->getTotalPoints());
        //it will calculated the final total points that has been reached for recycler
        dataRecycler->acceptSubmissionData(totPointsAwarded);

        return listSubmission->Display();//<- return the submission display
    }

    //method to view the submission history for admin
    std:: string viewSubmissionAdmin(material& dataMaterial, int choice)
    {
        std::string display= "";
        std::string nameColl, nameRec;
        submission* dataSubmission;
        vector<submission*> datalistSUbmission;
        //sorting status
        if(choice == 1)
        {
            datalistSUbmission = dataMaterial.getSubmission();
            for(int u = 0; u <datalistSUbmission.size(); u++)
            {
                for(int t =0; t < (datalistSUbmission.size()-1);t++)
                {
                    if(datalistSUbmission[t]->getstatus().compare
                            (datalistSUbmission[t+1]->getstatus()) > 0)
                    {
                        dataSubmission = datalistSUbmission[t];
                        datalistSUbmission[t]=datalistSUbmission[t+1];
                        datalistSUbmission[t+1]=dataSubmission;
                    }
                }
            }
        }
        else
        {
            for(int h = 0; h < dataMaterial.getSubmission().size(); h++)
            {
                if(dataMaterial.getSubmission()[h]->getstatus() == "Submitted")
                {
                    datalistSUbmission.push_back(dataMaterial.getSubmission()[h]);
                }
            }
        }
        //the first for loop to find data submission
        for(int m = 0; m < datalistSUbmission.size(); m++)
        {
            //the second loop to find the user data
            for (int i = 0; i < newUsers.size(); ++i)
            {
                recycler* Recycler = dynamic_cast<recycler*>(newUsers[i]);
                collector* Collector = dynamic_cast<collector*>(newUsers[i]);
                //if the recycler data is available
                if(Recycler != nullptr && Recycler->checkingSubmission
                (datalistSUbmission[m]->getsubmissionID()))
                {
                    //it will assign the recycler fullname into variable nameRec
                    nameRec = Recycler->getFullName();
                }
                //if the collector data is available
                else if (Collector != nullptr && Collector->checkingSubmission
                (datalistSUbmission[m]->getsubmissionID()) )
                {
                    //it will assign the collector fullname into variable nameRec
                    nameColl = Collector->getFullName();
                }
            }
            //all the data recycler and collector also the submission data
            // will be assigned into display variable
            display += "Recycler : "+ nameRec +"\n" + "Collector : "+ nameColl
                    + "\n" + datalistSUbmission[m]->Display()+"\n";
        }
        //it will return the display data
        return display;
    }

    //method to view the submission history for admin
    std:: string viewSubmissionUser(material& dataMaterial, user&
    listUser, int choice)
    {
        std::string display= "";
        std::string nameColl, nameRec;
        bool checking;
        submission* dataSubmission;
        vector<submission*> datalistSUbmission;

        //sorting status
        if(choice == 1)
        {
            datalistSUbmission = dataMaterial.getSubmission();
            for(int u = 0; u <datalistSUbmission.size(); u++)
            {
                for(int t =0; t < (datalistSUbmission.size()-1);t++)
                {
                    if(datalistSUbmission[t]->getstatus().compare
                    (datalistSUbmission[t+1]->getstatus()) > 0)
                    {
                        dataSubmission = datalistSUbmission[t];
                        datalistSUbmission[t]=datalistSUbmission[t+1];
                        datalistSUbmission[t+1]=dataSubmission;
                    }
                }
            }
        }
        else
        {
            for(int h = 0; h < dataMaterial.getSubmission().size(); h++)
            {
                if(dataMaterial.getSubmission()[h]->getstatus() == "Submitted")
                {
                    datalistSUbmission.push_back(dataMaterial
                    .getSubmission()[h]);
                }
            }
        }
        recycler* dataRecycler = dynamic_cast<recycler*>(&listUser);
        collector* dataCollector = dynamic_cast<collector*>(&listUser);
        //the first for loop to find data submission
        for(int m = 0; m < datalistSUbmission.size(); m++)
        {
            //the second loop to find the user data
            for (int i = 0; i < newUsers.size(); ++i)
            {
                //checking the existing data of collector and recycler
                if(dataRecycler != nullptr)
                {
                    checking = dataRecycler->checkingSubmission
                            (datalistSUbmission[m]->getsubmissionID());
                }
                else
                    checking = dataCollector->checkingSubmission
                            (datalistSUbmission[m]->getsubmissionID());

                recycler* Recycler = dynamic_cast<recycler*>(newUsers[i]);

                collector* Collector = dynamic_cast<collector*>(newUsers[i]);

                //if the recycler data is found
                if(Recycler != nullptr && Recycler->checkingSubmission
                (datalistSUbmission[m]->getsubmissionID()) && checking)
                {
                    //it will assign the recycler fullname into variable nameRec
                    nameRec = Recycler->getFullName();
                }
                //if the recycler data is found
                else if (Collector != nullptr && Collector->checkingSubmission
                (datalistSUbmission[m]->getsubmissionID()) && checking)
                {
                    //it will assign the collector fullname into variable nameColl
                    nameColl = Collector->getFullName();
                }
            }
            //all the data recycler and collector also the submission data will be assigned into display variable
            display += "Recycler : "+ nameRec +"\n" + "Collector : "+ nameColl
                    + "\n" + datalistSUbmission[m]->Display()+"\n";
        }
        //it will return the display data
        return display;
    }
};

#endif //E1800189_ECOSAVE_H
