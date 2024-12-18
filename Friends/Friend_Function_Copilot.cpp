#include <iostream>
using namespace std;

class Box {
    private:
        int length;

    public:
        Box() : length(0) {} // Constructor to initialize length to 0

        void setLength(int len) {
            length = len;
        }

        // Friend function declaration
        friend int printLength(Box);
};

// Friend function definition
int printLength(Box b) {
    return b.length;
}

int main() {
    Box b;
    b.setLength(10);
    cout << "Length of box: " << printLength(b) << endl;
    return 0;
}
