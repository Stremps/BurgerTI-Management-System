# BurgerTI Order System

## Description
This repository contains the code for managing a drive-through fast food restaurant system called BurgerTI. The system was developed as part of an Algorithms and Data Structures assignment at UNIOESTE University, Foz do Iguaçu campus.

## Features
The system allows for the management of:
- Sandwiches, beverages, extra sides, and desserts, including registration and listing of available items.
- Customer orders, allowing for the registration of new orders, printing existing orders, and managing the queue of unattended orders.

### Technical Characteristics
- **Implementation:** The code is written in C.
- **Data Storage:** Uses linked lists for data management in memory and binary files for data persistence.

## Known Limitations
- **Binary Files:** There are known issues with binary file manipulation that will be corrected in future updates.
- **Optimization and Documentation:** Due to initial inexperience in programming, the code may not be optimized and the internal documentation is limited.

## How to Use
### Compilation and Execution
To compile and execute the program in a Linux environment:
```bash
gcc -o burgerTI *.c
./burgerTI
