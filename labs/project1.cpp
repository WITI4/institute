#include<iostream>
#include<string>
#include<fstream>
//#define DEBAG

enum Position {
    LABORANT, SECRETAR, MANAGER, OTHER
};
class Date {
private:
    int day;
    int month;
    int year;
public:
    Date() : day(0), month(0), year(0) {}
    Date(const Date& other) : day(other.day), month(other.month), year(other.year) {}

    void SetDate(int day = 0, int month = 0, int year = 0) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    void Printf() const {
        std::cout << day << "." << month << "." << year;
    }
    std::string ToString() const {
        return std::to_string(day) + "." + std::to_string(month) + "." + std::to_string(year);
    }
    ~Date() {
#ifdef DEBAG
        cout << "���������� Date ������" << endl;
#endif
    }
};
class Employee {
private:
    int id;
    float salary;
    Date hireDate;
    Position empPosition;
public:
    Employee() : id(0), salary(0.0), empPosition(OTHER) {}
    Employee(const Employee& other) : id(other.id), salary(other.salary), hireDate(other.hireDate), empPosition(other.empPosition) {}

    void SetEmployee(int id = 0, float salary = 0.00, const Date& hireDate = Date(), Position empPosition = OTHER) {
        this->id = id;
        this->salary = salary;
        this->hireDate = hireDate;
        this->empPosition = empPosition;
    }

    void Printf() {
        std::cout << "����������������� ����� ����������: " << id << std::endl;
        std::cout << "�������� ������ ����������: " << salary << std::endl;
        std::cout << "���� ������ ���������� �� ������: ";
        hireDate.Printf();
        std::cout << std::endl;
        std::cout << "������ ����������: " << GetempPosition() << std::endl;
    }

    std::string GetempPosition() {
        switch (empPosition) {
        case LABORANT:
            return "laborant";
        case SECRETAR:
            return "secretar";
        case MANAGER:
            return "manager";
        default:
            return "other";
        }
    }

    void WriteToFile(std::ofstream& outFile) {
        outFile << "����������������� ����� ����������: " << id << std::endl;
        outFile << "�������� ������ ����������: " << salary << std::endl;
        outFile << "���� ������ ���������� �� ������: " << hireDate.ToString() << std::endl;
        outFile << "������ ����������: " << GetempPosition() << std::endl;
        outFile << "\n\n" << std::endl;
    }

    ~Employee() {
#ifdef DEBAG
        cout << "���������� Employee ������" << endl;
#endif
    }
};
static int isValidDate(int day, int month, int year) {
    if (year < 1925 || year > 2025) return 0;
    if (month > 12 || month < 1) return 0;
    if (day > 31 || day < 1) return 0;
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) return 0;
    if (month == 2) {
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            if (day > 29) return 0;
        }
        else {
            if (day > 28) return 0;
        }
    }
    return 1;
}