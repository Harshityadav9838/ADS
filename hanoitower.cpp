#include <iostream>
using namespace std;

void hanoi(int n, char source, char helper, char destination) {
    if (n == 1) {
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    hanoi(n - 1, source, destination, helper);

    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    hanoi(n - 1, helper, source, destination);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;

    hanoi(n, 'A', 'B', 'C');

    cout << "Total steps = " << (1 << n) - 1 << endl;

    return 0;
}