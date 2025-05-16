# 🏥 Hospital Management System – C++

This is a fully functional **Hospital Management System** built using **Object-Oriented Programming (OOP)** principles in **C++**.

It demonstrates key OOP concepts like:
- Inheritance
- Encapsulation
- Constructor Chaining
- Deep Copy
- Pointers and Dynamic Memory
- Friend Functions
- Static Members

---

## 📌 Features

- 👨‍⚕️ **Patients and Doctors** inherit from a base `Person` class
- 📋 Schedule and reschedule appointments using pointers
- 📊 Track total patients, doctors, and appointments using static members
- 🔐 Proper use of encapsulation with setters/getters
- 🧠 Friend function used to **reschedule** appointments
- 🗂️ Centralized `HospitalSystem` class to manage all data
- 💡 Dynamic memory handled with deep copy and destructors

---

## 📁 File Structure

- `code.cpp`: Complete source code

## 🚀 How to Run

### Using g++ on terminal:
```bash
g++ code.cpp -o hospital
./hospital
