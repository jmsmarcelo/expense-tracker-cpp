# Expense Tracker CLI

A simple expense tracker application to manage your finances.
This project is [my solution](https://roadmap.sh/projects/expense-tracker/solutions?u=66f7e663c45e253cb00d6b67) to the [Roadmap Expense Tracker Challenge](https://roadmap.sh/projects/expense-tracker).

It allows you to add, list, update, delete, and summarize expenses directly from the terminal.

## ⚙️ Technologies and Tools used

- **Language:** C++
- **Structure:** CLI
- **Terminal:** Bash (Linux) | CMD (Windows)

## 🛠️ How to Run the Project

### Prerequisites

- For compile:
  - Linux: GCC (GNU Compiler Collection)
  - Windows: MSVC (Visual Studio Developer Command Prompt)
- To run:
  - Bash (Linux) | CMD (Windows)

### Steps to Execute

1. Clone the repository:
   ```bash
   git clone https://github.com/jmsmarcelo/expense-tracker-cpp.git
   cd expense-tracker-cpp
   ```

2. Compile the project:
   ```bash
   mkdir build
   cd build

   # Linux:
   g++ -o expense-tracker ../src/*.cpp

   # Windows (MSVC):
   cl /EHsc /Fe:expense-tracker ..\src\*.cpp
   ```

3. Run the application:
   ```Bash
   # Linux:
   ./expense-tracker <command> --<option> <value>

   # Windows:
   .\expense-tracker <command> --<option> <value>
   ```

## 📌 Usage

- **Add an expense with a description and amount:**

  ```bash
  ./expense-tracker add --description <description> --amount <amount>

  # Example:

  ./expense-tracker add --description "Lunch" --amount 20
  # Expense added successfully (ID: 1)

  ./expense-tracker add --amount 10 --description "Dinner"
  # Expense added successfully (ID: 2)
  ```

- **View all expenses:**

  ```bash
  ./expense-tracker list
  # ID     Date    Description Amount
  #  1  2024-08-06    Lunch    $20.00
  #  2  2024-08-06    Dinner   $10.00
  ```

- **View a summary of all expenses:**
  ```bash
  ./expense-tracker summary
  # Total expenses: $30.00

  # For a specific month (of current year):
  ./expense-tracker summary --month <month>

  # Example:

  ./expense-tracker summary --month 8
  # Total expenses for August: $30.00
  ```

- **Update an expense:**

  ```bash
  ./expense-tracker update --id <id> --description <description>
  # or
  ./expense-tracker update --id <id> --amount <amount>
  # or
  ./expense-tracker update --id <id> --description <description> --amount <amount>

  # Example:

  ./expense-tracker update --id 1 --amount 30
  # Expense updated successfully
  ```

- **Delete an expense:**

  ```bash
  ./expense-tracker delete --id <id>
  # Expense deleted successfully
  ```

## 📖 How to Contribute

Contributions are welcome!

### To contribute

  1. Fork the repository.
  2. Create a new branch:
     ```bash
     git checkout -b my-new-feature
     ```
  3. Commit your changes:
     ```bash
     git commit -m "add new feature"
     ```
  4. Push to the branch:
     ```bash
     git push origin my-new-feature
     ```
  5. Open a Pull Request.

## 🎬 Project Demo

*Watch the full development process of this project on YouTube:*

[![Expense Tracker CLI Demo](https://img.youtube.com/vi/WEZZXSLoc_g/0.jpg)](https://youtu.be/WEZZXSLoc_g)

## 🖼️ Screenshots

![Screenshot from 2025-06-21 11-27-24](https://github.com/user-attachments/assets/a11a9b4e-e146-49e5-a9b1-f56f460b9988)

## 📜 License

this project is licensed under the **MIT License**.
See the [LICENSE](https://github.com/jmsmarcelo/expense-tracker-cpp/blob/main/LICENSE) file for details.

## 🙋‍♂️ Author

Created by [**Jose Marcelo**](https://jmsmarcelo.github.io).
Feel free to get in touch or explore more of [**my projects**](https://github.com/jmsmarcelo?tab=repositories)!
