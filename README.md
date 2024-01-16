# Sports League Management Program

## Overview

The Sports League Management Program is a command-line application that provides a simple interface for interacting with a simulated sports league table. It includes functionalities such as displaying divisions, points, a specific team, and teams in a particular position across all divisions. The program is designed to be easy to use and navigate, with a simple menu system to guide the user through the program, with input validation to ensure the user enters the correct data/selections.

## Files Overview

### `leagueTable.cpp`

This file contains the main program logic. It utilizes the `LeagueManager` class to manage the sports league table. The program is structured around a menu-driven interface, allowing users to make selections and interact with the league data which is stored and declared in this file. The main function sets up a continuous loop, providing users with options until they choose to exit the program.

### `leagueTable.h`

The header file defines the structure `team` and the class `LeagueManager`. The `team` structure represents a sports team with attributes such as division, name, wins, draws, losses, and position. The `LeagueManager` class encapsulates static functions for various operations on the sports league table. It includes functions for displaying divisions, points, specific teams, and teams in a particular position across all divisions. Constants for menu choices are also declared in this file.

### `utilities.cpp` and `utilities.h`

These utility files provide helper functions used by the main program. The `utilities` namespace includes functions for clearing the terminal, pausing code execution until the user presses Enter, introducing delays, adding separators between lines, and exiting the program with an animation. These utilities contribute to a more user-friendly and visually appealing interface.

## Usage
Upon running the program, a menu will be displayed, presenting the user with different options:

```
1. Display Entire League: View all teams in the league table by division in alphabetical order.

2. Display a Division: View teams in a single division ordered by points in descending order.

3. Find Specific Team: View details of a single team based on division and position.

4. Find Teams in a Position: View teams at a specified overall position across all divisions.

0: Exit: Ends the program after displaying an animation.
```
Simply enter the corresponding number for the action you want to perform.


## How to Run in Visual Studio

1. **Open Visual Studio:**
   - Launch Visual Studio on your machine.

2. **Open the Project:**
   - In the menu, go to `File` > `Open` > `Project/Solution...`.
   - Navigate to the directory where you have the Sports League Management Program files.
   - Select the file `leagueTable.cpp` and click `Open`.

3. **Configure the Project:**
   - Once the project is open, ensure that the project configuration is set up correctly. You may need to configure the project settings based on your system.
   - Check that the necessary compiler and linker settings are in place.

4. **Build the Project:**
   - Build the project by selecting `Build` > `Build Solution` from the menu.
   - Ensure that the build process is completed without errors.

5. **Run the Program:**
   - After a successful build, you can run the program by selecting `Debug` > `Start Without Debugging` or by pressing `Ctrl + F5`.

6. **Interact with the Program:**
   - The program will run in the console window. Follow the on-screen instructions to interact with the sports league table.

7. **Close the Program:**
   - To exit the program, select the console window and press `Enter`. Alternatively, close the console window.


## Contributors

Joshua Thomas (`GameBoyCymru`).
