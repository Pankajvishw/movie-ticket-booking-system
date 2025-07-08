# 🎟️ Movie Ticket Booking System (C Project)

[![C](https://img.shields.io/badge/Language-C-blue.svg)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Build](https://img.shields.io/badge/Build-GCC-brightgreen)](https://gcc.gnu.org/)

## 📌 Project Description

This is a **console-based Movie Ticket Booking System** written in **C**, using file handling for persistent storage. It includes functionality for:

- 🎫 Booking and canceling tickets  
- 👥 Admin and User login  
- 🛠️ Movie management (add, edit, delete)  
- 📂 File saving/loading (`.csv`)  
- 🔐 Password validation  
- 📊 Display of available seats, ticket details, etc.

---

## 🚀 Features

✅ Admin Panel  
✅ User Signup/Login  
✅ Movie Listing and Search  
✅ Seat-wise Booking  
✅ Data Persistence with CSV  
✅ Console-based UI (with proper formatting)

---

## 📁 File Structure

| File             | Description                                 |
|------------------|---------------------------------------------|
| `main.c`         | Entry point of the Movie Ticket Booking System |
| `movies.h`       | Common structures and global declarations   |
| `login.c/h`      | Admin and User login/signup functionality   |
| `booking.c/h`    | Booking, viewing, and canceling tickets     |
| `search.c/h`     | Search movies and seat availability         |
| `validate.c/h`   | Input validation for all user/admin input   |
| `file.c/h`       | Save and load data using CSV file handling  |
| `populate.c/h`   | Load dummy data (users and movies)          |
| `editmovie.c/h`  | Functions to edit movie details             |
| `movie.csv`      | Stores movie information (auto-generated)   |
| `user.csv`       | Stores user credentials and bookings        |
| `README.md`      | Project documentation and usage guide       |

---

## ⚙️ How to Compile & Run

```bash
gcc *.c -o movie_booking
./movie_booking
