#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    char input[75];

    // Opening file using constructor and writing to it
    ofstream os("sample60.txt");
    if (!os.is_open())
    {
        cerr << "Failed to open the file for writing." << endl;
        return 1; // Exit with an error code
    }

    cout << "Writing to a text file..." << endl;
    cout << "Please Enter your name: ";
    cin.getline(input, 75); // Ensure the correct buffer size
    os << input << endl;

    cout << "Please Enter your age: ";
    cin >> input;
    cin.ignore(); // Ignore the newline left in the buffer
    os << input << endl;

    os.close(); // Close the file after writing

    // Reading from the file
    ifstream is("sample60.txt");
    if (!is.is_open())
    {
        cerr << "Failed to open the file for reading." << endl;
        return 1; // Exit with an error code
    }

    cout << "Reading from a text file..." << endl;
    string line;
    while (getline(is, line))
    {
        cout << line << endl;
    }

    is.close(); // Close the file after reading
    return 0;
}
