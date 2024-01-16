#include "leagueTable.h"
#include "utilities.h"

// Vector to store the league table
std::vector<team> LeagueManager::leagueTable = {
    {1, "Liverpool", 4, 2, 0},
    {1, "Manchester City", 3, 1, 2},
    {1, "Leicester City", 3, 2, 1},
    {1, "Cardiff", 1, 5, 1},
    {1, "Arsenal", 2, 3, 1},
    {1, "Chelsea", 1, 2, 4},
    {1, "Manchester United", 3, 1, 3},
    {1, "Tottenham Hotspur", 2, 2, 1},
    {2, "Swansea City", 2, 2, 0},
    {2, "Everton", 2, 2, 1},
    {2, "Aston Villa", 2, 1, 2},
    {2, "Newcastle United", 4, 2, 2},
    {2, "Leeds United", 1, 3, 1},
    {2, "West Ham United", 2, 1, 3},
    {2, "Southampton", 3, 2, 2},
    {2, "Crystal Palace", 1, 2, 2},
    {3, "Norwich City", 4, 1, 2},
    {3, "Fulham", 2, 3, 4},
    {3, "Wolverhampton Wanderers", 2, 2, 2},
    {3, "Sheffield United", 2, 0, 2},
    {3, "Burnley", 1, 4, 0},
    {3, "Brighton & Hove Albion", 2, 2, 1},
    {3, "West Bromwich Albion", 3, 1, 2},
    {3, "Leicester City", 2, 1, 3},
    {4, "Sunderland", 1, 3, 2},
    {4, "Hull City", 0, 3, 5},
    {4, "Stoke City", 3, 1, 2},
    {4, "Birmingham City", 1, 2, 4},
    {4, "Watford", 2, 3, 1},
    {4, "Blackburn Rovers", 1, 2, 3},
    {4, "Middlesbrough", 2, 1, 2},
    {4, "Portsmouth", 3, 2, 2}};


// Main function
int main()
{
    while (true)
    {
        // Display the menu and get the user's choice
        unsigned short int choice = LeagueManager::intValidChoice(0, 4, LeagueManager::MENU);

        // Perform the corresponding action based on the user's choice
        switch (choice)
        {
        case LeagueManager::DISPLAY_DIVISIONS:
            LeagueManager::displayDivisions();
            break;
        case LeagueManager::DISPLAY_POINTS:
            LeagueManager::displayPoints();
            break;
        case LeagueManager::DISPLAY_TEAM:
            LeagueManager::displayTeam();
            break;
        case LeagueManager::DISPLAY_POS_DIVISION:
            LeagueManager::displayPosDivision();
            break;
        case LeagueManager::EXIT_PROGRAM:
            utilities::exitProgram();
        }
    }

    return 0;
}

// Function to display a menu based on the parameter
void LeagueManager::displayMenu(const InputType &type)
{
    utilities::clear();

    switch (type)
    {
    case MENU:
        utilities::addSeparator(46, '=');
        std::cout << std::setw(23) << "Menu" << std::endl;
        utilities::addSeparator(46, '=');
        std::cout << "1. Display entire league" << std::endl;
        std::cout << "2. Display a division" << std::endl;
        std::cout << "3. Find specific team" << std::endl;
        std::cout << "4. Find teams in a position" << std::endl;
        std::cout << "0. Exit" << std::endl;
        utilities::addSeparator(46, '-');
        std::cout << "\nChoice: ";
        break;

    case ENTER_DIVISION:
        std::cout << "Enter division number (1-4): ";
        break;

    case ENTER_POSITION:
        std::cout << "Enter position (1-8): ";
        break;
    }
}

