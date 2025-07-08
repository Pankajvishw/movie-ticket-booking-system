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

.
├── movies.h            # All common structures and function declarations
├── login.c/h           # Login, signup, and admin panel
├── booking.c/h         # Booking, viewing, and canceling tickets
├── search.c/h          # Search movies and seats
├── validate.c/h        # Input validation
├── file.c/h            # Save/load data from CSV files
├── populate.c/h        # Initial dummy data
├── editmovie.c/h       # Movie edit operations
├── main.c              # Entry point (can be created if needed)

---

## ⚙️ How to Compile & Run

```bash
gcc *.c -o movie_booking
./movie_booking
