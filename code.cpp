#include <iostream>
#include <string>
using namespace std;
// Base Class

class Person
{

private:
    string *name;
    int age;
    static int totalPersons;

public:
    // Default constructor
    Person()
    {
        name = new string("Unknown");
        age = 0;
        totalPersons++;
    }
    // Parameterized Constructor
    Person(const string &n, int a)
    {
        name = new string(n);
        age = a;
        totalPersons++;
    }
    // Copy Constructor
    Person(const Person &other)
    {
        name = new string(*(other.name));
        age = other.age;
        totalPersons++;
    }
    // Destructor
    ~Person()
    {
        cout << "Destructor called for: " << *name << endl;
        delete name;
    }
    // Display fun
    void displayInfo() const
    {
        cout << "Name: " << *name << endl;
        cout << "Age: " << age << endl;
    }
    // Setters
    void setName(string n)
    {
        delete name;
        name = new string(n);
    }
    void setAge(int a)
    {
        age = a;
    }
    // Getters
    string getName() const
    {
        return *name;
    }
    int getAge() const
    {
        return age;
    }
    // Utility Function
    static int getTotalPersons()
    {
        return totalPersons;
    }
};
int Person::totalPersons = 0;
class Patients : public Person
{
private:
    int patientId;
    string *disease;
    static int totalPatients;

public:
    Patients() : Person()
    {
        patientId = 0;
        disease = new string("unknown");
        totalPatients++;
    }
    Patients(const string &d, int i, const string &name, int age) : Person(name, age)
    {
        disease = new string(d);
        patientId = i;
        totalPatients++;
    }
    Patients(const Patients &other) : Person(other)
    {
        disease = new string(*(other.disease));
        patientId = other.patientId;
    }
    ~Patients()
    {
        cout << "Destructor called for: " << *disease << endl;
        delete disease;
    }
    // Setters
    void setDisease(string d)
    {
        delete disease;
        disease = new string(d);
    }
    void setId(int i)
    {
        patientId = i;
    }
    // Getters
    string getDisease() const
    {
        return *disease;
    }
    int getID() const
    {
        return patientId;
    }
    void display() const
    {
        Person::displayInfo();
        cout << "Patient Disease: " << *disease << endl;
        cout << "Patient id: " << patientId << endl;
    }
    static int getTotalPatients()
    {
        return totalPatients;
    }
};
int Patients::totalPatients = 0;
class Doctor : public Person
{
private:
    int doctorID;
    string *specialization;
    bool isAvailable;
    static int totalDoctor;

public:
    Doctor() : Person()
    {
        doctorID = 0;
        specialization = new string("unknown");
        isAvailable = false;
        totalDoctor++;
    }
    Doctor(int _doctorId, const string &spec, bool flag, const string &name, int age) : Person(name, age)
    {
        doctorID = _doctorId;
        specialization = new string(spec);
        isAvailable = flag;
        totalDoctor++;
    }
    Doctor(const Doctor &other) : Person(other)
    {
        doctorID = other.doctorID;
        specialization = new string(*(other.specialization));
        isAvailable = other.isAvailable;
    }
    // Setters
    void setId(int iD)
    {
        doctorID = iD;
    }
    void setSpec(string spec)
    {
        delete specialization;
        specialization = new string(spec);
    }
    void setAvailable(bool flag)
    {
        isAvailable = flag;
    }
    // Getters
    int getId() const
    {
        return doctorID;
    }
    string getSpecialization() const
    {
        return *specialization;
    }
    bool getAvailable() const
    {
        return isAvailable;
    }
    static int getTotalDoctor()
    {
        return totalDoctor;
    }
    void displayInf() const
    {
        Person::displayInfo();
        cout << "Doctor ID: " << doctorID << endl;
        cout << "Specialization: " << *specialization << endl;
        cout << "Availability: " << (isAvailable ? "Yes" : "No") << endl;
    }
    ~Doctor()
    {
        cout << "Destructor called for Doctor: " << *specialization << endl;
        delete specialization;
    }
};
int Doctor::totalDoctor = 0;
class Appointment
{
private:
    int appointmentId;
    string *date;
    Patients *patient;
    Doctor *doctor;
    static int totalAppointments;

public:
    Appointment()
    {
        appointmentId = 0;
        date = new string("Unknown");
        patient = nullptr;
        doctor = nullptr;
        totalAppointments++;
    }
    Appointment(int id, const string &da, Patients *p, Doctor *d)
    {
        appointmentId = id;
        date = new string(da);
        patient = p;
        doctor = d;
        totalAppointments++;
    }
    ~Appointment()
    {
        cout << "Destructor called for: " << *date << endl;
        delete date;
        date = nullptr;
    }
    Appointment(const Appointment &other)
    {
        appointmentId = other.appointmentId;
        date = new string(*(other.date));
        patient = other.patient;
        doctor = other.doctor;
    }
    void displayInformation() const
    {
        cout << "Appointment Id: " << appointmentId << endl;
        cout << "Date: " << *date << endl;
        if (patient != nullptr)
        {
            cout << "Patient name: " << patient->getName() << endl;
            cout << "Patient ID: " << patient->getID() << endl;
            cout << "Patient disease: " << patient->getDisease() << endl;
        }
        else
        {
            cout << "No patient assigned.\n";
        }
    }
    static int getTotalAppointments()
    {
        return totalAppointments;
    }
    friend void rescheduleAppointment(Appointment &appt, const string &newdate);
};
int Appointment::totalAppointments = 0;
void rescheduleAppointment(Appointment &appt, const string &newdate)
{
    delete appt.date;
    appt.date = new string(newdate);
    cout << "Appointment reschedule to: " << *appt.date << endl;
}
class HospitalSystem
{
private:
    Patients *patients[100];
    Doctor *doctors[100];
    Appointment *appointments[100];

