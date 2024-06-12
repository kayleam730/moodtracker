#include <iostream>
#include <string>
#include <vector>
#include <limits>

enum class Mood
{
    Happy,
    Sad,
    Angry,
    Excited,
    Calm
};

std::string moodToString(Mood mood)
{
    switch (mood)
    {
    case Mood::Happy:
        return "Happy";
    case Mood::Sad:
        return "Sad";
    case Mood::Angry:
        return "Angry";
    case Mood::Excited:
        return "Excited";
    case Mood::Calm:
        return "Calm";
    default:
        return "Unknown";
    }
}

struct MoodEntry
{
    std::string date;
    std::string time;
    Mood mood;
};

std::vector<MoodEntry> moodEntries;

void addMoodEntry()
{
    MoodEntry newEntry;
    std::cout << "Enter date (MM/DD/YYYY): ";
    std::cin >> newEntry.date;
    std::cout << "Enter time (HH:MM): ";
    std::cin >> newEntry.time;

    int moodChoice;
    std::cout << "Select mood:\n";
    std::cout << "1. Happy\n2. Sad\n3. Angry\n4. Excited\n5. Calm\n";
    std::cin >> moodChoice;

    switch (moodChoice)
    {
    case 1:
        newEntry.mood = Mood::Happy;
        break;
    case 2:
        newEntry.mood = Mood::Sad;
        break;
    case 3:
        newEntry.mood = Mood::Angry;
        break;
    case 4:
        newEntry.mood = Mood::Excited;
        break;
    case 5:
        newEntry.mood = Mood::Calm;
        break;
    default:
        std::cout << "Invalid choice\n";
        return;
    }

    moodEntries.push_back(newEntry);
    std::cout << "Mood entry added successfully.\n";
}

void displayMoodEntries()
{
    std::cout << "Mood Entries:\n";
    for (const auto &entry : moodEntries)
    {
        std::cout << "Date: " << entry.date << " | Time: " << entry.time << " | Mood: " << moodToString(entry.mood) << "\n";
    }
}

int main()
{
    int choice;
    do
    {
        std::cout << "\nMood Tracker Menu:\n";
        std::cout << "1. Add Mood Entry\n";
        std::cout << "2. Display Mood Entries\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        // Debugging output to check the choice value
        std::cout << "You entered choice: " << choice << std::endl;

        // Clear input buffer to handle any leftover newline characters
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            addMoodEntry();
            break;
        case 2:
            displayMoodEntries();
            break;
        case 3:
            std::cout << "Exiting program.\n";
            break;
        default:
            std::cout << "Invalid choice\n";
            break;
        }
    } while (choice != 3);

    return 0;
}
