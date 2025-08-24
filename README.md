# 🏦 Bank Management System (CLI)

A simple **Command Line Interface (CLI)** project written in **C** that simulates a basic banking system.  
It allows users to **create accounts, deposit, withdraw, and check balances**.  

This project is designed as a **beginner-friendly system programming exercise**, commonly used in university courses and coding bootcamps.  

---

## ✨ Features
- 📌 Create a new bank account  
- 💰 Deposit money into an account  
- 💸 Withdraw money (with balance check)  
- 🔍 Check balance & account details  
- 💾 Data persistence using file storage (`accounts.txt`)  

---

## 🛠️ Tech Stack
- **Language**: C  
- **Paradigm**: Procedural Programming  
- **Storage**: File Handling (`fopen`, `fwrite`, `fread`)  
- **Platform**: Linux / Windows  

---

## 📂 Project Structure
```
.
├── bank.c          # Main source code
├── accounts.txt    # File storing accounts (auto-created at runtime)
└── README.md       # Project documentation
```

---

## ▶️ How to Run

### 1. Clone the repository
```bash
git clone git@github.com:ansettaf/Bank-Management-System-CLI-.git
cd Bank-Management-System-CLI-
```

### 2. Compile the program
```bash
gcc bank.c -o bank
```

### 3. Run the program
```bash
./bank
```

---

## 📖 Usage Example
```
===== 🏦 Bank Management CLI =====
1. Create account
2. Deposit
3. Withdraw
4. Check balance
5. Exit
Choose an option: 1

Enter account number: 1001
Enter name: John
Enter initial balance: 500
✅ Account created successfully!
```

---

## 🚀 Future Improvements
- Switch to **C++ (OOP)** with classes  
- Add **password authentication** for accounts  
- Implement **transaction history**  
- Use **SQLite/MySQL database** instead of flat file storage  
- Create a **GUI version** (Qt / GTK)  

---

## 📌 About
This project was built as part of **system programming practice**.  
It demonstrates **file handling, structured programming, and simple CLI design**.  

💼 Employers: This project highlights skills in **low-level programming, memory management, and persistence**.  
