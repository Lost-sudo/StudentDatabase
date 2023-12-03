#include <iostream>
#include <vector>
#include <string>
#include <limits>

class Student {
public:
    std::string name;
    int age;
    std::string address;
    long long num;
    std::string course;
    std::string year_lvl;

    void getInfo();
    void printInfo() const;
};

void Student::getInfo() {
        do {
            std::cout << "Enter student name: \n";
            std::getline(std::cin, name);

            if (name.empty()) {
                std::cout << "Name can't be empty!\n";
            }
        } while (name.empty());

        do {
            std::cout << "Enter student's age\n";
            std::cin >> age;

            if (age <= 0) {
                std::cout << "Invalid age input!\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (age <= 0);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        do {
            std::cout << "Enter student's current address\n";
            std::getline(std::cin, address);

            if (address.empty()) {
                std::cout << "Address can't be empty!\n";
            }
        } while (address.empty());

        do {
            std::cout << "Enter phone number: \n";
            std::cin >> num;

            if (std::to_string(num).length() != 10) {
                std::cout << "Invalid phone number\n";
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }

        } while (std::to_string(num).length() != 10);

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        do {
            std::cout << "Enter course: \n";
            std::getline(std::cin, course);

            if(course.empty()){
                std::cout << "Course can't be empty!\n";
            }
        } while (course.empty());

        do {
            std::cout << "Enter year level: \n";
            std::getline(std::cin, year_lvl);

            if (year_lvl.empty()) {
                std::cout << "Year level cant be empty!\n";
            }
        } while (year_lvl.empty());

        std::cin.ignore();
    }
void Student::printInfo() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Age: " << age << "\n";
        std::cout << "Address: " << address << "\n";
        std::cout << "Number: " << num << "\n";
        std::cout << "Course: " << course << "\n";
        std::cout << "Year level: " << year_lvl << "\n";
    }

class Admin {
private:
    std::string inputUsername;
    std::string inputPassword;
    const std::string correctUsername = "admin";
    const std::string correctPassword = "adminpassword";

public:
    void setUser(std::string username) {
        inputUsername = username;
    }

    std::string getUser() {
        return inputUsername;
    }

    void setPass(std::string password) {
        inputPassword = password;
    }

    std::string getPass() {
        return inputPassword;
    }

    bool authenticate() {
        return (inputUsername == correctUsername && inputPassword == correctPassword);
    }

    bool adminMenu(std::vector<Student>& studentList) {
        do {
            std::cout << "Enter username: \n";
            std::cin >> inputUsername;
            setUser(inputUsername);
            std::cout << "Enter password: \n";
            std::cin >> inputPassword;

            setPass(inputPassword);

            if (!authenticate()) {
                std::cout << "Invalid username or password! \n";
                return false;
            }
        } while (!authenticate());

        int option;
        do {
            std::cout << "Admin Option:\n[1] Modify Student\n[2] Delete Student\n[3] Exit\n";
            std::cin >> option;
            switch (option) {
                case 1: {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::string nameToModify;
                    std::cout << "Enter name to modify:\n";
                    std::getline(std::cin, nameToModify);
                    modifyStudentbyName(studentList, nameToModify);
                    break;
                }
                case 2: {
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::string nameToDelete;
                    std::cout << "Enter name to delete:\n";
                    std::getline(std::cin, nameToDelete);
                    deleteStudentbyName(studentList, nameToDelete);
                    break;
                }
                case 3: {
                    std::cout << "Returning to the main menu.\n";
                    break;
                }
                default: {
                    std::cout << "Invalid Option!\n";
                    break;
                }
            }
        } while (option != 3);

        return true;
    }

    void modifyStudentbyName(std::vector<Student>& studentList, const std::string& name) {
        for (auto& student : studentList) {
            if (student.name == name) {
                std::cout << "Enter new information for student " << student.name << "\n";
                do {
                    std::cout << "Age:\n";
                    std::cin >> student.age;

                    if (student.age <= 0) {
                        std::cout << "Invalid age input!\n";
                    }
                } while (student.age <= 0);
                std::cin.ignore();

                do{
                    std::cout << "Address:\n";
                    std::getline(std::cin, student.address);

                    if (student.address.empty()) {
                    std::cout << "Address can't be empty!";
                    }
                }while(student.address.empty());

                do{
                    std::cout << "Number:\n";
                    std::cin >> student.num;

                    if(std::to_string(student.num).length() != 10){
                        std::cout << "Invalid number!\n";
                    }
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }while(std::to_string(student.num).length() != 10);
                    std::cin.ignore();

                do {
                    std::cout << "Course:\n";
                    std::getline(std::cin, student.course);

                    if (student.course.empty()) {
                        std::cout << "Course can't be empty\n";
                    }
                } while (student.course.empty());

                do {
                    std::cout << "Year level: \n";
                    std::getline(std::cin, student.year_lvl);

                    if (student.year_lvl.empty()){
                        std::cout << "Year level can't be empty!\n";
                    }
                }while (student.year_lvl.empty());

                std::cin.ignore();

                break;
            }
        }
    }

    void deleteStudentbyName(std::vector<Student>& studentList, const std::string& name) {
        for (auto it = studentList.begin(); it != studentList.end(); ++it) {
            if (it->name == name) {
                it = studentList.erase(it);
                std::cout << "Student " << name << " has been deleted.\n";
                return;
            }
        }
    }
};

int main() {
    Admin admin;
    std::vector<Student> studentList;

    while (true) {
        int option;

        std::cout << "Student Data Management\n";
        std::cout << "Option:\n[1] Register Student\n[2] List of Students\n[3] Admin Option\n[4] Exit\n";
        std::cin >> option;

        switch (option) {
            case 1: {
                std::cin.ignore();
                Student newStudent;
                newStudent.getInfo();
                studentList.push_back(newStudent);
                break;
            }
            case 2: {
                for (const auto& s : studentList) {
                    s.printInfo();
                    std::cout << "--------------\n";
                }
                break;
            }
            case 3: {
                std::cin.ignore();
                if (admin.adminMenu(studentList)) {
                    admin.modifyStudentbyName(studentList," ");
                    admin.deleteStudentbyName(studentList, " ");
                } else {
                    std::cout << "Authentication failed.\n";
                }
                break;
            }
            case 4: {
                std::cout << "Exiting the program.\n";
                return 0;
            }
            default: {
                std::cout << "Invalid Option!\n";
                break;
            }
        }
    }

    return 0;
}