    int patientCount;
    int doctorCount;
    int appointmentCount;

public:
    HospitalSystem()
    {
        patientCount = 0;
        doctorCount = 0;
        appointmentCount = 0;
    }
    void addPatient(Patients *p)
    {
        if (patientCount < 100)
        {
            patients[patientCount++] = p;
        }
    }
    void addDoctor(Doctor *d)
    {
        if (doctorCount < 100)
        {
            doctors[doctorCount++] = d;
        }
    }
    void addAppointments(Appointment *a)
    {
        if (appointmentCount < 100)
        {
            appointments[appointmentCount++] = a;
        }
    }
    void showAllPatients()
    {
        for (int i = 0; i < patientCount; i++)
        {
            patients[i]->display();
        }
    }
    void showAllDoctors()
    {
        for (int i = 0; i < doctorCount; i++)
        {
            doctors[i]->displayInf();
        }
    }
    void showAllAppointments()
    {
        for (int i = 0; i < appointmentCount; i++)
        {
            appointments[i]->displayInformation();
        }
    }
};
int main()
{
    HospitalSystem hospital;
    // Create patients
    Patients *p1 = new Patients("Flue", 101, "Ali", 25);
    Patients *p2 = new Patients("Fever", 102, "Ahmed", 30);
    hospital.addPatient(p1);
    hospital.addPatient(p2);
    // Create doctors
    Doctor *d1 = new Doctor(201, "Cardiology", true, "Dr.Ahsan", 50);
    Doctor *d2 = new Doctor(202, "Dermatology", true, "Dr.Saba", 40);
    hospital.addDoctor(d1);
    hospital.addDoctor(d2);
    // Create Appointments
    Appointment *a1 = new Appointment(301, "2025-05-20", p1, d1);
    Appointment *a2 = new Appointment(302, "2025-06-01", p2, d2);
    hospital.addAppointments(a1);
    hospital.addAppointments(a2);

    cout << "\n--- All Patients ---\n";
    hospital.showAllPatients();

    cout << "\n--- All Doctors ---\n";
    hospital.showAllDoctors();

    cout << "\n--- All Appointments ---\n";
    hospital.showAllAppointments();
    // Rescheduling appointments
    cout << "\n----Rescheduling appointment 301---\n";
    rescheduleAppointment(*a1, "25-06-12");
    delete p1;
    delete p2;
    delete d1;
    delete d2;
    delete a1;
    delete a2;

    return 0;
}