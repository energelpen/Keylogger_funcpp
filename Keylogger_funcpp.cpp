#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

bool isPrintableKey(int keyCode) {
    return keyCode >= 32 && keyCode <= 126;
}

void printPrintableKey(int keyCode) {
    cout << "Pressed Key: '" << static_cast<char>(keyCode)
        << "' (ASCII: " << keyCode
        << ", Hex: 0x" << hex << uppercase << keyCode << dec << ")" << endl;
}

void printSpecialKey(int keyCode) {
    cout << "Special Key: ";
    switch (keyCode) {
    case 8:  cout << "Backspace"; break;
    case 9:  cout << "Tab"; break;
    case 13: cout << "Enter"; break;
    case 16: cout << "Shift"; break;
    case 17: cout << "Ctrl"; break;
    case 18: cout << "Alt"; break;
    case 19: cout << "Pause"; break;
    case 20: cout << "Caps Lock"; break;
    case 27: cout << "Escape"; break;
    case 127: cout << "Delete"; break;
    default:
        cout << "Unknown Special Key"; break;
    }

    cout << " (Code: " << keyCode
        << ", Hex: 0x" << hex << uppercase << keyCode << dec << ")" << endl;
}

// Main entry
int main() {
    cout << "Press Any Key:" << endl;

    while (true) {
        for (int keyCode = 8; keyCode <= 127; ++keyCode) {
            SHORT keyState = GetAsyncKeyState(keyCode);

            if (keyState & 0x8000) {
                if (isPrintableKey(keyCode)) {
                    printPrintableKey(keyCode);
                }
                else {
                    printSpecialKey(keyCode);
                }
            }
        }
        Sleep(100); // So that CPU doesnt go brr
    }

    return 0;
}
