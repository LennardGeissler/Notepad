#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h> 

using namespace std;

// Function to save notes
static void saveNote(const string& note) {
    system("cls"); //Clearing console

    ofstream file("notizblock.txt", ios::app); // Opening file in attachment mode ("append")
    if (file.is_open()) {
        file << note << endl; // Writing note into file
        cout << "Notiz gespeichert!" << endl;
        file.close(); // Closing file
        cout << endl;
    }
    else {
        cout << "Fehler beim Öffnen der Datei!" << endl;
    }
}

// Function to show all the notes
static void showNotes() {
    system("cls"); //Clearing console

    ifstream file("notizblock.txt");
    if (file.is_open()) {
        string note;
        cout << "Notizen:" << endl;
        while (getline(file, note)) {
            cout << note << endl;
        }
        cout << endl;
        file.close(); // Closing file
    }
    else {
        cout << "Notizblock ist leer oder konnte nicht geöffnet werden." << endl;
    }
}

int main() {
    while (true)
    {
        int choice;

        // Graphical User Interface
        cout << "Dein Notizblock:" << endl;
        cout << "------------------------------" << endl;
        cout << "Bitte triff eine Auswahl:" << endl;
        cout << "(1) Notiz speichern" << endl;
        cout << "(2) Notizen anzeigen" << endl;
        cout << "(3) Beenden" << endl;
        cout << "------------------------------" << endl;

        // Get user input
        cout << "Deine Auswahl: ";
        cin >> choice;
        cout << "------------------------------" << endl;

        // Execution of the corresponding function based on the user input
        switch (choice) {
        case 1:
        {
            cin.ignore(); // Clear input buffer
            string note;
            cout << "Notiz eingeben: ";
            getline(cin, note);
            saveNote(note);
            break;
        }
        case 2:
            showNotes();
            break;
        case 3:
            cout << "Auf Wiedersehen!" << endl;
            return 0;
        default:
            cout << "Ungueltige Auswahl!" << endl;
        }
    }

    return 0;
}