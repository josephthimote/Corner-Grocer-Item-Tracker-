# Corner-Grocer-Item-Tracker- 

Project Summary

This grocery item tracker program (GroceryItemTracker) reads in a grocery item list from an input file, calculates the total occurrence of each item listed in the input file, provides the user with options to interact with the data through a menu. The user may enter the name of an item to see the total number of occurrences of the entered item, or they may choose to view the total occurrences of all the items listed in the input file, or they may even create a histogram displaying the total purchases of each type of item. When the user chooses to exit the program, a backup file will be saved which contains the frequency of each item.


What I did particularly well:

I think there were three specific areas where I excelled in this project: 1) separation of the code for organizational purposes and separating it between the main function and the GroceryTracker class; 2) clarity of the code for others to follow along with what I am doing; 3) validation on user input for preventing crashing due to entering something outside of valid choice parameters.

Areas for Improvement:

If I had to enhance this project in the future, I would implement auto correct or suggestions in item search entries. For instance, if users searched for items as “Brocoli” (instead of the proper spelling) the system can suggest the most likely related item(s) from the database. If there are any issues with file operations during load/write process, I would add additional error checking/logging so the program will be able to give users better information about what was happening when things went awry. Overall, these changes would improve usability of the application while enhancing reliability and troubleshooting.

Most Difficult Part:

The most difficult aspect of this project was figuring out how to break down the program into smaller components so each component had one responsibility but still worked well together. Organizing the program into smaller functions and a separate class made completing this project significantly easier. Not only was organizing the program effectively challenging, but utilizing all available course materials, C++ documentation, debugging tools offered through Visual Studio, testing various inputs to confirm all requested capabilities were operating as expected was also time consuming.
