#include <iostream>
#include <iomanip>
// <cmath> прибрано

using namespace std;

// Функцію назвала 's' (маленька літера)
double s(double x, double eps) {
    double term = x / 2.0;
    double sum = 0.0;
    int n = 0;
    double abs_term = term;

    // Якщо число менше нуля, змінюємо знак на протилежний
    if (abs_term < 0) {
        abs_term = -abs_term;
    }

    while (abs_term >= eps) {
        sum += term;
        n++;
        // Рекурентна формула
        term = term * ((n * n + 2 * n + 1) * x) / ((2 * n + 4) * (2 * n + 3));
        abs_term = term;

        if (abs_term < 0) {
            abs_term = -abs_term;
        }
    }
    return sum;
}

int main() {
    const double a = 0.0;
    const double b = 1.0;
    
    cout << "The author of this program is Yuliia Akimova from K-14\n";
    cout << "This program calculates the value of the series s(x) with given accuracy eps. Variant 50.\n\n";
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
        result = s(x, eps); // Викликаємо функцію s
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
