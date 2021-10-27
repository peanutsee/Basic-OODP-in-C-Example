#include <iostream>

using namespace std;

/*
OOP Concepts
1. Encapsulation: Bundling data with the methods that operate on that data. It is used to hide the values or state of a structured data object in a class preventing unauthorized access.
2. Polymorphism: Same same but different. Same method signature, different inputs, processing and outputs. Object have many forms.
3. Abstraction: Hides the internal workings of the methods, only show what the developers want the users to see. Acts as an interface.
4. Inheritance: Super Class (Base Class) - Sub Class (Derived Class)
*/

// Type Enum
enum TYPE {EM, DV, TC};

// Abstract Employee Class
class AbstractEmployee
{
    // Pure Virtual Function
    virtual void askForPromotion()=0;
};

// Employee Class
class Employee:AbstractEmployee
{
private:
    // Attributes
    string Name;
    string Company;
    int Age;
    TYPE type;

public:

    // Constructor
    Employee() {}

    Employee(string name, string company, int age)
    {
        this->Name = name;
        this->Company = company;
        this->Age = age;
        this->type = EM;
    }

    Employee(string name, string company, int age, TYPE type)
    {
        this->Name = name;
        this->Company = company;
        this->Age = age;
        this->type = type;
    }

    // Mutators
    void setName(string name)
    {
        this->Name = name;
    }

    void setCompany(string company)
    {
        this->Company = company;
    }

    void setAge(int age)
    {
        this->Age = age;
    }

    // Accessors
    string getName()
    {
        return this->Name;
    }

    string getCompany()
    {
        return this->Company;
    }

    int getAge()
    {
        return this->Age;
    }

    // Methods
    void introductYourself()
    {
        cout << "Name - " << Name << endl;
        cout << "Company - " << Company << endl;
        cout << "Age - " << Age << endl;
    }

    void askForPromotion()
    {
        if (this->Age >= 30)
        {
            cout << this->Name << " got promoted!" << endl;
        }
        else
        {
            cout << "Sorry, not promotion for " << this->Name << endl;
        }
    }

    void work()
    {
        if (this->type == DV)
        {
            cout << this->Name << " is checking email, task backlog and performing tasks..." << endl;

        }
        else if (this->type == TC)
        {
            cout << this->Name << " is doing admin work..." << endl;
        }
        else
        {
            cout << this->Name << " is idling..." << endl;
        }
    }


};

// Inheritance -> Derived Class of Employee
class Developer: public Employee
{
private:
    // Attributes
    string favouriteProgrammingLanguage;
public:
    // Constructor
    Developer(string name, string company, int age, string favouriteProgrammingLanguage):
        Employee(name, company, age, DV)
    {
        this->favouriteProgrammingLanguage = favouriteProgrammingLanguage;
    }

    // Mutators
    void setFavouriteProgrammingLanguage(string language)
    {
        this->favouriteProgrammingLanguage = language;
    }

    // Accessors
    string getFavouriteProgrammingLanguage()
    {
        return this->favouriteProgrammingLanguage;
    }

    // Method
    void fixBug()
    {
        cout << getName() << " fixed bug using " << this->favouriteProgrammingLanguage << endl;
    }
};

class Teacher: public Employee
{
public:
    // Attributes
    string subject;

    // Constructor
    Teacher(string name, string company, int age, string subject): Employee(name, company, age, TC)
    {
        this->subject = subject;
    }

    // Mutators
    void setSubject(string subject)
    {
        this->subject = subject;
    }

    // Accessors
    string getSubject()
    {
        return this->subject;
    }

    // Methods
    void prepareLesson()
    {
        cout << getName() << " is preparing for " << subject << " lesson!" << endl;
    }
};

int main()
{
    // Employee
    Employee employee_1 = Employee("Darryl See", "HP", 22);
    employee_1.askForPromotion();
    employee_1.work();
    cout << "" << endl;

    // Developer
    Developer developer_1 = Developer("Peanut Lee", "Amazon", 20, "Python");
    developer_1.fixBug();
    developer_1.askForPromotion();
    developer_1.work();
    cout << "" << endl;

    // Teacher
    Teacher teacher_1 = Teacher("Elizabeth Lee", "Shopee", 22, "Python");
    teacher_1.prepareLesson();
    teacher_1.askForPromotion();
    teacher_1.work();
}
