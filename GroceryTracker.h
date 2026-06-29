/*
 * GroceryTracker.h
 * Date: June 20th, 2026
 * Author: Joseph Thimote
 * Description: Declares the GroceryTracker class used to count purchased items and display grocery reports.
 */

#ifndef GROCERY_TRACKER_H
#define GROCERY_TRACKER_H

#include <map>
#include <string>

class GroceryTracker {
public:
    GroceryTracker(const std::string& inputFileName, const std::string& backupFileName);

    // Prepare the frequency data and create the backup file.
    bool initialize();
    int getFrequencyForItem(const std::string& itemName) const;
    void printAllFrequencies() const;
    void printHistogram() const;
    void runMenu();

private:
    std::map<std::string, int> itemFrequencies;
    std::string inputFileName;
    std::string backupFileName;

    bool loadFrequencies();
    bool writeBackupFile() const;
    static std::string normalizeItemName(const std::string& itemName);
    int readMenuChoice() const;
    void handleItemSearch() const;
};

#endif
