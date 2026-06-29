/*
 * GroceryTracker.cpp
 * Date: June 20th, 2026
 * Author: Joseph Thimote
 * Description: Implements the GroceryTracker class for reading grocery data, counting item frequencies, and displaying reports.
 */

#include "GroceryTracker.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <limits>

GroceryTracker::GroceryTracker(const std::string& inputFileName, const std::string& backupFileName)
    : inputFileName(inputFileName), backupFileName(backupFileName) {
}

bool GroceryTracker::initialize() {
    // Load the grocery purchases before creating the backup summary file.
    if (!loadFrequencies()) {
        return false;
    }

    return writeBackupFile();
}

int GroceryTracker::getFrequencyForItem(const std::string& itemName) const {
    const std::string normalizedItem = normalizeItemName(itemName);
    const std::map<std::string, int>::const_iterator result = itemFrequencies.find(normalizedItem);

    if (result == itemFrequencies.end()) {
        return 0;
    }

    return result->second;
}

void GroceryTracker::printAllFrequencies() const {
    for (std::map<std::string, int>::const_iterator entry = itemFrequencies.begin(); entry != itemFrequencies.end(); ++entry) {
        std::cout << entry->first << ' ' << entry->second << std::endl;
    }
}

void GroceryTracker::printHistogram() const {
    for (std::map<std::string, int>::const_iterator entry = itemFrequencies.begin(); entry != itemFrequencies.end(); ++entry) {
        std::cout << entry->first << ' ' << std::string(entry->second, '*') << std::endl;
    }
}

void GroceryTracker::runMenu() {
    int menuChoice = 0;

    // Keep showing the menu until the user selects the exit option.
    while (menuChoice != 4) {
        std::cout << "\nCorner Grocer Menu\n";
        std::cout << "1. Search for an item frequency\n";
        std::cout << "2. Print all item frequencies\n";
        std::cout << "3. Print histogram\n";
        std::cout << "4. Exit\n";
        std::cout << "Choose an option: ";

        menuChoice = readMenuChoice();

        switch (menuChoice) {
        case 1:
            handleItemSearch();
            break;
        case 2:
            printAllFrequencies();
            break;
        case 3:
            printHistogram();
            break;
        case 4:
            break;
        default:
            std::cout << "Please enter a number from 1 to 4." << std::endl;
            break;
        }
    }
}

bool GroceryTracker::loadFrequencies() {
    std::ifstream inputFile(inputFileName.c_str());
    std::string currentItem;

    if (!inputFile.is_open()) {
        std::cerr << "Unable to open input file: " << inputFileName << std::endl;
        return false;
    }

    itemFrequencies.clear();

    // Count how many times each grocery item appears in the input file.
    while (inputFile >> currentItem) {
        ++itemFrequencies[normalizeItemName(currentItem)];
    }

    return true;
}

bool GroceryTracker::writeBackupFile() const {
    std::ofstream outputFile(backupFileName.c_str());

    if (!outputFile.is_open()) {
        std::cerr << "Unable to create backup file: " << backupFileName << std::endl;
        return false;
    }

    for (std::map<std::string, int>::const_iterator entry = itemFrequencies.begin(); entry != itemFrequencies.end(); ++entry) {
        outputFile << entry->first << ' ' << entry->second << '\n';
    }

    return true;
}

std::string GroceryTracker::normalizeItemName(const std::string& itemName) {
    std::string normalizedName = itemName;

    if (!normalizedName.empty()) {
        // Normalize case so item lookups stay consistent.
        std::transform(normalizedName.begin(), normalizedName.end(), normalizedName.begin(),
            [](unsigned char character) {
                return static_cast<char>(std::tolower(character));
            });

        normalizedName[0] = static_cast<char>(std::toupper(static_cast<unsigned char>(normalizedName[0])));
    }

    return normalizedName;
}

int GroceryTracker::readMenuChoice() const {
    int menuChoice = 0;

    // Re-prompt until the user enters a numeric menu option.
    while (!(std::cin >> menuChoice)) {
        std::cout << "Invalid input. Enter a number from 1 to 4: ";
        std::cin.clear();
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }

    std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    return menuChoice;
}

void GroceryTracker::handleItemSearch() const {
    std::string itemName;

    std::cout << "Enter the item to search for: ";
    std::getline(std::cin, itemName);

    std::cout << normalizeItemName(itemName) << " was purchased "
              << getFrequencyForItem(itemName) << " time(s)." << std::endl;
}
