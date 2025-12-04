#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double PI = 3.141592653589793;
const double E = 2.718281828459045;

double f(double x) {
    const double part1 = sin(24.0 / 53.0);
    const double part2 = (4 * E) / (63 * PI) * (7.0 / ((x + 3) * (x - 13)));
    const double part3 = -14 * cos(x + 10);
    const double part4 = sqrt(x - 5);

    return part1 + part2 + part3 + part4;
}

int main() {
    cout << "The author of this program is Yuliia Akimova from K-14\n";
    cout << "This program calculates the value of the expression by given x. Variant 50.\n\n";
    cout << "Enter x (x >= 5 and x != 13): ";
    double x;
    cin >> x;

    if (cin.fail()) {
        cout << "\nwrong input\n";
        return 0;
    }

    cout << "\n***** do calculations ... ";

    bool ok = true;
    double result = 0.0;

    if (x < 5 || x == 13) {
        ok = false;
    }
    else {
        result = f(x);
    }

    cout << "done\n\n";
    cout << fixed << setprecision(7) << "for x = " << x << "\n\n";
    cout << setprecision(8);
    if (ok)
        cout << "result = " << result << "\n";
    else
        cout << "result = undefined\n";

    return 0;
}
