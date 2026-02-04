#include <iostream>
#include <string>
using namespace std;

#define MAX 100

// Function to create Rail Fence pattern
void createRailFence(const string &text, int rails, char rail[][MAX]) {
    int len = text.length();
    int row = 0;
    bool dir_down = false;

    // Initialize the matrix
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = ' ';

    // Build the zig-zag pattern
    for (int i = 0; i < len; i++) {
        rail[row][i] = text[i];

        if (row == 0)
            dir_down = true;
        else if (row == rails - 1)
            dir_down = false;

        row += dir_down ? 1 : -1;
    }
}

// Function to print the Rail Fence matrix
void printRailFence(char rail[][MAX], int rails, int len) {
    cout << "\n========== Rail Fence Cipher ==========\n";

    // Top border
    for (int j = 0; j < len; j++)
        cout << "*---";
    cout << "+\n";

    // Rows
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < len; j++) {
            cout << "| " << rail[i][j] << " ";
        }
        cout << "|\n";

        for (int j = 0; j < len; j++)
            cout << "*---";
        cout << "*\n";
    }
}

// Encryption
void encrypt(const string &text, int rails) {
    char rail[rails][MAX];
    createRailFence(text, rails, rail);
    int len = text.length();

    printRailFence(rail, rails, len);

    cout << "\n Encrypted Message: ";
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] != ' ')
                cout << rail[i][j];
    cout << endl;
}

// Decryption
void decrypt(const string &cipher, int rails) {
    int len = cipher.length();
    char rail[rails][MAX];

    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            rail[i][j] = ' ';

    int row = 0;
    bool dir_down = false;

    // Mark positions
    for (int i = 0; i < len; i++) {
        if (row == 0)
            dir_down = true;
        else if (row == rails - 1)
            dir_down = false;

        rail[row][i] = '*';
        row += dir_down ? 1 : -1;
    }

    // Fill cipher text
    int index = 0;
    for (int i = 0; i < rails; i++)
        for (int j = 0; j < len; j++)
            if (rail[i][j] == '*' && index < len)
                rail[i][j] = cipher[index++];

    printRailFence(rail, rails, len);

    cout << "\n Decrypted Message: ";
    row = 0;
    dir_down = false;

    for (int i = 0; i < len; i++) {
        if (row == 0)
            dir_down = true;
        else if (row == rails - 1)
            dir_down = false;

        cout << rail[row][i];
        row += dir_down ? 1 : -1;
    }
    cout << endl;
}

// Main function
int main() {
    string text, cipher;
    int rails;

    cout << "*****Rail-Fence Cipher*****\n\n";

    cout << " Enter the message : ";
    cin >> text;

    cout << " Enter the number of rails: ";
    cin >> rails;

    encrypt(text, rails);

    cout << "\n Enter the cipher text for decryption: ";
    cin >> cipher;

    decrypt(cipher, rails);

    return 0;
}
