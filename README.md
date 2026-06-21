# Unit Conversion Tool

A C++ command-line application that converts common measurements between metric and imperial units.

## Features

### Temperature Conversion

* Celsius to Fahrenheit
* Fahrenheit to Celsius

### Distance Conversion

* Miles to Kilometers
* Miles to Meters
* Kilometers to Miles
* Kilometers to Feet

### Volume Conversion

* Liters ↔ Gallons
* Liters ↔ Quarts
* Gallons ↔ Quarts

## Technologies

* C++
* Functions
* Loops
* Input Validation
* Menu-Driven Interfaces

## Skills Demonstrated

* Modular Programming
* Function Design
* User Input Handling
* Mathematical Calculations
* Unit Conversion Logic
* Command Line Applications

## Building and Running

### Prerequisites

* Visual Studio Code
* C/C++ Extension
* GCC/G++ Compiler (MinGW-w64 on Windows)

Verify the compiler is installed:

```bash
g++ --version
```

### Compile

```bash
g++ Prog3.cpp -o unit_conversion_tool
```

### Run

```bash
.\unit_conversion_tool
```

## Example Usage

```text
Unit Conversion Tool

Main Menu:
--------------------
(T) Temperature
(D) Distance
(V) Volume
(X) Exit

Select the type of conversion: T

Temperature conversion:
--------------------
(F) From Celsius to Fahrenheit
(C) From Fahrenheit to Celsius

Select type of conversion: F

Enter the temperature in celsius: 100

100.0000 degrees Celsius is equivalent to 212.0000 degrees Fahrenheit
```
