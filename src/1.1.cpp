#include <iostream>
#include <fstream>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;

class PMS
{
private:
    string cr_username;
    string cr_description;
    string cr_password;
    string profile_name;
    string master_password;
    int menu_choice;
    int profile_choice; // menu choice, Change name
    int choose_profile;

public:
    void welcomeMsg();
    void setProfile(); // stores Profile name, Master-password
    int storeProfile();
    void setCredential();
    void storeCredential();
    void run();
    int menu();
};
void PMS::welcomeMsg()
{
    cout << "\n! Welcome to the PASSWORD MANAGEMENT SYSTEM !" << endl;
}
void PMS::setProfile()
{
    cout << "Set the Profile nickname (without any white spaces): ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clears any leftover newline
    getline(cin, profile_name);
    cout << "Set the master-password: ";
    getline(cin, master_password);
}
int PMS::storeProfile()
{
    // Storing only the profile names everytime they are created
    ofstream StoreAllProfiles("../data/AllProfileData.txt", ios::app);
    StoreAllProfiles << profile_name <<endl;
    StoreAllProfiles.close();

    // Define path to data folder (relative to where the program runs)
    string folderPath = "../data";

    // Check if "data" folder exists, if not create it
    if (!fs::exists(folderPath)) //  checks whether the folder already exists
    {
        if (!fs::create_directory(folderPath)) // tries to create the folder (only runs if it doesn’t already exist)
        {
            cerr << "Failed to create folder: " << folderPath << endl;
            return 1;
        }
    }
    profile_name = folderPath + "/1.1." + profile_name + ".txt";

    ofstream storeProfileData(profile_name, ios::app); // Note: using new Constructor method
    storeProfileData << profile_name;
    storeProfileData << endl;
    storeProfileData << master_password;
    storeProfileData << endl
                     << endl;
    return 0;
}
void PMS::setCredential()
{
    cout << "\nEnter the username to be registered: ";
    cin.ignore();
    getline(cin, cr_username);
    cout << "Enter the password to be registered: ";
    getline(cin, cr_password);
    cout << "Enter the description to be registered: ";
    getline(cin, cr_description);
}
void PMS::storeCredential()
{
    ofstream storeCredentialDAta(profile_name, ios::app);
    storeCredentialDAta << cr_username;
    storeCredentialDAta << endl;
    storeCredentialDAta << cr_password;
    storeCredentialDAta << endl;
    storeCredentialDAta << cr_description;
    storeCredentialDAta << endl
                        << endl;
    storeCredentialDAta.close();
}
void PMS::run()
{
    welcomeMsg();
    menu();
    // setCredential();
    // storeCredential();
}
int PMS::menu()
{
    cout << "\nChoose the operation to be followed:\n";
    cout << "1. View a Stored profile\n";
    cout << "2. Create a New profile\n";
    cout << "3. Exit\n";

    cin >> menu_choice;
    switch (menu_choice)
    {
    case 1:
        cout<<"Choose one of the following profiles:\n";
        cin>>choose_profile;

        break;
    case 2:
        cout << "\nCreating a new Profile:\n";
        setProfile();
        storeProfile();
        cout << "\nProfile created successfully\n";

        while (1)
        {
            cout << "1. Add credentials\n";
            cout << "2. exit\n";
            cin >> profile_choice;
            switch (profile_choice)
            {
            case 1:
                setCredential();
                storeCredential();
                cout << "\nStored entered credential successfully\n";
                break;
            case 2:
                return 0;
                break;
            default:
                break;
            }
        }
        break;

    case 3:
        return 0;
        break;

    default:
        cout << "Submit your response in intgers 1,2,3 only!\n";
        break;
    }
    return 0;
}

int main()
{
    PMS alpha;
    alpha.run();

    return 0;
}