// Function to validate the user's choice
unsigned short int LeagueManager::intValidChoice(unsigned short int minRange, unsigned short int maxRange, const InputType &type)
{
    unsigned short int choice;
    bool failed = true;

    while (failed)
    {
        utilities::clear();
        failed = false;

        if (type == ENTER_DIVISION)
        {
            displayMenu(ENTER_DIVISION);
        }
        else if (type == ENTER_POSITION)
        {
            displayMenu(ENTER_POSITION);
        }
        else if (type == MENU)
        {
            displayMenu(MENU);
        }

        std::cin >> choice;

        // Validate the user's choice to ensure it is an integer between the specified range
        if (choice < minRange || choice > maxRange || std::cin.fail() || std::cin.peek() != '\n')
        {
            failed = true;
            std::cout << "\nInvalid choice, please try again!\n";
            utilities::sleep(1200);
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        if (failed == false)
        {
            break;
        }
    }

    return choice;
}

// Comparison function for sorting teams based on points
bool LeagueManager::compareTeamsByPoints(const team &lhs, const team &rhs)
{
    // Sort in ascending order of points
    return (lhs.wins * 3 + lhs.draws) > (rhs.wins * 3 + rhs.draws);
}

// Function to filter teams for the specified division
std::vector<team> LeagueManager::filterTeamsByDivision(unsigned short int division)
{

    // Vector to store teams in the specified division
    std::vector<team> divisionTeams;

    // Copy teams from leagueTable to divisionTeams if the team's division matches the specified division
    copy_if(LeagueManager::leagueTable.begin(), LeagueManager::leagueTable.end(), back_inserter(divisionTeams), [division](const team &t)
            { return t.division == division; });

    return divisionTeams;
}

// Function to filter teams for the specified division, sort by points, and assign positions
std::vector<team> LeagueManager::filterAndSortByPoints(unsigned short int division)
{
    // Vector to store teams in the specified division
    std::vector<team> divisionTeams;

    // Copy teams from leagueTable to divisionTeams if the team's division matches the specified division
    copy_if(LeagueManager::leagueTable.begin(), LeagueManager::leagueTable.end(), back_inserter(divisionTeams), [division](const team &t)
            { return t.division == division; });

    // Sort teams in descending order based on points
    sort(divisionTeams.begin(), divisionTeams.end(), LeagueManager::compareTeamsByPoints);

    // Assign positions based on points
    unsigned short int position = 1;
    for (auto &team : divisionTeams)
    {
        team.position = position++;
    }

    return divisionTeams;
}

// Display all the teams in the league table by division in alphabetical order
void LeagueManager::displayDivisions()
{
    utilities::clear();

    // Sort the vector by division and then by name
    sort(LeagueManager::leagueTable.begin(), LeagueManager::leagueTable.end(), [](const team &lhs, const team &rhs)
         { return lhs.division < rhs.division || (lhs.division == rhs.division && lhs.name < rhs.name); });

    // Create a vector to store the index of the last displayed team for each division
    std::vector<unsigned short int> lastDisplayedIndex(4, 0);

    printf("| %-30s | %-30s | %-30s | %-30s |\n", "Division 1", "Division 2", "Division 3", "Division 4");
    utilities::addSeparator(133, '=');

    // Iterate through teams
    for (unsigned short int i = 0; i < 8; ++i)
    {
        // Iterate through divisions
        for (unsigned short int j = 1; j <= 4; ++j)
        {
            // Find the team in the current division and print its name
            auto it = find_if(LeagueManager::leagueTable.begin() + lastDisplayedIndex[j - 1], LeagueManager::leagueTable.end(), [j, i](const team &t)
                              { return t.division == j; });

            // If the team exists, print its name and store its index
            if (it != LeagueManager::leagueTable.end())
            {
                printf("| %-30s ", it->name.c_str());
                lastDisplayedIndex[j - 1] = distance(LeagueManager::leagueTable.begin(), it) + 1; // Store the index of the last displayed team
            }
            else
            {
                printf("%-25s", "");
            }
        }
        printf("|\n");
    }
    utilities::addSeparator(133, '-'); // Add separator after each row
    utilities::continuePrompt();
}

// Display all the teams in the league table in a specific division in order of points
void LeagueManager::displayPoints()
{
    utilities::clear();

    // Validate the user's choice to ensure it is an integer between 1 and 4
    unsigned short int division = LeagueManager::intValidChoice(1, 4, ENTER_DIVISION);

    std::cout << std::endl;

    // Filter teams for the specified division
    std::vector<team> divisionTeams = LeagueManager::filterTeamsByDivision(division);

    // Sort teams in ascending order based on points
    sort(divisionTeams.begin(), divisionTeams.end(), LeagueManager::compareTeamsByPoints);

    // Display the sorted teams with corresponding points and position
    printf("| %-30s | %-12s | %-12s |\n", "Team:", "Points:", "Position:");
    utilities::addSeparator(64, '=');
    for (size_t i = 0; i < divisionTeams.size(); ++i)
    {
        printf("| %-30s | %-12d | %-12d |\n", divisionTeams[i].name.c_str(), divisionTeams[i].wins * 3 + divisionTeams[i].draws, i + 1);
    }
    utilities::addSeparator(64, '-');
    utilities::continuePrompt();
}

// Display a team based on division number and position
void LeagueManager::displayTeam()
{
    utilities::clear();

    // Validate the user's choice to ensure it is an integer between 1 and 4 and display the prompt message
    unsigned short int division = LeagueManager::intValidChoice(1, 4, ENTER_DIVISION);
    std::cout << std::endl;

    // Validate the user's choice to ensure it is an integer between 1 and 8 and display the prompt message
    unsigned short int searchPosition = LeagueManager::intValidChoice(1, 8, ENTER_POSITION);
    std::cout << std::endl;

    std::vector<team> divisionTeams = LeagueManager::filterTeamsByDivision(division);

    // Create a separate std::vector to represent the sorted order based on points
    std::vector<team> sortedTeams = divisionTeams;
    sort(sortedTeams.begin(), sortedTeams.end(), LeagueManager::compareTeamsByPoints);

    // Display the searched team
    std::cout << "Searched Team: " << sortedTeams[searchPosition - 1].name.c_str() << "\n\n";
    printf("| %-30s | %-12s | %-12s | %-12s |\n", "Team Name:", "Points:", "Position:", "Division:");
    utilities::addSeparator(79, '=');
    printf("| %-30s | %-12d | %-12d | %-12d |\n", sortedTeams[searchPosition - 1].name.c_str(), sortedTeams[searchPosition - 1].wins * 3 + sortedTeams[searchPosition - 1].draws, searchPosition, division);
    utilities::addSeparator(79, '-');
    utilities::continuePrompt();
}

// Display team position across all divisions
void LeagueManager::displayPosDivision()
{
    utilities::clear();

    // Validate the user's choice to ensure it is an integer between 1 and 8 and display the prompt message
    unsigned short int searchPosition = LeagueManager::intValidChoice(1, 8, ENTER_POSITION);
    std::cout << std::endl;

    // Display the teams at the specified overall position in alphabetical order
    printf("| %-30s | %-12s | %-12s |\n", "Team:", "Points:", "Division:");
    utilities::addSeparator(64, '=');

    unsigned short int count = 0;               // To keep track of the number of teams displayed

    // Iterate through each division
    for (int currentDivision = 1; currentDivision <= 4; ++currentDivision)
    {
        // Filter and sort teams for the current division
        std::vector<team> divisionTeams = LeagueManager::filterAndSortByPoints(currentDivision);

        // Find the team at the specified overall position for the current division
        auto it = find_if(divisionTeams.begin(), divisionTeams.end(), [searchPosition](const team &t)
                          { return t.position == searchPosition; });

        // If a team is found, display its information
        if (it != divisionTeams.end())
        {
            printf("| %-30s | %-12d | %-12d |\n", it->name.c_str(), it->wins * 3 + it->draws, it->division);
            count++;
        }
    }
    utilities::addSeparator(64, '-');
    // If no teams found at the specified position, inform the user
    if (count == 0)
    {
        std::cout << "No teams found at the specified overall position.\n";
    }

    utilities::continuePrompt();
}