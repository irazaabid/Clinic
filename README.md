# Clinic & Hospital Management System (C++)

A lightweight, console-based **Clinic & Hospital Management System** built in C++. This application demonstrates Object-Oriented Programming (OOP) principles, file-based data persistence, and in-memory data structures to handle basic operational data for clinics, including patient records, staff management, and pharmacy inventory.

---

## Key Features

* **Patient Management:**
  * Register new patients with details like name, age, sex, CNIC (national ID), medical history, and prescribed medications.
  * Save patient data persistently to local storage (`patient.txt`).
  * Search patient records dynamically using their **CNIC**.

* **Staff Management:**
  * Add staff members with details such as job role, salary, and shift timings.
  * Save staff data to disk (`staff.txt`).

* **Medicine Inventory Management:**
  * Track available medicines along with price, stock units, and expiry dates.
  * In-memory database support using C++ Standard Library vectors (`std::vector`).

---

## Technical Overview

* **Language:** C++ (C++11 or higher)
* **Programming Paradigm:** Object-Oriented Programming (OOP) using classes (`Patient`, `Staff`, `Medicine`)
* **Persistence:** File I/O stream operations (`std::ifstream`, `std::ofstream`) for file logging
* **Data Structures:** `std::vector` for dynamic storage

---

## Project Structure

```text
.
├── main.cpp         # Main C++ source file containing logic & CLI
├── patient.txt      # Text database storing patient records (auto-generated)
└── staff.txt        # Text database storing staff records (auto-generated)
