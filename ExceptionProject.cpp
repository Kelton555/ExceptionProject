// Kelton ___
// ________
// December 2, 2024

#include <cctype>
#include <iostream>

using namespace std;

class invalidCharacterException {};
class invalidRangeException {};

char character(char, int);

int main() {
    const int TEST_SIZE = 5;
    char inputChars[TEST_SIZE] = {'a', 'a', 'Z', '?', 'A'};
    int inputInts[TEST_SIZE] = {1, -1, -1, 5, 32};

    for (int i = 0; i < TEST_SIZE; i++) {
        try {
            cout << "Input " << inputChars[i] << ", " << inputInts[i] << " returned: ";
            char newCharacter = character(inputChars[i], inputInts[i]);
            cout << newCharacter << endl; // if there is no exception, this is executed
        } catch (invalidCharacterException) {
            cout << "An invalidCharacterException\n";
        } catch (invalidRangeException) {
            cout << "An invalidRangeException\n";
        }
    }

    return 0;
}

char character(char start, int offset) {
    bool isUpper = false; // used to check if overstepped into other case
    if (isalpha(start)) {
        isUpper = isupper(start);
    } else { // invalid start character
        throw invalidCharacterException();
    }

    start += offset;

    if (!isalpha(start)) { // if it's no longer alpha
        throw invalidRangeException();
    } else if (isUpper != isupper(start)) { // if it's changed cases
        throw invalidRangeException();
    } else { // otherwise
        return start;
    }
}