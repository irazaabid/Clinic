#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <limits>
class Patient
{
private:
    std::string name;
    int age;
    std::string sex;
    std::string cnic;
    std::string medicalHistory;
    std::string prescription;

public:
    Patient() = default;
    Patient(std::string name, int age, std::string sex, std::string cnic, std::string medicalHistory, std::string prescription)
    {
        this->name = name;
        this->age = age;
        this->sex = sex;
        this->cnic = cnic;
        this->medicalHistory = medicalHistory;
        this->prescription = prescription;
    }
    void displayInformation()
    {
        std::cout << "*** Patient Information ***" << std::endl
                  << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
        std::cout << "Sex: " << sex << std::endl;
        std::cout << "CNIC: " << cnic << std::endl;
        std::cout << "Medical History: " << medicalHistory << std::endl;
        std::cout << "Prescription: " << prescription << std::endl;
    }
    void saveToFile(std::ofstream &out)
    {
        out << name << "\n"
            << age << "\n"
            << sex << "\n"
            << cnic << "\n"
            << medicalHistory << "\n"
            << prescription << "\n";
    }
    bool loadFromFile(std::ifstream &in)
    {
        if (!std::getline(in, name))
            return false;
        std::string ageStr;
        if (!std::getline(in, ageStr))
            return false;
        age = std::stoi(ageStr);
        if (!std::getline(in, sex))
            return false;
        if (!std::getline(in, cnic))
            return false;
        if (!std::getline(in, medicalHistory))
            return false;
        if (!std::getline(in, prescription))
            return false;
        return true;
    }
    std::string getCNIC()
    {
        return cnic;
    }
} p1;
class Medicine
{
private:
    std::string name;
    double price;
    int totalUnit;
    std::string expiry;

public:
    Medicine(std::string name, double price, int totalUnit, std::string expiry)
    {
        this->name = name;
        this->price = price;
        this->totalUnit = totalUnit;
        this->expiry = expiry;
    }
    void displayInformation()
    {
        std::cout << "*** Medicine Information ***" << std::endl
                  << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Price: " << price << std::endl;
        std::cout << "Total Unit: " << totalUnit << std::endl;
        std::cout << "Expiry Date: " << expiry << std::endl;
    }
};
class Staff
{
private:
    std::string name;
    std::string role;
    double salary;
    std::string shiftTime;

public:
    Staff(std::string name, std::string role, double salary, std::string shiftTime)
    {
        this->name = name;
        this->role = role;
        this->salary = salary;
        this->shiftTime = shiftTime;
    }
    void displayInformation()
    {
        std::cout << "*** Staff Information ***" << std::endl
                  << std::endl;
        std::cout << "Name: " << name << std::endl;
        std::cout << "Role: " << role << std::endl;
        std::cout << "Salary: " << salary << std::endl;
        std::cout << "Shift Time: " << shiftTime << std::endl;
    }
};
// Patient Details
void addPatient()
{
    std::string name;
    int age;
    std::string sex;
    std::string cnic;
    std::string medicalHistory;
    std::string prescription;
    std::cout << "*** Enter Patient Details ***" << std::endl
              << std::endl;
    std::cout << "Name: " << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, name);
    std::cout << "Age: " << std::endl;
    std::cin >> age;
    int s;
    std::cout << "Sex: " << std::endl;
    std::cout << "1. Male" << std::endl;
    std::cout << "2. Female" << std::endl;
    std::cin >> s;
    if (s == 1)
        sex = "Male";
    else if (s == 2)
        sex = "Female";
    else
        sex = "Unknown";
    std::cout << "CNIC: " << std::endl;
    std::cin >> cnic;

    std::cout << "Medical History: " << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, medicalHistory);
    std::cout << "Prescrition: " << std::endl;
    std::getline(std::cin, prescription);
    Patient p1(name, age, sex, cnic, medicalHistory, prescription);
    std::ofstream out("patient.txt", std::ios::app);
    if (out.is_open())
    {
        p1.saveToFile(out);
        out.close();
        std::cout << "\nPatient Added Successfully" << std::endl;
    }
    else
    {
        std::cout << "Error opening file!" << std::endl;
    }
}
void addStaff(std::vector<Staff> &database)
{
    std::string name;
    std::string role;
    double salary;
    std::string shiftTime;
    std::cout << "*** Enter Staff Details ***" << std::endl;
    std::cout << "Name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Role: " << std::endl;
    std::getline(std::cin, role);
    std::cout << "Salary: " << std::endl;
    std::cin >> salary;
    std::cout << "Shift Time: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, shiftTime);
    Staff s1(name, role, salary, shiftTime);
    database.push_back(s1);
    std::cout << "\nStaff Added Successfully" << std::endl;
}
void addMedicine(std::vector<Medicine> &database)
{
    std::string name;
    double price;
    int totalUnit;
    std::string expiry;
    std::cout << "*** Enter Medicine Details ***" << std::endl;
    std::cout << "Name: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
    std::cout << "Price: " << std::endl;
    std::cin >> price;
    std::cout << "Total Unit: " << std::endl;
    std::cin >> totalUnit;
    std::cout << "Expiry Date: " << std::endl;
    std::cin.ignore();
    std::getline(std::cin, expiry);
    Medicine m1(name, price, totalUnit, expiry);

    database.push_back(m1);
    std::cout << "\nMedicine Added Successfully" << std::endl;
}
int getChoice()
{
    int choice;
    std::cout << std::endl
              << "Select" << std::endl
              << std::endl;
    std::cout << "1. Add Patient" << std::endl;
    std::cout << "2. Get Patient Information" << std::endl;
    std::cout << "3. Add Staff" << std::endl;
    std::cout << "4. Get Staff Information" << std::endl;
    std::cout << "5. Add Medicine" << std::endl;
    std::cout << "6. Get Medicine Information" << std::endl;
    std::cout << "7. Exit" << std::endl;
    std::cin >> choice;
    return choice;
}
void searchPatient(std::string cnic)
{
    char found = 'n';

    std::ifstream in("patient.txt", std::ios::in);
    if (!in.is_open())
    {
        std::cout << "Error: Could not open clinic database file." << std::endl;
        return;
    }
    while (p1.loadFromFile(in))
    {
        if (p1.getCNIC() == cnic)
        {
            p1.displayInformation();
            found = 'y';
            break;
        }
    }
    if (found == 'n')
    {
        std::cout << "Patient Record Not Found" << std::endl;
    }
    in.close();
}

