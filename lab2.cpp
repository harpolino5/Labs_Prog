#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

const double a = 0.0;
const double b = 1.0;

double S(double x, double eps) {
    //a0 = x/2
    double term = x / 2.0;
    double sum = 0.0;
    int n = 0;

    while (fabs(term) >= eps) {
        sum += term;
        n++;

        // a_{n+1}

        term = term * ((n * n + 2 * n + 1) * x) / ((2 * n + 4) * (2 * n + 3));
    }

    return sum;
}

int main() {
    cout << "The author of this program is Yuliia Akimova from K-14\n";
    cout << "This program calculates the value of the series S(x) with given accuracy eps. Variant 50.\n\n";
    cout << "Enter x (" << a << " <= x <= " << b << "): ";
    double x;
    cin >> x;

    if (cin.fail()) {
        cout << "\nwrong input\n";
        return 0;
    }

    if ((x < a) || (x > b)) {
        cout << "\n***** error\nx must be in [0, 1].\n";
        return 0;
    }

    cout << "Enter eps (eps > 0): ";
    double eps;
    cin >> eps;

    if (cin.fail()) {
        cout << "\nwrong input\n";
        return 0;
    }

    if (eps <= 0) {
        cout << "\n***** error\neps must be positive.\n";
        return 0;
    }

    cout << "\n***** do calculations ... ";

    bool ok = true;
    double result = 0.0;

    if (x < a || x > b || eps <= 0) {
        ok = false;
    }
    else {
        result = S(x, eps);
    }

    cout << "done\n\n";

    cout << scientific << setprecision(5)
        << "for x = " << x << "\n";
    cout << scientific << setprecision(8)
        << "for eps = " << eps << "\n\n";

    cout << fixed << setprecision(9);
    if (ok)
        cout << "result = " << result << "\n";
    else
        cout << "result = undefined\n";

    return 0;
}
