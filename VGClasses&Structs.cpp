#include <iostream>
#include <string>
using namespace std;

// Program: Video Game Player Classes
// Description: Simulates different player classes in a video game with unique abilities and resources.

// Struct representing player abilities
struct Abilities {
    string primary; // Stores primary ability name
    string secondary; // Stores secondary ability name
};

// Class representing a player class in the video game
class PlayerClass {
private:
    string name; // Player class name
    int health; // Health points
    int resource; // Resource points (rage, energy, or mana)
    Abilities abilities; // Player abilities

public:
    // Constructor to initialize player class
    PlayerClass(string n, int hp, int res, string primary, string secondary) {
        name = n;
        health = hp;
        resource = res; // Set rage, energy, or mana
        abilities.primary = primary;
        abilities.secondary = secondary;
    }

    // Display player class information
    void displayInfo() {
        cout << "Class: " << name << endl;
        cout << "Health: " << health << endl;
        cout << "Resource (" << getResourceType() << "): " << resource << endl;
        cout << "Primary Ability: " << abilities.primary << endl;
        cout << "Secondary Ability: " << abilities.secondary << endl;
    }

    // Use primary ability
    void usePrimaryAbility() {
        cout << name << " uses primary ability: " << abilities.primary << endl;
        if (resource > 0) {
            resource -= 10;
        }
    }

    // Use secondary ability
    void useSecondaryAbility() {
        cout << name << " uses secondary ability: " << abilities.secondary << endl;
        if (resource > 0) {
            resource -= 20;
        }
    }

private:
    // Get resource type (rage, energy, or mana) based on class
    string getResourceType() {
        if (name == "Warrior") {
            return "Rage";
        } else if (name == "Rogue") {
            return "Energy";
        } else {
            return "Mana";
        }
    }
};

int main() {
    // Create instances of player classes with rage, energy, and mana
    PlayerClass warrior("Warrior", 100, 100, "Slash", "Block");
    PlayerClass mage("Mage", 80, 100, "Fireball", "Teleport");
    PlayerClass rogue("Rogue", 90, 100, "Backstab", "Stealth");

    // Display information about player classes
    cout << "Warrior Info:" << endl;
    warrior.displayInfo();
    cout << endl;
    cout << "Mage Info:" << endl;
    mage.displayInfo();
    cout << endl;
    cout << "Rogue Info:" << endl;
    rogue.displayInfo();
    cout << endl;

    // Use player class abilities
    cout << "Using abilities:" << endl;
    warrior.usePrimaryAbility();
    mage.useSecondaryAbility();
    rogue.usePrimaryAbility();

    return 0;
}