int main()
{
    std::vector<Patient> patientDatabase;
    std::vector<Staff> staffDatabase;
    std::vector<Medicine> medicineDatabase;
    int choice;
    bool loop = true;
    do
    {
        choice = getChoice();
        if (choice > 7 || choice < 1)
        {
            std::cout << "Invalid Choice";
            continue;
        }
        switch (choice)
        {

        case 1:
        {
            addPatient();
            break;
        }
        case 2:
        {
            std::string cnic;
            std::cout << "Enter Patient CNIC: " << std::endl;
            std::cin >> cnic;
            searchPatient(cnic);
            break;
        }
        case 3:
        {
            addStaff(staffDatabase);
            break;
        }
        case 4:
        {
            int c;
            std::cout << "Enter Staff NO: " << std::endl;
            std::cin >> c;
            if (c == 1)
                staffDatabase[0].displayInformation();
            break;
        }
        case 5:
        {
            addMedicine(medicineDatabase);
            break;
        }
        case 6:
        {
            int c;
            std::cout << "Enter Medicine NO: " << std::endl;
            std::cin >> c;
            if (c == 1)
                medicineDatabase[0].displayInformation();
            break;
        }
        case 7:
        {
            std::cout << "\nExiting....\n";
            loop = false;
            break;
        }
        default:
        {
            std::cout << "UNKNOWN ERROR" << std::endl;
        }
        }
    } while (loop);
    return 0;
}