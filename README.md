# PMS (Password Management System) 🔐

A lightweight CLI-based password manager written in C++.

---

## Directories

src ---> Source code  
data ---> stores passwords and other files  
notes ---> Digital Notes related to this program  

---

## Version

Version 1.0  
>uses file handling to store data in local file  
>asks the username for username and password  
>uses master password to change file from source code  

---

## 📌 Features

- Create multiple user profiles.
- Store credentials (username, password, description) under profiles.
- Protect each profile with a master password.
- View and authenticate stored profiles.
- All data stored in plain `.txt` files (encryption planned in v1.3).

---

## 🚀 How to Run

```bash
cd src
g++ main.cpp -o pms
./pms
