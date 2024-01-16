#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <thread>
#include <iterator>

struct team
{
    unsigned short int division;
    std::string name;
    unsigned short int wins;
    unsigned short int draws;
    unsigned short int losses;
    unsigned short int position = 0;
};

class LeagueManager
{
public:
    enum MenuOption
    {
        DISPLAY_DIVISIONS = 1,
        DISPLAY_POINTS,
        DISPLAY_TEAM,
        DISPLAY_POS_DIVISION,
        EXIT_PROGRAM = 0
    };

    enum InputType
    {
        MENU,
        ENTER_DIVISION,
        ENTER_POSITION
    };

    // Vector to store the league table
    static std::vector<team> leagueTable;

    // Destructor to clear the league table vector
    ~LeagueManager()
    {
        leagueTable.clear();
    }

    // Function to display the league table
    static void displayDivisions();

    // Function to display teams in a given division in order of points
    static void displayPoints();

    // Function to display the team at a given position in a given division
    static void displayTeam();

    // Function to display the teams in the same position across divisions
    static void displayPosDivision();

    // Function to display the menu and return the user's choice
    static void displayMenu(const InputType &type);

    // Function to validate the user's choice
    static unsigned short int intValidChoice(unsigned short int minRange, unsigned short int maxRange, const InputType &type);


    // Function to sort the league table by points
    static bool compareTeamsByPoints(const team &lhs, const team &rhs);
    
    // Function to sort the league table by division
    static std::vector<team> filterTeamsByDivision(unsigned short int division);

    // Function to filter the league table by division and sort by points
    static std::vector<team> filterAndSortByPoints(unsigned short int division);

};

